#ifndef __SHAPE_H__
#define __SHAPE_H__

/*
* �����࣬�ж����Ƿ��ھ������Լ��������Ƿ��غ�
*/
#include "Rect.h"

class Shape
{
public:
	static bool CheckPointInRect(Point& p, Rect& rect);		// �ж���p�Ƿ���rect��
	static bool CheckIntersect(Rect& rectA, Rect& rectB);	// �ж�����A�� ����B�Ƿ��غ�
};

#endif // !__SHAPE_H__
