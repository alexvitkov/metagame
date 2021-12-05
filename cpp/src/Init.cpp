#include <Allocator.h>
#include <Console.h>
#include <Renderer.h>
#include <Vector3.h>

EXPORT("init")
void init() {
  Renderer::init();
  Allocator::init();
}