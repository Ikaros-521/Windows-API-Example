// ���Ի�����win7��MinGW��VS Code�����뷽ʽ GB2312��
// ʹ��Windows API���������� gcc �ļ���.c -o �����ļ���
#include <stdio.h>
#include <windows.h>

int main()
{
    printf("��������QQ��Ϣ��ը\n����˵����ѭ����ָ�����ڷ���ճ���������\n");
    // ����������QQ������ǳ�
    char win_name[100];
    printf("�����봰����:");
    scanf("%s", win_name);
    HWND win = FindWindow(NULL, win_name);
    // ѭ������
    int i = 0;
    printf("�����뷢�ʹ���:");
    scanf("%d", &i);
    // ѭ��
    while(i--)
    {
        // ճ��
        SendMessage(win, WM_PASTE, 0, 0);
        // �س�
        SendMessage(win, WM_KEYDOWN, VK_RETURN, 0);
    }
    printf("�������!\n");
    return 0;
}

/*
���ô�����Ϣ��
WM_GETFONT(&H31=49)                   �õ���ǰ�ؼ������ı������壨�ľ����
WM_GETTEXT(&HD=13),��������,����       ȡ�ô���ı��⣬������Ԥ�ȸ����ִ�(chr(0))����������=Len(����)
WM_SETTEXT(&HC=12),0,ByVal "�ִ�"     ���ô���ı���
WM_NCLBUTTONDOWN(&HA1=161),2,0        �ڷǿͻ��������߿򼰱������ϣ����綨�����һ���������ǿͻ�������Form�ȣ�������������
WM_LBUTTONDOWN(&H201=513),2,0         �ڿͻ�����Ҳ���ǳ��߿򼰱��������ⰴ��������
WM_VSCROLL(&H115=277),&H10000*p+SB_THUMBPOSITION(&H4),0 ͬ�������ı���p��λ�øı���
WM_PAINT
WM_USER(&H400=1024)

WM_CUT(&H300=768),0,0                 ����
WM_COPY(&H301=769)),0,0               ����
WM_PASTE(&H302=770)),0,0              ճ��
WM_CLEAR(&H303=771)),0,0              ɾ��
WM_UNDO(&H304=772)),0,0               ����
*/
