#include <Allocator.h>
#include <Console.h>
#include <Renderer.h>

EXPORT("init") void init() {
  Renderer::init();
  Allocator::init();
}