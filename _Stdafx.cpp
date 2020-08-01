#include "_StdAfx.h"

BOOL AABB(RECT obj1, RECT obj2)
{
	RECT tmp;
	if (IntersectRect(&tmp, &obj1, &obj2)) return true;
	return false;
}

void DEBUG_LOG(LPCSTR fmt, ...) {
	char buf[256];
	va_list list;
	va_start(list, fmt);
	vsprintf_s(buf, fmt, list);
	va_end(list);
	OutputDebugStringA(buf);
}  

int nowStatus = START;
D2D1_POINT_2F m_pPos;
D2D1_POINT_2F m_BBPos;
int TTurn = 1;
int Re = 0;
int Replayed = 0;
int that = 0;
