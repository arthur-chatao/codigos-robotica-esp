// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int esquerda_e = 35;
const int esquerda = 34;
const int centro = 13;
const int direita = 15;
const int direita_d = 2;

int lido_dd, lido_d, lido_c, lido_e, lido_ee;
// variable for storing the potentiometer value

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  lido_dd = analogRead(direita_d);
  lido_d = analogRead(direita);
  lido_c = analogRead(centro);
  lido_e = analogRead(esquerda);
  lido_ee = analogRead(esquerda_e);
  
  Serial.print(lido_dd);
  Serial.print("        ");
  Serial.print(lido_d);
  Serial.print("        ");
  Serial.print(lido_c);
  Serial.print("        ");
  Serial.print(lido_e);
  Serial.print("        ");
  Serial.print(lido_ee);
  Serial.print("        ");
  Serial.println("");
  delay(500);
}

