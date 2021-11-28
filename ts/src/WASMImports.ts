import { wasmImports as wasmImportsGL } from "./GL";
import { getCString, Pointer } from "./WASM";

const wasmImportsCore = {
  alert_num: alert,
  alert_string: (ptr: Pointer) => alert(getCString(ptr)),
  console_log_string: (ptr: Pointer) => console.log(getCString(ptr)),
  console_log_num: (num: number) => console.log(num),
};


const wasmImports = {
  env: {
    ...wasmImportsCore,
    ...wasmImportsGL,
  }
};

export default wasmImports;
