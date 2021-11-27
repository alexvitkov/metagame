import * as WASM from './WASM';
import * as GL from './GL';

async function main() {
  await WASM.init();
  await GL.init();
  await GL.mainLoop();
}

main();