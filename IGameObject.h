#pragma once
class IGameObject					//05
{
public:
	virtual ~IGameObject() {};

	virtual void FrameMove(DWORD elapsed) = 0; //CGameObject에서 사용하기 위한 정의
	virtual void Render() = 0;
	virtual void Control(CInput* Input) = 0;	//07
};