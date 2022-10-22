
int ifMoistureIsBiggerThan = 700;
int numberOfReadingsAboveTreshold = 0;

int wateringTimeInSeconds = 120;
void setup() {

  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(9, LOW);
}

void loop() {
 
if(analogRead(A0) > ifMoistureIsBiggerThan){
  numberOfReadingsAboveTreshold += 1;
}else{
  numberOfReadingsAboveTreshold = 0;
}

if(numberOfReadingsAboveTreshold == 10){
  numberOfReadingsAboveTreshold = 0;
  digitalWrite(9, HIGH);

  for(int a = 0; a < wateringTimeInSeconds; a++){
    delay(1000);
  }
  digitalWrite(9, LOW);
}

delay(10 * 1000);
}


