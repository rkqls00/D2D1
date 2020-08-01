#pragma once
#include "GameObject.h"

//UI
class CGameObjectButton : public CGameObject
{
public:
	CGameObjectButton(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprSizeX, int SprSizeY);
		~CGameObjectButton();
		virtual void Control(CInput* Input) override;
		virtual void Render() override;
		virtual void FrameMove(DWORD elapsed) override;
		void Destroy();
};

