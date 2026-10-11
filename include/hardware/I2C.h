#pragma once

#include <Arduino.h>
#include <Wire.h>

#define SDA D3
#define SCL D2

#define SDA1 D5
#define SCL1 D4

class I2C
{
public:
    void init();

private:
};