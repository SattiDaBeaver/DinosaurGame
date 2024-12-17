#include "Dinosaur.h"
#include "Globals.h"

Dinosaur::Dinosaur(){
  x = DINO_X;
  y = FLOOR;
  jump = false;
}

void Dinosaur::setJump(bool b){
  jump = b;
  return;
}

void Dinosaur::setY(float y_){
  y = y_;
  return;
}

bool Dinosaur::getJump(){
  return jump;
}

float Dinosaur::getY(){
  return y;
}

void Dinosaur::drawDino(){
  display.drawBitmap(x, 63 - (int)y - DINO_HEIGHT, dino_1, DINO_WIDTH, DINO_HEIGHT, 1);
  return;
}

void Dinosaur::drawDino(int y_){
  display.drawBitmap(x, 63 - y_ - DINO_HEIGHT - y, dino_1, DINO_WIDTH, DINO_HEIGHT, 1);
  return;
}