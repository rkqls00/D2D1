#pragma once
class IGameObject					//05
{
public:
	virtual ~IGameObject() {};

	virtual void FrameMove(DWORD elapsed) = 0; //CGameObject���� ����ϱ� ���� ����
	virtual void Render() = 0;
	virtual void Control(CInput* Input) = 0;	//07
};