/*
HANDLE CreateFile(
    LPCTSTR lpFileName,    // 指向文件名的指针 
    DWORD dwDesiredAccess,    // 访问模式（写 / 读） 
    DWORD dwShareMode,    // 共享模式 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes, // 指向安全属性的指针 
    DWORD dwCreationDisposition,   // 如何创建 
    DWORD dwFlagsAndAttributes,   // 文件属性 
    HANDLE hTemplateFile    // 用于复制文件句柄 
);
*/
#include <stdio.h>
#include <windows.h>

#define BUF_SIZE 256

int main()
{
    HANDLE hFileRead;
    DWORD nIn;
    CHAR buffer[BUF_SIZE];
    // 打开文件
    hFileRead = CreateFile("1.txt",
        GENERIC_READ,
        FILE_SHARE_READ, 
        NULL,
        OPEN_EXISTING, 
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if(hFileRead == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open file Error: %x\n", GetLastError());
        system("pause");
        return -1;
    }
    // 读取数据
    while(ReadFile(hFileRead, buffer, BUF_SIZE, &nIn, NULL) && nIn > 0)
    {
        printf("%s\n", buffer);
    }
    
    system("pause");
    return 0;

}