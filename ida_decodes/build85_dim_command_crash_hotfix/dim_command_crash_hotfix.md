# Build 85 Dim Command Crash Hotfix

Scope: crash report for `VESDimPurple` and `VESDimDarkRed`.

## Observed implementation path

- Both commands call `StartDimEffect` with their profile IDs.
- Both profiles route to the same Dim shader family and the same `VESDimPS.pso` slot as `VESDim50`, `VESDim100`, and `VESDimWhiteInverted`.
- The color difference is carried through `MoonSugarProfile.w` as a profile variant constant.

## Correction

The remaining public-release hazard was command registration. The plugin still used OBSE's default development opcode base `0x2000`, which OBSE documents as unsuitable for released plugins because multiple plugins using that base can collide in the command table.

Build 85 initially moved the local VES opcode base away from `0x2000`. Build 86 supersedes the temporary value and registers VES in the local Daggers opcode ledger at `0x70F0-0x7111`. This does not change shader semantics, hook addresses, profile IDs, or command names. It only moves the registered command opcodes away from the development default to reduce collision risk.

## Remaining validation

This pass is build/package verified, but it still needs in-game confirmation with:

```text
VESDimPurple
VESStop
VESDimDarkRed
VESStop
VESDumpShaderRenderer
```
