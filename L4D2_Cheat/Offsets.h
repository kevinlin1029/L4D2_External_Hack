#pragma once
#include <Windows.h>
using namespace std;

class Offsets
{
public:
	//各种偏移量
	DWORD64 dwEntityList = 0x7384F4;  //人物数组
	DWORD64 dwLocalPlayer = 0x724B58; //玩家自身结构体
	DWORD64 dwViewMatrix = 0x2E4; //游戏矩阵

	DWORD m_iTeamNum = 0xE4; //人物阵营
	DWORD m_iHeath = 0xEC; //血量
	DWORD m_fPos = 0x124; //坐标



	//进程相关信息
	HWND hWnd = 0;
	HANDLE hProcess = 0;
	DWORD processID = 0;

	DWORD64 clientBase;
	DWORD64 engineBase;
};
extern Offsets offsets;