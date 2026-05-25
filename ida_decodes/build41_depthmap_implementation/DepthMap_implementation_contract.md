# Build 41 DepthMap Implementation

Authoritative source: live Oblivion IDA database for `Oblivion.exe` 1.2.0.416 (`fxq5`) plus the direct
shaderpackage disassembly already extracted in build 33/build 38. Fallout material was not used.

## IDA Evidence

- `0x007FD560` builds `B47288[18]` from `lighting\3x\SM3DepthMap.v.hlsl` and `B47288[19]` from the same source with `SKIN`.
- `0x007FDDE0` builds `B46ED8[26..27]` from `lighting\3x\SM3DepthMap.p.hlsl`.
- `0x0085E660` binds pass `42` to `B47288[18]` plus `B46ED8[26]` and sets masks `v=0x00000012`, `p=0x00000400`.
- `0x0085E660` binds pass `43` to `B47288[19]` plus `B46ED8[26]` and sets masks `v=0x0000002C`, `p=0x00000400`.
- `0x007FD260` maps selector IDs `0x154..0x155` through the same Lighting30 pass table and alpha-7 route.

## Native Shader Contract

`SM3018 DepthMap`:

- Constants: `ModelViewProj c0-c3`, `WorldView c5-c7`.
- Inputs: position, UV.
- Outputs: clip position, UV, and `WorldView * position` in `TEXCOORD1.xyz`; `TEXCOORD1.w` is zero.

`SM3019 DepthMap SKIN`:

- Constants: `SkinModelViewProj c1-c4`, `SkinWorldView c6-c8`, `Bones c31-c84`.
- Inputs: position, UV, blend weights, blend indices.
- Outputs: clip position, UV, and `SkinWorldView * skinnedPosition` in `TEXCOORD1.xyz`; `TEXCOORD1.w` is zero.

The paired pixel shader samples `BaseMap s0`, reads `TEXCOORD1.z`, divides by `LightData c10.w`, writes the
depth-like value to RGB, and preserves base alpha.

## Implementation

The plugin now has exact-gated `Lighting30 DepthMap` vertex replacement:

- Pass `42`: `SM3018_DEPTHMAP_vs3_clone_c26c27`.
- Pass `43`: `SM3019_DEPTHMAP_SKIN_vs3_clone_c27c28`.

Build 48 codifies the IDA-derived constants in the gate instead of relying on family labels alone:

- Pass `42` must resolve to vertex program `18`, pixel program `26`, vertex mask `0x00000012`,
  and pixel mask `0x00000400`.
- Pass `43` must resolve to vertex program `19`, pixel program `26`, vertex mask `0x0000002C`,
  and pixel mask `0x00000400`.
- The skin hook and variant must agree; a non-skinned hook cannot apply the `SM3019` clone and a skinned hook
  cannot apply the `SM3018` clone.

The clone deliberately replaces only the active D3D vertex shader after native setup and constant-manager flush.
It preserves native pixel shader, texture stages, render states, and the DepthMap pixel constant contract.

Because DepthMap has no normal/tangent inputs, the Moon Sugar displacement uses a deterministic position-derived
local basis. The displaced position feeds both clip projection and view-depth output, keeping the support buffer
internally coherent instead of moving only the visible edge.

Runtime diagnostics now track `depthAppliedMask` separately from `depthShaderMask`, and each DepthMap variant logs
its first application independently. This avoids hiding support-buffer coverage when the first replacement draw is
a normal Lighting30 pass.

## Runtime Validation Needed

Build 38 blocked DepthMap by default because support buffers can reveal mismatches if only some consumers are
deformed. Build 41 moves it to a dedicated implementation under exact pass/wrapper gating. The next runtime pass
should verify:

- `Moon Sugar object vertex shader DepthMap` logs appear only on pass `42` or `43`.
- `depthShaderMask` reaches `01` for non-skinned depth, `02` for skinned depth, or `03` for both.
- No new shadow/refraction/object-edge mismatch appears when Moon Sugar is active.
