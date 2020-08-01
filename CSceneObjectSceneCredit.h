#pragma once

//크레딧
class CSceneObjectSceneCredit: public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* bg = nullptr;
	CGameObject* Creditpage = nullptr;
	CGameObject* Homebutton1 = nullptr; //홈버튼
	CGameObject* Homebutton2 = nullptr; //홈버튼 마우스에 올렸을 경우
	CGameObject* Homebutton3 = nullptr; //홈버튼 클릭했을 경우
	CInput* m_pInput;
	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;

	int Close=0; //크레딧을 닫기위해 선언한 변수
public:
	CSceneObjectSceneCredit();
	~CSceneObjectSceneCredit();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

