#pragma once
#include <Windows.h>
#include "Structure.h"
#include "Offsets.h"
#include "Memory.h"
using namespace std;

class Draw
{
public:
	HWND hExWnd;//蒙版窗口句柄
	RECT rectGame;//游戏窗口大小信息


	RECT rect; //内窗口分辨率
	int width; //内窗口宽
	int height; //内窗口高

	RECT rectEx; //外窗口分辨率
	int widthEx; //外窗口宽
	int heightEx; //外窗口高

	void DrawRect(HDC hDC, RECT rect);//绘制瞄准镜方框
	void DrawHP(HDC hDC, HBRUSH hBrush, RECT  rect, float hp);

	BOOL WorldToScreen(Vec3& worldPos, Vec2& screenPos);
	void GetWindowInfo();
};
extern Draw draw;
