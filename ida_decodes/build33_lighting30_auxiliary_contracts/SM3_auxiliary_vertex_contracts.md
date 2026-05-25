# Lighting30 Auxiliary SM3 Vertex Contracts

This pass extracts and disassembles `SM3008..SM3031.vso` directly from Oblivion's local `shaderpackage019.sdp` after the IDA loader order identified `B47288[8..31]`. No Fallout material was used.

## Extracted Contract Summary

| Program | Family | Key constants | Inputs | Outputs | Slots |
| --- | --- | --- | --- | --- | --- |
| `SM3008` | EnvMap | `ModelViewProj c0-c3`, `ObjToCubeSpace c10-c12`, `EyePosition c14` | pos, uv, normal, tangent, binormal | clip, uv, cube basis/view rows, color | 22 |
| `SM3009` | EnvMap VC | same as `SM3008` | `SM3008` plus color | same, color from vertex | 22 |
| `SM3010` | EnvMap SKIN | `SkinModelViewProj c1-c4`, `EyePosition c14`, `SkinToCubeSpace c27-c29`, `Bones c31-c84` | pos, uv, normal, tangent, binormal, blend weights/indices | clip, uv, cube basis/view rows, color | 103 |
| `SM3011` | EnvMap SKIN VC | same as `SM3010` | `SM3010` plus color | same, color from vertex | 103 |
| `SM3012` | EnvMap special | `ModelViewProj c0-c3`, `ObjToCubeSpace c10-c12`, `EyePosition c14`, `BoundWorldCenter c20` | pos, uv | clip, uv, cube lookup, view vector, color | 27 |
| `SM3013` | SimpleShadow | `ModelViewProj c0-c3`, `ObjToCubeMap c10-c13`, `FogParam c15`, `FogColor c16` | pos, uv | clip, uv, source position, cube projection, fog | 20 |
| `SM3014` | SimpleShadow VC | same bytecode shape as `SM3013` | pos, uv | same as `SM3013` | 20 |
| `SM3015` | SimpleShadow SKIN | `SkinModelViewProj c1-c4`, `ObjToCubeMap c10-c13`, `FogParam c15`, `FogColor c16`, `Bones c31-c84` | pos, uv, blend weights/indices | clip, uv, skinned source position, cube projection, fog | 44 |
| `SM3016` | SimpleShadow SKIN VC | same bytecode shape as `SM3015` | pos, uv, blend weights/indices | same as `SM3015` | 44 |
| `SM3017` | Decal | `ModelViewProj c0-c3`, `DecalFade c32-c39`, `DecalProjection c40-c70` | pos, normal | clip, eight decal projection/fade outputs | 140 |
| `SM3018` | DepthMap | `ModelViewProj c0-c3`, `WorldView c5-c7` | pos, uv | clip, uv, view depth data | 9 |
| `SM3019` | DepthMap SKIN | `SkinModelViewProj c1-c4`, `SkinWorldView c6-c8`, `Bones c31-c84` | pos, uv, blend weights/indices | clip, uv, view depth data | 33 |
| `SM3020` | RenderNormals | `ModelViewProj c0-c3`, `WorldViewTranspose c5-c6` | pos, normal, uv | clip, view normal, uv | 12 |
| `SM3021` | RenderNormals SKIN | `SkinModelViewProj c1-c4`, `SkinWorldViewTranspose c6-c7`, `Bones c31-c84` | pos, normal, uv, blend weights/indices | clip, view normal, uv | 55 |
| `SM3022` | RenderNormals FIRE | `ModelViewProj c0-c3`, `WorldViewTranspose c5-c7`, `EyePosition c14`, `Time c19` | pos, normal | clip, fire/vector data | 17 |
| `SM3023` | RenderNormals CLEAR | `ModelViewProj c0-c3` | pos | clip | 4 |
| `SM3024` | RenderNormals CLEAR SKIN | `SkinModelViewProj c1-c4`, `Bones c31-c84` | pos, blend weights/indices | clip | 28 |
| `SM3025` | LocalMap | `ModelViewProj c0-c3`, `WorldViewTranspose c5-c7` | pos, normal | clip, encoded normal/depth | 10 |
| `SM3026` | LocalMap SKIN | `SkinModelViewProj c1-c4`, `SkinWorldViewTranspose c6-c8`, `Bones c31-c84` | pos, normal, blend weights/indices | clip, encoded normal/depth | 53 |
| `SM3027` | LocalMap CLEAR | `ModelViewProj c0-c3` | pos | clip | 4 |
| `SM3028` | TexEffect | `ModelViewProj c0-c3`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, `FogColor c13` | pos, tangent, binormal, normal, uv | clip, offset UVs, view vector, fog color | 53 |
| `SM3029` | TexEffect SKIN | `SkinModelViewProj c4-c7`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, `FogColor c13`, `Bones c14-c67` | pos, tangent, binormal, normal, uv, blend weights/indices | clip, offset UVs, view vector, fog color | 135 |
| `SM3030` | ZOnly | `ModelViewProj c0-c3` | pos, uv | clip, uv, color | 6 |
| `SM3031` | ZOnly SKIN | `SkinModelViewProj c1-c4`, `Bones c31-c84` | pos, uv, blend weights/indices | clip, uv, color | 30 |

## Implementation Consequence

The remaining broader object-coverage work cannot be a blind reuse of the primary `SM3Lighting` clones. The auxiliary families have different output semantics and, in several skinned cases, different constant-register pressure:

- EnvMap and TexEffect are visible final-color candidates and should be first for broader scene deformation.
- SimpleShadow, DepthMap, RenderNormals, LocalMap, and ZOnly are mostly shadow/depth/diagnostic/offscreen support; replacing them may be useful for consistency but can also perturb render targets that are not directly visible.
- Decal is visible, but its eight decal projection outputs depend on `DecalProjection c40-c70` and normal fade; it needs a dedicated clone rather than a clip-only displacement.
- TexEffect SKIN uses `Bones c14-c67`, so Moon Sugar scratch constants must move outside that native range.

The current deployed build intentionally leaves these auxiliary families blocked until dedicated clones are implemented and runtime-validated.
