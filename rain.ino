void rain() {
  switchBit(2, random(0,3), random(0,3), 1);
  drawCube();
  byte randX = 0;
  byte randY = 0;
  for (long j=0; j<85; j++) {
    for (byte i=0; i<16; i++) {
      drawCube(); // Lets just draw the cube to waste some time.
    }
    for (byte i=0; i< PINCOUNT; i++) {      
      layerOne[i] = layerTwo[i];
      layerTwo[i] = layerThree[i];
      layerThree[i] = 0;
    }
    
    while (getBit(0, randX, randY) == 1 || getBit(1, randX, randY) == 1 || getBit(2, randX, randY) == 1) {
      randX = random(0,3);
      randY = random(0,3);
    }
    switchBit(2, randX, randY, 1);
    drawCube();
  }
}
