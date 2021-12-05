#pragma once
#include <List.h>
#include <Vector3.h>
#include <Quat.h>
#include <Mat4.h>

class Transform {
  Transform* parent;
  List<Transform*> children;
public:
  bool dirty = false;
  Vector3 position;
  Quat rotation;
  Vector3 scale;

  Mat4 localMatrix;
  Mat4 globalMatrix;
};