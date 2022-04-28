/*
  ESP32 Blink
  esp32-blink.ino
  Rewrite of classic Blink sketch for ESP32
  Use LED on GPIO2
   
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// LED on GPIO2
int lednum = 36;

void setup()
{
      // Set LED as output
      pinMode(23, OUTPUT);
    
   
    
    // Serial monitor setup
    Serial.begin(115200);
}

void loop()
{
    //for(int j = 1; j < lednum; j++){
       Serial.print("hello");
       Serial.print("\n");
       digitalWrite(23, HIGH);
       delay(1000);
    
       digitalWrite(23, LOW);
    
       delay(1000);
    //}
    
}
