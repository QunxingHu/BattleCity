#pragma once

#ifndef __TANK_H__
#define __TANK_H__

/**
* ̹�˻���Ķ��壬����̹�˾��̳��Ը���
*/

#include "Graphic.h"

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
	// ��ǰ����
	int m_x;
	int m_y;
	// ̹����ɫ
	COLORREF m_color;
	// �ƶ�����
	Direction m_direction;
	// �ƶ�����
	int m_step;
};

#endif // !__TANK_H__
