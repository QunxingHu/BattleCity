#include "EnemyTank.h"

void EnemyTank::GenRandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleSpace().GetWidth());
	m_pos.SetY(rand() % Graphic::GetBattleSpace().GetHeight());
	m_color = WHITE;
	m_dir = (Direction)(Direction::UP + (rand() % 4));
	m_step = 2;
	m_stepCnt = rand() % MAX_STEP; // 起始步数随机
}

void EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(m_color);

	// 敌方坦克主体
	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);
	
	// 敌方坦克四个脚
	fillrectangle(m_space.GetStartPoint().GetX(), m_space.GetStartPoint().GetY(),
		m_space.GetStartPoint().GetX() + 4, m_space.GetStartPoint().GetY() + 4);
	fillrectangle(m_space.GetEndPoint().GetX() - 4, m_space.GetStartPoint().GetY(),
		m_space.GetEndPoint().GetX(), m_space.GetStartPoint().GetY() + 4);

	fillrectangle(m_space.GetStartPoint().GetX(), m_space.GetEndPoint().GetY() - 4,
		m_space.GetStartPoint().GetX() + 4, m_space.GetEndPoint().GetY());
	fillrectangle(m_space.GetEndPoint().GetX() - 4, m_space.GetEndPoint().GetY() - 4,
		m_space.GetEndPoint().GetX(), m_space.GetEndPoint().GetY());

	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

// 碰壁后或者到达最大步数时，随机转向
void EnemyTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_pos.GetY() < Graphic::GetBattleSpace().GetStartPoint().GetY()) {
			m_pos.SetY(m_pos.GetY() + m_step);
			RandomDir();
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_pos.GetY() > Graphic::GetBattleSpace().GetEndPoint().GetY()) {
			m_pos.SetY(m_pos.GetY() - m_step);
			RandomDir();
		}
			
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_pos.GetX() < Graphic::GetBattleSpace().GetStartPoint().GetX()) {
			m_pos.SetX(m_pos.GetX() + m_step);
			RandomDir();
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_pos.GetX() > Graphic::GetBattleSpace().GetEndPoint().GetX()) {
			m_pos.SetX(m_pos.GetX() - m_step);
			RandomDir();
		}
		break;
	default:
		break;
	}
	CalculateSpace();
	m_stepCnt++;
	if (m_stepCnt >= MAX_STEP) {
		m_stepCnt = 0;
		RandomDir();
	}
}

void EnemyTank::CalculateSpace()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_space.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_space.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}

void EnemyTank::RandomDir()
{
	m_dir = (Direction)(Direction::UP + (rand() % 4));
}