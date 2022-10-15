#include<Windows.h>  

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    TCHAR appname[] = TEXT("Windows Programming");
    WNDCLASS wndclass;
    MSG msg;
    HWND hwnd;

    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hInstance = hInstance;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = appname;
    wndclass.lpszMenuName = NULL;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;

    // check this window class is registered or not  
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("Window class is not registered"), TEXT("Error...."), MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(appname,  //window name  
        appname,   // window text  
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, // window style  
        CW_USEDEFAULT,   //default window position x  
        CW_USEDEFAULT,   //default window position y  
        600,   //width  
        500,    // height  
        NULL,
        NULL,
        hInstance,
        NULL
    );

    // show & update created window  
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    // get message from queue  
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message)
    {

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        SetTextColor(hdc, RGB(0, 0, 240));
        RECT rect;
        GetClientRect(hwnd, &rect);

        DrawText(hdc, TEXT("Yeah!"), -1, &rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(EXIT_SUCCESS);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}