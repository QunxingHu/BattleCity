#pragma once

#ifndef __TANK_H__
#define __TANK_H__

/**
* ̹�˻���Ķ��壬����̹�˾��̳��Ը���
*/

#include "Object.h"
#include <list>

class Tank: public Object
{
public:
	Tank() {
		m_pos.Set(300,300);
		this->CalculateSpace();
		m_color = YELLOW;
		m_dir = Direction::UP;
		m_step = 4;
		m_disappear = false;
	}
	~Tank() {}
	// ��ʾ̹��
	void Display() {}
	// �ƶ�̹��
	void Move() {}
	// ����
	void Shoot(std::list<Object*>& lsBullets) {}

	bool IsDisappear() {
		return m_disappear;
	}

	// boom
	void Boom(std::list<Object*>& lstBombs){}

protected:
	// ����������Χ
	void CalculateSpace(){}
};

#endif // !__TANK_H__
