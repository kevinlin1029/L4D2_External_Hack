#include "Draw.h"

Draw draw;

void Draw::GetWindowInfo()
{
	GetClientRect(offsets.hWnd, &rect);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;

	//ȡ�ⴰ����Ϣ
	GetWindowRect(offsets.hWnd, &rectEx);
	widthEx = rectEx.right - rectEx.left;
	heightEx = rectEx.bottom - rectEx.top;
}


BOOL Draw::WorldToScreen(Vec3& worldPos, Vec2& screenPos)
{
	GetWindowInfo();
	float matrix[4][4];
	ReadProcessMemory(offsets.hProcess, (LPCVOID)(offsets.engineBase + 0x601FDC + offsets.dwViewMatrix), matrix, 64, NULL);

	//�������� ---> ��������
	Vec4 clipPos; //��������
	clipPos.x = matrix[0][0] * worldPos.x + matrix[0][1] * worldPos.y + matrix[0][2] * worldPos.z + matrix[0][3];
	clipPos.y = matrix[1][0] * worldPos.x + matrix[1][1] * worldPos.y + matrix[1][2] * worldPos.z + matrix[1][3];
	clipPos.z = matrix[2][0] * worldPos.x + matrix[2][1] * worldPos.y + matrix[2][2] * worldPos.z + matrix[2][3];
	clipPos.w = matrix[3][0] * worldPos.x + matrix[3][1] * worldPos.y + matrix[3][2] * worldPos.z + matrix[3][3];
	//�ж������ڲ���������Ұ��Χ��
	if (clipPos.w < 0.01) { return false; }

	//��������---> NDC����
	Vec3 NDC;
	NDC.x = clipPos.x / clipPos.w;
	NDC.y = clipPos.y / clipPos.w;
	NDC.z = clipPos.z / clipPos.w;

	//NDC���� ---> ��Ļ����
	screenPos.x = width / 2 + (width / 2) * NDC.x;
	screenPos.y = height / 2 - (height / 2) * NDC.y + 30;

	return true;
}

