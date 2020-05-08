#coding=utf-8
#适合窗口化游戏1280*800
import time
from pymouse import PyMouse
from pykeyboard import PyKeyboard

m = PyMouse() 
k = PyKeyboard()

#睡眠5s，给你准备时间
time.sleep(5)
#锁定视角
k.tap_key("y")
time.sleep(0.5)

#循环
while True:
	#右击这个坐标
	m.click(732,716,2,1)
	time.sleep(3.8)
	
	#按下q
	k.tap_key("q")
	time.sleep(0.5)
	
	#右击这个坐标
	m.click(1149,375,2,1)
	time.sleep(3.8)
