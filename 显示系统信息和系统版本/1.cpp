// VS Code(����gb2312),win7,mingw
// g++����
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
        lstrcat(szVersionInfo, TEXT("����"));

    printf("ϵͳ�汾��Ϣ��%s\n", szVersionInfo);
    printf("Windows %d.%d Build %d ", ovex.dwMajorVersion, ovex.dwMinorVersion, ovex.dwBuildNumber);
    printf("%s\n", ovex.szCSDVersion);
}

void ShowSystemInfo()
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("�ڴ��ҳ��С��0x%.8X, �����ڴ���ʼ: 0x%.8X, �����ڴ������0x%.8X\n",
        si.dwPageSize, si.lpMinimumApplicationAddress, si.lpMaximumApplicationAddress);
    printf("������������%d\n", si.dwNumberOfProcessors);
    printf("���������ͣ�");
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

    printf("�������ܹ���");
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
    printf("ϵͳĿ¼: \t%s\n", szSystemDirectory);
    printf("WindowsĿ¼: \t%s\n", szWindowsDirectory) ;
    
    DWORD dwComputerNameLen = MAX_COMPUTERNAME_LENGTH + 1;
    TCHAR szComputerName [MAX_COMPUTERNAME_LENGTH+1];
    
    GetComputerName(szComputerName,&dwComputerNameLen);
    printf("�������: \t%s\n" ,szComputerName) ;

    DWORD dwUserNameLen = 64;
    TCHAR szUserName[64];
    GetUserName(szUserName, &dwUserNameLen);
    printf("�û���: \t%s\n", szUserName) ;

}

int main()
{
    ShowVersionInfo();
    printf("\n");
    ShowSystemInfo();
    system("pause");
    return 0;
}
