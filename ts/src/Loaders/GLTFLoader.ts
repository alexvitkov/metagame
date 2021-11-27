import GLTF, { convertIndicesToReferences } from "../GLTF";
import { gl, registerBuffer as registerBufferUnchecked } from '../GL';

export default async function loadGLTF(url: string): Promise<any> {
  const resp = await fetch(url);
  const gltf: GLTF = await resp.json();

  convertIndicesToReferences(gltf);

  // load the buffers
  for (let buf of gltf.buffers) {
    let bufferUri = url;
    if (url.lastIndexOf('/') !== -1)
      bufferUri = bufferUri.substring(0, bufferUri.lastIndexOf('/'));
    bufferUri += '/' + buf.uri;

    const resp = await fetch(bufferUri);
    buf.data = await resp.arrayBuffer();
  }

  // assign the targets for the buffer views based on their usage in the meshes
  for (const mesh of gltf.meshes) {
    for (const primitive of mesh.primitives) {
      if (primitive.indices)
        primitive.indices.bufferView.target = gl.ELEMENT_ARRAY_BUFFER;
      for (const id in primitive.attributes)
        primitive.attributes[id].bufferView.target = gl.ARRAY_BUFFER;
    }
  }

  // create and upload the buffer views
  for (const bw of gltf.bufferViews) {
    bw.data = new Uint8Array(bw.buffer.data, bw.byteOffset, bw.byteLength);

    bw.gpuBuffer = gl.createBuffer();
    bw.gpuBufferIndex = registerBufferUnchecked(bw.gpuBuffer);

    gl.bindBuffer(bw.target, bw.gpuBuffer);
    gl.bufferData(bw.target, bw.data, gl.STATIC_DRAW);
  }

  console.log(gltf);

  return gltf;
}

