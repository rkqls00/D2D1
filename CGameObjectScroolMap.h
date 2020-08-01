#pragma once
#include "GameObject.h"

//MAP
class CGameObjectScroolMap : public CGameObject
{
public:
	CGameObjectScroolMap(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight);
	~CGameObjectScroolMap();

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* Input) override;
};

