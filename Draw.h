#pragma once

#include "Classes.h"

TriVertex getPixelsForNormalizeedValues(Window* window, int* data);

QuadVertex getPixelsForNormalizeedValuesQuad( std::vector<std::vector<char>> &buffer, std::vector<float> data);

void fragmentShader(int color, bool space);
void drawRect(std::vector<std::vector<int>> &buffer, Rect* rect);
void renderWindowBorder(std::vector<std::vector<int>> &buffer);
void drawTri(Window* window, int* data);
void drawCircle(Window* window, Circle* circle);
void drawLine(Window* window, int* data);
void drawVector(Window* window, std::vector<std::vector<int>> &pixelArray);
void clearVector(std::vector<std::vector<int>> &buffer);