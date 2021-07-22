# -*- coding: utf-8 -*
'''
  @file set_dio.py
  @brief 设置4-Dio模块4个继电器的开关状态
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
print('PID = %d',dio.read_pid())
time.sleep(0.01)
#获取VID
print('PID = %d',dio.read_vid())

#更改设置设备(重启后生效)
dio.set_addr(0x0e);

'''
更改设备串口通信波特率(重启后生效)
   0x0001 : 2400
   0x0002 : 4800
   0x0003 : 9600
   0x0004 : 14400
   0x0005 : 19200
   0x0006 : 38400
   0x0007 : 57600
   0x0008 : 115200
   other  : 115200
'''
dio.set_baudr_rate(0x05);


while(True):
    #打开使用1,3继电器,不使用2,4继电器
    #dio.config_dio(True,False,True,False)
    #time.sleep(2)
    #打开使用2,4继电器,不使用1,3继电器
    #dio.config_dio(False,True,False,True)
    #time.sleep(2)
    
    #分别开关四个继电器
    dio.set_dio(dio.DIO_1)
    time.sleep(0.5)
    dio.set_dio(dio.DIO_2)
    time.sleep(0.5)
    dio.set_dio(dio.DIO_3)
    time.sleep(0.5)
    dio.set_dio(dio.DIO_4)
    time.sleep(0.5)
    
    dio.reset_dio(dio.DIO_1)
    time.sleep(0.5)
    dio.reset_dio(dio.DIO_2)
    time.sleep(0.5)
    dio.reset_dio(dio.DIO_3)
    time.sleep(0.5)
    dio.reset_dio(dio.DIO_4)
    time.sleep(0.5)
    
