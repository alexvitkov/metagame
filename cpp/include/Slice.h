#pragma once
#include <lib.h>

template <typename T>
class Slice {
public:
  T* head;
  u32 size;

  T* begin() {
    return head;
  }

  T* end() {
    return head + size;
  }
};