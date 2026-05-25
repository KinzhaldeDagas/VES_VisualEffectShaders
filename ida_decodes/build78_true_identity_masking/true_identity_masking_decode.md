# Build 78 True Terrain/Object Identity Masking Decode

Authoritative source: live Oblivion IDA database for `Oblivion.exe` 1.2.0416. Fallout material was not used.

## Current Verdict

No validated true terrain/object identity mask was found in the inspected Oblivion paths. The decoded engine paths expose object pointers during cull/render traversal and expose native auxiliary buffers such as depth, render normals, local map, canopy shadow, and refraction. None of the inspected targets is proven to encode terrain material IDs, object IDs, actor IDs, form IDs, or a plugin-neutral per-object identity channel that the VES image-space shader can sample.

The safe implementation status remains:

- Use captured world depth only as a depth/coherence cue.
- Treat `VESDepthMaskDebug` as validation tooling, not identity masking.
- Do not wire HeatShimmer, OnFire, Rain, Frost, or other screen effects to an object-ID or terrain-ID semantic.
- Treat a plugin-owned mask/prepass as future work requiring explicit implementation and runtime validation.

## Evidence Table

| Address / path | Observed behavior | Identity-mask conclusion |
| --- | --- | --- |
| `0x007D2070` | Walks a caller-owned object list, reads the object pointer from list node `+8`, filters by shader/property state, selects hardcoded native shader IDs `0x10`, `0x14`, `0x154`, or `0x155`, then calls `NiAVObject_Render`. | Has object pointers during traversal, but does not create or expose a sampled object-ID buffer. |
| `0x00813300` | Builds a temporary `BSShaderAccumulator` and `NiCullingProcess`, then calls `0x007D2070` over its provided object list before restoring the original accumulator. | Specialized offscreen/object path. It is a pattern for isolated rendering, not a reusable world identity API. |
| `0x007D21F0` | Finalizes the same object-list system, updates eligible shader properties, resets `dword_B42E90` / `dword_B42EB8`, and frees list nodes. | Confirms list ownership and cleanup are native-subsystem-specific. |
| `0x007A9820` | Forces `dword_B42E90` to a shader/pass ID, stores `dword_B42EB8` as the active render pass, refreshes shader property state, and calls the object render vtable. | Native shader selection is global/pass-owned. Hijacking this for VES identity would collide with renderer-owned state. |
| `0x007AC9A0` | Flushes accumulator pass buckets and dispatches render-pass nodes through `0x007A9820` or special native list paths. | Accumulator buckets expose visible render passes, not a plugin-neutral identity target. |
| `0x007B4920` | Maps render-pass IDs to names including `BSSM_DEPTHMAP`, `BSSM_RENDERNORMALS`, `BSSM_LOCALMAP`, `BSSM_3XDEPTHMAP`, `BSSM_3XRENDERNORMALS`, `BSSM_3XLOCALMAP`, land, grass, water, and refraction-style passes. | The pass-name table contains auxiliary/support pass names, but no observed `ID`, `object mask`, `terrain ID`, or equivalent identity pass. |
| `0x004CE460` | `TESObjectCELL::CreateCanopyShadowMaskForCell` creates a `64x64` `NiRenderedTexture`, attaches `ExtraCellCanopyShadowMask`, locks the texture data, and clears it. | This is a cell canopy-shadow texture/mask, not terrain or object identity. |
| `0x004826F0` | `ShadowCanopyPass` builds screen/quad geometry for cell canopy masks and renders into a target before assigning `CanopySadowMap`. | Canopy shadow is a visual terrain/cell shadow input, not object identity. |
| `0x004D0190` / `0x004D06C0` | Canopy/shadow capture allocates temporary rendered textures, hides/restores scene nodes, renders via `sub_70C0B0`, and restores state. | Useful offscreen-target precedent only; no identity output was observed. |
| `0x007CD090` / `0x007CEFD0` | Loads terrain/land shader programs including `land`, `landlighting`, `depthmap`, `renderNormals`, and `localMap` variants. | Terrain shader variants are material/support passes; no terrain material-ID buffer is proven. |
| `0x00811640` / `0x007E6B10` | Loads DistantLOD and tallgrass shader programs. | Terrain/grass rendering evidence only; no identity target. |
| `0x00800E20` / `0x00800750` | Native `RefractionShader` uses a two-input image-space pattern and `refraction_P20.p.hlsl`. | Refraction is the strongest native two-texture composite pattern, but the second texture is object/property-owned distortion data, not identity. |

## Decoded Non-Identity Buffers

| Buffer/path | Confirmed meaning | Why it cannot be promoted to identity |
| --- | --- | --- |
| Captured world depth | Depth/coherence cue from the validated world render order. | Contains depth-like visibility, not object/form/material IDs. |
| Lighting30 DepthMap | View-depth-like RGB plus base alpha through `SM3DepthMap.p.hlsl`. | Encodes depth, not identity. |
| RenderNormals | Normal/refraction-style packed vector outputs. | Encodes vectors/power, not object IDs. |
| LocalMap | Native local-map support pass. | No decoded output shows object/form/terrain IDs. |
| Canopy shadow mask | Cell/tree canopy shadow texture attached through `ExtraCellCanopyShadowMask`. | Cell visual shadow mask, not object identity. |
| Refraction texture | Object/property-owned distortion texture consumed by native image-space refraction. | Useful architecture, but not an ID buffer. |

## Implementation Guidance

Do not implement a VES "true identity mask" by reusing native shader IDs, accumulator buckets, canopy shadow textures, refraction flags, local-map passes, or DepthMap outputs.

The first defensible implementation path is still a plugin-owned mask/prepass:

1. Allocate a plugin-owned render target with an explicitly documented format.
2. Collect visible candidates through a plugin-owned visible-array cull or a tightly gated accumulator observation path.
3. Draw only candidates whose live geometry buffers and shader state are understood.
4. Encode only a documented plugin semantic, such as binary world/object silhouette or coarse class color.
5. Bind that plugin-owned texture to the VES image-space shader as a separate sampler.
6. Treat terrain, SpeedTree, skinned actors, particles, water, and translucent objects as separate validation gates.

Until that exists, public wording should remain "depth-derived scene/terrain masking" or "screen/depth-buffer masking", not "true terrain/object identity masking".

## Remaining Unknowns

- Whether any editor/debug-only picking, selection, or Havok probe path can be safely repurposed at runtime. No inspected render path supports this yet.
- Whether terrain material layer data can be read CPU-side and rasterized into a plugin-owned mask target without relying on the native terrain shader. This is not decoded.
- Whether a plugin-owned second cull can include terrain, SpeedTree, skinned actors, and translucent objects without unacceptable cost or state risk.
