import { getU8Array, exports, Pointer } from "./WASM";

let gl: WebGL2RenderingContext;
const canvas = document.getElementById("mainCanvas") as HTMLCanvasElement;

export function init() {
  gl = canvas.getContext('webgl2');
  if (!gl) {
    alert("Failed to initialize WebGL2");
    return;
  }
}

export function mainLoop() {
  exports.renderFrame();
  requestAnimationFrame(mainLoop);
}

function glCreateBuffer() {
  return gl.createBuffer();
}

function glBindBuffer(target, buffer) {
  gl.bindBuffer(target, buffer);
}

function glBufferData(target, size: number, data: Pointer, usage) {
  gl.bufferData(target, getU8Array(data, size), usage);
}

function glClearColor(red: number, green: number, blue: number, alpha: number) {
  gl.clearColor(red, green, blue, alpha);
}

function glClear(mask: number) {
  gl.clear(mask);
}

export const wasmImports = {
  glCreateBuffer,
  glBindBuffer,
  glBufferData,
  glClearColor,
  glClear,
}
