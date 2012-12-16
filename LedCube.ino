#define LAYERS 3
#define PINCOUNT LAYERS*LAYERS

byte layerPins[LAYERS] = {2,3,4};
byte rowPins[PINCOUNT] = {22,23,24,25,26,27,28,29,30};

byte layerOne[PINCOUNT] = {0,0,0,0,0,0,0,0,0};
byte layerTwo[PINCOUNT] = {0,0,0,0,0,0,0,0,0};
byte layerThree[PINCOUNT] = {0,0,0,0,0,0,0,0,0};

void setup() {
  randomSeed(analogRead(0));
  for (byte i= 0; i < LAYERS; i++)
    {
        pinMode(layerPins[i], OUTPUT);
        digitalWrite(layerPins[i], LOW);
    }
    
    for (byte i= 0; i < LAYERS*3; i++)
    {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], LOW);
    }
}

void loop() {
  for (byte i=0; i<35; i++) {
    for (byte j=0; j<20; j++) {
      switchBit(random(0,3), random(0,3), random(0,3), 1);
      drawCube();
    }
    turnOff();
    drawCube(); 
  }
  rain();
  turnOff();
  drawCube();

  snakeing();
  turnOff();
  drawCube(); 
}

void switchBit(byte layer, byte x, byte y, byte newState) {
  byte col = x + y*3;
  if (layer == 0) {
    layerOne[col] = newState;
  }
  if (layer == 1) {
    layerTwo[col] = newState;
  }
  if (layer == 2) {
    layerThree[col] = newState;
  }
}

byte getBit(byte layer, byte x, byte y) {
  byte col = x + y*3;
  if (layer == 0) {
    return layerOne[col];
  }
  if (layer == 1) {
    return layerTwo[col];
  }
  if (layer == 2) {
    return layerThree[col];
  }
}

void turnOff () {
  for (byte i=0; i< PINCOUNT; i++) {
    layerOne[i] = 0;
    layerTwo[i] = 0;
    layerThree[i] = 0;
  }
}

void drawCube() {
  digitalWrite(layerPins[0], HIGH);
  for (byte i=0; i< PINCOUNT; i++) {
     if (layerOne[i] == 1) {
       digitalWrite(rowPins[i], HIGH);
     }
     delayMicroseconds(225);
     digitalWrite(rowPins[i], LOW);
  }
  digitalWrite(layerPins[0], LOW);
  
  digitalWrite(layerPins[1], HIGH);
  for (byte i=0; i< PINCOUNT; i++) {
     if (layerTwo[i] == 1) {
       digitalWrite(rowPins[i], HIGH);
     }
     delayMicroseconds(225);
     digitalWrite(rowPins[i], LOW);
  }
  digitalWrite(layerPins[1], LOW);
  
  digitalWrite(layerPins[2], HIGH);
  for (byte i=0; i< PINCOUNT; i++) {
     if (layerThree[i] == 1) {
       digitalWrite(rowPins[i], HIGH);
     }
     delayMicroseconds(225);
     digitalWrite(rowPins[i], LOW);
  }
  digitalWrite(layerPins[2], LOW);
}
