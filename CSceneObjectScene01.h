#pragma once
//�������� 1
class CSceneObjectScene01 : public CSceneObject
{
private:
	time_t mobSpawn = timeGetTime(); 
	CGameObject* hero = nullptr; //�÷��̾� ĳ����
	CGameObject* pause = nullptr; //���� �ִ� �Ͻ����� �ɼ� ul
	CGameObject* pause2 = nullptr; //���� �ִ� �Ͻ����� �ɼ� ul�� ���콺 �÷��� ��� �ٲ�� �̹���
	CGameObject* Boom1 = nullptr; //�� ���� ����Ʈ
	CGameObject* Boom2 = nullptr;
	CGameObject* Boom3 = nullptr;
	CGameObject* Boom4 = nullptr;
	CGameObject* Boom5 = nullptr;
	CGameObject* Boom6 = nullptr;
	CGameObject* Boom7 = nullptr;
	CGameObject* Boom8 = nullptr;
	CGameObject* Boom9 = nullptr;
	CGameObject* Hp = nullptr; //ü�¹�
	int op = 0; //�ɼ����� �̵��ϱ� ���� ����

	POINT					m_ptPoint; //���콺
	RECT					m_rtBox; //�浹����
	BOOL					m_bIsCrash; //�浹
	CInput* m_pInput;
	int PressReplay = 0; 
	int RemoveEffect = 0; //����Ʈ ����� ���� ����
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

