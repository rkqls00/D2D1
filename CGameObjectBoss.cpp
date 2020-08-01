#include "_StdAfx.h"
#include "CGameObjectBoss.h"
CGameObjectBoss::CGameObjectBoss(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, BOSS)
{
	m_Scale = { 1, 1 };
}

CGameObjectBoss::~CGameObjectBoss()
{
}

void CGameObjectBoss::Render()
{
	m_Sprite->Draw(&m_rTiled, m_Pos, m_Scale, &m_Pos, 0);
}

void CGameObjectBoss::FrameMove(DWORD elapsed)
{
	if (BossPos <1) {
		m_Pos.x -= 100.f * elapsed / 1000.f;
	}
	if (m_Pos.x <200) {
		m_Pos.x += 100.f * elapsed / 1000.f;
		BossPos++;
	}
	if (BossPos %2==1) {
		m_Pos.x += 100.f * elapsed / 1000.f;
	}
	if (m_Pos.x > 1000) {
		m_Pos.x -= 100.f * elapsed / 1000.f;
		BossPos++;
	}
	if (BossPos % 2 == 0) {
		m_Pos.x -= 100.f * elapsed / 1000.f;
	}
	m_BBPos.x = m_Pos.x + 250;
}
BOOL CGameObjectBoss::OutMapChk()
{
	//맵밖을 실제 윈도우 크기보다 조금 더 여유공간을 둠
	if (m_Option < 1) {
		if (m_Pos.x > 2800 || m_Pos.x < 100 ||
			m_Pos.y > 900 + 100 ||
			m_Pos.x + m_rTiled.right * m_Scale.x < -100 ||
			m_Pos.y + m_rTiled.bottom * m_Scale.y < -100
			)return true;
	}
	return false;

}

BOOL CGameObjectBoss::IsFire()
{
	if (m_Option < 1) {
		if (timeGetTime() - m_bulletTimer > 1000) {
			m_bulletTimer = timeGetTime();
			return true;
		}
	}
	return false;

}BOOL CGameObjectBoss::IsFire2()
{
	if (m_Option < 1) {
		if (timeGetTime() - m_bulletTimer > 1000) {
			m_bulletTimer = timeGetTime();
			return true;
		}
	}
	return false;
}