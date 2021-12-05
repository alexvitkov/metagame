#pragma once
#include <Ostream.h>
#include <lib.h>

namespace Debug {

typedef void (*Logger)(const char*);

class JOstream : public Ostream {
  char buffer[1024];
  int pos = 0;
  Logger logger;

public:
  JOstream(Logger logger);
  virtual void write(Slice<u8>) override;

  template <typename... Args>
  void operator()(Args...);

  template <typename T, typename... Args>
  void operator()(T head, Args... tail) {
    format(*this, head);
    (*this)(tail...);
  }

  template <>
  void operator()() {
    format(*this, "\n");
  }
};

extern JOstream log;
extern JOstream warn;
extern JOstream error;
extern JOstream alert;

}