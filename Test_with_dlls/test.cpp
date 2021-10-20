#include "SDL_ALL.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include "texture.h"

Texture t;
SDL_Texture* texture;

void draw(struct Display*);

int main(){
  SDL_Rect rect = {100, 100, 800, 800};
  SDL_MANAGER manager(&rect);
  manager.init("F");
  manager.setDrawMethod(draw);
  bool quit = false;
  t.load_image("Unbenannt.png", manager.getDisplay()->renderer);


  SDL_Surface* s = IMG_Load(const_cast<char*>("Unbenannt.png"));

  //making texture
  texture = SDL_CreateTextureFromSurface(manager.getDisplay()->renderer, s);

  SDL_FreeSurface(s);

  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);



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

  SDL_RenderCopy(r, texture, NULL, NULL);

  SDL_RenderPresent(r);
}
