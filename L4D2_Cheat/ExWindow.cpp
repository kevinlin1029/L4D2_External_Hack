#include "ExWindow.h"

void Loop()
{
	DWORD localPlayer = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwLocalPlayer); //����Լ�
	DWORD localTeam = mem.ReadMemory<DWORD>(localPlayer + offsets.m_iTeamNum);//����Լ�����Ӫ��־λ

	HDC hDC = GetDC(draw.hExWnd);
	HBRUSH hBrush = CreateSolidBrush(RGB(128, 0, 0)); //GDI���� ԭ��

	HDC dcMem = CreateCompatibleDC(hDC);//�����ڴ�DC ˫��������ͼ
	HBITMAP bmpMem = CreateCompatibleBitmap(hDC, draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top);
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(128, 0, 0));// �������� ����׼������

	SelectObject(dcMem, bmpMem); //��λͼѡ���ڴ�DC
	SelectObject(dcMem, hPen); //�����ʺͻ�������

	if (localPlayer)
	{
		for (int i = 0; i < 500; i++) //�����ѭ��ֵ��Ҫ���ݲ�ͬ��Ϸ���䶯
		{
			DWORD entity = mem.ReadMemory<DWORD>(offsets.clientBase + offsets.dwEntityList + i * 0x10);
			
			//������Լ�������
			if (localPlayer == entity) { continue; }
			if (entity == 0) { continue; }

			Vec3 entityPos3, enetityHeadPos3, LocalPos3; //������������
			Vec2 entityPos2, enetityHeadPos2; //��Ļ����

			//������������
			entityPos3.x = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x0);
			entityPos3.y = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x4);
			entityPos3.z = mem.ReadMemory<float>(entity + offsets.m_fPos + 0x8);
			DWORD teamID = mem.ReadMemory<BYTE>(entity + offsets.m_iTeamNum);

			LocalPos3.x = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x0);
			LocalPos3.y = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x4);
			LocalPos3.z = mem.ReadMemory<float>(localPlayer + offsets.m_fPos + 0x8);

			//��ʼ��ȡentityID
			Entity ModelID;
			DWORD ModelID_address = mem.ReadMemory<DWORD>(entity + offsets.m_modelIdAddress);
			ModelID = mem.ReadMemory<Entity>(ModelID_address + offsets.m_modelId);
			ModelID.ID[sizeof(ModelID.ID)- 1] = '\0';

			//�ж�Ŀǰ���ĸ�����->��ȡ�������Ϣ
			const BoneMatrix* Bone = GetBoneMapping(ModelID);
			if (Bone == nullptr) { continue; }

			//std::cout << ModelID.ID << std::endl;
			

			if (teamID != 2 && teamID != 3) {
				continue; 
			}
			if (teamID != localTeam) {
				DWORD entityHealth = mem.ReadMemory<DWORD>(entity + offsets.m_iHeath);
				if (0  < entityHealth && draw.WorldToScreen(entityPos3, entityPos2)) {
					
					
					mem.ReadBone(entity, Bone->Head, enetityHeadPos3);
					if (draw.WorldToScreen(enetityHeadPos3, enetityHeadPos2)) {
						//���㷽��ĸ߶ȺͿ��
						float height = entityPos2.y - enetityHeadPos2.y;
						float width = height / 2;

						//��ֹ��Ϊ�������������²���ʱ���µ�����ͷ��������ŵ׵������
						if (height <= 0 || width <= 0) { continue; }

						RECT rect;
						rect.left = entityPos2.x - (width / 2);
						rect.top = enetityHeadPos2.y;
						rect.right = entityPos2.x + (width / 2);
						rect.bottom = entityPos2.y;


						//�����ķ���
						//FrameRect(dcMem, &rect, hBrush);
						//��׼������
						draw.DrawRect(dcMem, rect);

						//����Ѫ��
						//if (config.health) {
							draw.DrawHP(dcMem, hBrush, rect, entityHealth);
						//}
#if 0
						Vec3 tmpBone3;
						Vec2 tmpBone2;
						for (int i = 0; i < 100; i++)
						{
							mem.ReadBone(entity, i, tmpBone3);
							wchar_t buffer[MAXBYTE];
							wsprintf(buffer, L"%d", i);
							if (draw.WorldToScreen(tmpBone3, tmpBone2))
							{
								TextOut(dcMem, tmpBone2.x, tmpBone2.y, buffer, 2);
	
							}
						}
#endif // 0				


					}


				}
			}
		}
		BitBlt(hDC, 0, 0, draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top, dcMem, 0, 0, SRCCOPY);//ԭɫ����
	}
	DeleteObject(hBrush);
	DeleteDC(dcMem);
	DeleteObject(bmpMem);
	ReleaseDC(draw.hExWnd, hDC);
	DeleteObject(hPen);

}


	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg)
		{
			//������Ϣ
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
		MSG msg; //windows��Ϣ
		ZeroMemory(&msg, sizeof(msg));
		GetWindowRect(offsets.hWnd, &draw.rectGame);
		//��ƴ�����
		WNDCLASSEX wc;
		ZeroMemory(&wc, sizeof(wc)); //��ʼ��������
		wc.cbSize = sizeof(wc); //���ô�����Ĵ�С��һ�㶼����sizeof����ȡ��С��
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = (WNDPROC)WindowProc;
		wc.hInstance = GetModuleHandle(NULL);//����ʵ��������������κ���
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���������ʽ 
		wc.hbrBackground = (HBRUSH)RGB(0, 0, 0); //���ڱ�����ɫ
		wc.lpszClassName = L"ExternalWindow"; //����������

		RegisterClassEx(&wc); //ע�ᴰ����
		draw.hExWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, wc.lpszClassName, L"ExWindow", WS_POPUP, draw.rectGame.left, draw.rectGame.top,
			draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top, NULL, NULL, wc.hInstance, NULL);
		if (draw.hExWnd == NULL) { return; }
		SetLayeredWindowAttributes(draw.hExWnd, RGB(0, 0, 0), 0, LWA_COLORKEY); //ʹ������ȫ͸��
		ShowWindow(draw.hExWnd, SW_SHOW); //��ʾ����
		UpdateWindow(draw.hExWnd);

		while (msg.message != WM_QUIT) {
			//ȷ������ʼ������ǰ��
			SetWindowPos(draw.hExWnd, HWND_TOPMOST, draw.rectGame.left, draw.rectGame.top,
				draw.rectGame.right - draw.rectGame.left, draw.rectGame.bottom - draw.rectGame.top, SWP_SHOWWINDOW);
			GetWindowRect(offsets.hWnd, &draw.rectGame);
			if (PeekMessage(&msg, draw.hExWnd, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);//���ݼ�����Ϣ
				DispatchMessage(&msg); //�ɷ���Ϣ ����Ϣ���ݸ���Ϣ������
			}

		}
	}
