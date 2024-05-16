#include "wrapping_integers.hh"

#include <iostream>

using namespace std;

//! Transform an "absolute" 64-bit sequence number (zero-indexed) into a WrappingInt32
//! \param n The input absolute 64-bit sequence number
//! \param isn The initial sequence number
WrappingInt32 wrap(uint64_t n, WrappingInt32 isn) { return isn + uint32_t(n); }

//! Transform a WrappingInt32 into an "absolute" 64-bit sequence number (zero-indexed)
//! \param n The relative sequence number
//! \param isn The initial sequence number
//! \param checkpoint A recent absolute 64-bit sequence number
//! \returns the 64-bit sequence number that wraps to `n` and is closest to `checkpoint`
//!
//! \note Each of the two streams of the TCP connection has its own ISN. One stream
//! runs from the local TCPSender to the remote TCPReceiver and has one ISN,
//! and the other stream runs from the remote TCPSender to the local TCPReceiver and
//! has a different ISN.
uint64_t unwrap(WrappingInt32 n, WrappingInt32 isn, uint64_t checkpoint) {

    uint64_t n_abs = static_cast<uint64_t>(n.raw_value() - isn.raw_value());

    uint64_t boundary = static_cast<uint64_t>(UINT32_MAX) + 1;

    uint64_t ckt_offset = checkpoint % boundary;
    uint64_t ckt_start = checkpoint - ckt_offset;

    if (ckt_offset == 0 && ckt_start >= boundary) {
        ckt_offset += boundary;
        ckt_start -= boundary;
    }

    
    if (n_abs > ckt_offset) {
        if (ckt_start >= boundary && (n_abs - ckt_offset) >= (boundary - n_abs + ckt_offset))
            return ckt_start - boundary + n_abs;
        else
            return ckt_start + n_abs;
    }
    else{
        if ((ckt_offset - n_abs) <= (n_abs + boundary - ckt_offset))
            return ckt_start + n_abs;
        else if((ckt_offset - n_abs) > (n_abs + boundary - ckt_offset))
            return ckt_start + boundary + n_abs;

    }
}
