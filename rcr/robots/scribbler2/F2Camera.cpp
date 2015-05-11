#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "F2Camera.h"
#include "Scribbler2.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

F2Camera::F2Camera( Scribbler2& s2_ ):
                    s2(s2_), image_width( 0 ), image_height( 0 )
{
}

F2Camera::~F2Camera()
{
}

void F2Camera::setPicSize( F2Camera::ImageSize size )
{
    rcr::utils::Lock lock( s2.getMutex() );
    int s, w, h;
    if( size == IMAGE_LARGE ) {
        s = 213;
        w = 1280;
        h = 800;
    }
    else { // if( size == IMAGE_SMALL )
        s = 71;
        w = 427;
        h = 266;
    }
    uint8_t packet[2];
    packet[0] = 11;
    packet[1] = (uint8_t)s;
    s2.sendF2Command( packet, 2, 100 );
    image_width = w;
    image_height = h;
}

HF2Image F2Camera::getImage( F2Camera::ImageMode mode )
{
    rcr::utils::Lock lock( s2.getMutex() );
    int reg, cmd_header, cmd;
    if( mode == IMAGE_GRAYJPEG ) {
        reg = 1;
        cmd_header = 135;
        cmd = 136;
    }
    else if( mode == IMAGE_GRAYJPEG_FAST ) {
        reg = 0;
        cmd_header = 135;
        cmd = 136;
    }
    else if( mode == IMAGE_JPEG ) {
        reg = 1;
        cmd_header = 137;
        cmd = 138;
    }
    else { // if( mode == IMAGE_JPEG_FAST )
        reg = 0;
        cmd_header = 137;
        cmd = 138;
    }

    uint8_t packet[2];
    packet[0] = (uint8_t)cmd_header;
    s2.sendF2Command( packet, 1, 100 );

    int header_len = s2.getUInt8Response() + (s2.getUInt8Response() << 8);
    uint8_t* image = new uint8_t[ header_len ];
    int curr_size = header_len;

    s2.getBytesResponse( image, header_len );
    int image_len = header_len;

    packet[0] = (uint8_t)cmd;
    packet[1] = (uint8_t)reg;
    s2.sendF2Command( packet, 2, 100 );

    int last = 0;
    while( true ) {
        if( image_len >= curr_size ) {
            curr_size += 4096;
            uint8_t* p = new uint8_t[curr_size];
            for( int i=0; i<image_len; i++ )
                    p[i] = image[i];
            delete[] image;
            image = p;
        }

        uint8_t b = s2.getUInt8Response();
        image[image_len++] = b;
        if( b == 0xD9 && last == 0xFF) {
            s2.getUInt32Response();
            s2.getUInt32Response();
            s2.getUInt32Response();
            break;
        }
        last = b;
    }
    if( image_len < curr_size ){
        uint8_t* p = new uint8_t[image_len];
        for( int i=0; i<image_len; i++ )
            p[i] = image[i];
        delete[] image;
        image = p;
    }
    return HF2Image( image_width, image_height, image, image_len );
}

void F2Camera::whiteBalanceOn()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = (uint8_t)129;
    s2.sendF2Command( packet, 1, 100 );
}

void F2Camera::whiteBalanceOff()
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[1];
    packet[0] = (uint8_t)130;
    s2.sendF2Command( packet, 1, 100 );
}

void F2Camera::setCameraParam( int addr, int value )
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[3];
    packet[0] = (uint8_t)131;
    packet[1] = (uint8_t)(addr & 0xFF);
    packet[2] = (uint8_t)(value & 0xFF);
    s2.sendF2Command( packet, 3, 100 );
}

void F2Camera::setWindow( int window, int xLow, int yLow, int xHigh, int yHigh, int xStep, int yStep)
{
    rcr::utils::Lock lock( s2.getMutex() );
    uint8_t packet[12];
    packet[0] = (uint8_t)127;
    packet[1] = (uint8_t)(window & 0xFF);
    packet[2] = (uint8_t)((xLow >> 8) & 0xFF);
    packet[3] = (uint8_t)(xLow & 0xFF);
    packet[4] = (uint8_t)((yLow >> 8) & 0xFF);
    packet[5] = (uint8_t)(yLow & 0xFF);
    packet[6] = (uint8_t)((xHigh >> 8) & 0xFF);
    packet[7] = (uint8_t)(xHigh & 0xFF);
    packet[8] = (uint8_t)((yHigh >> 8) & 0xFF);
    packet[9] = (uint8_t)(yHigh & 0xFF);
    packet[10] = (uint8_t)(xStep & 0xFF);
    packet[11] = (uint8_t)(yStep & 0xFF);
    s2.sendF2Command( packet, 12, 100 );
}

}}}
