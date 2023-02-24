const int triggerPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   int duration, cm;
   
   pinMode(triggerPin, OUTPUT);
   digitalWrite(triggerPin, LOW);
   
   delayMicroseconds(2);
   
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(triggerPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   //Serial.println(cm);
   Serial.write((byte *) &cm, 4);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
/*
Serial.write((byte *) &pream, 4);
          Serial.write((byte *) &timer_lab, 4);
*/