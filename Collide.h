#pragma once
class Collide: public CSceneObject
{

public:
	Collide();
	~Collide();
	BOOL IsPointInRect(RECT rt, POINT pt);
};
