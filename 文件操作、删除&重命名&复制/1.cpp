// VS Code(GB2312), MinGW, g++����
// ʵ��cmd���� a.exe -c 1.txt 12.txt
#include <Windows.h>
#include <stdio.h>

int main(int argc, PTCHAR argv[])
{
    //printf("��������: %d\n", argc);
    //printf("��1��: %s\n", argv[0]);
    //printf("��2��: %s\n", argv[0]);
    //printf("��3��: %s\n", argv[0]);
    if (0==lstrcmp("-d", argv[1]) && argc==3)
    {
        if(!DeleteFile(argv[2]))
        {
            printf("ɾ���ļ���������: %x\n", GetLastError());
        }
        else
        {
            printf("ɾ���ļ��ɹ�\n");
        }
        
    }
    else if (0==lstrcmp("-c", argv[1]) && argc==4)
    {
        // TRUEΪ���ڲ�����
        if(!CopyFile(argv[2], argv[3], TRUE))
        {
            // ��Ŀ���ļ��Ѿ�����
            if(GetLastError() == 0x50)
            {
                printf("�ļ�%s�Ѿ����ڣ��Ƿ�Ҫ����? y/n: ", argv[3]);
                if('y' == getchar())
                {
                    // ���Ʋ�����
                    if(!CopyFile(argv[2], argv[3], FALSE))
                    {
                        printf("�����ļ���������: %d\n", GetLastError());
                    }
                    else
                    {
                        printf("�����ļ��ɹ�\n");
                    }
                }
                else
                    return 0;
            }
        }
        else
        {
            printf("�����ļ��ɹ�\n");
        }
    }
    else if (0==lstrcmp("-m", argv[1]) && argc==4)
    {
        if(!MoveFile(argv[2], argv[3]))
        {
            printf("�������ļ���������: %d\n", GetLastError());
        }
        else
        {
            printf("�������ļ��ɹ�\n");
        }
    }
    else
    {
        printf("��������\n");
    }
    


    return 0;
}