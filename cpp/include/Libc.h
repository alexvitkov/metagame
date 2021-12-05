#pragma once
#include <lib.h>

extern "C" void* memcpy(void* dest, const void* src, size_t len);
extern "C" void* memset(void* s, int c, size_t n);
extern "C" u32 strlen(const char*);
extern "C" char* strcpy(char* dest, const char* src);

IMPORT("isnan") bool isnan(double);
IMPORT("isinf") bool isinf(double);
IMPORT("log10") double log10(double);
IMPORT("pow") double pow(double base, double pow);
IMPORT("floor") double floor(double);