#include "EnemyTank.h"

void EnemyTank::GenRandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleSpace().GetWidth());
	m_pos.SetY(rand() % Graphic::GetBattleSpace().GetHeight());
	m_color = WHITE;
	m_direction = (Direction)(Direction::UP + (rand() % 4));
	m_step = 2;
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

	switch (m_direction)
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

void EnemyTank::Move()
{
	switch (m_direction)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_pos.GetY() < Graphic::GetBattleSpace().GetStartPoint().GetY())
			m_pos.SetY(Graphic::GetBattleSpace().GetEndPoint().GetY() - 1);
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_pos.GetY() > Graphic::GetBattleSpace().GetEndPoint().GetY())
			m_pos.SetY(Graphic::GetBattleSpace().GetStartPoint().GetY() + 1);
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_pos.GetX() < Graphic::GetBattleSpace().GetStartPoint().GetX())
			m_pos.SetX(Graphic::GetBattleSpace().GetEndPoint().GetX() - 1);
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_pos.GetX() > Graphic::GetBattleSpace().GetEndPoint().GetX())
			m_pos.SetX(Graphic::GetBattleSpace().GetStartPoint().GetX() + 1);
		break;
	default:
		break;
	}
	CalculateSpace();
}

void EnemyTank::CalculateSpace()
{
	switch (m_direction)
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