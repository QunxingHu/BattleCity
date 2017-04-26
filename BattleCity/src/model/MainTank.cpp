#include "MainTank.h"

void MainTank::SetDirection(Direction dir)
{
	m_direction = dir;
}

void MainTank::DrawTankBody(int style)
{
	fillrectangle(m_x - 4, m_y - 4, m_x + 4, m_y + 4); //坦克主体
	
	if (style == 1) {
		// 上下方向的坦克形状
		fillrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6); // 坦克左侧履带 
		fillrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6); // 坦克右侧履带
	} else {
		// 左右方向的坦克形状
		fillrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);	// 坦克下侧履带
		fillrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8);	// 坦克上侧履带
	}
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();
	setfillcolor(m_color);

	switch (m_direction)
	{
		case UP:
			DrawTankBody(1);	// 绘制坦克主体
			line(m_x, m_y -10 , m_x, m_y); // 绘制坦克炮杆
			break;
		case DOWN:
			DrawTankBody(1);	// 绘制坦克主体
			line(m_x, m_y, m_x, m_y + 10); // 绘制坦克炮杆
			break;
		case LEFT:
			DrawTankBody(0);	// 绘制坦克主体
			line(m_x, m_y, m_x -10, m_y); // 绘制坦克炮杆
			break;
		case RIGHT:
			DrawTankBody(0);	// 绘制坦克主体
			line(m_x, m_y, m_x + 10, m_y); // 绘制坦克炮杆
			break;
		default:
			break;
	}
}

void MainTank::Move()
{
	// 碰到边缘后，停在边缘
	switch (m_direction)
	{
		case UP:
			m_y -= m_step;
			if (m_y < 0)
				m_y = 6;
			break;
		case DOWN:
			m_y += m_step;
			if (m_y > Graphic::GetScreenHeight())
				m_y = Graphic::GetScreenHeight() - 6;
			break;
		case LEFT:
			m_x -= m_step;
			if (m_x < 0)
				m_x = 6;
			break;
		case RIGHT:
			m_x += m_step;
			if (m_x > Graphic::GetScreenWidth())
				m_x = Graphic::GetScreenWidth() - 6;
			break;
		default:
			break;
	}
}