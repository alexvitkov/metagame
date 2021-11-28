#include "JS.h"
#include <Console.h>

namespace Console {

void log(const char* msg) {
  JS::console_log_string(msg);
}

void alert(const char* msg) {
  JS::alert_string(msg);
}

}