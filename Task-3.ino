#define EN 10
#define IN1 9
#define IN2 8

int motor_speed = 0;
int pedal = A0;
const int buttonPin = 2;     
int buttonState = 0; // variable for reading the pushbutton status
void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
  pinMode(pedal,INPUT); // potentiometer pin
  pinMode(buttonPin, INPUT);    // initialize the pushbutton pin as an input:
pinMode(13,OUTPUT);
  
  Serial.begin(9600); 
}

void loop()
{
  digitalWrite(13,HIGH);
  buttonState = digitalRead(buttonPin);
  int pedalValue = analogRead(pedal);
  delay(1000);
  
  if (buttonState == HIGH) {
    buttonState =1;
  } else {
    buttonState =0;
  }
  motor_speed = map(pedalValue, 0, 1024, 0, 255);
 
  Serial.print("RPM: ");
  Serial.println(motor_speed);
  Serial.print("buttonState: ");
  Serial.println(buttonState);
  if( buttonState ==1)
  {
  if(motor_speed >= 0 && motor_speed <= 255)
       {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       analogWrite(EN,motor_speed);
       }
}
if( buttonState ==0)
{
         analogWrite(EN,0);

}
}
