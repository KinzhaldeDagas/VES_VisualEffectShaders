# Auxiliary Visible Shader Family Contracts

Build 34 targets the visible auxiliary Lighting30 families after the primary `SM3Lighting` path was implemented. The IDA-identified chain is:

- IDA `0x007FD560`: builds `B47288[8..12]` EnvMap, `B47288[17]` Decal, and `B47288[28..29]` TexEffect vertex wrappers.
- IDA `0x007FDDE0`: builds paired normal pixel wrappers `B46ED8[20..22]`, `B46ED8[24..25]`, and `B46ED8[35..36]`.
- IDA `0x0085E660`: binds those wrappers into concrete `B473D0` pass indices.
- IDA `0x007FD260`: selector routing keeps EnvMap/Decal on alpha-7 routes, while TexEffect uses the alternate shader-slot route for selectors `0x15E..0x15F`.
- Direct bytecode extraction/disassembly is from Oblivion's local `C:\Games\Oblivion\Data\Shaders\shaderpackage019.sdp`.

No Fallout material was used.

## Package Records

| Program | Name offset | Bytecode offset | Size |
| --- | ---: | ---: | ---: |
| `SM3008.vso` | `0xB1E7C` | `0xB1F80` | `0x2D4` |
| `SM3009.vso` | `0xB2254` | `0xB2358` | `0x2C8` |
| `SM3010.vso` | `0xB2620` | `0xB2724` | `0x8AC` |
| `SM3011.vso` | `0xB2FD0` | `0xB30D4` | `0x8B8` |
| `SM3012.vso` | `0xB398C` | `0xB3A90` | `0x2FC` |
| `SM3017.vso` | `0xB4FF4` | `0xB50F8` | `0x954` |
| `SM3028.vso` | `0xB7EE4` | `0xB7FE8` | `0x574` |
| `SM3029.vso` | `0xB855C` | `0xB8660` | `0xB6C` |
| `SM3020.pso` | `0xF088C` | `0xF0990` | `0x2F4` |
| `SM3021.pso` | `0xF0C84` | `0xF0D88` | `0x2F4` |
| `SM3022.pso` | `0xF107C` | `0xF1180` | `0x27C` |
| `SM3024.pso` | `0xF2094` | `0xF2198` | `0x690` |
| `SM3025.pso` | `0xF2828` | `0xF292C` | `0x63C` |
| `SM3035.pso` | `0xF42CC` | `0xF43D0` | `0x274` |
| `SM3036.pso` | `0xF4644` | `0xF4748` | `0x274` |

## Pass Map

| Pass | Selector | Route | A8 | VS | PS | vMask | pMask |
| ---: | ---: | --- | ---: | --- | --- | --- | --- |
| 29 | `0x147` | alpha7 | 7 | 8 `SM3008 EnvMap` | 20 `SM3020 EnvMap` | `0x00008802` | `0x00000010` |
| 30 | `0x148` | alpha7 | 7 | 8 `SM3008 EnvMap` | 21 `SM3021 EnvMap WINDOW` | `0x00008802` | `0x00000010` |
| 31 | `0x149` | alpha7 | 7 | 9 `SM3009 EnvMap VC` | 20 `SM3020 EnvMap` | `0x00008802` | `0x00000010` |
| 32 | `0x14A` | alpha7 | 7 | 9 `SM3009 EnvMap VC` | 21 `SM3021 EnvMap WINDOW` | `0x00008802` | `0x00000010` |
| 33 | `0x14B` | alpha7 | 7 | 10 `SM3010 EnvMap SKIN` | 20 `SM3020 EnvMap` | `0x1000800C` | `0x00000010` |
| 34 | `0x14C` | alpha7 | 7 | 11 `SM3011 EnvMap SKIN VC` | 20 `SM3020 EnvMap` | `0x1000800C` | `0x00000010` |
| 35 | `0x14D` | alpha7 | 7 | 12 `SM3012 EnvMap special` | 22 `SM3022 EnvMap special` | `0x00208802` | `0x00000010` |
| 40 | `0x152` | alpha7 | 7 | 17 `SM3017 Decal` | 24 `SM3024 Decal` | `0x00000002` | `0x00000000` |
| 41 | `0x153` | alpha7 | 7 | 17 `SM3017 Decal` | 25 `SM3025 Decal ALPHA` | `0x00000002` | `0x00000000` |
| 52 | `0x15E` | altShaderSlots | 0 | 28 `SM3028 TexEffect` | 35 `SM3035 TexEffect HQ` | `0x00000000` | `0x00000000` |
| 53 | `0x15F` | altShaderSlots | 0 | 29 `SM3029 TexEffect SKIN` | 36 `SM3036 TexEffect HQ` | `0x00000000` | `0x00000000` |

Mask notes:

- `0x00008802`: `WVP(c0)`, selector-state bytes `10` and `14`, forced bytes `16..18`.
- `0x1000800C`: `SkinWVP(c1)`, `Bone3(c31)`, selector-state bytes `14` and `27`, forced bytes `16..18`.
- `0x00208802`: `WVP(c0)`, selector-state bytes `10`, `14`, and `20`, forced bytes `16..18`.
- `0x00000002`: `WVP(c0)`, forced bytes `16..18`.
- Pixel `0x00000010`: pixel constant row `pc3`, forced rows `5..7`.

