#include "_StdAfx.h"
#include "CSceneObjectSceneOption.h"
#include "CProcessManager.h"
CSceneObjectSceneOption::CSceneObjectSceneOption()
{
}

CSceneObjectSceneOption::~CSceneObjectSceneOption()
{
	Destroy();
}

void CSceneObjectSceneOption::Init()
{
	SceneStop = 1;
	m_pInput = new CInput;
	m_rtBox2.left = 595;
	m_rtBox2.top = 250;
	m_rtBox2.right = 1001;
	m_rtBox2.bottom = 335;

	m_rtBox.left = 595;
	m_rtBox.top = 420;
	m_rtBox.right = 1001;
	m_rtBox.bottom = 505;

	m_rtBox3.left = 595;
	m_rtBox3.top = 590;
	m_rtBox3.right = 1001;
	m_rtBox3.bottom = 675;

	bg = new CGameObjectScroolMap(L"./image/bg.png", D2D1::Point2F(0, 0), 1600, 900);
	AddObject(bg);
	Options = new CGameObjectButton(L"./image/Options.png", D2D1::Point2F(400, 45), 782, 806);
	AddObject(Options);

	ReStart = 0;
	resume = 0;
	exit = 0;
}

void CSceneObjectSceneOption::Render()
{
	if (nowStatus == OPTION) {
		CSceneObject::Render();
	}
}

void CSceneObjectSceneOption::FrameMove(DWORD elapsed)
{
	if (m_blsCrash2) {
		Resume2 = new CGameObjectButton(L"./image/Resume2.png", D2D1::Point2F(595, 250), 406, 85);
		AddObject(Resume2);
	}
	else {
		Resume = new CGameObjectButton(L"./image/Resume.png", D2D1::Point2F(595, 250), 406, 85);
		AddObject(Resume);
	}
	if (m_bIsCrash) {
		Replay2 = new CGameObjectButton(L"./image/Replay2.png", D2D1::Point2F(595, 420), 406, 85);
		AddObject(Replay2);
	}
	else {
		Replay = new CGameObjectButton(L"./image/Replay.png", D2D1::Point2F(595, 420), 406, 85);
		AddObject(Replay);
	}
	if (m_blsCrash3) {
		Exit2 = new CGameObjectButton(L"./image/Exit22.png", D2D1::Point2F(595, 590), 406, 85);
		AddObject(Exit2);
	}
	else {
		Exit = new CGameObjectButton(L"./image/Exit11.png", D2D1::Point2F(595, 590), 406, 85);
		AddObject(Exit);
	}
	/*if (((CGameObjectHero*)(hero))->m_PLife < 12 && ((CGameObjectHero*)(hero))->m_PLife>10) {
		Hp = new CGameObjectButton(L"./image/UI_bar_full.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 11 && ((CGameObjectHero*)(hero))->m_PLife>9) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-1.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 10 && ((CGameObjectHero*)(hero))->m_PLife>8) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-2.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 9 && ((CGameObjectHero*)(hero))->m_PLife>7) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-3.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 8 && ((CGameObjectHero*)(hero))->m_PLife>6) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-4.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 7 && ((CGameObjectHero*)(hero))->m_PLife>5) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-5.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 6 && ((CGameObjectHero*)(hero))->m_PLife>4) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-6.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 5 && ((CGameObjectHero*)(hero))->m_PLife>3) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-7.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 4 && ((CGameObjectHero*)(hero))->m_PLife>2) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-8.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 3 && ((CGameObjectHero*)(hero))->m_PLife>1) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_energybar_damage-9.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}
	if (((CGameObjectHero*)(hero))->m_PLife < 2 && ((CGameObjectHero*)(hero))->m_PLife>0) {
		((CGameObjectButton*)(Hp))->m_isLive = false;
		Hp = new CGameObjectButton(L"./image/UI_bar_zero.png", D2D1::Point2F(1150, 800), 395, 57);
		AddObject(Hp);
	}*/
	if (resume > 0) {
		Re=1;
		SceneStop = 0;
		nowStatus = STAGE;
	}
	if(ReStart > 0) {
		Replayed=1;
		SceneStop = 0;
		nowStatus = CHOICE;
	}
	if (exit > 0) {
		ExitProcess(0);
	}
	if (m_pInput)
	{
		m_pInput->FrameMove();

		m_ptPoint = m_pInput->GetMousePos();
	}
	m_blsCrash2 = PtInRect(&m_rtBox2, m_ptPoint);
	m_bIsCrash = PtInRect(&m_rtBox, m_ptPoint);
	m_blsCrash3 = PtInRect(&m_rtBox3, m_ptPoint);
	CSceneObject::FrameMove(elapsed);
}

void CSceneObjectSceneOption::Control(CInput* pInput)
{
	if (m_blsCrash2) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			resume = 1;
		}
	}
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			ReStart = 1;
		}
	}
	if (m_blsCrash3) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			exit = 1;
		}
	}
	CSceneObject::Control(pInput);
}

void CSceneObjectSceneOption::Command(CGameObject* pSource)
{
}
