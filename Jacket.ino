#define buttonLeftPin A2        // analog input pin to use as a digital input
#define buttonRightPin 9	//input for right LEDs
#define ledLeftPin 11          // digital output pin for left indicator LEDs 
#define ledRightPin 10          // digital output pin for right indicator LEDs

int debounce = 50;          // ms debounce period to prevent flickering when pressing or releasing the button
boolean buttonLeftVal = HIGH;
boolean buttonRightVal = HIGH;
long upTime = -1;
long downTime = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRightPin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);
  //pinMode(ledButtonPin, OUTPUT);
  pinMode(buttonLeftPin, INPUT_PULLUP);
  pinMode(buttonRightPin, INPUT);
  digitalWrite (ledRightPin, LOW);
  digitalWrite (ledLeftPin, LOW);
  //digitalWrite (ledButtonPin, LOW);
  digitalWrite (buttonLeftPin, HIGH);
  digitalWrite (buttonRightPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonLeftVal = digitalRead(buttonLeftPin);
  buttonRightVal = digitalRead(buttonRightPin);
  //Left Signal
  if (buttonLeftVal == LOW && (millis() - upTime) > debounce)
  {
    //Blink the Left LEDs if the left button is pressed and held longer than debounce
    digitalWrite (ledLeftPin, HIGH);
      delay(500);
      digitalWrite (ledLeftPin, LOW);
      delay(500);
      downTime = millis();
  }
  

  //Right Signal
  if (buttonRightVal == LOW && (millis() - upTime) > debounce)
  {
    //Blink the Right LEDs if the right button is pressed and held longer than debounce
    digitalWrite (ledRightPin, HIGH);
      delay(500);
      digitalWrite (ledRightPin, LOW);
      delay(500);
      downTime = millis();
  }
  if (buttonRightVal == HIGH && buttonLeftVal == HIGH && (millis() - downTime) > debounce){
    // Blink left and right LEDs if none of the buttons are pressed.
    digitalWrite (ledRightPin, HIGH);
    digitalWrite (ledLeftPin, HIGH);
    delay(500);
    digitalWrite (ledRightPin, LOW);
    digitalWrite (ledLeftPin, LOW);
    delay(500);
    upTime = millis();
  }
  
}
