#pragma once
#include <Windows.h>
using namespace std;

class Offsets
{
public:
	//各种偏移量
	DWORD dwEntityList = 0x7384F4;  //人物数组
	DWORD dwLocalPlayer = 0x724B58; //玩家自身结构体
	DWORD dwViewMatrix = 0x2E4; //游戏矩阵

	DWORD m_iTeamNum = 0xE4; //人物阵营
	DWORD m_iHeath = 0xEC; //血量
	DWORD m_fPos = 0x124; //坐标

	DWORD m_modelIdAddress = 0x60;
	DWORD m_modelId = 0x14;


	//进程相关信息
	HWND hWnd = 0;
	HANDLE hProcess = 0;
	DWORD processID = 0;

	DWORD clientBase;
	DWORD engineBase;
};
extern Offsets offsets;