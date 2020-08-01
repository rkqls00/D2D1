#pragma once
#include "GameObject.h"

//º¸½ºÃÑ¾Ë
class CGameObjectBossBullet3 : public CGameObject
{
public:
	CGameObjectBossBullet3(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
	~CGameObjectBossBullet3();
	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	BOOL OutMapChk();

};
