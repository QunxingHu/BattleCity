#include "Graphic.h"

// 初始化屏幕大小
int Graphic::m_screen_width = SCREEN_WIDTH;
int Graphic::m_screen_height = SCREEN_HEIGHT;

Rect Graphic::m_rectBattleSpace;
Rect Graphic::m_rectScreen;

// 创建画布
void Graphic::Create() 
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(m_screen_width, m_screen_height);
	setbkcolor(DARKGRAY);
	m_rectBattleSpace.Set(BATTLE_SCOPE_X1, BATTLE_SCOPE_Y1, BATTLE_SCOPE_X2, BATTLE_SCOPE_Y2);
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

void Graphic::DrawBattleSpace()
{
	rectangle(m_rectBattleSpace.GetStartPoint().GetX(), m_rectBattleSpace.GetStartPoint().GetY(),
		m_rectBattleSpace.GetEndPoint().GetX(), m_rectBattleSpace.GetEndPoint().GetY());
}

Rect Graphic::GetBattleSpace()
{
	return m_rectBattleSpace;
}