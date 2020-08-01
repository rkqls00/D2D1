#pragma once

class CProcessManager 
{
protected:
	std::list<CGameObject*> m_listGObject;
	time_t BulletSpawn = timeGetTime();
	CGameObject* BossBullet1=nullptr;
	INT WTurn = 0; //���� �Ѿ� ������ ���� ���� (������ �Ѿ˰� ����ź�� ������ �ϱ� ����)
public:
	int Score=0; //���� �׿����� ������ ��� ���� ����
	int SceneStop = 0; //�ɼ��� �������� �Ͻ������� ���� ����
	D2D1_POINT_2F			m_Epos; //���� ���� �ڸ��� ����Ʈ�� ����� �ϱ����� ����
	D2D1_POINT_2F           m_PlPos; //�÷��̾� ��ǥ
	D2D1_POINT_2F           pPos;   //�÷��̾� ��ǥ
	int m_EStop =0; //���� �׾����� ����Ʈ�� ���� ���� ����
	CProcessManager(void);
	~CProcessManager(void);
	void Init();
	void AddObject(CGameObject* p_pObject);
	void RemoveObject(CGameObject* p_pOjbect);

	void RenderAllObject();
	void FrameMoveAllObject(DWORD elapsed);
	void ControlAllObject(CInput* pInput);	//07
	void RemoveAllObject();
};
