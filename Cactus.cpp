#include "Cactus.h"

Cactus::Cactus(){
    width = 0; 
    height = 0; 
    x = 0; 
    y = 0; 
    cactus_num = 0;
  }

Cactus::Cactus(int w, int h, float x_, int y_, int n){
    width = w; 
    height = h; 
    x = x_; 
    y = y_; 
    cactus_num = n;
  }

void Cactus::setX(float x_){
  x = x_;
  return;
}

float Cactus::getX(){
  return x;
}

void Cactus::setY(int y_){
  y = y_;
  return;
}

void Cactus::drawCactus(){
  display.drawBitmap((int)x, 63 - y - height, cactus_1, width, height, 1);
  return;
}





