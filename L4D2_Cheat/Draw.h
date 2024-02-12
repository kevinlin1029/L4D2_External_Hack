#pragma once
#include <Windows.h>
#include "Structure.h"
#include "Offsets.h"
#include "Memory.h"
using namespace std;

class Draw
{
public:
	HWND hExWnd;//�ɰ洰�ھ��
	RECT rectGame;//��Ϸ���ڴ�С��Ϣ


	RECT rect; //�ڴ��ڷֱ���
	int width; //�ڴ��ڿ�
	int height; //�ڴ��ڸ�

	RECT rectEx; //�ⴰ�ڷֱ���
	int widthEx; //�ⴰ�ڿ�
	int heightEx; //�ⴰ�ڸ�

	void DrawRect(HDC hDC, RECT rect);//������׼������
	void DrawHP(HDC hDC, HBRUSH hBrush, RECT  rect, float hp);

	BOOL WorldToScreen(Vec3& worldPos, Vec2& screenPos);
	void GetWindowInfo();
};
extern Draw draw;
