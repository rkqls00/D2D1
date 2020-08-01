#include "_StdAfx.h"

extern CDX2DApp*	g_pDX2App;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//dk ahfmrpTek
	//_CrtSetBreakAlloc(153);

	CGame DX2DApp;

	// Create the system object.
	g_pDX2App = &DX2DApp;

	// Initialize and run the system object.
	HRESULT hr = DX2DApp.Create(hInstance);
	if(hr != S_OK)
		return -1;

	return DX2DApp.Run();

}