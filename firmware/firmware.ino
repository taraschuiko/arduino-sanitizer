#define relay 2
#define distanceTrig 9
#define distanceEcho 10

long duration;
long distance;

// Configurations
int dispenseDuration = 200;
int waitAfterDispense = 2000;
int dispenseWhenDistanceIsLowerThan = 10;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(distanceTrig, OUTPUT);
  pinMode(distanceEcho, INPUT);
}

void loop() {
  digitalWrite(relay, HIGH);
  
  digitalWrite(distanceTrig, LOW);
  delayMicroseconds(5);
  digitalWrite(distanceTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(distanceTrig, LOW);

  duration = pulseIn(distanceEcho, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < dispenseWhenDistanceIsLowerThan) {
    digitalWrite(relay, LOW);
    delay(dispenseDuration);
    digitalWrite(relay, HIGH);
    delay(waitAfterDispense);
  }

  delay(500);
}
