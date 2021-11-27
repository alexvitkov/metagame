#include <Allocator.h>
#include <Console.h>

namespace Allocator {

void init() {
  __heap_base = Block {
    .flags = 0,
    .previous = NULL,
    .next = 0,
  };
}

void* alloc(u32 size) {
  u32 needed_size = ALIGN(size + sizeof(Block), 4);

  for (Block* block = &__heap_base; block; block = block->next) {
    if (block->flags & Block::ALLOCATED) continue;
    if (block->size() < needed_size) continue;

    Block* new_block = (Block*)(block->memory_start + block->size() - needed_size);
    block->set_next(new_block);
    return new_block->memory_start;
  }

  out_of_memory();
}

u32 Block::size() {
  return (u8*)this->next - (u8*)this - sizeof(Block);
}

void Block::set_next(Block* new_next) {
  Block *old_next = next;

  this->next = new_next;

  new_next->previous = this;
  new_next->next = old_next;

  if (old_next) old_next->previous = new_next;
}

void out_of_memory() {
  Console::alert("Out of memory");
  __builtin_unreachable();
}

}