// VS Code(����gb2312),win7,mingw
// g++����
#include <windows.h>
#include <stdio.h>

int main()
{
    BOOL fResult;
    int aMouseInfo[3];
    // SPI_GETMOUSE����������2����ֵ�ͼ������ԡ�pvParam��������ָ��һ������Ϊ3���������飬�ֱ�洢��ֵ��
    fResult = SystemParametersInfo(SPI_GETMOUSE, 0, &aMouseInfo, 0);
    printf("fResult:%d\n", fResult);
    int i = 0;
    for(i=0; i<3; i++)
    {
        printf("i[%d]:%d\n", i, aMouseInfo[i]);
    }
    if(fResult)
    {
        // ������ٷ�����������Ч������
        aMouseInfo[2] = 2 * aMouseInfo[2];
        SystemParametersInfo(SPI_SETMOUSE, 0, aMouseInfo, SPIF_SENDCHANGE);
    }
    printf("ok\n");

    system("pause");
    return 0;
}
