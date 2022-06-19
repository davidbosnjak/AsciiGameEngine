#pragma once
#include <vector>
#include <string>
class Window
{
  public:
  int m_windowHeight;
  int m_windowLength;

  public:
    Window(int windowHeight, int windowLength)
      :m_windowHeight(windowHeight), m_windowLength(windowLength)
    {

    }
};
struct Speed
{
    float deltaX;
    float deltaY;
};
struct Vector2
{
  char direction;
  float size;
};
struct CheckCollisionData
{
  bool collision;
  char direciton;
};
struct Vertex2
{
    float x,y;

};
class Entity
{
public:

  double weight;
  std::string type;
  Entity()
  {
    type = "Entity";
    weight = 10;
  }


};

class Player :Entity
{
  public:
  char sprite[10][10];
  Player()
  {
    type = "Player";

  }
};

class Circle : Entity{
public: 
  float diameter;
  Vertex2 middlePosition;

  Circle(float dia, Vertex2 midpos)
  {
    type = "Circle";

    diameter = dia;
    middlePosition = midpos;
  }

};

class Rect : Entity
{
public:

  std::vector<float> data;
public:
  Rect(std::vector<float> mydata)
  {
    type = "Rect";
    data = mydata;
  }

};

struct QuadVertex
{
  Vertex2 a,b,c,d;
};
struct TriVertex
{
  Vertex2 a,b,c;
};