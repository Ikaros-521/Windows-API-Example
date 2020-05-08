#include <Windows.h>
#include <stdio.h>

int main()
{
    TCHAR szSystemDir[MAX_PATH];
    // 取得Windows系统目录(System目录)的完整路径名
    GetSystemDirectory(szSystemDir, MAX_PATH) ;
    printf("%s\n", szSystemDir) ;
    HANDLE hFile;
    DWORD dwWritten;
    // 打开文件
    hFile = CreateFile("systemroot.txt",
        GENERIC_WRITE,
        0, NULL,CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        // 写szSystemDir进入文件
        if(!WriteFile(hFile, szSystemDir, lstrlen(szSystemDir), &dwWritten, NULL))
            return GetLastError();
    }
    // 关闭一个内核对象
    CloseHandle(hFile);
    printf("OK\n");
    system("pause");
    return 0;


}
