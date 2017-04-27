#pragma once
#ifndef __MAIN_TANK_
#define __MAIN_TANK_

#include "Tank.h"


class MainTank : public Tank
{
public:
	MainTank(){
		m_pos.Set(400,300);
		m_direction = Direction::UP;
		this->CalculateSpace();
		m_color = YELLOW;
		m_step = 1;
	}
	~MainTank() {}

	// 显示和移动坦克
	void Display();
	void Move();

	// 设置移动方向
	void SetDirection(Direction dir);

protected:
	// 绘制坦克主体
	void DrawTankBody();
	void CalculateSpace();
};

#endif // !__MAIN_TANK_

