// Include Header Files
#include "Globals.h"
#include "Dinosaur.h"
#include "Cactus.h"
#include "io.h"

// Define
#define MAX 15

// Cacti
Cactus cactus(CACTUS_1_WIDTH, CACTUS_1_HEIGHT, 100, FLOOR, 1);

// Variables
long timeMillis = 0;
int count = 0;
int score = 0;

// Function Prototypes
void drawFrame();
void updateDino(int n, int max);
bool updateCactus(float deltaX);
bool detectCollision();
bool doGame();
void drawEndFrame();
void gameReset();

// Main Functions

void setup() {
  display.begin(0x02, SCREEN_ADDRESS);

  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2) , updateJump, FALLING);

  display.clearDisplay();

  display.setTextColor(WHITE);
  display.setTextWrap(true);
  display.setTextSize(2);
  display.setCursor(5, 5);
  display.print("Press \n Button");

  display.display();

  while (digitalRead(BUTTON));
}

void loop() {
  while(doGame()){

  }

  drawEndFrame();

  delay(100);

  while (digitalRead(BUTTON));

  delay(100);
  gameReset();
}

// Functions

void gameReset(){
  dino.setJump(false);
  dino.setY(FLOOR);

  cactus.setX(120);
  cactus.setY(FLOOR);

  score = 0;
  count = 0;
}

void drawEndFrame(){
  String scoreStr = String(score);

  display.clearDisplay();

  dino.drawDino();
  cactus.drawCactus();
  display.drawLine(0, 60, 120, 60, 1);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(54, 2);
  display.print(scoreStr);

  display.fillRect(3, 18, 117, 20, 0);

  display.setTextSize(2);
  display.setCursor(5, 20);
  display.print("Game Over");

  display.display();
}

bool doGame(){
  if (detectCollision()){
    return false;
  }

  if (dino.getJump()){
    if (count == MAX){
      count = 0;
      dino.setJump(false);
    }
    else {
      updateDino(count, MAX);
      count++;
    }
  }

  if (updateCactus(5)){
    score++;
  }

  drawFrame();
  
  delay(5);

  return true;
}

void drawFrame(){
  String scoreStr = String(score);

  display.clearDisplay();

  dino.drawDino();
  cactus.drawCactus();
  display.drawLine(0, 60, 120, 60, 1);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(54, 2);
  display.print(scoreStr);

  display.display();
}

void updateDino(int n, int max){
  if (n == max - 1){
    dino.setY(3);
    return;
  }

  double y = dino.getY();

  n = max / 2 - n;
  double deltaY = ((double) n / max) * 20;
  dino.setY(y + deltaY);
}

bool updateCactus(float deltaX){
  float x = cactus.getX() - deltaX;

  if (x <= -21){
    cactus.setX(128);
    return true;
  }

  cactus.setX(x);
  return false;
}

bool detectCollision(){
  float dinoY = dino.getY();

  int diffX = DINO_X - cactus.getX() + 3;
  if (diffX < 0){
    diffX = -diffX;
  }

  int diffY = dinoY - FLOOR;
  if (diffY < 0){
    diffY = -diffY;
  }

  if (diffX <= DINO_WIDTH - 3 && diffY <= DINO_HEIGHT){
    return true;
  }

  return false;
}


