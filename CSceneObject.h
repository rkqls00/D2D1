#pragma once
class CSceneObject : public IGameObject, public CProcessManager 
{
public:
	CSceneObject();
	~CSceneObject();

	virtual void Init();
	virtual void Destroy();

	virtual void Render() override;
	virtual void FrameMove(DWORD elapsed) override;
	virtual void Control(CInput* pInput) override;

	virtual void Command(CGameObject* pSource) = 0;
};

