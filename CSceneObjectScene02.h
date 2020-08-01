#pragma once
//#include "CSceneObject.h"

//�������� 2
class CSceneObjectScene02 : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* bg = nullptr; //���
	CGameObject* hero = nullptr; //�÷��̾� ĳ����
	CGameObject* Boss = nullptr; //���� ĳ����
	CGameObject* Hp = nullptr; //ü�¹�
public:
	CSceneObjectScene02();
	~CSceneObjectScene02();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

