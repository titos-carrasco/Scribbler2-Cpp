#ifndef F2CAMERA_H
#define F2CAMERA_H

#include "HF2Image.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2;

class F2Camera
{
public:
    enum ImageSize { IMAGE_LARGE = 1,IMAGE_SMALL = 2 };
    enum ImageMode { IMAGE_GRAYJPEG = 1, IMAGE_GRAYJPEG_FAST = 2, IMAGE_JPEG  = 3, IMAGE_JPEG_FAST = 4 };

private:
    Scribbler2 &s2;
    int image_width;
    int image_height;

public:
    F2Camera( Scribbler2& s2_ );
    ~F2Camera();
    void setPicSize( F2Camera::ImageSize size );
    HF2Image getImage( F2Camera::ImageMode mode );
    void whiteBalanceOn();
    void whiteBalanceOff();
    void setCameraParam( int addr, int value );
    void setWindow( int window, int xLow, int yLow, int xHigh, int yHigh, int xStep, int yStep);
};

}}}

#endif // F2CAMERA_H
