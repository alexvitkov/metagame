#include <Actor.h>
#include <Allocator.h>
#include <Debug.h>
#include <List.h>
#include <Renderer.h>
#include <Vector3.h>

extern "C" void __wasm_call_ctors();

EXPORT_VAR Actor rootActor;
EXPORT_VAR Actor child;

EXPORT("init") void init() {
  Allocator::init();
  __wasm_call_ctors();

  Renderer::init();
  
  rootActor.addChildUnchecked(&child);
}
