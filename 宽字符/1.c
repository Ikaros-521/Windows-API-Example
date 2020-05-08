// 编译 gcc 1.c
// 开发环境 VS Code(gb2312)，MinGW，Win7
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    printf("Locale is %s\n", setlocale(LC_ALL, NULL));
    // 用来配置地域的信息，设置当前程序使用的本地化信息。
    // 若 locale 为零(NULL)，则不会改变地域化配置，返回当前的地域值
    setlocale(LC_ALL,"");
    printf("Locale is %s\n", setlocale(LC_ALL, NULL));

    char c = 'a';
    printf("c:%c\n", c);

    // 宽字符
    wchar_t c2 = L'爱';
    wprintf(L"c2:%c\n", c2);

    char s[] = "abc";
    wchar_t s2[] = L"木大木大木大";
    char s3[] = "天下第一";
    printf("s:%s\n", s);
    wprintf(L"s2:%s\n", s2);
    printf("s3:%s\n", s3);

    printf("s len:%d\n", strlen(s));
    printf("s2 len:%d\n", wcslen(s2));
    printf("s3 len:%d\n", strlen(s3));

    system("pause");
    return 0;
}