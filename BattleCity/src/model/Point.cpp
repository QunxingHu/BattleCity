#include "Point.h"

Point::Point(int x, int y):m_x(x),m_y(y)
{

}

Point::~Point()
{

}

void Point::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Point::SetX(int x)
{
	m_x = x;
}

void Point::SetY(int y)
{
	m_y = y;
}

int Point::GetX() const
{
	return m_x;
}

int Point::GetY() const
{
	return m_y;
}

bool Point::operator==(const Point&p)
{
	if (this->m_x == p.GetX() && this->m_y == p.GetY())
		return true;
	else
		return false;
}

Point& Point::operator=(const Point& p)
{
	if (this == &p)
		return *this;
	else {
		m_x = p.GetX();
		m_y = p.GetY();
		return *this;
	}
}