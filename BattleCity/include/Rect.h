#ifndef __RECT_H__
#define __RECT_H__
/**
* ��������� Rect
* ͨ�� ���Ͻ� �� ���½� �ĵ�궨����
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
	Point m_startPoint; //���Ͻ�
	Point m_endPoint;	//���½�
	void check();	//���������㣬��֤����ʱ�����Ͻ����½��������˳��û�з�
};

#endif // !__RECT_H__
