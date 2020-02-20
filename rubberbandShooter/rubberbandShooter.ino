const int pResistor = A0;
const int limit = 40;
int value;


void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  digitalWrite(9, HIGH);
}

void loop() {
  value = analogRead(pResistor);
  Serial.println(value);
  delay(100);

  if(value >= limit){
    shoot();
  }
}

void shoot(){
    digitalWrite(9, LOW); //Disengage brake
    analogWrite(3, 255);  //Spin motor at full speed
    delay(3000);           //Wait 0.5 sec
    digitalWrite(9, HIGH); //Engage brake
    analogWrite(3, 0);  //Set motor speed to 0
}
