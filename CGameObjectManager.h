#pragma once
class CGameObjectManager
{
protected:
	std::map<CStringW, CGameObject*> m_gameObjectMap; //object에 넣은 친구들 통합쳐서 전체 관리가능
public:
	CGameObjectManager();
	~CGameObjectManager();

	void AddObject(CGameObject* p_pObject);
	void RemoveObject(CGameObject* p_pOjbect);
	CGameObject* FindObject(LPCWSTR sFile);

	void RemoveAllObject();

};

