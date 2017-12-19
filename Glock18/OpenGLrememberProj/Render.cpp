#include "Render.h"

#include <windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include "MyOGL.h"

#include "Camera.h"
#include "Light.h"
#include "Primitives.h"



bool textureMode = true;
bool lightMode = true;
bool sizenet = false;
bool details = false;
bool reload = false;
bool relended = true;
//bool fire = false;
float timer = 0;
int relflag = 0;

void drawMainPart()
{
	float z = 0;
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, 1.5, z);
	glVertex3f(8, 1.5, z);
	glVertex3f(8, 2, z);
	glVertex3f(0.5, 2, z);
	////////////////////
	//Низ
	////////////////////
	glVertex3f(0.5, 2, z);
	glVertex3f(8, 2, z);
	glVertex3f(8.5, 3.5, z);
	glVertex3f(0.5, 3.5, z);
	////////////////////
	glNormal3f(0, 0, 1);
	glVertex3f(0.5, 3.5, z);
	glVertex3f(8.5, 3.5, z);
	glVertex3f(12, 17.5, z);
	glVertex3f(4.5, 17.5, z);
	////////////////////
	/////////////////////////////////Задник рукоятки
	glNormal3f(-0.7, 0.4, 0);
	glVertex3f(0.5, 3.5, z);
	glVertex3f(-0.5, 3.5, z + 1.5);
	glVertex3f(3.5, 17.5, z + 1.5);
	glVertex3f(4.5, 17.5, z);
	/////////////////////////////////////////////////
	glVertex3f(-0.5, 3.5, z + 1.5);
	glVertex3f(3.5, 17.5, z + 1.5);
	glVertex3f(3.5, 17.5, z + 2.5);
	glVertex3f(-0.5, 3.5, z + 2.5);
	/////////////////////////////////////////////////
	glVertex3f(0.5, 3.5, z + 4);
	glVertex3f(-0.5, 3.5, z + 2.5);
	glVertex3f(3.5, 17.5, z + 2.5);
	glVertex3f(4.5, 17.5, z + 4);
	/////////////////////////////////////////////////
	glVertex3f(0.3, 2, z);
	glVertex3f(0.5, 3.5, z);
	glVertex3f(-0.5, 3.5, z + 1.5);
	glVertex3f(-0.5, 2, z + 1.5);
	////////////////////////////////////////////////
	glVertex3f(-0.5, 3.5, z + 1.5);
	glVertex3f(-0.5, 3.5, z + 2.5);
	glVertex3f(-0.5, 2, z + 2.5);
	glVertex3f(-0.5, 2, z + 1.5);
	///////////////////////////////////////////////
	glVertex3f(-0.5, 3.5, z + 2.5);
	glVertex3f(-0.5, 2, z + 2.5);
	glVertex3f(0.3, 2, z + 4);
	glVertex3f(0.5, 3.5, z + 4);
	//////////////////////////////////////////////
	glVertex3f(0, 1.5, z);
	glVertex3f(0.3, 2, z);
	glVertex3f(-0.5, 2, z + 1.5);
	glVertex3f(-0.7, 1.5, z + 1.5);
	//////////////////////////////////////////////
	glVertex3f(-0.5, 2, z + 1.5);
	glVertex3f(-0.5, 2, z + 2.5);
	glVertex3f(-0.7, 1.5, z + 2.5);
	glVertex3f(-0.7, 1.5, z + 1.5);
	/////////////////////////////////////////////
	glVertex3f(-0.7, 1.5, z + 2.5);
	glVertex3f(0, 1.5, z + 4);
	glVertex3f(0.3, 2, z + 4);
	glVertex3f(-0.5, 2, z + 2.5);
	//////////////////// Конец задника рукоятки
	//////////////////// Низ рукоятки
	glNormal3f(0, -1, 0);
	glVertex3f(0, 1.5, z);
	glVertex3f(-0.7, 1.5, z + 1.5);
	glVertex3f(-0.7, 1.5, z + 2.5);
	glVertex3f(0, 1.5, z + 4);
	///////////////////////////////////
	glVertex3f(0, 1.5, z);
	glVertex3f(0, 1.5, z + 4);
	glVertex3f(0.9, 1.5, z + 4);
	glVertex3f(0.9, 1.5, z);
	//////////////////////////////////
	glVertex3f(0.9, 1.5, z + 4);
	glVertex3f(0.9, 1.5, z + 3.2);
	glVertex3f(8.7, 1.5, z + 3.2);
	glVertex3f(8.7, 1.5, z + 4);
	/////////////////////////////////
	glVertex3f(0.9, 1.5, z);
	glVertex3f(0.9, 1.5, z + 0.6);
	glVertex3f(8.7, 1.5, z + 0.6);
	glVertex3f(8.7, 1.5, z);
	/////////////////////////////////
	glVertex3f(7.8, 1.5, z + 0.6);
	glVertex3f(8.7, 1.5, z + 0.6);
	glVertex3f(8.7, 1.5, z + 3.2);
	glVertex3f(7.8, 1.5, z + 3.2);
	//////////////////// конец низа рукоятки
	//////////////////// Передник рукоятки
	glColor3f(1, 0, 1);
	glNormal3f(1, 0, 0);
	glVertex3f(8.7, 1.5, z);
	glVertex3f(8.7, 1.5, z + 4);
	glVertex3f(8.6, 1.6, z + 4);
	glVertex3f(8.6, 1.6, z);
	//
	glVertex3f(8.6, 1.6, z + 4);
	glVertex3f(8.6, 1.6, z);
	glVertex3f(8.5, 1.7, z);
	glVertex3f(8.5, 1.7, z + 4);
	//
	glVertex3f(8.5, 1.7, z);
	glVertex3f(8.5, 1.7, z + 4);
	glVertex3f(8.3, 1.75, z + 4);
	glVertex3f(8.3, 1.75, z);
	//
	glVertex3f(8.3, 1.75, z + 4);
	glVertex3f(8.3, 1.75, z);
	glVertex3f(8.1, 1.9, z);
	glVertex3f(8.1, 1.9, z + 4);
	//
	glVertex3f(8.1, 1.9, z);
	glVertex3f(8.1, 1.9, z + 4);
	glVertex3f(8, 2, z + 4);
	glVertex3f(8, 2, z);
	////////////////////////////
	glVertex3f(8, 2, z + 4);
	glVertex3f(8, 2, z);
	glVertex3f(8.5, 3.5, z);
	glVertex3f(8.5, 3.5, z + 4);
	/////////////////////////////
	glVertex3f(8.5, 3.5, z);
	glVertex3f(8.5, 3.5, z + 4);
	glVertex3f(12, 17.5, z + 4);
	glVertex3f(12, 17.5, z);
	//////////////////// Конец передника рукоятки
	//////////////////// Низ ствола
	glVertex3f(4.5, 17.5, z);
	glVertex3f(12, 17.5, z);
	glVertex3f(12, 17.5, z - 1.5);
	glVertex3f(3.4, 17.5, z - 1.5);
	//
	glVertex3f(4.5, 17.5, z + 4);
	glVertex3f(12, 17.5, z + 4);
	glVertex3f(12, 17.5, z + 5.5);
	glVertex3f(3.4, 17.5, z + 5.5);
	//
	glVertex3f(12, 17.5, z - 1.5);
	glVertex3f(28.5, 17.5, z - 1.5);
	glVertex3f(28.5, 17.5, z + 5.5);
	glVertex3f(12, 17.5, z + 5.5);
	//
	glVertex3f(28.5, 17.5, z - 1.5);
	glVertex3f(28.5, 17.5, z + 5.5);
	glVertex3f(28.5, 18.5, z + 5.5);
	glVertex3f(28.5, 18.5, z - 1.5);
	//
	glVertex3f(28.5, 18.5, z + 5.5);
	glVertex3f(28.5, 18.5, z - 1.5);
	glVertex3f(30.5, 18.5, z - 1.5);
	glVertex3f(30.5, 18.5, z + 5.5);
	///
	glVertex3f(30.5, 18.5, z - 1.5);
	glVertex3f(30.5, 18.5, z + 5.5);
	glVertex3f(30.5, 17.5, z + 5.5);
	glVertex3f(30.5, 17.5, z - 1.5);
	//////////
	glVertex3f(30.5, 17.5, z + 5.5);
	glVertex3f(30.5, 17.5, z - 1.5);
	glVertex3f(31.5, 17.5, z - 1.5);
	glVertex3f(31.5, 17.5, z + 5.5);
	//////////
	glVertex3f(31.5, 17.5, z - 1.5);
	glVertex3f(31.5, 17.5, z + 5.5);
	glVertex3f(32.5, 18, z + 5.5);
	glVertex3f(32.5, 18, z - 1.5);
	////
	glVertex3f(32.5, 18, z + 5.5);
	glVertex3f(32.5, 18, z - 1.5);
	glVertex3f(33.5, 18, z - 1.5);
	glVertex3f(33.5, 18, z + 5.5);
	///
	glVertex3f(33.5, 18, z - 1.5);
	glVertex3f(33.5, 18, z + 5.5);
	glVertex3f(33.5, 20, z + 5.5);
	glVertex3f(33.5, 20, z - 1.5);
	//////////////////// Конец низа ствола

	/////////////////// Задник ствола
		glColor3f(0.6, 1, 0.12);
	glVertex3f(4.5, 17.5, z-1.5);
	glVertex3f(4.5, 17.5, z + 5.5);
	glVertex3f(2.5, 17.5, z + 5.5);
	glVertex3f(2.5, 17.5, z-1.5);
	////
	glVertex3f(2.5, 17.5, z + 5.5);
	glVertex3f(2.5, 17.5, z - 1.5);
	glVertex3f(2.5, 19.5, z - 1.5);
	glVertex3f(2.5, 19.5, z + 5.5);
	/////
	glVertex3f(2.5, 17.5, z - 1.5);
	glVertex3f(2.5, 19.5, z - 1.5);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(3.5, 17.5, z - 1.5);
	///////
	glVertex3f(2.5, 17.5, z + 5.5);
	glVertex3f(2.5, 19.5, z + 5.5);
	glVertex3f(3.5, 19.5, z + 5.5);
	glVertex3f(3.5, 17.5, z + 5.5);
	/////////////////// Конец задника ствола

	glVertex3f(3.5, 17.5, z - 1.5);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(28.5, 19.5, z - 1.5);
	glVertex3f(28.5, 17.5, z - 1.5);
	////////////////////
	glVertex3f(3.5, 17.5, z - 1.5);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(3, 19.5, z - 1.5);
	glVertex3f(3, 18, z - 1.5);
	////////////////////
	glVertex3f(0, 1.5, z);
	glVertex3f(0.5, 1.5, z);
	glVertex3f(0.5, 2, z);
	glVertex3f(0.3, 2, z);
	////////////////////
	glColor3f(1, 0, 0);
	glVertex3f(12 + 1, 17.5, z + 1);
	glVertex3f(13.5 + 1, 17.5, z + 1);
	glVertex3f(12 + 1, 15.5, z + 1);
	glVertex3f(11.5 + 1, 15.5, z + 1);
	////////////////////////////
	glVertex3f(11.5 + 1, 15.5, z + 1);
	glVertex3f(12 + 1, 15.5, z + 1);
	glVertex3f(13 + 1, 13.5, z + 1);
	glVertex3f(11 + 1, 13.5, z + 1);
	///////////////////////////
	glVertex3f(13 + 1, 13.5, z + 1);
	glVertex3f(12.6 + 1, 14, z + 1);
	glVertex3f(16 + 1, 14, z + 1);
	glVertex3f(16 + 1, 13.5, z + 1);
	/////////////////////////
	glVertex3f(16 + 1, 13.5, z + 1);
	glVertex3f(16 + 1, 14, z + 1);
	glVertex3f(18 + 1, 15.5, z + 1);
	glVertex3f(18 + 1, 13.5, z + 1);
	/////////////////////////
	glVertex3f(12, 17.5, z + 1);
	glVertex3f(13.5, 17.5, z + 1);
	glVertex3f(12, 13.5, z + 1);
	glVertex3f(11, 13.5, z + 1);
	////////////////////////
	glVertex3f(12, 13.5, z + 1);
	glVertex3f(11, 13.5, z + 1);
	glVertex3f(10.5, 12.5, z + 1);
	glVertex3f(10.5, 12.5, z + 1);
	////////////////////////
	glColor3f(0, 0, 1);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(3.5, 21, z - 1.5);
	glVertex3f(28.5, 21, z - 1.5);
	glVertex3f(28.5, 19.5, z - 1.5);
	/////////////////////////
	glVertex3f(28.5, 18.5, z - 1.5);
	glVertex3f(28.5, 21, z - 1.5);
	glVertex3f(30.5, 21, z - 1.5);
	glVertex3f(30.5, 18.5, z - 1.5);
	/////////////////////////
	glVertex3f(30.5, 21, z - 1.5);
	glVertex3f(30.5, 18, z - 1.5);
	glVertex3f(33.5, 18, z - 1.5);
	glVertex3f(33.5, 21, z - 1.5);
	////////////////////////
	glVertex3f(30.5, 18, z - 1.5);
	glVertex3f(30.5, 17.5, z - 1.5);
	glVertex3f(31.5, 17.5, z - 1.5);
	glVertex3f(32.5, 18, z - 1.5);
	glEnd();

	//////////////
	glColor3f(0.4, 0, 0);
	glBegin(GL_QUAD_STRIP);
	glVertex3f(18 + 1, 13.5, z + 1);
	glVertex3f(19 + 1, 13.5, z + 1);
	glVertex3f(18 + 1, 14.5, z + 1);
	glVertex3f(18.5 + 1, 14.5, z + 1);
	glVertex3f(18 + 1, 15.5, z + 1);
	glVertex3f(18.5 + 1, 15.5, z + 1);
	glVertex3f(18 + 1, 16, z + 1);
	glVertex3f(18.5 + 1, 16, z + 1);
	glVertex3f(17.5 + 1, 17.5, z + 1);
	glVertex3f(19.5 + 1, 17.5, z + 1);
	glEnd();
	////////////////////////////
	glBegin(GL_QUAD_STRIP);
	glColor3f(0, 1, 0.5);
	glVertex3f(3.5, 19.5, z + 1.5);
	glVertex3f(2.3, 19.5, z + 1.5);
	glVertex3f(3.5, 20, z + 1.5);
	glVertex3f(2.5, 20, z + 1.5);
	glVertex3f(3.5, 20.5, z + 1.5);
	glVertex3f(2.7, 20.5, z + 1.5);
	glVertex3f(3.5, 21, z + 1.5);
	glVertex3f(2.9, 21, z + 1.5);
	glVertex3f(3.5, 21.5, z + 1.5);
	glVertex3f(3.1, 21.5, z + 1.5);
	glEnd();
	/////////////////////////////
	glBegin(GL_QUAD_STRIP);
	glColor3f(0, 0.8, 0.2);
	glVertex3f(14.5, 17.5, z + 1);
	glVertex3f(14.5, 17.5, z + 3);
	glVertex3f(13, 15.5, z + 1);
	glVertex3f(13, 15.5, z + 3);
	glVertex3f(13.5, 14, z + 1);
	glVertex3f(13.5, 14, z + 3);
	glVertex3f(17, 14, z + 1);
	glVertex3f(17, 14, z + 3);
	glVertex3f(18.5, 15, z + 1);
	glVertex3f(18.5, 15, z + 3);
	glVertex3f(19, 15.5, z + 1);
	glVertex3f(19, 15.5, z + 3);
	glVertex3f(19, 16, z + 1);
	glVertex3f(19, 16, z + 3);
	glVertex3f(18.5, 17.5, z + 1);
	glVertex3f(18.5, 17.5, z + 3);
	glEnd();
	////////////////////////////
	glColor3f(1, 1, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.3, 2, z);
	glVertex3f(0.5, 2, z);
	glVertex3f(0.5, 3.5, z);
	/////////////////////////////
	/////////////////////////////
	glVertex3f(3, 18, z + 1.5);
	glVertex3f(3, 19.5, z + 1.5);
	glVertex3f(2.3, 19.5, z + 1.5);
	/////////////////////////////

	glEnd();
	//////////
	float u = z;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(8, 1.5, z);
	glVertex3f(8.7, 1.5, z);
	glVertex3f(8.6, 1.6, z);
	glVertex3f(8.5, 1.7, z);
	glVertex3f(8.3, 1.75, z);
	glVertex3f(8.25, 1.85, z);
	glVertex3f(8.1, 1.9, z);
	glVertex3f(8, 2, z);
	glEnd();
	z = z + 4;
	/////////////////////////
	glBegin(GL_QUADS);
	glVertex3f(0.5, 1.5, z);
	glVertex3f(8, 1.5, z);
	glVertex3f(8, 2, z);
	glVertex3f(0.5, 2, z);
	////////////////////
	glVertex3f(0.5, 2, z);
	glVertex3f(8, 2, z);
	glVertex3f(8.5, 3.5, z);
	glVertex3f(0.5, 3.5, z);
	////////////////////
	glVertex3f(0.5, 3.5, z);
	glVertex3f(8.5, 3.5, z);
	glVertex3f(12, 17.5, z);
	glVertex3f(4.5, 17.5, z);
	////////////////////
	glVertex3f(3.5, 17.5, z + 1.5);
	glVertex3f(3.5, 19.5, z + 1.5);
	glVertex3f(28.5, 19.5, z + 1.5);
	glVertex3f(28.5, 17.5, z + 1.5);
	////////////////////
	glVertex3f(3.5, 17.5, z + 1.5);
	glVertex3f(3.5, 19.5, z + 1.5);
	glVertex3f(3, 19.5, z + 1.5);
	glVertex3f(3, 18, z + 1.5);
	////////////////////
	glVertex3f(0, 1.5, z);
	glVertex3f(0.5, 1.5, z);
	glVertex3f(0.5, 2, z);
	glVertex3f(0.3, 2, z);
	////////////////////
	glColor3f(1, 0, 0);
	glVertex3f(12 + 1, 17.5, z - 1);
	glVertex3f(13.5 + 1, 17.5, z - 1);
	glVertex3f(12 + 1, 15.5, z - 1);
	glVertex3f(11.5 + 1, 15.5, z - 1);
	////////////////////////////
	glVertex3f(11.5 + 1, 15.5, z - 1);
	glVertex3f(12 + 1, 15.5, z - 1);
	glVertex3f(13 + 1, 13.5, z - 1);
	glVertex3f(11 + 1, 13.5, z - 1);
	///////////////////////////
	glVertex3f(13 + 1, 13.5, z - 1);
	glVertex3f(12.6 + 1, 14, z - 1);
	glVertex3f(16 + 1, 14, z - 1);
	glVertex3f(16 + 1, 13.5, z - 1);
	/////////////////////////
	glVertex3f(16 + 1, 13.5, z - 1);
	glVertex3f(16 + 1, 14, z - 1);
	glVertex3f(18 + 1, 15.5, z - 1);
	glVertex3f(18 + 1, 13.5, z - 1);
	/////////////////////////
	glVertex3f(12, 17.5, z - 1);
	glVertex3f(13.5, 17.5, z - 1);
	glVertex3f(12, 13.5, z - 1);
	glVertex3f(11, 13.5, z - 1);
	/////////////////////////
	glVertex3f(12, 13.5, z - 1);
	glVertex3f(11, 13.5, z - 1);
	glVertex3f(10.5, 12.5, z - 1);
	glVertex3f(10.5, 12.5, z - 1);
	/////////////////////////
	glColor3f(0, 0, 1);
	glVertex3f(3.5, 19.5, z + 1.5);
	glVertex3f(3.5, 21, z + 1.5);
	glVertex3f(28.5, 21, z + 1.5);
	glVertex3f(28.5, 19.5, z + 1.5);
	/////////////////////////
	glVertex3f(28.5, 18.5, z + 1.5);
	glVertex3f(28.5, 21, z + 1.5);
	glVertex3f(30.5, 21, z + 1.5);
	glVertex3f(30.5, 18.5, z + 1.5);
	/////////////////////////
	glVertex3f(30.5, 21, z + 1.5);
	glVertex3f(30.5, 18, z + 1.5);
	glVertex3f(33.5, 18, z + 1.5);
	glVertex3f(33.5, 21, z + 1.5);
	////////////////////////
	glVertex3f(30.5, 18, z + 1.5);
	glVertex3f(30.5, 17.5, z + 1.5);
	glVertex3f(31.5, 17.5, z + 1.5);
	glVertex3f(32.5, 18, z + 1.5);
	glEnd();

	//////////////
	glBegin(GL_QUAD_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(18 + 1, 13.5, z - 1);
	glVertex3f(19 + 1, 13.5, z - 1);
	glVertex3f(18 + 1, 14.5, z - 1);
	glVertex3f(18.5 + 1, 14.5, z - 1);
	glVertex3f(18 + 1, 15.5, z - 1);
	glVertex3f(18.5 + 1, 15.5, z - 1);
	glVertex3f(18 + 1, 16, z - 1);
	glVertex3f(18.5 + 1, 16, z - 1);
	glVertex3f(17.5 + 1, 17.5, z - 1);
	glVertex3f(19.5 + 1, 17.5, z - 1);
	glEnd();
	////////////////////////////
	glBegin(GL_QUAD_STRIP);
	glColor3f(0, 0, 1);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(2.3, 19.5, z - 1.5);
	glVertex3f(3.5, 20, z - 1.5);
	glVertex3f(2.5, 20, z - 1.5);
	glVertex3f(3.5, 20.5, z - 1.5);
	glVertex3f(2.7, 20.5, z - 1.5);
	glVertex3f(3.5, 21, z - 1.5);
	glVertex3f(2.9, 21, z - 1.5);
	glVertex3f(3.5, 21.5, z - 1.5);
	glVertex3f(3.1, 21.5, z - 1.5);
	glEnd();
	////////////////////////////
	glColor3f(1, 0, 0);
	glBegin(GL_QUAD_STRIP);
	glVertex3f(10.5, 12.5, z - 1);
	glVertex3f(10.5, 12.5, z - 3);
	glVertex3f(12, 13.5, z - 1);
	glVertex3f(12, 13.5, z - 3);
	glVertex3f(20, 13.5, z - 1);
	glVertex3f(20, 13.5, z - 3);
	glVertex3f(19.5, 14.5, z - 1);
	glVertex3f(19.5, 14.5, z - 3);
	glVertex3f(19, 15.5, z - 1);
	glVertex3f(19, 15.5, z - 3);
	glVertex3f(19, 16, z - 1);
	glVertex3f(19, 16, z - 3);
	glVertex3f(20.5, 17.5, z - 1);
	glVertex3f(20.5, 17.5, z - 3);
	glEnd();
	////////////////////////////
	glBegin(GL_TRIANGLES);
	glVertex3f(0.3, 2, z);
	glVertex3f(0.5, 2, z);
	glVertex3f(0.5, 3.5, z);
	/////////////////////////////
	/////////////////////////////
	glVertex3f(3, 18, z - 1.5);
	glVertex3f(3, 19.5, z - 1.5);
	glVertex3f(2.3, 19.5, z - 1.5);
	/////////////////////////////

	glEnd();
	//////////
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(8, 1.5, z);
	glVertex3f(8.7, 1.5, z);
	glVertex3f(8.6, 1.6, z);
	glVertex3f(8.5, 1.7, z);
	glVertex3f(8.3, 1.75, z);
	glVertex3f(8.25, 1.85, z);
	glVertex3f(8.1, 1.9, z);
	glVertex3f(8, 2, z);
	glEnd();
	////////////////////////////////////////////////////////////////////////////
	glBegin(GL_QUAD_STRIP);
	glVertex3f(3, 18, z - 1.5);
	glVertex3f(3, 18, z - 2.5);
	glVertex3f(3, 19.5, z - 1.5);
	glVertex3f(3, 19.5, z - 2.5);
	glVertex3f(3.5, 19.5, z - 1.5);
	glVertex3f(3.5, 19.5, z - 2.5);
	glVertex3f(3.5, 21.5, z - 1.5);
	glVertex3f(3.5, 21.5, z - 2.5);
	glVertex3f(3.1, 21.5, z - 1.5);
	glVertex3f(3.1, 21.5, z - 2.5);
	glVertex3f(2.3, 19.5, z - 1.5);
	glVertex3f(2.3, 19.5, z - 2.5);
	glVertex3f(3, 18, z - 1.5);
	glVertex3f(3, 18, z - 2.5);

	glEnd();
}
void drawUpPart()
{
	glBegin(GL_QUADS);
	glVertex3f(0, 31, 0);
	glVertex3f(0, 31, 9);
	glVertex3f(32, 31, 9);
	glVertex3f(32, 31, 0);
	////////
	glVertex3f(32, 31, 0);
	glVertex3f(0, 31, 0);
	glVertex3f(0, 27, 0);
	glVertex3f(32, 27, 0);
	////////
	glVertex3f(32, 31, 9);
	glVertex3f(0, 31, 9);
	glVertex3f(0, 27, 9);
	glVertex3f(32, 27, 9);
	///////////
	glColor3f(0, 0, 1);
	glVertex3f(0, 31, 0);
	glVertex3f(0, 31, 4);
	glVertex3f(0, 27, 4);
	glVertex3f(0, 27, 0);
	////////////
	glVertex3f(0, 31, 9);
	glVertex3f(0, 31, 5);
	glVertex3f(0, 27, 5);
	glVertex3f(0, 27, 9);
	///////////
	glVertex3f(0, 31, 3.5);
	glVertex3f(0, 31, 5);
	glVertex3f(0, 29, 5);
	glVertex3f(0, 29, 3.5);
	//////////
	glColor3f(0, 0.3, 0.84);
	glVertex3f(0, 27, 0);
	glVertex3f(0, 27, 1);
	glVertex3f(31, 27, 1);
	glVertex3f(31, 27, 0);
	////////////
	glVertex3f(0, 27, 9);
	glVertex3f(0, 27, 8);
	glVertex3f(31, 27, 8);
	glVertex3f(31, 27, 9);
	////
	glVertex3f(31, 27, 9);
	glVertex3f(31, 27, 0);
	glVertex3f(32, 27, 0);
	glVertex3f(32, 27, 9);
	/////////
	glVertex3f(32, 27, 0);
	glVertex3f(32, 31, 0);
	glVertex3f(32, 31, 3.5);
	glVertex3f(32, 27, 3.5);
	////////
	glVertex3f(32, 27, 9);
	glVertex3f(32, 31, 9);
	glVertex3f(32, 31, 5.5);
	glVertex3f(32, 27, 5.5);
	//////////
	glVertex3f(32, 27, 3.5);
	glVertex3f(32, 27, 5.5);
	glVertex3f(32, 28.177, 5.5);
	glVertex3f(32, 28.177, 3.5);
	//////////
	glVertex3f(32, 29.866, 3.5);
	glVertex3f(32, 29.866, 5.5);
	glVertex3f(32, 31, 5.5);
	glVertex3f(32, 31, 3.5);
	glEnd();
}
void drawMagazine()
{
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(0, 1.5, 0);
	glVertex3f(6, 1.5, 0);
	glVertex3f(10, 18 + 1.5, 0);
	glVertex3f(4, 18 + 1.5, 0);
	//////////////////////
	glNormal3f(0, 0, 1);
	glVertex3f(0, 1.5, 2.5);
	glVertex3f(6, 1.5, 2.5);
	glVertex3f(10, 18 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 2.5);
	/////////////////////
	glVertex3f(0, 0 + 1.5, 0);
	glVertex3f(0, 0 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 0);
	/////////////////////
	glVertex3f(6, 0 + 1.5, 0);
	glVertex3f(6, 0 + 1.5, 2.5);
	glVertex3f(10, 18 + 1.5, 2.5);
	glVertex3f(10, 18 + 1.5, 0);
	///////////////////////
	glVertex3f(-.5, 0, 0);
	glVertex3f(7, 0, 0);
	glVertex3f(6, 1.5, 0);
	glVertex3f(0, 1.5, 0);
	//////////////////////
	glVertex3f(-.5, 0, 2.5);
	glVertex3f(7, 0, 2.5);
	glVertex3f(6, 1.5, 2.5);
	glVertex3f(0, 1.5, 2.5);
	//////////////////////
	glVertex3f(-.5, 0, 0);
	glVertex3f(-.5, 0, 2.5);
	glVertex3f(6, 1.5, 2.5);
	glVertex3f(6, 1.5, 0);
	//////////////////////
	glVertex3f(-.5, 0, 0);
	glVertex3f(-.5, 0, 2.5);
	glVertex3f(0, 1.5, 2.5);
	glVertex3f(0, 1.5, 0);
	//////////////////////
	glVertex3f(7, 0, 0);
	glVertex3f(7, 0, 2.5);
	glVertex3f(6, 1.5, 2.5);
	glVertex3f(6, 1.5, 0);
	//////////////////////
	glNormal3f(0, 1, 0);
	glVertex3f(10, 18 + 1.5, 0);
	glVertex3f(10, 18 + 1.5, 1.5);
	glVertex3f(4, 18 + 1.5, 1.5);
	glVertex3f(4, 18 + 1.5, 0);
	//////////////////////
	glNormal3f(0, 1, 0);
	glVertex3f(10, 18 + 1.5, 2.5);
	glVertex3f(10, 18 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 2.5);
	//////////////////////
	glNormal3f(0, 1, 0);
	glVertex3f(10, 18 + 1.5, 1.5);
	glVertex3f(10, 18 + 1.5, 2.5);
	glVertex3f(8, 18 + 1.5, 2.5);
	glVertex3f(8, 18 + 1.5, 1.5);
	//////////////////////
	glVertex3f(4, 18 + 1.5, 2.5);
	glVertex3f(4, 18 + 1.5, 1.5);
	glVertex3f(6, 18 + 1.5, 1.5);
	glVertex3f(6, 18 + 1.5, 2.5);
	//////////////////////
	glEnd();
}
bool Sizenet()
{
	float i = 0;
	int h = 0;
	glLineWidth(2);
		glBegin(GL_LINES);
		for (i = -5; i < 101; i++)
		{
			if ((h = i) % 5 == 0)
			{
				glVertex2f(50, i / 2);
				glVertex2f(-10, i / 2);
				glVertex2f(i / 2, -2);
				glVertex2f(i / 2, 50);
			}

			else {
				glVertex2f(50, i / 2);
				glVertex2f(-5, i / 2);
				glVertex2f(i / 2, -1);
				glVertex2f(i / 2, 50);
			}
		}
		glEnd();
		return 1;
}
void drawTube(float r)
{
	float x = 0, y = 0, z = 0;
	glBegin(GL_QUAD_STRIP);
	glColor3d(0, 1, 1);
	for (int i = 0; i <= 360; i++) {
		x = r*cos(i*M_PI / 180);
		y = r*sin(i*M_PI / 180);
		glVertex3d(x, y, 0);
		glVertex3d(x, y, 26.5);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glColor3d(0, 1, 1);
	for (int i = 0; i <= 360; i++) {
		x = r / 1.5*cos(i*M_PI / 180);
		y = r / 1.5*sin(i*M_PI / 180);
		glVertex3d(x, y, 0);
		glVertex3d(x, y, 26.5);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	float x1, y1, z1;
	glColor3d(1, 0, 1);
	for (int i = 0; i <= 360; i++)
	{
		x = r / 1.5*cos(i*M_PI / 180);
		y = r / 1.5*sin(i*M_PI / 180);
		x1 = r*cos(i*M_PI / 180);
		y1 = r*sin(i*M_PI / 180);
		glVertex3d(x, y, 0);
		glVertex3d(x1, y1, 0);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	x1 = 0, y1 = 0;
	glColor3d(1, 0, 1);
	for (int i = 0; i <= 360; i++)
	{
		x = r / 1.5*cos(i*M_PI / 180);
		y = r / 1.5*sin(i*M_PI / 180);
		x1 = r*cos(i*M_PI / 180);
		y1 = r*sin(i*M_PI / 180);
		glVertex3d(x, y, 26.5);
		glVertex3d(x1, y1, 26.5);
	}
	glEnd();
}
void drawTrigger()
{
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(-1, 0, 0);
	glVertex3f(-1.5, 4, 0);
	glVertex3f(-0.5, 4, 0);
	/////
	glVertex3f(0, 0, -0.5);
	glVertex3f(-1, 0, -0.5);
	glVertex3f(-1.5, 4, -0.5);
	glVertex3f(-0.5, 4, -0.5);
	//////
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -0.5);
	glVertex3f(-0.5, 4, -0.5);
	glVertex3f(-0.5, 4, 0);
	///////
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -0.5);
	glVertex3f(-1, 0, -0.5);
	glVertex3f(-1, 0, 0);
	//////////
	glVertex3f(-0.5, 4, -0.5);
	glVertex3f(-0.5, 4, 0);
	glVertex3f(-1.5, 4, 0);
	glVertex3f(-1.5, 4, -0.5);
	//////
	glVertex3f(-1.5, 4, -0.5);
	glVertex3f(-1.5, 4, 0);
	glVertex3f(-1, 0, 0);
	glVertex3f(-1, 0, -0.5);
	glEnd();
}
void Reloading()
{
	static float tempX;
	static float tempY;
	int reloadTime = 45;
	relended = false;
	glPushMatrix();
	if (timer>reloadTime*(-1) && relflag == 0)
	{
		glTranslatef(tempX = 1.2 + timer / 5.0, tempY = 0.8 + timer, 0.65);
		drawMagazine();
		timer--;
	}
	else
	{
		if (relflag == 0) timer = 0;
		relflag = 1;
	}
	if (timer < reloadTime-1 && relflag == 1)
	{
		glTranslatef(tempX + timer / 5.0, tempY + timer, 0.65);
		drawMagazine();
		timer++;
	}
	else { if (relflag == 1) { reload = false; timer = 0; relflag = 0; tempX = 0; tempY = 0; relended = true; } }

	glPopMatrix();
	drawMainPart();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-2, 21.5, 10);
	drawTube(1.25);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5, -7.5, -2.5);
	drawUpPart();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(17, 15, 2.5);
	drawTrigger();
	glPopMatrix();
}

