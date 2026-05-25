# Lighting30 EnvMap Implementation Contract

Build 35 implements the decoded visible EnvMap auxiliary family as dedicated vertex-shader clones. This is not a reuse of the primary `SM3Lighting` clone.

Implemented variants:

- `SM3008 EnvMap`: no skin, no vertex color, pass rows `29..30`.
- `SM3009 EnvMap VC`: no skin, vertex color, pass rows `31..32`.
- `SM3010 EnvMap SKIN`: skinned, pass row `33`.
- `SM3011 EnvMap SKIN VC`: skinned and vertex color, pass row `34`.
- `SM3012 EnvMap special`: special cube/rim variant, pass row `35`.

Runtime gating:

- The active pass must be in `B473D0[29..35]`.
- The active vertex wrapper must exactly match `B47288[8..12]`.
- The active pixel wrapper must exactly match `B46ED8[20..22]`.
- Native pixel shaders, samplers, selector state, and pass objects remain untouched.

Moon Sugar constant plan:

- `SM3008`, `SM3009`, and `SM3012` use `c26-c27`.
- `SM3010` and `SM3011` use `c24-c25` because skinned EnvMap owns `SkinToCubeSpace c27-c29` and `Bones c31-c84`.

Vertex contract preservation:

- EnvMap no-skin/VC clones preserve `POSITION`, `TEXCOORD0`, `TEXCOORD1`, `TEXCOORD2`, `TEXCOORD3`, and `COLOR0` outputs.
- EnvMap skinned clones preserve the same output family and reproduce the indexed bone blend before Moon Sugar displacement.
- EnvMap special preserves `POSITION`, `TEXCOORD0`, `TEXCOORD1`, `TEXCOORD2`, and `COLOR0`.

Displacement placement:

- Position is displaced before clip projection.
- EnvMap cube-space view vectors are derived from the displaced position.
- Reflection tangent/cube basis outputs remain compatible with the native `SM3020/3021/3022.pso` pixel programs.

Verification:

- All five embedded HLSL sources compile locally as `vs_3_0` with June 2010 `fxc.exe`.
- The Release Win32 OBSE DLL builds successfully with MSBuild.

No Fallout material was used.
