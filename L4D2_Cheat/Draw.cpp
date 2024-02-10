#include "Draw.h"

Draw draw;

void Draw::GetWindowInfo()
{
	GetClientRect(offsets.hWnd, &rect);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;

	//取外窗口信息
	GetWindowRect(offsets.hWnd, &rectEx);
	widthEx = rectEx.right - rectEx.left;
	heightEx = rectEx.bottom - rectEx.top;
}


BOOL Draw::WorldToScreen(Vec3& worldPos, Vec2& screenPos)
{
	GetWindowInfo();
	float matrix[4][4];
	ReadProcessMemory(offsets.hProcess, (LPCVOID)(offsets.engineBase + 0x601FDC + offsets.dwViewMatrix), matrix, 64, NULL);

	//世界坐标 ---> 剪辑坐标
	Vec4 clipPos; //剪辑坐标
	clipPos.x = matrix[0][0] * worldPos.x + matrix[0][1] * worldPos.y + matrix[0][2] * worldPos.z + matrix[0][3];
	clipPos.y = matrix[1][0] * worldPos.x + matrix[1][1] * worldPos.y + matrix[1][2] * worldPos.z + matrix[1][3];
	clipPos.z = matrix[2][0] * worldPos.x + matrix[2][1] * worldPos.y + matrix[2][2] * worldPos.z + matrix[2][3];
	clipPos.w = matrix[3][0] * worldPos.x + matrix[3][1] * worldPos.y + matrix[3][2] * worldPos.z + matrix[3][3];
	//判断人物在不在我们视野范围里
	if (clipPos.w < 0.01) { return false; }

	//剪辑坐标---> NDC坐标
	Vec3 NDC;
	NDC.x = clipPos.x / clipPos.w;
	NDC.y = clipPos.y / clipPos.w;
	NDC.z = clipPos.z / clipPos.w;

	//NDC坐标 ---> 屏幕坐标
	screenPos.x = width / 2 + (width / 2) * NDC.x;
	screenPos.y = height / 2 - (height / 2) * NDC.y + 30;

	return true;
}

