#include "Object.h"

void Object::movie(GLdouble x, GLdouble y, GLdouble z)
{
	Vector3 v(x, y, z);
	movie(v);
}

void Object::movie(Vector3 &v)
{
	pos = pos + v;
}