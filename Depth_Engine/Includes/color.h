/*


container class for colors

*/

#ifndef __COLOR_SDL__
#define __COLOR_SDL__

#include <cinttypes>

class Color{

public:
uint8_t color[4];

Color();
Color(uint8_t, uint8_t, uint8_t, uint8_t);
~Color();


};

#endif
