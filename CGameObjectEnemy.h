#pragma once
#include "GameObject.h"

//스테이지 1의 적
class CGameObjectEnemy : public CGameObject
{
private:
	time_t m_bulletTimer = timeGetTime();

public:
	CGameObjectEnemy(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight);
	~CGameObjectEnemy();

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
	BOOL IsFire();
};

