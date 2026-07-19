# Home Remote Platform Roadmap

This roadmap is the high-level status page for the Home Remote Platform ecosystem. Detailed work is tracked as GitHub issues and pull requests across the three repositories.

## Repository ecosystem

| Repository | Responsibility | Current phase |
|---|---|---|
| `waveshare-s3-touch` | Reusable hardware abstraction for supported Waveshare ESP32-S3 touchscreen boards | Foundation |
| `home-remote-protocol` | Versioned messages, validation, serialization, and compatibility rules | Foundation |
| `home-remote-platform` | Bedroom Remote application, LVGL UI, ESP-NOW transport, Ulanzi bridge, and Home Assistant integration | Foundation |

## Current milestone

### v0.1.0 — Foundation

Goal: establish three independently understandable repositories with clear boundaries, buildable skeletons, initial tests, and recorded architecture decisions.

### Completed

- [x] Define the overall Home Remote Platform architecture.
- [x] Define `WaveshareS3Touch` as a reusable board library.
- [x] Define Home Remote Protocol message categories and packet validation concepts.
- [x] Establish the Ulanzi bridge as the source of truth for synchronized Home Assistant state.
- [x] Define project and device metadata.
- [x] Record initial architecture decisions in ADRs.
- [x] Create the Bedroom Remote application skeleton.
- [x] Create an initial host-side protocol test.

### In progress

- [ ] Create and publish the three GitHub repositories.
- [ ] Move `HomeRemoteProtocol` into the independent `home-remote-protocol` repository.
- [ ] Update `home-remote-platform` to consume both libraries as external dependencies.
- [ ] Review repository READMEs, licenses, issue lists, and ADR locations after the split.
- [ ] Confirm each repository can be built or tested independently where applicable.

### Ready next

- [ ] Finalize the protocol packet header and payload definitions.
- [ ] Implement protocol serialization, validation, CRC checking, and sequence handling.
- [ ] Add verified SPD2010 display and touch support to `waveshare-s3-touch`.
- [ ] Add the ESP32-S3-Touch-LCD-1.46C board profile and diagnostics example.
- [ ] Create the production ESP-NOW transport layer in `home-remote-platform`.
- [ ] Integrate the Ulanzi ESPHome bridge without changing its existing display lambda behavior.

## Planned releases

### v0.2.0 — Hardware and protocol

- Verified display, touch, IO-expander, battery, backlight, and power APIs.
- Stable protocol serialization and validation.
- Host-side protocol tests.
- Working diagnostics firmware for the target Waveshare board.

### v0.3.0 — Transport and bridge

- Bidirectional ESP-NOW communication.
- Sender, protocol-version, length, CRC, and duplicate validation.
- State request and response flow.
- Ulanzi bridge command handling and Home Assistant service calls.
- Remote battery reporting through the bridge.

### v0.4.0 — Bedroom Remote UI

- LVGL display and input integration owned by `home-remote-platform`.
- Horizontal Fan ↔ Main ↔ Brightness navigation.
- Main light and fan controls.
- Light brightness presets.
- Fan Off, Low, Medium, and High controls.
- State-driven button appearance and subtle interaction animations.

### v0.5.0 — Synchronization and power

- Automatic updates after Home Assistant, voice, automation, or original-remote changes.
- Last non-zero fan speed restoration without restoring fan power after an outage.
- Ambient brightness synchronization from the Ulanzi photocell.
- Battery icon, low-battery warning, dimming, sleep, and touch wake.
- Bedroom-safe maximum display brightness.

### v0.9.0 — Beta

- Hardware testing and reliability improvements.
- Fault handling and reconnect behavior.
- Configuration cleanup.
- Installation, flashing, wiring, troubleshooting, and Home Assistant documentation.
- Enclosure and finished-device assets where available.

### v1.0.0 — First stable release

- Stable public APIs for the supported hardware profile and protocol version.
- Reproducible Bedroom Remote and Ulanzi bridge setup.
- Complete user and contributor documentation.
- Tagged releases for all three repositories.

## Architecture boundaries

### `waveshare-s3-touch`

Owns hardware-facing behavior:

- Board profiles and pin definitions
- Display primitives and panel control
- Raw touch input
- TCA9554 IO expander
- QMI8658 IMU
- Battery measurement
- Backlight and board power control
- Hardware diagnostics

It does **not** own application screens, navigation, Home Assistant concepts, or the LVGL object tree.

### `home-remote-protocol`

Owns communication contracts:

- Protocol versioning
- Packet header and payload structures
- Serialization and deserialization
- CRC and packet validation
- Sequence and duplicate handling rules
- Commands, state, battery, ambient light, acknowledgements, and heartbeat messages

It does **not** own ESP-NOW radio setup, board drivers, UI behavior, or Home Assistant service calls.

### `home-remote-platform`

Owns product behavior and integration:

- ESP-NOW transport and peer management
- Bedroom Remote application
- LVGL display and input adapters
- UI screens, navigation, and state rendering
- Ulanzi ESPHome bridge
- Home Assistant service calls and imported state
- Battery reporting, ambient brightness, dimming, and sleep policy

## Decision records

Architecture decisions remain with the repository they affect:

- Board and hardware decisions: `waveshare-s3-touch/docs/adr/`
- Packet and compatibility decisions: `home-remote-protocol/docs/adr/`
- Application, bridge, synchronization, and UI decisions: `home-remote-platform/docs/adr/`

## How this roadmap is maintained

- GitHub issues contain the actionable work.
- Pull requests implement one focused issue or tightly related group of issues.
- Milestones group issues into a releasable outcome for each repository.
- This file records the ecosystem-level direction and current phase.
- Update this file when a milestone changes, a major architectural boundary changes, or a planned release is completed.
