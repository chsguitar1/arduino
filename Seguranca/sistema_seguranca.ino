  #define trigPin 6
  #define echoPin 7
  #define GreenLED 11
  #define YellowLED 10
  #define RedLED 9
  #define buzzer 3
  
  int sound = 500;
  
  void setup() {
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(GreenLED, OUTPUT);
    pinMode(YellowLED, OUTPUT);
    pinMode(RedLED, OUTPUT);
    pinMode(buzzer, OUTPUT);
   
  }
  
  void loop() {
    long duration, distance;
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/5) / 29.1;
   
    if (distance < 50) 
    {
        digitalWrite(GreenLED, HIGH);
    }
    else {
        digitalWrite(GreenLED, LOW);
    }
    
    if (distance < 20) 
    {
      digitalWrite(YellowLED, HIGH);
    }
    else {
      digitalWrite(YellowLED,LOW);
    }
    
     if (distance < 5) {
      digitalWrite(RedLED, HIGH);
      sound = 1000;
    }
    else {
      digitalWrite(RedLED,LOW);
    }
   
    if (distance > 5 || distance <= 0){
      Serial.println("Out of range");
      noTone(buzzer);
    }
    else {
      //Serial.print(distance);
      /Serial.println(" cm");
      tone(buzzer, sound);
     
    }
    delay(300);
  }
