#pragma once
#include "GameObject.h"

//�����Ѿ�
class CGameObjectBossBullet : public CGameObject
{
public:
	CGameObjectBossBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectBossBullet();
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
	
};

