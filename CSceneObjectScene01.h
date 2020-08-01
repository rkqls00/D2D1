#pragma once
//스테이지 1
class CSceneObjectScene01 : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime(); 
	CGameObject* hero = nullptr; //플레이어 캐릭터
	CGameObject* pause = nullptr; //위에 있는 일시정지 옵션 ul
	CGameObject* pause2 = nullptr; //위에 있는 일시정지 옵션 ul에 마우스 올렸을 경우 바뀌는 이미지
	CGameObject* Boom1 = nullptr; //적 죽음 이펙트
	CGameObject* Boom2 = nullptr;
	CGameObject* Boom3 = nullptr;
	CGameObject* Boom4 = nullptr;
	CGameObject* Boom5 = nullptr;
	CGameObject* Boom6 = nullptr;
	CGameObject* Boom7 = nullptr;
	CGameObject* Boom8 = nullptr;
	CGameObject* Boom9 = nullptr;
	CGameObject* Hp = nullptr; //체력바
	int op = 0; //옵션으로 이동하기 위한 변수

	POINT					m_ptPoint; //마우스
	RECT					m_rtBox; //충돌범위
	BOOL					m_bIsCrash; //충돌
	CInput* m_pInput;
	int PressReplay = 0; 
	int RemoveEffect = 0; //이펙트 지우기 위한 변수
	int RemoveEffect2 = 0;
	int RemoveEffect3 = 0;
	int RemoveEffect4 = 0;
	int RemoveEffect5 = 0;
	int RemoveEffect6 = 0;
	int RemoveEffect7 = 0;
	int RemoveEffect8 = 0;
	int RemoveEffect9 = 0;

public:
	CSceneObjectScene01(); 
	~CSceneObjectScene01();
	
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

