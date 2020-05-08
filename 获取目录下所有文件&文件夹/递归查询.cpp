// VS Code(GB2312), MinGW, g++����
#include <Windows.h>
#include <stdio.h>

DWORD dwTotalFileNum = 0;

DWORD ListAllFileInDirectory(LPTSTR szPath)
{
    /*
    typedef struct _WIN32_FIND_DATA {  
        DWORD dwFileAttributes;  //�ļ�����
        FILETIME ftCreationTime;  //����ʱ��
        FILETIME ftLastAccessTime;  //�������ʱ��
        FILETIME ftLastWriteTime; //����޸�ʱ��
        DWORD nFileSizeHigh; //��λ��С
        DWORD nFileSizeLow;  //��λ��С
        DWORD dwReserved0;  //����
        DWORD dwReserved1;  //����
        TCHAR cFileName[MAX_PATH];//�ļ�������ȫ·�� 
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
    //�����ļ�
    HANDLE WINAPI FindFirstFile(
        __in          LPCTSTR lpFileName,//�ļ�����·��
        __out         LPWIN32_FIND_DATA lpFindFileData
    );
    */
    hListFile = FindFirstFile(szFilePath, &FindFileData);
    if(hListFile == INVALID_HANDLE_VALUE)
    {
        printf("����: %d\n", GetLastError()); 
        return 1;
    }
    else
    {
        do
        {
            // ƴ��ȫ��
            if(lstrcmp(FindFileData.cFileName, TEXT(".")) == 0 ||
                lstrcmp(FindFileData.cFileName, TEXT("..")) == 0)
            {
                continue;
            }
            wsprintf(szFullPath, "%s\\%s", szPath, FindFileData.cFileName);
            dwTotalFileNum++;
            printf("\n%d\t%s\t", dwTotalFileNum, szFullPath);
            // ������ļ���
            if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                printf("<DIR>");
                // �ݹ�
                ListAllFileInDirectory(szFullPath);
            }
        } while (FindNextFile(hListFile, &FindFileData));
        printf("\n");
    }
    return 0;
}


int main()
{
    // ��ʾĿ¼�¼���Ŀ¼�������ļ�/�ļ���
    ListAllFileInDirectory((LPTSTR)TEXT("e:\\OpenCV"));
    system("pause");
    return 0;
}