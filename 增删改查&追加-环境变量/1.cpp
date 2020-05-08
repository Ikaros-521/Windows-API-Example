// g++ ����
// ���� gb2312
#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

#define BUF_SIZE 10240

DWORD AppendEnvironmentVariable(LPTSTR szName, LPTSTR szNewValue)
{
    DWORD dwNewValSize;
    PVOID szVal;
    DWORD dwReturn;
    DWORD dwErr;

    dwNewValSize = lstrlen(szNewValue)+1;

    szVal = HeapAlloc(GetProcessHeap(), 0, BUF_SIZE);
    dwReturn = GetEnvironmentVariable(szName, (LPTSTR)szVal, BUF_SIZE);
    if(dwReturn == 0)
    {
        dwErr = GetLastError();
        if(ERROR_ENVVAR_NOT_FOUND == dwErr)
        {
            cout << "��������" << szName << "������" << endl;
        }
        else
        {
            cout << "append error:" << dwErr << endl;
        }
        HeapFree(GetProcessHeap(), 0, szVal);
        return FALSE;
    }
    else if(dwReturn > BUF_SIZE)
    {
        szVal = HeapReAlloc(GetProcessHeap(), 0, szVal, dwReturn+dwNewValSize);
        if(NULL == szVal)
        {
            cout << "Memory error" << endl;
            return FALSE;
        }
        dwReturn = GetEnvironmentVariable(szName, (LPTSTR)szVal, dwReturn);
        if(!dwReturn)
        {
            cout << "GetEnvironmentVariable failed:" << GetLastError() << endl;
            HeapFree(GetProcessHeap(), 0, szVal);
            return FALSE;
        }
    }
    lstrcat((LPTSTR)szVal, szNewValue);
    lstrcat((LPTSTR)szVal, TEXT(";"));
    if(!SetEnvironmentVariable(szName, (LPTSTR)szVal))
    {
        cout << "Set Value Error:" << GetLastError() << endl;
        return FALSE;
    }
    HeapFree(GetProcessHeap(), 0, szVal);
    return TRUE;
}

// ��ʾ���л�������
DWORD WINAPI EnumEnvironmentVariables()
{
    PVOID pEv = GetEnvironmentStrings();
    LPTSTR szEnvs;
    
    for(szEnvs = (LPTSTR)pEv; *szEnvs;)
    {
        cout << szEnvs << endl;
        while(*szEnvs++);
    }
    FreeEnvironmentStrings((LPCH)pEv);
    return 0;
}

int main(int argc, PTCHAR argv[])
{
    TCHAR szEv[BUF_SIZE];

    if(0==lstrcmp("showall", argv[1]) && argc ==2)
    {
        EnumEnvironmentVariables();
    }
    else if(0 == lstrcmp("nsd", argv[1]) && argc==2)
    {
        cout << "����µĻ�������" << endl;
        getchar();
        // ���(�˽��̵Ļ�������)
        if(!SetEnvironmentVariable(TEXT("b"), TEXT("big")))
        {
            cout << "��ӻ�������ʧ�� error:" << GetLastError() << endl;
            return 1;
        }
        EnumEnvironmentVariables();
        cout << "��ӻ��������ɹ�" << endl;
        getchar();

        cout << "�޸Ļ�������" << endl;
        getchar();
        // �޸�
        if(!SetEnvironmentVariable(TEXT("b"), TEXT("pig")))
        {
            cout << "�޸Ļ�������ʧ�� error:" << GetLastError() << endl;
            return 2;
        }
        EnumEnvironmentVariables();
        cout << "�޸Ļ��������ɹ�" << endl;
        getchar();

        cout << "ɾ����������" << endl;
        getchar();
        // ɾ��
        if(!SetEnvironmentVariable(TEXT("b"), NULL))
        {
            cout << "��ӻ�������ʧ�� error:" << GetLastError() << endl;
            return 3;
        }
        EnumEnvironmentVariables();
        cout << "ɾ�����������ɹ�" << endl;
    }
    else if(0 == lstrcmp("get", argv[1]) && argc==2)
    {
        if(0 == GetEnvironmentVariable(TEXT("username"), szEv, BUF_SIZE))
        {
            //cout << "��ȡ��������ʧ�� error:" << GetLastError() << endl;
            DWORD dwErr = GetLastError();
            if(ERROR_ENVVAR_NOT_FOUND == dwErr)
            {
                cout << "�������� username ������" << endl;
                return 4;
            }
        }
        cout << szEv << endl;
    }
    else if(0 == lstrcmp("append", argv[1]) && argc==2)
    {
        cout << "׷��֮ǰ:" << endl;
        EnumEnvironmentVariables();
        if(!AppendEnvironmentVariable((LPTSTR)TEXT("PATH"), (LPTSTR)TEXT("d:\\demo")))
        {
            cout << "׷�ӻ�������ʧ��" << endl;
            return 5;
        }
        cout << "׷��֮��:" << endl;
        EnumEnvironmentVariables();
        cout << szEv << endl;
    }
    else
    {
        cout << "�������" << endl;
    }
    


    system("pause");

    return 0;
}