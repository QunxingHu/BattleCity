#ifndef __ENEMYTANK_H__
#define __ENEMYTANK_H__

/*
* 敌方坦克类的定义
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
	void RandomDir();	// 随机转向
	int  m_stepCnt;		// 统计走的步数， MAX_STEP 后转向
};

#endif // !__ENEMYTANK_H__

