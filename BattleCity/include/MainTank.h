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
		m_step = 6;
	}
	~MainTank() {}

	// ��ʾ���ƶ�̹��
	void Display();
	void Move();

	// �����ƶ�����
	void SetDirection(Direction dir);

	Direction GetDirection()
	{
		return m_dir;
	}
	// shoot
	void Shoot(std::list<Object*>& lstBullets);

	// boom
	void Boom(std::list<Object*>& lstBombs) {}
	Rect GetSpace() { return m_space; }
protected:
	// ����̹������
	void DrawTankBody();
	void CalculateSpace();
	
};

#endif // !__MAIN_TANK_

