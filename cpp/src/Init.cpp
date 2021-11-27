#include <Allocator.h>
#include <Renderer.h>
#include <JS.h>

EXPORT("init") void init() {
  Renderer::init();
  Allocator::init();
}