#pragma once
//#include "CSceneObject.h"

//옵션창
class CSceneObjectSceneOption : public CSceneObject
{
private:
	CGameObject* Options = nullptr;
	CGameObject* Replay = nullptr; 
	CGameObject* Replay2 = nullptr;
	CGameObject* Exit = nullptr;
	CGameObject* Exit2 = nullptr;
	CGameObject* Resume = nullptr;
	CGameObject* Resume2 = nullptr;
	CGameObject* bg = nullptr;
	CGameObject* Hp = nullptr;
	int ReStart = 0; //UI 실행을 위한 변수
	int exit = 0;    //UI 실행을 위한 변수
	int resume = 0;  //UI 실행을 위한 변수
	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	RECT					m_rtBox2;
	RECT					m_rtBox3;
	BOOL                    m_blsCrash2;
	BOOL                    m_blsCrash3;
	CInput* m_pInput;
public:
	CSceneObjectSceneOption();
	~CSceneObjectSceneOption();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

