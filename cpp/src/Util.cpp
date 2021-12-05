#include <String.h>

EXPORT("strlen") u32 strlen(const char* str) {
  u32 len = 0;
  while (*str++) len++;
  return len;
}