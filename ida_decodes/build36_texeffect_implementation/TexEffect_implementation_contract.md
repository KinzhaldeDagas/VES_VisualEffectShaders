# Lighting30 TexEffect Implementation Contract

Build 36 implements the decoded visible TexEffect auxiliary family as dedicated `vs_3_0` vertex-shader clones. This path does not reuse the primary `SM3Lighting` or EnvMap clones.

## Runtime Gate

- The active pass must be `B473D0[52]` or `B473D0[53]`.
- The active vertex wrapper must exactly match `B47288[28]` or `B47288[29]`.
- The active pixel wrapper must exactly match native `B46ED8[35]` or `B46ED8[36]`.
- Native TexEffect pixel shaders, samplers, fill/rim/fVars constants, and alternate shader-slot setup remain owned by Oblivion.

## Variants

- `SM3028 TexEffect`: no skin, pass row `52`, Moon Sugar constants at `c26-c27`.
- `SM3029 TexEffect SKIN`: skinned, pass row `53`, Moon Sugar constants at `c68-c69`.

## Constant Safety

- `SM3028` uses native `ModelViewProj c0-c3`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, and `FogColor c13`; `c26-c27` is free for the Moon Sugar clone constants.
- `SM3029` uses native `SkinModelViewProj c4-c7`, `EyePosition c8`, `UOffset c9`, `VOffset c10`, `FogParam c12`, `FogColor c13`, and `Bones c14-c67`; `c68-c69` avoids the native bone array.

## Output Contract

- Both clones preserve the native TexEffect output family: clip position, `TEXCOORD0` base UV, `TEXCOORD1` source/offset UV, `TEXCOORD3` tangent-space view vector, and `COLOR1` fog/color blend.
- Displacement is applied before clip projection, before source/offset UV generation, before tangent-space view-vector generation, and before fog distance generation.
- The native pixel shader continues to consume `NormalMap s0`, `SourceTexture s1`, `FillColor c0`, `RimColor c1`, and `fVars c2`.

## Verification

- `MoonSugar_SM3028_TEXEFFECT.vso` compiled locally with June 2010 `fxc`.
- `MoonSugar_SM3029_TEXEFFECT_SKIN.vso` compiled locally with June 2010 `fxc`.
- Disassembly confirms `SM3029` preserves `Bones c14-c67` and places Moon Sugar constants at `c68-c69`.
