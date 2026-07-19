# Architecture

```text
Home Assistant
      │
      │ native API/services/state
      ▼
Ulanzi TC001 ESPHome Bridge
      │
      │ Home Remote Protocol over ESP-NOW
      ▼
Bedroom Remote Application
      │
      │ stable board API
      ▼
WaveshareS3Touch Library
      │
      ▼
Waveshare ESP32-S3-Touch-LCD-1.46C
```

## Source of truth

The bridge and Home Assistant are authoritative for light and fan state. The remote sends intent and updates its UI from received state messages rather than assuming a command succeeded.

## Repository boundaries

- `waveshare-s3-touch`: reusable hardware support for the Waveshare ESP32-S3-Touch-LCD-1.46C family. It does not depend on LVGL, ESP-NOW, Home Assistant, or Home Remote application behavior.

- `home-remote-protocol`: transport-independent packet definitions, serialization, validation, message types, sequencing, acknowledgements, compatibility rules, and protocol tests.

- `home-remote-platform`: Bedroom Remote application behavior, LVGL integration, ESP-NOW transport implementation, bridge configuration, Home Assistant integration, and ecosystem-level documentation.
