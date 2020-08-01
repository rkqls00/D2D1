#pragma once
#include "GameObject.h"

//플레이어의 총알

class CGameObjectBullet : public CGameObject
{
public:
	CGameObjectBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectBullet();

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
};

