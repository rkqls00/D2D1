#include "_StdAfx.h"

CGameObjectEnemyBullet::CGameObjectEnemyBullet(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, EBULLET)
{
	//m_Scale = { 0.5, 0.5 };
}

CGameObjectEnemyBullet::~CGameObjectEnemyBullet()
{
}

void CGameObjectEnemyBullet::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 180);
}

void CGameObjectEnemyBullet::FrameMove(DWORD elapsed)
{

	m_Pos.y += 300 * elapsed / 1000.f;

}

BOOL CGameObjectEnemyBullet::OutMapChk()
{
	if (m_Pos.x > 1600 ||
		m_Pos.y > 900 ||
		m_Pos.x + m_rTiled.right < 0 ||
		m_Pos.y + m_rTiled.bottom < 0
		) return true;
	return false;
}
