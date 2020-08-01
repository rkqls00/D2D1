#pragma once
#include "CSceneObject.h"

//����ȭ��
class MainStage : public CSceneObject
{
private:
	CGameObject* bg1 = nullptr;           //���
	CGameObject* Start1 = nullptr;       //���۹�ư
	CGameObject* Start2 = nullptr;  
	CGameObject* Exit1 = nullptr;        //�������ư
	CGameObject* Exit2 = nullptr;
	CGameObject* Credit1 = nullptr;     //ũ������ư
	CGameObject* Credit2 = nullptr;   
	CGameObject* Rule1 = nullptr;      //��Ģ,�����ư
	CGameObject* Rule2 = nullptr;
	CGameObject* Title = nullptr;     //Ÿ��Ʋ
	CGameObject* Sound = nullptr;    //�Ҹ�
	CGameObject* fix = nullptr;     

	int NextScene = 0; //���ӽ��� �ϱ����� ���� ������ �̵��ϱ� ���� ������ ����
	int CreditPageOpen = 0;   //ũ�������� �̵��ϱ� ���� ������ ����
	int RuleOpen = 0;        //����,��Ģ���� �̵� �ϱ� ���� ������ ����
	
	POINT					m_ptPoint; //���콺
	RECT					m_rtBox;  //�浹����
	RECT					m_rtBox2;
	RECT					m_rtBox3;
	RECT					m_rtBox4;
	RECT                    m_rtBox5;
	BOOL					m_bIsCrash; //�浹üũ
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

