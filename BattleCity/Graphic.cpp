#include "Graphic.h"

// 初始化屏幕大小
int Graphic::m_screen_width = SCREEN_WIDTH;
int Graphic::m_screen_height = SCREEN_HEIGHT;

// 创建画布
void Graphic::Create() 
{
	initgraph(m_screen_width, m_screen_height);
}

// 销毁画布
void Graphic::Destory()
{
	closegraph();
}

int Graphic::GetScreenHeight()
{
	return m_screen_height;
}

int Graphic::GetScreenWidth()
{
	return m_screen_width;
}