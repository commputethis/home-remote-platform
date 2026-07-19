# Home Remote Platform

A reusable platform for battery-powered ESP-NOW touch remotes that synchronize with Home Assistant through an ESPHome bridge.

The first application is a bedside controller for a bedroom light and ceiling fan.

## Repositories

- `home-remote-platform`: protocol, applications, ESPHome bridge, Home Assistant integration, and documentation.
- `waveshare-s3-touch`: reusable hardware support for Waveshare ESP32-S3 touch displays.

## Milestone 1 status

Completed foundation:

- Two-repository boundary
- Project and device metadata configuration
- Versioned typed protocol
- Sequence numbers and CRC validation
- Bedroom Remote application skeleton
- Ulanzi bridge integration contract
- Initial ADR set
- Host-side protocol test

Hardware drivers and live ESP-NOW integration are intentionally scheduled for later milestones.

## Current architecture

See [`docs/architecture.md`](docs/architecture.md).

## Build the protocol test

```bash
cmake -S tests -B build/tests
cmake --build build/tests
./build/tests/protocol_test
```

## Planned milestones

1. **Foundation** — repository structure, board API, protocol, configuration, ADRs.
2. **Transport and bridge** — production ESP-NOW layer and Ulanzi ESPHome integration.
3. **UI** — final LVGL screens, gestures, indicators, and state rendering.
4. **Synchronization** — Home Assistant state imports and bidirectional updates.
5. **Power** — battery reporting, ambient brightness, touch wake, dimming, and sleep.
6. **Documentation and release** — wiring, build, flashing, troubleshooting, screenshots, and release process.

## Identity

- Author: Commputethis
- Educational program: The Maker's Space
- License: MIT
