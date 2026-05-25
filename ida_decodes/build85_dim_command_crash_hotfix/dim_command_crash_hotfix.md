# Build 85 Dim Command Crash Investigation

Scope: crash investigation for the Dim color-variant commands. The initial report covered `VESDimPurple` and `VESDimDarkRed`; later testing also reported `VESDimWhiteInverted`.

## Observed implementation path

- Both commands call `StartDimEffect` with their profile IDs.
- Both profiles route to the same Dim shader family and the same `VESDimPS.pso` slot as `VESDim50`, `VESDim100`, and `VESDimWhiteInverted`.
- The color difference is carried through `MoonSugarProfile.w` as a profile variant constant.

## Build 85 / 86 Correction

The public-release hazard identified in this pass was command registration. The plugin still used OBSE's default development opcode base `0x2000`, which OBSE documents as unsuitable for released plugins because multiple plugins using that base can collide in the command table.

Build 85 initially moved the local VES opcode base away from `0x2000`. Build 86 supersedes the temporary value and registers VES in the local Daggers opcode ledger at `0x70F0-0x7111`. This does not change shader semantics, hook addresses, profile IDs, or command names. It only moves the registered command opcodes away from the development default to reduce collision risk.

Later testing reported crashes on all three Dim color-variant commands: `VESDimWhiteInverted`, `VESDimPurple`, and `VESDimDarkRed`. That report means the opcode correction was not sufficient evidence for the crash root cause. Treat Build 85 / 86 as an opcode-collision risk reduction, not as proof that command registration caused the Dim variant crash.

## Build 87 Correction

Build 87 preserves the public command names and Dim variant constants, but it no longer stores the Dim color variants as independent active renderer profiles. The active renderer profile is canonicalized to `VESDim100`, while the requested command identity is retained for logging/console text and the Dim color selector is still passed through `MoonSugarProfile.w`.

This follows the decoded Build 82 evidence: the color variants use the existing Dim image-space profile-family shader and differ by the profile-variant constant. No decoded evidence currently requires separate native runtime image-space profiles for these color variants.

## Remaining validation

This pass is build/package verified, but it still needs in-game confirmation with:

```text
VESDimWhiteInverted
VESStop
VESDimPurple
VESStop
VESDimDarkRed
VESStop
VESDumpShaderRenderer
```
