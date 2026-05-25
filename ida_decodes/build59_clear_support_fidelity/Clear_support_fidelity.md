# Build 59 clear support fidelity pass

Oblivion IDA database instance `nf52` is the evidence source for this pass. No Fallout material was used.

Status after cleanup, 2026-05-21: this file is current evidence for superseding Build42 clear-support clone
guidance. Use `ez_obse_plugin_example/docs/current_hook_contracts.md` for the active support/clear ship policy.

## Observed Oblivion bindings

- `sub_85E660` (`0x0085E660`) builds the Lighting30 pass pool.
- Pass `47` binds `B47288[23]` / `SM3023 RenderNormals CLEAR` with `B46ED8[31]` / `SM3031 RenderNormals CLEAR`.
- Pass `48` binds `B47288[24]` / `SM3024 RenderNormals CLEAR SKIN` with `B46ED8[32]` / `SM3032 RenderNormals CLEAR`.
- Pass `51` binds `B47288[27]` / `SM3027 LocalMap CLEAR` with `B46ED8[34]` / `SM3034 LocalMap CLEAR`.

The direct Oblivion shaderpackage disassembly already captured in `build33_lighting30_auxiliary_contracts` and `build38_support_pass_decision` shows the relevant clear vertex programs only provide clip coverage, while the paired pixel programs write constant clear values.

## Implementation decision

VES build 59 blocks live vertex-shader replacement for pass `47`, pass `48`, and pass `51`. These passes are clear support-buffer coverage passes, not visible material shading passes. Replacing their vertex programs can deform the clear coverage and leave stale support-buffer regions.

Diagnostics now report the affected vertex/pass/replacement plan as `blocked:clearSupportPass`. Non-clear RenderNormals, LocalMap, DepthMap, SimpleShadow, ZOnly, EnvMap, TexEffect, Decal, and primary Lighting30 paths remain governed by their decoded contracts and existing exact pass/wrapper gates.

## Build 61 cleanup

The blocked clear replacement clones are no longer part of the live support replacement variant enum, bytecode
generator, or generated embedded vertex bytecode table. The decoded native clear labels remain in the Lighting30
contract tables so diagnostics can still identify `SM3023`, `SM3024`, `SM3027`, `SM3031`, `SM3032`, and `SM3034`
and report `blocked:clearSupportPass` without carrying stale plugin replacement bytecode for those passes.
