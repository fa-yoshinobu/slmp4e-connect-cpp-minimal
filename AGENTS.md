# Agent Guide: SLMP C++ Minimal

This repository is part of the PLC Communication Workspace and follows the global standards defined in `D:\PLC_COMM_PROJ\AGENTS.md`.

## 1. Project-Specific Context
- **Protocol**: SLMP (Seamless Message Protocol)
- **Authoritative Source**: Mitsubishi Electric specifications.
- **Language**: C++ (Minimal / Embedded focus)
- **Platform**: PlatformIO (Arduino/ESP32/etc.)
- **Role**: Lightweight Communication Library for embedded devices.

## 2. Mandatory Rules (Global Standards)
- **Language**: All code, comments, and documentation MUST be in **English**.
- **Encoding**: Use **UTF-8 (without BOM)** for all files to prevent Mojibake.
- **Mandatory Static Analysis**:
  - All changes must pass `cppcheck` or `clang-tidy`.
  - Use PlatformIO linting tools to verify compliance.
- **Documentation Structure**: Follow the Modern Documentation Policy:
  - `docs/user/`: User manuals and API guides. [DIST]
  - `docs/maintainer/`: Protocol specs and internal logic. [REPO]
  - `docs/validation/`: Hardware QA reports and bug analysis. [REPO]
- **Distribution Control**: Ensure `library.json` or `library.properties` excludes `docs/maintainer/`, `docs/validation/`, and `TODO.md` from library packages.

## 3. Reference Materials
- **Official Specs**: Refer to `local_folder/CLPA_DOWNLOAD_.../` for authoritative English manuals (Local only).
- **Evidence**: Check `docs/validation/reports/` for verified communication results with Mitsubishi PLCs.

## 4. Development Workflow
- **Issue Tracking**: Log remaining tasks in `TODO.md`.
- **Change Tracking**: Update `CHANGELOG.md` for every fix or feature.
- **QA Requirement**: Every hardware-related fix must include an evidence report in `docs/validation/reports/`.
