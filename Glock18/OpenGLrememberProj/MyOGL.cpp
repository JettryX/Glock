#include "MyOGL.h"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>



#include "Camera.h"
#include "Light.h"
#include "PrimitivesStatic.h"





OpenGL::OpenGL()
{
	
}
OpenGL::~OpenGL()
{

}

void OpenGL::setHWND(HWND window)
{
	g_hWnd = window;
}


void OpenGL::mouseMovie(int mX, int mY)
{
	for (unsigned char i = 0; i < mouseFunc.size(); i++)
	{
		(*mouseFunc[i])(this, mX, mY);
	}
	OldMouseX = mX;
	OldMouseY = mY;
}

void OpenGL::wheelEvent(float delta)
{
	for (unsigned char i = 0; i < wheelFunc.size(); i++)
	{
		(*wheelFunc[i])(this, delta);
	}

}

void OpenGL::keyDownEvent(int key)
{
	for (unsigned char i = 0; i < keyDownFunc.size(); i++)
	{
		(*keyDownFunc[i])(this, key);
	}

}


void OpenGL::keyUpEvent(int key)
{
	for (unsigned char i = 0; i < keyUpFunc.size(); i++)
	{
		(*keyUpFunc[i])(this, key);
	}

}


void OpenGL::DrawAxes()
{
	glDisable(GL_LIGHTING);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(10, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 10, 0);

	glColor3f(0, 0, 1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 10);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_LIGHTING);
}



void OpenGL::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	
	mainCamera->SetUpCamera();
	mainLight->SetUpLight();

	glEnable(GL_DEPTH_TEST);
	DrawAxes();
	//drawPlane();
	glDisable(GL_LIGHTING);

	for (unsigned char i = 0; i < renderFunc.size(); i++)
	{
		(*(renderFunc[i]))(this); //вызываем все функции рендера
	}

	//отключаем проверку Zбуфера для прорисовки "лампочки" сквозь объекты
	glDisable(GL_DEPTH_TEST);
	mainLight->DrawLightGhismo();

	//drawPlane();
	SwapBuffers(g_hDC);


	//рисуем сообщение вверху слева:
	
	//прямоугольник для текста

	
	tagRECT r;
	r.left = 10;
	r.top = 10;
	r.right = width;
	r.bottom = 200;

	//рисуем текст
	DrawText(g_hDC, message.c_str(), -1, &r, 0);
}

void OpenGL::resize(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (GLdouble)width / (GLdouble)height, .1, 500.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//инициализация openGL
void OpenGL::init(void)
{
	
	//вот отсюда
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 16;
	pfd.cDepthBits = 16;

	g_hDC = GetDC(g_hWnd);
	GLuint iPixelFormat = ChoosePixelFormat(g_hDC, &pfd);

	if (iPixelFormat != 0)
	{
		PIXELFORMATDESCRIPTOR bestMatch_pfd;
		DescribePixelFormat(g_hDC, iPixelFormat, sizeof(pfd), &bestMatch_pfd);

		if (bestMatch_pfd.cDepthBits < pfd.cDepthBits)
		{
			return;
		}

		if (SetPixelFormat(g_hDC, iPixelFormat, &pfd) == FALSE)
		{
			DWORD dwErrorCode = GetLastError();
			return;
		}
	}
	else
	{
		DWORD dwErrorCode = GetLastError();
		return;
	}

	g_hRC = wglCreateContext(g_hDC);
	wglMakeCurrent(g_hDC, g_hRC);

	//до сюда - обязательные функции инициализации 


	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);


	//выполняем пользовательские функции инфициализации
	for (unsigned char i = 0; i < initFunc.size(); i++)
	{
		(*initFunc[i])(this);
	}

	SphereStatic::MakeVertex();
	CircleStatic::MakeVertex();

}