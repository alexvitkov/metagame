#pragma once
#include <lib.h>

namespace Allocator {

struct Block {
  u32 flags;
  Block* previous;
  Block* next;
  u8 memory_start[0];

  enum Flags : u32 {
    ALLOCATED = 0x01,
    NULL_BLOCK = 0x02,
  };

  u32 size();
  void set_next(Block*);
  bool is_free();
  void remove();
};

inline u32 size(void* ptr) {
  return ((uint32_t*)ptr)[-1];
}

void init();
void* alloc(u32 size);
void free(void *ptr);
[[noreturn]] void outOfMemory();

} // namespace Allocator

extern Allocator::Block __heap_base;