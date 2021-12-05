import { Pointer } from "./WASM";

function actorAddChildCallback(parent: Pointer, child: Pointer) {
  console.log(parent, child);
}

export const wasmImports = {
  actorAddChildCallback,
}