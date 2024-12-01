// Distanz-Sensor (25..1000mm) mit VL53L0x Chip
// - https://docs.m5stack.com/en/unit/TOF
// - https://github.com/adafruit/Adafruit_VL53L0X

//-------------------------------------------------------------------
#include <Adafruit_VL53L0X.h>

//-------------------------------------------------------------------
Adafruit_VL53L0X sensor;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  while (sensor.begin() == false) {
    Serial.print(".");
    delay(1000);
  }

  sensor.startRangeContinuous();
}

//-------------------------------------------------------------------
void loop(void)
{
  if (sensor.isRangeComplete()) {
    Serial.print("Distanz: ");
    Serial.print( sensor.readRange() );
    Serial.println(" mm");
  }

  //delay(100);
}
