#include "byte_stream.hh"
#include <bits/stdc++.h>
#include <algorithm>

// You will need to add private members to the class declaration in `byte_stream.hh`

/* Replace all the dummy definitions inside the methods in this file. */


using namespace std;

ByteStream::ByteStream(const size_t capa){
  capacity=capa;
}

size_t ByteStream::write(const string &data) {
  size_t count_bytes_w=0;
  cout<<data<<":"<<count_bytes_w<<endl;
  cout<<":"<<count_bytes_written<<endl;
  for(auto i: data){
    if(buffer.size()+1<=capacity)
    {
      ++count_bytes_w;
      buffer.push_back(i);
    }
    else{
      break;
    }
  }
  cout<<data<<":"<<count_bytes_w<<endl;
  count_bytes_written+=count_bytes_w;
  cout<<":"<<count_bytes_written<<endl;
  return count_bytes_w;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
  size_t peekLen = min(len, buffer.size());
  return string(buffer.begin(), buffer.begin() + peekLen);
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
  if(len>buffer.size()){
    set_error();
    return;
  }
  size_t popLen = len;
  count_bytes_read+=popLen;
  buffer.erase(buffer.begin(), buffer.begin() + popLen);
}

//! Read (i.e., copy and then pop) the next "len" bytes of the stream
//! \param[in] len bytes will be popped and returned
//! \returns a string
std::string ByteStream::read(const size_t len) {
  if(len>buffer.size()){
    set_error();
    return "";
  }
  size_t readLen = len;
  string result(buffer.begin(), buffer.begin() + readLen);
  buffer.erase(buffer.begin(), buffer.begin() + readLen);
  count_bytes_read+=readLen;
  return result;
}

void ByteStream::end_input() { 
  // cout<<"Calling Inputed ended:";
  input_end=true;
  // cout<<input_end<<endl;
}

bool ByteStream::input_ended() const { 
  return input_end;
}

size_t ByteStream::buffer_size() const {
  size_t k=static_cast<size_t>(buffer.size());
  return k; 
}

bool ByteStream::buffer_empty() const {
  return buffer.size()==0; 
}

bool ByteStream::eof() const {
  // cout<<"buffer size"<<buffer.size()<<endl;
  // cout<<"input ended"<<input_ended()<<endl;
   return buffer_empty() && input_ended(); }

size_t ByteStream::bytes_written() const { 
  return count_bytes_written; 
  }

size_t ByteStream::bytes_read() const { 
  return count_bytes_read;  
  }

size_t ByteStream::remaining_capacity() const { 
  size_t k=static_cast<size_t>(capacity-buffer.size());
  return k;
  }
