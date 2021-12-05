#pragma once
#include <Ostream.h>

typedef void (*LogFunction)(const char*);

template <LogFunction Log>
class JSConsoleStream : public Ostream {
  char buf[1024];
  int ptr = 0;

public:
  virtual void write(Slice<u8>);
};

IMPORT("console_log_string") void console_log_string(const char* str);
IMPORT("alert_string") void alert_string(const char* str);