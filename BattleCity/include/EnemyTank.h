#ifndef __ENEMYTANK_H__
#define __ENEMYTANK_H__

/*
* �з�̹����Ķ���
*/
#include "Tank.h"

#define	MAX_STEP 25

class EnemyTank : public Tank
{
public:
	EnemyTank() {
		GenRandomTank();
	}
	~EnemyTank() {}

	void Display();
	void Move();
	// boom
	void Boom(std::list<Object*>& lstBombs) {}
protected:
	void CalculateSpace();
	void GenRandomTank();
	void RandomDir();	// ���ת��
	int  m_stepCnt;		// ͳ���ߵĲ����� MAX_STEP ��ת��
};

#endif // !__ENEMYTANK_H__

