# ADR 0002: The bridge is the state authority for the remote

- Status: Accepted
- Date: 2026-07-19

## Context

Light and fan state may change from Home Assistant, voice assistants, dashboards, automations, or the original fan remote.

## Decision

The touch remote sends commands but renders state received from the Ulanzi bridge. It does not permanently assume a command succeeded.

## Consequences

- The screen remains synchronized with external changes.
- Commands require acknowledgement and/or a resulting state update.
- The bridge imports Home Assistant entity state and publishes it over ESP-NOW.
