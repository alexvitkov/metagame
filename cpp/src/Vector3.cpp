#include <Vector3.h>
#include <Ostream.h>

Vector3 Vector3::operator+(const Vector3& other) {
  return {
    x + other.x,
    y + other.y,
    z + other.z,
  };
}

Vector3 Vector3::operator-(const Vector3& other) {
  return {
    x - other.x,
    y - other.y,
    z - other.z,
  };
}

void format(class Ostream& o, const Vector3& vec) {
  format(o, "Vector3 { ");
  format(o, vec.x);
  format(o, ", ");
  format(o, vec.y);
  format(o, ", ");
  format(o, vec.z);
  format(o, " }");
}