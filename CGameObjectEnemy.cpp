#include "_StdAfx.h"
#include "CGameObjectEnemy.h"

CGameObjectEnemy::CGameObjectEnemy(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, ENEMY)
{
	m_Scale = { 1, 1 };
}

CGameObjectEnemy::~CGameObjectEnemy()
{

}

void CGameObjectEnemy::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}

void CGameObjectEnemy::FrameMove(DWORD elapsed)
{
	if (m_Option < 1) {
		m_Pos.y += 100.f * elapsed / 1000.f;
	}
}

BOOL CGameObjectEnemy::OutMapChk()
{
	//맵밖을 실제 윈도우 크기보다 조금 더 여유공간을 둠
	if (m_Option < 1) {
		if (m_Pos.x > 1200 || m_Pos.x<100||
			m_Pos.y > 900 + 100 ||
			m_Pos.x + m_rTiled.right * m_Scale.x < -100 ||
			m_Pos.y + m_rTiled.bottom * m_Scale.y < -100
			)return true;
	}
		return false;
	
}

BOOL CGameObjectEnemy::IsFire()
{
	if (m_Option < 1) {
		if (timeGetTime() - m_bulletTimer > 2100) {
			m_bulletTimer = timeGetTime();
			return true;
		}
	}
	return false;
}
