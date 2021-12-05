#include <GL.h>

namespace Renderer {

int frame = 0;
GLuint buffer;

float triangle[] = {
  -0.5, -0.5, 0,
  0.5, -0.5, 0,
  0, 0.5, 0,
};

void init() {
  buffer = GL::createBuffer();
  GL::bindBuffer(GL::ARRAY_BUFFER, buffer);
  GL::bufferData(GL::ARRAY_BUFFER, sizeof(triangle), triangle, GL::STATIC_DRAW);
}

EXPORT("renderFrame") void renderFrame() {
  // frame++;
  // GL::clearColor((frame % 256) / 256.0, 0, 0, 1.0);
  // GL::clear(GL::COLOR_BUFFER_BIT);

  // GL::enableVertexAttribArray(0);
  // GL::vertexAttribPointer(0, 3, GL::FLOAT, false, 0, 0);
  // GL::drawArrays(GL::TRIANGLES, 0, 3);
}

}
