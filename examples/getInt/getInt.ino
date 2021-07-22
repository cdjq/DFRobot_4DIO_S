
/*!
 *@file getInt.ino
 *@brief 获取设备外部输入引脚状态
 *@copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2021-7-22
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_4DIO_S
*/


#include "DFRobot_4DIO_S.h"
#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
#include <SoftwareSerial.h>
#endif

#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
  SoftwareSerial mySerial(/*rx =*/4, /*tx =*/5);
  DFRobot_4DIO_S dio(/*s =*/&mySerial,0x0e);
#else
  /**
   * @brief Init communication port
   * @param Software serial or hardware serial 
   * @param Device address
   */
  DFRobot_4DIO_S dio(&Serial1,0x0e);
#endif

void setup()
{
  Serial.begin(115200);
  while(!Serial){                                                     //Waiting for USB Serial COM port to open.
  }

#if defined(ARDUINO_AVR_UNO)||defined(ESP8266)
    mySerial.begin(19200);
#elif defined(ESP32)
    Serial1.begin(19200, SERIAL_8N1, /*rx =*/D3, /*tx =*/D2);
#else
    Serial1.begin(19200);
#endif
   //获取设备pid
   Serial.print("pid :");
   Serial.println(dio.readPid());
   //获取设备vid
   Serial.print("vid :");
   Serial.println(dio.readVid());
   //更改设置设备(重启后生效)
   dio.setAddr(0x0e);
   
   /*
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
   */
   dio.setBaudrRate(0x05);
}

void loop(){
  //获取int1的输入状态
  if(dio.readInt(dio.eInt_1)){
    Serial.println("int1 high");
  }
  //获取int2的输入状态
  delay(10);
  if(dio.readInt(dio.eInt_2)){
    Serial.println("int2 high");
  }
  //获取int3的输入状态
  delay(10);
  if(dio.readInt(dio.eInt_3)){
    Serial.println("int3 high");
  }
  //获取int4的输入状态
  delay(10);
  if(dio.readInt(dio.eInt_4)){
    Serial.println("int4 high");
  }
  delay(10);
}