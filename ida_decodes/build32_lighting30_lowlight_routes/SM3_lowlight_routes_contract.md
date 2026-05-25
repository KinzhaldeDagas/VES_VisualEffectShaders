# Lighting30 SM3 Low-Light Route Contract

Build 32 closes the low-light routing gap for the primary Lighting30 SM3 vertex clones.

Authoritative Oblivion observations:

- `0x007FD560` builds the vertex program table at `0x00B47288`. Entries `0..7` are the primary `SM3Lighting.v.hlsl` variants: no-skin/skinned, vertex color, projected shadow, and their combinations.
- `0x007FDDE0` builds the normal pixel program table at `0x00B46ED8`. Entries `0..19` are the normal `SM3Lighting.p.hlsl` variants.
- `0x007FDDE0` also builds the low-light pixel program table at `0x00B46C20`. Entries `0..19` are the aligned `SM3LLLighting` variants.
- `0x0085E660` and the pass map remain the source of the pass index to vertex/pixel program index pairing.

Implementation rule:

- A Moon Sugar Lighting30 vertex replacement is allowed only when the active vertex wrapper matches `B47288[0..7]`.
- The active pixel wrapper may match either normal `B46ED8[pixelIndex]` or low-light `B46C20[pixelIndex]`, provided the pixel index is still in the primary `0..19` lighting range.
- The plugin does not replace the pixel shader, mutate the pass table, or alter selector/constant-mask state. It binds only the plugin-owned vertex clone after native setup and native constant flushing.

Result:

- Existing no-skin and skinned `vs_3_0` clones now cover both normal and low-light SM3Lighting draws.
- Auxiliary Lighting30 families such as EnvMap, SimpleShadow, Decal, DepthMap, RenderNormals, LocalMap, TexEffect, and ZOnly remain blocked until their vertex and pixel contracts are cloned separately.

No Fallout material was used for this pass.
