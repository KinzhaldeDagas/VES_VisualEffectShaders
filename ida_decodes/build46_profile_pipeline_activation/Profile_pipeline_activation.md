# Profile pipeline activation

The v0.0.52 log from `2026-05-19 21:06` showed:

- `Blind50` started and expired normally;
- texture-backed depth capture activated with `INTZ`;
- embedded image-space bytecode loaded;
- the first image-space frame rendered;
- no camera, geometry, or object vertex shader activity was logged.

The source-side reason was `EffectProfileUsesWorldWobble`: before build 53 it returned true only for the `MoonSugar` profile. The absence of camera, geometry, and object-vertex activity for `Blind50` is correct because blind profiles are image-space/depth effects and do not participate in world wobble.

## Build 54 correction

Build 53 briefly widened the source-side gate to all plugin profiles. Build 54 narrows the world shader pipeline to the profiles that intentionally use wobble:

- `MoonSugar`
- `HeadWoundSmall`
- `HeadWoundBig`

The blind profiles remain image-space/depth only:

- `Blind25`
- `Blind50`
- `Blind75`

The per-profile world-wobble scale is not new Oblivion semantics. It reuses the plugin's existing profile severity values for non-blind wobble profiles:

- `MoonSugar`: `1.0`
- `HeadWoundSmall`: `0.58`
- `HeadWoundBig`: `1.0`

Blind profiles report `worldWobble=0` and `worldScale=0.000` in the effect-start pipeline log.

Oblivion shader replacement eligibility is unchanged. Object vertex replacements still require the decoded pass-table/program gates before any D3D shader handle is installed for a draw.

## Diagnostics

Build 54 logs:

- an effect-start pipeline line with depth and world-wobble participation;
- an automatic pipeline summary on stop or expiration with image-space frames, depth capture state, camera/geometry/object hook counts, Lighting30/Parallax/Skin pass census totals, and applied masks.

This is intended to separate plugin profile gating from Oblivion pass eligibility in future logs.
