/*
  ESP32 Blink
  esp32-blink.ino
  Rewrite of classic Blink sketch for ESP32
  Use LED on GPIO2
   
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// LED on GPIO2
int ledPin = 1, lednum = 36;

void setup()
{
    for(int i = 1; i < lednum; i++){
      // Set LED as output
      pinMode(ledPin, OUTPUT);
    }
   
    
    // Serial monitor setup
    Serial.begin(115200);
}

void loop()
{
    for(int j = 1; j < lednum; j++){
       Serial.print(j);
       Serial.print("\n");
       digitalWrite(j, HIGH);
       delay(1000);
    
       digitalWrite(j, LOW);
    
       delay(1000);
    }
    
}
