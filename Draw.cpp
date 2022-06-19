#include "Draw.h"
#include <iostream>
TriVertex getPixelsForNormalizeedValues(Window* window, int* data)
{
   //make normalized values into pixel values using window length and height of current instance
  Vertex2 VertexA = {float(window->m_windowLength)*data[0], float(window->m_windowHeight)*data[1]};
  Vertex2 VertexB = {float(window->m_windowLength)*data[2],float(window->m_windowHeight)*data[3]};
  Vertex2 VertexC = {float(window->m_windowLength)*data[4], float(window->m_windowHeight)*data[5]};
  return {VertexA, VertexB, VertexC};
}

QuadVertex getPixelsForNormalizeedValuesQuad(std::vector<std::vector<int>> &buffer, std::vector<float> data)
{
   //make normalized values into pixel values using window length and height of current instance
  int length = buffer[0].size();
  int height = buffer.size();
  Vertex2 VertexA = {float(length)*data[0], float(height)*data[1]};
  Vertex2 VertexB = {float(length)*data[2],float(height)*data[3]};
  Vertex2 VertexC = {float(length)*data[4], float(height)*data[5]};
  Vertex2 VertexD = {float(length)*data[6], float(height)* data[7]};
  return {VertexA, VertexB, VertexC, VertexD};
}

void fragmentShader(int color, bool space)
{
  if(space){
     //std::cout<<color<<' ';
     switch(color)
     {
        case 0:
        std::cout<<' ';
        break;
        case 1:
        std::cout<<"#";
        break;
        //full block
        case 2:
        std::cout<<"\u2588";
        break;
        //horizontal thing
        case 3:
        std::cout<<"\u2550";
        break;
        //vertical thing
        case 4:
        std::cout<<"\u2551";
        break;
        //top left corner
        case 5: 
        std::cout<<"\u2554";
        break;
        //top right corner
        case 6:
        std::cout<<"\u2557";
        break;
        //bottom left corner
        case 7:
        std::cout<<"\u255A";
        break;
        //bottom right corner
        case 8:
        std::cout<<"\u255D";
     }
  }

  
  else
  {
    std::cout<<color;
  }
 
}
void drawRect(std::vector<std::vector<int>> &buffer, Rect* rect)
{
  //std::cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[7]<<std::endl;
  //std::cout<<"issued draw call"<<std::endl;
  //std::cout<<buffer.size()<<std::endl;
  //std::cout<<buffer[0].size()<<std::endl;
  QuadVertex returnValues = getPixelsForNormalizeedValuesQuad(buffer, rect->data);
  //std::cout<<returnValues.a.y<<std::endl;
  //std::cout<<returnValues.c.y<<std::endl;
  //std::cout<<returnValues.c.x<<std::endl;
  //std::cout<<returnValues.a.y<<std::endl;
  //std::cout<<returnValues.b.y<<std::endl;
  //std::cout<<returnValues.b.x<<std::endl;;
  int height = buffer.size();
  int length = buffer[0].size();

  int color = 2;
  for(int i = 0; i<buffer.size(); i++)
  {
    for(int j =0; j<buffer[0].size(); j++)
    {
      //std::cout<<i<<" "<<j<<std::endl;
      
      if(i >= returnValues.a.y && i<=returnValues.c.y)
      {
        if(j>=returnValues.a.x && j<=returnValues.c.x)
        {
                      //fragmentShader(color, false);
          buffer[i][j] = color;
        }
        else
        {
          
        }
      }
      else{
        
              }
    }
    
  }
}
void renderWindowBorder(std::vector<std::vector<int>> &buffer)
{
  
  for(int i = 0; i<buffer.size(); i++)
  {
    for(int j=0; j<buffer[0].size(); j++)
    {
      if(i == 0 || i==buffer.size()-1 || j==0 || j==buffer[0].size()-1)
      {
        //check corners first
        if(i==0 && j==0)
        {
            buffer[i][j] = 5; 
        }
        else if(i == buffer.size()-1 && j==0)
        {
            buffer[i][j] = 7;
        }
        else if(i ==0 && j == buffer[0].size()-1)
        {
            buffer[i][j] = 6;
        }
        else if(i== buffer.size()-1 && j==buffer[0].size() -1)
        {
            buffer[i][j] = 8;
        }
        else if(i==0 || i==buffer.size()-1)
        {
            buffer[i][j] = 3;
        }

        else if(j==0 || j==buffer[0].size()-1)
        {
            buffer[i][j] = 4;
        }

      }
      
    }
  }
}
void drawTri(Window* window, int* data)
{
  TriVertex returnValues= getPixelsForNormalizeedValues(window, data);
  


}
void drawCircle(Window* window, Circle* circle)
{

}



void drawLine(Window* window, int* data)
{

}
void drawVector(Window* window, std::vector<std::vector<int>> &pixelArray)
{
    for(auto i: pixelArray)
    {
        for(auto j: i )
        {
            fragmentShader(j, true);
        }
        std::cout<<std::endl;
    }
}

void clearVector(std::vector<std::vector<int>> &buffer)
{
    for(int i =0; i<buffer.size(); i++)
    {
        for(int j = 0; j<buffer[0].size(); j++)
        {
            buffer[i][j] = 0;
        }
    }
}