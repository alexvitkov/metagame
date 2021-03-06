import Imports from "./WASMImports";
import Exports from "./WASMExports";

export type Pointer = number;
export let exports: Exports;

export async function init() {
  const wasm = await WebAssembly.instantiateStreaming(fetch("/meta.wasm"), Imports);
  exports = wasm.instance.exports;
  exports.init();
}

export function getU8Array(ptr: Pointer, length: number): Uint8Array {
  return new Uint8Array(exports.memory.buffer, ptr, length);
}

export function getCString(ptr: Pointer): string {
  const decoder = new TextDecoder("utf-8");
  const length = exports.strlen(ptr);
  const arr = new Uint8Array(exports.memory.buffer, ptr, length);

  return decoder.decode(arr);
}