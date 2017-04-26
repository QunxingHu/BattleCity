#pragma once
#ifndef __POINT_H__
#define __POINT_H__
/*
* 定义 Point 类， 标示位置
*/
class Point
{
public:
	Point(int x, int y);
	~Point();

	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX() const;
	int GetY() const;

	Point& operator=(const Point&p);
	bool operator==(const Point&p);

private:
	int m_x;
	int m_y;
};
#endif // !__POINT_H__

