#include "_Stdafx.h"

CInput* CGameManager::m_Input = NULL;
CGraphics* CGameManager::m_gfx = NULL;
CSpriteManager* CGameManager::m_SpriteManager = NULL;
CGameObjectManager* CGameManager::m_GameObjectManager = NULL;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init(CInput* Input, CGraphics* gfx, CGameObjectManager* GOMg, CSpriteManager* SprMg) // , CSceneObject* Scene)
{
	m_Input = Input;
	m_gfx = gfx;
	m_GameObjectManager = GOMg;
	m_SpriteManager = SprMg;

	//Loading = true;
	//m_CurrentScene = Scene;
	//m_CurrentScene->Init();
	//Loading = false;
}
/*
void CGameManager::SwitchScene(CSceneObject* Scene)
{
	Loading = true;
	m_CurrentScene->Destroy();
	Scene->Init();
	delete m_CurrentScene;
	m_CurrentScene = Scene;
	Loading = false;

}

void CGameManager::Render()
{
	if (Loading) return;
	m_CurrentScene->Render();
}
void CGameManager::FrameMove() {
	if (Loading) return;
	m_CurrentScene->FrameMove();
}
void CGameManager::Control()
{
	if (Loading) return;
	m_CurrentScene->Control();
}
*/