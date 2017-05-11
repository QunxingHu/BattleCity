#pragma once
#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__
/*
 * ��װ EasyX ��������ز���
*/

#include <graphics.h>
#include "Rect.h"
#include "Setting.h"

// ������Ļ���ȿ��
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

// ���� tank ����
#define BATTLE_SCOPE_X1 5
#define BATTLE_SCOPE_Y1	5
#define BATTLE_SCOPE_X2 800
#define BATTLE_SCOPE_Y2 (SCREEN_HEIGHT - BATTLE_SCOPE_Y1)

class Graphic 
{
public:
	static void Create();
	static void Destory();
	static int GetScreenWidth();
	static int GetScreenHeight();
	static void DrawBattleSpace();	// ����̹����ս����
	static Rect GetBattleSpace();	// ��ȡ��ս����
	static void ShowScore();	// ���Ƴɼ�
private:
	static int m_screen_width;
	static int m_screen_height;
	static Rect m_rectScreen;		// ��Ļ����
	static Rect m_rectBattleSpace;	// ��ս�������
	static char m_pArray[100];
};

#endif // !__GRAPHIC_H
