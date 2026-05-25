# Build 83 Blind Water-Safety Pass

## Scope

This pass targets the reported issue where Blind could make water disappear.

## Evidence And Reasoning

- Blind profiles previously opted into the texture-backed depth path through `EffectProfileUsesDepth`.
- `BlindPS` previously sampled `DepthSampler` to derive its distance cue when depth was available.
- Existing Oblivion decode notes mark water, reflection, refraction, and depth/support paths as sensitive and not interchangeable with ordinary image-space presentation.

The exact in-game water failure mode has not been independently reproduced in this pass. The correction is conservative: remove Blind from the depth path rather than adding more water-specific assumptions.

## Implementation

- `EffectProfileUsesDepth` now returns true only for `VESHeatShimmer50`, `VESHeatShimmer100`, and `VESDepthMaskDebug`.
- `BlindPS` no longer samples `DepthSampler`; it derives distance/softness from screen-space composition only.
- Blind profiles now require the current standalone `VESBlindPS.pso`, so stale combined/embedded fallback bytecode cannot reintroduce the old depth-sampling Blind path.

## Remaining Validation

- Runtime validation should test `VESBlind25/50/75/100` near exterior water and confirm water remains visible.
- `VESDumpShaderRenderer` should report the Blind profile with `depth=0` in the effect-start pipeline log.
- HeatShimmer and DepthMaskDebug remain the only current depth-consuming profile paths.
