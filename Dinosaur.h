#ifndef DINOSAUR_H
#define DINOSAUR_H

#include "Globals.h"

class Dinosaur{
  private:
    // Location
    int x;
    float y;

    // Variables
    bool jump = false;

  public:
    Dinosaur();
    void setJump(bool b);
    void setY(float y_);
    bool getJump();
    float getY();
    void drawDino();
    void drawDino(int y_);
};

inline Dinosaur dino;

#endif 