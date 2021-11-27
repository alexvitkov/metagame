
export interface Node {
  name: string;
  mesh: Mesh;
  children?: Node[];
  translation?: number[];
  rotation?: number[];
  scale?: number[];
  matrix?: number[];
}

export interface Scene {
  name: string;
}

export interface Buffer {
  byteLength: number;
  uri: string;
  data: ArrayBuffer;
}

export interface BufferView {
  buffer: Buffer;
  byteLength: number;
  byteOffset: number;
  target: number;

  data: Uint8Array;
  gpuBuffer: WebGLBuffer;
  gpuBufferIndex: number;
}

export interface Accessor {
  bufferView: BufferView;
  byteOffset: number;
  componentType: number;
  count: number;
  type: 'SCALAR' | 'VEC2' | 'VEC3' | 'VEC4' | 'MAT2' | 'MAT3' | 'MAT4';
}

export interface Primitive {
  attributes: { [key: string]: Accessor };
  indices: Accessor;
}

export interface Mesh {
  primitives: Primitive[];
}

export default interface GLTF {
  secnes: Scene[];
  nodes: Node[];
  buffers: Buffer[];
  bufferViews: BufferView[];
  meshes: Mesh[];
  accessors: Accessor[];
};

export function convertIndicesToReferences(gltf: GLTF) {
  for (const bw of gltf.bufferViews)
    bw.buffer = gltf.buffers[bw.buffer as any as number];

  for (const accessor of gltf.accessors)
    accessor.bufferView = gltf.bufferViews[accessor.bufferView as any as number];

  for (const mesh of gltf.meshes) {
    for (const primitive of mesh.primitives) {
      for (const attribute in primitive.attributes)
        primitive.attributes[attribute] = gltf.accessors[primitive.attributes[attribute] as any as number];

      if (primitive.indices !== undefined)
        primitive.indices = gltf.accessors[primitive.indices as any as number];
    }
  }

  for (const node of gltf.nodes) {
    if (node.mesh !== undefined)
      node.mesh = gltf.meshes[node.mesh as any as number];
    
    if (node.children) {
      for (let i = 0; i < node.children.length; i++)
        node.children[i] = gltf.nodes[node.children[i] as any as number];
    }
  }
}