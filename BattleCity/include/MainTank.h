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

	// ��ʾ���ƶ�̹��
	void Display();
	void Move();

	// �����ƶ�����
	void SetDirection(Direction dir);

	// shoot
	void Shoot(std::list<Object*>& lstBullets);

	// boom
	void Boom(std::list<Object*>& lstBombs) {}

protected:
	// ����̹������
	void DrawTankBody();
	void CalculateSpace();
};

#endif // !__MAIN_TANK_

