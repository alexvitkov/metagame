#pragma once
#include <lib.h>

namespace JS {

IMPORT("console_log_string") void console_log_string(const char* str);
IMPORT("alert_string") void alert_string(const char* str);
IMPORT("alert_num") void alert_num(int num);
IMPORT("console_log_num") void console_log_num(int num);

}