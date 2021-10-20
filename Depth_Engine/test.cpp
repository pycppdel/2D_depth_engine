#include "SDL_ALL.h"
#include "utils.h"
#include <iostream>

void draw(struct Display*);

int main(){
  SDL_Rect rect = {0, 0, 200, 200};
  SDL_MANAGER manager(&rect);
  manager.init("F");
  manager.setDrawMethod(draw);
  bool quit = false;

  SDL_Event e;

  while (!quit){

    SDL_PollEvent(&e);

    switch(e.type){
      case SDL_QUIT:
        	         	quit = true;
                    break;
    }

    manager.draw();
  }

  manager.deinit();


  return 0;
}


void draw(struct Display* display){
  SDL_Renderer* r = display->renderer;

  SDL_RenderClear(r);
  SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderPresent(r);
}
