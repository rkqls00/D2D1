#pragma once
#include "GameObject.h"

//���� ���� 2��°�� ����ź
class CGameObjectBossBullet4 : public CGameObject
{
public:
	CGameObjectBossBullet4(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectBossBullet4();
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();
	
};
