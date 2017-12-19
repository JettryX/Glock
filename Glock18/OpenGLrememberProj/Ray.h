#ifndef RAY_H
#define RAY_H

#include "MyVector3d.h"

//луч
class Ray
{
public:
	//точка начала
	Vector3 origin;

	//напрввление
	Vector3 direction;
};

#endif