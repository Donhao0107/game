#include "Window.h"

Window::Window(int len,int wid,int r,int g,int b):
	length(len), wide(wid),r(r),g(g),b(b) {
	initgraph(length, wide);
	setfillcolor(RGB(r,g,b)); 
	solidrectangle(0, 0, length, wide); 
}
