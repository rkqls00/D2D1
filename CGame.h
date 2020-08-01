#pragma once
//#include "D3DApp.h"

class CGame : public CDX2DApp
{
	CGameObjectManager*			m_GameObjectManager;
	CSpriteManager*				m_SpriteManager;
	std::list<CSceneObject*>	m_Game01;

public:

	CGame();
	~CGame();

	virtual INT		Init();
	virtual void	Destroy();

	virtual INT		FrameMove(DWORD elpased);
	virtual INT		Render();
	virtual INT		Control(CInput* Input);

	virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);


};

