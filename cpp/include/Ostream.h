#pragma once
#include <lib.h>
#include <Slice.h>

class Ostream {
public:
  virtual void write(Slice<u8>) = 0;

  template <typename... Args>
  void operator()(Args...);

  template <typename T, typename... Args>
  void operator()(T head, Args... tail) {
    format(*this, head);
    (*this)(tail...);
  }

  template <>
  void operator()() {
  }
};

template <typename T>
void format(class Ostream& o, const Slice<T>& slice) {
  o(slice.head, ", ", slice.size, "\n");
  o("Slice {");
  for (const T& el : slice)
    o(el, ", ");
  o("}");
}

void format(Ostream& o, u8);
void format(Ostream& o, u16);
void format(Ostream& o, u32);
void format(Ostream& o, u64);
void format(Ostream& o, i8);
void format(Ostream& o, i16);
void format(Ostream& o, i32);
void format(Ostream& o, i64);
void format(Ostream& o, void*);
void format(Ostream& o, const char*);
void format(Ostream& o, float);
void format(Ostream& o, double);