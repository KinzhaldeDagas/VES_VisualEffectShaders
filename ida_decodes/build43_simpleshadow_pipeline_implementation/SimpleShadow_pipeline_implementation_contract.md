# Build 43 SimpleShadow Pipeline Implementation

Authoritative source: live Oblivion IDA database for `Oblivion.exe` 1.2.0.416 (`fxq5`) plus direct
`shaderpackage019.sdp` disassembly from build 33/build 38. Fallout material was not used.

## Native Passes Implemented

This pass adds exact-gated vertex replacement for the Lighting30 SimpleShadow family:

- Pass `36`: `B47288[13]` / `SM3013 SimpleShadow`, `B46ED8[23]` / `SM3023 SimpleShadow`.
- Pass `37`: `B47288[14]` / `SM3014 SimpleShadow VC`, `B46ED8[23]`.
- Pass `38`: `B47288[15]` / `SM3015 SimpleShadow SKIN`, `B46ED8[23]`.
- Pass `39`: `B47288[16]` / `SM3016 SimpleShadow SKIN VC`, `B46ED8[23]`.

Each gate checks the Oblivion pass index, native vertex program index, native pixel program index, vertex constant
mask, pixel constant mask, and live wrapper identity before replacing the active D3D vertex shader.

## Constants And Scratch Registers

- Non-skinned SimpleShadow clones use `c26-c27`.
- Skinned SimpleShadow clones use `c27-c28`.
- Native `ObjToCubeMap c10-c13`, `FogParam c15`, `FogColor c16`, and `Bones c31-c84` remain untouched.

## Preserved Vertex Contract

The clone preserves the native `SM3013..SM3016` output payload while applying Moon Sugar displacement to the
source position:

- `POSITION0`: displaced clip position.
- `TEXCOORD0`: base UV.
- `TEXCOORD6`: displaced source position consumed by `SM3023`.
- `TEXCOORD1`: displaced `ObjToCubeMap` projection.
- `TEXCOORD2`: native fog color/fade payload.

The native SimpleShadow pixel shader, textures, render states, and constant maps remain unchanged.
