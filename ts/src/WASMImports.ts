import { wasmImports as wasmImportsGL } from "./GL";
import { wasmImports as wasmImportsInspector } from "./Inspector";
import { getCString, Pointer } from "./WASM";

const wasmImportsCore = {
  alert_string: (ptr: Pointer) => alert(getCString(ptr)),
  console_log_string: (ptr: Pointer) => console.log(getCString(ptr)),
  console_warn_string: (ptr: Pointer) => console.warn(getCString(ptr)),
  console_error_string: (ptr: Pointer) => console.error(getCString(ptr)),

  isnan: Number.isNaN,
  isinf: num => !Number.isFinite(num),
  log10: Math.log10,
  pow: Math.pow,
  floor: Math.floor
};


const wasmImports = {
  env: {
    ...wasmImportsCore,
    ...wasmImportsGL,
    ...wasmImportsInspector,
  }
};

export default wasmImports;