TexEffect pass masks are zero because `0x007FD260` treats selectors `0x15E..0x15F` specially: it copies alternate shader maps from shader slots `+0x1F/+0x20` into the active slots `+0x0B/+0x0C` before selector state is applied.

## EnvMap

Vertex variants:

- `SM3008`: no skin, no vertex color. Reads position, UV, normal, tangent, binormal. Constants are `ModelViewProj c0-c3`, `ObjToCubeSpace c10-c12`, and `EyePosition c14`.
- `SM3009`: same as `SM3008`, plus vertex color.
- `SM3010`: skinned EnvMap. Reads position, UV, normal, tangent, binormal, blend weights, and blend indices. Constants are `SkinModelViewProj c1-c4`, `EyePosition c14`, `SkinToCubeSpace c27-c29`, and `Bones c31-c84`.
- `SM3011`: same as `SM3010`, plus vertex color.
- `SM3012`: special EnvMap. Reads position and UV. Constants are `ModelViewProj c0-c3`, `ObjToCubeSpace c10-c12`, `EyePosition c14`, and `BoundWorldCenter c20`.

Pixel variants:

- `SM3020` and `SM3021` read `NormalMap s0`, `EnvironmentCubeMap s1`, `MatAlpha c3`, UV `v0.xy`, tangent-to-cube rows in `v1/v2/v3`, and color in `v4`.
- `SM3022` reads `NormalMap s0`, `EnvironmentCubeMap s1`, `MatAlpha c3`, `PSLightColor c9`, UV `v0.xy`, vector data in `v1/v2`, and color in `v3`.

State-preserving clone requirement:

- Displace the source position before clip projection and before the cube-space view vector is derived.
- Preserve tangent/binormal/normal basis outputs, because the pixel shader reconstructs reflection from the normal map and those basis rows.
- For skinned variants, reproduce the same indexed bone blend first, then apply Moon Sugar displacement in skinned/object surface space.
- Scratch constants cannot use `c27-c29` on skinned EnvMap because `SkinToCubeSpace` lives there; use a different free range for those variants.

## Decal

Vertex variant:

- `SM3017` reads position and normal. Constants are `ModelViewProj c0-c3`, `DecalFade c32-c39`, and `DecalProjection c40-c70`.
- It writes clip position plus eight projected decal outputs, one for each decal slot.

Pixel variants:

- `SM3024` reads eight projected decal coordinates `v0..v7`, samples `DecalMap s1`, and blends up to `PSNumDecals c6` decal layers using `PSDecalOffsets c9-c16`.
- `SM3025` adds `BaseMap s0`; its first input `v0.xy` is used for base sampling, while `v1..v7` remain decal projection/fade inputs.

State-preserving clone requirement:

- Displace the source position before clip projection and before every decal-projection coordinate is computed.
- Keep the normal-dependent fade path intact; decal fade uses the native normal and `DecalProjection` rows.
- The clone needs all eight output registers. A clip-only displacement would make the object edge move while decals still project from the undisplaced surface, which is visibly wrong.
- Scratch constants must avoid `c32-c70`.

## TexEffect

Vertex variants:

- `SM3028`: no skin. Reads position, tangent, binormal, normal, and UV. Constants are `ModelViewProj c0-c3`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, and `FogColor c13`.
- `SM3029`: skinned. Reads the same surface basis plus blend weights and indices. Constants are `SkinModelViewProj c4-c7`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, `FogColor c13`, and `Bones c14-c67`.

Pixel variants:

- `SM3035` and `SM3036` read `NormalMap s0`, `SourceTexture s1`, `FillColor c0`, `RimColor c1`, and `fVars c2`.
- Pixel inputs are UV `v0.xy`, offset/source UV `v1.xy`, tangent-space view vector `v2.xyz`, and fog/color blend `v3`.

State-preserving clone requirement:

- Displace the source position before clip projection, before the tangent-space view vector is computed, before fog distance is computed, and before the procedural U/V offset path uses object position.
- `SM3029` uses `Bones c14-c67`, so the current primary Lighting30 scratch ranges are not safe. A TexEffect skinned clone should use a later range such as `c68-c69` for Moon Sugar constants.
- Because TexEffect uses alternate shader maps, runtime gating must verify both selector route and wrapper identity before enabling any clone.

## Implementation Priority

1. EnvMap no-skin/VC/special: visible and relatively small, but must preserve cube reflection inputs.
2. EnvMap skinned/VC: visible, but requires a separate clone because `SkinToCubeSpace c27-c29` conflicts with the primary skinned Lighting30 constant plan.
3. TexEffect no-skin: visible and self-contained, but uses alternate shader-slot setup.
4. TexEffect skinned: visible but has the unusual `Bones c14-c67` layout.
5. Decal: visible but highest risk among this group due to eight decal outputs and projection/fade semantics.

These contracts are now decoded enough to implement dedicated clones, but they should not be enabled with the primary SM3Lighting shader source.
