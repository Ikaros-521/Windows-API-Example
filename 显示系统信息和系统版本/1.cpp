// VS Code(编码gb2312),win7,mingw
// g++编译
#include <windows.h>
#include <stdio.h>

void ShowVersionInfo()
{
    OSVERSIONINFO ovex;
    TCHAR szVersionInfo[1024];
    ovex.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if(!GetVersionEx(&ovex))
    {
        printf("error %d\n", GetLastError());
        return;
    }

    if(ovex.dwMajorVersion == 5)
    {
        if(ovex.dwMinorVersion == 0)
            lstrcat(szVersionInfo, TEXT("Windows 2000"));
        else if(ovex.dwMinorVersion == 1)
            lstrcat(szVersionInfo, TEXT("Windows XP"));
        else if(ovex.dwMinorVersion == 2)
            lstrcat(szVersionInfo, TEXT("Windows Server 2003"));
    }
    else if(ovex.dwMajorVersion == 6)
        lstrcat(szVersionInfo, TEXT("Windows Vista"));
    else
        lstrcat(szVersionInfo, TEXT("其他"));

    printf("系统版本信息：%s\n", szVersionInfo);
    printf("Windows %d.%d Build %d ", ovex.dwMajorVersion, ovex.dwMinorVersion, ovex.dwBuildNumber);
    printf("%s\n", ovex.szCSDVersion);
}

void ShowSystemInfo()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("内存分页大小：0x%.8X, 可用内存起始: 0x%.8X, 可用内存结束：0x%.8X\n",
        si.dwPageSize, si.lpMinimumApplicationAddress, si.lpMaximumApplicationAddress);
    printf("处理器个数：%d\n", si.dwNumberOfProcessors);
    printf("处理器类型：");
    switch(si.dwProcessorType)
    {
    case PROCESSOR_INTEL_386:
        printf("386\n");
        break;
    case PROCESSOR_INTEL_486:
        printf("486\n");
        break;
    case PROCESSOR_INTEL_PENTIUM:
        printf("pentium\n");
        break;
    default:
        printf("%d\n", si.dwProcessorType);
        break;
    }

    printf("处理器架构：");
    switch (si.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_INTEL:
        printf("intel\n");
        break;
    case PROCESSOR_ARCHITECTURE_IA64:
        printf("64 bits intel\n");
        break;
    case PROCESSOR_ARCHITECTURE_AMD64:
        printf("64 bits AMD\n");
        break;
    default:
        break;
    }

    TCHAR szSystemDirectory[MAX_PATH];
    TCHAR szWindowsDirectory[MAX_PATH];
    GetSystemDirectory(szSystemDirectory, MAX_PATH);
    GetWindowsDirectory(szWindowsDirectory, MAX_PATH);
    printf("系统目录: \t%s\n", szSystemDirectory);
    printf("Windows目录: \t%s\n", szWindowsDirectory) ;
    
    DWORD dwComputerNameLen = MAX_COMPUTERNAME_LENGTH + 1;
    TCHAR szComputerName [MAX_COMPUTERNAME_LENGTH+1];
    
    GetComputerName(szComputerName,&dwComputerNameLen);
    printf("计算机名: \t%s\n" ,szComputerName) ;

    DWORD dwUserNameLen = 64;
    TCHAR szUserName[64];
    GetUserName(szUserName, &dwUserNameLen);
    printf("用户名: \t%s\n", szUserName) ;

}

int main()
{
    ShowVersionInfo();
    printf("\n");
    ShowSystemInfo();
    system("pause");
    return 0;
}
