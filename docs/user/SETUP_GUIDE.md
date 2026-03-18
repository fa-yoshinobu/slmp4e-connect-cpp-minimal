# Setup Guide: SLMP C++ Minimal

This guide explains how to install and configure the SLMP C++ Minimal library for various microcontroller boards.

## 1. Supported Boards

The library is board-agnostic and designed for:
- **ESP32** (using `WiFiClient`)
- **RP2040 / RP2350** (using `EthernetClient` or `WiFiClient`)
- Any board providing an Arduino-compatible `Client` implementation.

## 2. Installation

### Using Arduino IDE
1. Download the latest release zip (`slmp-connect-cpp-minimal-vX.X.X.zip`).
2. In Arduino IDE, go to `Sketch -> Include Library -> Add .ZIP Library...`.
3. The library will now be available under `File -> Examples -> SLMP Connect C++ Minimal`.

### Using PlatformIO
1. Add the library to your project by cloning this repository into your `lib/` folder:
   ```bash
   git clone https://github.com/fa-yoshinobu/plc-comm-slmp-cpp-minimal.git lib/slmp-connect-cpp-minimal
   ```
2. Or reference it in your `platformio.ini` (once published to a registry).
3. Include the necessary headers in your code:
   ```cpp
   #include <slmp_minimal.h>
   #include <slmp_arduino_transport.h>
   ```

## 3. Network Hardware Setup

### ESP32 (Wi-Fi)
Pass a `WiFiClient` instance to the library's transport layer.

### RP2040 + W5500 (Ethernet)
Pair your RP2040 with a W5500 module and use the `EthernetClient` provided by the Arduino Ethernet library.

### W5500-EVB-Pico2 / W6300-EVB-Pico2
These boards have onboard Ethernet. Use the vendor-provided core packages (e.g., Arduino-Pico with `W6300lwIP`).

## 4. Initial Connection Check

The most reliable way to verify your setup is to run the `readTypeName` example:
1. Connect your board to the same network as the PLC.
2. Open the `esp32_read_words` (or equivalent) example.
3. Update the IP address and port (default 1025) to match your PLC.
4. Open the Serial Monitor at 115200 baud to see the results.
