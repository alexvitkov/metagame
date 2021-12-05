#include <Libc.h>

void* memcpy(void* dest, const void* src, size_t len) {
  char* d       = (char*)dest;
  const char* s = (char*)src;

  while (len--)
    *d++ = *s++;
  return dest;
}

void* memset(void* dest, int val, size_t len) {
  u8* ptr = (u8*)dest;

  while (len-- > 0)
    *ptr++ = val;
  return dest;
}

EXPORT("strlen") u32 strlen(const char* str) {
  u32 len = 0;
  while (*str++)
    len++;
  return len;
}

char* strcpy(char* dest, const char* src) {
  return (char*)memcpy(dest, src, strlen(src) + 1);
}