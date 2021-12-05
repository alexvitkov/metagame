#include <Actor.h>

#ifdef ACTOR_ADD_CHILD_CALLBACK
IMPORT("actorAddChildCallback") void actorAddChildCallback(Actor* parent, Actor* child);
#endif

void Actor::addChildUnchecked(Actor* other) {
  other->parent = this;
  children.push(other);
#ifdef ACTOR_ADD_CHILD_CALLBACK
  actorAddChildCallback(this, other);
#endif
}