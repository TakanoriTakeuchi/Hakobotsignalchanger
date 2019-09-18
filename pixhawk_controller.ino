
const int CH1_PIN = A0;
const int CH2_PIN = A1;

const int Rsig = 9;
const int Lsig = 10;

const int Rfbc = 53;
const int Lfbc = 52;

const int Russ = 51;
const int Luss = 50;

int Rvalf;
int Rvalb;
int Lvalf;
int Lvalb;


int CH1_value = 0;
int CH2_value = 0;


void setup() {
  Serial.begin(38400);
  pinMode(CH1_PIN, INPUT);
  pinMode(CH2_PIN, INPUT);
  pinMode(Rsig, OUTPUT);
  pinMode(Lsig, OUTPUT);
  pinMode(Rfbc, OUTPUT);
  pinMode(Lfbc, OUTPUT);
  pinMode(Russ, INPUT);
  pinMode(Luss, INPUT);

}

void loop() {
  if ((Russ != LOW) && (Luss != LOW)) {
    CH1_value = pulseIn(CH1_PIN, HIGH);
    CH2_value = pulseIn(CH2_PIN, HIGH);
    Rvalf = map(CH1_value, 1550, 2000, 10, 245);
    Rvalb = map(CH1_value, 1000, 1450, 245, 10);
    Lvalf = map(CH2_value, 1550, 2000, 10, 245);
    Lvalb = map(CH2_value, 1000, 1450, 245, 10);


    if (CH1_value > 1550) {
      analogWrite( Rsig, Rvalf);
      digitalWrite(Rfbc, LOW);
    
    }
    if ((CH1_value < 1450) && (CH1_value > 0)) {
      analogWrite( Rsig, Rvalb);
      digitalWrite(Rfbc, HIGH);
 
    }
    if (CH2_value > 1550) {
      analogWrite( Lsig, Lvalf);
      digitalWrite(Lfbc, LOW);

    }
    if ((CH2_value < 1450) && (CH2_value > 0)) {
      analogWrite( Lsig, Lvalb);
      digitalWrite(Lfbc, HIGH);

    }
    if ((CH1_value >= 1450) && (CH1_value <= 1550) || (CH1_value = 0)) {
      analogWrite( Rsig, 10);
      digitalWrite(Rfbc, HIGH);
    }
    if ((CH2_value >= 1450) && (CH2_value <= 1550) || (CH2_value = 0)) {
      analogWrite( Lsig, 10);
      digitalWrite(Lfbc, HIGH);
    }

  }

  if ((Russ == LOW) && (Luss != LOW)) {
    CH1_value = pulseIn(CH1_PIN, HIGH);
    CH2_value = pulseIn(CH2_PIN, HIGH);
    Rvalf = map(CH1_value, 1550, 2000, 10, 245);
    Rvalb = map(CH1_value, 1000, 1450, 245, 10);
    Lvalf = map(CH2_value, 1550, 2000, 10, 245);
    Lvalb = map(CH2_value, 1000, 1450, 245, 10);


    if (CH1_value > 1550) {
      analogWrite( Rsig, Rvalf);
      digitalWrite(Rfbc, LOW);
    }
    if ((CH1_value < 1450) && (CH1_value > 0)) {
      analogWrite( Rsig, Rvalb);
      digitalWrite(Rfbc, HIGH);
    }
    if (CH2_value > 1550) {
      analogWrite( Lsig, Lvalf);
      digitalWrite(Lfbc, LOW);
    }
    if ((CH2_value < 1450) && (CH2_value > 0)) {
      analogWrite( Lsig, Lvalb);
      digitalWrite(Lfbc, HIGH);
    }
    if ((CH1_value >= 1450) && (CH1_value <= 1550) || (CH1_value = 0)) {
      analogWrite( Rsig, 10);
      digitalWrite(Rfbc, HIGH);
    }
    if ((CH2_value >= 1450) && (CH2_value <= 1550) || (CH2_value = 0)) {
      analogWrite( Lsig, 10);
      digitalWrite(Lfbc, HIGH);
    }
  }


  Serial.print(pulseIn(Rsig, HIGH) / 51 / 4);
  Serial.print("&");
  Serial.print(pulseIn(Lsig, HIGH) / 51 / 4);
  Serial.print("&");
  Serial.print(digitalRead(Russ));
  Serial.print("&");
  Serial.print(digitalRead(Luss));
  Serial.println("");
  delay(100);






}
