#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "AABB.h"

namespace Collisions {
    bool intersect(const AABB& a, const AABB& b);
}

#endif // COLLISIONS_H