#include <Allocator.h>
#include <Console.h>
#include <List.h>
#include <Renderer.h>
#include <Vector3.h>

EXPORT("init")
void init() {

  List<Vector3> lst;

  Console::log(lst);

  Renderer::init();
  Allocator::init();
}