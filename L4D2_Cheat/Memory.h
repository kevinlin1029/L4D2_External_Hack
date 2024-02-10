#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include "Offsets.h"
#include "Structure.h"
using namespace std;

class Memory
{
public:
	HWND hWnd;
	HANDLE hSS;
	MODULEENTRY32 mEntry;
	void Setup();

	DWORD GetProcessID(const wchar_t* windowName); //32
	MODULEENTRY32 GetModule(DWORD pID, const wchar_t* moduleName);
	void GetMoudles();
	//分装自己的内存读写函数 跨进程读写
	template <typename T>
	T ReadMemory(DWORD address) {
		T buffer;
		ReadProcessMemory(offsets.hProcess, (LPCVOID)address, &buffer, sizeof(buffer), NULL);
		return buffer;
	}

	template <typename T>
	void WriteMemory(DWORD address, T val) {
		WriteProcessMemory(offsets.hProcess, (LPVOID)address, &val, sizeof(val), NULL);
	}


	void ReadBone(DWORD dwEntity, int nBoneIndex, Vec3& bonePos3) //读取骨骼矩阵用来测试绘制部位
	{
		DWORD tmp1, dwBoneMatrix;
		tmp1 = 0x6C0;
		dwBoneMatrix = ReadMemory<DWORD>(dwEntity + tmp1);
		

		bonePos3.x = ReadMemory<float>(dwBoneMatrix + nBoneIndex * 0x30 + 0xC);
		bonePos3.y = ReadMemory<float>(dwBoneMatrix + nBoneIndex * 0x30 + 0x1C);
		bonePos3.z = ReadMemory<float>(dwBoneMatrix + nBoneIndex * 0x30 + 0x2C);
	}

};
extern Memory mem;

