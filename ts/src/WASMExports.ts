interface Exports {
  init(): void;
  renderFrame(): void;
  memory: WebAssembly.Memory;
}

export default Exports;