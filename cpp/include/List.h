#include <Allocator.h>
#include <Console.h>
#include <Slice.h>

template <typename T>
class List : public Slice<T> {
  u32 capacity;

public:
  List(u32 capacity = 5) : Slice<T> {0, 0}, capacity(capacity) {
    this->head = (T*)Allocator::alloc(capacity * sizeof(T));
  }

  void push(T val) {
    if (this->size >= capacity)
      reserve(capacity * 2);
    pushUnchecked(val);
  }

  void pushUnchecked(T val) {
    this->head[this->size++] = val;
  }

  T pop() {
    return this->head[--this->size];
  }

  void reserve(u32 newCapacity) {
    T* newData = (T*)Allocator::alloc(newCapacity * sizeof(T));
    for (u32 i = 0; i < this->size; i++) {
      newData[i] = this->head[i];
    }

    Allocator::free(this->head);
    this->head     = newData;
    this->capacity = newCapacity;
  }
};