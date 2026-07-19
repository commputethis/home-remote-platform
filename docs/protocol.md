# Home Remote Protocol

Protocol version: 1

Every message includes:

- Magic value
- Protocol version
- Message type
- Sequence number
- Device ID
- Payload size
- Typed payload
- CRC-16 checksum

## Message flow

```text
Remote                         Bridge
  │                              │
  ├──────── HELLO ──────────────►│
  ├────── STATE_REQUEST ────────►│
  │◄──────── STATE ──────────────┤
  ├──────── COMMAND ────────────►│
  │◄──────── ACK ────────────────┤
  │◄──────── STATE ──────────────┤
  ├──────── BATTERY ────────────►│
  │◄──────── ACK ────────────────┤
```

## Sequence numbers

The sender increments a 16-bit sequence number. The receiver may identify duplicate retransmissions and return a duplicate acknowledgement without repeating a state-changing command.

## Compatibility

A receiver rejects packets with unsupported versions. The bridge may temporarily retain support for the current single-byte command format during migration.
