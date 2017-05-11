#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Shape.h"

using namespace std;

#define MAX_TANKS 5

// 创建坦克
MainTank mainTank;

// 循环标记
bool loop = true;

// 暂停标记
bool skip = false;

// Bomb list
list<Object*> lstBomb;

// EnemyTank list
list<Tank* > lstEnemyTank;

// 主坦克子弹
std::list<Object*> lstMainBullets;

// 地方坦克子弹
std::list<Object*> lstEnemyBullets;

// 检查坦克是否被击中
void CheckCrash()
{
	for (list<Object*>::iterator it = lstMainBullets.begin(); it != lstMainBullets.end(); it++)
	{
		for (list<Tank*>::iterator itt = lstEnemyTank.begin(); itt != lstEnemyTank.end(); itt++)
		{
			if (Shape::CheckIntersect((*it)->GetSpace(), (*itt)->GetSpace()))
			{
				(*it)->SetDisappear();
				(*itt)->SetDisappear();
			}
		}
	}
}

void main()
{
	// 创建画布
	Graphic::Create();

	lstBomb.clear();

	// 创建敌方坦克
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_TANKS; i++)
	{
		lstEnemyTank.push_back(new EnemyTank());
	}

	lstMainBullets.clear();

	while (loop)
	{
		if (_kbhit())
		{
			int key = getch();

			switch (key)
			{
				// Up
				case 72:
					mainTank.SetDirection(Direction::UP);
					break;
				// Down
				case 80:
					mainTank.SetDirection(Direction::DOWN);
					break;
				// Left
				case 75:
					mainTank.SetDirection(Direction::LEFT);
					break;
				// Right
				case 77:
					mainTank.SetDirection(Direction::RIGHT);
					break;
				case 224: // 方向键高8位
					break;
				// Esc
				case 27:
					loop = false;
					break;
				// Space
				case 32:
					mainTank.Shoot(lstMainBullets);
					break;
				// Enter : 暂停 或 开始
				case 13:
					if (skip)
						skip = false;
					else
						skip = true;
					break;
				default:
					break;
				}
		}

		if (!skip)
		{
			cleardevice();
			CheckCrash();
			Graphic::DrawBattleSpace();
			mainTank.Move();
			mainTank.Display();

			for (list<Tank*>::iterator itt = lstEnemyTank.begin(); itt != lstEnemyTank.end(); itt++)
			{
				(*itt)->Move();
				EnemyTank* p = (EnemyTank*)*itt;
				if (p->NeedShoot())
				{
					p->Shoot(lstEnemyBullets);
				}
				if ((*itt)->IsDisappear()) {
					// Add bomb
					(*itt)->Boom(lstBomb);
					
					//delete Tank
					delete *itt;
					itt = lstEnemyTank.erase(itt);

					continue;
				}
				(*itt)->Display();
			}
			
			for (std::list<Object*>::iterator it = lstEnemyBullets.begin(); it != lstEnemyBullets.end();) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					// Add a bomb
					(*it)->Boom(lstBomb);

					// delete the bullet
					delete *it;
					it = lstEnemyBullets.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}
			
			for (std::list<Object*>::iterator it = lstMainBullets.begin(); it != lstMainBullets.end();) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					// Add a bomb
					(*it)->Boom(lstBomb);

					// delete the bullet
					delete *it;
					it = lstMainBullets.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}

			//Draw Bombs
			for (list<Object*>::iterator it = lstBomb.begin(); it != lstBomb.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					delete *it;
					it = lstBomb.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			// Draw Score
			Graphic::ShowScore();

		}

		Sleep(100);
	}

	for (list<Tank*>::iterator itt = lstEnemyTank.begin(); itt != lstEnemyTank.end(); itt++)
	{
		delete *(itt);
	}

	for (std::list<Object*>::iterator it = lstMainBullets.begin(); it != lstMainBullets.end(); it++)
	{
		delete *it;
	}
	lstMainBullets.clear();

	for (list<Object*>::iterator it = lstBomb.begin(); it != lstBomb.end(); it++)
	{
		delete *it;
	}
	lstBomb.clear();

	Graphic::Destory();
}