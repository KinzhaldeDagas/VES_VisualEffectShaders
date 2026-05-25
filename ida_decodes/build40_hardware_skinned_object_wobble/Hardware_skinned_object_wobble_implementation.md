# Build 40 Hardware-Skinned Object Wobble Implementation

Evidence source: live Oblivion IDA database for `Oblivion.exe` 1.2.0.416. Fallout material was not used for this implementation pass.

Status after cleanup, 2026-05-21: this file documents the Build40 hook mechanics. Use
`ez_obse_plugin_example/docs/current_hook_contracts.md` for active hook status and ship guidance.

## Largest Gap Targeted

Build 39 identified the remaining world/object wobble coverage gap as the hardware-skinned draw loop in
`SkinnedRenderTriGeometrySetup` (`sub_767520`).

The live IDA bytes at `0x007676F9` are:

```text
33 C0 39 47 44 89 44 24 14 89 44 24 18 76 68 8B
```

The implemented patch overwrites only the first five bytes:

```asm
0x007676F9  xor eax, eax
0x007676FB  cmp [edi+44h], eax
```

and re-emits them before returning to `0x007676FE`.

## Decoded Register Contract

At `0x007676F9`, after `SetupShaderPrograms` at `0x007676E4` and the shader constant-manager flush at `0x007676F7`:

| Register | Decoded value |
| --- | --- |
| `esi` | `NiDX9Renderer*` |
| `ebx` | active `NiD3DShaderInterface*` |
| `ebp` | current skin partition |
| `edi` | returned partition `NiGeometryBufferData` / buffer data |

No stable `NiGeometry*` register is available at this hook window, but the caller's stack arguments remain intact.

Fidelity pass correction: while no geometry register survives at the hook window, the original first stack
argument from the `0x007694BD` call is still recoverable. At `0x007676F9`, the live stack slot `[esp+0x30]`
contains the original `NiGeometry*`. The OBSE naked hook reads that value as `[esp+0x54]` after its
`pushfd/pushad` prologue and passes it to the skinned wrapper. `ebp` remains a fallback seed only if that stack
slot is unexpectedly null.

## OBSE Implementation

The plugin now installs a second object vertex hook:

```text
0x00767410  NonSkinnedPostSetupVertexReplacementHook in NonSkinnedRenderTriGeometrySetup (sub_7672F0)
0x007676F9  SkinnedPostSetupVertexReplacementHook in SkinnedRenderTriGeometrySetup (sub_767520)
```

The hardware-skinned hook calls:

```cpp
ApplyMoonSugarSkinnedObjectVertexShader(renderer, shader, geometry, skinPartition, bufferData)
```

with arguments sourced from `esi`, `ebx`, `[esp+0x30]`, `ebp`, and `edi`.

The shared object-vertex replacement helper now accepts a `skinnedDraw` flag. For skinned draws it is intentionally conservative and only allows decoded skinned-compatible replacement clones:

- Lighting30 `SM3001`, `SM3003`, `SM3005`, `SM3007`.
- EnvMap `SM3010`, `SM3011`.
- TexEffect `SM3029`.

It rejects the generic `PAR2016/SKIN2008` clone, non-skinned Lighting30/EnvMap/TexEffect variants, and Decal `SM3017` on the skinned hook because those contracts do not preserve hardware skinning inputs and bone constants for this path.

## Validation Status

- Static IDA evidence identifies the `0x007676F9` post-setup/post-flush hook window in the inspected binary.
- The hook is exact-gated and only routes skinned-compatible decoded clones.
- Remaining validation: representative armor, creature, NPC, first-person, and third-person skinned draws, plus separate policy for direct SpeedTree helper paths.
