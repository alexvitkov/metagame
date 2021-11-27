#pragma once
#include <lib.h>

typedef i32 GLint;
typedef u32 GLuint;
typedef u32 GLenum;
typedef u32 GLsizei;
typedef u32 GLsizeiptr;
typedef u32 GLbitfield;
typedef bool GLboolean;
typedef float GLclampf;

namespace GL {

enum AttribMask : GLenum {
  CURRENT_BIT         = 0x00000001,
  POINT_BIT           = 0x00000002,
  LINE_BIT            = 0x00000004,
  POLYGON_BIT         = 0x00000008,
  POLYGON_STIPPLE_BIT = 0x00000010,
  PIXEL_MODE_BIT      = 0x00000020,
  LIGHTING_BIT        = 0x00000040,
  FOG_BIT             = 0x00000080,
  DEPTH_BUFFER_BIT    = 0x00000100,
  ACCUM_BUFFER_BIT    = 0x00000200,
  STENCIL_BUFFER_BIT  = 0x00000400,
  VIEWPORT_BIT        = 0x00000800,
  TRANSFORM_BIT       = 0x00001000,
  ENABLE_BIT          = 0x00002000,
  COLOR_BUFFER_BIT    = 0x00004000,
  HINT_BIT            = 0x00008000,
  EVAL_BIT            = 0x00010000,
  LIST_BIT            = 0x00020000,
  TEXTURE_BIT         = 0x00040000,
  SCISSOR_BIT         = 0x00080000,
  ALL_ATTRIB_BITS     = 0xFFFFFFFF
};

enum Buffer : GLenum {
  ARRAY_BUFFER         = 0x8892,
  ELEMENT_ARRAY_BUFFER = 0x8893,
};

enum Usage : GLenum {
  STREAM_DRAW      = 0x88E0,
  STREAM_READ      = 0x88E1,
  STREAM_COPY      = 0x88E2,
  STATIC_DRAW      = 0x88E4,
  STATIC_READ      = 0x88E5,
  STATIC_COPY      = 0x88E6,
  DYNAMIC_DRAW     = 0x88E8,
  DYNAMIC_READ     = 0x88E9,
  DYNAMIC_COPY     = 0x88EA,
};

enum DataType : GLenum {
  BYTE           = 0x1400,
  UNSIGNED_BYTE  = 0x1401,
  SHORT          = 0x1402,
  UNSIGNED_SHORT = 0x1403,
  INT            = 0x1404,
  UNSIGNED_INT   = 0x1405,
  FLOAT          = 0x1406,
  DOUBLE         = 0x140A,
};

enum BeginMode : GLenum {
  POINTS         = 0x0000,
  LINES          = 0x0001,
  LINE_LOOP      = 0x0002,
  LINE_STRIP     = 0x0003,
  TRIANGLES      = 0x0004,
  TRIANGLE_STRIP = 0x0005,
  TRIANGLE_FAN   = 0x0006,
  QUADS          = 0x0007,
  QUAD_STRIP     = 0x0008,
  POLYGON        = 0x0009,
};

IMPORT("glCreateBuffer") GLuint createBuffer();
IMPORT("glBindBuffer") void bindBuffer(GLuint target, GLuint buffer);
IMPORT("glBufferData") void bufferData(GLuint target, GLsizeiptr size, const void* data, GLenum usage);
IMPORT("glClearColor") void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
IMPORT("glClear") void clear(GLbitfield mask);
IMPORT("glVertexAttribPointer") void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, u32 pointer);
IMPORT("glDrawArrays") void drawArrays(GLenum mode, GLint first, GLsizei count);
IMPORT("glEnableVertexAttribArray") void enableVertexAttribArray(GLuint index);
}