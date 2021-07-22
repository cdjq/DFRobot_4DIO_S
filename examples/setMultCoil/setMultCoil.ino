/*!
 *@file getMultCoil.ino
 *@brief 设置设备多个继电器开关状态
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
//打开使用1,3继电器,不使用2,4继电器
dio.configDio(true,false,true,false);
delay(2000);
//打开使用2,4继电器,不使用1,3继电器
dio.configDio(false,true,false,true);
delay(2000);
}