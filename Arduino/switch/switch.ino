#define PIN_BUTTON 3
#define PIN_RELAY  7

bool buttonState = HIGH;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(7, LOW);
  
  // bluetooth
  Serial.begin(38400);
  Serial.println("Hello");
}

void loop() {
  int preState = digitalRead(PIN_BUTTON);
  delay(10);
  int nowState = digitalRead(PIN_BUTTON);

  if (preState && !nowState)
    buttonState = !buttonState;

  // bluetooth
  String s = "";
  while (Serial.available()) {
    char c = Serial.read();
    if(c!='\n') {
      s += c;
    }
    delay(5);
  }
  if (s == "sw\r") 
    buttonState = !buttonState;
     
  digitalWrite(PIN_RELAY, buttonState);
}
