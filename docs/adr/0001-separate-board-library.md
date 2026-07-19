# ADR 0001: Keep board support in a separate repository

- Status: Superseded
- Superseded by: ADR 0006
- Date: 2026-07-19

## Context

The board library is useful beyond the bedroom remote and should not depend on Home Assistant or the remote protocol.

## Decision

Maintain two repositories:

1. `waveshare-s3-touch`
2. `home-remote-platform`

## Consequences

- Hardware support can be versioned and released independently.
- The platform consumes the board library as a dependency.
- Coordinated changes may require matching branches or tagged releases.
