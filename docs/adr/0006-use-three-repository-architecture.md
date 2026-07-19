# ADR 0006: Use a three-repository architecture

- Status: Accepted
- Date: 2026-07-19
- Supersedes: ADR 0001

## Context

The board-support library, communication protocol, and home-control
application have separate responsibilities and release cycles.

The board library can support applications unrelated to Home Remote.
The protocol can be shared by remotes, bridges, simulators, and future
devices. The platform combines those libraries into user-facing
applications.

## Decision

Maintain three repositories:

1. `waveshare-s3-touch`
2. `home-remote-protocol`
3. `home-remote-platform`

The dependency direction is:

```text
home-remote-platform
    ├── home-remote-protocol
    └── waveshare-s3-touch
```

Neither reusable library depends on home-remote-platform, and the two
libraries do not depend on each other.

## Consequences

- Each component can be versioned and released independently.
- The protocol can be reused by devices that do not use Waveshare hardware.
- The board library remains independent of Home Assistant and ESP-NOW application behavior.
- Platform builds must declare compatible versions of both libraries.
- Coordinated changes may temporarily require matching feature branches or prerelease versions.
