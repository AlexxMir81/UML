#include<Windows.h>

CONST CHAR g_szClassName[] = "MyWindowClass"; //��� ������ ����
CONST CHAR g_szWindowTitle[] = "My first Window"; //��������� ����

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//1) ����������� ������ ����:
	WNDCLASSEX wc; //wc- Windows Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = (WNDPROC)WndProc; //��� ������ - ��� ��������� �� �������, ��� ��������� �����,
	//�� �������� ������� ��������� � ������
	wc.lpszClassName = g_szClassName;
	wc.lpszMenuName = NULL;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed! :(", "Error", MB_OK | MB_ICONERROR);
	}
	//2) �������� ����:
	HWND hwnd = CreateWindowEx
	(
		NULL, //exStyle �������������� �����
		g_szClassName,
		g_szWindowTitle,
		WS_OVERLAPPEDWINDOW, //������� ����, � �������� ���� ������ ���������, 
		//������ ���������� �����, ����� ���������� �� ��������
	)
	//3) ������ ����� ���������:

	return 0;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: break;
	case WM_COMMAND: break;
	case WM_CLOSE: DestroyWindow(hwnd); break;
	case WM_DESTROY: PostQuitMessage(NULL);break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}