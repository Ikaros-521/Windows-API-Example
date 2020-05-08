// VS Code 编码 gb2312, gcc 编译
#include <stdio.h>
#include <windows.h>

struct Date
{
    short month;
    short day;
    short year; 
};

// 显示时间
DWORD ShowFileTime(PFILETIME lptime)
{
    FILETIME ftLocal;
    SYSTEMTIME st;
    FileTimeToLocalFileTime(lptime, &ftLocal);
    FileTimeToSystemTime(&ftLocal, &st);
    printf("%d年%#02d月%#02d日, %#02d:%#02d:%#02d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return 0;
}

int main()
{
    WIN32_FILE_ATTRIBUTE_DATA wfad;
    // 传入文件名
    char filename[256] = {};
    printf("请输入文件名:");
    scanf("%s", filename);
    /* 此函数获取其他一组文件或目录属性信息。
    BOOL GetFileAttributesEx(
        LPCTSTR lpFileName, 
        GET_FILEEX_INFO_LEVELS fInfoLevelId, 
        LPVOID lpFileInformation 
    );
    */
    if (!GetFileAttributesEx(filename, GetFileExInfoStandard, &wfad))
    {
        printf("获取文件属性失败: %d\n", GetLastError());
        return 1;
    }

    printf("创建时间:\t");
    ShowFileTime(&wfad.ftCreationTime);
    printf("访问时间:\t");
    ShowFileTime(&wfad.ftLastAccessTime);
    printf("修改时间:\t");
    ShowFileTime(&wfad.ftLastWriteTime);
    system("pause");
    return 0;
}