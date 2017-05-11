#include "Graphic.h"

// 初始化屏幕大小
int Graphic::m_screen_width = SCREEN_WIDTH;
int Graphic::m_screen_height = SCREEN_HEIGHT;

Rect Graphic::m_rectBattleSpace;
Rect Graphic::m_rectScreen;

char Graphic::m_pArray[100];

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

void Graphic::ShowScore()
{
	const int SCORE_LEFT = 810;
	const int SCORE_TOP = 5;

	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	//setfillcolor(m_color);
	//setcolor(m_color);

	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());

	drawtext(m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("分  数  :  %d"), Setting::GetSumScore());
	drawtext(m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("级  别  :  %d"), Setting::GetTankLevel());
	drawtext(m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("生  命  :  %d"), Setting::GetLife());
	drawtext(m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("敌人数  :  %d"), Setting::GetTankNum());
	drawtext(m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("共击毁敌人数  :  %d"), Setting::GetTankSum());
	drawtext(m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}