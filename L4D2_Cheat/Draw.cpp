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


void Draw::DrawRect(HDC hDC, RECT rect)
{
	float width = rect.right - rect.left;
	int length = width / 3;
	MoveToEx(hDC, rect.left, rect.top + length, NULL);
	LineTo(hDC, rect.left, rect.top);
	LineTo(hDC, rect.left + length, rect.top);

	MoveToEx(hDC, rect.right, rect.top + length, NULL);
	LineTo(hDC, rect.right, rect.top);
	LineTo(hDC, rect.right - length, rect.top);

	MoveToEx(hDC, rect.left, rect.bottom - length, NULL);
	LineTo(hDC, rect.left, rect.bottom);
	LineTo(hDC, rect.left + length, rect.bottom);

	MoveToEx(hDC, rect.right, rect.bottom - length, NULL);
	LineTo(hDC, rect.right, rect.bottom);
	LineTo(hDC, rect.right - length, rect.bottom);



}

void Draw::DrawHP(HDC hDC, HBRUSH hBrush, RECT rect, float hp)
{
	//���Ʊ���ɫ
	int width = 5;
	RECT backgroundRect = {
		rect.left - width, //���Ͻ� x
		rect.top,
		rect.left - width / 2, //����ط���ֵԽ�ӽ�5 Ѫ�۾�Խϸ
		rect.bottom
	};
	FillRect(hDC, &backgroundRect, hBrush);

	//������ɫ��Ѫ�� 90 0.1
	HBRUSH hBrush2 = CreateSolidBrush(RGB(53, 196, 36));
	float autoTop = (rect.bottom - rect.top) * ((100 - hp) / 100) + rect.top; //100Ϊ��ѪѪ����
	RECT HpRect = {
		backgroundRect.left,
		autoTop,
		backgroundRect.right,
		backgroundRect.bottom,
	};
	FillRect(hDC, &HpRect, hBrush2);
	DeleteObject(hBrush2);
}


BOOL Draw::WorldToScreen(Vec3& worldPos, Vec2& screenPos)
{
	GetWindowInfo();
	float matrix[4][4];
	DWORD Engine = mem.ReadMemory<DWORD>(offsets.engineBase + 0x601FDC);
	ReadProcessMemory(offsets.hProcess, (LPCVOID)(Engine + offsets.dwViewMatrix), matrix, 64, NULL);

	
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

