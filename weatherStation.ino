#include <Wire.h>
#include "ds3231.h"
#include "rtc_ds3231.h"
#include <MicroLCD.h>
#include <SHT1x.h>
#include <SD.h>

//ds3231
#define BUFF_MAX 128
uint8_t time[8];
char recv[BUFF_MAX];
unsigned int recv_size = 0;
unsigned long prev, interval = 5000;
//oled
LCD_SH1106 lcd; /* for SH1106 OLED module */
//sht1x
const int dataPin = 5;
const int clockPin = 6;
SHT1x sht1x(dataPin, clockPin);
float temp;
float humidity;
//SD card
const int sdCS = 4;
File myFile;
char *fileName = "datalog1.txt";

void setup()
{
    Serial.begin(9600);
    
    pinMode(sdCS, OUTPUT);
    
    if(!SD.begin(sdCS)){
      Serial.println("Card failed, or not present");
      return;
    }else{
      Serial.println("Card initialized.");
    }
    
    Wire.begin();
    DS3231_init(DS3231_INTCN);
    memset(recv, 0, BUFF_MAX);
    
    lcd.begin();
    Serial.println("GET time");
    
    //sdtest();
}

void loop()
{   
    char buffer[BUFF_MAX];
    unsigned long now = millis();
    struct ts t;

    if ((now - prev > interval) && (Serial.available() <= 0)) {
        DS3231_get(&t);
        snprintf(buffer, BUFF_MAX, "%d.%02d.%02d %02d:%02d:%02d", t.year,
             t.mon, t.mday, t.hour, t.min, t.sec);
        Serial.println(buffer);
        saveData(buffer, temp, humidity);
        prev = now;
    }

    temp = readtemp();
    humidity = readhumidity();
    displayOled(buffer, temp, humidity);
    //sdtest();
}

