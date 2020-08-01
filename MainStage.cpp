#include "_StdAfx.h"
#include "MainStage.h"

MainStage::MainStage()
{
	
}

MainStage::~MainStage()
{
	Destroy();
}

void MainStage::Init()
{
	//nowStatus = START;
	m_rtBox.left = 200;
	m_rtBox.top = 500;
	m_rtBox.right = 739;
	m_rtBox.bottom = 608;

	m_rtBox2.left = 850;
	m_rtBox2.top = 500;
	m_rtBox2.right = 1389;
	m_rtBox2.bottom = 608;
	
	m_rtBox3.left = 200;
	m_rtBox3.top = 700;
	m_rtBox3.right = 739;
	m_rtBox3.bottom = 808;
	
	m_rtBox4.left = 850;
	m_rtBox4.top = 700;
	m_rtBox4.right = 1389;
	m_rtBox4.bottom = 808;

	RuleOpen = 0;
	CreditPageOpen = 0;

	m_pInput = new CInput;
	if (nowStatus == START) {
		bg1 = new CGameObjectScroolMap(L"./image/Main.png", D2D1::Point2F(0, 0), 1600, 900);
		AddObject(bg1);
		Title = new CGameObjectButton(L"./image/Title.png", { 300, 50 }, 1004, 351);
		AddObject(Title);
		Sound = new CGameObjectButton(L"./image/Sound.jpg", { 1390, 0 }, 62, 62);
		AddObject(Sound);
		fix = new CGameObjectButton(L"./image/Fix.jpg", { 1470, 0 }, 62, 62);
		AddObject(fix);
	}
	PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
}

void MainStage::Render()
{
	if (nowStatus == START) {
		if (m_bIsCrash)
		{
			Start2 = new CGameObjectButton(L"./image/Start2.png", { 200, 500 }, 539, 108);
			AddObject(Start2);
		}
		else {
			Start1 = new CGameObjectButton(L"./image/Start.png", { 200, 500 }, 539, 108);
			AddObject(Start1);
		}
		if (m_blsCrash2) {
			Exit2 = new CGameObjectButton(L"./image/Exit2.png", { 850, 500 }, 539, 108);
			AddObject(Exit2);
		}
		else
		{
			Exit1 = new CGameObjectButton(L"./image/Exit.png", { 850, 500 }, 539, 108);
			AddObject(Exit1);
		}
		if (m_blsCrash3) {
			Credit2 = new CGameObjectButton(L"./image/Credit2.png", { 200, 700 }, 539, 108);
			AddObject(Credit2);
		}
		else {
			Credit1 = new CGameObjectButton(L"./image/Credit.png", { 200, 700 }, 539, 108);
			AddObject(Credit1);
		}
		if (m_blsCrash4) {
			Rule2 = new CGameObjectButton(L"./image/Rule2.png", { 850, 700 }, 539, 108);
			AddObject(Rule2);
		}
		else {
			Rule1 = new CGameObjectButton(L"./image/Rule.png", { 850, 700 }, 539, 108);
			AddObject(Rule1);
		}
		CSceneObject::Render();
	}
	
	
}

void MainStage::FrameMove(DWORD elapsed)
{
	if (NextScene > 0) {
		Destroy();
		nowStatus = CHOICE;
	}
	if (CreditPageOpen > 0) {
		nowStatus = CREDIT;
	}
	if (RuleOpen > 0) {
		nowStatus = RULE;
	}
	if (m_pInput)
	{
		m_pInput->FrameMove();

		m_ptPoint = m_pInput->GetMousePos();
	}
	m_bIsCrash  = PtInRect(&m_rtBox, m_ptPoint);
	m_blsCrash2 = PtInRect(&m_rtBox2, m_ptPoint);
	m_blsCrash3 = PtInRect(&m_rtBox3, m_ptPoint);
	m_blsCrash4 = PtInRect(&m_rtBox4, m_ptPoint);
	CSceneObject::FrameMove(elapsed);
}

void MainStage::Control(CInput* pInput)
{
	CSceneObject::Control(pInput);
	if (m_bIsCrash) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			NextScene++;
		}
	}
	if (m_blsCrash2) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			Destroy();
			ExitProcess(0);
		}
	}
	if (m_blsCrash3) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			CreditPageOpen=1;
		}
		
	}
	if (m_blsCrash4) {
		if (pInput->KeyPress(VK_LBUTTON)) {
			RuleOpen=1;	
		}
	}
}

void MainStage::Command(CGameObject* pSource)
{
}
