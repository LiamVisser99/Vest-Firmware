#include "hardware/I2C.h"

void I2C::init()
{

    Wire.begin(SDA, SCL);
    Wire1.begin(SDA1, SCL1);

    Wire.setClock(1000000);
    Wire1.setClock(1000000);
}