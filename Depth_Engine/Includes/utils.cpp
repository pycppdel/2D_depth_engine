#include "utils.h"

//SDL_Manager
SDL_MANAGER::SDL_MANAGER(){

//does nothing
windowSize = NULL;
texturecount = 0;

}

SDL_MANAGER::SDL_MANAGER(SDL_Rect* pos){

  windowSize = pos;
  //does nothing
  texturecount = 0;

}

SDL_MANAGER::~SDL_MANAGER(){


}

bool SDL_MANAGER::init(){

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);

  display.window = SDL_CreateWindow("", windowSize->x, windowSize->y, windowSize->w, windowSize->h, SDL_WINDOW_SHOWN);


  display.renderer = SDL_CreateRenderer(display.window, -1, SDL_RENDERER_ACCELERATED);
  display.screen = SDL_GetWindowSurface(display.window);



  return true;
}

bool SDL_MANAGER::init(std::string name){

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);

  display.window = SDL_CreateWindow(const_cast<char*>(name.data()), windowSize->x, windowSize->y, windowSize->w, windowSize->h, SDL_WINDOW_SHOWN);


  display.renderer = SDL_CreateRenderer(display.window, -1, SDL_RENDERER_ACCELERATED);
  display.screen = SDL_GetWindowSurface(display.window);



  return true;
}

bool SDL_MANAGER::deinit(){



  SDL_DestroyRenderer(display.renderer);
  SDL_FreeSurface(display.screen);

  //delete windowSize;
  SDL_DestroyWindow(display.window);

  //quittinh
  SDL_Quit();
  IMG_Quit();
  return true;
}

void SDL_MANAGER::setDrawMethod(void (*method)(Display*)){

  this->drawmethod = method;

}

void SDL_MANAGER::draw(){

drawmethod(&display);

}


Display* SDL_MANAGER::getDisplay(){

  return &display;

}
