#include "_StdAfx.h"
#include "CSceneObjectScene02.h"
#include "CProcessManager.h"
CSceneObjectScene02::CSceneObjectScene02()
{
}

CSceneObjectScene02::~CSceneObjectScene02()
{
	Destroy();
}

void CSceneObjectScene02::Init()
{
	PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	mobSpawn = timeGetTime();
	that = 1;
	bg = new CGameObjectScroolMap(L"./image/Map.jpg", { 0, 0 }, 1600, 900);
	AddObject(bg);
	Boss = new CGameObjectBoss(L"./image/Boss.png", { 500, 50 }, 448, 256);
	AddObject(Boss);
	hero = new CGameObjectHero(L"./image/Player.png", { 500, 500 }, 186, 170);
	AddObject(hero);
	((CGameObjectHero*)(hero))->m_PLife = 11;
	Hp = new CGameObjectButton(L"./image/UI_bar_full.png", D2D1::Point2F(1150, 800), 395, 57);
	AddObject(Hp);
}

void CSceneObjectScene02::Render()
{
	if (nowStatus == STAGE2) {
		CSceneObject::Render();
	}
}

void CSceneObjectScene02::FrameMove(DWORD elapsed)
{
	if (((CGameObjectBoss*)(Boss))->m_BLife == 0) {
		Destroy();
		nowStatus = ENDING;
	}
	if (((CGameObjectHero*)(hero))->m_PLife == 0) {
		Destroy();
		nowStatus = GAMEOVER;
	}
	if (((CGameObjectHero*)(hero))->GetIsFire()) {
		AddObject(((CGameObjectHero*)(hero))->Fire());
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 11) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-1.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
		if (((CGameObjectHero*)(hero))->m_PLife < 10) {
			((CGameObjectButton*)(Hp))->m_isLive = false;
			Hp = new CGameObjectButton(L"./image/UI_energybar_damage-2.png", D2D1::Point2F(1150, 800), 395, 57);
			AddObject(Hp);
			if (((CGameObjectHero*)(hero))->m_PLife < 9) {
				((CGameObjectButton*)(Hp))->m_isLive = false;
				Hp = new CGameObjectButton(L"./image/UI_energybar_damage-3.png", D2D1::Point2F(1150, 800), 395, 57);
				AddObject(Hp);
			}
			if (((CGameObjectHero*)(hero))->m_PLife < 8) {
				((CGameObjectButton*)(Hp))->m_isLive = false;
				Hp = new CGameObjectButton(L"./image/UI_energybar_damage-4.png", D2D1::Point2F(1150, 800), 395, 57);
				AddObject(Hp);
			}
			if (((CGameObjectHero*)(hero))->m_PLife < 7) {
				((CGameObjectButton*)(Hp))->m_isLive = false;
				Hp = new CGameObjectButton(L"./image/UI_energybar_damage-5.png", D2D1::Point2F(1150, 800), 395, 57);
				AddObject(Hp);
			}
			if (((CGameObjectHero*)(hero))->m_PLife < 6) {
				((CGameObjectButton*)(Hp))->m_isLive = false;
				Hp = new CGameObjectButton(L"./image/UI_energybar_damage-6.png", D2D1::Point2F(1150, 800), 395, 57);
				AddObject(Hp);
				if (((CGameObjectHero*)(hero))->m_PLife < 5) {
					((CGameObjectButton*)(Hp))->m_isLive = false;
					Hp = new CGameObjectButton(L"./image/UI_energybar_damage-7.png", D2D1::Point2F(1150, 800), 395, 57);
					AddObject(Hp);
				}
				if (((CGameObjectHero*)(hero))->m_PLife < 4) {
					((CGameObjectButton*)(Hp))->m_isLive = false;
					Hp = new CGameObjectButton(L"./image/UI_energybar_damage-8.png", D2D1::Point2F(1150, 800), 395, 57);
					AddObject(Hp);
				}
				if (((CGameObjectHero*)(hero))->m_PLife < 3) {
					((CGameObjectButton*)(Hp))->m_isLive = false;
					Hp = new CGameObjectButton(L"./image/UI_energybar_damage-9.png", D2D1::Point2F(1150, 800), 395, 57);
					AddObject(Hp);
				}
				if (((CGameObjectHero*)(hero))->m_PLife < 2) {
					((CGameObjectButton*)(Hp))->m_isLive = false;
					Hp = new CGameObjectButton(L"./image/UI_bar_zero.png", D2D1::Point2F(1150, 800), 395, 57);
					AddObject(Hp);
				}
			}
		}
	}

		CSceneObject::FrameMove(elapsed);
}

void CSceneObjectScene02::Control(CInput* pInput)
{
	CSceneObject::Control(pInput);
}

void CSceneObjectScene02::Command(CGameObject* pSource)
{
}
