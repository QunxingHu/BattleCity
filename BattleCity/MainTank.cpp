#include "MainTank.h"

void MainTank::SetDirection(Direction dir)
{
	m_direction = dir;
}

void MainTank::DrawTankBody(int style)
{
	fillrectangle(m_x - 4, m_y - 4, m_x + 4, m_y + 4); //̹������
	
	if (style == 1) {
		// ���·����̹����״
		fillrectangle(m_x - 8, m_y - 6, m_x - 6, m_y + 6); // ̹������Ĵ� 
		fillrectangle(m_x + 6, m_y - 6, m_x + 8, m_y + 6); // ̹���Ҳ��Ĵ�
	} else {
		// ���ҷ����̹����״
		fillrectangle(m_x - 6, m_y - 8, m_x + 6, m_y - 6);	// ̹���²��Ĵ�
		fillrectangle(m_x - 6, m_y + 6, m_x + 6, m_y + 8);	// ̹���ϲ��Ĵ�
	}
}

void MainTank::Display()
{
	COLORREF color_save = getfillcolor();
	setfillcolor(m_color);

	switch (m_direction)
	{
		case UP:
			DrawTankBody(1);	// ����̹������
			line(m_x, m_y -10 , m_x, m_y); // ����̹���ڸ�
			break;
		case DOWN:
			DrawTankBody(1);	// ����̹������
			line(m_x, m_y, m_x, m_y + 10); // ����̹���ڸ�
			break;
		case LEFT:
			DrawTankBody(0);	// ����̹������
			line(m_x, m_y, m_x -10, m_y); // ����̹���ڸ�
			break;
		case RIGHT:
			DrawTankBody(0);	// ����̹������
			line(m_x, m_y, m_x + 10, m_y); // ����̹���ڸ�
			break;
		default:
			break;
	}
}

void MainTank::Move()
{
	// ������Ե��ͣ�ڱ�Ե
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