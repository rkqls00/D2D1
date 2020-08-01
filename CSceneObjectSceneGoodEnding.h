#pragma once
#include "CSceneObject.h"

//게임 클리어씬
class CSceneObjectSceneGoodEnding : public CSceneObject
{
private:
	CGameObject* bg11 = nullptr;
	CGameObject* Replay = nullptr;
	CGameObject* Replay2 = nullptr;
	CGameObject* Replay3= nullptr;

	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	CInput* m_pInput;
	int before = 0;        //리플레이를 눌렀을때 전 스테이지가 실행되기 위한 변수
public:
	CSceneObjectSceneGoodEnding();
	~CSceneObjectSceneGoodEnding();

	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