//класс для настройки камеры
class CustomCamera : public Camera
{
public:
	//дистанция камеры
	double camDist;
	//углы поворота камеры
	double fi1, fi2;

	
	//значния масеры по умолчанию
	CustomCamera()
	{
		camDist = 15;
		fi1 = 1;
		fi2 = 1;
	}

	
	//считает позицию камеры, исходя из углов поворота, вызывается движком
	void SetUpCamera()
	{
		//отвечает за поворот камеры мышкой
		lookPoint.setCoords(0, 0, 0);

		pos.setCoords(camDist*cos(fi2)*cos(fi1),
			camDist*cos(fi2)*sin(fi1),
			camDist*sin(fi2));

		if (cos(fi2) <= 0)
			normal.setCoords(0, 0, -1);
		else
			normal.setCoords(0, 0, 1);

		LookAt();
	}

	void CustomCamera::LookAt()
	{
		//функция настройки камеры
		gluLookAt(pos.X(), pos.Y(), pos.Z(), lookPoint.X(), lookPoint.Y(), lookPoint.Z(), normal.X(), normal.Y(), normal.Z());
	}



}  camera;   //создаем объект камеры


//Класс для настройки света
class CustomLight : public Light
{
public:
	CustomLight()
	{
		//начальная позиция света
		pos = Vector3(1, 1, 3);
	}

	
	//рисует сферу и линии под источником света, вызывается движком
	void  DrawLightGhismo()
	{
		glDisable(GL_LIGHTING);

		
		glColor3d(0.9, 0.8, 0);
		Sphere s;
		s.pos = pos;
		s.scale = s.scale*0.08;
		s.Show();
		
		if (OpenGL::isKeyPressed('G'))
		{
			glColor3d(0, 0, 0);
			//линия от источника света до окружности
			glBegin(GL_LINES);
			glVertex3d(pos.X(), pos.Y(), pos.Z());
			glVertex3d(pos.X(), pos.Y(), 0);
			glEnd();

			//рисуем окруность
			Circle c;
			c.pos.setCoords(pos.X(), pos.Y(), 0);
			c.scale = c.scale*1.5;
			c.Show();
		}

	}

