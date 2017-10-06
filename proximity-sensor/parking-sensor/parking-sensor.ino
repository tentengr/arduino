#define trigPin 12
#define echoPin 11
#define ledPin 10

long distance = 500, duration;
int blinkInterval = 500;
boolean blinkStart = false;
long previousMillis = 0;
int ledState = LOW;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  setInterval(true);
  blinkLed();
}

void setInterval(boolean debug) {
  distance = readDistance();
  blinkInterval = distance * 10;
  
  if (distance > 40) {
    blinkStart = false;
  } else {
    blinkStart = true;
  }
  
  if (debug) {
    Serial.println(distance);
  }
}

int readDistance() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return distance = (duration/2) / 29.1;
}

void blinkLed() {
  if (!blinkStart) {
    ledState = LOW;
    digitalWrite(ledPin, ledState);
    return;
  }

  if (blinkInterval < 40) {
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
    return;
  }
  
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > blinkInterval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
 
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) ledState = HIGH;
    else                 ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}


