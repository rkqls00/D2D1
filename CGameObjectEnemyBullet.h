#pragma once
#include "GameObject.h"

//스테이지 1의 적들의 총알
class CGameObjectEnemyBullet : public CGameObject
{
public:
	CGameObjectEnemyBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectEnemyBullet();
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
};

