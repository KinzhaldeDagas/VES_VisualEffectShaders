# Lighting30 no-skin SM3 variant contracts

MoonSugarEffect build 30 decode artifact for broader exact-gated non-skinned per-vertex deformation.

IDA anchors:

- `0x007FD560`: `B47288[0..7]` are `SM3Lighting.v.hlsl` variants.
- `0x0085E660`: Lighting30 pooled passes bind those vertex variants to native `B46ED8` pixel variants.
- `0x007FD260`: selector masks preserve the native constant-map/state ownership; the plugin replacement still runs after native setup and constant flushing.

The package disassembly is from Oblivion's local `C:\Games\Oblivion\Data\Shaders\shaderpackage019.sdp`, after IDA identified the loader order and pass map. No Fallout material was used.

## Enabled no-skin variants

- `SM3000.vso`: plain no-skin, no vertex color, no projected shadow. Native reads `c0-c3`, `c15`, `c16`; plugin uses Moon Sugar constants at `c26-c27`.
- `SM3002.vso`: no-skin vertex-color variant. Same output contract as `SM3000`, but declares `COLOR0` input and forwards it to `o2`; plugin uses `c26-c27`.
- `SM3004.vso`: no-skin projected-shadow variant. Native reads `ShadowProj c21-c24`, `ShadowProjData c25`, and `ShadowProjTransform c26`; plugin preserves those and moves Moon Sugar constants to `c27-c28`.
- `SM3006.vso`: no-skin vertex-color plus projected-shadow variant. Combines the `SM3002` color path with the `SM3004` projected-shadow path; plugin uses `c27-c28`.

Runtime gating:

- Replacement applies only to Lighting30 pass-table entries whose current pass owns the exact expected `B47288[0/2/4/6]` vertex wrapper and a normal `B46ED8` `SM3Lighting` pixel wrapper.
- Low-light `B46C20` pixel programs remain blocked.
- Skinned `SM3001/SM3003/SM3005/SM3007` remain blocked because they use blend weights/indices and `Bones c31-c84`.

Local compiler verification:

- `MoonSugar_SM3000.vso`
- `MoonSugar_SM3002_VC.vso`
- `MoonSugar_SM3004_PROJ.vso`
- `MoonSugar_SM3006_VC_PROJ.vso`

All four compile as `vs_3_0` with June 2010 `fxc.exe`. Their disassemblies preserve the stock output declaration families. The non-shadow variants preserve `o0/o1/o2/o3/o4/o5/o6/o7`; the projected-shadow variants preserve `o0/o1/o2/o3/o4/o5/o6/o7/o8`, with `o7` as projected-shadow coordinates and `o8` as fog.

Implementation consequence:

Build 30 expands exact-gated per-vertex object deformation from one Lighting30 pass (`SM3000`) to every decoded no-skin SM3Lighting vertex contract in the Lighting30 pass map. The remaining hard gap for broader object coverage is the skinned SM3 path: a state-preserving replacement must reproduce Oblivion's indexed bone-matrix transforms before applying Moon Sugar displacement and must not collide with `Bones c31-c84`.
