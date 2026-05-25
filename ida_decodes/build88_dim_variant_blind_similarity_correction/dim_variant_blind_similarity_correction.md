# Build 88 Dim Variant / Blind Similarity Correction

Scope: visual report that `VESDimWhiteInverted`, `VESDimPurple`, and `VESDimDarkRed` looked like Blind variants with different colors.

## Evidence Used

- Build 60 defines Dim as a screen-space darkening/desaturation pass only.
- Build 82 defines the color variants as Dim-family variants selected by `MoonSugarProfile.w`.
- Build 83 keeps Blind as a separate screen-space profile with blur, peripheral falloff, ghosting, and distance/softness cues.
- Build 87 keeps the color commands on the existing Dim runtime profile path and passes the variant selector separately.

## Observed Implementation Issue

The Dim branch did not call `BlindPS`, but its color-variant branch used a radial vignette and heavy luma-only replacement. That made the color variants read like Blind-style peripheral occlusion even though the renderer routed them through `VESDimPS`.

## Correction

`DimPS` now keeps the color variants as a uniform, single-sample screen treatment:

- removed the Dim-variant radial radius/vignette falloff;
- removed luma-only full replacement for Purple and Dark Red;
- kept one viewport-clamped scene sample through `MoonSugarSceneSample`;
- kept the Dim darkness boost and `MoonSugarProfile.w` variant selector;
- applies Purple and Dark Red as uniform tints over the dimmed scene;
- applies White/Inverted as a uniform inverted/white treatment over the dimmed scene.

`BlindPS` remains the only profile-family shader with the multi-sample blur, peripheral falloff, ghost/distance cue, and heavy edge occlusion behavior.

## Validation

- `VESDimPS` compiled successfully as `ps_3_0`.
- Disassembly reports about 43 instruction slots and 1 texture read.
- Release x86 plugin build passed.
- In-game visual validation still required.

```text
VESDimWhiteInverted
VESDumpShaderRenderer
VESStop
VESDimPurple
VESDumpShaderRenderer
VESStop
VESDimDarkRed
VESDumpShaderRenderer
VESStop
VESBlind100
VESDumpShaderRenderer
VESStop
```
