const int TRIG_PIN1 = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN1 = 10; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int TRIG_PIN2 = 11; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN2 = 12; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 3; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 50; // centimeters
const int SPEAKER = 2;

// variables will change:
float duration_us1, distance_cm1,duration_us2, distance_cm2;

void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN1, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN1, INPUT);  // set arduino pin to input mode
  pinMode(TRIG_PIN2, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN2, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode
  pinMode(SPEAKER ,OUTPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  // measure duration of pulse from ECHO pin
  duration_us1 = pulseIn(ECHO_PIN1, HIGH);
  duration_us2 = pulseIn(ECHO_PIN2, HIGH);
  // calculate the distance
  distance_cm1 = 0.017 * duration_us1;
  distance_cm2 = 0.017 * duration_us2;

  if(distance_cm1 < DISTANCE_THRESHOLD){
    digitalWrite(LED_PIN, HIGH); // turn on LED
    tone(2,262,2000);
  delay(2000);
  
  }
  else
  {
    digitalWrite(LED_PIN, LOW);  // turn off LED
  }
  if(distance_cm2 < DISTANCE_THRESHOLD){
    digitalWrite(LED_PIN, HIGH); // turn on LED
    tone(2,294,2000);
  delay(2000);
  
  }
  else
  {
    digitalWrite(LED_PIN, LOW);  // turn off LED
  }
  // print the value to Serial Monitor
  
  delay(100);
}
