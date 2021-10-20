#include "utils.h"
#include "texture.h"

void draw(struct Display*);

int main(){

  SDL_Rect rect = {100,100, 800, 800};
  SDL_MANAGER manager(&rect);
  manager.init("D");

  manager.setDrawMethod(draw);

  bool quit = false;
  SDL_Event e;

  t.load_image("fire.png", manager.getDisplay()->renderer);
  SDL_Rect clip = {0, 0, 100, 100};

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
t.draw();
SDL_RenderPresent(r);

}
