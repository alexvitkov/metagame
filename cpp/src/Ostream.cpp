#include <Ostream.h>
#include <Slice.h>
#include <Libc.h>

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


static double PRECISION = 0.00000000001;

// https://stackoverflow.com/questions/2302969/convert-a-float-to-a-string
char* dtoa(char* s, double n) {
  // handle special cases
  if (isnan(n)) {
    strcpy(s, "nan");
  } else if (isinf(n)) {
    strcpy(s, "inf");
  } else if (n == 0.0) {
    strcpy(s, "0");
  } else {
    int digit, m, m1;
    char* c = s;
    int neg = (n < 0);
    if (neg)
      n = -n;
    // calculate magnitude
    m = log10(n);
    int useExp = (m >= 14 || (neg && m >= 9) || m <= -9);
    if (neg)
      *(c++) = '-';
    // set up for scientific notation
    if (useExp) {
      if (m < 0)
        m -= 1.0;
      n  = n / pow(10.0, m);
      m1 = m;
      m  = 0;
    }
    if (m < 1.0) {
      m = 0;
    }
    // convert the number
    while (n > PRECISION || m >= 0) {
      double weight = pow(10.0, m);
      if (weight > 0 && !isinf(weight)) {
        digit = floor(n / weight);
        n -= (digit * weight);
        *(c++) = '0' + digit;
      }
      if (m == 0 && n > 0)
        *(c++) = '.';
      m--;
    }
    if (useExp) {
      // convert the exponent
      int i, j;
      *(c++) = 'e';
      if (m1 > 0) {
        *(c++) = '+';
      } else {
        *(c++) = '-';
        m1     = -m1;
      }
      m = 0;
      while (m1 > 0) {
        *(c++) = '0' + m1 % 10;
        m1 /= 10;
        m++;
      }
      c -= m;
      for (i = 0, j = m - 1; i < j; i++, j--) {
        // swap without temporary
        c[i] ^= c[j];
        c[j] ^= c[i];
        c[i] ^= c[j];
      }
      c += m;
    }
    *(c) = '\0';
  }
  return s;
}

void format(Ostream& o, float num) {
  format(o, (double)num);
}

void format(Ostream& o, double num) {
  char buf[33];
  memset(buf, 0, 33);
  dtoa(buf, num);
  o.write({ (u8*)buf, strlen(buf) });
}