// g++ ����
// ���� gb2312
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

    // �������� ���м�����
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
        cout << "��������������ʧ��" << GetLastError() << endl;
        return;
    }
    else
    {
        cout << "�����������ӽ��̳ɹ���" << endl << "�ӽ���PID��" << pi.dwProcessId << endl;
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
    
    // �򿪼��±�
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
        cout << "�������±�����ʧ��" << GetLastError() << endl;
        return;
    }
    else
    {
        cout << "�������±��ӽ��̳ɹ���" << endl << "�ӽ���PID��" << pi.dwProcessId << endl;
    }
    free(filename);
}

int main()
{
    create_jsq();
    create_notepad();
    
    cout << "������PID��" << GetCurrentProcessId() << endl;

    system("pause");

    return 0;
}