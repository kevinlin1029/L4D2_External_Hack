#pragma once
#include <Windows.h>
using namespace std;

class Offsets
{
public:
	//����ƫ����
	DWORD dwEntityList = 0x7384F4;  //��������
	DWORD dwLocalPlayer = 0x724B58; //�������ṹ��
	DWORD dwViewMatrix = 0x2E4; //��Ϸ����

	DWORD m_iTeamNum = 0xE4; //������Ӫ
	DWORD m_iHeath = 0xEC; //Ѫ��
	DWORD m_fPos = 0x124; //����

	DWORD m_modelIdAddress = 0x60;
	DWORD m_modelId = 0x14;


	//���������Ϣ
	HWND hWnd = 0;
	HANDLE hProcess = 0;
	DWORD processID = 0;

	DWORD clientBase;
	DWORD engineBase;
};
extern Offsets offsets;