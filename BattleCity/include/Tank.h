#pragma once

#ifndef __TANK_H__
#define __TANK_H__

/**
* 坦克基类的定义，所有坦克均继承自该类
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
	// 显示坦克
	void Display() {}
	// 移动坦克
	void Move() {}
	// 开火
	void Shoot(std::list<Object*>& lsBullets) {}

	bool IsDisappear() {
		return m_disappear;
	}

	// boom
	void Boom(std::list<Object*>& lstBombs){}

protected:
	// 计算势力范围
	void CalculateSpace(){}
};

#endif // !__TANK_H__
