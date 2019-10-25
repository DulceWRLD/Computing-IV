#include <stdint.h>
#include <vector>

class RingBuffer {
public:
  RingBuffer(int capacity);
  int size();
  int cap();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
private:
  std::vector<int16_t> buffer;
  int size_;
  int capacity;
};
