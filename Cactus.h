#ifndef CACTUS_H
#define CACTUS_H

#include "Globals.h"

class Cactus{
  private:
    int width;
    int height;
    float x;
    int y;
    int cactus_num;

  public:
    Cactus();
    Cactus(int w, int h, float x_, int y_, int n);
    void setX(float x_);
    void setY(int y_);
    float getX();
    void drawCactus();
};

#endif