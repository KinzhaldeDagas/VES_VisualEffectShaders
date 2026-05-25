# Build 79 Plugin-Owned Mask/Prepass Contract

Authoritative source: live Oblivion IDA database for `Oblivion.exe` 1.2.0416 plus the current VES plugin implementation. Fallout material was not used.

## Current Verdict

Build 78 did not find a native terrain/object identity buffer. Build 79 therefore treats "true terrain/object masking" as future plugin-owned work, not as a native semantic that can be wired from DepthMap, RenderNormals, LocalMap, canopy shadow, or refraction.

The only plugin-side implementation added in this pass is read-only runtime diagnostics on the existing world-render wrapper. `VESDumpShaderRenderer` now reports whether the hooked `sub_70C0B0(camera, sceneGraph, cullingProcess, visibleGeo)` calls receive:

- the current world camera,
- the current world scene graph,
- the scene graph's current culling process,
- normal render mode,
- an explicit `visibleGeo` argument,
- a non-null `NiCullingProcess::VisibleGeo` pointer at culling-process offset `+0x08`.

This is not a mask draw and not identity masking. It is a validation surface for deciding whether a second-cull/plugin-owned prepass can be implemented without relying on guessed engine state.

## Evidence Used

| Address / field | Observed behavior | Build 79 use |
| --- | --- | --- |
| `0x0040CCD3`, `0x0040CE48` | `NiRenderer_Render` call sites into `sub_70C0B0`; current plugin already wraps them with expected-byte validation. | Safe place to observe world-render call arguments already crossing the plugin wrapper. |
| `0x0070C0B0` | Wrapper calls `SetCameraViewProj`, then either processes an explicit visible array and submits it through `sub_70C000`, or calls `NiCullingProcess::Process(..., 0)`. | Do not use as collection-only when `visibleGeo` is non-null because it immediately submits the list. |
| `0x0070DF30` | `NiCullingProcess` constructor stores `VisibleGeo` at `+0x08`; normal scene graph construction passes null. | Read-only diagnostic checks culling-process `+0x08`; no mutation. |
| `0x0070E0A0` | `NiCullingProcess::Process` temporarily installs an explicit visible array only when the fourth argument is non-null. | Candidate collection API, but not called by Build 79 implementation. |
| `0x0070E1A0` | `NiCullingProcess::OnVisible` appends `NiGeometry*` into `{ data, count, capacity, grow }` when `VisibleGeo` is non-null; otherwise routes through the active accumulator. | Confirms visible-array structure for a future diagnostic collector. |
| `0x00732200` | Visible-array grow helper reallocates pointer storage through `FormHeapAlloc` / `FormHeapFree`. | A future plugin-owned visible array must either use compatible allocation or avoid engine growth. |
| `SceneGraph +0xDC`, `SceneGraph +0xE4` | Decode notes identify camera and culling-process fields. | Runtime diagnostics compare wrapper arguments to the current scene graph fields. |

## Safe Current Implementation

The plugin now records these counters:

| Counter | Meaning |
| --- | --- |
| `worldCalls` | Calls observed by the existing world-render wrapper. |
| `worldCamera` | Calls whose camera pointer matches the current world scene graph camera. |
| `worldScene` | Calls whose scene graph pointer matches `g_worldScenegraph`. |
| `sceneCull` | Calls whose culling-process argument matches `SceneGraph +0xE4`. |
| `normalMode` | Calls observed while render mode is `0`. |
| `explicitVisibleArg` | Calls with a non-null fourth `visibleGeo` argument. |
| `cullingVisibleGeo` | Calls where `cullingProcess +0x08` is non-null. |
| `missingCull` | Calls with a null culling-process argument. |

Expected result for the normal decoded world path is usually `explicitVisibleArg=0` and `cullingVisibleGeo=0`. Any non-zero value should be treated as runtime evidence to inspect, not as permission to reuse that list for VES identity.

## Not Implemented

The following remain unimplemented and must not be described as shipped:

- plugin-owned visible-array collection,
- plugin-owned render target for a mask/prepass,
- manual live-`BuffData` draw submission,
- terrain material IDs,
- object IDs, actor IDs, form IDs, or plugin-neutral identity colors,
- terrain, SpeedTree, skinned actor, particle, water, or translucent-object mask support.

## Candidate Next Implementation Gate

A conservative first real prepass should be staged in this order:

1. Add a command-gated visible-array collector that calls `NiCullingProcess::Process(camera, sceneGraph, visibleArray)` directly, not `sub_70C0B0`, and only while camera, scene graph, render mode, and culling-process pointers match the observed world path.
2. Allocate visible-array storage compatibly with the engine grow path or use a fixed no-growth collector through an explicitly decoded append override. Do not mix CRT allocation with `sub_732200` growth/free behavior.
3. Count and classify collected `NiGeometry*` pointers without drawing them.
4. Decode and validate enough `NiGeometry`, geometry data, `BuffData`, `VBChip`, declaration/FVF, and index-buffer layout to submit only already-live non-skinned geometry.
5. Add a plugin-owned render target and flat binary silhouette shader only after the collection and buffer-read contracts are validated.
6. Bind that plugin-owned texture to the image-space pass as a documented VES mask sampler.

## Qualitative Completion Estimate

| Area | Estimate |
| --- | --- |
| Native true identity buffer search across inspected render/object/offscreen paths | High confidence negative for the currently inspected paths |
| Visible-array ABI shape | Moderate confidence for fields and append behavior |
| Runtime availability of visible arrays in normal world calls | Now instrumented; requires in-game `VESDumpShaderRenderer` evidence |
| Plugin-owned collection-only second cull | Plausible, but not implemented |
| Plugin-owned manual mask draw | Architectural evidence only; requires more layout decode and runtime validation |
| True terrain/object identity masking | Not implemented |

## Ship Guidance

Ship wording should remain "depth-backed scene masking" or "screen/depth-buffer masking" for current VES effects. A plugin-owned prepass may be described as "under investigation" or "diagnostic instrumentation present." Do not claim true terrain/object identity masking until a plugin-owned mask target is created, populated, sampled, and validated in runtime scenes.
