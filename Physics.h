#pragma once
#include "Movement.h"
#include "Classes.h"

void fallObject(Rect* e, float& baseOffset, const float& gravFieldStrength);


void throwObject(Rect* e, Vector2 movX, Vector2 movY);

void rollObject(Rect* e, float friction, float& baseOffset);

void onCollision(Rect* e, char direction);

Speed getSpeed(Rect* curr, Rect* prev);
char checkCollision(Rect* r,std::vector<std::vector<float>> dataArray);
void changeDirectionForCollisionData(char direction, Vector2& up, Vector2& right);
char checkCollisionWithShape(Rect* r, std::vector<float> data);

