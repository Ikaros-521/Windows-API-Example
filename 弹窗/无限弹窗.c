// 开发环境 VS Code（gb2312编码），MinGW，win7
// 编译命令 gcc 文件名.c -o 生成文件名
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    // 无限弹窗
    while(1)
    {
        // 弹窗
        MessageBox(NULL, TEXT("打开任务管理器，找到对应进程（文件名.exe），结束进程即可"), TEXT("关闭方式"), MB_OK);
    }
    return 0;
}