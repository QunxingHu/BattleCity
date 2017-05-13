#ifndef __SETTING_H__
#define __SETTING_H__

#include <list>

using namespace std;

class Setting
{
public:
	static void NewGameLevel();
	static void TankDamaged();

	static int GetLife()
	{
		return m_nLife;
	}
	static int GetGameLevel()
	{
		return m_nGameLevel;
	}
	static int GetTankLevel()
	{
		return m_nTankLevel;
	}
	static int GetTankSum()
	{
		return m_nTankSum;
	}
	static int GetSumScore()
	{
		return m_nSumScore;
	}
	static int GetTankScore()
	{
		return m_nTankScore;
	}
	static int GetTankNum()
	{
		return m_nTankNum;
	}
	static void Die();
	static bool m_bNewLevel;	//�¹ؿ�
private:
	static int m_nLife; //����ֵ
	static int m_nGameLevel; //��ǰ��Ϸ�ؿ�
	static int m_nTankLevel;	//��ǰ̹�˼���
	static int m_nTankNum; //��ǰ̹����
	static int m_nSumScore;	//�ܷ�
	static int m_nTankScore; //����̹�˵÷�
	static int m_nTankSum;	//����̹������
};
#endif // !__SETTING_H__