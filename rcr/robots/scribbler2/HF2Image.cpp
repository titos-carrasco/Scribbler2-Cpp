#include "HF2Image.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

HF2Image::HF2Image( int _width, int _height, const uint8_t _image[], int _imageSize ):
                    width(_width), height(_height), image(_image), imageSize(_imageSize)
{
}

HF2Image::~HF2Image()
{
    delete[] image;
}

std::ostream& operator<<( std::ostream& os, const HF2Image& obj )
{
    os << "HF2Image(" << obj.width << ", " << obj.height << ", " << obj.imageSize << ")";
    return os;
}

}}}
