#include "_StdAfx.h"
#include "CGameObjectButton.h"

CGameObjectButton::CGameObjectButton(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	:CGameObject(FileName, Pos, SprWidth, SprHeight, BUTTON) {

}
CGameObjectButton::~CGameObjectButton()
{

}

void CGameObjectButton::Control(CInput* Input) {
	
}
void CGameObjectButton::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}

void CGameObjectButton::FrameMove(DWORD elapsed)
{
}


