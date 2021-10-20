/*

In this file all the utilities and setup structures for development needed are stored
It includes SDL_ALL automatically

*/

#ifndef SDL_UTILS_ALL
#define SDL_UTILS_ALL
#include "SDL_ALL.h"
#include <list>
#include <string>
//needed: General structures for storing data and interacting

class SDL_MANAGER;
struct Display;

//for storing window, screen as well as the renderer
struct Display{

  SDL_Window* window;
  SDL_Surface* screen;
  SDL_Renderer* renderer;


};


//class for managing all structures
class SDL_MANAGER{

private:

  SDL_Rect* windowSize;
  Display display;
  void (*drawmethod)(Display*);
  int texturecount = 0;

public:
  SDL_MANAGER();
  SDL_MANAGER(SDL_Rect*);
  ~SDL_MANAGER();

  bool init();
  bool init(std::string);
  bool deinit();

  void setDrawMethod(void (*d)(Display*));
  void draw();

  Display* getDisplay();



};



#endif
