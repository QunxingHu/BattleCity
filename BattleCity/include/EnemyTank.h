#ifndef __ENEMYTANK_H__
#define __ENEMYTANK_H__

/*
* �з�̹����Ķ���
*/
#include "Tank.h"
#include "Bullet.h"

#define	MAX_STEP 25
#define MAX_STEP_SHOOT 10

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
	void Boom(std::list<Object*>& lstBombs);
	// shoot
	void Shoot(std::list<Object*>& lstBullets);
	bool NeedShoot();

protected:
	void CalculateSpace();
	Rect GetSpace() { return m_space; }
	void GenRandomTank();
	void RandomDir();	// ���ת��
	int  m_stepCnt;		// ͳ���ߵĲ����� MAX_STEP ��ת��
	int  m_bNeedShoot;
};

#endif // !__ENEMYTANK_H__

