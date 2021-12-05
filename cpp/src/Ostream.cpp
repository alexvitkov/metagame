#include <Ostream.h>
#include <String.h>

template <typename T>
static void format_number(Ostream& o, T number, int radix) {
  const int bufferSize = 66;
  char buffer[bufferSize];

  char* ptr = &buffer[bufferSize - 1];

  bool negative = number < 0;
  if (negative) number *= -1;

  do {
    int digit = number % radix;
    if (digit < 10) {
      digit += '0';
    } else {
      digit += 'A' - 10;
    }

    number /= radix;

    *ptr = digit;
    ptr--;
  } while (number);

  if (negative) {
    *ptr = '-';
  } else {
    ptr++;
  }

  o.write({ (u8*)ptr, (u32)(ptr - buffer) });
}

void format(Ostream& o, const char* str) {
  auto len = strlen(str);
  o.write({(u8*)str, len});
}

void format(Ostream& o, u8 num) { format_number(o, num, 10); }
void format(Ostream& o, u16 num) { format_number(o, num, 10); }
void format(Ostream& o, u32 num) { format_number(o, num, 10); }
void format(Ostream& o, u64 num) { format_number(o, num, 10); }
void format(Ostream& o, i8 num) { format_number(o, num, 10); }
void format(Ostream& o, i16 num) { format_number(o, num, 10); }
void format(Ostream& o, i32 num) { format_number(o, num, 10); }
void format(Ostream& o, i64 num) { format_number(o, num, 10); }
void format(Ostream& o, void* ptr) { format_number(o, (u32)ptr, 16); }
void format(Ostream& o, const char*);