	void SetUpLight()
	{
		GLfloat amb[] = { 0.2, 0.2, 0.2, 0 };
		GLfloat dif[] = { 1.0, 1.0, 1.0, 0 };
		GLfloat spec[] = { .7, .7, .7, 0 };
		GLfloat position[] = { pos.X(), pos.Y(), pos.Z(), 1. };

		// параметры источника света
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		// характеристики излучаемого света
		// фоновое освещение (рассеянный свет)
		glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
		// диффузная составляющая света
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
		// зеркально отражаемая составляющая света
		glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

		glEnable(GL_LIGHT0);
	}


} light;  //создаем источник света




//старые координаты мыши
int mouseX = 0, mouseY = 0;

void mouseEvent(OpenGL *ogl, int mX, int mY)
{
	int dx = mouseX - mX;
	int dy = mouseY - mY;
	mouseX = mX;
	mouseY = mY;

	//меняем углы камеры при нажатой правой кнопке мыши
	if (OpenGL::isKeyPressed(VK_RBUTTON))
	{
		camera.fi1 += 0.01*dx;
		camera.fi2 += -0.01*dy;
	}

	
	//двигаем свет по плоскости, в точку где мышь
	if (OpenGL::isKeyPressed('G') && !OpenGL::isKeyPressed(VK_LBUTTON))
	{
		LPPOINT POINT = new tagPOINT();
		GetCursorPos(POINT);
		ScreenToClient(ogl->getHwnd(), POINT);
		POINT->y = ogl->getHeight() - POINT->y;

		Ray r = camera.getLookRay(POINT->x, POINT->y);

		double z = light.pos.Z();

		double k = 0, x = 0, y = 0;
		if (r.direction.Z() == 0)
			k = 0;
		else
			k = (z - r.origin.Z()) / r.direction.Z();

		x = k*r.direction.X() + r.origin.X();
		y = k*r.direction.Y() + r.origin.Y();

		light.pos = Vector3(x, y, z);
	}

	if (OpenGL::isKeyPressed('G') && OpenGL::isKeyPressed(VK_LBUTTON))
	{
		light.pos = light.pos + Vector3(0, 0, 0.02*dy);
	}

	/*if (OpenGL::isKeyPressed(VK_LBUTTON))
	{
		fire = !fire;
	}*/

	
}

