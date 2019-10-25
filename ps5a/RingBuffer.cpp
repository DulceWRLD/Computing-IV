#include "RingBuffer.hpp"
#include <vector>
#include <stdint.h>
#include <stdexcept>

RingBuffer::RingBuffer(int capacity) {
  
    if(capacity <= 0) {
      throw std::invalid_argument("RingBuffer constructor: capacity must be greater than 0\n");
    }
    this->capacity = capacity;
  
    this->size_ = 0;
    
    //make an exception for negative numbers
    
}

int RingBuffer::size() {
  return this->size_; 
}

bool RingBuffer::isEmpty() {
  return (this->size_ == 0) ? true : false;
}

bool RingBuffer::isFull() {
  return (this->size_ == this->capacity) ? true : false;
}

void RingBuffer::enqueue(int16_t x) {
  if(this->size_ == this->capacity)
    throw std::runtime_error("enqueue: can't enqueue to a full ring\n");
  this->buffer.push_back(x);
  this->size_++;
}

int16_t RingBuffer::dequeue() {
  if(this->isEmpty())
    throw std::runtime_error("dequeue: can't dequeue to an empty buffer");
  int16_t front = this->buffer.at(0);
  this->buffer.erase(this->buffer.begin());
  this->size_--;
  return front;
}

int16_t RingBuffer::peek() {
  if(this->isEmpty())                                                         
    throw std::runtime_error("peek: can't peek to an empty buffer");
  return this->buffer.front();
}
  
