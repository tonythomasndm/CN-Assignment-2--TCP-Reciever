#include "stream_reassembler.hh"
#include <algorithm>
#include <iostream>

StreamReassembler::StreamReassembler(const size_t capacity)
    : _output(capacity), capacity(capacity), nextExpectedIndex(0), eof(false) {}

void StreamReassembler::push_segment(const std::string &data, size_t index, bool eof) {
    Segment s(data, index, eof);
    segments.push_back(s);
}

void StreamReassembler::push_substring(const std::string &data, size_t index, bool eof) {
    if (index + data.length() <= nextExpectedIndex && !eof) {
        return;
    }

    push_segment(data, index, eof);

    auto segmentComparator = [](const Segment &segment1, const Segment &segment2) {
        return segment1.index < segment2.index;
    };

    sort(segments.begin(),segments.end(),segmentComparator);

    for (auto it = segments.begin(); it != segments.end();) {
        Segment &s = *it;
        if (s.index == nextExpectedIndex) {
            if (s.eof) {
                this->eof = true;
            }
            int bytesWritten = _output.write(s.data);
            if (bytesWritten < s.data.length()) {
                this->eof = false;
            }
            nextExpectedIndex += bytesWritten;
            
            it = segments.erase(it);
        } else if (s.index < nextExpectedIndex) {
            if (s.eof) {
                this->eof = true;
            }
            int startPos = nextExpectedIndex - s.index;
            int len = s.data.length() - startPos;
            std::string subData = s.data.substr(startPos, len);
            int bytesWritten = _output.write(subData);
            if (bytesWritten < subData.length()) {
                this->eof = false;
            }
            nextExpectedIndex += bytesWritten;
            
            it = segments.erase(it);
        } else {
            break;
        }
    }

    if (this->eof) {
        _output.end_input();
    }
}

size_t StreamReassembler::unassembled_bytes() const {
    size_t unassembledBytes = 0;
    size_t lastAssembledIndex = nextExpectedIndex - 1;

    for (const Segment &segment : segments) {
        if (segment.index <= lastAssembledIndex) {
            size_t overlap = lastAssembledIndex - segment.index + 1;
            unassembledBytes += std::max<size_t>(0, segment.data.length() - overlap);
        } else {
            unassembledBytes += segment.data.length();
        }
        lastAssembledIndex = std::max(lastAssembledIndex, segment.index + segment.data.length() - 1);
    }
    return unassembledBytes;
}

bool StreamReassembler::empty() const {
    return segments.empty();
}

size_t StreamReassembler::ack_index() const {
    return nextExpectedIndex;
}
