#include <Allocator.h>
#include <Console.h>

u32 heap_size = 4 << 20;

namespace Allocator {

void init() {
  Block* nullBlock = (Block*)((u8*)&__heap_base + heap_size - sizeof(Block));
  nullBlock->flags = Block::NULL_BLOCK;

  __heap_base = Block {
    .flags = 0,
    .previous = NULL,
    .next = nullBlock,
  };

}

void* alloc(u32 size) {
  u32 needed_size = ALIGN(size + sizeof(Block), 4);

  for (Block* block = &__heap_base; !(block->flags & Block::NULL_BLOCK); block = block->next) {
    if (block->flags & Block::ALLOCATED) continue;
    if (block->size() < needed_size) continue;

    Block* new_block = (Block*)(block->memory_start + block->size() - needed_size);
    block->set_next(new_block);
    return new_block->memory_start;
  }

  outOfMemory();
}

void free(void *ptr) {
  Block *block = (Block*)((u8*)ptr - sizeof(Block));
  
  if (block->previous && block->previous->is_free()) {
    block->remove();
  }
}

u32 Block::size() {
  return (u8*)this->next - (u8*)this - sizeof(Block);
}

bool Block::is_free() {
  return !(flags & ALLOCATED);
}

void Block::remove() {
  if (previous) previous->next = next;
  if (next) next->previous = previous;
}

void Block::set_next(Block* new_next) {
  Block *old_next = next;

  this->next = new_next;

  new_next->previous = this;
  new_next->next = old_next;

  if (old_next) old_next->previous = new_next;
}

void outOfMemory() {
  Console::alert("Out of memory");
  __builtin_unreachable();
}

}