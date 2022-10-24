#ifndef LIB_GPS_GPS_H_
#define LIB_GPS_GPS_H_

#include <Arduino.h>

void gps_time(char* buffer, uint8_t size);
float gps_latitude();
float gps_longitude();
float gps_altitude();
float gps_hdop();
uint8_t gps_sats();
void gps_setup();
void gps_loop();

#endif /* LIB_GPS_GPS_H_ */
