// ���� gcc 1.c -mwindows
// �������� VS Code(���� gb2312)��MinGW��Win7
#include <Windows.h>

// ������͡���������
HINSTANCE hinst;
// ���ڵľ��
HWND hwnd;

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ���崰����
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
    // ����Ԥ����ı��ñʡ�ˢ�ӡ�������ߵ�ɫ��ľ��
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH) ;
    wcx.lpszMenuName = NULL;
    wcx.lpszClassName = "MainWClass";
    // װ��ͼ�꣬��꣬��λͼ
    wcx.hIconSm = (HICON)LoadImage(hinstance,
        MAKEINTRESOURCE(5), IMAGE_ICON,
        // ��ȡϵͳ�ֱ���
        GetSystemMetrics(SM_CXSMICON),
        GetSystemMetrics(SM_CYSMICON),
        LR_DEFAULTCOLOR);

    // ע��һ��������
    if(!RegisterClassEx(&wcx))
    {
        return 1;
    }

    // ʹ�ô����ഴ������
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
    // ����ָ�����ڵ���ʾ
    ShowWindow(hwnd, nCmdShow);
    // ����ָ�����ڵĿͻ���
    UpdateWindow(hwnd);

    // �ӵ����̵߳���Ϣ������ȡ��һ����Ϣ���������ָ���Ľṹ
    while((fGotMessage = GetMessage(&msg, (HWND)NULL, 0, 0)) != 0)
    {
        // ���������Ϣת��Ϊ�ַ���Ϣ
        TranslateMessage(&msg);
        // �ַ�һ����Ϣ�����ڳ���
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// ���ڹ��̺�����������Ϣ
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_LBUTTONDOWN:
            MessageBox(hwnd, "��ϲ������", "����", MB_OK);
            return 0;
        case WM_DESTROY:
            // ֪ͨϵͳ��ǰ��һ���̷߳����˽�����ֹ�˳�����
            PostQuitMessage(0);
            return 0;
        default:
            // ΪӦ�ó���û�д�����κδ�����Ϣ�ṩȱʡ�Ĵ���
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}