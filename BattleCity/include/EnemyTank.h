#ifndef __ENEMYTANK_H__
#define __ENEMYTANK_H__

/*
* �з�̹����Ķ���
*/
#include "Tank.h"

class EnemyTank : public Tank
{
public:
	EnemyTank() {
		GenRandomTank();
	}
	~EnemyTank() {}

	void Display();
	void Move();

protected:
	void CalculateSpace();
	void GenRandomTank();
};

#endif // !__ENEMYTANK_H__

