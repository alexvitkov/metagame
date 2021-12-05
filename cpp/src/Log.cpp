#include <Log.h>

template <LogFunction Log>
void JSConsoleStream<Log>::write(Slice<u8> bytes) {
  for (u8 b : bytes) {
    if (b == '\n') {
      buf[ptr] = '\0';
      Log((char*)buf);
      ptr = 0;
    } else {
      buf[ptr++] = b;
    }
  }
}

template class JSConsoleStream<console_log_string>;
template class JSConsoleStream<alert_string>;