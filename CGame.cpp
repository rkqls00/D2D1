#include "_StdAfx.h"

CGame::CGame()
{
	m_SpriteManager = nullptr;
}


CGame::~CGame()
{
	Destroy();
}

INT CGame::Init()
{
	CDX2DApp::Init();

	m_GameObjectManager = new CGameObjectManager();
	m_SpriteManager = new CSpriteManager();

	CGameManager::Init(m_Input, m_Gfx, m_GameObjectManager, m_SpriteManager); ///사용할수 있도록 연결
	m_Game01.push_back(new MainStage());
	m_Game01.push_back(new CSceneObjectScene01());
	m_Game01.push_back(new CSceneObjectScene02());
	m_Game01.push_back(new CSceneObjectSceneGoodEnding());
	m_Game01.push_back(new CSceneObjectSceneChoice());
	m_Game01.push_back(new CSceneObjectSceneOption());
	m_Game01.push_back(new CSceneObjectSceneCredit());
	m_Game01.push_back(new CSceneObjectSceneRule());
	m_Game01.push_back(new CSceneObjectSceneGameOver());
	
	
	auto iter = m_Game01.begin();
	std::advance(iter, nowStatus);
	(*iter)->Init();

	return 0;
}
void CGame::Destroy()
{
	for (auto iter : m_Game01) {
		delete iter;
		iter = nullptr;
	}
	m_Game01.clear();

	if (m_GameObjectManager) {
		delete m_GameObjectManager;
		m_GameObjectManager = nullptr;
	}

	if (m_SpriteManager) {
		delete m_SpriteManager;
		m_SpriteManager = nullptr;
	}
}
INT		CGame::FrameMove(DWORD elapsed)
{
	static int wasStatus = nowStatus;
	CDX2DApp::FrameMove(elapsed);

	auto iter = m_Game01.begin();
	std::advance(iter, nowStatus);
	
	(*iter)->FrameMove(elapsed);

	if (wasStatus != nowStatus) {
		auto iter = m_Game01.begin();
		std::advance(iter, nowStatus);
		(*iter)->Init();
		(*iter)->FrameMove(elapsed);
	}
	wasStatus = nowStatus;
	return 0;
}

INT		CGame::Control(CInput* Input) {
	auto iter = m_Game01.begin();
	std::advance(iter, nowStatus);

	(*iter)->Control(Input);

	
	/*if (nowStatus == GAMEOVER) {
		for (size_t i = 0; i < 0xff; i++)
			if (Input->KeyDown(i)) {
				Destroy();
				Cleanup();
				ExitProcess(0);
				return 0;
			}
	}*/
	return 0;
}


INT		CGame::Render()
{
	m_Gfx->BeginDraw();
	m_Gfx->ClearScreen(0.0f, 0.0f, 0.5f);

	auto iter = m_Game01.begin();
	std::advance(iter, nowStatus);
	(*iter)->Render();

	wchar_t Wstring[100];
	//swprintf(Wstring, 100, L"현재 프레임 : %d\n조작 : 방향키\n총알 발사 : 스페이스바", m_fps);
	//m_Gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	//m_Gfx->DrawTextOut(Wstring, D2D1::Point2F(0, 0));

	m_Gfx->EndDraw();

	return 0;
}



LRESULT CGame::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
	case WM_PAINT:
	{
		break;
	}
	}

	return CDX2DApp::MsgProc(hWnd, msg, wParam, lParam);
}