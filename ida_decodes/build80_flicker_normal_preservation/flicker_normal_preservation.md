# Build 80 Flicker / Normal Preservation Pass

Authoritative basis: current VES implementation plus previously decoded Oblivion `1.2.0416` Lighting30 support-pass contracts. No new native semantics are claimed.

## Runtime Issue

In-game testing reported white mesh/texture flicker when using HeatShimmer and HeadWound-style effects. The risky implemented overlap was:

- HeadWound opts into world/object wobble.
- The object-vertex replacement path could bind plugin wobble shaders for native support-buffer passes.
- Support buffers include DepthMap, RenderNormals, LocalMap, ZOnly, and SimpleShadow families.
- Perturbing these auxiliary passes can make their output disagree with final visible shading or leave unstable normal/depth data for later engine work.

## Implementation Change

The live object-vertex replacement selector now leaves native support-buffer passes on Oblivion's original shaders. These passes are still counted and decoded, but no plugin wobble shader is bound for them.

Blocked live replacement families:

| Family | Reason |
| --- | --- |
| DepthMap | Native depth/support output should remain stable. |
| RenderNormals | Native normal/refraction-style output should not be perturbed by visual wobble. |
| LocalMap | Native local-map output should remain stable. |
| ZOnly | Native depth-only coverage should not be widened by effect wobble. |
| SimpleShadow | Shadow/source-position support output remains native. |

Visible final-color families such as primary Lighting30, EnvMap, TexEffect, Decal, and the legacy Parallax/Skin pass remain eligible under their existing exact gates.

## Pixel Shader Guard

`VESHeadWoundPS` and `VESHeatShimmerPS` now use viewport-clamped scene sampling. Distorted sample taps that resolve as isolated near-white outliers relative to the stable scene sample are rejected back to the stable sample. This is a guard against screen-space sample flicker, not a terrain/object identity mask.

## Current Guidance

Do not treat support-buffer replacement as release-stable. Future support-pass work must prove, per pass, that native normal/depth/local-map outputs remain correct before live replacement is re-enabled.
