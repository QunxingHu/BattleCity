#include "Bomb.h"

Bomb::Bomb()
{
	this->m_disappear = false;
	this->m_color = YELLOW;
	this->m_dir = Direction::UP;
}

Bomb::Bomb(Point pos, BombType type) : Bomb()
{
	this->m_pos = pos;
	this->m_type = type;
	switch (m_type)
	{
	case LARGE:
		m_timer = 8;
		break;
	case SMALL:
		m_timer = 4;
		break;
	default:
		break;
	}
}

void Bomb::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(RED);

	fillcircle(m_pos.GetX(), m_pos.GetY(), 8 - m_timer);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bomb::Move()
{
	m_timer -= 2;
	if (m_timer < 0)
		m_disappear = true;
}

bool Bomb::IsDisappear()
{
	return  m_disappear;
}

void Bomb::Boom(std::list<Object*>& lstBombs)
{
	// Do nothing
}

void Bomb::CalculateSpace()
{
	// Do nothing
}