# Build 82 Dim Variants / Shader Fidelity Pass

## Scope

This pass updates the existing command-driven Dim image-space profile and adds Dim color variants. It does not add a native `BSImageSpaceShader` object, material ID mask, object ID mask, or new render hook.

## Implementation

- `VESDim100` now applies Dim darkness terms at 135% of the previous full-strength Dim value.
- `VESDimWhiteInverted`, `VESDimPurple`, and `VESDimDarkRed` are new zero-argument OBSE commands.
- The new profiles reuse the existing `VESDimPS` profile-family shader and pass a Dim variant selector through `MoonSugarProfile.w`.
- Dim color variants use the same full-screen image-space path as `VESDim50` / `VESDim100`.
- All Dim profiles now require the current standalone `VESDimPS.pso`, so stale combined fallback bytecode cannot render new Dim variants as plain Dim.

## Fidelity Pass

- The embedded fallback HLSL Dim branch now uses the same viewport-clamped scene sampling helper as the external shader source.
- All standalone profile-family pixel shaders were regenerated from the current `VESDistortion.fx` source.
- `VESDistortion.pso` remains a compatibility fallback only and is not treated as the current implementation path for new Dim variant behavior.

## Remaining Validation

- Runtime validation should confirm `VESDumpShaderRenderer` reports the Dim profile shader slot loaded when running the new commands.
- The new color variants are screen-space color treatments only. They do not imply object material changes, scene lighting changes, or native image-space shader insertion.
