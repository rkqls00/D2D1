#include "_StdAfx.h"



CGraphics::CGraphics()
{
	m_factory = NULL;
	m_rendertarget = NULL;
	m_Redbrush = NULL;


}


CGraphics::~CGraphics()
{
}

INT CGraphics::Init(HWND hWnd, RECT rcWin) {

	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
	if (res != S_OK) return -1;

	res = m_factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd, D2D1::SizeU(rcWin.right- rcWin.left, rcWin.bottom-rcWin.top)),
		&m_rendertarget);
	if (res != S_OK) return -1;

	res = m_rendertarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &m_Redbrush);
	res = m_rendertarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_Blackbrush);
	res = m_rendertarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_Whitebrush);

	res = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown **>(&m_writeFactory));

	m_writeFactory->CreateTextFormat(
		L"Gabiola",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		30.0f, // font size
		L"", //locale
		&m_format);
	////////////////////////////////////////////////////////////////////////////

	return 0;
}

void CGraphics::ClearScreen(float r, float g, float b)
{
	m_rendertarget->Clear(D2D1::ColorF(r, g, b));
}
void CGraphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	m_Redbrush->SetColor(D2D1::ColorF(r, g, b, a));
	m_rendertarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius),
		m_Redbrush, 3.0f);
}

void CGraphics::Cleanup() {
	if (m_format)
		m_format->Release();
	if (m_Redbrush)
		m_Redbrush->Release();
	if (m_Whitebrush)
		m_Whitebrush->Release();
	if (m_Blackbrush)
		m_Blackbrush->Release();
	if (m_rendertarget)
		m_rendertarget->Release();
	if (m_writeFactory)
		m_writeFactory->Release();
	if (m_factory)
		m_factory->Release();

}
void CGraphics::DrawTextOut(LPCWSTR text, D2D1_POINT_2F Pos)
{
	
	m_rendertarget->DrawTextW(text, lstrlen(text) , m_format, D2D1::RectF(Pos.x, Pos.y, 800, 600), m_Whitebrush);
}
