import { Pointer } from "./WASM";

interface Exports {
  init(): void;
  renderFrame(): void;
  memory: WebAssembly.Memory;
  strlen: (ptr: Pointer) => number;
}

export default Exports;