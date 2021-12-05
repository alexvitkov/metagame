#include <Debug.h>

namespace Debug {

IMPORT("console_log_string") void console_log_string(const char* str);
IMPORT("console_warn_string") void console_warn_string(const char* str);
IMPORT("console_error_string") void console_error_string(const char* str);
IMPORT("alert_string") void alert_string(const char* str);

JOstream log(console_log_string);
JOstream warn(console_warn_string);
JOstream error(console_error_string);
JOstream alert(alert_string);

JOstream::JOstream(Logger logger)
    : logger(logger) { }

void JOstream::write(Slice<u8> slice) {
  for (u8 c : slice) {
    if (c == '\n') {
      buffer[pos] = 0;
      logger(buffer);
      pos = 0;
    } else {
      buffer[pos++] = c;
    }
  }
}

}