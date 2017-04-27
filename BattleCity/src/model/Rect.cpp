#include "Rect.h"

Rect::Rect(const Point &s, const Point &e) {
	m_startPoint = s;
	m_endPoint = e;
}
Rect::Rect(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}
void Rect::Set(const Point &s, const Point &e) 
{
	m_startPoint = s;
	m_endPoint = e;
}

Point Rect::GetEndPoint() const
{
	return m_endPoint;
}
Point Rect::GetStartPoint() const
{
	return m_startPoint;
}

int Rect::GetHeight()
{
	return (m_endPoint.GetY() - m_startPoint.GetY());
}

int Rect::GetWidth()
{
	return (m_endPoint.GetX() - m_startPoint.GetX());
}

void Rect::check()
{
	if (m_endPoint.GetX() <= m_startPoint.GetX() || m_endPoint.GetY() <= m_startPoint.GetY()) {
		Point temp = m_endPoint;
		m_endPoint = m_startPoint;
		m_startPoint = temp;
	}
}

Rect::~Rect()
{

}