#ifndef ANGLE_H
#define ANGLE_H
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

class angle
{
	double value;

	void check()
	{
		if (value < 0)
		{
			int n = abs((int)(value / (2 * PI)));
			value += (n + 1) * 2 * PI;
		}
		else
		{
			double nn = value / (2 * PI);
			int n = abs((int)(nn));
			if ((nn - n) > 0.999999)
				n++;
			value -= (n)* 2 * PI;
			//printf("%f\n", value);
			//char buf[30];
			//sprintf_s(buf, "%f\n", value);
			//OutputDebugString(buf);
		}
	}

public:
	angle normolize()
	{
		angle a = *this;
		a.check();
		return a;
	}
	double getValue()
	{
		return value;
	}
	angle operator = (angle &a)
	{
		value = a.value;
		return (*this);
	}

	angle operator = (double a)
	{
		value = a;
		//check();
		return (*this);
	}

	angle operator + (angle &a)
	{
		angle a1;
		a1 = value + a.value;
		//a1.check();
		return a1;
	}

	angle operator +(double a)
	{
		angle a1;
		a1.value = value + a;
		//a1.check();
		return a1;
	}

	angle operator - (angle &a)
	{
		angle a1;
		a1 = value - a.value;
		//a1.check();
		return a1;
	}

	angle operator -(double a)
	{
		angle a1;
		a1.value = value - a;
		//a1.check();
		return a1;
	}

	angle operator / (double &a)
	{
		angle a1;
		a1.value = value / a;
		//a1.check();
		return a1;
	}

	angle operator / (angle &a)
	{
		angle a1;
		a1.value = value / a.value;
		//a1.check();
		return a1;
	}
	operator double()
	{
		return value;
	}
};

#endif