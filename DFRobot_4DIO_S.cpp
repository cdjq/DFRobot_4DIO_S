/*!
 *@file DFRobot_4DIO_S.cpp
 *@brief the implementation of the basic methods
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-7-22
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_4DIO_S
*/
#include "DFRobot_4DIO_S.h"


DFRobot_4DIO_S::DFRobot_4DIO_S(Stream *s,uint8_t addr)
:DFRobot_RTU(s){
  _addr = addr;
  //DFRobot_RTU::DFRobot_RTU(s);
}
uint16_t DFRobot_4DIO_S::readPid()
{ 
  delay(20);
  return readHoldingRegister(_addr,REG_4DIO_DEVICE_PID);
}

uint16_t DFRobot_4DIO_S::readVid()
{
  delay(20);
  return readHoldingRegister(_addr,REG_4DIO_DEVICE_VID);
}

uint16_t DFRobot_4DIO_S::setAddr(uint16_t addr)
{
  return writeHoldingRegister(_addr,REG_4DIO_DEVICE_ADRR,&addr,2);
}

uint16_t DFRobot_4DIO_S::setBaudrRate(uint16_t rate)
{
  return writeHoldingRegister(_addr,REG_4DIO_UART_CONFIG1,&rate,2);
}

bool DFRobot_4DIO_S::setDio(eDio_t number)
{
  return writeCoilsRegister(_addr,number,true);
}
bool DFRobot_4DIO_S::configDio(bool dio1,bool dio2,bool dio3, bool dio4)
{
   uint8_t data = 0;
   
   data = (uint8_t)dio1;
   data = data | ((uint8_t)dio2 << 1);
   data = data | ((uint8_t)dio3 << 2);
   data = data | ((uint8_t)dio4 << 3);
   Serial.println(data);
   return writeCoilsRegister(_addr,1,4,&data,1);

}
bool DFRobot_4DIO_S::resetDio(eDio_t number)
{
  return writeCoilsRegister(_addr,number,false);
}

uint8_t DFRobot_4DIO_S::readDio(eDio_t number)
{
  uint8_t data;
  readCoilsRegister(_addr,number,1,&data,1);
  delay(20);
  return data;
}
uint8_t DFRobot_4DIO_S::readDio(uint8_t &dio1,uint8_t &dio2,uint8_t &dio3 ,uint8_t &dio4){

  uint8_t ret;
  uint8_t data;
  ret = readCoilsRegister(_addr,1,4,&data,1);
  dio1 = data & 0x01;
  dio2 = (data & 0x02) >> 1;
  dio3 = (data & 0x04) >> 2;
  dio4 = (data & 0x08) >> 3;
  return ret;
  
}
uint8_t DFRobot_4DIO_S::readInt(eInt_t intN)
{
  uint8_t data;
  readDiscreteInputsRegister(_addr,intN,1,&data,1);
  delay(20);
  return data;
}
uint8_t DFRobot_4DIO_S::readInt(uint8_t &int1,uint8_t &int2,uint8_t &int3 ,uint8_t &int4){


  uint8_t ret;
  uint8_t data;
  ret = readDiscreteInputsRegister(_addr,1,4,&data,1);
  int1 = data & 0x01;
  int2 = (data & 0x02) >> 1;
  int3 = (data & 0x04) >> 2;
  int4 = (data & 0x08) >> 3;
  return ret;


}