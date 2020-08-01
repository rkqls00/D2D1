#include "_Stdafx.h"
#include <Windows.h>
CProcessManager::CProcessManager()
{
}


CProcessManager::~CProcessManager()
{
	RemoveAllObject();
}

void CProcessManager::Init() {
	BulletSpawn = timeGetTime();
}
void CProcessManager::AddObject(CGameObject* p_pObject) {

	m_listGObject.push_back(p_pObject);
}

void CProcessManager::RemoveObject(CGameObject* p_pObject) {
	std::list<CGameObject*>::iterator iter;
	for (iter= m_listGObject.begin(); iter != m_listGObject.end(); iter++) {
		if ((*iter) == p_pObject) {
			m_listGObject.erase(iter);
			break;
		}
	}
}

void CProcessManager::RenderAllObject() {
	for (auto iter : m_listGObject)
		iter->Render();
}

void CProcessManager::FrameMoveAllObject(DWORD elapsed) {
	if (SceneStop <1) {
		for (auto iter : m_listGObject)
			iter->FrameMove(elapsed);
		for (auto iter = m_listGObject.begin(); iter != m_listGObject.end();) {
			if ((*iter)->m_isLive) {
				if ((*iter)->m_tag == BULLET) {
					if (((CGameObjectBullet*)(*iter))->OutMapChk())
						(*iter)->m_isLive = false;
					else {
						BOOL isColl = FALSE;

						D2D1_POINT_2F bPos = (*iter)->GetPos();
						RECT b = {
							bPos.x + 10, bPos.y + 10,
							bPos.x + (*iter)->m_rTiled.right - 10, bPos.y + (*iter)->m_rTiled.bottom - 10
						};
						//적 위치 검사
						for (auto iter2 = m_listGObject.begin(); iter2 != m_listGObject.end();) {
							if ((*iter2)->m_isLive && (*iter2)->m_tag == ENEMY) {
								D2D1_POINT_2F ePos = (*iter2)->GetPos();
								RECT e = {
									ePos.x + 20, ePos.y + 20,
									ePos.x + ((*iter2)->m_rTiled.right - 20) * (*iter2)->m_Scale.x,
									ePos.y + ((*iter2)->m_rTiled.bottom - 20) * (*iter2)->m_Scale.y
								};

								if (AABB(b, e)) {
									isColl = TRUE;
									(*iter2)->m_isLive = false;
									m_Epos = ePos;
									Score++;
									m_EStop++;
									break;
								}
							}
							else if ((*iter2)->m_isLive && (*iter2)->m_tag == BOSS) {
								D2D1_POINT_2F ePos = (*iter2)->GetPos();
								RECT e = {
									ePos.x + 20, ePos.y + 20,
									ePos.x + ((*iter2)->m_rTiled.right - 20) * (*iter2)->m_Scale.x,
									ePos.y + ((*iter2)->m_rTiled.bottom - 20) * (*iter2)->m_Scale.y
								};

								if (AABB(b, e)) {
									isColl = TRUE;
									(*iter2)->m_BLife--;
									m_Epos = ePos;
									Score++;
									m_EStop++;
									break;
								}
							}
							iter2++;
						}
						if (isColl) (*iter)->m_isLive = false;

					}
				}
				else if ((*iter)->m_tag == EBULLET) {
					if (((CGameObjectEnemyBullet*)(*iter))->OutMapChk())
						(*iter)->m_isLive = false;
					else {
						BOOL isColl = FALSE;

						D2D1_POINT_2F bPos = (*iter)->GetPos();
						RECT b = {
							bPos.x + 10, bPos.y + 10,
							bPos.x + (*iter)->m_rTiled.right - 10, bPos.y + (*iter)->m_rTiled.bottom - 10
						};
						//플레이어 위치 검사
						for (auto iter2 = m_listGObject.begin(); iter2 != m_listGObject.end();) {
							if ((*iter2)->m_PLife && (*iter2)->m_tag == PLAYER) {
								 pPos = (*iter2)->GetPos();
								RECT p = {
									pPos.x + 20, pPos.y + 20,
									pPos.x + ((*iter2)->m_rTiled.right - 20),
									pPos.y + ((*iter2)->m_rTiled.bottom - 20)
								};
								m_PlPos = pPos;
								if (AABB(b, p)) {
									isColl = TRUE;
									(*iter2)->m_PLife--;

									break;
								}
							}
							iter2++;
						}

						if (isColl) (*iter)->m_isLive = false;
					}
				}
				else if ((*iter)->m_tag == BBULLET) {
					if (((CGameObjectEnemyBullet*)(*iter))->OutMapChk())
						(*iter)->m_isLive = false;
					else {
						BOOL isColl = FALSE;

						D2D1_POINT_2F bPos = (*iter)->GetPos();
						RECT b = {
							bPos.x + 10, bPos.y + 10,
							bPos.x + (*iter)->m_rTiled.right - 10, bPos.y + (*iter)->m_rTiled.bottom - 10
						};
						//플레이어 위치 검사
						for (auto iter2 = m_listGObject.begin(); iter2 != m_listGObject.end();) {
							if ((*iter2)->m_PLife && (*iter2)->m_tag == PLAYER) {
								 pPos = (*iter2)->GetPos();
								RECT p = {
									pPos.x + 20, pPos.y + 20,
									pPos.x + ((*iter2)->m_rTiled.right - 20),
									pPos.y + ((*iter2)->m_rTiled.bottom - 20)
								};
								m_PlPos = pPos;
								if (AABB(b, p)) {
									isColl = TRUE;
									(*iter2)->m_PLife--;
									break;
								}
							}
							iter2++;
						}

						if (isColl) (*iter)->m_isLive = false;
					}
				}
				else if ((*iter)->m_tag == BBULLETT) {
				if (((CGameObjectEnemyBullet*)(*iter))->OutMapChk())
					(*iter)->m_isLive = false;
				else {
					BOOL isColl = FALSE;

					D2D1_POINT_2F bPos = (*iter)->GetPos();
					RECT b = {
						bPos.x + 10, bPos.y + 10,
						bPos.x + (*iter)->m_rTiled.right - 10, bPos.y + (*iter)->m_rTiled.bottom - 10
					};
					//플레이어 위치 검사
					for (auto iter2 = m_listGObject.begin(); iter2 != m_listGObject.end();) {
						if ((*iter2)->m_PLife && (*iter2)->m_tag == PLAYER) {
							 pPos = (*iter2)->GetPos();
							RECT p = {
								pPos.x + 20, pPos.y + 20,
								pPos.x + ((*iter2)->m_rTiled.right - 20),
								pPos.y + ((*iter2)->m_rTiled.bottom - 20)
							};
							m_PlPos = pPos;
							if (AABB(b, p)) {
								isColl = TRUE;
								(*iter2)->m_PLife--;
								break;
							}
						}
						iter2++;
					}

					if (isColl) (*iter)->m_isLive = false;
				}
				}
				else if ((*iter)->m_tag == ENEMY) {
					if (((CGameObjectEnemy*)(*iter))->OutMapChk())
						(*iter)->m_isLive = false;
					else if (((CGameObjectEnemy*)(*iter))->IsFire())
						AddObject(new CGameObjectEnemyBullet(
							L"./image/EnemyBullet1.png",
							D2D1::Point2F(
								(*iter)->GetPos().x + 104,
								(*iter)->GetPos().y + 108
							),
							31, 92)
						);
				}
				else if ((*iter)->m_tag == BOSS) {
					if (((CGameObjectBoss*)(*iter))->OutMapChk())
						(*iter)->m_isLive = false; 
					else if (((CGameObjectBoss*)(*iter))->IsFire()) {
						WTurn++;
						if (WTurn % 3 == 0) {
							TTurn += 1;
						}
						if(TTurn%2!=0){
							AddObject(new CGameObjectBossBullet(
								L"./image/EnemyBullet1.png",
								D2D1::Point2F(
									(*iter)->GetPos().x + 250,
									(*iter)->GetPos().y + 108
								),
								31, 92)
							);
							AddObject(new CGameObjectBossBullet2(
								L"./image/EnemyBullet1.png",
								D2D1::Point2F(
									(*iter)->GetPos().x + 150,
									(*iter)->GetPos().y + 108
								),
								31, 92)
							);
						BossBullet1 = new CGameObjectBossBullet3(
								L"./image/EnemyBullet1.png",
								D2D1::Point2F(
									(*iter)->GetPos().x + 350,
									(*iter)->GetPos().y + 108
								),
								31, 92);
							AddObject(BossBullet1);
						}
							m_pPos = pPos;
							if (TTurn % 2 == 0){
								AddObject(new CGameObjectBossBullet4(
								L"./image/EnemyBullet1.png",
								D2D1::Point2F(
									(*iter)->GetPos().x + 250,
									(*iter)->GetPos().y + 108
								),
								31, 92)
							);
							}
					}
				}
				iter++;
			}
			//죽어있는 객체면 삭제처리
			//(isLive변수가 false가 된 후 1프레임 뒤에 삭제 처리됨)
			else {
				if (*iter) {
					delete* iter;
					*iter = nullptr;
				}
				iter = m_listGObject.erase(iter);
			}

		}
	}
}

void CProcessManager::ControlAllObject(CInput* pInput) {
	std::list<CGameObject*>::iterator iter;
	for (iter = m_listGObject.begin(); iter != m_listGObject.end(); iter++) {
		(*iter)->Control(pInput);
	}
}


void CProcessManager::RemoveAllObject() {
    for (auto iter : m_listGObject) {
		if (iter) {
			delete iter;
			iter = nullptr;
		}
	}
	m_listGObject.clear();
}
