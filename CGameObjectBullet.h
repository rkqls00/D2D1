#pragma once
#include "GameObject.h"

//�÷��̾��� �Ѿ�

class CGameObjectBullet : public CGameObject
{
public:
	CGameObjectBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectBullet();

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
};

