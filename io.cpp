#include "io.h"
#include "Dinosaur.h"

void updateJump(){
  dino.setJump(true);
  return;
}

bool getInput() {
  return !digitalRead(BUTTON);
}