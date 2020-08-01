#include "_StdAfx.h"
CGameObjectBossBullet3::CGameObjectBossBullet3(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, BBULLETT)
{
	//m_Scale = { 0.5, 0.5 };
}

CGameObjectBossBullet3::~CGameObjectBossBullet3()
{
}

void CGameObjectBossBullet3::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 180);
}

void CGameObjectBossBullet3::FrameMove(DWORD elapsed)
{
	m_Pos.y += 300 * elapsed / 800.f;
	m_Pos.x += 3 + elapsed / 800.f;
}

BOOL CGameObjectBossBullet3::OutMapChk()
{
	if (m_Pos.x > 1600 ||
		m_Pos.y > 900 ||
		m_Pos.x + m_rTiled.right < 0 ||
		m_Pos.y + m_rTiled.bottom < 0
		) return true;
	return false;
}
