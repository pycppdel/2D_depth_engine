
#include "texture.h"
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

  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

}

Texture::Texture(SDL_Renderer* r, std::string p, SDL_Rect* clip, SDL_Rect* rerect){

  path = p;
  render = r;

  load_texture(path, r);

  clip_rect = clip;
  render_rect = rerect;

  alpha = 0;
  rotation_angle = 0;
  colorMod = NULL;


}

Texture::~Texture(){

  delete clip_rect;
  delete render_rect;
  delete colorMod;

  SDL_DestroyTexture(texture);


}

void Texture::rotate(int angle){

rotation_angle += angle;

}

int Texture::set_rotation_angle(int angle){

  int save = rotation_angle;
  rotation_angle = angle;
  return save;
}

uint8_t Texture::set_alpha(uint8_t a){

  uint8_t save = alpha;
  alpha = a;
  SDL_SetTextureAlphaMod(texture, alpha);
  return save;
}

Color* Texture::set_color_mod(Color* c){

  Color* back = colorMod;
  colorMod = c;
  SDL_SetTextureColorMod(texture, colorMod->color[0], colorMod->color[1], colorMod->color[2]);
  return back;
}

SDL_Rect* Texture::set_clip_rect(SDL_Rect* clip){

  SDL_Rect* save = clip_rect;
  clip_rect = clip;
  return save;
}

SDL_Rect* Texture::set_render_rect(SDL_Rect* r){

  SDL_Rect* save = render_rect;
  render_rect = r;
  return save;
}

void Texture::load_image(std::string p, SDL_Renderer* r){

path = p;
render = r;

load_texture(p, r);

}

void Texture::draw(){

SDL_RenderCopyEx(render, texture, clip_rect, render_rect, rotation_angle, NULL, SDL_FLIP_NONE);


}
