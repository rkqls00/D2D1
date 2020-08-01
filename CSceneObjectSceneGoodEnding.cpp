#include "_StdAfx.h"
#include "CSceneObjectSceneGoodEnding.h"

CSceneObjectSceneGoodEnding::CSceneObjectSceneGoodEnding()
{
}

CSceneObjectSceneGoodEnding::~CSceneObjectSceneGoodEnding()
{
	Destroy();
}

void CSceneObjectSceneGoodEnding::Init()
{
	m_pInput = new CInput;

	before = 0;
	m_rtBox.left = 535;
	m_rtBox.top = 400;
	m_rtBox.right = 1074;
	m_rtBox.bottom = 508;

	bg11 = new CGameObjectScroolMap(L"./image/page_youwin.png", { 0, 0 }, 1600, 900);
	AddObject(bg11);
}

void CSceneObjectSceneGoodEnding::Render()
{
	if (nowStatus == ENDING)
	{
		CSceneObject::Render();
	}
}

void CSceneObjectSceneGoodEnding::FrameMove(DWORD elapsed)
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
		nowStatus = STAGE2;
	}
	CSceneObject::FrameMove(elapsed);
}

void CSceneObjectSceneGoodEnding::Control(CInput* pInput)
{
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			before = 1;
		}
	}
	CSceneObject::Control(pInput);
}

void CSceneObjectSceneGoodEnding::Command(CGameObject* pSource)
{
}
