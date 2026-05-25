# Build 47 full shader pipeline usage

Evidence source: live Oblivion IDA database for `Oblivion.exe` 1.2.0.416 (`fxq5`) and the existing
shaderpackage disassembly artifacts. Fallout material was not used.

## IDA decode checkpoint

`sub_7FD260` shows Lighting30 selector IDs are routed through the decoded pass table and constant masks:

- selector `0x12A + passIndex` maps regular Lighting30 passes through `B473D0`;
- selectors `0x15E..0x15F` use the alternate shader-slot branch before pass routing, matching the TexEffect path;
- selector handling writes vertex constant activity from `B46988` and pixel constant activity from `B46A60`;
- broad replacement is not valid without the pass index, active wrapper identity, and constant-mask gates.

`sub_85E660_Lighting30PassPopulate` remains the IDA-identified pass-population function for the `B473D0` Lighting30 pass pool. The OBSE
side keeps the existing decoded pass/program gates unchanged.

## Implementation pass

Build 55 extends runtime shader-pipeline observability so every implemented decoded replacement family reports
actual application, not only compiled shader availability:

- legacy Parallax/Skin: `legacyAppliedMask`;
- primary Lighting30 SM3: `sm3AppliedMask`;
- Lighting30 EnvMap: `envAppliedMask`;
- Lighting30 TexEffect: `texAppliedMask`;
- Lighting30 Decal: `decalAppliedMask`;
- Lighting30 DepthMap: `depthAppliedMask`;
- Lighting30 support families: `supportAppliedMask`.

Each family now logs its first applied variant independently. This makes runtime logs capable of proving which
decoded shader families were actually reached by live draws.

## File-backed image-space shader

The packaged `MoonSugarDistortion.fx` and `MoonSugarDistortion.pso` now match the embedded profile/depth shader
pipeline:

- `MoonSugarProfile.x` routes MoonSugar, HeadWound, and Blind profiles;
- `MoonSugarProfile.y` carries profile severity;
- `MoonSugarProfile.z` carries whether depth sampling is available for profiles that still request depth capture.

Historical note: this pass used `DepthSampler s1` for Blind profiles when texture-backed depth capture was active.
Build 83 supersedes that Blind policy after water disappearance was reported. Blind profiles are now screen-space only:
they do not request depth capture, sample `DepthSampler`, enable world wobble, or enable object vertex replacement.

Build 56 routes HeadWound and Blind starts through the shared `MoonSugarDistortion` asset instead of profile-named
embedded-only shader paths. The effect profile constant still selects the active branch, so this changes shader
asset selection only; it does not add any new Oblivion behavior or widen world/object replacement eligibility.
