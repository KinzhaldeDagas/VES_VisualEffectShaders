# Build 38 support-pass decision matrix

Evidence sources for this pass are Oblivion IDA only, plus direct bytecode extraction from
`Data\Shaders\shaderpackage019.sdp`. Fallout material was not used for behavior.

Status after cleanup, 2026-05-21: this file is a historical decision matrix. Build42 attempted exact-gated
support replacement, and Build59/61 later superseded the clear support subset. Use
`ez_obse_plugin_example/docs/current_hook_contracts.md` for current support/clear guidance.

## IDA chain

- `0x007FD560` builds `B47288[0..31]`, the Lighting30 vertex wrapper table.
- `0x007FDDE0` builds the normal Lighting30 pixel wrapper table at `B46ED8[0..38]` and the low-light subset at `B46C20[0..19]`.
- `0x0085E660` populates the `B473D0[0..53]` pass array and binds each pass to one vertex wrapper plus one pixel wrapper.
- `0x007FD260` maps selector IDs through the pass table, applies `B46988/B46A60` constant masks, and routes special selectors through the higher `B46F28` path.
- `0x007FCC80` builds the Lighting30 constant maps. It confirms named ownership for `WorldViewProjTranspose`, `SkinWorldViewProjTranspose`, `WorldViewTranspose`, `SkinWorldViewTranspose`, `BoneMatrix3`, and `ConstantGroup`.
- `0x007FB6F0` consumes selector-state bytes and reinforces that pass constants are native state, not safe plugin scratch space unless each clone is planned separately.

## Largest gap closed

Builds 35, 36, and 37 covered the visible auxiliary final-color families: EnvMap, TexEffect, and Decal.
The remaining large gap was whether the support families should be cloned for Moon Sugar object wobble.
The answer from Oblivion's own pass map and bytecode is conservative: most of them write support buffers,
not ordinary final color. They should not be broadly replaced by the current Moon Sugar shader path.

## Support pass map

| Pass | Selector | Route | Vertex wrapper | Pixel wrapper | vMask | pMask | Decision |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | `0x12A` | direct | 30 `SM3030 ZOnly` | 37 `SM3037 ZOnly` | `0x00000812` | `0x00000000` | Block |
| 1 | `0x12B`, alias `4` | alpha7 + direct alias | 30 `SM3030 ZOnly` | 37 `SM3037 ZOnly` | `0x00000002` | `0x00000000` | Block |
| 2 | `0x12C`, alias `5` | alpha7 + direct alias | 31 `SM3031 ZOnly SKIN` | 38 `SM3038 ZOnly` | `0x0000000C` | `0x00000000` | Block |
| 36 | `0x14E` | alpha7 | 13 `SM3013 SimpleShadow` | 23 `SM3023 SimpleShadow` | `0x00030802` | `0x00000C10` | Defer, conditional |
| 37 | `0x14F` | alpha7 | 14 `SM3014 SimpleShadow VC` | 23 `SM3023 SimpleShadow` | `0x00030802` | `0x00000C10` | Defer, conditional |
| 38 | `0x150` | alpha7 | 15 `SM3015 SimpleShadow SKIN` | 23 `SM3023 SimpleShadow` | `0x0003080C` | `0x00000C10` | Defer, conditional |
| 39 | `0x151` | alpha7 | 16 `SM3016 SimpleShadow SKIN VC` | 23 `SM3023 SimpleShadow` | `0x0003080C` | `0x00000C10` | Defer, conditional |
| 42 | `0x154` | alpha7 | 18 `SM3018 DepthMap` | 26 `SM3026 DepthMap` | `0x00000012` | `0x00000400` | Block by default |
| 43 | `0x155` | alpha7 | 19 `SM3019 DepthMap SKIN` | 26 `SM3026 DepthMap` | `0x0000002C` | `0x00000400` | Block by default |
| 44 | `0x156` | alpha15 | 20 `SM3020 RenderNormals` | 28 `SM3028 RenderNormals` | `0x00000012` | `0x00000200` | Block by default |
| 45 | `0x157` | alpha15 | 21 `SM3021 RenderNormals SKIN` | 29 `SM3029 RenderNormals` | `0x0000002C` | `0x00000200` | Block by default |
| 46 | `0x158` | alpha15 | 22 `SM3022 RenderNormals FIRE` | 30 `SM3030 RenderNormals FIRE` | `0x00108012` | `0x00000200` | Block by default |
| 47 | `0x159` | alpha15 | 23 `SM3023 RenderNormals CLEAR` | 31 `SM3031 RenderNormals CLEAR` | `0x00000002` | `0x00000000` | Block |
| 48 | `0x15A` | alpha15 | 24 `SM3024 RenderNormals CLEAR SKIN` | 32 `SM3032 RenderNormals CLEAR` | `0x0000000C` | `0x00000000` | Block |
| 49 | `0x15B` | alpha15 | 25 `SM3025 LocalMap` | 33 `SM3033 LocalMap` | `0x00000012` | `0x00000000` | Block by default |
| 50 | `0x15C` | alpha15 | 26 `SM3026 LocalMap SKIN` | 33 `SM3033 LocalMap` | `0x0000002C` | `0x00000000` | Block by default |
| 51 | `0x15D` | alpha15 | 27 `SM3027 LocalMap CLEAR` | 34 `SM3034 LocalMap CLEAR` | `0x00000002` | `0x00000000` | Block |

