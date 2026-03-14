# Python Comparison Checklist

Use this note when you want to compare the original Python implementation with the current C++ library on the same PLC and the same block-access scenarios.

The original Python project referenced by this repository is:

- `slmp4e-connect-python`: <https://github.com/fa-yoshinobu/slmp4e-connect-python>

## Purpose

The current C++ library already has:

- mixed block support in the codec and request builder ([src/slmp4e_minimal.cpp](./src/slmp4e_minimal.cpp))
- mock-PLC integration coverage that accepts mixed `writeBlock()` ([tests/slmp4e_socket_integration.cpp](./tests/slmp4e_socket_integration.cpp))
- a real-board Atom Matrix result against Mitsubishi iQ-R `R08CPU` showing that mixed `writeBlock` was rejected on the real PLC ([HARDWARE_VALIDATION.md](./HARDWARE_VALIDATION.md))

What is still unknown is whether the original Python implementation:

- sends the same `1406/0002` mixed block frame
- passes on the same PLC
- fails with the same end code
- or uses a different fallback or packing rule

## Current C++ Baseline

Recorded board:

- `m5stack-atom`
- sketch: `examples/atom_matrix_serial_console`
- PLC: Mitsubishi iQ-R `R08CPU`
- date: `2026-03-14`

Current result summary:

| Scenario | C++ result | Notes |
|---|---|---|
| `readBlock/writeBlock words` | pass | `word-only` block write succeeded |
| `readBlock/writeBlock bits` | pass | `bit-only` block write succeeded |
| `readBlock/writeBlock mixed` | fail | PLC returned `0xC05B` during mixed `writeBlock` |

Mixed write case used:

- word block device: `D300`, `2 points`
- bit block device: `M200`, `1 packed word`
- effective bit range: `M200..M215`

Sample failing C++ mixed request captured from the real PLC run:

```text
last request: 54 00 99 00 00 00 00 FF FF 03 00 1E 00 10 00 06 14 02 00 01 01 2C 01 00 00 A8 00 02 00 C8 00 00 00 90 00 01 00 F7 87 BE 80 FE 6D
last response: D4 00 99 00 00 00 00 FF FF 03 00 0B 00 5B C0 00 FF FF 03 00 06 14 02 00
```

Interpreted meaning:

- command: `1406`
- subcommand: `0002`
- word blocks: `1`
- bit blocks: `1`
- word block: `D300`, `2 points`
- bit block: `M200`, `1 packed word`

## Comparison Conditions

Keep the Python-side check as close as possible to the C++ run:

- same PLC: Mitsubishi iQ-R `R08CPU`
- same network path and target settings
- same device addresses
- same point counts
- same packed-bit interpretation for block bit writes
- capture both request hex and response hex

Recommended device set:

- word-only block write: `D300`, `2 points`
- bit-only block write: `M200`, `1 packed word`
- mixed block write: `D300`, `2 points` plus `M200`, `1 packed word`

## What To Record From Python

For each case below, record:

- function or API name used in Python
- exact device list and values
- whether the write succeeded
- request hex
- response hex
- end code if failed
- whether actual PLC memory changed

## Worksheet

Fill this table after running the Python version.

| Scenario | Devices | Expected comparison target | Python result | End code | Notes |
|---|---|---|---|---|---|
| `readBlock words+bits` | `D300 x2`, `M200 x1 packed` | C++ pass | pending |  |  |
| `writeBlock words only` | `D300 x2` | C++ pass | pending |  |  |
| `writeBlock bits only` | `M200 x1 packed` | C++ pass | pending |  |  |
| `writeBlock mixed` | `D300 x2` + `M200 x1 packed` | C++ fail with `0xC05B` | pending |  |  |

## Suggested Python Test Notes

If the Python project already has a block-write helper, prefer running exactly these three write cases:

1. `word-only`
2. `bit-only`
3. `mixed`

If `mixed` fails, capture:

- whether Python used the same combined request shape
- whether the end code was also `0xC05B`
- whether Python retried by splitting the request

If `mixed` passes, capture:

- the full request hex
- any difference in subcommand, payload order, or packed-bit layout compared with the C++ request above

## Expected Outcome Categories

Use one of these when summarizing the Python result:

- `same_as_cpp_pass`
- `same_as_cpp_fail_same_end_code`
- `same_as_cpp_fail_different_end_code`
- `different_request_shape`
- `different_runtime_behavior`

## After Comparison

When the Python result is known, update:

- [HARDWARE_VALIDATION.md](./HARDWARE_VALIDATION.md)
- this file
- any issue opened from the hardware-validation template
