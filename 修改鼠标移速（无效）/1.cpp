// VS Code(编码gb2312),win7,mingw
// g++编译
#include <windows.h>
#include <stdio.h>

int main()
{
    BOOL fResult;
    int aMouseInfo[3];
    // SPI_GETMOUSE：检索鼠标的2个阈值和加速特性。pvParam参数必须指向一个长度为3的整型数组，分别存储此值。
    fResult = SystemParametersInfo(SPI_GETMOUSE, 0, &aMouseInfo, 0);
    printf("fResult:%d\n", fResult);
    int i = 0;
    for(i=0; i<3; i++)
    {
        printf("i[%d]:%d\n", i, aMouseInfo[i]);
    }
    if(fResult)
    {
        // 鼠标移速翻倍，但是无效。。。
        aMouseInfo[2] = 2 * aMouseInfo[2];
        SystemParametersInfo(SPI_SETMOUSE, 0, aMouseInfo, SPIF_SENDCHANGE);
    }
    printf("ok\n");

    system("pause");
    return 0;
}
