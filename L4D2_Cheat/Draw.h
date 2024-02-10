#pragma once
#include <Windows.h>
#include "Structure.h"
#include "Offsets.h"
#include "Memory.h"
using namespace std;

class Draw
{
public:
	HWND hExWnd;
	RECT rectGame;



	RECT rect;
	int width;
	int height;

	RECT rectEx;
	int widthEx;
	int heightEx;

	BOOL WorldToScreen(Vec3& worldPos, Vec2& screenPos);
	void GetWindowInfo();
};
extern Draw draw;
