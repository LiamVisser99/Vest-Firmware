#include "hardware/PCA9685_driver.h"

void pca_manager::init()
{
  for (size_t i = 0; i < 4; i++)
  {
    pwm[i].begin();
    pwm[i].setOscillatorFrequency(Freqs[i]);
    pwm[i].setPWMFreq(250);
  }
}

void pca_manager::duty_write(const uint8_t &motor_ID,const uint16_t intensity)
{
  if (intensity >= 4096 || intensity == 0 || motor_ID > 64)
    return;

  pwm[motor_ID / 16].setPin(motor_ID % 16, intensity);
}

void pca_manager::packet_write(const raw_haptic_packet &packet)
{
  for(size_t i =  0; i < packet.array_back.size(); i++)
  {
    duty_write(motors.back[i], packet.array_back[i]);
  }

  for(size_t i =  0; i < packet.array_front.size(); i++)
  {
    duty_write(motors.front[i], packet.array_front[i]);
  }
}

// This is a hardware blocking function used in initial motor config
void pca_manager::motor_pwm_test()
{
  for (size_t i = 0; i < 20; i++)
  {
    duty_write(motors.front[i], 4095);
    delay(300);
    duty_write(motors.front[i], 0);
  }
  for (size_t i = 0; i < 20; i++)
  {
    duty_write(motors.back[i], 4095);
    delay(300);
    duty_write(motors.back[i], 0);
  }
}