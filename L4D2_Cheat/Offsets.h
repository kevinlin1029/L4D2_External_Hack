#pragma once
#include <Windows.h>
using namespace std;

class Offsets
{
public:
	//����ƫ����
	DWORD64 dwEntityList = 0x7384F4;  //��������
	DWORD64 dwLocalPlayer = 0x724B58; //�������ṹ��
	DWORD64 dwViewMatrix = 0x2E4; //��Ϸ����

	DWORD m_iTeamNum = 0xE4; //������Ӫ
	DWORD m_iHeath = 0xEC; //Ѫ��
	DWORD m_fPos = 0x124; //����



	//���������Ϣ
	HWND hWnd = 0;
	HANDLE hProcess = 0;
	DWORD processID = 0;

	DWORD64 clientBase;
	DWORD64 engineBase;
};
extern Offsets offsets;