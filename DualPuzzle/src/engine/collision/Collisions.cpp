#include "Collisions.h"

bool Collisions::intersect(const AABB& a, const AABB& b)
{
	bool outside = a.max.x < b.min.x ||
		a.max.y < b.min.y ||
		a.max.z < b.min.z ||
		b.max.x < a.min.x ||
		b.max.y < a.min.y ||
		b.max.z < a.min.z;
	return !outside;
}