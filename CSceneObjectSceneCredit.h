#pragma once

//ũ����
class CSceneObjectSceneCredit: public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* bg = nullptr;
	CGameObject* Creditpage = nullptr;
	CGameObject* Homebutton1 = nullptr; //Ȩ��ư
	CGameObject* Homebutton2 = nullptr; //Ȩ��ư ���콺�� �÷��� ���
	CGameObject* Homebutton3 = nullptr; //Ȩ��ư Ŭ������ ���
	CInput* m_pInput;
	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;

	int Close=0; //ũ������ �ݱ����� ������ ����
public:
	CSceneObjectSceneCredit();
	~CSceneObjectSceneCredit();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

