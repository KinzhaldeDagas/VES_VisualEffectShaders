# shaderpackage019 pass-0 contract

MoonSugarEffect decode artifact for the first non-rigid vertex-deformation target.

Source package: `C:\Games\Oblivion\Data\Shaders\shaderpackage019.sdp`

Disassembler: `D3DXDisassembleShader` from local `D3DX9_43.dll`.

This artifact is not Fallout-derived. Fallout naming should only be used later for contrast after the Oblivion behavior below is treated as the inspected Oblivion baseline.

## Parallax pass 0

- Vertex program bind: `sub_864A60`, address `0x00864DC3`
- Pixel program bind: `sub_864A60`, address `0x00864E06`
- Vertex package record: `PAR2016.vso`, bytecode offset `0x8C564`, target `vs_2_0`
- Pixel package record: `PAR2012.pso`, bytecode offset `0x997A0`, target `ps_2_x`

`PAR2016.vso` consumes the normal six-element TES4 object declaration differently than the declaration construction order suggests:

- `v0`: `POSITION`
- `v1`: `TANGENT`
- `v2`: `BINORMAL`
- `v3`: `NORMAL`
- `v4`: `TEXCOORD`
- Declared `COLOR`: unused by this variant

Relevant `PAR2016.vso` disassembly:

```asm
vs_2_0
def c4, 0.5, 0, 0, 0
dcl_position v0
dcl_tangent v1
dcl_binormal v2
dcl_normal v3
dcl_texcoord v4
dp4 oPos.x, c0, v0
dp4 oPos.y, c1, v0
dp4 oPos.z, c2, v0
dp4 oPos.w, c3, v0
dp3 r0.x, v1, c13
dp3 r0.y, v2, c13
dp3 r0.z, v3, c13
add r1.xyz, -v0, c25
nrm r2.xyz, r1
dp3 r1.x, v1, r2
dp3 r1.y, v2, r2
dp3 r1.z, v3, r2
nrm r2.xyz, r0
mov oT1.xyz, r2
dp3 r0.x, r1, r1
rsq r0.w, r0.x
add r0.xyz, -v0, c17
mul oT7.xyz, r1, r0.w
nrm r1.xyz, r0
dp3 oT2.x, v1, r1
rcp r0.w, c17.w
dp3 oT2.y, v2, r1
mul r0.xyz, r0, r0.w
dp3 oT2.z, v3, r1
mad oT4.xyz, r0, c4.x, c4.x
mov oT0.xy, v4
mov oT4.w, c4.x
```

`PAR2016.vso` constants observed from CTAB/disassembly:

- `c0-c3`: `ModelViewProj`
- `c13`: `LightDirection`
- `c16-c17`: `LightPosition` range, with this variant reading `c17`
- `c25`: `EyePosition`

`PAR2012.pso` input/output contract:

```asm
ps_2_x
def c0, 0.0399999991, -0.0199999996, -0.5, 1
dcl t0.xy
dcl_centroid t1.xyz
dcl_centroid t2.xyz
dcl t4
dcl_centroid t7.xyz
dcl_2d s0
dcl_2d s1
dcl_2d s4
texld_pp r0, t0, s0
dp3_pp r0.x, t7, t7
rsq_pp r1.w, r0.x
mul_pp r0.xy, r1.w, t7
mad_pp r0.w, r0.w, c0.x, c0.y
mad r1.xy, r0, r0.w, t0
mov r0.x, t4.z
mov r0.y, t4.w
texld_pp r2, r1, s1
texld_pp r0, r0, s4
texld_pp r1, t4, s4
add r2.xyz, r2, c0.z
add_pp r3.xyz, r2, r2
nrm_pp r2.xyz, r3
nrm_pp r3.xyz, t2
dp3_sat_pp r3.x, r2, r3
dp3_sat_pp r2.x, r2, t1
add_pp r0.w, -r1.x, c0.w
mul_pp r1.xyz, r3.x, c3
add_sat_pp r0.w, -r0.x, r0.w
mul_pp r0.xyz, r1, r0.w
mad_pp r0.xyz, c2, r2.x, r0
add_pp r0.xyz, r0, c1
mov r0.w, c0.w
mov_pp oC0, r0
```

`PAR2012.pso` constants/samplers observed from CTAB/disassembly:

- `c1`: `AmbientColor`
- `c2-c3`: `PSLightColor`
- `s0`: `BaseMap`
- `s1`: `NormalMap`
- `s4`: `AttenuationMap`

Implementation consequence: a Moon Sugar replacement vertex shader should displace the object-space position before all position-derived outputs are computed. Moving only `oPos` creates a visible wobble, but it leaves `oT2`, `oT4`, and `oT7` based on the undisplaced surface, desynchronizing TES4 parallax UV offset, normal lighting, and point-light attenuation.

## Skin pass 0 contrast

- Vertex program bind: `sub_87AD10`, address `0x0087B073`
- Pixel program bind: `sub_87AD10`, address `0x0087B0B6`
- Vertex package record: `SKIN2008.vso`, bytecode offset `0x7A7A0`, target `vs_2_0`
- Pixel package record: `SKIN2004.pso`, bytecode offset `0x81C3C`, target `ps_2_x`

`SKIN2008.vso` is bytecode-equivalent to `PAR2016.vso` for this pass-0 no-`SKIN` path and has the same vertex-output contract. `SKIN2004.pso` consumes the same `t0/t1/t2/t4/t7` interpolator contract but uses different pixel lighting math. Keep Skin as a second whitelist after the Parallax replacement path works.
