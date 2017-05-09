#include "Shape.h"

bool Shape::CheckPointInRect(Point &p, Rect &rect)
{
	if (p.GetX() < rect.GetStartPoint().GetX() || p.GetX() > rect.GetEndPoint().GetX() ||
		p.GetY() < rect.GetStartPoint().GetY() || p.GetY() > rect.GetEndPoint().GetY())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Shape::CheckIntersect(Rect& rectA, Rect& rectB) 
{
	if (CheckPointInRect(rectA.GetStartPoint(), rectB) ||
		CheckPointInRect(rectA.GetTRPoint(), rectB) ||
		CheckPointInRect(rectA.GetBLPoint(), rectB) ||
		CheckPointInRect(rectA.GetEndPoint(), rectB) )
	{
		return true;
	}
	else
	{
		return false;
	}
}