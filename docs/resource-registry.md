# Home Remote Platform Resource Registry

## Resource IDs

| ID | Resource |
| ---- | ---------- |
| 0x0100 | Bedroom light |
| 0x0101 | Bedroom fan |
| 0x0200 | Bedroom Remote device |

## Property IDs

Property identifiers are interpreted in the context of a resource.

### Bedroom light

| ID | Property | Type |
| ---- | ---------- | ------ |
| 0x0001 | Power | BOOL |
| 0x0002 | Brightness | UINT8 |

### Bedroom fan

| ID | Property | Type |
| ---- | ---------- | ------ |
| 0x0001 | Power | BOOL |
| 0x0002 | Speed | UINT8 |

### Bedroom Remote

| ID | Property | Type |
| ---- | ---------- | ------ |
| 0x0001 | Battery percentage | UINT8 |
| 0x0002 | Battery voltage millivolts | UINT16 |
| 0x0003 | Ambient light | UINT16 |
