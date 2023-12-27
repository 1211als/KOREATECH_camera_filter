int lastsens, currentsens = 0;
int lastsens2, currentsens2 = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentsens = digitalRead(7);  //forward
  if(lastsens == 0 && currentsens == 1){
    digitalWrite(4, HIGH);
    for(int i = 0; i < 67; i++){
      digitalWrite(5, HIGH);
      delayMicroseconds(6200);
      digitalWrite(5, LOW);
      delayMicroseconds(6200);
    }
  }
  lastsens = currentsens;

  currentsens2 = digitalRead(6);  //reverse
  if(lastsens2 == 0 && currentsens2 == 1){
    digitalWrite(4, LOW);
    for(int i = 0; i < 67; i++){
      digitalWrite(5, HIGH);
      delayMicroseconds(6200);
      digitalWrite(5, LOW);
      delayMicroseconds(6200);
    }
  }
  lastsens2 = currentsens2;
}
