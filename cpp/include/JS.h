#define EXPORT(name) [[clang::export_name(name)]] extern "C"
#define IMPORT(name) [[clang::import_name(name)]] extern "C"

namespace JS {
  // IMPORT("console_log_string") void console_log_string();
  IMPORT("alert_num") void alert_num(int num);
};