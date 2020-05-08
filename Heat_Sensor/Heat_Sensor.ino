
int red = 11;
int green = 10;
int blue = 9;
int button = 3;             //Pushbutton Pin
int toggle = 0;              //Variable to store case toggle mode
int buttonstate = 0;//Is the button pressed or not?
int tempPin = A1;
int temp;
int voltage = 4.45; 
int tempTotal;
int x;
int redl;
int bluel;


//Millis Stuff
int changeState = 0;         // Will change to next state after interval
long previousMillis = 0;     // will store last time Millis was updated
long interval = 1000;        // Change rate

void setup() { 
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT);
 pinMode(tempPin, INPUT);
 
  Serial.begin(9600);

}

void loop() {
 buttonstate = digitalRead(button);

  if (buttonstate == HIGH)
  {
    delay(300);
    toggle = toggle + 1;
  }

  if (toggle > 6)
  {
    delay(150);
    toggle = 0;
  }

  else {
  }

  switch (toggle)
  {
    case 0: //off
    {
    digitalWrite (red, LOW);
    digitalWrite (green, LOW);
    digitalWrite (blue, LOW);
  }
  break;
  case 1:
  Serial.println("red");
  {
    digitalWrite (red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  break;
  case 2:
  Serial.println("green");
  {
    digitalWrite (red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
  break;
  case 3:
  Serial.println("blue");
  {
    digitalWrite (red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  break;
  
  case 4: //off
    {
    digitalWrite (red, LOW);
    digitalWrite (green, LOW);
    digitalWrite (blue, LOW);
  }
  break;
case 5: 

 {
    tempTotal = 0;//  clear the accumulator
  //  Read the ADC 64 times and compute a total
  for(x = 0; x < 30; x++) {    
    tempTotal += analogRead(tempPin);
  }

  temp = tempTotal/30;
  temp = (voltage * temp * 100) / 1024; //mv to decimal
  
Serial.println(temp);


  redl = map(temp, 0, 30, 0, 255);
  bluel = map(temp, 0, 30, 255, 0);
  analogWrite(red,redl);
analogWrite(blue,bluel);
}

  break;
  case 6:
  
  //Millis stuff
  unsigned long currentMillis = millis();           //Save the time since start to currentMillis variable

  if(currentMillis - previousMillis > interval)     //Compare Current time to the last recorded time to see if interval has elapsed
  {
  previousMillis = currentMillis;                   //Save new previousMillis value
  changeState = 0;                    //If time has elapsed changeState +1 to switch thru modes
  }
  Serial.println("fade");
  { 
    if (changeState == 0) {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(red, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(red, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(green, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

    }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(green, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(blue, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(blue, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  break;
    

  }
  }
  }

