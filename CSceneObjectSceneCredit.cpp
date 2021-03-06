#include "_StdAfx.h"
#include "CSceneObjectSceneCredit.h"

CSceneObjectSceneCredit::CSceneObjectSceneCredit()
{
}

CSceneObjectSceneCredit::~CSceneObjectSceneCredit()
{
	Destroy();
}

void CSceneObjectSceneCredit::Init()
{
	mobSpawn = timeGetTime();
	m_pInput = new CInput;
	m_rtBox.left = 1200;
	m_rtBox.top = 110;
	m_rtBox.right = 1801;
	m_rtBox.bottom = 172;
	Close = 0;
	bg = new CGameObjectScroolMap(L"./image/bg.png", D2D1::Point2F(0, 0), 1600, 900);
	AddObject(bg);
	Creditpage = new CGameObjectButton(L"./image/Creditpage.png", { 270, 55 }, 1068, 734);
	AddObject(Creditpage);
}

void CSceneObjectSceneCredit::Render()
{
	if (nowStatus == CREDIT) {
		if (m_bIsCrash) {
			Homebutton2 = new CGameObjectButton(L"./image/HomeButtonMouseover.png", { 1200,110 }, 61, 62);
			AddObject(Homebutton2);
		}
		else {
			Homebutton1 = new CGameObjectButton(L"./image/HomeButton.png", { 1200,110 }, 61, 62);
			AddObject(Homebutton1);
		}
		CSceneObject::Render();
	}
}

void CSceneObjectSceneCredit::FrameMove(DWORD elapsed)
{
	if (Close > 0) {
		Homebutton3 = new CGameObjectButton(L"./image/HomeButtonClick.png", { 1200,110 }, 61, 62);
		AddObject(Homebutton3);
		if (timeGetTime() - mobSpawn > 1000) {
			nowStatus = START;
		}
	}
	CSceneObject::FrameMove(elapsed);
}

void CSceneObjectSceneCredit::Control(CInput* pInput)
{
	if (m_pInput)
	{
		m_pInput->FrameMove();

		m_ptPoint = m_pInput->GetMousePos();
	}
	m_bIsCrash = PtInRect(&m_rtBox, m_ptPoint);

	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			Close = 1;
		}
	}
	CSceneObject::Control(pInput);
}

void CSceneObjectSceneCredit::Command(CGameObject* pSource)
{
}
