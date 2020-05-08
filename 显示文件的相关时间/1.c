// VS Code ���� gb2312, gcc ����
#include <stdio.h>
#include <windows.h>

struct Date
{
    short month;
    short day;
    short year; 
};

// ��ʾʱ��
DWORD ShowFileTime(PFILETIME lptime)
{
    FILETIME ftLocal;
    SYSTEMTIME st;
    FileTimeToLocalFileTime(lptime, &ftLocal);
    FileTimeToSystemTime(&ftLocal, &st);
    printf("%d��%#02d��%#02d��, %#02d:%#02d:%#02d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return 0;
}

int main()
{
    WIN32_FILE_ATTRIBUTE_DATA wfad;
    // �����ļ���
    char filename[256] = {};
    printf("�������ļ���:");
    scanf("%s", filename);
    /* �˺�����ȡ����һ���ļ���Ŀ¼������Ϣ��
    BOOL GetFileAttributesEx(
        LPCTSTR lpFileName, 
        GET_FILEEX_INFO_LEVELS fInfoLevelId, 
        LPVOID lpFileInformation 
    );
    */
    if (!GetFileAttributesEx(filename, GetFileExInfoStandard, &wfad))
    {
        printf("��ȡ�ļ�����ʧ��: %d\n", GetLastError());
        return 1;
    }

    printf("����ʱ��:\t");
    ShowFileTime(&wfad.ftCreationTime);
    printf("����ʱ��:\t");
    ShowFileTime(&wfad.ftLastAccessTime);
    printf("�޸�ʱ��:\t");
    ShowFileTime(&wfad.ftLastWriteTime);
    system("pause");
    return 0;
}