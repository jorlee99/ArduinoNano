int C = 5;
int Cs = 6;
int D = 7;
int E = 8;
int F = 9;
int G = 10;
int A = 11;
int B = 12;
int change = 4;
int speaker = 3;
int buttonstate = 0;
int toggle = 0;
int shite = 0;

int buttonstate_C = 0;
int buttonstate_Cs = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;
int buttonstate_G = 0;
int buttonstate_A = 0;
int buttonstate_B = 0;
int buttonstate_change = 0;

int melody1[] = {0, 784, 880, 698, 0, 784, 0, 0, 932, 880, 698, 0, 784, 0, 0, 784, 880, 698, 0, 784, 0, 0, 932, 880, 698, 0, 784, 0, 0, 784, 880, 698, 0, 784, 0, 0, 932, 880, 698, 0, 784, 0, 0, 784, 880, 698, 0, 784, 0, 0, 932, 880, 698, 0, 784, 0};
int noteDurations1[] = {8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16, 8, 8, 16, 16, 16, 2, 16};

int melody2[] = {493, 493, 493, 493, 493, 0, 0, 587,493, 493, 493, 493, 493, 0, 0, 587,493, 493, 493, 493, 493, 0, 0, 587,493, 493, 493, 493, 493, 0, 0, 587,493, 493, 493, 493, 493, 0, 493, 493, 493, 493, 493, 0, 493, 493, 493, 493, 493, 0, 493, 493, 493, 493, 493, 0,493, 493, 493, 493, 493,493, 493, 493, 493, 493,493, 493, 493, 493, 493,493, 493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493,493, 493, 493, 493};
int noteDurations2[] = {16,16,16,16,4,1,4,4,16,16,16,16,4,1,4,4,16,16,16,16,4,1,4,4,16,16,16,16,4,1,4,4,16,16,16,16,4,2,16,16,16,16,4,2,16,16,16,16,4,2,16,16,16,16,4,2,16,16,16,16,4,16,16,16,16,4,16,16,16,16,4,16,16,16,16,4,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};

int melody3[]= {493,493,493,493,493,493,493,493,493,493,493,493,659,659,659,659,659,659,659,587,587,587,587,587,587,587,440,493,493,493,493,493,493,493,493,493,493,493,493,659,659,493,493,493,493,493,493,493,493,493,493,493,493,659,659,659,493,493,493,493,493,493,493,493,493,493,493,493,659,659};
int noteDurations3[] = {16,16,16,16,8,16,16,16,16,16,16,8,16,16,16,16,16,16,8,16,16,16,16,16,16,8,8,16,16,16,16,8,16,16,16,16,16,16,8,16,16,16,16,16,16,8,16,16,16,16,16,16,8,16,16,1616,16,16,16,8,16,16,16,16,16,16,8,16,16};

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

void setup() {
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(Cs, INPUT);
  pinMode(change, INPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  buttonstate = digitalRead(change);
  buttonstate_C = digitalRead(C);
  buttonstate_Cs = digitalRead(Cs);
  buttonstate_D = digitalRead(D);
  buttonstate_E = digitalRead(E);
  buttonstate_F = digitalRead(F);
  buttonstate_G = digitalRead(G);
  buttonstate_A = digitalRead(A);
  buttonstate_B = digitalRead(B);
  Serial.println(digitalRead(change));
  if (buttonstate == LOW)
  {
    delay(300);
    toggle = toggle + 1;
    shite = 1;
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
    case 0:    // manual mode
      { Serial.println("Manual mode");
        if (buttonstate_C == HIGH)     // Ab
        {
          tone(speaker, 415);
        }

        else if (buttonstate_Cs == HIGH)   // Bb
        {
          tone(speaker, 466);
        }

        else if (buttonstate_D == HIGH)   // C
        {
          tone(speaker, 523);
        }

        else if (buttonstate_E == HIGH)   // Db
        {
          tone(speaker, 554);
        }

        else if (buttonstate_F == HIGH)   // Eb
        {
          tone(speaker, 622);
        }

        else if (buttonstate_G == HIGH)   // F
        {
          tone(speaker, 698);
        }

        else if (buttonstate_A == HIGH)   // G
        {
          tone(speaker, 784);
        }

        else if (buttonstate_B == HIGH)           // Ab
        {
          tone(speaker, 831);
        }

        else {
          noTone(speaker);

        }
      }
      break;
    case 1: //song1
      {
        if (shite == 1)
        {
          Serial.println("Song1");
          for (int thisNote = 0; thisNote < 28; thisNote++)
          {
            int noteDuration = 2100 / noteDurations1[thisNote];
            tone(speaker, melody1[thisNote], noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(speaker);
          }
          shite = 0;
        }        if (buttonstate_C == HIGH)
        {
          shite = 1;
        }
      }
      break;

    case 2: //song2
    {
     if (shite == 1)
      {
        Serial.println("Song2");
   for (int thisNote = 0; thisNote < 108; thisNote++)
          {
            int noteDuration = 1400 / noteDurations2[thisNote];
            tone(speaker, melody2[thisNote], noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(speaker);
          }
        shite = 0;
      }
      if (buttonstate_C == HIGH)
      {
        shite=1;
      }
    }
      break;

    case 3:
     {
     if (shite == 1)
      {
        Serial.println("Song3");
         for (int thisNote = 0; thisNote < 55; thisNote++)
          {
            int noteDuration = 1400 / noteDurations3[thisNote];
            tone(speaker, melody3[thisNote], noteDuration);
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            noTone(speaker);
          }
        shite = 0;
      }
      if (buttonstate_C == HIGH)
      {
        shite=1;
      }
    }
      break;
  }
}


