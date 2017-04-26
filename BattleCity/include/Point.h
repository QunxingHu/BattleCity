#pragma once
#ifndef __POINT_H__
#define __POINT_H__
/*
* ���� point �࣬ ��ʾλ��
*/
class Point
{
public:
	Point();
	~Point();

	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();

	Point& operator=(const Point&p);

private:
	int m_x;
	int m_y;
};
#endif // !__POINT_H__

