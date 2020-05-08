// g++ 编译
// 编码 gb2312
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
            cout << "环境变量" << szName << "不存在" << endl;
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

// 显示所有环境变量
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
        cout << "添加新的环境变量" << endl;
        getchar();
        // 添加(此进程的环境变量)
        if(!SetEnvironmentVariable(TEXT("b"), TEXT("big")))
        {
            cout << "添加环境变量失败 error:" << GetLastError() << endl;
            return 1;
        }
        EnumEnvironmentVariables();
        cout << "添加环境变量成功" << endl;
        getchar();

        cout << "修改环境变量" << endl;
        getchar();
        // 修改
        if(!SetEnvironmentVariable(TEXT("b"), TEXT("pig")))
        {
            cout << "修改环境变量失败 error:" << GetLastError() << endl;
            return 2;
        }
        EnumEnvironmentVariables();
        cout << "修改环境变量成功" << endl;
        getchar();

        cout << "删除环境变量" << endl;
        getchar();
        // 删除
        if(!SetEnvironmentVariable(TEXT("b"), NULL))
        {
            cout << "添加环境变量失败 error:" << GetLastError() << endl;
            return 3;
        }
        EnumEnvironmentVariables();
        cout << "删除环境变量成功" << endl;
    }
    else if(0 == lstrcmp("get", argv[1]) && argc==2)
    {
        if(0 == GetEnvironmentVariable(TEXT("username"), szEv, BUF_SIZE))
        {
            //cout << "获取环境变量失败 error:" << GetLastError() << endl;
            DWORD dwErr = GetLastError();
            if(ERROR_ENVVAR_NOT_FOUND == dwErr)
            {
                cout << "环境变量 username 不存在" << endl;
                return 4;
            }
        }
        cout << szEv << endl;
    }
    else if(0 == lstrcmp("append", argv[1]) && argc==2)
    {
        cout << "追加之前:" << endl;
        EnumEnvironmentVariables();
        if(!AppendEnvironmentVariable((LPTSTR)TEXT("PATH"), (LPTSTR)TEXT("d:\\demo")))
        {
            cout << "追加环境变量失败" << endl;
            return 5;
        }
        cout << "追加之后:" << endl;
        EnumEnvironmentVariables();
        cout << szEv << endl;
    }
    else
    {
        cout << "命令错误" << endl;
    }
    


    system("pause");

    return 0;
}