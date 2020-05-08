// 编译 gcc 1.c -mwindows
// 开发环境 VS Code(编码 gb2312)，MinGW，Win7
#include <Windows.h>

// “句柄型”数据类型
HINSTANCE hinst;
// 窗口的句柄
HWND hwnd;

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 定义窗口类
    WNDCLASSEX wcx;
    hinst = hinstance;
    MSG msg;
    BOOL fGotMessage;

    wcx.cbSize = sizeof(wcx);
    wcx.style = CS_HREDRAW | CS_VREDRAW;
    wcx.lpfnWndProc = MainWndProc;
    wcx.cbClsExtra = 0;
    wcx.cbWndExtra = 0;
    wcx.hInstance = hinstance;
    wcx.lpszClassName = "MainWClass";
    wcx. hIcon = LoadIcon(NULL, IDI_APPLICATION) ;
    wcx.hCursor = LoadCursor(NULL, IDC_ARROW) ;
    // 检索预定义的备用笔、刷子、字体或者调色板的句柄
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH) ;
    wcx.lpszMenuName = NULL;
    wcx.lpszClassName = "MainWClass";
    // 装载图标，光标，或位图
    wcx.hIconSm = (HICON)LoadImage(hinstance,
        MAKEINTRESOURCE(5), IMAGE_ICON,
        // 获取系统分辨率
        GetSystemMetrics(SM_CXSMICON),
        GetSystemMetrics(SM_CYSMICON),
        LR_DEFAULTCOLOR);

    // 注册一个窗口类
    if(!RegisterClassEx(&wcx))
    {
        return 1;
    }

    // 使用窗口类创建窗口
    hwnd = CreateWindow("MainWClass",
        "Hello",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        (HWND)NULL,
        (HMENU)NULL,
        hinstance, 
        (LPVOID)NULL);

    if(!hwnd)
    {
        return 1;
    }
    // 设置指定窗口的显示
    ShowWindow(hwnd, nCmdShow);
    // 更新指定窗口的客户区
    UpdateWindow(hwnd);

    // 从调用线程的消息队列里取得一个消息并将其放于指定的结构
    while((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0)
    {
        // 将虚拟键消息转换为字符消息
        TranslateMessage(&msg);
        // 分发一个消息给窗口程序
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// 窗口过程函数，处理消息
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, "你喜欢我吗", "提问", MB_OK);
            return 0;
        case WM_DESTROY:
            // 通知系统当前有一个线程发送了进程中止退出请求
            PostQuitMessage(0);
            return 0;
        default:
            // 为应用程序没有处理的任何窗口消息提供缺省的处理
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}