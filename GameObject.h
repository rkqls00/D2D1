#pragma once
class CGameObject : public IGameObject				//0504
{
protected:
	D2D1_POINT_2F			m_Pos; //��ġ
	CSprite*				m_Sprite; //�̹���
	D2D1_POINT_2F           m_BPos;
public:
	D2D1_POINT_2F			m_Scale; //ũ��
	D2D1_RECT_F				m_rTiled; //������
	INT						m_tag;
	CStringW				m_Name; //�̸�
	BOOL					m_isLive; //����? ����?
	INT                    m_PLife; //�÷��̾��� ����
	INT                    m_BLife; //���� ����
	INT                    m_Option; 
	CGameObject(LPCWSTR sFileName, D2D1_POINT_2F Pos, int sprWidth, int sprHeight, int tag);
	virtual ~CGameObject(void);

	virtual void Render() override; //����־ ���Ǵ� �ؾߵ�
	virtual void FrameMove(DWORD elapsed) override; //����־ ���Ǵ� �ؾߵ�
	virtual void Control( CInput* Input) override;		//07 //����־ ���Ǵ� �ؾߵ�

	D2D1_POINT_2F GetPos() { return m_Pos; }
};

