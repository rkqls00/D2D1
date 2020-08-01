#pragma once
#include "CSceneObject.h"

//�������� ����â
class CSceneObjectSceneChoice : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime();
	CGameObject* Bg = nullptr; //���
	CGameObject* Stage1 = nullptr;  //�������� 1
	CGameObject* Stage1Mouse = nullptr; //�������� 1 ��ư�� ���콺�� �÷��� ���
	CGameObject* Stage1Click = nullptr; //�������� 1�� Ŭ������ ���
	CGameObject* Stage2 = nullptr;  
	CGameObject* Stage2Mouse = nullptr;
	CGameObject* Stage2Click = nullptr;
	INT ChoiceScene = 0; //���������� ��ȯ�ϱ� ���� ������ ����
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

