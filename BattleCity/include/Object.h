#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"
#include <list>

/* ̹�� �� �ӵ��Ļ��� */
enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Object
{
public:
	// ��ͼ
	virtual void Display() = 0;

	// �ƶ�
	virtual void Move() = 0;

	// �ж��Ƿ���ʧ
	virtual bool IsDisappear() = 0;

	// ��ըЧ��
	virtual void Boom(std::list<Object*>& lstBombs) = 0;

protected:
	
	// ����������Χ
	virtual void CalculateSpace() = 0;

	// λ��
	Point m_pos;

	// ������Χ
	Rect m_space;	

	// ����
	Direction m_dir;

	// ����״̬
	bool m_disappear;

	// ����
	int m_step;

	// ̹����ɫ
	COLORREF m_color;
};

#endif // !__OBJECT_H__


