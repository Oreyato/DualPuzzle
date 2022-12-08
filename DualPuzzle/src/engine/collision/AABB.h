#ifndef AABB_H
#define AABB_H

#include "../maths/Vector3.h"

struct AABB
{
    AABB(const Vector3& minP, const Vector3& maxP);

    Vector3 min;
    Vector3 max;
};

#endif // AABB_H