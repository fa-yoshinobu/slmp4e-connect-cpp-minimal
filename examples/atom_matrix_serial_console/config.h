#ifndef SLMP4E_EXAMPLE_ATOM_MATRIX_SERIAL_CONSOLE_CONFIG_H
#define SLMP4E_EXAMPLE_ATOM_MATRIX_SERIAL_CONSOLE_CONFIG_H

#include <stddef.h>
#include <stdint.h>

namespace example_config {

struct ManualCheckStep {
    const char* guide;
    const char* preview;
    const char* command;
};

constexpr char kWifiSsid[] = "YOUR_WIFI_SSID";
constexpr char kWifiPassword[] = "YOUR_WIFI_PASSWORD";

constexpr char kPlcHost[] = "192.168.250.101";
constexpr uint16_t kPlcPort = 1025;

constexpr uint32_t kWifiConnectTimeoutMs = 10000;

constexpr size_t kTxBufferSize = 512;
constexpr size_t kRxBufferSize = 512;

// Replace these with the inspection guidance and writable commands you want to verify on site.
// Default set writes each device family once and leaves the written value as-is.
constexpr ManualCheckStep kManualCheckSteps[] = {
    {"X10 linked indication should turn ON.", "write target: X10 <- ON", "verifyb X10 1"},
    {"Y10 linked indication should turn ON.", "write target: Y10 <- ON", "verifyb Y10 1"},
    {"SD100 linked display/HMI value should become 111.", "write target: SD100 <- 111", "verifyw SD100 111"},
    {"D100 linked display/HMI value should become 123.", "write target: D100 <- 123", "verifyw D100 123"},
    {"SM100 linked indication should turn ON.", "write target: SM100 <- ON", "verifyb SM100 1"},
    {"M100 linked indication should turn ON.", "write target: M100 <- ON", "verifyb M100 1"},
    {"L100 linked indication should turn ON.", "write target: L100 <- ON", "verifyb L100 1"},
    {"F100 linked indication should turn ON.", "write target: F100 <- ON", "verifyb F100 1"},
    {"V100 linked indication should turn ON.", "write target: V100 <- ON", "verifyb V100 1"},
    {"B100 linked indication should turn ON.", "write target: B100 <- ON", "verifyb B100 1"},
    {"W100 linked display/HMI value should become 4660.", "write target: W100 <- 4660", "verifyw W100 4660"},
    {"TS100 linked indication should turn ON.", "write target: TS100 <- ON", "verifyb TS100 1"},
    {"TC100 linked indication should turn ON.", "write target: TC100 <- ON", "verifyb TC100 1"},
    {"TN100 linked value should become 21.", "write target: TN100 <- 21", "verifyw TN100 21"},
    {"LTS100 linked indication should turn ON.", "write target: LTS100 <- ON", "verifyb LTS100 1"},
    {"LTC100 linked indication should turn ON.", "write target: LTC100 <- ON", "verifyb LTC100 1"},
    {"LTN100 linked value should become 22.", "write target: LTN100 <- 22", "verifyw LTN100 22"},
    {"STS100 linked indication should turn ON.", "write target: STS100 <- ON", "verifyb STS100 1"},
    {"STC100 linked indication should turn ON.", "write target: STC100 <- ON", "verifyb STC100 1"},
    {"STN100 linked value should become 23.", "write target: STN100 <- 23", "verifyw STN100 23"},
    {"LSTS100 linked indication should turn ON.", "write target: LSTS100 <- ON", "verifyb LSTS100 1"},
    {"LSTC100 linked indication should turn ON.", "write target: LSTC100 <- ON", "verifyb LSTC100 1"},
    {"LSTN100 linked value should become 24.", "write target: LSTN100 <- 24", "verifyw LSTN100 24"},
    {"CS100 linked indication should turn ON.", "write target: CS100 <- ON", "verifyb CS100 1"},
    {"CC100 linked indication should turn ON.", "write target: CC100 <- ON", "verifyb CC100 1"},
    {"CN100 linked value should become 31.", "write target: CN100 <- 31", "verifyw CN100 31"},
    {"SB100 linked indication should turn ON.", "write target: SB100 <- ON", "verifyb SB100 1"},
    {"SW100 linked value should become 9029.", "write target: SW100 <- 9029", "verifyw SW100 9029"},
    {"S100 linked indication should turn ON.", "write target: S100 <- ON", "verifyb S100 1"},
    {"DX10 linked indication should turn ON.", "write target: DX10 <- ON", "verifyb DX10 1"},
    {"DY10 linked indication should turn ON.", "write target: DY10 <- ON", "verifyb DY10 1"},
    {"Z100 linked value should become 5.", "write target: Z100 <- 5", "verifyw Z100 5"},
    {"LZ100 linked value should become 6.", "write target: LZ100 <- 6", "verifyw LZ100 6"},
    {"R200 linked display/HMI value should become 234.", "write target: R200 <- 234", "verifyw R200 234"},
    {"ZR300 linked display/HMI value should become 345.", "write target: ZR300 <- 345", "verifyw ZR300 345"},
    {"RD100 linked value should become 456.", "write target: RD100 <- 456", "verifyw RD100 456"},
    {"G100 linked value should become 567.", "write target: G100 <- 567", "verifyw G100 567"},
    {"HG100 linked value should become 678.", "write target: HG100 <- 678", "verifyw HG100 678"},
};

}  // namespace example_config

#endif
