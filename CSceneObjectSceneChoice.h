#pragma once
#include "CSceneObject.h"

//스테이지 선택창
class CSceneObjectSceneChoice : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* Bg = nullptr; //배경
	CGameObject* Stage1 = nullptr;  //스테이지 1
	CGameObject* Stage1Mouse = nullptr; //스테이지 1 버튼에 마우스를 올렸을 경우
	CGameObject* Stage1Click = nullptr; //스테이지 1을 클릭했을 경우
	CGameObject* Stage2 = nullptr;  
	CGameObject* Stage2Mouse = nullptr;
	CGameObject* Stage2Click = nullptr;
	INT ChoiceScene = 0; //스테이지를 전환하기 위해 선언한 변수
	INT ChoiceScene2 = 0;
	POINT					m_ptPoint;
	RECT					m_rtBox;
	RECT					m_rtBox2;
	BOOL					m_bIsCrash;
	BOOL                    m_blsCrash2;
	CInput* m_pInput;
public:
	CSceneObjectSceneChoice();
	~CSceneObjectSceneChoice();

	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

