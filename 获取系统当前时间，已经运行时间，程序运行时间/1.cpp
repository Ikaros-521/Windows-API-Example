// VS Code(����gb2312),win7,mingw
// g++����
#include <windows.h>
#include <stdio.h>

#define total 100000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    SYSTEMTIME st;
    GetLocalTime (&st);
    printf("Now: %d-%d-%d, %d:%d:%d\n",
    st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    //SetLocalTime(&st);

    DWORD c1 = GetTickCount() ;
    //ULONGLONG c2 = GetTickCount64() ;
    printf("��������%dms �� %ds �� %dmin\n", c1, c1/1000, c1/1000/60);

    int nums[total];
    srand(GetTickCount());
    for(int i=0; i<total; i++)
        nums[i] = rand() % 1000;
    int StartTime = GetTickCount();
    // ����
    qsort(nums, total, sizeof(nums[0]), cmp);
    int EndTime = GetTickCount();
    printf("����%d��������ʱ: %d ms\n", total, EndTime - StartTime);

    //for(int i=0; i<total; i++)
    //    printf("%d\n", nums[i]);

    system("pause");
    return 0;
}
