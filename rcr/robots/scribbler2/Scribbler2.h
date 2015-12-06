#ifndef SCRIBBLER2_H
#define SCRIBBLER2_H

#include <string>
#include <stdint.h>
#include "rcr/utils/Lock.h"
#include "rcr/utils/SerialPort.h"
#include "HS2Sensors.h"
#include "S2Inner.h"
#include "S2IRSensors.h"
#include "S2LEDs.h"
#include "S2LightSensors.h"
#include "S2LineSensors.h"
#include "S2Microphone.h"
#include "S2Motors.h"
#include "S2Speaker.h"
#include "S2Path.h"
#include "F2Camera.h"
#include "F2Inner.h"
#include "F2IRSensors.h"
#include "F2LEDs.h"
#include "F2Servos.h"

namespace rcr {
namespace robots {
namespace scribbler2 {

class Scribbler2
{
public:
    static const int DATA_LENGTH = 8;
    static const int PACKET_LENGTH = 9;

private:
    rcr::utils::Mutex mutex;
    rcr::utils::SerialPort serial;
    S2Inner s2Inner;
    S2IRSensors s2IRSensors;
    S2LEDs s2LEDs;
    S2LightSensors s2LightSensors;
    S2LineSensors s2LineSensors;
    S2Microphone s2Microphone;
    S2Motors s2Motors;
    S2Speaker s2Speaker;
    S2Path s2Path;
    F2Camera f2Camera;
    F2Inner f2Inner;
    F2IRSensors f2IRSensors;
    F2LEDs f2LEDs;
    F2Servos f2Servos;

public:
    Scribbler2( const std::string& port, int timeout );
    ~Scribbler2();
    void close();
    rcr::utils::Mutex& getMutex();
    S2Inner& getS2Inner();
    S2IRSensors& getS2IRSensors();
    S2LEDs& getS2LEDs();
    S2LightSensors& getS2LightSensors();
    S2LineSensors& getS2LineSensors();
    S2Microphone& getS2Microphone();
    S2Motors& getS2Motors();
    S2Speaker& getS2Speaker();
    S2Path& getS2Path();
    F2Camera& getF2Camera();
    F2Inner& getF2Inner();
    F2IRSensors& getF2IRSensors();
    F2LEDs& getF2LEDs();
    F2Servos& getF2Servos();
    bool sendS2Command( const uint8_t packet[PACKET_LENGTH], int pause );
    void sendS2PathCommand( const uint8_t packet[PACKET_LENGTH] );
    void sendF2Command( const uint8_t packet[], int len, int pause );
    HS2Sensors getS2SensorsResponse();
    std::string getLineResponse( int maxChars );
    uint8_t getUInt8Response();
    uint16_t getUInt16Response();
    uint32_t getUInt32Response();
    int32_t getInt32Response();
    void getBytesResponse( uint8_t b[], int nbytes );
};

}}}

#endif // SCRIBBLER2_H
