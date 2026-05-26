# Build 89 Profile Fallback Fidelity

Scope: prevent current command-driven profile effects from silently rendering stale combined fallback semantics.

## Evidence Used

- Build 72 records the normal shipped path as profile-family pixel shaders loaded from `Data\Shaders\VES\VES*PS.pso`.
- Build 74 optimized On Fire in `VESOnFirePS`.
- Build 75 and Build 76 introduced Rain and Frost as profile-family shader effects.
- Build 77 introduced `VESDepthMaskDebug` as a diagnostic profile that depends on current depth-state constants and depth-backed shader behavior.
- Builds 81, 82, and 83 already require current standalone bytecode for HeadWound/HeatShimmer, Dim, and Blind where stale fallback behavior was known to be unsafe or misleading.

## Correction

`EffectProfileRequiresCurrentProfileShader` now also covers:

- `VESOnFire25`, `VESOnFire50`, `VESOnFire75`, `VESOnFire100`
- `VESRain50`, `VESRain75`, `VESRain100`
- `VESFrost50`, `VESFrost75`, `VESFrost100`
- `VESDepthMaskDebug`

If one of those profile slots is unavailable, `GetActivePixelShader` returns `nullptr` and the renderer logs the unavailable active profile shader instead of using the combined `VESDistortion.pso` dispatcher.

## Semantics Boundary

This pass does not change shader visuals, command opcodes, hook addresses, depth behavior, or profile constants. It only prevents stale compatibility fallback bytecode from being treated as the current implementation of profile-family effects.

## Verification

- Release x86 build passed with `0` warnings and `0` errors.
- Package asset parity confirmed source, package, and out shader bytecode match for the shipped profile-family `.pso` files.
- Package layout check confirmed the release ZIP contains `Data\...` paths only, with no README, changelog, or `.ini`.
- In-game validation should confirm `VESDumpShaderRenderer` reports the expected active profile shader slot for representative commands.
