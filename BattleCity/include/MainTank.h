#pragma once
#ifndef __MAIN_TANK_
#define __MAIN_TANK_

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank(){
		m_x = 400;
		m_y = 300;
		m_color = WHITE;
		m_direction = Direction::UP;
		m_step = 1;
	}
	~MainTank() {}

	// 显示和移动坦克
	void Display();
	void Move();

	// 设置移动方向
	void SetDirection(Direction dir);

protected:
	/* 绘制坦克主体
	* @style: 1 向上方向的坦克形状  |口|
	*		  2 左右方向的坦克形状   亘
	*/
	void DrawTankBody(int style);
};

#endif // !__MAIN_TANK_

