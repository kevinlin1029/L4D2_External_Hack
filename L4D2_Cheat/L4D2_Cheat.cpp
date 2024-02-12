#include <iostream>
#include <Windows.h>
#include "Memory.h"
#include "ExWindow.h"
using namespace std;

void Init()
{
	mem.Setup();
	mem.GetMoudles();
}

int main()
{
	//set up console title
		SetConsoleTitle(L"Yin");
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		//set up size
		MoveWindow(console, r.left, r.right, 500, 700, TRUE);
		cout << "\n					YYCOCO" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "\n [*] waiting for L4D2...." << endl;

		Init();
		CreateExternalWindow();
		

}