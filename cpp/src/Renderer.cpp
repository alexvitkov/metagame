#include <GL.h>


int frame = 0;
EXPORT("renderFrame") void renderFrame() {
  frame++;
  GL::clearColor((frame % 256) / 256.0, 0, 0, 1.0);
  GL::clear(GL::COLOR_BUFFER_BIT);
}