import * as WASM from './WASM';
import * as GL from './GL';
import * as Loader from './Loader';
import gltfLoder from './Loaders/GLTFLoader';

const manifest: Loader.Manifest = new Map<string, Loader.Loader>([
  ["/assets/sphere.gltf", gltfLoder],
]);

async function main() {
  await GL.init();
  await Loader.load(manifest);
  await WASM.init();
  await GL.mainLoop();
}

main();