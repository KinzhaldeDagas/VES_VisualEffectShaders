# Build 42 Support Pipeline Implementation

Evidence source: live Oblivion IDA database for `Oblivion.exe` 1.2.0.416 (`fxq5`) plus the direct
shaderpackage disassembly from build 33/build 38. Fallout material was not used.

Status after cleanup, 2026-05-21: this is a historical implementation snapshot. Build59/61 supersede the
clear-support clone portion for passes `47`, `48`, and `51`; those passes are not active replacement guidance.
Use `ez_obse_plugin_example/docs/current_hook_contracts.md` for current support/clear ship policy.

## Historical Native Passes Implemented

This pass adds exact-gated vertex replacement for the support-buffer Lighting30 families that can be cloned
without replacing the native pixel shader:

- ZOnly: passes `0`, `1`, and `2` using `SM3030` / `SM3031`.
- RenderNormals: passes `44..48` using `SM3020..SM3024` in this historical snapshot. The clear subset
  `47..48` is superseded by Build59/61 and is not active guidance.
- LocalMap: passes `49..51` using `SM3025..SM3027` in this historical snapshot. Clear pass `51` is superseded
  by Build59/61 and is not active guidance.

Each gate checks the Oblivion pass index, native vertex program index, native pixel program index, vertex constant
mask, pixel constant mask, and live wrapper identity before replacing the active D3D vertex shader.

## Scratch Registers

- Non-skinned support clones use `c26-c27`.
- Skinned support clones use `c27-c28`.
- Native bones remain untouched at `c31-c84`.

## Behavior

The clones preserve each native output contract:

- ZOnly preserves clip position, UV, and white vertex color while deforming the silhouette.
- RenderNormals preserves encoded support data: UV/depth/refraction vectors and fire vector data. Build 42 also
  cloned clear variants, but build 59 supersedes that portion.
- LocalMap preserves encoded local normal/depth output. Build 42 also cloned the clear variant, but build 59
  supersedes that portion.

The native pixel shaders, texture stages, render states, and constant maps remain unchanged.

## Build 59 supersession

Build 59 supersedes the clear portion of this implementation. Passes `47`, `48`, and `51` are still decoded
as native clear support passes, but VES no longer emits or applies replacement clones for them because the paired
pixels write constant clear values. The live support replacement set is now:

- ZOnly: passes `0`, `1`, and `2`.
- RenderNormals: passes `44`, `45`, and `46`.
- LocalMap: passes `49` and `50`.

The native clear contract labels remain available for diagnostics, and those passes report
`blocked:clearSupportPass`.
