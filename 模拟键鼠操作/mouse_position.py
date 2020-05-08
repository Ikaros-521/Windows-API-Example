#coding=utf-8
#python 2.7
#pip install pyUserInput
import time
from pymouse import PyMouse
from pykeyboard import PyKeyboard

m = PyMouse() 
k = PyKeyboard()

time.sleep(5)

while True:
	x,y = m.position()
	print "x:",x,",y:",y
	time.sleep(3)