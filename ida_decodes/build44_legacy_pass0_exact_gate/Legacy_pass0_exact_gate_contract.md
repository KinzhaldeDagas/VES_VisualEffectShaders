# Legacy pass 0 exact gate contract

This pass tightens the existing `PAR2016/SKIN2008` object vertex replacement so it only runs when the live Oblivion shader object matches the decoded pass-0 bind sites. No Fallout behavior is used for eligibility.

## Authoritative Oblivion sources

- `sub_864A60` Parallax pass 0:
  - `0x00864DC3` binds the vertex shader stored at `this + 0xDC`, matching `PAR2016.vso` (`vs_2_0`).
  - `0x00864E06` binds the pixel shader stored at `this + 0x15C`, matching `PAR2012.pso` (`ps_2_x`).
  - The current pass must be the exact global entry `B47620[0]`.
- `sub_87AD10` Skin pass 0:
  - `0x0087B073` binds the vertex shader stored at `this + 0xBC`, matching `SKIN2008.vso` (`vs_2_0`).
  - `0x0087B0B6` binds the pixel shader stored at `this + 0xFC`, matching `SKIN2004.pso` (`ps_2_x`).
  - The current pass must be the exact global entry `B47718[0]`.

## Runtime gate applied in build 51

`TryGetLegacyObjectVertexShaderVariant` now requires all of the following before selecting the generic legacy replacement:

- classified family is Parallax or Skin;
- pass index is `0`;
- current pass pointer equals the decoded pass-table entry for that family;
- original pass vertex shader pointer equals the shader object pointer at the decoded vertex offset;
- original pass pixel shader pointer equals the shader object pointer at the decoded pixel offset.

The replacement still rejects the hardware-skinned draw hook. The decoded `SKIN2008.vso` contract used here is the same no-bone vertex output contract as `PAR2016.vso`; extending this to hardware-skinned semantics would require a separate Oblivion decode.

## Diagnostics

Build 51 adds a per-variant legacy applied mask:

- bit 0: `PAR2016/PAR2012`
- bit 1: `SKIN2008/SKIN2004`

The first accepted draw for each variant logs the pass, original vertex and pixel shader pointers, constant base, and applied mask.
