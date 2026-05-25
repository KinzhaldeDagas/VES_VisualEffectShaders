# Build 81 Fidelity Correction Pass

## Scope

This pass corrects documentation and runtime behavior that could overstate the current Build 80 flicker/normal-preservation implementation.

## Evidence

- Build 80 changed `HeadWoundPS` and `HeatShimmerPS` to clamp viewport samples and reject isolated near-white outlier taps back to a stable scene sample.
- Build 80 also blocks live object-vertex replacement on native support-buffer families: DepthMap, RenderNormals, LocalMap, ZOnly, and SimpleShadow.
- The combined `VESDistortion.pso` was retained as compatibility fallback, but it was not treated as the validated path for the Build 80 HeadWound/HeatShimmer sample-stability changes in this pass.

## Implementation Changes

- `VESHeadWound25`, `VESHeadWound50`, `VESHeadWound75`, `VESHeatShimmer50`, and `VESHeatShimmer100` now require their standalone profile pixel shader when rendering.
- If the required standalone profile shader is missing, those profiles fail closed instead of silently using the combined/embedded fallback.
- Runtime debug logging now distinguishes a missing active pixel shader from a `DrawPrimitiveUP` failure.

## Documentation Changes

- Historical Build 41, Build 42, and Build 43 notes now state that Build 80 supersedes their live support-buffer replacement policy.
- Current hook documentation now describes DepthMap support as pass identification and diagnostics, not live vertex replacement.
- Public deploy README now notes that HeadWound and HeatShimmer require their standalone `.pso` files for the current flicker/normal-preservation path.

## Remaining Uncertainty

- This pass does not prove that all reported flicker sources are removed. It only prevents the known Build 80 HeadWound/HeatShimmer stability path from being bypassed by an older fallback shader.
- Support-buffer replacement remains decoded/counted but not release-stable.
- The combined `VESDistortion.pso` remains useful as a compatibility fallback for profiles that do not require the current HeadWound/HeatShimmer stability patch, but it should not be used as evidence for those profile-specific changes unless regenerated and verified.
