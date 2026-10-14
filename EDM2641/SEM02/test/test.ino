int pinVert = 4; 
int pinRouge = 5; 
int pinBleu = 2; 

void setup() {
  pinMode(pinVert, OUTPUT);
  pinMode(pinRouge, OUTPUT);
  pinMode(pinBleu, OUTPUT);
}

void loop() {
  // digitalWrite(pinVert, LOW);
  // digitalWrite(pinRouge, LOW);
  // digitalWrite(pinBleu, LOW);
  // delay(500);
  // digitalWrite(pinVert, HIGH);
  // digitalWrite(pinRouge, LOW);
  // digitalWrite(pinBleu, LOW);
  // delay(500);
  // digitalWrite(pinVert, LOW);
  // digitalWrite(pinRouge, HIGH);
  // digitalWrite(pinBleu, LOW);
  // delay(500);
  // digitalWrite(pinVert, LOW);
  // digitalWrite(pinRouge, LOW);
  // digitalWrite(pinBleu, HIGH);
  // delay(500);


  // for(int r=0; r<256; r++)
  // {
  //   analogWrite(pinRouge, r);
  //   delay(10);
  // }
  //   for(int b=256; b>=0; b--)
  //   {
  //     analogWrite(pinBleu, b);
  //     delay(10);
  //   }

  //  for(int v=0; v<256; v++)
  // {
  //   analogWrite(pinVert, v);
  //   delay(10);

  //  }
  //   for(int r=256; r>=0; r--)
  //   {
  //     analogWrite(pinRouge, r);
  //     delay(10);
  //   }

  //  for(int b=0; b<256; b++)
  // {
  //   analogWrite(pinBleu, b);
  //   delay(10);
  //  }
  //   for(int v=256; v>=0; v--)
  //   {
  //     analogWrite(pinVert, v);
  //     delay(10);
  //   }

  for(int i=0; i<256; i++)
  {
    analogWrite(pinBleu, 255-i);
    analogWrite(pinRouge, i);
    delay(10);
  }
  for(int i=0; i<256; i++)
  {
    analogWrite(pinRouge, 255-i);
    analogWrite(pinVert, i);
    delay(10);
  }
  for(int i=0; i<256; i++)
  {
    analogWrite(pinVert, 255-i);
    analogWrite(pinBleu, i);
    delay(10);
  }
}
