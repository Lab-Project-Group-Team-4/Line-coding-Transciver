int bitsize = 100;
int Data[100];
int Result[100];
void setup() {

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  Serial.begin(115200);
  digitalWrite(8, 1);
}

void loop() {
  for (int j = 0; j < bitsize; j++) {
    Data[j] = rand() % 2;

  }
//  for (int i = 0; i < bitsize; i++) {
//    Serial.print(Data[i]);
//    Serial.print(" ");
//    //delayMicroseconds(1);
//  }
//  Serial.println();

  for (int i = 0; i < bitsize; i++) {
    digitalWrite(8, 1);
    digitalWrite(7, Data[i]);

    delayMicroseconds(50);
    //delay(5);
    digitalWrite(8, 0);
    delayMicroseconds(50);
    //delay(5);
    int a = digitalRead(9);
    Result[i] = a;
    //Serial.print(a);
    //Serial.print(" ");


  }
  //Serial.println();
  int count = 0;
  for (int i = 0; i < bitsize; i++) {
    if (Data[i] != Result[i]) {
      count += 1;
    }
  }
  Serial.print("Number of Errors: ");
  Serial.println(count);
  //delay(10000);


}
