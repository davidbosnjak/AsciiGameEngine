
#define FPS 20
#include "Renderer.h"
//call functions from other files in here 
//while loop runs FPS times per second
void renderer()
{
    //initing stuff
  int windowLength = 75;
  int windowHeight = 35;
  Window window(windowLength, windowHeight);
  std::vector<float> mydata1 = {
        0.4f,0.2f,
        0.4f,0.4f,
        0.6,0.4f,
        0.6f,0.2f
      };
  std::vector<float> mydata2 = {
      0.4f,0.6f,
      0.4f,0.8f,
      0.6f, 0.8f,
      0.6f, 0.6f,
  };
  Rect mysecondRect(mydata2);
  Rect myrect(mydata1);
  
  Rect myrectcopy = myrect;

  float rollOffset = 0.15f;
  float gravOffset = 0.0001f;
  Vector2 up = {'w',0.02};
  Vector2 right = {'d',0.03};
  Vector2 up2 = {'w',0.03};
  Vector2 right2 = {'d',0.05};
    std::vector<std::vector<int>> buffer(
    windowHeight+1,
    std::vector<int>(windowLength+1,0));
    std::vector<float> worldBoundaries = {0,0,0,1,1,1,1,0};
    std::vector<std::vector<float>>  allBoundaries;
    char collision_data;
    char collision_data2;
    char collision_data_with_object;
    char collision_data_with_object2;
    //gameloop: this stuff happens every frame 
  while(true)
  {     
    
    //do this instead of reiniting vector every frame which would be garbage due to a heap allocation every frame would slow down the program a ton 
    clearVector(buffer);
    renderWindowBorder(buffer);
    drawRect(buffer, &myrect);
    drawRect(buffer, &mysecondRect);
    allBoundaries.push_back(worldBoundaries);
    collision_data_with_object2 = checkCollisionWithShape(&mysecondRect, myrect.data);
    collision_data_with_object = checkCollisionWithShape(&myrect, mysecondRect.data);
    collision_data = checkCollision(&myrect, allBoundaries);
    changeDirectionForCollisionData(collision_data_with_object2, up2, right2);
    changeDirectionForCollisionData(collision_data_with_object, up, right);
    changeDirectionForCollisionData(collision_data, up, right);
    changeDirectionForCollisionData(collision_data2, up2, right2);

    collision_data2 = checkCollision(&mysecondRect, allBoundaries);
      //fallObject(&myrect, gravOffset,9.8);
      throwObject(&mysecondRect, up2, right2);
      throwObject(&myrect, up, right);
      //rollObject(&myrect, 0.05f, rollOffset);
      //std::cout<<myrect.data[1]<<std::endl;
      //std::cout<<myrect.data[0]<<std::endl;
      //drawRect(&window, mydata2);
      getSpeed(&myrect, &myrectcopy);
      drawVector(&window, buffer);
      std::this_thread::sleep_for (std::chrono::milliseconds(1000/FPS)); 
      std::system("clear");
      myrectcopy = myrect;


  
}}