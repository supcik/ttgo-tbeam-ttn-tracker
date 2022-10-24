/*

Credentials file
The effective credentials come from the ".env" file.

*/

#pragma once

#include <Arduino.h>

// Only one of these settings must be defined
// #define USE_ABP
#define USE_OTAA

#ifdef USE_ABP

#ifndef LW_NWKSKEY
#define LW_NWKSKEY 0
#endif

#ifndef LW_APPSKEY
#define LW_APPSKEY 0
#endif

#ifndef LW_DEVADDR
#define LW_DEVADDR 0x0
#endif

// LoRaWAN NwkSKey, network session key
static const u1_t PROGMEM NWKSKEY[16] = {LW_NWKSKEY};
// LoRaWAN AppSKey, application session key
static const u1_t PROGMEM APPSKEY[16] = {LW_APPSKEY};
// LoRaWAN end-device address (DevAddr)
// This has to be unique for every node
static const u4_t DEVADDR = LW_DEVADDR;

#endif

#ifdef USE_OTAA

#ifndef LW_APPEUI
#define LW_APPEUI 0
#endif

#ifndef LW_DEVEUI
#define LW_DEVEUI 0
#endif

#ifndef LW_APPKEY
#define LW_APPKEY 0
#endif

// For TTN issued EUIs the last bytes should be 0x00, 0x00, 0x00.
static const u1_t PROGMEM APPEUI[8] = {LW_APPEUI};

// Note: You do not need to set this field, if unset it will be generated automatically based on the
// device macaddr
static u1_t DEVEUI[8] = {LW_DEVEUI};

// In practice, a key taken from ttnctl can be copied as-is.
static const u1_t PROGMEM APPKEY[16] = {LW_APPKEY};

#endif
