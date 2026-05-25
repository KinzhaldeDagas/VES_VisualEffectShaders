# Build 87 Dim Variant Runtime Profile Correction

Scope: follow-up crash report for `VESDimWhiteInverted`, `VESDimPurple`, and `VESDimDarkRed`.

## Evidence Used

- Build 82 decode notes say the Dim color variants reuse the existing `VESDimPS` profile-family shader.
- The color selector is carried through `MoonSugarProfile.w`.
- The variants use the same full-screen image-space path as `VESDim50` and `VESDim100`.
- No decoded note identifies a separate native image-space object, hook, material mask, or engine profile required for the three color variants.
- Build 86 opcode registration remains valid at `0x70F0-0x7111`, but the later report that all three Dim color variants still crash means opcode registration is not proven as the crash cause.

## Correction

The implementation now treats the three color commands as Dim-family variants over the existing `VESDim100` runtime profile:

| Public command | Active renderer profile | Variant constant |
| --- | --- | --- |
| `VESDimWhiteInverted` | `VESDim100` | `2.0` |
| `VESDimPurple` | `VESDim100` | `3.0` |
| `VESDimDarkRed` | `VESDim100` | `4.0` |

The command identity is preserved for console output and renderer diagnostics through explicit active-profile display fields. The shader constant path still receives the variant value through `MoonSugarProfile.w`.

## Semantics Boundary

This is a plugin-side state correction. It does not add a new Oblivion image-space shader object, hook, depth path, material/object mask, or new shader bytecode. It also does not claim the exact crash mechanism is proven until in-game testing confirms the three commands no longer crash.

## Validation

- Release x86 build: passed.
- In-game validation still required:

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
```
