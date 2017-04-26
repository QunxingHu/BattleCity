#pragma once

#ifndef __TANK_H__
#define __TANK_H__

/**
* 坦克基类的定义，所有坦克均继承自该类
*/

#include "Graphic.h"

// 移动方向定义
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
	// 显示坦克
	virtual void Display() = 0;	
	// 移动坦克
	virtual void Move() = 0;

protected:
	// 当前坐标
	int m_x;
	int m_y;
	// 坦克颜色
	COLORREF m_color;
	// 移动方向
	Direction m_direction;
	// 移动步长
	int m_step;
};

#endif // !__TANK_H__
