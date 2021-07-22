# DFRobot_4DIO_S
 4-DIO 是一个继电器控制模块,该模块拥有四个线圈继电器,四个离散输入引脚
 

![正反面svg效果图](https://github.com/cdjq/DFRobot_4DIO_S/raw/master/resources/images/SEN0245svg4.png)


## Product Link（链接到英文商城）
    SKU：产品名称
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Calibration](#calibration)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
This is a DFRobot_4DIO_S libary  for raspberryPi by DFRobot.<br>


## Installation
To use this library, first download the library file, then open the examples folder and run the demo in the folder Proceed as follows:
* sudo git clone https://github.com/DFRobot/DFRobot_4DIO_S
* cd python
* cd raspberrypi
* cd examples
* python demo_*
* python3 demo_*


## Methods

```C++
'''
  
  '''
    @brief 获取设备pid
    @return 返回16设备pid
  '''
  def read_pid(self):

  '''
    @brief 获取设备vid
    @return 返回16设备vid
  '''
  def read_vid(self):

  
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

  '''
    @brief 设置单个继电器为连通状态
    @param number 继电器的编号
    @return True(成功)/False(失败)
  '''
  def set_dio(self,number):

  '''
    @brief 设置单个继电器为断开状态
    @param number 继电器的编号
    @return True(成功)/False(失败)
  '''
  def reset_dio(self,number):

  '''
    @brief 配置四个继电器的状态
    @param dio1 True(连通)/False(断开)
    @param dio2 True(连通)/False(断开)
    @param dio3 True(连通)/False(断开)
    @param dio4 True(连通)/False(断开)
    @return True(成功)/False(失败)
  '''
  def config_dio(self,dio1,dio2,dio3,dio4):
  
  '''
    @brief 获取单个继电器的开关状态
    @param number 继电器的编号
    @return 1(连通)/0(断开)
  '''
  def read_dio(self,number):

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
      
  '''
    @brief 获取单个离散输入引脚的状态
    @param intN 离散输入编号
    @return 1(高电平)/0(低电平)
  '''
  def read_int(self,intN):
  
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

```

## Compatibility

MCU                | SoftwareSerial | HardwareSerial |  IO   |
------------------ | :----------: | :----------: | :---------: |
raspberry          |      X       |      √       |      √       |

## History

- Data 2021-07-22
- Version V1.0

## Credits

Written by fengli(li.feng@dfrobot.com), 2021.7.22 (Welcome to our [website](https://www.dfrobot.com/))





