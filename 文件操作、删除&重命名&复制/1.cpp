// VS Code(GB2312), MinGW, g++编译
// 实例cmd运行 a.exe -c 1.txt 12.txt
#include <Windows.h>
#include <stdio.h>

int main(int argc, PTCHAR argv[])
{
    //printf("参数个数: %d\n", argc);
    //printf("第1个: %s\n", argv[0]);
    //printf("第2个: %s\n", argv[0]);
    //printf("第3个: %s\n", argv[0]);
    if (0==lstrcmp("-d", argv[1]) && argc==3)
    {
        if(!DeleteFile(argv[2]))
        {
            printf("删除文件发生错误: %x\n", GetLastError());
        }
        else
        {
            printf("删除文件成功\n");
        }
        
    }
    else if (0==lstrcmp("-c", argv[1]) && argc==4)
    {
        // TRUE为存在不覆盖
        if(!CopyFile(argv[2], argv[3], TRUE))
        {
            // 若目标文件已经存在
            if(GetLastError() == 0x50)
            {
                printf("文件%s已经存在，是否要覆盖? y/n: ", argv[3]);
                if('y' == getchar())
                {
                    // 复制并覆盖
                    if(!CopyFile(argv[2], argv[3], FALSE))
                    {
                        printf("复制文件发生错误: %d\n", GetLastError());
                    }
                    else
                    {
                        printf("复制文件成功\n");
                    }
                }
                else
                    return 0;
            }
        }
        else
        {
            printf("复制文件成功\n");
        }
    }
    else if (0==lstrcmp("-m", argv[1]) && argc==4)
    {
        if(!MoveFile(argv[2], argv[3]))
        {
            printf("重命名文件发生错误: %d\n", GetLastError());
        }
        else
        {
            printf("重命名文件成功\n");
        }
    }
    else
    {
        printf("参数错误\n");
    }
    


    return 0;
}