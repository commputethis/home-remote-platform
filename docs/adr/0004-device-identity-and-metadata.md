# ADR 0004: Keep device identity in project configuration

- Status: Accepted
- Date: 2026-07-19

## Context

Applications need a human-readable name, numeric routing identity, firmware version, author attribution, and project metadata.

## Decision

Store identity and runtime constants in `ProjectConfig.h`. Use `Commputethis` as the author identity and `The Maker's Space` as optional educational attribution.

## Consequences

- A new remote can be created by changing one configuration file.
- Logs and HELLO messages can identify devices clearly.
- Project metadata does not leak into the reusable board library.