Passes `40..41` are Decal and were already handled in build 37. Passes `52..53` are TexEffect and were already handled in build 36.

## Pixel-output behavior

The pixel bytecode confirms why these are not interchangeable with final-color clones:

- `SM3037/SM3038 ZOnly` write zero color. These are depth/occlusion-style support passes.
- `SM3026/SM3027 DepthMap` sample `BaseMap s0`, consume `v1.z`, and write depth-like RGB with base alpha.
- `SM3028/SM3029 RenderNormals` consume `NormalMap s0` and `PSRefractionPower c8`, then write encoded normal/refraction vectors.
- `SM3030 RenderNormals FIRE` consumes fire/vector inputs and writes an encoded vector plus refraction power.
- `SM3031/SM3032 RenderNormals CLEAR` write a constant clear value.
- `SM3033 LocalMap` writes encoded normalized vector data plus a depth-style alpha.
- `SM3034 LocalMap CLEAR` writes a constant clear color.
- `SM3023 SimpleShadow` is visible-adjacent but specialized. It consumes `BaseMap s0`, `ShadowMap s2`, `ToggleADTS c5`, `LightColor c9`, `LightData c10`, source position in `TEXCOORD6`, projected shadow/cube coordinates, and fog/fade. It is not a generic support pass and cannot share the existing final-color auxiliary clones.

## Clone policy

- ZOnly remains blocked. Replacing it would change depth/occlusion silhouettes or prepass consistency while producing no useful visible color.
- DepthMap remains blocked by default. A wobble there would move depth support data and can desynchronize shadows, refraction, or other later consumers.
- RenderNormals remains blocked by default. It writes encoded normal/refraction support data; wobbling it without a render-target-level decision can create mismatches between visible geometry and support buffers.
- LocalMap remains blocked by default for the same support-buffer reason.
- SimpleShadow is deferred, not rejected. It can contribute visible shadow-light output, but it depends on `ObjToCubeMap`, `ShadowMap s2`, `LightData c10`, and source-position/projected-coordinate outputs. If later logs prove it is a visible gap after all primary and visible auxiliary clones are active, implement dedicated clones for each of `SM3013..SM3016` only under exact pass/wrapper gating.

## Scratch-constant implications

No support family gets a generic Moon Sugar scratch constant assignment.

- No-skin support variants can usually avoid high native rows with `c26-c27`, but that is not a universal contract.
- Skinned support variants use `Bones c31-c84` in several families, so high scratch rows are unsafe there.
- SimpleShadow owns `ObjToCubeMap c10-c13`, `FogParam c15`, and `FogColor c16`.
- RenderNormals FIRE owns `EyePosition c14` and `Time c19`.
- DepthMap and LocalMap rely on world-view or skin-world-view rows that must remain native for buffer correctness.

If any support pass is ever enabled, it must get a variant-specific clone and scratch plan, then a render-target gate proving the pass is writing a buffer we deliberately want to deform.

## Validation status after build 38

- Static IDA and shaderpackage evidence identify the support-pass families and why broad support replacement is risky.
- Runtime validation is still required for in-game logs/screenshots, exact render-target role classification when support passes draw, and any deliberate decision to deform a support buffer.
- Do not express this as a percentage unless a future pass adds a concrete coverage method.

Implementation coverage remains intentionally split:

- Primary Lighting30, Parallax, Skin, EnvMap, TexEffect, and Decal visible paths have dedicated replacement coverage.
- Support-pass replacement remains intentionally limited by current implementation policy. The decode says broad support clones are more likely to damage buffer correctness than improve the visible Moon Sugar effect.
