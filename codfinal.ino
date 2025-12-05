#include <Servo.h>

Servo servoOX;
Servo servoOY;
Servo servoOZ;

int pinServoOX = 8;
int pinServoOY = 9;
int pinServoOZ = 10;
bool buttonPressed = false;

int VRx = A0;
int VRy = A1;
int buttonPin = 2;

void setup() {
  Serial.begin(9600);
  servoOX.attach(pinServoOX);
  servoOY.attach(pinServoOY);
  servoOZ.attach(pinServoOZ);

  pinMode(buttonPin, INPUT_PULLUP);

  servoOX.write(90); // Poziție neutră la start
  servoOY.write(90); // Poziție neutră la start
  servoOZ.write(0); // Poziție neutră la start
  
  Serial.println("Controleaza servomotoarele pe OX, OY cu joystick-ul si OZ cu butonul");
}

void loop() {
  int valoareX = analogRead(VRx);
  int valoareY = analogRead(VRy);
  int butonApasat = digitalRead(buttonPin);

  // Control pentru axa OX
  if (valoareX < 450) {
    Serial.println("OX: Rotire la stanga");
    servoOX.write(0); // Rotire la stânga
  } 
  else if (valoareX > 570) {
    Serial.println("OX: Rotire la dreapta");
    servoOX.write(180); // Rotire la dreapta
  } 
  else {
    servoOX.write(90); // Oprire
  }

  // Control pentru axa OY
  if (valoareY < 450) {
    Serial.println("OY: Rotire in jos");
    servoOY.write(0); // Rotire în jos
  } 
  else if (valoareY > 570) {
    Serial.println("OY: Rotire in sus");
    servoOY.write(180); // Rotire în sus
  } 
  else {
    servoOY.write(90); // Oprire
  }

  // Control pentru axa OZ
  if (butonApasat == LOW && !buttonPressed) {
    buttonPressed = true;
    Serial.println("OZ: Coborâre");
    servoOZ.write(180); // Coborâre
    delay(3000);        // Așteaptă 3 secunde
    Serial.println("OZ: Ridicare");
    servoOZ.write(0);   // Ridicare
  }
  if (butonApasat == HIGH && buttonPressed) {
    buttonPressed = false;
  }
}
