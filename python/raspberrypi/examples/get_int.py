# -*- coding: utf-8 -*
'''
  @file get_int.py
  @brief 获取4-Dio模块4个int离散输入的状态
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
  @author [fengli](li.feng@dfrobot.com)
  @version  V1.0
  @date  2021-7-21
  @get from https://www.dfrobot.com
  @https://github.com/DFRobot/DFRobot_4DIO_S
'''
import sys
import time
sys.path.append("../")
from DFRobot_4DIO_S import *

ADRESS     =           0x0E       #4-DIO模块设备地址
'''
  @brief Init communication port
  @param Device address
  @param Software serial or hardware serial 
'''
dio = DFRobot_4DIO_S(ADRESS,19200)
    
#获取PID
print('PID = %d'%dio.read_pid())
time.sleep(0.01)
#获取VID
print('PID = %d'%dio.read_vid())
print("start")
while(True):
   #获取int1的输入状态
   if dio.read_int(dio.INT_1):
       print("int1 high")
   time.sleep(0.3)
   #获取int2的输入状态
   if dio.read_int(dio.INT_2):
       print("int2 high")
   time.sleep(0.3)
   #获取int3的输入状态
   if dio.read_int(dio.INT_3):
       print("int3 high")
   time.sleep(0.3)
   #获取int4的输入状态
   if dio.read_int(dio.INT_4):
       print("int4 high")
   time.sleep(0.3)