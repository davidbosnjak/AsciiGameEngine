#include "Physics.h"
#include <iostream>
#include <vector>
#include <cmath>
void fallObject(Rect* e, float& baseOffset, const float& gravFieldStrengh)
{
  
  const float forceOfGravity = 0.004f;

  moveRect(e, 's', baseOffset);
  if(baseOffset <0.3)
  {
    baseOffset +=forceOfGravity;
    std::cout<<baseOffset<<std::endl;
  }
  else
  {
    std::cout<<"terminal velocity!"<<std::endl;

    baseOffset = baseOffset;
    
  }

}
void throwObject(Rect* e, Vector2 movX, Vector2 movY)
{
  moveRect(e, movX.direction, movX.size);
  moveRect(e,movY.direction, movY.size);
}
void onCollision(Rect* e, char dir)
{
  
}
void rollObject(Rect* e, float friction, float& baseOffset)
{
  moveRect(e, 'd', baseOffset);
  if(baseOffset - friction >0){
    baseOffset -=friction;
  }
  else
  {
    baseOffset = 0;
  }
  
}
//pass an array of arrays containing vertices for other objects. this will then check once per frame if they intersect and if so it will add a bool and a char to the return vector containing whether there was a collision and what direction it collidded.
char checkCollisionWithShape(Rect* r, std::vector<float> data)
{   
    //check collision 
    if(r->data[6]>=data[0] && r->data[0]<data[6]&& r->data[7]<data[5] && r->data[5]> data[7])
    {
        //check direction
        //std::cout<<"shapes collided "<<std::endl;
        if(std::abs(r->data[6]-data[0])< std::abs(r->data[0]-data[6]) && std::abs(r->data[6]-data[0]) <std::abs(r->data[7]-data[5])&& std::abs(r->data[6]-data[0])<std::abs(r->data[5]-data[7]))
        {
            //std::cout<<"collision right"<<std::endl;
            return 'd';
        }
        else if(std::abs(r->data[0]-data[6])<std::abs(r->data[7]-data[5]) && std::abs(r->data[0]-data[6])<std::abs(r->data[5]-data[7]))
        {
            //std::cout<<"collision left"<<std::endl;
            return 'a';
        }
        else if(std::abs(r->data[7]-data[5])<std::abs(r->data[5]-data[7]))
        {
            //std::cout<<"collision down "<<std::endl;
            return 'w';
        }
        else
        {

            //std::cout<<"collision up"<<std::endl;
            return 's';
        }
            
    }
    return ' ';
    
}
char checkCollision(Rect* r,std::vector<std::vector<float>> dataArrays)
{
  bool collided = false;
  for(auto i : dataArrays)
  {
    //if x vals intersect
    if(r->data[0]<=i[0])
    {
      //std::cout<<"collision left"<<std::endl;
      collided = true;
      return 'a';

    }
    if(r->data[1]<=i[1])
    {
      //std::cout<<"collision up"<<std::endl;
      collided = true;
      return 'w';


    }
    if(r->data[6]>=i[6])
    {

      //std::cout<<"collision right"<<std::endl;
      //std::cout<<i[6]<<std::endl;
      //std::cout<<r->data[6]<<std::endl;
      collided = true;
      return 'd';

    }
    if(r->data[5]>=i[5])
    {
      //std::cout<<i[5]<<std::endl;
      //std::cout<<"collision down"<<std::endl;
      collided = true;
      return 's';

    }
  
}
    return ' ';
}
void changeDirectionForCollisionData(char direction, Vector2& up, Vector2& right)
{
    char prevDir = up.direction;
    if(direction == ' ') return;

    if(direction == 'w')
    {
        up.direction = 's';
    }
    else if(direction =='s')
    {
        up.direction = 'w';
    }
    else if(direction == 'a')
    {
        right.direction = 'd';
    }
    else if(direction == 'd')
    {
        right.direction ='a';
    }
    

}

Speed getSpeed(Rect* curr, Rect* prev)
{
    float diffx = curr->data[0] - prev->data[0];
    float diffy = curr->data[1] - prev->data[1];
    std::cout<<"moved "<<diffx<<" in x and "<<diffy<<" in y"<<std::endl;
    return {diffx, diffy};
    
}
