/*
RPM and Speed via reed switch.
Based on state change example and blink withought delay.
 http://arduino.cc/en/Tutorial/ButtonStateChange
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
This code is junk.
This really needs to trigger an interupt. That is beyond me currently.
You have been warned.
Reed switch may require hardware debouncing.
*/

// Constants.
const int switchPin = 2;        // Set the pin used for reed switch.
const float circ = 69.12;       // Circumference of wheel = DIAM * PI in inches

// Variables.
unsigned int switchCounter = 0;     // Rotation counter.
int switchState = 0;                // State of reed switch.
int lastSwitchState = 0;            //last state of switch.
unsigned long lastMicros = 0;       // Last report HIGH
unsigned long currentMicros = 0;    // Current report HIGH         
unsigned long difMicros = 0;        // Difference
float RPM = 0;                      // RPM in Float.
float MPH = 0;                      // Miles Per Hour.
int timer=0;

void setup() {
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

// Enter loop.

void loop() {

  
  timer++;
  switchState = digitalRead(switchPin);
  
  if (switchState != lastSwitchState) {
    timer = 0;
    if (switchState == HIGH) {
    switchCounter++;
    currentMicros = micros();
    difMicros = currentMicros - lastMicros;
    RPM = 60000000.0 / difMicros;
    MPH = (((RPM * circ) / 12) / 5280) * 60;
/*    Serial.print("switchCounter  ");
    Serial.println(switchCounter);
    Serial.println(currentMicros);
    Serial.println(lastMicros);
    Serial.println(difMicros);
*/    
    Serial.println(MPH);
  }
  
}    
   
  

lastSwitchState = switchState;
lastMicros = currentMicros;
 
}

