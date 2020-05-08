// 编译 g++ 文件名 -o 生成文件名
#include <Windows.h>
#include <iostream>
using namespace std;

int main() {
	// 获取带标题栏和菜单栏即全屏像素大小
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	// 睡眠5s，准备时间
	Sleep(5000);
	// 判断用变量
	int flag = 14;
	// 死循环
	while (1) 
	{
		// 移动到绝对位置右击
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_MOVE, 718 * 65535 / width, 734 * 65535 / height, 0, 0 );
		Sleep(4000);
	
		// 移动到绝对位置右击
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN  | MOUSEEVENTF_RIGHTUP | MOUSEEVENTF_MOVE, 1078 * 65535 / width, 412 * 65535 / height, 0, 0 );
		Sleep(4000);
		
		flag++;
	
		// 时间到了即cd到了，进入条件
		if(flag > 13)
		{
			// 按下某键
			keybd_event(87, 0, 0, 0);
			keybd_event(87, 0, KEYEVENTF_KEYUP, 0);
			Sleep(5000);
			keybd_event(68, 0, 0, 0);
			keybd_event(68, 0, KEYEVENTF_KEYUP, 0);
			Sleep(500);
			keybd_event(82, 0, 0, 0);
			keybd_event(82, 0, KEYEVENTF_KEYUP, 0);
			Sleep(3000);
			keybd_event(87, 0, 0, 0);
			keybd_event(87, 0, KEYEVENTF_KEYUP, 0);
			Sleep(2500);
			flag = 0;
		}	
	}
	
	//system("pasue");
	return 0;
}