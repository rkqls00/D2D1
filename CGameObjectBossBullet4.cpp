#include "_StdAfx.h"
#include <math.h>
CGameObjectBossBullet4::CGameObjectBossBullet4(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, BBULLETT)
{
	//m_Scale = { 0.5, 0.5 };
}

CGameObjectBossBullet4::~CGameObjectBossBullet4()
{
}

void CGameObjectBossBullet4::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 180);
}

void CGameObjectBossBullet4::FrameMove(DWORD elapsed)
{
	m_Pos.y += ((m_pPos.y - m_BBPos.y)) * elapsed / 800.f;
	m_Pos.x += ((m_pPos.x - m_BBPos.x)) * elapsed / 800.f;
}

BOOL CGameObjectBossBullet4::OutMapChk()
{
	if (m_Pos.x > 1600 ||
		m_Pos.y > 900 ||
		m_Pos.x + m_rTiled.right < 0 ||
		m_Pos.y + m_rTiled.bottom < 0
		) return true;
	return false;
}
