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

// ����̹��
MainTank mainTank;

// ѭ�����
bool loop = true;

// ��ͣ���
bool skip = false;

bool bGameOver = false;

// Bomb list
list<Object*> lstBomb;

// EnemyTank list
list<Tank* > lstEnemyTank;

// ��̹���ӵ�
std::list<Object*> lstMainBullets;

// �ط�̹���ӵ�
std::list<Object*> lstEnemyBullets;

// ���̹���Ƿ񱻻���
void CheckCrash()
{
	// check enemy tank damage
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
	//check main tank damage
	for (list<Object*>::iterator it = lstEnemyBullets.begin(); it != lstEnemyBullets.end(); it++)
	{
		if (Shape::CheckIntersect((*it)->GetSpace(), mainTank.GetSpace()))
		{
			Setting::Die();

			if (Setting::GetLife() > 0)
			{
				(*it)->SetDisappear();
			}
			else
			{
				mainTank.SetDisappear();
			}
		}
	}
}

void main()
{
	// ��������
	Graphic::Create();

	lstBomb.clear();

	// �����з�̹��
	srand((unsigned)time(NULL));
	/*
	for (int i = 0; i < MAX_TANKS; i++)
	{
		lstEnemyTank.push_back(new EnemyTank());
	}
	*/
	lstMainBullets.clear();

	Direction dirBak;
	while (loop)
	{
		if (_kbhit())
		{
			int key = getch();

			if (skip && key != 13)
				continue;

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
				case 224: // �������8λ
					break;
				// Esc
				case 27:
					loop = false;
					break;
				// Space
				case 32:
					mainTank.Shoot(lstMainBullets);
					break;
				// Enter : ��ͣ �� ��ʼ
				case 13:
					if (skip)
						skip = false;
					else
						skip = true;
					break;
				// ��������
				case 113:
					dirBak = mainTank.GetDirection();
					mainTank.SetDirection(Direction::UP);
					mainTank.Shoot(lstMainBullets);
					mainTank.SetDirection(Direction::DOWN);
					mainTank.Shoot(lstMainBullets);
					mainTank.SetDirection(Direction::LEFT);
					mainTank.Shoot(lstMainBullets);
					mainTank.SetDirection(Direction::RIGHT);
					mainTank.Shoot(lstMainBullets);
					mainTank.SetDirection(dirBak);
					break;
				default:
					break;
				}
		}

		if (!skip)
		{
			if (bGameOver)
				break;
			cleardevice();
			Graphic::DrawBattleSpace();
			Graphic::ShowScore();

			if (Setting::m_bNewLevel)
			{
				Setting::m_bNewLevel = false;

				Setting::NewGameLevel();

				Graphic::ShowGameLevel(Setting::GetGameLevel());

				for (int i = 0; i < Setting::GetTankNum(); i++)
				{
					EnemyTank* p = new EnemyTank();
					lstEnemyTank.push_back(p);
				}

				// ������ͣ����Enter��ʼ
				skip = true;
				continue;

			}


			CheckCrash();


			if (mainTank.IsDisappear())
			{
				skip = true;
				bGameOver = true;

				Graphic::ShowGameOver();

				continue;
			}
			mainTank.Move();
			mainTank.Display();

			for (list<Tank*>::iterator itt = lstEnemyTank.begin(); itt != lstEnemyTank.end();)
			{
				(*itt)->Move();
				EnemyTank* p = (EnemyTank*)*itt;
				if (p->NeedShoot())
				{
					p->Shoot(lstEnemyBullets);
				}
				if ((*itt)->IsDisappear()) {
					Setting::TankDamaged();
					// Add bomb
					(*itt)->Boom(lstBomb);
					
					//delete Tank
					delete *itt;
					itt = lstEnemyTank.erase(itt);
					continue;
				}
				(*itt)->Display();
				itt++;
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