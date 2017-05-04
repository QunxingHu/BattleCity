#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"

using namespace std;

#define MAX_TANKS 15


void main()
{
	// 创建画布
	Graphic::Create();

	// 创建坦克
	MainTank mainTank;

	// 循环标记
	bool loop = true;

	// 暂停标记
	bool skip = false;

	// Bomb list
	std::list<Object*> lstBomb;
	lstBomb.clear();

	// 创建敌方坦克
	srand((unsigned)time(NULL));
	Tank* pEnemyTank[MAX_TANKS];
	for (int i = 0; i < MAX_TANKS; i++)
	{
		pEnemyTank[i] = new EnemyTank();
	}
	// 子弹
	std::list<Object*> lstBullets;
	lstBullets.clear();

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
					mainTank.Shoot(lstBullets);
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
			Graphic::DrawBattleSpace();
			mainTank.Move();
			mainTank.Display();
			for (int i = 0; i < MAX_TANKS; i++)
			{
				pEnemyTank[i]->Move();
				pEnemyTank[i]->Display();
			}
			
			for (std::list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					// Add a bomb
					(*it)->Boom(lstBomb);

					// delete the bullet
					delete *it;
					it = lstBullets.erase(it);
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
		}

		Sleep(100);
	}

	for (int i = 0; i < MAX_TANKS; i++)
	{
		delete pEnemyTank[i];
	}

	for (std::list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete *it;
	}
	lstBullets.clear();

	for (list<Object*>::iterator it = lstBomb.begin(); it != lstBomb.end(); it++)
	{
		delete *it;
	}
	lstBomb.clear();

	Graphic::Destory();
}