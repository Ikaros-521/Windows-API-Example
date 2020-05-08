// VS Code(GB2312), MinGW, g++编译
#include <Windows.h>
#include <stdio.h>

int main()
{
    BOOL bResult;
    // 簇
    DWORD dwTotalClusters;
    DWORD dwFreeClusters;
    // 扇区
    DWORD dwSectPerClust;
    DWORD dwBytesPerSect;
    
    // 这里以C盘为例
    bResult = GetDiskFreeSpace(TEXT("C:"), &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);
    if(bResult)
    {
        printf("\n使用GetDiskFreeSpace获取磁盘空间信息\n");
        printf("总簇数量: \t\t\t%d\n", dwTotalClusters);
        printf("空闲的簇数量: \t\t\t%d\n", dwFreeClusters);
        printf("每簇的扇区数量: \t\t%d\n", dwSectPerClust);
        printf("每扇区字节数: \t\t\t%d\n", dwBytesPerSect);
        printf("磁盘总容量: \t\t\t%I64d字节\n", (DWORD64)dwTotalClusters * (DWORD64)dwSectPerClust * (DWORD64)dwBytesPerSect);
        printf("磁盘空闲容量: \t\t\t%I64d字节\n", (DWORD64)dwFreeClusters * (DWORD64)dwSectPerClust * (DWORD64)dwBytesPerSect);
    }

    printf("\n\n");

    DWORD64 qwFreeBytes, qwFreeBytesToCaller, qwTotalBytes;
    bResult = GetDiskFreeSpaceEx(TEXT("C:"), 
        (PULARGE_INTEGER)&qwFreeBytesToCaller, 
        (PULARGE_INTEGER)&qwTotalBytes, 
        (PULARGE_INTEGER)&qwFreeBytes);
    if(bResult)
    {
        printf("\n使用GetDiskFreeSpaceEx获取磁盘空间信息\n");
        printf("磁盘总容量: \t\t\t%I64d字节\t%dGB\n", qwTotalBytes, qwTotalBytes/1024/1024/1024);
        printf("可用的磁盘空闲容量: \t\t%I64d字节\t%dGB\n", qwFreeBytes, qwFreeBytes/1024/1024/1024);
        printf("磁盘空闲容量: \t\t\t%I64d字节\t%dGB\n", qwFreeBytesToCaller, qwFreeBytesToCaller/1024/1024/1024);
    }

    system("pause");
    return 0;
}