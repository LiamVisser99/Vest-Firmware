#pragma once

#include <array>

constexpr std::size_t motor_array_size = 20;

// Struct containing data type for (send)
#pragma pack(push, 1)
struct raw_haptic_packet
{
    std::array<uint16_t, motor_array_size> array_front;
    std::array<uint16_t, motor_array_size> array_back;
};
#pragma pack(pop)