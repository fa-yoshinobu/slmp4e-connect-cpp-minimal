# (Mitsubishi MELSEC) SLMP C++ Minimal

[![Release](https://img.shields.io/github/v/release/fa-yoshinobu/plc-comm-slmp-cpp-minimal?label=release)](https://github.com/fa-yoshinobu/plc-comm-slmp-cpp-minimal/releases/latest)
[![CI](https://img.shields.io/github/actions/workflow/status/fa-yoshinobu/plc-comm-slmp-cpp-minimal/ci.yml?branch=main&label=CI&logo=github)](https://github.com/fa-yoshinobu/plc-comm-slmp-cpp-minimal/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Static Analysis: PlatformIO Check](https://img.shields.io/badge/Lint-PIO%20Check-blue.svg)](https://docs.platformio.org/en/latest/plus/pio-check.html)

A lightweight, microcontroller-oriented C++ library for Mitsubishi SLMP (Seamless Message Protocol). Optimized for ESP32, RP2040, and RP2350 with zero dynamic allocation.

## 噫 Key Features

- **Embedded Optimized**: No dynamic memory allocation (`malloc`/`new`). Predictable RAM usage.
- **Async Support**: Built-in state machine for non-blocking communication.
- **Broad Hardware Support**: Board-agnostic design for Wi-Fi and Ethernet (Arduino-compatible).
- **Binary 3E/4E**: Supports both modern and legacy SLMP frames.
- **CI-Ready**: Host-side G++ testing and size regression monitoring.

## 逃 Quick Start

### Minimal Usage
```cpp
#include <slmp4e_arduino_transport.h>

WiFiClient tcp;
slmp4e::ArduinoClientTransport transport(tcp);

uint8_t tx_buffer[128];
uint8_t rx_buffer[128];
slmp4e::Slmp4eClient plc(transport, tx_buffer, 128, rx_buffer, 128);

void setup() {
    plc.connect("192.168.1.10", 1025);
    slmp4e::TypeNameInfo info = {};
    plc.readTypeName(info);
}
```

## 当 Documentation

Follows the workspace-wide hierarchical documentation policy:

- [**Setup Guide**](docs/user/SETUP_GUIDE.md): Installation for Arduino/PlatformIO and hardware setup.
- [**Usage Guide**](docs/user/USAGE_GUIDE.md): Detailed API reference, Sync vs Async, and memory model.
- [**QA Reports**](docs/validation/reports/): Formal evidence of communication with Mitsubishi hardware.
- [**Developer Notes**](docs/maintainer/DEVELOPER_NOTES.md): Metrics, host-testing, and internal design.

## 屏 Development & CI

Quality is managed via `run_ci.bat`.

### Quality Checks
- **Building**: `pio run`
- **Static Analysis**: `pio check` (cppcheck / clang-tidy)
- **Host Testing**: G++ tests for protocol logic.

### Local CI Run
```bash
run_ci.bat
```

## 塘 License

Distributed under the [MIT License](LICENSE).

