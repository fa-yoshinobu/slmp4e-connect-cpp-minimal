# Example Index

Use this file as the quick "which sketch should I start from?" guide.

For install steps and the overall library overview, go back to [../README.md](../README.md).

## Quick Picks

- Want the smallest first read example: start with `esp32_read_words`.
- Want a Wi-Fi interactive debug console: start with `esp32_c3_serial_console`.
- Want the same Wi-Fi interactive debug console on Atom Matrix: start with `atom_matrix_serial_console`.
- Want an Ethernet interactive debug console on WIZnet RP2350 hardware: start with `w6300_evb_pico2_read_words`.
- Want reconnect and remote password flow in one sketch: start with `esp32_password_read_loop`.
- Want random or block API coverage: start with `esp32_random_block`.

| Use case | Folder | Board/transport | What it shows |
|---|---|---|---|
| Basic direct read | `esp32_read_words` | ESP32 + `WiFiClient` | `connect()`, `readTypeName()`, `readWords()`, frame dump |
| Random and block access | `esp32_random_block` | ESP32 + `WiFiClient` | `readRandom()`, `readBlock()`, optional write examples |
| Dynamic bit walk | `esp32_dynamic_bits` | ESP32 + `WiFiClient` | dynamic `M100..M500` writes with odd-address filtering |
| Reconnect + password | `esp32_password_read_loop` | ESP32 + `WiFiClient` | reconnect loop, password unlock, type-name read, periodic polling, `config.h` for deployment settings |
| ESP32-C3 interactive console | `esp32_c3_serial_console` | ESP32-C3 + `WiFiClient` | full interactive serial console for direct, one-shot, random, block, password, target, and frame-dump API checks |
| Atom Matrix interactive console | `atom_matrix_serial_console` | M5Stack Atom Matrix (`ESP32-PICO-D4`) + `WiFiClient` | the same full interactive serial console shape as the ESP32-C3 example, plus `demo` mode for button-driven `D0` increment and 5x5 `M0..M24` LED mirroring |
| RP2040 Ethernet basic read | `rp2040_w5500_read_words` | RP2040 + `EthernetClient` | same core API with W5500 transport |
| W5500-EVB-Pico2 interactive console | `w5500_evb_pico2_read_words` | RP2350 + onboard W5500 + `EthernetClient` | Arduino-Pico `EthernetCompat` bring-up plus `connect()`, `readTypeName()`, `readWords()`, and an interactive serial debug console with human-evaluated write verification |
| W6300-EVB-Pico2 interactive console | `w6300_evb_pico2_read_words` | RP2350 + onboard W6300 + `WiFiClient` via `W6300lwIP` | QSPI W6300 bring-up plus a full interactive serial console for direct, one-shot, random, block, password, and frame-dump API checks |

Suggested order:

1. Start with `esp32_read_words`.
2. Move to `esp32_password_read_loop` if you need a more complete session pattern with a separate `config.h`.
3. Use `esp32_c3_serial_console` if you want a Wi-Fi based interactive debug console on ESP32-C3.
4. Use `atom_matrix_serial_console` if you want the same interactive console on M5Stack Atom Matrix hardware.
5. Use `esp32_random_block` or `esp32_dynamic_bits` for specialized access patterns.
6. Use `w5500_evb_pico2_read_words` if you are on the WIZnet RP2350 Ethernet board.
7. Use `w6300_evb_pico2_read_words` if you are on the WIZnet RP2350 W6300 Ethernet board.

## Related Docs

- [../README.md](../README.md): install, quick start, board-by-board overview, memory notes
- [../TROUBLESHOOTING.md](../TROUBLESHOOTING.md): network, buffer, and frame-dump troubleshooting
- [../HARDWARE_VALIDATION.md](../HARDWARE_VALIDATION.md): record real-board validation status and capture data
