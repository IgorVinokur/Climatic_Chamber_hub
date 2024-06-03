#include <Arduino.h>
#include "config.h"


void setup() {
  // put your setup code here, to run once:
startup();
Serial.println("Starting loading...");

}

void loop() {
  // put your main code here, to run repeatedly:
hub.tick();
data.tick();

}
