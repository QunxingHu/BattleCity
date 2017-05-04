#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"
#include <list>

/* 坦克 和 子弹的基类 */
enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Object
{
public:
	// 绘图
	virtual void Display() = 0;

	// 移动
	virtual void Move() = 0;

	// 判断是否消失
	virtual bool IsDisappear() = 0;

	// 爆炸效果
	virtual void Boom(std::list<Object*>& lstBombs) = 0;

protected:
	
	// 计算势力范围
	virtual void CalculateSpace() = 0;

	// 位置
	Point m_pos;

	// 势力范围
	Rect m_space;	

	// 方向
	Direction m_dir;

	// 存在状态
	bool m_disappear;

	// 步长
	int m_step;

	// 坦克颜色
	COLORREF m_color;
};

#endif // !__OBJECT_H__


