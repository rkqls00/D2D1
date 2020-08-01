#pragma once
class CGameObject : public IGameObject				//0504
{
protected:
	D2D1_POINT_2F			m_Pos; //위치
	CSprite*				m_Sprite; //이미지
	D2D1_POINT_2F           m_BPos;
public:
	D2D1_POINT_2F			m_Scale; //크기
	D2D1_RECT_F				m_rTiled; //사이즈
	INT						m_tag;
	CStringW				m_Name; //이름
	BOOL					m_isLive; //죽음? 살음?
	INT                    m_PLife; //플레이어의 생명
	INT                    m_BLife; //보스 생명
	INT                    m_Option; 
	CGameObject(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int tag);
	virtual ~CGameObject(void);

	virtual void Render() override; //비어있어도 정의는 해야됨
	virtual void FrameMove(DWORD elapsed) override; //비어있어도 정의는 해야됨
	virtual void Control( CInput* Input) override;		//07 //비어있어도 정의는 해야됨

	D2D1_POINT_2F GetPos() { return m_Pos; }
};

