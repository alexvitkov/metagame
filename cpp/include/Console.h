#pragma once
#include <Ostream.h>
#include <lib.h>

namespace Console {

typedef void (*Logger)(const char*);

class JOstream : public Ostream {
  char buffer[1024];
  int pos = 0;
  Logger logger;

public:
  JOstream(Logger logger);
  virtual void write(Slice<u8>) override;
};

extern JOstream log;
extern JOstream warn;
extern JOstream error;
extern JOstream alert;

}