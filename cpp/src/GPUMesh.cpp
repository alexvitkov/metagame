#pragma once
#include <GL.h>

struct GPUMesh {
  GLuint verticesBuffer;
  GLuint indicesBuffer;
  u32 indicesCount;
};