#pragma once

struct Vector3 {
  float x = 0, y = 0, z = 0;

  Vector3 operator+(const Vector3& other);
  Vector3 operator-(const Vector3& other);
};

void format(class Ostream& o, const Vector3& vec);