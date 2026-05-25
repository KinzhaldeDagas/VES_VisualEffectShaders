# Lighting30 skinned SM3 variant contracts

MoonSugarEffect build 31 decode artifact for exact-gated non-rigid per-vertex deformation on Lighting30 skinned SM3 contracts.

IDA anchors:

- `0x007FD560`: `B47288[1/3/5/7]` are the skinned `SM3Lighting.v.hlsl` variants.
- `0x0085E660`: pooled Lighting30 passes bind those skinned vertex wrappers to native `B46ED8` pixel wrappers.
- `0x007FD260`: selector masks and constant-map ownership remain native; the plugin replacement is still a post-native-setup D3D vertex-shader override.

Direct Oblivion shader-package disassembly shows:

- `SM3001.vso`: skinned, no vertex color, no projected shadow.
- `SM3003.vso`: skinned with vertex color.
- `SM3005.vso`: skinned with projected shadow.
- `SM3007.vso`: skinned with vertex color and projected shadow.

Common skinned contract:

- `SkinModelViewProj`: `c1-c4`
- `FogParam`: `c15`
- `FogColor`: `c16`
- `Bones[54]`: `c31-c84`
- Blend indices are multiplied by `765.01001` and converted through `mova a0`, matching Oblivion's normalized UBYTE-style indexed bone rows.
- The stock shaders blend normal, tangent, binormal, and position through the same indexed bone rows before writing `o3/o4/o5/o6`.

Projected-shadow variants additionally use:

- `ShadowProj`: `c21-c24`
- `ShadowProjData`: `c25`
- `ShadowProjTransform`: `c26`

Build 31 implementation:

- Adds a separate skinned `vs_3_0` clone source from the no-skin Lighting30 clone.
- Applies Moon Sugar displacement after native-style bone blending, so animation/deformation is preserved first and drug wobble is applied in the skinned surface space.
- Uses `c27-c28` for Moon Sugar constants on every skinned variant, avoiding `ShadowProjTransform c26` and `Bones c31-c84`.
- Runtime still requires exact current-pass wrapper matches against `B47288[1/3/5/7]` and normal `B46ED8` SM3Lighting pixel wrappers.

Local compiler verification:

- `MoonSugar_SM3001_SKIN.vso`
- `MoonSugar_SM3003_SKIN_VC.vso`
- `MoonSugar_SM3005_SKIN_PROJ.vso`
- `MoonSugar_SM3007_SKIN_VC_PROJ.vso`

All four compile as `vs_3_0` with June 2010 `fxc.exe` and declare the expected blend weight/index inputs, indexed `Bones c31-c84`, and stock output families.

Remaining broader-coverage boundary:

Within the decoded Lighting30 SM3 family, exact-gated replacement is implemented for all eight primary `SM3Lighting.v.hlsl` variants (`0..7`). Remaining object coverage outside this family still depends on decoding and cloning auxiliary Lighting30 families, low-light pixel routing, and non-Lighting30 shader families.
