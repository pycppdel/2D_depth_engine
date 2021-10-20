/*
Advanced Texture Class for SDL
SDL needs to be included first
*/
#ifndef __TEXTURE_SDL__
#define __TEXTURE_SDL__

//check for color

#ifndef __COLOR_SDL__
#include "color.h"
#endif

#ifndef __SDL_ALL__
#include "SDL_ALL.h"
#endif

#include <string>


class Texture{

private:

std::string path;
SDL_Renderer* render;
SDL_Texture* texture;
SDL_Rect *clip_rect, *render_rect;
uint8_t alpha;
int rotation_angle;
Color *colorMod;

void load_texture(std::string, SDL_Renderer*);




public:

  Texture();
  Texture(SDL_Renderer*, std::string);
  Texture(SDL_Renderer*,std::string, SDL_Rect*, SDL_Rect*);
  ~Texture();

  void rotate(int);
  int set_rotation_angle(int);  // gives back old angle
  uint8_t set_alpha(uint8_t);
  Color& set_color_mod(Color&);
  SDL_Rect& set_clip_rect(SDL_Rect&);
  SDL_Rect& set_render_rect(SDL_Rect&);

  void draw();





};
#endif
