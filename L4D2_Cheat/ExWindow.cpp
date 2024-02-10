#pragma once
#include <Windows.h>
#include "ExWindow.h"

void Loop()
{
	DWORD64 localPlayer = mem.ReadMemory<DWORD64>(offsets.clientBase + offsets.dwLocalPlayer); //玩家自己
	DWORD localTeam = mem.ReadMemory<DWORD64>(localPlayer + offsets.m_iTeamNum);//玩家自己的阵营标志位

	HDC hDC = GetDC(draw.hExWnd);


	HBRUSH hbrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
	FillRect(hDC, &draw.rectEx, hbrush);
	DeleteObject(hbrush);

	if (localPlayer)
	{
		for (int i = 0; i < 32; i++) //这里的循环值需要根据不同游戏而变动
		{
			DWORD64 entity = mem.ReadMemory<DWORD32>(offsets.clientBase + offsets.dwEntityList + i * 0x10);
			
			//如果是自己则跳过
			if (localPlayer == entity) { continue; }
			if (entity == 0) { continue; }

			Vec3 entityPos3, enetityHeadPos3, LocalPos3; //人物世界坐标
			Vec2 entityPos2, enetityHeadPos2; //屏幕坐标

			//敌人世界坐标
			entityPos3.x = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x0);
			entityPos3.y = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x4);
			entityPos3.z = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x8);
			DWORD teamID = mem.ReadMemory<BYTE>(entity + offsets.m_iTeamNum);

		//	LocalPos3.x = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x0);
		//	LocalPos3.y = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x4);
		//	LocalPos3.z = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x8);

			if (teamID != 2 && teamID != 3) {
				continue; 
			}
			if (teamID != localTeam || teamID == localTeam) {
				DWORD entityHealth = mem.ReadMemory<DWORD>(entity + offsets.m_iHeath);
				if (0  < entityHealth && draw.WorldToScreen(entityPos3, entityPos2)) {
					Vec3 tmpBone3;
					Vec2 tmpBone2;
					for (int i = 0; i < 100; i++)
					{
						mem.ReadBone(entity, i, tmpBone3);
						wchar_t buffer[MAXBYTE];
						wsprintf(buffer, L"%d", i);
						if (draw.WorldToScreen(tmpBone3, tmpBone2))
						{
							TextOut(hDC, tmpBone2.x, tmpBone2.y, buffer, 2);
						}
					}
				}
			}
		}
	}
	ReleaseDC(draw.hExWnd, hDC);



}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
		//绘制消息
	case WM_PAINT:
		Loop();
		break;
	case WM_CREATE:
		break;
	case WM_DESTROY:
		DestroyWindow(hwnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

void CreateExternalWindow()
{
	MSG msg; //windows消息
	ZeroMemory(&msg, sizeof(msg));
	GetWindowRect(offsets.hWnd, &draw.rectGame);
	//设计窗口类
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc)); //初始化窗口类
	wc.cbSize = sizeof(wc); //设置窗口类的大小，一般都是用sizeof来获取大小的
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WindowProc;

	wc.hInstance = GetModuleHandle(NULL);//窗口实例句柄，不依赖任何项
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//窗口鼠标样式 
	wc.hbrBackground = (HBRUSH)RGB(0, 0, 0); //窗口背景颜色
	wc.lpszClassName = L"ExternalWindow"; //窗口类名称

	RegisterClassEx(&wc); //注册窗口类
	draw.hExWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, wc.lpszClassName, L"ExWindow", WS_POPUP, draw.rectGame.left, draw.rectGame.top,
		draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top, NULL, NULL, wc.hInstance, NULL);
	if (draw.hExWnd == NULL) { return; }
	SetLayeredWindowAttributes(draw.hExWnd, RGB(0, 0, 0), 0, LWA_COLORKEY); //使窗口完全透明
	ShowWindow(draw.hExWnd, SW_SHOW); //显示窗口
	UpdateWindow(draw.hExWnd);

	while (msg.message != WM_QUIT) {
		//确保窗口始终在最前面
		SetWindowPos(draw.hExWnd, HWND_TOPMOST, draw.rectGame.left, draw.rectGame.top,
			draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top, SWP_SHOWWINDOW);
		GetWindowRect(offsets.hWnd, &draw.rectGame);
		if (PeekMessage(&msg, draw.hExWnd, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);//传递键盘消息
			DispatchMessage(&msg); //派发消息 将消息传递给消息处理函数
		}

	}
}
