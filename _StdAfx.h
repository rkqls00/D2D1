#pragma once

#ifndef __STDAFX_H_
#define __STDAFX_H_

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "winmm.lib")

#include <windows.h>

#include <atlstr.h>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <Mmsystem.h>
#include <string.h>
#include <map>
#include <list>

#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>

enum TAGS {
	TEXTURE,
	PLAYER,
	ENEMY,
	BULLET,
	EBULLET,
	BUTTON,
	BOSS,
	BBULLET,
	BBULLETT
};

enum SCENE {
	START,
	STAGE,
	STAGE2,
	ENDING,
	CHOICE,
	OPTION,
	CREDIT,
	RULE,
	GAMEOVER
};

BOOL AABB(RECT obj1, RECT obj2);
void DEBUG_LOG(LPCSTR fmt, ...);
extern int nowStatus;
extern D2D1_POINT_2F m_pPos; //�÷��̾� ��ǥ
extern D2D1_POINT_2F m_BBPos; //������ǥ
extern int TTurn; //���������� ���� ����� ����( ���� ���� 2���� ������ ����ϱ� ����)
extern int Re; //�ɼ�->�������� 1���� �ٽ� �ϴ� ������ ��� �ϱ� ���� ����� ����
extern int Replayed; //�ɼ�->�������� 1���� ó������ �ٽ� �÷��� �ϱ� ���� ����� ����
extern int that; // ���÷��� �ؾ��ϴ� ���������� ������ �˱����� ����
#include "CGraphics.h"
#include "input.h"
#include "CDX2DApp.h"
#include "CSprite.h"
#include "IGameObject.h"
#include "GameObject.h"
#include "CGameObjectHero.h"
#include "CGameObjectBullet.h"
#include "CGameObjectEnemy.h"
#include "CGameObjectBoss.h"
#include "CGameObjectEnemyBullet.h"
#include "CGameObjectScroolMap.h"
#include "CGameObjectManager.h"
#include "CGameObjectBossBullet.h"
#include "CGameObjectBossBullet2.h"
#include "CGameObjectBossBullet3.h"
#include "CGameObjectBossBullet4.h"
#include "CProcessManager.h"
#include "CSceneObject.h"
#include "CSceneObjectScene01.h"
#include "CSceneObjectSceneOption.h"
#include "CSceneObjectSceneGoodEnding.h"
#include "MainStage.h"
#include "CSceneObjectSceneChoice.h"
#include "CSceneObjectScene02.h"
#include "CSceneObjectSceneGameOver.h"
#include "CSceneObjectSceneCredit.h"
#include "CSceneObjectSceneRule.h"
#include "CSpriteManager.h"
#include "CGameManager.h"
#include "CGame.h"
#include "CGameObjectButton.h"
#include "Collide.h"
#endif