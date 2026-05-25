# Lighting30 Decal Implementation Contract

Build 37 implements the decoded visible Decal auxiliary family as a dedicated `vs_3_0` vertex-shader clone. This path does not reuse the primary `SM3Lighting`, EnvMap, or TexEffect clones.

## Runtime Gate

- The active pass must be `B473D0[40]` or `B473D0[41]`.
- The active vertex wrapper must exactly match `B47288[17]` (`SM3017 Decal MAXDECALS8`).
- The active pixel wrapper must exactly match native `B46ED8[24]` or `B46ED8[25]`.
- Native Decal pixel shaders, samplers, `PSNumDecals`, and `PSDecalOffsets` remain owned by Oblivion.

## Variants

- `SM3017 Decal MAXDECALS8`: no skin, pass rows `40..41`, Moon Sugar constants at `c26-c27`.

## Constant Safety

- Native Decal owns `ModelViewProj c0-c3`, `DecalFade c32-c39`, and `DecalProjection c40-c70`.
- The clone uses `c26-c27`, avoiding the native fade/projection block.
- `DecalProjection` keeps Oblivion's sparse row layout: slot rows `c40-c42`, `c44-c46`, `c48-c50`, `c52-c54`, `c56-c58`, `c60-c62`, `c64-c66`, and `c68-c70`.

## Output Contract

- The clone preserves stock `SM3017` inputs: `POSITION0` and `NORMAL0`.
- The clone preserves stock outputs: clip position plus `TEXCOORD0..7`, each as projected decal coordinate/fade triples.
- Displacement is applied before clip projection and before every decal projection coordinate is computed.
- The normal-dependent fade path continues to use Oblivion's native normal and projection rows.

## Verification

- `MoonSugar_SM3017_DECAL.vso` compiled locally with June 2010 `fxc`.
- Disassembly confirms `MoonSugar0 c26`, `MoonSugar1 c27`, `DecalFade c32-c39`, and projection rows through `c70`.
- Disassembly confirms the output declaration family `POSITION`, `TEXCOORD0`, `TEXCOORD1`, `TEXCOORD2`, `TEXCOORD3`, `TEXCOORD4`, `TEXCOORD5`, `TEXCOORD6`, and `TEXCOORD7`.
