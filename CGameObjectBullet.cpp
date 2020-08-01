#include "_StdAfx.h"

CGameObjectBullet::CGameObjectBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, BULLET)
{
}

CGameObjectBullet::~CGameObjectBullet()
{
}

void CGameObjectBullet::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}

void CGameObjectBullet::FrameMove(DWORD elapsed)
{
	m_Pos.y -= 300 * elapsed / 500.f;
	
}

BOOL CGameObjectBullet::OutMapChk()
{
	if (m_Pos.x > 1600 ||
		m_Pos.y > 900 ||
		m_Pos.x + m_rTiled.right < 0 ||
		m_Pos.y + m_rTiled.bottom < 0
		) return true;
	return false;
}