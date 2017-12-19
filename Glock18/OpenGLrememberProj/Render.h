#ifndef  RENDER_H
#define  RENDER_H


class OpenGL;



//обработчик события мыши
void mouseEvent(OpenGL *ogl, int mX, int mY);

//обработчик события колесика миши мыши
void mouseWheelEvent(OpenGL *ogl, int delta);

//обработчки события нажатия кнопки (мышь + клава)
void keyDownEvent(OpenGL *ogl, int key);

//обработчки события отпускания кнопки (только!11 клава)
void keyUpEvent(OpenGL *ogl, int key);

//выполняется перед  первым рендером
void initRender(OpenGL *ogl);

//рендер
void Render(OpenGL *ogl);


#endif // ! RENDER_H