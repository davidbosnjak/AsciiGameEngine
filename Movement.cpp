#include "Movement.h"
#include <iostream>
void moveRect(Rect* r, char direction, float movementOffset)
{
  switch(direction)
  {
    case 'a':
      r->data[0] = r->data[0] - movementOffset;
      r->data[2] = r->data[2] - movementOffset;
      r->data[4] = r->data[4] - movementOffset;
      r->data[6] = r->data[6] - movementOffset;
      break;
    case 'd':
     
      r->data[0] = r->data[0] + movementOffset;
      r->data[2] = r->data[2] + movementOffset;
      r->data[4] = r->data[4] + movementOffset;
      r->data[6] = r->data[6] + movementOffset;
      break;
    case 'w':
      r->data[1] = r->data[1] - movementOffset;
      r->data[3] = r->data[3] - movementOffset;
      r->data[5] = r->data[5] - movementOffset;
      r->data[7] = r->data[7] - movementOffset;
      break;
          
    case 's':
          r->data[1] = r->data[1] + movementOffset;
          r->data[3] = r->data[3] + movementOffset;
          r->data[5] = r->data[5] + movementOffset;
          r->data[7] = r->data[7] + movementOffset;
          break;
    default:
      std::cout<<direction<<" is not a valid direction"<<std::endl;
      break;
  }
}
void MovementController(Rect* r, float offset)
{

    char direction;
    std::cin>>direction;
    float movementOffset = offset;
    
    
      moveRect(r, direction, movementOffset);


    
}


