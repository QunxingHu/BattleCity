#pragma once
#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__
/*
 * 封装 EasyX 画布的相关操作
*/

#include <graphics.h>

// 定义屏幕长度宽度
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Graphic 
{
public:
	static void Create();
	static void Destory();
	static int GetScreenWidth();
	static int GetScreenHeight();

private:
	static int m_screen_width;
	static int m_screen_height;
};

#endif // !__GRAPHIC_H
