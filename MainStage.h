#pragma once
#include "CSceneObject.h"

//메인화면
class MainStage : public CSceneObject
{
private:
	CGameObject* bg1 = nullptr;           //배경
	CGameObject* Start1 = nullptr;       //시작버튼
	CGameObject* Start2 = nullptr;  
	CGameObject* Exit1 = nullptr;        //나가기버튼
	CGameObject* Exit2 = nullptr;
	CGameObject* Credit1 = nullptr;     //크래딧버튼
	CGameObject* Credit2 = nullptr;   
	CGameObject* Rule1 = nullptr;      //규칙,설명버튼
	CGameObject* Rule2 = nullptr;
	CGameObject* Title = nullptr;     //타이틀
	CGameObject* Sound = nullptr;    //소리
	CGameObject* fix = nullptr;     

	int NextScene = 0; //게임시작 하기위해 다음 씬으로 이동하기 위해 선언한 변수
	int CreditPageOpen = 0;   //크레딧으로 이동하기 위해 선언한 변수
	int RuleOpen = 0;        //설명,규칙으로 이동 하기 위해 선언한 변수
	
	POINT					m_ptPoint; //마우스
	RECT					m_rtBox;  //충돌범위
	RECT					m_rtBox2;
	RECT					m_rtBox3;
	RECT					m_rtBox4;
	RECT                    m_rtBox5;
	BOOL					m_bIsCrash; //충돌체크
	BOOL                    m_blsCrash2;
	BOOL                    m_blsCrash3;
	BOOL                    m_blsCrash4;
	BOOL                    m_blsCrash5;
	CInput* m_pInput;
public:
	MainStage();
	~MainStage();

	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

