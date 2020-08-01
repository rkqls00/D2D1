#pragma once
#include "CSceneObject.h"

//���ӿ��� ��
class CSceneObjectSceneGameOver : public CSceneObject
{
private:
	CGameObject* bg = nullptr;
	CGameObject* Replay = nullptr;
	CGameObject* Replay2 = nullptr;
	CGameObject* Replay3 = nullptr;


	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	CInput* m_pInput;
	int before = 0;     //���÷��̸� �������� �� ���������� ����Ǳ� ���� ����
public:
	CSceneObjectSceneGameOver();
	~CSceneObjectSceneGameOver();
	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

