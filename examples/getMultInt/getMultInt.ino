
/*!
 *@file getMultInt.ino
 *@brief 获取设备的多个外部输入引脚状态
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
  /**
   * @brief Init communication port
   * @param Software serial or hardware serial 
   * @param Device address
   */
  DFRobot_4DIO_S dio(/*s =*/&mySerial,0x0e);
#else
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
}

void loop(){
  uint8_t int1,int2,int3,int4;
  //获取四个离散输入引脚的状态
  dio.readInt(int1,int2,int3,int4);
  if(int1){
    Serial.println("int1 high");
  }

  if(int2){
    Serial.println("int2 high");
  }

  if(int3){
    Serial.println("int3 high");
  }

  if(int4){
    Serial.println("int4 high");
  }
  delay(100);
}