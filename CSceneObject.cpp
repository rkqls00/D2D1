#include "_StdAfx.h"

CSceneObject::CSceneObject()
{
}


CSceneObject::~CSceneObject()
{
	Destroy();
}

void CSceneObject::Init()
{
}

void CSceneObject::Destroy()
{
	RemoveAllObject();
}

void CSceneObject::Render()
{
	RenderAllObject();
}
void CSceneObject::FrameMove(DWORD elapsed)
{
	FrameMoveAllObject(elapsed);
}
void CSceneObject::Control(CInput* pInput)
{
	ControlAllObject(pInput);
}