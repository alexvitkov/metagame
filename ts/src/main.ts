import * as WASM from './WASM';
import * as GL from './GL';

async function main() {
  await GL.init();
  await WASM.init();
  await GL.mainLoop();
}

main();