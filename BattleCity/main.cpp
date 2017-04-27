#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include "Graphic.h"
#include "MainTank.h"

using namespace std;

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
		}

		Sleep(50);
	}
	Graphic::Destory();
}