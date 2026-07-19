# Ulanzi TC001 Bridge

The Ulanzi TC001 is the Home Assistant/ESP-NOW bridge for the Bedroom Remote.

## Milestone 1 boundaries

This directory records the integration contract without changing the existing display implementation.

The existing ESPHome display lambda must remain unchanged:

```yaml
display:
  lambda: |-
    id(rgb8x32)->tick();
    id(rgb8x32)->draw();
```

## Milestone 2 work

- Validate sender MAC, packet magic, version, type, size, and checksum.
- Accept versioned command and battery messages.
- Keep temporary backward compatibility with existing single-byte commands.
- Import Home Assistant light/fan state.
- Send state packets to the remote after changes and state requests.
- Store the last non-zero fan percentage at the bridge.
