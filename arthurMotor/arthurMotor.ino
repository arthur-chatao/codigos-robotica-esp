int dir1Pin1 = 27; 
int dir1Pin2 = 26; 
int direnable1Pin = 14; 

int esq1Pin1b = 32; 
int esq1Pin2b = 33; 
int esqenable1Pin2 = 25; 



// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;


const int pwmChannelB = 1;
int dirdutyCycle = 255;
int esqdutyCycleB = 255;

void setup() {
  // sets the pins as outputs:
  pinMode(dir1Pin1, OUTPUT);
  pinMode(dir1Pin2, OUTPUT);
  pinMode(esq1Pin1b, OUTPUT);
  pinMode(esq1Pin2b, OUTPUT);
  pinMode(direnable1Pin, OUTPUT);
  pinMode(esqenable1Pin2, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(pwmChannelB, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(direnable1Pin, pwmChannel);
  ledcAttachPin(esqenable1Pin2, pwmChannelB);
 // ledcAttachPin(enable1Pin2, pwmChannel);


  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {
  Serial.println("Motor stopped");
  digitalWrite(dir1Pin1, LOW);
  digitalWrite(dir1Pin2, LOW);
  digitalWrite(esq1Pin1b, LOW);
  digitalWrite(esq1Pin2b, LOW);
  
  delay(1000);
  
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  ledcWrite(pwmChannel,dirdutyCycle);
  ledcWrite(pwmChannelB, esqdutyCycleB); 
  digitalWrite(dir1Pin1, LOW);
  digitalWrite(dir1Pin2, HIGH);
  digitalWrite(esq1Pin1b, LOW);
  digitalWrite(esq1Pin2b, HIGH);
  
  
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(dir1Pin1, LOW);
  digitalWrite(dir1Pin2, LOW);
  digitalWrite(esq1Pin1b, LOW);
  digitalWrite(esq1Pin2b, LOW);
  
  delay(1000);
  dirdutyCycle = 200;
  esqdutyCycleB = 255;
  ledcWrite(pwmChannel,dirdutyCycle);
  ledcWrite(pwmChannelB, esqdutyCycleB); 
  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(dir1Pin1, HIGH);
  digitalWrite(dir1Pin2, LOW);
  digitalWrite(esq1Pin1b, HIGH);
  digitalWrite(esq1Pin2b, LOW);
  
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(dir1Pin1, LOW);
  digitalWrite(dir1Pin2, LOW);
  digitalWrite(esq1Pin1b, LOW);
  digitalWrite(esq1Pin2b, LOW);
  
  delay(1000);

 /* // Move DC motor forward with increasing speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin1b, HIGH);
  digitalWrite(motor1Pin2b, LOW);*/
  
  /*while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
    ledcWrite(pwmChannelB, dutyCycleB); 
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    Serial.print(dutyCycleB);
    dutyCycle = dutyCycle + 5;
    dutyCycleB = dutyCycleB + 5;
    delay(500);
  }
  dutyCycle = 200;
  dutyCycleB = 200;
  */
}
