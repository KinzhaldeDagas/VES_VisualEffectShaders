# Build 84 Pipeline Diagnostic Alignment

Scope: implementation correction against the current Build 80 support-buffer policy.

## Evidence

- Oblivion IDA byte reads for the active hook sites still match the plugin expected bytes for the inspected `1.2.0416` binary:
  - `0x00666639`: `E8 72 BD 03 00 5F 5E 8A`
  - `0x0040CF6E`: `E8 6D 79 3A 00 D9 EE 8B`
  - `0x0040CCD3`: `E8 D8 F3 2F 00 83 C4 10`
  - `0x0040CE48`: `E8 63 F2 2F 00 83 C4 10`
  - `0x007694D7`: `E8 14 DE FF FF 5F 5E 5D`
  - `0x00767410`: `33 C0 39 46 30 74 6F 39`
  - `0x007676F9`: `33 C0 39 47 44 89 44 24`
- Build 80 superseded live replacement for SimpleShadow, DepthMap, RenderNormals, LocalMap, and ZOnly to preserve native support-buffer outputs after in-game white texture/normal instability reports.
- `main.cpp` still contained diagnostic readiness strings that described those support-buffer families as candidate clone paths even though the live replacement helper already preserves them.

## Implementation Correction

- Added a shared support-buffer family classifier for SimpleShadow, DepthMap, RenderNormals, LocalMap, and ZOnly.
- Updated vertex, pixel, pass, and replacement-plan readiness reporting for those families to return `blocked:preserveNativeSupportBuffers` or `blocked:clearSupportPass`.
- Removed stale support-buffer candidate replacement-plan strings from active runtime diagnostics.
- Renamed the pipeline coverage output from `supportNeedsValidation` / `supportBlocked` to `supportPreserved`.

## Semantics

This is a diagnostic alignment pass only. It does not prove a safe support-buffer replacement route, does not implement terrain/object identity masking, and does not widen any object-vertex shader eligibility.

Current guidance remains:

| Family | Live status |
| --- | --- |
| SimpleShadow | Preserve native shader path |
| DepthMap | Preserve native shader path |
| RenderNormals | Preserve native shader path |
| LocalMap | Preserve native shader path |
| ZOnly | Preserve native shader path |

