#include "Bullet.h"

Bullet::Bullet(Point pos, Direction dir, COLORREF color) {
	m_pos = pos;
	m_dir = dir;
	m_color = color;
	m_step = 20;
	m_disappear = false;
	CalculateSpace();
}

void Bullet::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);
	fillcircle(m_pos.GetX() - 1, m_pos.GetY() - 1, 4);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bullet::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		CalculateSpace();
		if (m_space.GetStartPoint().GetY() < Graphic::GetBattleSpace().GetStartPoint().GetY())
		{
			m_disappear = true;
		}
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		CalculateSpace();
		if (m_space.GetEndPoint().GetY() > Graphic::GetBattleSpace().GetEndPoint().GetY())
		{
			m_disappear = true;
		}
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		CalculateSpace();
		if (m_space.GetStartPoint().GetX() < Graphic::GetBattleSpace().GetStartPoint().GetX())
		{
			m_disappear = true;
		}
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		CalculateSpace();
		if (m_space.GetEndPoint().GetX() > Graphic::GetBattleSpace().GetEndPoint().GetX())
		{
			m_disappear = true;
		}
		break;
	default:
		break;
	}
}

void Bullet::CalculateSpace()
{
	m_space.Set(m_pos.GetX() - 2, m_pos.GetY() - 2, m_pos.GetX() + 2, m_pos.GetY() + 2);
}