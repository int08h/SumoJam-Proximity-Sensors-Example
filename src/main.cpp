//
// Sumo Jam example reading the proximity sensors
//
#include <Zumo32U4.h>

namespace {
   // Delay between loop()s in milliseconds
  constexpr unsigned long DELAY_MS = 100;

  // Proximity sensors object
  Zumo32U4ProximitySensors proxSensors = Zumo32U4ProximitySensors{};

  // Robot LCD display
  Zumo32U4LCD lcd = Zumo32U4LCD{};
} // namespace 

void setup() {
  // Initialize the Left, Front, and Right proximity sensors
  proxSensors.initThreeSensors();

  // Initialize the LCD
  lcd.init();
}

void loop() {
  // Emit IR pulses and read values from the sensors
  proxSensors.read();    
  
  // The front sensor, intensity of the reflected infra-red
  // light from the left LED and the right LED in turn
  int valueFrontLeft = proxSensors.countsFrontWithLeftLeds();
  int valueFrontRight = proxSensors.countsFrontWithRightLeds();

  // Side sensors, intensity of reflected infra-red light from
  // the LED on the same side
  int valueSideLeft = proxSensors.countsLeftWithLeftLeds();
  int valueSideRight = proxSensors.countsRightWithRightLeds();

  // Display the sensor readings (0-6) on the LCD
  //      FL  FR
  //    SL      SR
  lcd.clear();
  lcd.gotoXY(2, 0);
  lcd.print(valueFrontLeft);
  lcd.gotoXY(5, 0);
  lcd.print(valueFrontRight);

  lcd.gotoXY(0, 1);
  lcd.print(valueSideLeft);
  lcd.gotoXY(7, 1);
  lcd.print(valueSideRight);

  delay(DELAY_MS);
}