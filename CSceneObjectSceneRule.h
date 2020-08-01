#pragma once

//��Ģ�����
class CSceneObjectSceneRule : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* bg = nullptr;
	CGameObject* Rulepage = nullptr;
	CGameObject* Homebutton1 = nullptr;
	CGameObject* Homebutton2 = nullptr;
	CGameObject* Homebutton3 = nullptr;
	CInput* m_pInput;
	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	int Close = 0; //â�� �ݱ����� ����
public:
	CSceneObjectSceneRule();
	~CSceneObjectSceneRule();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

