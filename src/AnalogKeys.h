/*
  AnalogKeys library to integrate an analoge input for easy key integration
  Developer  : Bastian Geier
  Date       : 30.12.2023
  E-mail     : mail@bastiangeier.de
  Repo       : https://github.com/RedCali/AnalogKeys.git

  Any suggestions are welcome.
*/
#pragma once
#ifndef __ANALOG_KEYS__
#define __ANALOG_KEYS__

#define ANALOG_KEYS_VERSION "0.0.1"  // software version of this library

#if defined(ARDUINO) && ARDUINO >= 100
#pragma message("Compiling for Arduino Framework Architecture...")
#include "Arduino.h"
#else
#pragma message("Compiling for AVR ATMEGA Framework Architecture...")
// #include "WProgram.h"
#include <stdio.h>
#include <stdlib.h>
#endif

#include <avr/io.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define STRING_NONE   "none  "
#define STRING_NULL   "      "
#define STRING_SELECT "Select"
#define STRING_UP     "Up    "
#define STRING_DOWN   "Down  "
#define STRING_LEFT   "Left  "
#define STRING_RIGHT  "Right "

template <
  unsigned int ANL_SELECT_Lower,
  unsigned int ANL_SELECT_Upper,
  unsigned int ANL_RIGHT_Lower,
  unsigned int ANL_RIGHT_Upper,
  unsigned int ANL_LEFT_Lower,
  unsigned int ANL_LEFT_Upper,
  unsigned int ANL_UP_Lower,
  unsigned int ANL_UP_Upper,
  unsigned int ANL_DOWN_Lower,
  unsigned int ANL_DOWN_Upper,
  bool returnEmptyString
  >
class AnalogKeys {
  private:

  public:
    typedef enum KeyValues : uint8_t {
      NONE = 0,
      UP = 1,
      DOWN = 2,
      LEFT = 3,
      RIGHT = 4,
      SELECT = 10,
      NONE_FF = 99
    } KeyValue;

    AnalogKeys() {};
    ~AnalogKeys() {};

    inline KeyValues Read(uint16_t anlValue) {
      if ((ANL_RIGHT_Lower <= anlValue ) && (anlValue <= ANL_RIGHT_Upper) ) {
        return RIGHT;
      } else if ((ANL_UP_Lower <= anlValue ) && (anlValue <= ANL_UP_Upper) ) {
        return UP;
      } else if ((ANL_DOWN_Lower <= anlValue ) && (anlValue <= ANL_DOWN_Upper) ) {
        return DOWN;
      } else if ((ANL_LEFT_Lower <= anlValue ) && (anlValue <= ANL_LEFT_Upper) ) {
        return LEFT;
      } else if ((ANL_SELECT_Lower <= anlValue ) && (anlValue <= ANL_SELECT_Upper) ) {
        return SELECT;
      }
      return NONE_FF;
    }

    static const inline char* GetString(uint8_t keyValue) {
      return GetString(static_cast<KeyValues>(keyValue));
    }

    static const inline char* GetString(KeyValues keyValue) {
      const char* const StringNULL = STRING_NULL;
      const char* const StringNONE =  STRING_NONE;
      const char* const StringSELECT = STRING_SELECT;
      const char* const StringUP = STRING_UP;
      const char* const StringDOWN = STRING_DOWN;
      const char* const StringLEFT = STRING_LEFT;
      const char* const StringRIGHT = STRING_RIGHT;

      switch (keyValue) {
        case RIGHT:
          return StringRIGHT;
        case LEFT:
          return StringLEFT;
        case UP:
          return StringUP;
        case DOWN:
          return StringDOWN;
        case SELECT:
          return StringSELECT;
        case NONE_FF:
          if (returnEmptyString)
            return StringNULL;
          else
            return StringNONE;
        case NONE:
          return StringNULL;
        default:
          return "ERROR";
      }
    }
};
#endif /* __ANALOG_KEYS__ */
