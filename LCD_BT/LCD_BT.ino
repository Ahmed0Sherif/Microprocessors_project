// Include libraries
#include <WiFi.h>
#include "time.h"
#include <LiquidCrystal_I2C.h>       // Include LiquidCrystal_I2C library
//#include "BluetoothSerial.h"

// Configure LiquidCrystal_I2C library with 0x27 address, 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid       = "Yahia Walid";
const char* password   = "yinhunfuf";

const char* ntpServer = "pool.ntp.org";
const int  gmtOffset_sec = 7200;
const int   daylightOffset_sec = 0;

// Print the time on the serial monitor
void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  // Print time on serial monitor
  Serial.println(&timeinfo, "%B %d %Y %H:%M:%S");

  // Print time in LCD
  lcd.setCursor(0, 0);
  lcd.print(&timeinfo, "%d %Y %H:%M:%S");
  lcd.setCursor(0, 1);
  lcd.print(&timeinfo, "%B");
}


void setup()
{
  Serial.begin(115200);
  
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  // Initialize I2C LCD module (SDA = GPIO21, SCL = GPIO22)
  lcd.begin(21, 22);
  // Turn backlight ON
  lcd.backlight();

}

void loop()
{
  delay(1000);
  printLocalTime();
  
}
