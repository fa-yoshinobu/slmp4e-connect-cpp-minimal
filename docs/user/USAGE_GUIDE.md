# Usage Guide: SLMP C++ Minimal

This guide covers basic and advanced usage of the library, including synchronous and asynchronous communication.

## 1. Basic Synchronous Usage

Synchronous methods block execution until a response is received or a timeout occurs.

```cpp
#include <slmp_arduino_transport.h>

// 1. Setup Transport
WiFiClient tcp;
slmp::ArduinoClientTransport transport(tcp);

// 2. Initialize Client with fixed TX/RX buffers
uint8_t tx_buffer[128];
uint8_t rx_buffer[128];
slmp::SlmpClient plc(transport, tx_buffer, sizeof(tx_buffer), rx_buffer, sizeof(rx_buffer));

void setup() {
    plc.connect("192.168.1.10", 1025);
}

void loop() {
    // Read 2 words from D100
    uint16_t words[2] = {0};
    if (plc.readWords({slmp::DeviceCode::D, 100}, 2, words, 2) == slmp::Error::Ok) {
        // Success
    }
    delay(1000);
}
```

## 2. Asynchronous (Non-blocking) Usage

Asynchronous communication allows the microcontroller to perform other tasks while waiting for the PLC.

### Workflow
1.  Start an operation with a `beginXXX()` method.
2.  Call `plc.update(millis())` in your main `loop()`.
3.  Check `plc.isBusy()` to monitor progress.
4.  Check `plc.lastError()` once finished.

### Example
```cpp
uint16_t data[10];
bool active = false;

void loop() {
    uint32_t now = millis();
    if (!active) {
        auto dev = slmp::dev::D(slmp::dev::dec(100));
        if (plc.beginReadWords(dev, 10, data, 10, now) == slmp::Error::Ok) {
            active = true;
        }
    }

    plc.update(now);

    if (active && !plc.isBusy()) {
        if (plc.lastError() == slmp::Error::Ok) {
            // Data is ready in data[]
        }
        active = false;
    }
}
```

## 3. Advanced Features

### 3E/4E Frame Selection
Default is **4E**. To use **3E** frames (e.g., for older Q-series):
```cpp
plc.setFrameType(slmp::FrameType::Frame3E);
```

### Random and Block Access
- **Random Read**: Get multiple non-contiguous devices in one request.
- **Block Read**: Efficiently read mixed word and bit blocks.
- *Note: Bit blocks use packed 16-bit words.*

### Password Security
Use `remotePasswordUnlock(password)` and `remotePasswordLock(password)` for PLCs with enabled remote security.

## 4. Memory Model and Buffers

The library does not use dynamic allocation.
- **Small reads/writes**: 96 bytes buffer.
- **Large word writes**: 128 - 192 bytes.
- **Random/Block access**: 192 - 256 bytes.
