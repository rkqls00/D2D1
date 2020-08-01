#pragma once
//#include "CSceneObject.h"

//스테이지 2
class CSceneObjectScene02 : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* bg = nullptr; //배경
	CGameObject* hero = nullptr; //플레이어 캐릭터
	CGameObject* Boss = nullptr; //보스 캐릭터
	CGameObject* Hp = nullptr; //체력바
public:
	CSceneObjectScene02();
	~CSceneObjectScene02();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

