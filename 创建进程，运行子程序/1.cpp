// g++ 编译
// 编码 gb2312
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void create_jsq()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    // 创建进程 运行计算器
    if(!CreateProcess(TEXT("C:\\WINDOWS\\system32\\calc.exe"),
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)
    )
    {
        cout << "创建计算器进程失败" << GetLastError() << endl;
        return;
    }
    else
    {
        cout << "创建计算器子进程成功。" << endl << "子进程PID：" << pi.dwProcessId << endl;
    }
    return;
}

void create_notepad()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));
    
    // 打开记事本
    char *filename = (char*)malloc(40);
    strcpy(filename, " 1.txt");
    if(!CreateProcess(TEXT("C:\\WINDOWS\\system32\\notepad.exe"),
        filename,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)
    )
    {
        cout << "创建记事本进程失败" << GetLastError() << endl;
        return;
    }
    else
    {
        cout << "创建记事本子进程成功。" << endl << "子进程PID：" << pi.dwProcessId << endl;
    }
    free(filename);
}

int main()
{
    create_jsq();
    create_notepad();
    
    cout << "父进程PID：" << GetCurrentProcessId() << endl;

    system("pause");

    return 0;
}