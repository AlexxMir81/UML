#include<Windows.h>

CONST CHAR g_szClassName[] = "MyWindowClass"; //имя класса окна
CONST CHAR g_szWindowTitle[] = "My first Window"; //заголовок окна

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//1) Регистрация класса окна:
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
	wc.lpfnWndProc = (WNDPROC)WndProc; //имя фукции - это указатель на функцию, оно содержить адрес,
	//по которому функция загружена в память
	wc.lpszClassName = g_szClassName;
	wc.lpszMenuName = NULL;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed! :(", "Error", MB_OK | MB_ICONERROR);
	}
	//2) Создание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL, //exStyle дополнительные стили
		g_szClassName,
		g_szWindowTitle,
		WS_OVERLAPPEDWINDOW, //Главное окно, у которого есть строка заголовка, 
		//кнопки управления окном, может изменяться по размерам
	)
	//3) Запуск цикла сообщений:

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