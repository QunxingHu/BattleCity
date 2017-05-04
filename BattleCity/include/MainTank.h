#pragma once
#ifndef __MAIN_TANK_
#define __MAIN_TANK_

#include "Tank.h"
#include "Bullet.h"

class MainTank : public Tank
{
public:
	MainTank(){
		m_pos.Set(400,300);
		m_dir = Direction::UP;
		this->CalculateSpace();
		m_color = YELLOW;
		m_step = 4;
	}
	~MainTank() {}

	// 显示和移动坦克
	void Display();
	void Move();

	// 设置移动方向
	void SetDirection(Direction dir);

	// shoot
	void Shoot(std::list<Object*>& lstBullets);

	// boom
	void Boom(std::list<Object*>& lstBombs) {}

protected:
	// 绘制坦克主体
	void DrawTankBody();
	void CalculateSpace();
};

#endif // !__MAIN_TANK_

