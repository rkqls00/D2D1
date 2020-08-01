#pragma once
#include "GameObject.h"

//����
class CGameObjectBoss : public CGameObject
{
private:
	time_t m_bulletTimer = timeGetTime();
	INT BossPos = 0; //������ �̵��ϴ� ������ �����ֱ� ���� ���� 
public:
	CGameObjectBoss(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight);
	~CGameObjectBoss();
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
	BOOL IsFire();
	BOOL IsFire2();
};

