#pragma once

#ifndef __TANK_H__
#define __TANK_H__

/**
* ̹�˻���Ķ��壬����̹�˾��̳��Ը���
*/

#include "Graphic.h"
#include "Point.h"
#include "Rect.h"

// �ƶ�������
enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Tank
{
public:
	// ��ʾ̹��
	virtual void Display() = 0;	
	// �ƶ�̹��
	virtual void Move() = 0;

protected:
	// ����������Χ
	virtual void CalculateSpace() = 0;
	Point m_pos;	// λ�õ�
	Rect m_space;	// ��״��Χ
	// ̹����ɫ
	COLORREF m_color;
	// �ƶ�����
	Direction m_direction;
	// �ƶ�����
	int m_step;
};

#endif // !__TANK_H__
