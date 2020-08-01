#include "_StdAfx.h"
#include "CSceneObjectSceneGameOver.h"

CSceneObjectSceneGameOver::CSceneObjectSceneGameOver()
{
}

CSceneObjectSceneGameOver::~CSceneObjectSceneGameOver()
{
	Destroy();
}

void CSceneObjectSceneGameOver::Init()
{
	m_pInput = new CInput;

	before = 0;

	m_rtBox.left = 535;
	m_rtBox.top = 300;
	m_rtBox.right = 1074;
	m_rtBox.bottom = 508;

	bg=new CGameObjectScroolMap(L"./image/page_gameover.png", { 0, 0 }, 1600, 900);
	AddObject(bg);
}

void CSceneObjectSceneGameOver::Render()
{
	if (nowStatus == GAMEOVER) {
		CSceneObject::Render();
	}
	
}

void CSceneObjectSceneGameOver::FrameMove(DWORD elapsed)
{
	if (m_bIsCrash) {
		Replay2 = new CGameObjectButton(L"./image/UI_button_replay_mouseover.png", { 535,400 }, 539, 108);
		AddObject(Replay2);
	}
	else {
		Replay = new CGameObjectButton(L"./image/UI_button_replay.png", { 535,400 }, 539, 108);
		AddObject(Replay);
	}
	if (m_pInput)
	{
		m_pInput->FrameMove();

		m_ptPoint = m_pInput->GetMousePos();
	}
	m_bIsCrash = PtInRect(&m_rtBox, m_ptPoint);


	if (before > 0) {
		if (that > 0) {
			nowStatus = STAGE2;
		}
		else {
			nowStatus = STAGE;
		}
	}
	CSceneObject::FrameMove(elapsed);
}

void CSceneObjectSceneGameOver::Control(CInput* pInput)
{
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			before = 1;
		}
	}
	CSceneObject::Control(pInput);
}

void CSceneObjectSceneGameOver::Command(CGameObject* pSource)
{
}
