#ifndef __SHAPE_H__
#define __SHAPE_H__

/*
* 工具类，判定点是否在矩形内以及两矩形是否重合
*/
#include "Rect.h"

class Shape
{
public:
	static bool CheckPointInRect(Point& p, Rect& rect);		// 判定点p是否在rect内
	static bool CheckIntersect(Rect& rectA, Rect& rectB);	// 判定矩形A， 矩形B是否重合
};

#endif // !__SHAPE_H__
