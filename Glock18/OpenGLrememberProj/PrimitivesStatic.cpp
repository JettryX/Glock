#include "PrimitivesStatic.h"

#define _USE_MATH_DEFINES
#include <math.h>

std::vector<Vector3> CircleStatic::points;
std::vector<Vector3> SphereStatic::points;

void CircleStatic::MakeVertex()
{
		
		double k = M_PI / 180;
		double rad;
		for (int i = 0; i <= 360; i += 10)
		{
			rad = i*k;
			points.push_back(Vector3(sin(rad), cos(rad), 0));
		}
		
	
}

void SphereStatic::MakeVertex()
{
	int step = 15;
	for (int fi = 0; fi < 180; fi+=step)
	{
		for (int eta = 0; eta < 360; eta+=step)
		{
			points.push_back(Vector3(sin(eta*M_PI / 180)*sin(fi*M_PI / 180), cos(eta*M_PI / 180)*sin(fi*M_PI / 180), cos(fi*M_PI / 180)));
			points.push_back(Vector3(sin(eta*M_PI / 180)*sin((fi + step)*M_PI / 180), cos(eta*M_PI / 180)*sin((fi + step)*M_PI / 180), cos((fi + step)*M_PI / 180)));
			//points.push_back(Vector3(sin((eta + step)*M_PI / 180)*sin((fi + step)*M_PI / 180), cos((eta + step)*M_PI / 180)*sin((fi + step)*M_PI / 180), cos((fi + step)*M_PI / 180)));
		}
	}
}
