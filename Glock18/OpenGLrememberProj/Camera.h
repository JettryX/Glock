#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"
#include "MyVector3d.h"
#include "Ray.h"


//��������� ��� ������� � ������
class Camera : public Object
{
public:

	Vector3 lookPoint;
	Vector3 normal;

	Camera()
	{

	}

	virtual void LookAt()=0;

	virtual void SetUpCamera()=0;

	//������ ������ �� ����� �� ����������� � ���� � ����� �����.
	static Ray getLookRay(int wndX, int wndY)
	{
		GLint    viewport[4];    // ��������� viewport-a.
		GLdouble projection[16]; // ������� ��������.
		GLdouble modelview[16];  // ������� �������.
//		GLdouble vx, vy, vz;       // ���������� ������� ���� � ������� ��������� viewport-a.
		GLdouble wx, wy, wz;       // ������������ ������� ����������.

		glGetIntegerv(GL_VIEWPORT, viewport);           // ����� ��������� viewport-a.
		glGetDoublev(GL_PROJECTION_MATRIX, projection); // ����� ������� ��������.
		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);   // ����� ������� �������.
		// ��������� ������� ���������� ������� � ������� ��������� viewport-a.
				 
		gluUnProject(wndX, wndY, 0, modelview, projection, viewport, &wx, &wy, &wz);
		Vector3 o(wx, wy, wz);
		gluUnProject(wndX, wndY, 1, modelview, projection, viewport, &wx, &wy, &wz);
		Vector3 p(wx, wy, wz);
		Ray r;
		r.origin = o;
		r.direction = (p - o).normolize();
		return r;

	}
};

#endif