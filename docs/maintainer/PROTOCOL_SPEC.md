# SLMP Protocol Specification (C++ Minimal)

Technical details of the SLMP implementation used in this library.

## 1. Frame Formats

### 4E Binary Frame (Default)
The library focuses on the **4E Binary Frame** due to its rich features and support for newer iQ-R/iQ-F series.

**Request Structure:**
1. Subheader (`54 00`)
2. Serial No.
3. Reserved
4. Network No.
5. Station No.
6. Module I/O No.
7. Multidrop Station No.
8. Data Length
9. Monitoring Timer
10. Command / Subcommand
11. Request Data

### 3E Binary Frame
Supported for compatibility with older Q-series PLCs. Enable via `setFrameType(FrameType::Frame3E)`.

## 2. Command Support

Currently implemented commands:
- `0101`: Read Type Name
- `0401`: Read Device (Word/Bit)
- `1401`: Write Device (Word/Bit)
- `0403`: Read Random
- `1402`: Write Random
- `0406`: Read Block
- `1406`: Write Block
- `1630/1631`: Remote Password Unlock/Lock

## 3. Device Encoding

- **Decimal Devices (D, M, etc.)**: Encoded as standard numeric offsets.
- **Hexadecimal Devices (X, Y, B, W, etc.)**: Encoded using hex base.
- **Special Cases**:
  - `F` device is mapped to `slmp4e::DeviceCode::FDevice` to avoid conflicts with Arduino's `F()` macro.

## 4. Transport Abstraction

The library uses the `Slmp4eTransport` abstract class to decouple protocol logic from the physical network stack (Wi-Fi, Ethernet, etc.).
- `ArduinoClientTransport`: A concrete implementation for the standard Arduino `Client` class.
