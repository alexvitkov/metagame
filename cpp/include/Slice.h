#pragma once
#include <lib.h>

template <typename T>
class Slice {
public:
  T* head;
  u32 size;

  T* begin() const {
    return head;
  }

  T* end() const {
    return head + size;
  }

  T& operator[](u32 index) { return head[index]; }
};