#ifndef __RECT_H__
#define __RECT_H__
/**
* 定义矩形类 Rect
* 通过 左上角 和 右下角 的点标定矩形
*/
#include "Point.h"

class Rect
{
public:
	Rect(int x1, int y1, int x2, int y2);
	Rect(const Point& start, const Point& end);
	~Rect();

	int GetWidth();
	int GetHeight();

	Point GetStartPoint() const;
	Point GetEndPoint() const;

	void Set(const Point &start, const Point& end);
	void Set(int x1, int y1, int x2, int y2);


private:
	Point m_startPoint; //左上角
	Point m_endPoint;	//右下角
	void check();	//调整两个点，保证创建时，左上角右下角两个点的顺序没有反
};

#endif // !__RECT_H__
