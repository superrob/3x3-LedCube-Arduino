void snakeing () {
  byte lastSnake[3] = {0,0,0};
  byte snake[3] = {0,1,0};
  byte lastDir = 0;
  byte dir;
  boolean success = false;
  boolean firstRun = false;
  switchBit(lastSnake[0], lastSnake[1], lastSnake[2], 1);
  switchBit(snake[0], snake[1], snake[2], 1);
  drawCube();
  for (byte j=0; j<175; j++) {
    for (byte i=0; i<7; i++) {
      drawCube(); // Lets just draw the cube to waste some time.
    }
    switchBit(lastSnake[0], lastSnake[1], lastSnake[2], 0);
    lastSnake[0] = snake[0];
    lastSnake[1] = snake[1];
    lastSnake[2] = snake[2];
    success = false;
    firstRun = true;
    while (!success) {
      if (firstRun) {
        dir = lastDir;
        firstRun = false;
      } else {
        dir = random(1,7);
        while (dir == 1 && lastDir == 2 || dir == 2 && lastDir == 1 || dir == 3 && lastDir == 4 || dir == 4 && lastDir == 3 || dir == 5 && lastDir == 6 || dir == 6 && lastDir == 5) {
          dir = random(1,7);
        }
      }
      if (dir == 1) {
        if (snake[0] < 2 && lastSnake[0] != snake[0] + 1) {
          snake[0] += 1;
          success = true;
        }
      }
      if (dir == 2) {
        if (snake[0] > 0 && lastSnake[0] != snake[0] - 1) {
          snake[0] -= 1;
          success = true;
        }
      }
      if (dir == 3) {
        if (snake[1] < 2 && lastSnake[1] != snake[1] + 1) {
          snake[1] += 1;
          success = true;
        }
      }
      if (dir == 4) {
        if (snake[1] > 0 && lastSnake[1] != snake[1] - 1) {
          snake[1] -= 1;
          success = true;
        }
      }
      if (dir == 5 && lastSnake[2] != snake[2] + 1) {
        if (snake[2] < 2) {
          snake[2] += 1;
          success = true;
        }
      }
      if (dir == 6 && lastSnake[2] != snake[2] - 1) {
        if (snake[2] > 0) {
          snake[2] -= 1;
          success = true;
        }
      }
    }
    lastDir = dir;
    switchBit(snake[0], snake[1], snake[2], 1);
    drawCube();
  }
}
