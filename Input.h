#pragma once

#define MAX_INPUT_KEY	256
#define MAX_INPUT_BTN	8

class CInput
{
public:
	enum EInputState
	{
		EINPUT_NONE  = 0,
		EINPUT_DOWN  = 1,
		EINPUT_UP	 = 2,
		EINPUT_PRESS = 3,
		EINPUT_DBCLK = 4,//DoubleClick
	};

public:
	HWND		m_hWnd;

	BYTE		m_KeyCur[MAX_INPUT_KEY];	// Ű���� ���� ����
	BYTE		m_KeyOld[MAX_INPUT_KEY];	// Ű���� ���� ����
	BYTE		m_KeyMap[MAX_INPUT_KEY];	// Ű���� ��

	BYTE		m_BtnCur[MAX_INPUT_BTN];	// ���콺 ���� ����
	BYTE		m_BtnOld[MAX_INPUT_BTN];	// ���콺 ���� ����
	BYTE		m_BtnMap[MAX_INPUT_BTN];	// ���콺 ��

	//D3DXVECTOR3	m_vcCur;					// �� ���콺 Z
	//D3DXVECTOR3 m_vcOld;
	//D3DXVECTOR3 m_vcEps;
	
	POINT m_vcCur;
	POINT m_vcOld;
	POINT m_vcEps;

	DWORD		m_dTimeDC;					// Double Click Time Interval
	DWORD		m_dBtnBgn[MAX_INPUT_BTN];	// Double Click Start
	INT			m_dBtnCnt[MAX_INPUT_BTN];	// Double Click Count


public:
	CInput();
	virtual ~CInput();

	INT			Create(HWND	hWnd);
	INT			FrameMove();
	LRESULT		MsgProc(HWND,UINT, WPARAM, LPARAM);

public:
	BOOL		KeyDown	(INT nKey);
	BOOL		KeyUp	(INT nKey);
	BOOL		KeyPress(INT nKey);
	INT			KeyState(INT nKey);

	BOOL		BtnDown	 (INT nBtn);
	BOOL		BtnUp	 (INT nBtn);
	BOOL		BtnPress (INT nBtn);
	INT			BtnState (INT nBtn);

	POINT GetMousePos();
	POINT GetMouseEps();
};

