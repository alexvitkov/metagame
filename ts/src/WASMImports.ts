import { wasmImports as wasmImportsGL } from "./GL";

const wasm_imports = {
  alert_num: alert,
};

export default {
  env: {
    ...wasm_imports,
    ...wasmImportsGL,
  }
};