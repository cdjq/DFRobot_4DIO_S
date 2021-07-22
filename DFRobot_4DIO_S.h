/*!
 *@file DFRobot_4DIO_S.h
 *@brief Define the basic structure of class DFRobot_4DIO_S, the implementation of basic methods.
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-7-22
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_4DIO_S
*/


#ifndef DFROBOT_4DIO_S_H
#define DFROBOT_4DIO_S_H
#include "DFRobot_RTU.h"
#include <Arduino.h>
#include <string.h>
#include <Wire.h>
//#define ENABLE_DBG
#include<Stream.h>
#ifdef ENABLE_DBG
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif
//extern Stream *dbg;
#define REG_4DIO_DEVICE_PID      0x00  //pid寄存器
#define REG_4DIO_DEVICE_VID      0x01  //vid寄存器 
#define REG_4DIO_DEVICE_ADRR     0x02  //设备地址寄存器
#define REG_4DIO_UART_CONFIG1    0x03  //设备串口通信配置寄存器1
#define REG_4DIO_UART_CONFIG2    0x04  //设备串口通信配置寄存器2



class DFRobot_4DIO_S : public DFRobot_RTU
{
public:
  typedef enum{
   eBeep  = 0x00,  //蜂鸣器
   eDio_1 = 0x01,  //编号1的继电器
   eDio_2 = 0x02,  //编号2的继电器
   eDio_3 = 0x03,  //编号3的继电器
   eDio_4 = 0x04,  //编号4的继电器
  }eDio_t;
  
  typedef enum{
   eInt_1 = 0x01,  //离散输入1
   eInt_2 = 0x02,  //离散输入2
   eInt_3 = 0x03,  //离散输入3
   eInt_4 = 0x04,  //离散输入4
  }eInt_t;
public:

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

private:
  uint8_t _addr;


};
#endif