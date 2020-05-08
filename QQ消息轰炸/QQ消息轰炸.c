// 测试环境：win7，MinGW，VS Code（编码方式 GB2312）
// 使用Windows API，编译命令 gcc 文件名.c -o 生成文件名
#include <stdio.h>
#include <windows.h>

int main()
{
    printf("程序名：QQ消息轰炸\n功能说明：循环向指定窗口发送粘贴板的内容\n");
    // 窗口名，即QQ对象的昵称
    char win_name[100];
    printf("请输入窗口名:");
    scanf("%s", win_name);
    HWND win = FindWindow(NULL, win_name);
    // 循环次数
    int i = 0;
    printf("请输入发送次数:");
    scanf("%d", &i);
    // 循环
    while(i--)
    {
        // 粘贴
        SendMessage(win, WM_PASTE, 0, 0);
        // 回车
        SendMessage(win, WM_KEYDOWN, VK_RETURN, 0);
    }
    printf("发送完毕!\n");
    return 0;
}

/*
常用窗口消息：
WM_GETFONT(&H31=49)                   得到当前控件绘制文本的字体（的句柄）
WM_GETTEXT(&HD=13),变量长度,变量       取得窗体的标题，变量须预先赋空字串(chr(0))，变量长度=Len(变量)
WM_SETTEXT(&HC=12),0,ByVal "字串"     设置窗体的标题
WM_NCLBUTTONDOWN(&HA1=161),2,0        在非客户区，即边框及标题栏上（假如定义的是一个组件，则非客户区包括Form等）按下鼠标左键；
WM_LBUTTONDOWN(&H201=513),2,0         在客户区，也就是除边框及标题栏以外按下鼠标左键
WM_VSCROLL(&H115=277),&H10000*p+SB_THUMBPOSITION(&H4),0 同步滚动文本，p是位置改变量
WM_PAINT
WM_USER(&H400=1024)

WM_CUT(&H300=768),0,0                 剪切
WM_COPY(&H301=769)),0,0               复制
WM_PASTE(&H302=770)),0,0              粘贴
WM_CLEAR(&H303=771)),0,0              删除
WM_UNDO(&H304=772)),0,0               撤消
*/
