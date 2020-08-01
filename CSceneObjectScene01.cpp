#include "_StdAfx.h"
#include "CProcessManager.h"
CSceneObjectScene01::CSceneObjectScene01()
{
} 


CSceneObjectScene01::~CSceneObjectScene01()
{
	Destroy();
}

void CSceneObjectScene01::Init()
{
	op = 0;
	that = 0;
	mobSpawn = timeGetTime();
	m_pInput = new CInput;
	CGameObject* ScrollTemp_1;
	CGameObject* ScrollTemp_2;
	m_rtBox.left = 1450;
	m_rtBox.top = 0;
	m_rtBox.right = 1521;
	m_rtBox.bottom = 71;
	if (Re >= 0) {
		ScrollTemp_1 = new CGameObjectScroolMap(L"./image/Stage1.jpg", D2D1::Point2F(0, 0), 1600, 900);
		AddObject(ScrollTemp_1);

		hero = new CGameObjectHero(L"./image/Player.png", D2D1::Point2F(800, 700), 186, 170); //여기 좌표는 무시
		AddObject(hero);

		Hp = new CGameObjectButton(L"./image/UI_bar_full.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (Replayed > 0) {
		((CGameObjectHero*)(hero))->m_PLife = 11;
		Score = 0;
	}
}
void CSceneObjectScene01::Render()
{
	if (nowStatus == STAGE) {
		if (m_bIsCrash) {
			pause2 = new CGameObjectButton(L"./image/Pause2.jpg", D2D1::Point2F(1450, 0), 71, 71);
			AddObject(pause2);
		}
		else {
			pause = new CGameObjectButton(L"./image/Pause.jpg", D2D1::Point2F(1450, 0), 71, 71);
			AddObject(pause);
		}
		CSceneObject::Render();
	}
}
void CSceneObjectScene01::FrameMove(DWORD elapsed)
{
		
	if (((CGameObjectHero*)(hero))->m_PLife<11) {
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
		if (((CGameObjectHero*)(hero))->m_PLife==0) {
			Destroy();
			nowStatus = GAMEOVER;
		}
		if (m_EStop != 0) {
			Boom1 = new CGameObjectButton(L"./image/Boom1.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
			AddObject(Boom1);
			RemoveEffect++;
			m_EStop = 0;
		}
		if (RemoveEffect > 0) {
			if (timeGetTime() - mobSpawn > 200) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom2.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect2++;
				RemoveEffect = 0;
					}
				}
		if (RemoveEffect2 > 0) {
			if (timeGetTime() - mobSpawn > 300) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom3.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect3++;
				RemoveEffect2 = 0;
			}
		}
		if (RemoveEffect3 > 0) {
			if (timeGetTime() - mobSpawn > 400) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom4.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect4++;
				RemoveEffect3 = 0;
			}
		}
		if (RemoveEffect4 > 0) {
			if (timeGetTime() - mobSpawn > 500) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom5.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect5++;
				RemoveEffect4 = 0;
			}
		}
		if (RemoveEffect5 > 0) {
			if (timeGetTime() - mobSpawn > 600) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom6.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect6++;
				RemoveEffect5 = 0;
			}
		}
		if (RemoveEffect6 > 0) {
			if (timeGetTime() - mobSpawn > 700) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom7.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect7++;
				RemoveEffect6 = 0;
			}
		}
		if (RemoveEffect7 > 0) {
			if (timeGetTime() - mobSpawn > 800) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom8.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect8++;
				RemoveEffect7 = 0;
			}
		}
		if (RemoveEffect8 > 0) {
			if (timeGetTime() - mobSpawn > 900) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				Boom1 = new CGameObjectButton(L"./image/Boom9.png", D2D1::Point2F(m_Epos.x, m_Epos.y), 165, 151);
				AddObject(Boom1);
				RemoveEffect9++;
				RemoveEffect8 = 0;
			}
		}
		if (RemoveEffect9 > 0) {
			if (timeGetTime() - mobSpawn > 1000) {
				((CGameObjectButton*)(Boom1))->m_isLive = false;
				RemoveEffect9 = 0;
			}
		}
		if(Score>10){
			nowStatus = STAGE2;
		}
		if (((CGameObjectHero*)(hero))->GetIsFire())
			AddObject(((CGameObjectHero*)(hero))->Fire());
		if (SceneStop < 1) {
			if (timeGetTime() - mobSpawn > 1000) {
				AddObject(new CGameObjectEnemy(
					L"./image/EnemyChar.png",
					D2D1::Point2F(rand() % (1600 - 128), -128),
					286, 170)
				);
				mobSpawn = timeGetTime();
			}
		}
		if (m_pInput)
		{
			m_pInput->FrameMove();

			m_ptPoint = m_pInput->GetMousePos();
		}
		m_bIsCrash = PtInRect(&m_rtBox, m_ptPoint);
		if (op > 0) {
			//Destroy();
			nowStatus = OPTION;
			op = 0;
		}
		CSceneObject::FrameMove(elapsed);
}
void CSceneObjectScene01::Control(CInput* pInput)
{
	CSceneObject::Control(pInput);
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			op = 1;
		}
	}
}
void CSceneObjectScene01::Command(CGameObject* pSource)
{

}
