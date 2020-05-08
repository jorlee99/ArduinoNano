/* 
Sample code will only turn Red Led on when photocell is covered.
Modify the code so that it will cycle R-G-B under low light.
*/


int redled = A3;
int greenled = 5;
int blueled = 8;
int purpleled1 = 9;
int purpleled2 = 10;
int yellowled1 = 12;
int yellowled2 = A1;
int button = A4;
int buttonstate;
int toggle = 0;

int LDR = 0;
int Light;

// the setup routine runs once when you press reset:
void setup() {                
// initialize the digital pin as an output.
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(purpleled1, OUTPUT);
  pinMode(purpleled2, OUTPUT);
  pinMode(yellowled1, OUTPUT);
  pinMode(yellowled2, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(button, INPUT);
  
  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  Light = analogRead(LDR);
  Serial.println(Light);
  
  buttonstate = digitalRead(button);
  
    if (buttonstate == HIGH)
  {
  delay(200);
  toggle = toggle + 1;
  }
  else if (toggle > 4)
  {
    delay(150);
    toggle = 0;
    
  }
  else{}
  
  
  
  switch (toggle) {

  
    case 0:    // Off
    Serial.println("Off");
  {
    digitalWrite(redled, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, LOW);
      digitalWrite(purpleled1, LOW);
      digitalWrite(purpleled2, LOW);
      digitalWrite(yellowled1, LOW);
      digitalWrite(yellowled2, LOW);
  }
  break;
  
      case 2:    // Red
    Serial.println("Red");
  {
    digitalWrite(redled, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, LOW);
      digitalWrite(purpleled1, LOW);
      digitalWrite(purpleled2, LOW);
      digitalWrite(yellowled1, LOW);
      digitalWrite(yellowled2, LOW);
  }
  break;
  
        case 3:    // Green
    Serial.println("Green");
  {
    digitalWrite(redled, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(greenled, HIGH);
      digitalWrite(blueled, LOW);
      digitalWrite(purpleled1, LOW);
      digitalWrite(purpleled2, LOW);
      digitalWrite(yellowled1, LOW);
      digitalWrite(yellowled2, LOW);
  }
  break;

        case 4:    // Blue
    Serial.println("Blue");
  {
    digitalWrite(redled, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, HIGH);
      digitalWrite(purpleled1, LOW);
      digitalWrite(purpleled2, LOW);
      digitalWrite(yellowled1, LOW);
      digitalWrite(yellowled2, LOW);
  }
  break;  
  
  
  }
}


