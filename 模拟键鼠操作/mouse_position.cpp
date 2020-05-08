#include <Windows.h>
#include <iostream>
using namespace std;

int main() {
	// 死循环
	while (1) 
	{
		POINT pt = {0,0};
		// 检取光标的位置，以屏幕坐标表示
		GetCursorPos(&pt);
		// 打印当前鼠标的坐标
		printf("x=%d,y=%d\n", pt.x,pt.y);
		// 睡眠3s
		Sleep(3000);
	}
	
	//system("pasue");
	return 0;
}