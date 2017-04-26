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

	// ��ʾ���ƶ�̹��
	void Display();
	void Move();

	// �����ƶ�����
	void SetDirection(Direction dir);

protected:
	/* ����̹������
	* @style: 1 ���Ϸ����̹����״  |��|
	*		  2 ���ҷ����̹����״   ب
	*/
	void DrawTankBody(int style);
};

#endif // !__MAIN_TANK_

