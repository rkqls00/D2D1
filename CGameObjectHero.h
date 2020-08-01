#pragma once

//플레이어
class CGameObjectHero : public CGameObject
{
private:
	time_t start = timeGetTime();
	bool m_isFire = false;
	bool m_isFire2 = false;
public:
	CGameObjectHero(LPCWSTR FileName, D2D1_POINT_2F Pos, int SprWidth, int SprHeight);
	~CGameObjectHero();

	virtual void Control(CInput* Input) override;

	bool GetIsFire() { return m_isFire; }
	bool GetIsFire2() { return m_isFire2; }
	CGameObject* Fire();
	CGameObject* Fire2();
};

