#include <Allocator.h>
#include <Debug.h>
#include <List.h>
#include <Renderer.h>
#include <Vector3.h>

EXPORT("init")
void init() {
  Renderer::init();
  Allocator::init();
}