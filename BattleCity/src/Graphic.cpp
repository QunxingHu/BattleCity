#include "Graphic.h"

// ��ʼ����Ļ��С
int Graphic::m_screen_width = SCREEN_WIDTH;
int Graphic::m_screen_height = SCREEN_HEIGHT;

// ��������
void Graphic::Create() 
{
	initgraph(m_screen_width, m_screen_height);
}

// ���ٻ���
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