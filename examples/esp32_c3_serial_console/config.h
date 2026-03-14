#ifndef SLMP4E_EXAMPLE_ESP32_C3_SERIAL_CONSOLE_CONFIG_H
#define SLMP4E_EXAMPLE_ESP32_C3_SERIAL_CONSOLE_CONFIG_H

#include <stddef.h>
#include <stdint.h>

namespace example_config {

constexpr char kWifiSsid[] = "YOUR_WIFI_SSID";
constexpr char kWifiPassword[] = "YOUR_WIFI_PASSWORD";

constexpr char kPlcHost[] = "192.168.250.101";
constexpr uint16_t kPlcPort = 1025;

constexpr uint32_t kWifiConnectTimeoutMs = 10000;

constexpr size_t kTxBufferSize = 512;
constexpr size_t kRxBufferSize = 512;

}  // namespace example_config

#endif
