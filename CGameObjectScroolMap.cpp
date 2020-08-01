#include "_StdAfx.h"

CGameObjectScroolMap::CGameObjectScroolMap(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, TEXTURE)
{
}

CGameObjectScroolMap::~CGameObjectScroolMap()
{
}

void CGameObjectScroolMap::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}

void CGameObjectScroolMap::FrameMove(DWORD elapsed)
{
	/*m_Pos.y += 5.f;
	if (m_Pos.y > 900)
		m_Pos.y -= 1800;*/
}

void CGameObjectScroolMap::Control(CInput* Input)
{
}
