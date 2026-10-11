#pragma once

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <array>

#include "models/model.h"
#include "I2C.h"

struct Motors
{
  std::array<uint8_t, 20> front = {36, 47, 15, 2, 32, 35, 1, 0, 33, 34, 4, 3, 46, 45, 13, 14, 43, 44, 12, 11};

  std::array<uint8_t, 20> back = {50, 51, 18, 19, 49, 48, 16, 17, 62, 63, 26, 31, 52, 61, 27, 20, 59, 60, 30, 29};
};

class pca_manager
{

private:
  Adafruit_PWMServoDriver pwm[4] = {Adafruit_PWMServoDriver(0x40), Adafruit_PWMServoDriver(0x41), Adafruit_PWMServoDriver(0x42, Wire1), Adafruit_PWMServoDriver(0x43, Wire1)};
  int Freqs[4] = {25000000, 25000000, 25000000, 25000000};

public:
  void init();

  void duty_write(const uint8_t &motor_ID,const uint16_t intensity);
  void packet_write(const raw_haptic_packet &packet);
  
  void motor_pwm_test();

  Motors motors;
};

// These are the assignments for Prototype V1

/*

    Backup Pin and PCA Mapping:

      ID:2        ID:3    ID:1        ID:0
    ________    ________________    ________
     15   4      2   3    2   3      2   15
     3    0      1   0    0   1      0   1
     2    1      14  15   10  15     3   4
     13   14     4   13   11  4      14  13
     12   11     11  12   14  13     11  12

------------------------------------------------

     Mapped Properly (TBD):

         Front                Back
      ID:2    ID:0         ID:3   ID:1
    ________________    ________________
     4    15  15  2      2   3    2   3
     0    3   1   0      1   0    0   1
     1    2   4   3      14  15   10  15
     14   13  13  14     4   13   11  4
     11   12  12  11     11  12   14  13

------------------------------------------------

     Base 16 addition:

      ID:2        ID:3    ID:1        ID:0
    ___32___    ___48______16___    ___NA___
     47   36     50  51   18  19     2   15
     35   32     49  48   16  17     0   1
     34   33     62  63   26  31     3   4
     45   46     52  61   27  20     14  13
     44   43     59  60   30  29     11  12

     Mapped Properly Base 16 (TBD):

          Front                Back
      ID:2    ID:0         ID:3   ID:1
      0x42    0x40         0x43   0x41
    ________________    ________________
     36   47  15  2      50  51   18  19
     32   35  1   0      49  48   16  17
     33   34  4   3      62  63   26  31
     46   45  13  14     52  61   27  20
     43   44  12  11     59  60   30  29

------------------------------------------------

     Mapped Properly Base 16 HEX (TBD):

             Front                      Back
          ID:2    ID:0              ID:3   ID:1
          0x42    0x40              0x43   0x41
    _______________________    _________________________
     0x24 0x2F  0x0F  0x02      0x32  0x33   0x12  0x13
     0x20 0x23  0x01  0x00      0x31  0x30   0x10  0x11
     0x21 0x22  0x04  0x03      0x3E  0x3F   0x1A  0x1F
     0x2E 0x2D  0x0D  0x0E      0x34  0x3D   0x1B  0x14
     0x2B 0x2C  0x0C  0x0B      0x3B  0x3C   0x1E  0x1D


*/