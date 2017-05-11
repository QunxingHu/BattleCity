#ifndef __ENEMYTANK_H__
#define __ENEMYTANK_H__

/*
* 敌方坦克类的定义
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
	void RandomDir();	// 随机转向
	int  m_stepCnt;		// 统计走的步数， MAX_STEP 后转向
	int  m_bNeedShoot;
};

#endif // !__ENEMYTANK_H__

