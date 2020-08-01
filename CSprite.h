#pragma once
class CSprite
{
	CGraphics* m_gfx;
	ID2D1Bitmap* m_bmp;

	int m_imageWidth, m_imageHeight;
	int m_sprWidth, m_sprHeight;

	int m_sprAccross;

public:
	CSprite(LPCWSTR sFile, CGraphics* gfx, int sprWidth = 0, int sprHeight = 0);
//	CSprite(LPCWSTR sFile, CGraphics* gfx, int sprWidth, int sprHeight);
	~CSprite();

	void Draw();
	void Draw(D2D1_POINT_2F Pos);
//	void Draw(int index, int x, int y);
//	void Draw(int index, int x, int y, float angle);
	void Draw(D2D1_RECT_F *src, D2D1_POINT_2F pos, D2D1_POINT_2F Scale, D2D1_POINT_2F *center = NULL, float angle = 0);
//	ID2D1Bitmap* GetBmp() { return m_bmp; }
//	void SetSprSize(int SprSizeX, int SprSizeY) { m_sprWidth = SprSizeX; m_sprHeight = SprSizeY; }
};

