#include "MainTank.h"

void MainTank::SetDirection(Direction dir)
{
	m_direction = dir;
}

void MainTank::DrawTankBody()
{
	int m_x = m_pos.GetX();
	int m_y = m_pos.GetY();
	fillrectangle(m_x - 6, m_y - 6, m_x + 6, m_y + 6); //坦克主体
	
	// 绘制履带
	switch (m_direction)
	{
	case UP:
	case DOWN:
		fillrectangle(m_space.GetStartPoint().GetX(), m_space.GetStartPoint().GetY(),
			m_space.GetStartPoint().GetX() + 4, m_space.GetEndPoint().GetY());
		fillrectangle(m_space.GetEndPoint().GetX() - 4, m_space.GetStartPoint().GetY(),
			m_space.GetEndPoint().GetX(), m_space.GetEndPoint().GetY());
		break;
	case LEFT:
	case RIGHT:
		fillrectangle(m_space.GetStartPoint().GetX(), m_space.GetStartPoint().GetY(),
			m_space.GetEndPoint().GetX(), m_space.GetStartPoint().GetY() + 4);
		fillrectangle(m_space.GetStartPoint().GetX(), m_space.GetEndPoint().GetY() - 4,
			m_space.GetEndPoint().GetX(), m_space.GetEndPoint().GetY());
		break;
	default:
		break;
	}
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();
	setfillcolor(m_color);

	DrawTankBody();

	int m_x = m_pos.GetX();
	int m_y = m_pos.GetY();

	switch (m_direction)
	{
		case UP:
			line(m_x, m_y -15 , m_x, m_y); // 绘制坦克炮杆
			break;
		case DOWN:
			line(m_x, m_y, m_x, m_y + 15); // 绘制坦克炮杆
			break;
		case LEFT:
			line(m_x, m_y, m_x -15, m_y); // 绘制坦克炮杆
			break;
		case RIGHT:
			line(m_x, m_y, m_x + 15, m_y); // 绘制坦克炮杆
			break;
		default:
			break;
	}
}

void MainTank::Move()
{
	int m_x = m_pos.GetX();
	int m_y = m_pos.GetY();

	// 碰到边缘后，停在边缘
	switch (m_direction)
	{
		case UP:
			m_y -= m_step;
			if (m_y < 0)
				m_y = 6;
			m_pos.SetY(m_y);
			break;
		case DOWN:
			m_y += m_step;
			if (m_y > Graphic::GetBattleSpace().GetEndPoint().GetY())
				m_y = Graphic::GetBattleSpace().GetEndPoint().GetY() - 6;
			m_pos.SetY(m_y);
			break;
		case LEFT:
			m_x -= m_step;
			if (m_x < 0)
				m_x = 6;
			m_pos.SetX(m_x);
			break;
		case RIGHT:
			m_x += m_step;
			if (m_x > Graphic::GetBattleSpace().GetEndPoint().GetX())
				m_x = Graphic::GetBattleSpace().GetEndPoint().GetX() - 6;
			m_pos.SetX(m_x);
			break;
		default:
			break;
	}
	this->CalculateSpace();
}

void MainTank::CalculateSpace()
{
	switch (m_direction)
	{
	case UP:
	case DOWN:
		m_space.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_space.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}