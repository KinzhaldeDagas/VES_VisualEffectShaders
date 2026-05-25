# Build 39 world/object wobble submission coverage

Evidence sources are the live Oblivion IDA database and the decompiled functions exported into this folder.
Fallout material was not used for this pass.

Status after cleanup, 2026-05-21: this file is historical rationale for the current skinned hook mechanics.
Use `ez_obse_plugin_example/docs/current_hook_contracts.md` for active hook names, status, and ship guidance.

## Targeted gap

Build 38 closed the auxiliary support-pass decision. The next world/object wobble gap is not shader bytecode;
it is submission coverage: which native object paths the current Moon Sugar transform-copy and post-setup
vertex-shader hooks actually reach, and which paths need a separate hook if broader object wobble coverage is
validated later.

## Immediate geometry path

`RenderTriGeometries` at `0x007693E0` is still the central immediate NIF geometry route:

- It copies `NiGeometry::m_worldTransform` into a 13-float stack `NiTransform`.
- It copies `NiGeometry::m_kWorldBound` into a stack bound tuple.
- It calls the hardware/software skinning gate at `0x00768890`.
- If the gate is true, it calls the skinned path `0x00767520` at `0x007694BD`.
- If the gate is false, it calls the non-skinned path `0x007672F0` at `0x007694D7`.

The current Moon Sugar rigid object transform hook patches only the `0x007694D7` call. That is the correct
low-risk hook for ordinary non-hardware-skinned geometry because it modifies the local transform copy before
native shader/pass setup consumes it.

The special path at `0x0076B160` is a separate caller of `0x007672F0`, at `0x0076B2E0`, but it passes
null-ish geometry arguments and uses a geometry buffer held through the geometry parent field. It remains
excluded from Moon Sugar object wobble.

## Current vertex replacement window

The plugin's non-skinned object-vertex replacement hook is at `0x00767410`, inside
`NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`):

- Native pass state, texture stages, transform upload, stream binding, and `SetupShaderPrograms` have already run.
- The shader constant manager flush at `0x0076740E` has already run.
- The hook can then upload Moon Sugar constants and replace only the D3D vertex shader before
  `DrawIndexedPrimitive` or `DrawPrimitive`.
- This is why the existing implementation can preserve native pixel shaders, texture stages, render states,
  and pass ownership.

This hook covers the `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`) draw loop only. It does not cover the
hardware-skinned draw loop in `SkinnedRenderTriGeometrySetup` (`sub_767520`).

## Hardware-skinned gap

`SkinnedRenderTriGeometrySetup` (`sub_767520`) at `0x00767520` is the separate hardware-skinned path:

- It selects the active shader from the skin/shader property or renderer default.
- It walks hardware skin partitions.
- It calls vtable `+0x38` `SetupShaderPrograms` at `0x007676E4`.
- It flushes the shader constant manager at `0x007676F7`.
- It draws partition buffers after the post-flush window beginning at `0x007676F9`.

The current hardware-skinned post-setup hook candidate is therefore `0x007676F9`, not `sub_765560` and not
`NiDX9Renderer::CalculateBoneMatrixes`.

If this path is implemented later, it should:

- Use exact pass/wrapper gating, the same way the current non-skinned post-setup hook does.
- Preserve native pixel shaders, textures, pass state, and bone constants.
- Upload Moon Sugar constants only after the native constant-manager flush.
- Avoid editing `NiSkinInstance` or cached bone arrays.

This is now the largest remaining static implementation gap for full hardware-skinned object wobble.

## Transform upload xrefs

`sub_765480` is the common non-skinned world-transform upload. IDA xrefs show why it should not be detoured
globally as a broad Moon Sugar wobble hook.

