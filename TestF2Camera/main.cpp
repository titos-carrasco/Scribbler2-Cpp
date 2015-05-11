#include <QtGui/QApplication>
#include <QLabel>
#include <iostream>
#include "rcr/robots/scribbler2/Scribbler2.h"

using namespace rcr::robots::scribbler2;

int main(int argc, char* argv[])
{
    Scribbler2 robot( "/dev/rfcomm2", 500 );
    F2Camera f2Camera = robot.getF2Camera();

    std::cout << "Estableciendo tamaño de imagen" << std::endl;
    f2Camera.setPicSize( f2Camera.IMAGE_SMALL ); // IMAGE_LARGE, IMAGE_SMALL

    QApplication app(argc, argv);
    QLabel myLabel;
    QImage myImage;

    for( int i =0; i<=30; i++ ){
        std::cout << "Solicitando imagen ";
        HF2Image image = f2Camera.getImage( f2Camera.IMAGE_GRAYJPEG_FAST ); // IMAGE_JPEG_FAST, IMAGE_JPEG, IMAGE_GRAYJPEG
        std::cout << image << std::endl;

        myImage.loadFromData( image.image, image.imageSize, "JPG" );
        myLabel.setPixmap(QPixmap::fromImage(myImage));
        myLabel.show();
        app.processEvents();
    }

    std::cout << "Finalizando..:" << std::endl;
    robot.close();
}
