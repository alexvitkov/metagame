#pragma once
#include <List.h>
#include <Mat4.h>
#include <Quat.h>
#include <Vector3.h>

class Actor {

public:
  Actor* parent;
  List<Actor*> children;
  bool dirty = false;
  Vector3 position;
  Quat rotation;
  Vector3 scale = {1, 1, 1};

  Mat4 localMatrix;
  Mat4 globalMatrix;

  void addChildUnchecked(Actor* other);
};