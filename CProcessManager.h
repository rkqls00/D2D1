#pragma once

class CProcessManager 
{
protected:
	std::list<CGameObject*> m_listGObject;
	time_t BulletSpawn = timeGetTime();
	CGameObject* BossBullet1=nullptr;
	INT WTurn = 0; //보스 총알 패턴을 위한 변수 (퍼지는 총알과 유도탄을 번갈아 하기 위한)
public:
	int Score=0; //적을 죽였을때 점수를 얻기 위한 변수
	int SceneStop = 0; //옵션을 눌렀을때 일시정지를 위한 변수
	D2D1_POINT_2F			m_Epos; //적이 죽은 자리에 이펙트를 생기게 하기위해 만듬
	D2D1_POINT_2F           m_PlPos; //플레이어 좌표
	D2D1_POINT_2F           pPos;   //플레이어 좌표
	int m_EStop =0; //적이 죽었을때 이펙트를 띠우기 위한 변수
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
