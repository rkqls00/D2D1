#pragma once
#include "CSceneObject.h"

//게임오버 씬
class CSceneObjectSceneGameOver : public CSceneObject
{
private:
	CGameObject* bg = nullptr;
	CGameObject* Replay = nullptr;
	CGameObject* Replay2 = nullptr;
	CGameObject* Replay3 = nullptr;


	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	CInput* m_pInput;
	int before = 0;     //리플레이를 눌렀을때 전 스테이지가 실행되기 위한 변수
public:
	CSceneObjectSceneGameOver();
	~CSceneObjectSceneGameOver();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

