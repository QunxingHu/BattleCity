#ifndef __BOMB_H__
#define __BOMB_H__
/*±¬Õ¨Ð§¹û*/
#include "Object.h"
#include <list>

enum BombType {
	LARGE,
	SMALL
};

class Bomb : public Object
{
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb() {}

	void Display();
	void Move();
	void Boom(std::list<Object*>& lstBombs);
	bool IsDisappear();

protected:
	void CalculateSpace();
	BombType m_type;
	int m_timer;
};

#endif // !__BOMB_H__
