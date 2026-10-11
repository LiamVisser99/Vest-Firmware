#pragma once

#include <Arduino.h>
#include <string>
#include <NimBLEDevice.h>

#ifndef MYNEWT_VAL
# define MYNEWT_VAL(v) 0
#endif

#if !MYNEWT_VAL(BLE_EXT_ADV)
# warning "NimBLE extended advertising is disabled; some Bluetooth features may be unavailable."
#endif

#ifdef ESP_PLATFORM
# include "esp_sleep.h"
#endif

static NimBLEServer* pServer;

struct connection_info
{
    static constexpr uint32_t pairing_time_ms = 5000;
    static constexpr uint32_t sleep_seconds = 20;

    // Using m2 for the lowest data transfer latency
    static constexpr uint8_t primary_phy = BLE_HCI_LE_PHY_1M;
    static constexpr uint8_t secondary_phy = BLE_HCI_LE_PHY_2M;

    static constexpr const char* device_name = "Vibe Vest";
    static constexpr uint8_t manufacturer_tag[] = {0x6d, 0x6f, 0x64, 0x75, 0x65, 0x78};
    static constexpr const char* characteristic_uuid = "12345678-1234-5678-1234-56789abcdef1";   
    static constexpr const char* service_uuid = "12345678-1234-5678-1234-56789abcdef0";
};

class bluetooth_manager
{
private:
public:
    void init();

};