# Lighting30 SM3000 contract

MoonSugarEffect build 28/29 decode and implementation artifact for a state-preserving Lighting30 replacement candidate.

IDA anchors:

- `0x007FD560`: Lighting30 vertex loader creates `B47288[0]` from `lighting\3x\SM3Lighting.v.hlsl` as `SM3000.vso`.
- `0x007FDDE0`: Lighting30 pixel loader creates `B46ED8[0]` from `lighting\3x\SM3Lighting.p.hlsl` as `SM3000.pso`.
- `0x0085E660`: Lighting30 pooled-pass population maps pass `3` to `B47288[0]` plus `B46ED8[0]`.
- `0x007FD260`: selector `0x12D` routes to pass `3`; the pass uses `vMask=0x00030002` and `pMask=0x00000016`.

The extracted bytecode is from Oblivion's local `C:\Games\Oblivion\Data\Shaders\shaderpackage019.sdp` after the IDA loader and pass map identified the records. No Fallout material was used.

## Package records

- `SM3000.vso`: name offset `0xAE3EC`, bytecode offset `0xAE4F0`, size `0x2B0`, target `vs_3_0`.
- `SM3000.pso`: name offset `0xB9860`, bytecode offset `0xB9964`, size `0x28F0`, target `ps_3_0`.
- `SM3LL000.pso`: name offset `0xBB68C`, bytecode offset `0xBB790`, size `0x2548`, target `ps_3_0`. This is a low-light contrast only; build 28 keeps it blocked for replacement.

## SM3000.vso contract

Registers from CTAB/disassembly:

- `c0-c3`: `ModelViewProj`
- `c15`: `FogParam`
- `c16`: `FogColor`

Inputs:

- `v0`: `POSITION`
- `v1`: `TANGENT`
- `v2`: `BINORMAL`
- `v3`: `NORMAL`
- `v4`: `TEXCOORD`

Outputs consumed by `SM3000.pso`:

- `o0`: clip position
- `o1.xy`: base UV
- `o2`: vertex color, stock writes white
- `o3.xyz`: tangent
- `o4.xyz`: binormal
- `o5.xyz`: normal
- `o6.xyz`: source position vector used by pixel lighting
- `o7.xyz`: fog color
- `o7.w`: fog blend term

Implementation consequence: a Moon Sugar `SM3000.vso` clone should displace the source position before the `ModelViewProj` transform and should write the displaced position to `o6.xyz`. If only `o0` is moved, object edges wobble but the `ps_3_0` light vectors still use the undisplaced `o6`, producing lighting/geometry disagreement.

`c26/c27` remain plausible Moon Sugar vertex scratch constants for this plain pass because the decoded vertex shader reads only `c0-c3`, `c15`, and `c16`. Pixel constants `c9-c38` are a separate D3D constant namespace and remain native-owned.

## SM3000.pso contract

Registers from CTAB/disassembly:

- `c0`: `AmbientColor`
- `c3`: `MatAlpha`
- `c5`: `ToggleADTS`
- `c6`: `ToggleNumLights`
- `c9-c38`: `LightData[30]`
- `s0`: `BaseMap`
- `s1`: `NormalMap`

Inputs:

- `v0.xy`: base UV from `o1`
- `v1.xyz`: color from `o2`
- `v2.xyz`: tangent from `o3`
- `v3.xyz`: binormal from `o4`
- `v4.xyz`: normal from `o5`
- `v5.xyz`: position from `o6`
- `v6`: fog color/blend from `o7`

The pixel shader normalizes `v2/v3/v4`, reconstructs tangent-space light vectors from `LightData` and `v5`, samples normal/base maps, accumulates up to 30 lights, then fog-blends toward `v6.xyz` by `v6.w`.

## Replacement boundary

The decoded safe target is narrow:

- Candidate pass: `Lighting30 B473D0[3]` only.
- Selector: `0x12D`.
- Vertex program: `SM3000.vso` only.
- Pixel program: normal `SM3000.pso` only.
- Low-light `SM3LL000.pso` and all variant `SM3001+` contracts remain blocked until separately decoded and cloned.

This does not change the live whitelist by itself. It supplies the exact contract needed for the next OBSE-side implementation pass: a new `vs_3_0` Lighting30 replacement shader, separate from the existing `PAR2016`/`SKIN2008` `vs_2_0` replacement.

## Build 29 implementation

Build 29 adds that separate OBSE-side `vs_3_0` replacement path.

- The pass remains gated to `Lighting30 B473D0[3]`.
- Runtime verifies the current pass still owns exactly `B47288[0]` and `B46ED8[0]` before applying the replacement.
- The existing Parallax/Skin `vs_2_0` replacement is left intact and selected separately.
- The replacement is a direct D3D vertex-shader override at the already decoded post-setup/post-constant-flush hook, so native pass maps, pixel shaders, texture stages, render states, and constant-map ownership remain native.
- The plugin writes Moon Sugar constants to vertex constants `c26-c27`, then binds the plugin `SM3000` clone for the current draw only.

Local compiler verification:

- `MoonSugarSM3000.vs.hlsl` compiled with local June 2010 `fxc.exe`.
- Target profile: `vs_3_0`.
- Disassembly preserves the stock declarations: `POSITION`, `TEXCOORD0`, `COLOR0`, `TEXCOORD3`, `TEXCOORD4`, `TEXCOORD5`, `TEXCOORD6`, and `TEXCOORD7`.
- The disassembly writes `o6.xyz` from the displaced source position, preserving the decoded `SM3000.pso` lighting dependency.