| Call site | Owner observed in Oblivion | Behavior | Moon Sugar decision |
| --- | --- | --- | --- |
| `0x0077977B` | Base `NiD3DShader` vtable `+0x34` | For non-skinned pass 0, disables vertex blending and uploads the model transform. For skinned partition input, it calls `CalculateBoneMatrixes` and `sub_765560` instead. | Already reached by the `RenderTriGeometries` transform-copy hook on normal non-skinned geometry. Do not globally detour. |
| `0x007C92A7` | Shared shadow-light / Parallax / Skin-style transform slot | Calls `sub_765480`, then derives material, light, and shadow constants from the same passed transform. | Transform-copy wobble is state-preserving in this observed path because derived constants see the same copied transform. |
| `0x007FB798` | `Lighting30Shader` transform slot | Calls `sub_765480`, then builds Lighting30 light/shadow constant state. | Transform-copy wobble is state-preserving for this observed native path; shader replacement remains pass-gated. |
| `0x008052ED`, `0x00805301` | `GeometryDecalShader` transform slot | Skinned case can prepare bone matrices and vertex blending, then calls `sub_765480`. | Non-skinned transform-copy reaches decal geometry. Hardware skin still belongs to the skinned hook gap. |
| `0x007DB1BD` | `WaterShader` transform slot | Calls `sub_765480`, then writes camera-relative water globals. | Do not broaden via global hook; water needs a separate visual decision. |
| `0x007E6729` | `TallGrassShader` transform slot | Calls `sub_765480`, builds inverse/local wind and shadow constants. | Rigid transform-copy reaches normal grass submission, but true grass ripple is shader-owned. |
| `0x007EEBE7` | `PrecipitationShader` transform slot | Calls `sub_765480`, builds local transform data for a two-stream declaration family. | Not a generic object-vertex clone target. |
| `0x007F15F8` | `SpeedTreeLeafShader` transform slot | Calls `sub_765480`, builds inverse local matrix and leaf lighting/camera constants. | Rigid transform-copy can move leaves when routed through normal geometry, but leaf ripple remains shader-owned. |
| `0x0080DDB7` | `SpeedTreeFrondShader` transform slot | Calls `sub_765480`, transforms light vectors into object space. | Needs dedicated SpeedTree treatment if visible coverage is insufficient. |
| `0x008112B8` | `DistantLODShader` transform slot | Calls `sub_765480`, sets shadow/lighting constants. | Leave native unless runtime evidence shows a visible gap. |
| `0x007F85FC`, `0x007F8B96`, `0x007F8CA9`, `0x007F9303`, `0x007F9378` | SpeedTree direct render helpers | Direct SpeedTree submission helpers call `sub_765480` while managing their own shader/render state. | Current `RenderTriGeometries` hook should not be assumed to cover these. Treat as separate SpeedTree decode/implementation work. |

## Skinned transform boundary

The skinned transform helpers remain high risk:

- `sub_765560` uploads renderer world/bone transform state and, for small blend counts, writes
  `D3DTS_WORLD + i` from calculated skin bone matrices.
- `NiDX9Renderer::CalculateBoneMatrixes` at `0x007655F0` rebuilds cached `NiSkinInstance` bone matrix arrays,
  computes camera-relative skin-to-world/bone transforms, and records non-uniform-scale state.

These are not good Moon Sugar detour points. A skinned implementation should hook the draw window after native
setup, not mutate the shared skin/bone cache.

## Decision after build 39

- Keep the current `0x007694D7` transform-copy hook for low-risk rigid world/object motion.
- Keep the current `0x00767410` post-setup vertex replacement hook for the non-skinned `sub_7672F0` draw loop.
- Do not globally detour `sub_765480`. It is shared by water, grass, precipitation, SpeedTree, LOD, Lighting30,
  decal, and generic shader paths.
- Build 40 implements `0x007676F9` as the current hardware-skinned post-setup/post-flush object vertex boundary.
- Treat SpeedTree direct helpers as a separate world/object wobble family, not as generic NIF geometry.

## Validation status after build 40 implementation

- Static evidence identifies the current non-skinned and skinned hook windows for the inspected binary.
- `sub_765560` and `0x007655F0` remain skinned setup evidence only; they are stale as hook-boundary guidance.
- Remaining validation is runtime coverage across representative skinned actor, creature, armor, first-person,
  and third-person draws, plus a separate SpeedTree direct-helper policy. The `0x007676F9` hardware-skinned hook
  mechanics are implemented in build 40 but still require runtime validation.
