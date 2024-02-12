#include "Memory.h"

Memory mem;

MODULEENTRY32 Memory::GetModule(DWORD pID, const wchar_t* moduleName)
{
	hSS = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pID);
	mEntry.dwSize = sizeof(MODULEENTRY32);
	if (hSS != INVALID_HANDLE_VALUE) {
		if (Module32First(hSS, &mEntry)) {
			do {
				if (!wcscmp((const wchar_t*)mEntry.szModule, moduleName)) {
					break;
				}
			} while (Module32Next(hSS, &mEntry));

		}
		CloseHandle(hSS);
	}

	return mEntry;
}

DWORD Memory::GetProcessID(const wchar_t* windowName)
{
	DWORD pID;
	do {
		offsets.hWnd = FindWindow(NULL, windowName);
		Sleep(50);
	} while (!offsets.hWnd);
	GetWindowThreadProcessId(offsets.hWnd, &pID);

	cout << "[*] Game ProcessID found: " << pID << endl;
	return pID;
}



void Memory::Setup()
{
	offsets.processID = GetProcessID(L"Left 4 Dead 2 - Direct3D 9");
	offsets.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, offsets.processID);// 管理员权限启动 x86改成x64
	offsets.hWnd = FindWindow(NULL, L"Left 4 Dead 2 - Direct3D 9");

	if (offsets.hProcess) {
		cout << "[*] hProcess: " << offsets.hProcess << endl;
	}
	else {
		cout << "[!] hProcess error " << offsets.hProcess << endl;
	}
	cout << "" << endl;
}


void Memory::GetMoudles()
{
	do {
		offsets.clientBase = (DWORD)GetModule(offsets.processID, L"client.dll").modBaseAddr;
		offsets.engineBase = (DWORD)GetModule(offsets.processID, L"engine.dll").modBaseAddr;
		Sleep(50);
	} while (!offsets.clientBase && !offsets.engineBase);

}

