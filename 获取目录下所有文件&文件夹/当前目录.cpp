// VS Code(GB2312), MinGW, g++编译
#include <Windows.h>
#include <stdio.h>

DWORD EnumerateFileInDirectory(LPTSTR szPath)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hListFile;
    TCHAR szFilePath[MAX_PATH];
    lstrcpy(szFilePath, szPath);
    lstrcat(szFilePath, TEXT("\\*"));
    hListFile = FindFirstFile(szFilePath, &FindFileData);
    if(hListFile == INVALID_HANDLE_VALUE)
    {
        printf("错误: %d\n", GetLastError()); 
        return 1;
    }
    else
    {
        do
        {
            if(lstrcmp(FindFileData.cFileName, TEXT(".")) == 0 ||
                lstrcmp(FindFileData.cFileName, TEXT("..")) == 0)
            {
                continue;
            }
            printf("%s\t\t\t", FindFileData.cFileName);
            if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_ENCRYPTED)
            {
                printf("<加密>");
            }
            if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
            {
                printf("<隐藏>");
            }
            if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                printf("<DIR>");
            }
            printf("\n");
        } while (FindNextFile(hListFile, &FindFileData));
        
    }
}


int main()
{
    // 显示目录下所有文件/文件夹
    EnumerateFileInDirectory(TEXT("e:"));
    system("pause");
    return 0;
}