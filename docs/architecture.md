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

## Repository boundary

- `waveshare-s3-touch`: reusable hardware support only.
- `home-remote-platform`: protocol, applications, bridge configuration, Home Assistant integration, and project documentation.
