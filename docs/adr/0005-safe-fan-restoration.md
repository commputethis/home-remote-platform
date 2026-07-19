# ADR 0005: Restore fan speed separately from fan power state

- Status: Accepted
- Date: 2026-07-19

## Context

After a power interruption, the physical fan must remain off if it was off. A later toggle should still restore the most recently used non-zero speed.

## Decision

The fan controller boots off. The Ulanzi bridge remembers the last non-zero speed percentage and uses it only when processing a future fan-toggle-on command.

## Consequences

- Power restoration cannot unexpectedly turn on the fan.
- Toggle-on remains convenient.
- Current on/off state and remembered speed are never represented by the same variable.
