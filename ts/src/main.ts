import Imports from "./WASMImports";
import Exports from "./WASMExports";

let exports: Exports;

async function main() {
  const wasm = await WebAssembly.instantiateStreaming(fetch("meta.wasm"), Imports);
  exports = wasm.instance.exports;

  exports.main();
}


main();