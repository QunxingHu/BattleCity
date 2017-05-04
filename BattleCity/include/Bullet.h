#ifndef __BULLET_H__
#define __BULLET_H__

#include "Object.h"
#include <list>

class Bullet : public Object 
{
public:
	Bullet() {}
	Bullet(Point pos, Direction dir, COLORREF color);
	~Bullet() {}
	void Display();
	void Move();
	void Boom(std::list<Object*>& lstBombs);
	bool IsDisappear() 
	{
		return m_disappear;
	}
protected:
	void CalculateSpace();
};
#endif // !
