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

	// ��ʾ���ƶ�̹��
	void Display();
	void Move();

	// �����ƶ�����
	void SetDirection(Direction dir);

protected:
	// ����̹������
	void DrawTankBody();
	void CalculateSpace();
};

#endif // !__MAIN_TANK_

