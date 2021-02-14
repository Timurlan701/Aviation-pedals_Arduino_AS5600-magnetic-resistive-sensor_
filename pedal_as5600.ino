#include <Joystick.h>
#include <Wire.h>
#include <AS5600.h>

Joystick_ Joystick;
AMS_5600 ams5600;

#define zpos ams5600.getStartPosition()
#define mpos ams5600.getEndPosition()
#define rawAng ams5600.getRawAngle()

void setup() {

  Joystick.begin(115200);
  Wire.begin();
}

void loop()
{
    Serial.print("Angle: ");
    Serial.println(rawAng * 0.087);
    Joystick.setZAxis(map(rawAng, zpos, mpos, 0, 1023));
    
    delay(50);
}
