#include "color.h"

Color::Color(){

  for(int i=0;i<3;i++){
    color[i] = 0x00;
  }
}

Color::Color(uint8_t x1, uint8_t x2, uint8_t x3){

  color[0] = x1;
  color[1] = x2;
  color[2] = x3;

}

Color::~Color(){

}
