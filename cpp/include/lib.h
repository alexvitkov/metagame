#pragma once

#define EXPORT(name) [[clang::export_name(name)]] extern "C"
#define IMPORT(name) [[clang::import_name(name)]] extern "C"

#include <stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint32_t size_t;

#define NULL nullptr

#define ALIGN(x, a) __ALIGN_MASK(x, (typeof(x))(a)-1)
#define __ALIGN_MASK(x, mask) (((x) + (mask)) & ~(mask))