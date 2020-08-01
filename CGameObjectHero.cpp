#include "_StdAfx.h"

CGameObjectHero::CGameObjectHero(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight)
	: CGameObject(FileName, Pos, SprWidth, SprHeight, PLAYER)
{
}

CGameObjectHero::~CGameObjectHero() 
{
}

void CGameObjectHero::Control(CInput* Input)
{
	if (Input->KeyPress(VK_LEFT) && m_Pos.x > 0)
		m_Pos.x -= 5;
	if (Input->KeyPress(VK_RIGHT) && m_Pos.x + m_rTiled.right < 1600)
		m_Pos.x += 5;
	if (Input->KeyPress(VK_UP) && m_Pos.y > 0)
		m_Pos.y -= 5;
	if (Input->KeyPress(VK_DOWN) && m_Pos.y + m_rTiled.bottom < 900)
		m_Pos.y += 5;

	if (Input->KeyDown(VK_SPACE) ||
		(Input->KeyPress(VK_SPACE) && timeGetTime() - start > 100))
	{
		m_isFire = true;
		m_isFire2 = true;
		start = timeGetTime();
	}
}

CGameObject* CGameObjectHero::Fire()
{
	CGameObject* tmp = new CGameObjectBullet(
		L"./image/PlayerBullet.png",
		D2D1::Point2F(m_Pos.x + 75, m_Pos.y - 40),
		31,
		92
	);
	m_isFire = false;

	return tmp;
}

CGameObject* CGameObjectHero::Fire2() {
	CGameObject* tmp2 = new CGameObjectBullet(
		L"./image/PlayerBullet.png",
		D2D1::Point2F(m_Pos.x + 120, m_Pos.y - 40),
		31,
		92
	);
	m_isFire2 = false;

	return tmp2;
}
