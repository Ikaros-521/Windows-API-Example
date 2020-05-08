// VS Code(GB2312), MinGW, g++编译
#include <Windows.h>
#include <stdio.h>

DWORD dwTotalFileNum = 0;

DWORD ListAllFileInDirectory(LPTSTR szPath)
{
    /*
    typedef struct _WIN32_FIND_DATA {  
        DWORD dwFileAttributes;  //文件属性
        FILETIME ftCreationTime;  //创建时间
        FILETIME ftLastAccessTime;  //最近访问时间
        FILETIME ftLastWriteTime; //最近修改时间
        DWORD nFileSizeHigh; //高位大小
        DWORD nFileSizeLow;  //低位大小
        DWORD dwReserved0;  //保留
        DWORD dwReserved1;  //保留
        TCHAR cFileName[MAX_PATH];//文件名，非全路径 
        TCHAR cAlternateFileName[14];
    }WIN32_FIND_DATA,*PWIN32_FIND_DATA,*LPWIN32_FIND_DATA;
    */
    WIN32_FIND_DATA FindFileData;
    HANDLE hListFile;
    TCHAR szFilePath[MAX_PATH];
    TCHAR szFullPath[MAX_PATH];

    lstrcpy(szFilePath, szPath);
    lstrcat(szFilePath, TEXT("\\*"));

    /*
    //查找文件
    HANDLE WINAPI FindFirstFile(
        __in          LPCTSTR lpFileName,//文件名或路径
        __out         LPWIN32_FIND_DATA lpFindFileData
    );
    */
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
            // 拼接全名
            if(lstrcmp(FindFileData.cFileName, TEXT(".")) == 0 ||
                lstrcmp(FindFileData.cFileName, TEXT("..")) == 0)
            {
                continue;
            }
            wsprintf(szFullPath, "%s\\%s", szPath, FindFileData.cFileName);
            dwTotalFileNum++;
            printf("\n%d\t%s\t", dwTotalFileNum, szFullPath);
            // 如果是文件夹
            if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                printf("<DIR>");
                // 递归
                ListAllFileInDirectory(szFullPath);
            }
        } while (FindNextFile(hListFile, &FindFileData));
        printf("\n");
    }
    return 0;
}


int main()
{
    // 显示目录下及子目录下所有文件/文件夹
    ListAllFileInDirectory((LPTSTR)TEXT("e:\\OpenCV"));
    system("pause");
    return 0;
}