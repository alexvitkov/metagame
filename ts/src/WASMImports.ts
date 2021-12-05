import { wasmImports as wasmImportsGL } from "./GL";
import { getCString, Pointer } from "./WASM";

const wasmImportsCore = {
  alert_string: (ptr: Pointer) => alert(getCString(ptr)),
  console_log_string: (ptr: Pointer) => console.log(getCString(ptr)),
  console_warn_string: (ptr: Pointer) => console.warn(getCString(ptr)),
  console_error_string: (ptr: Pointer) => console.error(getCString(ptr)),
};


const wasmImports = {
  env: {
    ...wasmImportsCore,
    ...wasmImportsGL,
  }
};

export default wasmImports;
