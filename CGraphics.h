#pragma once

class CGraphics
{
	ID2D1Factory* m_factory;
	ID2D1HwndRenderTarget* m_rendertarget;

	IDWriteFactory* m_writeFactory;
	ID2D1SolidColorBrush* m_Redbrush;
	ID2D1SolidColorBrush* m_Blackbrush;
	ID2D1SolidColorBrush* m_Whitebrush;
	IDWriteTextFormat* m_format;
	//IDWriteTextLayout* m_textLayout;
public:
	CGraphics();
	~CGraphics();

	inline ID2D1HwndRenderTarget* GetRenderTarget() { return m_rendertarget; }
	INT Init(HWND hWnd, RECT rcWin);
	void Cleanup();

	void BeginDraw() { m_rendertarget->BeginDraw(); }
	void EndDraw() { m_rendertarget->EndDraw(); }
	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a);

	void DrawTextOut(LPCWSTR text, D2D1_POINT_2F Pos);
};

