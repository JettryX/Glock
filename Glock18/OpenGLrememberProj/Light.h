#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"

class Light : public Object
{
public:
	virtual void DrawLightGhismo()=0;
	virtual void SetUpLight()=0;
};


#endif