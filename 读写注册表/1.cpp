// VS Code(编码gb2312),win7,mingw
// g++编译
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <TChar.h>

using namespace std;

// 从注册表读取CPU信息
void read_reg_cpu()
{
    long lRet;
    HKEY hKey;
    TCHAR tchData[64];
    DWORD dwSize;

    lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        _T("Hardware\\Description\\System\\CentralProcessor\\0"),
        0,
        KEY_QUERY_VALUE,
        &hKey);
    dwSize = sizeof(tchData);
    if(lRet == ERROR_SUCCESS)
    {
        lRet = RegQueryValueEx(hKey,
            _T("ProcessorNameString"),
            NULL,
            NULL,
            (LPBYTE)tchData,
            &dwSize);
        if(lRet == ERROR_SUCCESS)
        {
            cout << "CPU:" << tchData << endl;
        }
        else
        {
            cout << "RegQueryValueEx failed" << endl;
        }
        
    }
    else
    {
        cout << "RegOpenKeyEx failed" << endl;
    }
    RegCloseKey(hKey); 
}

// 写入注册表，有32和64位的问题 需要注意
void write_reg()
{
    HKEY hKey;
    //RegCreateKey(HKEY_LOCAL_MACHINE, _T("Software\\Wow6432Node\\MyAppTest"), &hKey);
    //RegSetValue(hKey, NULL, REG_SZ, _T("ikaros"), 6);
    DWORD dwAge = 23;
    DWORD dwDisposition = 123;
    long lRet;
    // 创建
    lRet = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Wow6432Node\\MyAppTest"),
        0, 
        NULL, 
        0,
        KEY_WRITE, 
        NULL,
        &hKey, 
        &dwDisposition);
    if(lRet == ERROR_SUCCESS)
    {

    }
    else
    {
        cout << "RegCreateKeyEx failed" << endl;
    }
    // 加字段
    RegSetValueEx(hKey, _T("age"), 0, REG_DWORD, (CONST BYTE*)&dwAge, 4);
    RegCloseKey(hKey); 
}

// 读取注册表 默认数据
void read_reg1(const char *str)
{
    LONG lValue;
    long lRet;
    //RegQueryValue(HKEY_LOCAL_MACHINE, _T(str), NULL, &lValue);
    TCHAR *pBuf = new TCHAR[lValue];
    lRet = RegQueryValue(HKEY_LOCAL_MACHINE, _T(str), pBuf, &lValue);
    if(lRet == ERROR_SUCCESS)
    {
        cout << str << ":" << pBuf << endl;
    }
    else
    {
        cout << "RegQueryValue failed" << endl;
    }
}

// 读取注册表 指定名称数据
void read_reg2(const char *path, const char *name)
{
    HKEY hKey;
    RegOpenKey(HKEY_LOCAL_MACHINE, _T(path), &hKey);
    DWORD dwType;
    DWORD dwValue;
    DWORD dwAge;
    RegQueryValueEx(hKey, _T(name), 0, &dwType, (LPBYTE)&dwAge, &dwValue);
    cout << "age=" << dwAge << endl;
    RegCloseKey(hKey); 
}

int main()
{
    read_reg_cpu();
    write_reg();
    read_reg1("SOFTWARE\\Wow6432Node\\MyAppTest");
    read_reg2("SOFTWARE\\Wow6432Node\\MyAppTest", "age");
    return 0;
}
