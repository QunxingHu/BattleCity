#pragma once
#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__
/*
 * 封装 EasyX 画布的相关操作
*/

#include <graphics.h>
#include "Rect.h"
#include "Setting.h"

// 定义屏幕长度宽度
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

// 定义 tank 区域
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
	static void DrawBattleSpace();	// 绘制坦克作战区域
	static Rect GetBattleSpace();	// 获取作战区域
	static void ShowScore();	// 绘制成绩
private:
	static int m_screen_width;
	static int m_screen_height;
	static Rect m_rectScreen;		// 屏幕矩形
	static Rect m_rectBattleSpace;	// 作战区域矩形
	static char m_pArray[100];
};

#endif // !__GRAPHIC_H
