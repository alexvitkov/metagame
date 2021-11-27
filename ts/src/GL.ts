import { getU8Array, exports, Pointer } from "./WASM";

import vertexShader from "../../shader/basic.vert.glsl";
import fragmentShader from "../../shader/basic.frag.glsl";

let gl: WebGL2RenderingContext;
let glBuffers = [];
const canvas = document.getElementById("mainCanvas") as HTMLCanvasElement;

export function init() {
  gl = canvas.getContext('webgl2');
  if (!gl) {
    alert("Failed to initialize WebGL2");
    return;
  }

  const vert = compileShader(gl.VERTEX_SHADER, vertexShader);
  const frag = compileShader(gl.FRAGMENT_SHADER, fragmentShader);
  const program = createProgram(vert, frag);
  gl.useProgram(program);
}

export function mainLoop() {
  exports.renderFrame();
  requestAnimationFrame(mainLoop);
}

function compileShader(type, source) {
  const shader = gl.createShader(type);
  gl.shaderSource(shader, source);
  gl.compileShader(shader);

  const message = gl.getShaderInfoLog(shader);
  if (message.length > 0) {
    alert(message);
  }

  return shader;
}

function createProgram(vert, frag) {
  const program = gl.createProgram();
  gl.attachShader(program, vert);
  gl.attachShader(program, frag);
  gl.linkProgram(program);

  const message = gl.getProgramInfoLog(program);
  if (message.length > 0) {
    alert(message);
  }

  return program;
}


function glCreateBuffer() {
  const buf = gl.createBuffer();
  glBuffers.push(buf);
  return glBuffers.length - 1;
}

function glBindBuffer(target, buffer) {
  gl.bindBuffer(target, glBuffers[buffer]);
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

function glVertexAttribPointer(index: number, size: number, type: number, normalized: boolean, stride: number, offset: number) {
  gl.vertexAttribPointer(index, size, type, normalized, stride, offset);
}

function glDrawArrays(mode: number, first: number, count: number) {
  gl.drawArrays(mode, first, count);
}

function glEnableVertexAttribArray(index: number) {
  gl.enableVertexAttribArray(index);
}

export const wasmImports = {
  glCreateBuffer,
  glBindBuffer,
  glBufferData,
  glClearColor,
  glClear,
  glVertexAttribPointer,
  glDrawArrays,
  glEnableVertexAttribArray
}
