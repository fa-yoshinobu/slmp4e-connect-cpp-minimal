# TODO: SLMP C++ Minimal

This file tracks the remaining tasks and issues for the SLMP C++ Minimal library.

## 1. Protocol Implementation
- [ ] **3E Frame Full Support**: Expand validation for 3E frame communication across different Mitsubishi CPUs.
- [ ] **Memory Management**: Optimize memory usage for constrained embedded devices (ESP32/Arduino).

## 2. Testing & Validation
- [ ] **PlatformIO Unit Tests**: Implement on-device unit tests using the PlatformIO test runner.
- [ ] **CI Integration**: Setup a GitHub Action to verify builds for different boards.

## 3. Documentation & Maintenance
- [ ] **User API Guide**: Create a clear `docs/user/API_GUIDE.md` with minimal code snippets.
- [ ] **Library Packaging**: Update `library.json` to exclude maintainer and validation folders from the distribution.
