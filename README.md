# DFRobot_4DIO_S
 4-DIO 是一个继电器控制模块,该模块拥有四个线圈继电器,四个离散输入引脚
 
![正反面svg效果图](https://github.com/cdjq/DFRobot_4DIO_S/raw/master/resources/images/SEN0245svg4.png)

## 产品链接（链接到英文商城）
    SKU：产品名称
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary


Provide an Arduino library to control 4-dio

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++

  /**
   * @brief Init communication port
   * @param Software serial or hardware serial 
   * @param Device address
   */
  DFRobot_4DIO_S(Stream *s,uint8_t addr);
  
  /**
   * @brief 获取设备pid
   * @return 返回16设备pid
   */
  uint16_t readPid();
  
  /**
   * @brief 获取设备vid
   * @return 返回16设备vid
   */
  uint16_t readVid();
  
  /**
   * @brief 设置设备地址
   * @param addr 要设置的设备地址
   * @return Exception code:
   * @n      0 : sucess.
   * @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
   * @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
   * @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
   * @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
   * @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
   * @n      9 or eRTU_RECV_ERROR:  Receive packet error.
   * @n      10 or eRTU_MEMORY_ERROR: Memory error.
   * @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
   */
  uint16_t setAddr(uint16_t addr);

  /**
   * @brief 设置从机通信的波特率(复位从机后生效)
   * @param rate 要设置的波特率
                 0x0001 : 2400
                 0x0002 : 4800
                 0x0003 : 9600
                 0x0004 : 14400
                 0x0005 : 19200
                 0x0006 : 38400
                 0x0007 : 57600
                 0x0008 : 115200
                 other  : 115200
   * @return Exception code:
   * @n      0 : sucess.
   * @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
   * @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
   * @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
   * @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
   * @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
   * @n      9 or eRTU_RECV_ERROR:  Receive packet error.
   * @n      10 or eRTU_MEMORY_ERROR: Memory error.
   * @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
   */
  uint16_t setBaudrRate(uint16_t rate);

  /**
   * @brief 设置单个继电器为连通状态
   * @param number 继电器的编号
   * @return true(成功)/false(失败)
   */
  bool setDio(eDio_t number);
  
  /**
   * @brief 设置单个继电器为断开状态
   * @param number 继电器的编号
   * @return true(成功)/false(失败)
   */
  bool resetDio(eDio_t number);
  
  /**
   * @brief 配置四个继电器的状态
   * @param dio1 true(连通)/false(断开)
   * @param dio2 true(连通)/false(断开)
   * @param dio3 true(连通)/false(断开)
   * @param dio4 true(连通)/false(断开)
   * @return true(成功)/false(失败)
   */
  bool configDio(bool dio1,bool dio2,bool dio3, bool dio4);

  /**
   * @brief 获取单个继电器的开关状态
   * @param number 继电器的编号
   * @return 1(连通)/0(断开)
   */
  uint8_t readDio(eDio_t number);
  
  /**
   * @brief 获取四个继电器的开关状态
   * @param dio1 1(连通)/0(断开)
   * @param dio2 1(连通)/0(断开)
   * @param dio3 1(连通)/0(断开)
   * @param dio4 1(连通)/0(断开)
   * @return Exception code:
   * @n      0 : sucess.
   * @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
   * @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
   * @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
   * @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
   * @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
   * @n      9 or eRTU_RECV_ERROR:  Receive packet error.
   * @n      10 or eRTU_MEMORY_ERROR: Memory error.
   * @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
   */
  uint8_t readDio(uint8_t &dio1,uint8_t &dio2,uint8_t &dio3 ,uint8_t &dio4);

  /**
   * @brief 获取单个离散输入引脚的状态
   * @param intN 离散输入编号
   * @return 1(高电平)/0(低电平)
   */
  uint8_t readInt(eInt_t intN);
  
  /**
   * @brief 获取四个离散输入引脚的状态
   * @param int1 1(高电平)/0(低电平)
   * @param int2 1(高电平)/0(低电平)
   * @param int3 1(高电平)/0(低电平)
   * @param int4 1(高电平)/0(低电平)
   * @return Exception code:
   * @n      0 : sucess.
   * @n      1 or eRTU_EXCEPTION_ILLEGAL_FUNCTION : Illegal function.
   * @n      2 or eRTU_EXCEPTION_ILLEGAL_DATA_ADDRESS: Illegal data address.
   * @n      3 or eRTU_EXCEPTION_ILLEGAL_DATA_VALUE:  Illegal data value.
   * @n      4 or eRTU_EXCEPTION_SLAVE_FAILURE:  Slave failure.
   * @n      8 or eRTU_EXCEPTION_CRC_ERROR:  CRC check error.
   * @n      9 or eRTU_RECV_ERROR:  Receive packet error.
   * @n      10 or eRTU_MEMORY_ERROR: Memory error.
   * @n      11 or eRTU_ID_ERROR: Broadcasr address or error ID
   */
  uint8_t readInt(uint8_t &int1,uint8_t &int2,uint8_t &int3 ,uint8_t &int4);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
Micro:bit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 
Raspberry Pi      |      √       |              |             | 


## History

- Date 2021-7-22
- Version V0.1


## Credits

Written by fengli(li.feng@dfrobot.com), 2021.7.22 (Welcome to our [website](https://www.dfrobot.com/))





