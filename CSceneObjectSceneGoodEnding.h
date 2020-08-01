#pragma once
#include "CSceneObject.h"

//���� Ŭ�����
class CSceneObjectSceneGoodEnding : public CSceneObject
{
private:
	CGameObject* bg11 = nullptr;
	CGameObject* Replay = nullptr;
	CGameObject* Replay2 = nullptr;
	CGameObject* Replay3= nullptr;

	POINT					m_ptPoint;
	RECT					m_rtBox;
	BOOL					m_bIsCrash;
	CInput* m_pInput;
	int before = 0;        //���÷��̸� �������� �� ���������� ����Ǳ� ���� ����
public:
	CSceneObjectSceneGoodEnding();
	~CSceneObjectSceneGoodEnding();

	void Init();

	void Render();
	void FrameMove(DWORD elapsed);
	void Control(CInput* pInput);

	void Command(CGameObject* pSource);
};

