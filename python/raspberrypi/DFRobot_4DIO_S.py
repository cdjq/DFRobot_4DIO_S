# -*- coding:utf-8 -*-
'''
  @file DFRobot_4DIO_S.py
  @brief DFRobot_4DIO_S libary for raspberry. 
  
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @licence     The MIT License (MIT)
  @author [fengli](li.feng@dfrobot.com)
  @version  V1.0
  @date  2021-07-21
  @https://github.com/DFRobot/DFRobot_RTU
'''

from DFRobot_RTU import *

class DFRobot_4DIO_S(DFRobot_RTU): 

  REG_4DIO_DEVICE_PID     =  0x00  #pid
  REG_4DIO_DEVICE_VID     =  0x01  #vid
  REG_4DIO_DEVICE_ADRR    =  0x02  #设备地址寄存器
  REG_4DIO_UART_CONFIG1   =  0x03  #设备串口通信配置寄存器1
  REG_4DIO_UART_CONFIG2   =  0x04  #设备串口通信配置寄存器2
  
  BEEP  = 0X00  #蜂鸣器
  DIO_1 = 0X01  #编号1的继电器
  DIO_2 = 0X02  #编号2的继电器
  DIO_3 = 0X03  #编号3的继电器
  DIO_4 = 0X04  #编号4的继电器
  
  INT_1 = 0X01  #离散输入1
  INT_2 = 0X02  #离散输入2
  INT_3 = 0X03  #离散输入3
  INT_4 = 0X04  #离散输入4
  
  '''
    @brief Init communication port
    @param Device address
    @param Software serial or hardware serial 
  '''
  def __init__(self ,addr,Baud):
    self.__Baud = Baud
    self.__Addr = addr
    super(DFRobot_4DIO_S, self).__init__(Baud, 8, 'N', 1)
  
  '''
    @brief 获取设备pid
    @return 返回16设备pid
  '''
  def read_pid(self):
     return self.read_holding_register(self.__Addr,self.REG_4DIO_DEVICE_PID)

  '''
    @brief 获取设备vid
    @return 返回16设备vid
  '''
  def read_vid(self):
     return self.read_holding_register(self.__Addr,self.REG_4DIO_DEVICE_VID)
  
  '''
    @brief 设置设备地址
    @param addr 要设置的设备地址
    @return Exception code:
    @n      0 : sucess.
    @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
    @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
    @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
    @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
    @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
    @n      9 or eRTU_RECV_ERROR:  Receive packet error.
    @n      10 or eRTU_MEMORY_ERROR: Memory error.
    @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
  '''
  def set_addr(self,addr):
     return self.write_holding_register(self.__Addr,self.REG_4DIO_DEVICE_ADRR,addr)
     
  '''
    @brief 设置从机通信的波特率(复位从机后生效)
    @param rate 要设置的波特率
                0x0001 : 2400
                0x0002 : 4800
                0x0003 : 9600
                0x0004 : 14400
                0x0005 : 19200
                0x0006 : 38400
                0x0007 : 57600
                0x0008 : 115200
                other  : 115200
    @return Exception code:
    @n      0 : sucess.
    @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
    @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
    @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
    @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
    @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
    @n      9 or eRTU_RECV_ERROR:  Receive packet error.
    @n      10 or eRTU_MEMORY_ERROR: Memory error.
    @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
  '''
  def set_baudr_rate(self,rate):
     return self.write_holding_register(self.__Addr,self.REG_4DIO_UART_CONFIG1,rate)
     

  '''
    @brief 设置单个继电器为连通状态
    @param number 继电器的编号
    @return True(成功)/False(失败)
  '''
  def set_dio(self,number):
      return self.write_coils_register(self.__Addr,number,0xff00)
  '''
    @brief 设置单个继电器为断开状态
    @param number 继电器的编号
    @return True(成功)/False(失败)
  '''
  def reset_dio(self,number):
      return self.write_coils_register(self.__Addr,number,0x00)

  '''
    @brief 配置四个继电器的状态
    @param dio1 True(连通)/False(断开)
    @param dio2 True(连通)/False(断开)
    @param dio3 True(连通)/False(断开)
    @param dio4 True(连通)/False(断开)
    @return True(成功)/False(失败)
  '''
  def config_dio(self,dio1,dio2,dio3,dio4):
      data = 0 
      data = int(dio1)
      data = data | int(dio2 << 1);
      data = data | int(dio3 << 2);
      data = data | int(dio4 << 3);
      return self.write_coils_registers(self.__Addr,1,data)
  
  '''
    @brief 获取单个继电器的开关状态
    @param number 继电器的编号
    @return 1(连通)/0(断开)
  '''
  def read_dio(self,number):
     return self.read_coils_register(self.__Addr,number)

  '''
    @brief 获取四个继电器的开关状态
    @param dio1 1(连通)/0(断开)
    @param dio2 1(连通)/0(断开)
    @param dio3 1(连通)/0(断开)
    @param dio4 1(连通)/0(断开)
    @return Exception code:
    @n      0 : sucess.
    @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
    @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
    @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
    @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
    @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
    @n      9 or eRTU_RECV_ERROR:  Receive packet error.
    @n      10 or eRTU_MEMORY_ERROR: Memory error.
    @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
  '''
  def read_mult_dio(self):
      list = self.read_coils_registers(self.__Addr,1,4)
      dio1 = list[1] & 0x01
      dio2 = (list[1] & 0x02)>>1
      dio3 = (list[1] & 0x04)>>2
      dio4 = (list[1] & 0x08)>>3
      return dio1,dio2,dio3,dio4
      
  '''
    @brief 获取单个离散输入引脚的状态
    @param intN 离散输入编号
    @return 1(高电平)/0(低电平)
  '''
  def read_int(self,intN):
      return self.read_discrete_inputs_register(self.__Addr,intN)
  
  '''
    @brief 获取四个离散输入引脚的状态
    @param int1 1(高电平)/0(低电平)
    @param int2 1(高电平)/0(低电平)
    @param int3 1(高电平)/0(低电平)
    @param int4 1(高电平)/0(低电平)
    @return Exception code:
    @n      0 : sucess.
    @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
    @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
    @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
    @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
    @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
    @n      9 or eRTU_RECV_ERROR:  Receive packet error.
    @n      10 or eRTU_MEMORY_ERROR: Memory error.
    @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
  '''
  def read_mult_int(self):
      list = self.read_discrete_inputs_registers(self.__Addr,1,4)
      int1 = list[1] & 0x01
      int2 = (list[1] & 0x02)>>1
      int3 = (list[1] & 0x04)>>2
      int4 = (list[1] & 0x08)>>3
      return int1,int2,int3,int4
  