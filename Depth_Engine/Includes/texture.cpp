
#include "texture.h"
#include <iostream>
/*
cpp file for texture
*/

Texture::Texture(){

  path = "";
  texture = NULL;
  render = NULL;

  clip_rect = NULL;
  render_rect = NULL;

  alpha = 0;
  rotation_angle = 0;
  colorMod = NULL;

}

Texture::Texture(SDL_Renderer* r, std::string p){

path = p;
render = r;

load_texture(path, r);

clip_rect = NULL;
render_rect = NULL;

alpha = 0;
rotation_angle = 0;
colorMod = NULL;

}

void Texture::load_texture(std::string p, SDL_Renderer* r){

  SDL_Surface* s = IMG_Load(const_cast<char*>(p.data()));

  //making texture
  texture = SDL_CreateTextureFromSurface(r, s);

  SDL_FreeSurface(s);

}

Texture::Texture(SDL_Renderer* r, std::string p, SDL_Rect* clip, SDL_Rect* rerect){

  path = p;
  render = r;

  load_texture(path, r);

  clip_rect = clip;
  rerect = rerect;

  alpha = 0;
  rotation_angle = 0;
  colorMod = NULL;


}

Texture::~Texture(){

}

void Texture::rotate(int angle){

}

int Texture::set_rotation_angle(int angle){

  return 0;
}

uint8_t Texture::set_alpha(uint8_t a){

  return 0;
}

Color& Texture::set_color_mod(Color& c){

  return Color(0, 0, 0, 0);
}

SDL_Rect& Texture::set_clip_rect(SDL_Rect& clip){

  return SDL_Rect();
}

SDL_Rect& Texture::set_render_rect(SDL_Rect& r){

  return SDL_Rect();
}

void Texture::draw(){


}
