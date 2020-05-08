// VS Code, MinGW, win7
// 编译 gcc 文件名.c
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main()
{
    // 打印所有逻辑驱动器路径
    CHAR szLogicalDriveStrings[BUFSIZE];
    PCHAR szDrive;
    // 用0填充一个内存块
    ZeroMemory(szLogicalDriveStrings, BUFSIZE);

    // 获取一个字串，其中包含了当前所有逻辑驱动器的根驱动器路径
    GetLogicalDriveStrings(BUFSIZE-1, szLogicalDriveStrings);
    //printf("%s\n", szLogicalDriveStrings);
    szDrive = (PCHAR)szLogicalDriveStrings;
    do
    {
        printf("%s\n", szDrive);
        szDrive += (lstrlen(szDrive)+1);
    } while('\0' != szDrive[0]);
    // while('\x00' != *szDrive);


    TCHAR buf[BUFSIZE];
    HANDLE hVol;
    BOOL bFlag;

    // 查找主机上第一个驱动器，返回驱动器名
    hVol = FindFirstVolume(buf, BUFSIZE);
    if(hVol == INVALID_HANDLE_VALUE)
    {
        printf(TEXT("No volumes found!\n"));
        return -1;
    }
    // 查找下一个驱动器
    while(FindNextVolume(hVol, buf, BUFSIZE))
    {
        printf("%s\n", buf);
    }
    // 关闭一个驱动器的句柄
    bFlag = FindVolumeClose(hVol);

    system("pause");
    return bFlag;
}