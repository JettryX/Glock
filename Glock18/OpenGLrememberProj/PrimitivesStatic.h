#ifndef PRIMITIVESSTATIC_H
#define PRIMITIVESSTATIC_H

#include <vector>
#include "MyVector3d.h"

class Circle;
class Sphere;
class OpenGL;


//класс для храрения точек окоружности.
//функция их расчета void MakeVertex() вызывается в OpenGL::init(void) -  MyOGL.cpp


class CircleStatic
{
	static std::vector <Vector3> points;
	static void MakeVertex();

	friend Circle;
	friend OpenGL;
};

class SphereStatic
{
	static std::vector <Vector3> points;
	static void MakeVertex();

	friend Sphere;
	friend OpenGL;
};

#endif