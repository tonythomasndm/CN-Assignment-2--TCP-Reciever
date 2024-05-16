#include "tcp_receiver.hh"

#include <algorithm>


using namespace std;

void TCPReceiver::segment_received(const TCPSegment &seg) {
    const TCPHeader head = seg.header();
    const Buffer &payload = seg.payload();
    if(!head.syn && !_synReceived) return;

    if(!_synReceived){
        _synReceived=true;
        _isn=head.seqno;
    }

    std::string payloadString(payload.str().begin(), payload.str().end());
    uint64_t stream_idx;
    if (payload.size() > 0) {
        if (head.syn || head.seqno != _isn) {
    // --- Hint ------
        // convert the seqno into absolute seqno
        uint64_t checkpoint = _reassembler.ack_index();
        uint64_t abs_seqno = unwrap(head.seqno, _isn, checkpoint);
        stream_idx = abs_seqno - _synReceived;
        }
        _reassembler.push_substring(payloadString, stream_idx,head.fin);
        // _reassembler.push_substring(payload, stream_idx,_finReceived);
    }
    
    // --- Hint ------  
    if (head.fin || _finReceived) {
        _finReceived = true;
        if(_reassembler.unassembled_bytes()==0){
            _reassembler.stream_out().end_input();
        }
    }
    //_reassembler.push_substring(payloadString, stream_idx,_finReceived);
    // ... 
}

optional<WrappingInt32> TCPReceiver::ackno() const {
    optional<WrappingInt32> ackNo={};
    //  if (_synReceived) {
    //     // If the SYN has been received, the acknowledgment number is the next expected sequence number.
    //     WrappingInt32 ackNumber = static_cast<WrappingInt32>(_reassembler.ack_index() + 1);
    //     return ackNumber;
    if (_synReceived){
        ackNo = wrap(_reassembler.ack_index() + _synReceived + _finReceived, _isn);
    }
    return ackNo;
    // } else {
    //     // If the SYN has not been received, return an empty optional.
    //     return {};
    // }
}

size_t TCPReceiver::window_size() const { return _reassembler.stream_out().remaining_capacity(); }
