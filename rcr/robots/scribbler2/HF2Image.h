#ifndef HF2IMAGE_H
#define HF2IMAGE_H

#include <iostream>
#include <stdint.h>

namespace rcr {
namespace robots {
namespace scribbler2 {

class HF2Image
{
public:
    const int width;
    const int height;
    const uint8_t* image;
    const int imageSize;

public:
    HF2Image( int _width, int _height, const uint8_t _image[], int _imageSize );
    ~HF2Image();
    friend std::ostream& operator<<( std::ostream& os, const HF2Image& obj );
};

}}}

#endif // HF2IMAGE_H
