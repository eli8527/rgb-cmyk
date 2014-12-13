/*
RGB to CMYK
Eric Li
 */

int rLed = 13; // Red LED Pin
int gLed = 11; // Green LED Pin
int bLed = 12; // Blue LED Pin
int rVal, gVal, bVal; // Values of RGB

int rPot = 0; // Analog 0 - Red Pot
int gPot = 3; // Analog 3 - Green Pot
int bPot = 7; // Analog 7 - Blue Pot

int buttonPin = 2;

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  pinMode(rPot, INPUT);
  pinMode(gPot, INPUT);
  pinMode(bPot, INPUT);
  
  rVal = 0;
  gVal = 0;
  bVal = 0;
  
  
  Serial.begin(9600);
// Serial.write("Setup Done\n");

} 

// the loop routine runs over and over again forever:
void loop()  { 

  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  rVal = analogRead(rPot)/4;
  gVal = analogRead(gPot)/4;
  bVal = analogRead(bPot)/4;
  
  // set the brightness of pin 9:
  analogWrite(rLed, 255-rVal);
  analogWrite(gLed, 255-gVal);
  analogWrite(bLed, 255-bVal);  
 
  
  // If the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
      // reset the debouncing timer
      lastDebounceTime = millis();
    } 
  
    if ((millis() - lastDebounceTime) > debounceDelay) {
        
      if (reading != buttonState) {
        buttonState = reading;
  
        // only toggle the LED if the new button state is HIGH
        if (buttonState == HIGH) {
          Serial.print(rVal);
          Serial.print(",");
          Serial.print(gVal);
          Serial.print(",");
          Serial.print(bVal);
          Serial.print("\n");
        }
      }
    }
    
    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastButtonState = reading;
    
}
  
