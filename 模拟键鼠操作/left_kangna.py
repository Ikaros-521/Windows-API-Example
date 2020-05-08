#coding=utf-8
#适合窗口化游戏1280*800
#python 2.7
#pip install pyUserInput
import time
from pymouse import PyMouse
from pykeyboard import PyKeyboard

m = PyMouse() 
k = PyKeyboard()

#睡眠5s，给你准备时间
time.sleep(5)
#锁定视角
#k.tap_key("y")
#time.sleep(0.5)

#判断是否放R
flag = 14

#循环
while True:
	#右击这个坐标
	m.click(1138,371,2,1)
	time.sleep(4)
	
	#右击这个坐标
	m.click(820,631,2,1)
	time.sleep(4)
	
	if flag > 13:
		k.tap_key('w')
		time.sleep(5)
		k.tap_key('d')
		time.sleep(0.5)
		k.tap_key('r')
		time.sleep(3)
		k.tap_key('w')
		time.sleep(2.5)
		flag = 0
	flag = flag + 1