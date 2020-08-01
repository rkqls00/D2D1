#include "_StdAfx.h"
#include "CSceneObjectSceneChoice.h"

CSceneObjectSceneChoice::CSceneObjectSceneChoice()
{
}

CSceneObjectSceneChoice::~CSceneObjectSceneChoice()
{
	Destroy();
}

void CSceneObjectSceneChoice::Init()
{
	mobSpawn = timeGetTime();
	m_rtBox.left = 200;
	m_rtBox.top = 400;
	m_rtBox.right = 739;
	m_rtBox.bottom = 508;

	m_rtBox2.left = 900;
	m_rtBox2.top = 400;
	m_rtBox2.right = 1439;
	m_rtBox2.bottom = 508;

	m_pInput = new CInput;

	Bg = new CGameObjectScroolMap(L"./image/page_stage.png", D2D1::Point2F(0, 0), 1600, 900);
	AddObject(Bg);
	Stage1 = new CGameObjectButton(L"./image/Button_stage1.png", { 200, 400 }, 539, 108);
	AddObject(Stage1);
	Stage2 = new CGameObjectButton(L"./image/Button_stage2.png", { 900, 400 }, 534, 108);
	AddObject(Stage2);
}

void CSceneObjectSceneChoice::Render()
{
	if (nowStatus == CHOICE)
	{
		
		if (ChoiceScene > 0) {
			Stage1Click = new CGameObjectButton(L"./image/Button_stage1_click.png", { 200, 400 }, 539, 108);
			AddObject(Stage1Click);
		}
		if (m_blsCrash2) {
			Stage2Mouse = new CGameObjectButton(L"./image/Button_stage2_mouseover.png", { 900, 400 }, 534, 108);
			AddObject(Stage2Mouse);
		}
		else {
			Stage2 = new CGameObjectButton(L"./image/Button_stage2.png", { 900, 400 }, 534, 108);
			AddObject(Stage2);
		}
		if (ChoiceScene2 > 0) {
			Stage2Click = new CGameObjectButton(L"./image/Button_stage2_click.png", { 900, 400 }, 534, 108);
			AddObject(Stage2Click);
		}
		CSceneObject::Render();
	}
}

void CSceneObjectSceneChoice::FrameMove(DWORD elapsed)
{
	if (m_bIsCrash)
	{
		Stage1Mouse = new CGameObjectButton(L"./image/Button_stage1_mouseover.png", { 200, 400 }, 539, 108);
		AddObject(Stage1Mouse);
	}
	else {
		Stage1 = new CGameObjectButton(L"./image/Button_stage1.png", { 210, 400 }, 539, 108);
		AddObject(Stage1);
	}
	if (ChoiceScene > 0) {
		if (timeGetTime() - mobSpawn > 1500) {
			Destroy();
			nowStatus = STAGE;
		}
	}
	if (ChoiceScene2 > 0) {
		if (timeGetTime() - mobSpawn > 1500) {
			Destroy();
			nowStatus = STAGE2;
		}
	}
	if (m_pInput)
	{
		m_pInput->FrameMove();

		m_ptPoint = m_pInput->GetMousePos();
	}
	m_bIsCrash = PtInRect(&m_rtBox, m_ptPoint);
	m_blsCrash2 = PtInRect(&m_rtBox2, m_ptPoint);
	CSceneObject::FrameMove(elapsed);
}

void CSceneObjectSceneChoice::Control(CInput* pInput)
{
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			ChoiceScene++;
		}
	}
	if (m_blsCrash2) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			ChoiceScene2++;
		}
	}
	CSceneObject::Control(pInput);
}

void CSceneObjectSceneChoice::Command(CGameObject* pSource)
{
}