void mouseWheelEvent(OpenGL *ogl, int delta)
{

	if (delta < 0 && camera.camDist <= 1)
		return;
	if (delta > 0 && camera.camDist >= 100)
		return;

	camera.camDist += 0.01*delta;

}

void keyDownEvent(OpenGL *ogl, int key)
{
	if (key == 'L')
	{
		lightMode = !lightMode;
	}

	if (key == 'T')
	{
		textureMode = !textureMode;
	}

	if (key == 'K')
	{
		camera.fi1 = 1;
		camera.fi2 = 1;
		camera.camDist = 15;

		light.pos = Vector3(1, 1, 3);
	}

	if (key == 'F')
	{
		light.pos = camera.pos;
	}
	
	/*if (key == 'S')
	{
		sizenet = !sizenet;
	}*/
	if (key == 'D' && relended == true)
	{
		details = !details;
	}
	if (key == 'R' && relended==true && details== false)
	{
		reload = !reload;
	}
	/*if (key == 'Z')
	{
		fire = !fire;
	}*/
}

void keyUpEvent(OpenGL *ogl, int key)
{
	
}




//выполняется перед первым рендером
void initRender(OpenGL *ogl)
{
	//настройка текстур

	//4 байта на хранение пикселя
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	//настройка режима наложения текстур
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//включаем текстуры
	glEnable(GL_TEXTURE_2D);
	

	//массив трехбайтных элементов  (R G B)
	RGBTRIPLE *texarray;

	//массив символов, (высота*ширина*4      4, потомучто   выше, мы указали использовать по 4 байта на пиксель текстуры - R G B A)
	char *texCharArray;
	int texW, texH;
	OpenGL::LoadBMP("DSP.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);

	
	GLuint texId;
	//генерируем ИД для текстуры
	glGenTextures(1, &texId);
	//биндим айдишник, все что будет происходить с текстурой, будте происходить по этому ИД
	glBindTexture(GL_TEXTURE_2D, texId);

	//загружаем текстуру в видеопямять, в оперативке нам больше  она не нужна
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//отчистка памяти
	free(texCharArray);
	free(texarray);

	//наводим шмон
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	//камеру и свет привязываем к "движку"
	ogl->mainCamera = &camera;
	ogl->mainLight = &light;

	// нормализация нормалей : их длины будет равна 1
	glEnable(GL_NORMALIZE);

	// устранение ступенчатости для линий
	glEnable(GL_LINE_SMOOTH); 


	//   задать параметры освещения
	//  параметр GL_LIGHT_MODEL_TWO_SIDE - 
	//                0 -  лицевые и изнаночные рисуются одинаково(по умолчанию), 
	//                1 - лицевые и изнаночные обрабатываются разными режимами       
	//                соответственно лицевым и изнаночным свойствам материалов.    
	//  параметр GL_LIGHT_MODEL_AMBIENT - задать фоновое освещение, 
	//                не зависящее от сточников
	// по умолчанию (0.2, 0.2, 0.2, 1.0)

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
}





void Render(OpenGL *ogl)
{       	
	
	
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);
	if (textureMode)
		glEnable(GL_TEXTURE_2D);

	if (lightMode)
		glEnable(GL_LIGHTING);


	//альфаналожение
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//настройка материала
	GLfloat amb[] = { 0.0, 0.0, 0.0, 1. };
	GLfloat dif[] = { 0.85, 0.85, 0.85, 1. };
	GLfloat spec[] = { 0.4, 0.2, 0.5, 1. };
	GLfloat emis[] = { 0,0.7,0,1. };
	GLfloat sh = 0.25f * 125;


	//фоновая
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	//дифузная
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	//зеркальная
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);\
	//размер блика
	glMaterialf(GL_FRONT, GL_SHININESS, sh);
	// Собственное излучение
	//glMaterialfv(GL_FRONT, GL_EMISSION, emis);

    //чтоб было красиво, без квадратиков (сглаживание освещения)
	glShadeModel(GL_SMOOTH);
	//===================================
	//Прогать тут  
	static float u = 0;
	glPushMatrix();
	glColor3f(1, 1, 1);
	//glRotatef(-5, 0, 1, 0);
	glRotatef(8, 1, 0, 0);
	if (sizenet == true) Sizenet();
	if (details == false) 
	{
		glPushMatrix();
		glTranslatef(1.2, 0.8, 0.65);
		if(reload==false) drawMagazine();
		glPopMatrix();
		drawMainPart();
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-2, 21.5, 10);
		drawTube(1.25);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.5, -7.5, -2.5);
		drawUpPart();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(17, 15, 2.5);
		drawTrigger();
		glPopMatrix();
	}
	if (details == true)
	{
		glPushMatrix();
		glTranslatef(10.2, 0.8, 0.65);
		drawMagazine();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 20, 0);
		drawMainPart();
		glPushMatrix();
		glTranslatef(17, 15, 2.5);
		drawTrigger();
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-1.5, 46.5, 10);
		drawTube(1.25);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.5, 25.5, -2.5);
		drawUpPart();
		glPopMatrix();
	}

	if (details == false && reload == true)
	{
		Reloading();
	}
	glPopMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(-200, -200, 0);
	glTexCoord2f(-1.0, 1.0);
	glVertex3f(-200, 200, 0);
	glTexCoord2f(1.0/3, 1.0/3);
	glVertex3f(200, 200, 0);
	glTexCoord2f(1.0/3, -1.0/3);
	glVertex3f(200, -200, 0);
	glEnd();

	/*if (details == false && fire == true)
	{
		glPushMatrix();
		glTranslatef(1.2, 0.8, 0.65);
		if (reload == false) drawMagazine();
		glPopMatrix();
		drawMainPart();
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-2, 21.5, 10);
		drawTube(1.25);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.5, -7.5, -2.5);
		drawUpPart();
		glPopMatrix();
		glPushMatrix();
		if (timer<25) 
		{
			static float u = 5;
			glTranslatef(17-timer/5, 15+timer/20, 2.5);
			glRotatef(u-=2.5 ,0, 0, 1);
			drawTrigger();
			timer++;
		}
		
		glPopMatrix();
	}*/
	
	
	//текст сообщения вверху слева, если надоест - закоментировать, или заменить =)
	char c[1000];  //максимальная длина сообщения
	sprintf_s(c, "(T)Текстуры - %d\n(L)Свет - %d\n\nУправление светом:\n"
		"G - перемещение в горизонтальной плоскости,\nG+ЛКМ+перемещение по вертикальной линии\n"
		"K - установить камеру и свет в начальное положение\n"
		"R - перезарядка\n"
		"D - разобрать/собрать пистолет\n"
		"F - переместить свет в точку камеры", textureMode, lightMode);
	ogl->message = std::string(c);




}   //конец тела функции

