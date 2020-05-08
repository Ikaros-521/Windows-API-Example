// 开发环境 VS Code（gb2312编码），MinGW，win7
// 编译命令 gcc 文件名.c -o 生成文件名
#include <stdio.h>
#include <Windows.h>

int main(void)
{
    // 弹窗
    MessageBox(NULL, TEXT("内容"), TEXT("标题"), MB_OK);
    return 0;
}