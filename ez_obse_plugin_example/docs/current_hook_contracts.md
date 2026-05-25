# Current Hook and Evidence Contracts

Scope: active implementation guidance for the VES/OBSE plugin against the inspected Oblivion `1.2.0416` binary. Historical decode notes remain useful evidence, but this file is the current hook/address/terminology source of truth.

## Evidence and Confidence Legend

| Level | Meaning |
| --- | --- |
| Confirmed | Backed by live implementation byte validation, direct IDA/decompile evidence in this corpus, documented runtime logging, or a recorded test for the named path. |
| Likely | Strongly suggested by IDA/control-flow evidence, but not proven across every caller or runtime scene. |
| Speculative | Plausible interpretation without enough supporting evidence to drive implementation. |
| Unsupported | Claim lacks traceable evidence in the corpus. Do not use as implementation guidance. |
| Stale | Superseded by later IDA/runtime analysis. Preserve only in archived findings. |

## Canonical Terminology

| Canonical term | Previously called / avoid |
| --- | --- |
| `PlayerConsume_ProcessEffectsFromItemCall` | generic "confirmed player call" without path scope |
| `NiRendererRender_ImageSpaceProcessCall` | treating `0x0040CF6E` as a function entry |
| `ProcessImageSpaceShader` | inconsistent `ImageShaderList` spelling unless quoting history |
| `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`) | unqualified "draw loop" |
| `NonSkinnedRenderTriGeometrySetupCall` | generic non-skinned setup call |
| `SkinnedRenderTriGeometrySetup` (`sub_767520`) | unqualified "skinned path" |
| `NonSkinnedPostSetupVertexReplacementHook` | "object vertex shader hook" without timing |
| `SkinnedPostSetupVertexReplacementHook` | "faithful skinned hook" |
| `SkinnedBoneMatrixHelper` (`sub_765560`) | treating it as the current skinned hook boundary |
| `StaleDoNotPatch_OnEatIngredientConflictSite` | `0x005E4515` as an active VES hook |
| `sub_85E660_Lighting30PassPopulate` | treating the decoded pass map as broader than the inspected binary |
| `sub_7FD260_Lighting30SelectorRoute` | unsupported recovered source-style name |
| `Lighting30VertexProgramLoader` | recovered source-style name unless IDA evidence is attached |
| `Lighting30PixelProgramLoader` | recovered source-style name unless IDA evidence is attached |

## Current Address and Hook Table

| Address / symbol | Binary version | Current role | Evidence source | Confidence | Validation status | Replacement / supersession note |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00666639` | Oblivion `1.2.0416` | `PlayerConsume_ProcessEffectsFromItemCall` | `main.cpp` byte validation and consume-path decode | Confirmed for observed player-success path | Installed only after expected-byte check | Supersedes `0x005E4515` for VES. |
| `0x006A23B0` | Oblivion `1.2.0416` | Original `MagicTarget_ProcessEffectsFromItem` call target | `main.cpp` hook wrapper and decode notes | Confirmed call target | Called by trampoline | Keep argument/register preservation documented. |
| `0x0040CF6E` | Oblivion `1.2.0416` | `NiRendererRender_ImageSpaceProcessCall` | Exact call bytes in `main.cpp`, image-space decode notes | Confirmed call site | Installed only after expected-byte check | Distinguish from callee `0x007B48E0`. |
| `0x007B48E0` | Oblivion `1.2.0416` | `ProcessImageSpaceShader` original callee | IDA call from `0x0040CF6E` | Confirmed for hooked path | Called by trampoline | Class ownership remains likely, not source-confirmed. |
| `0x007694D7` | Oblivion `1.2.0416` | `NonSkinnedRenderTriGeometrySetupCall` | Direct call to `0x007672F0`, current transform-copy hook | Confirmed call site | Installed only after expected-byte check | Preferred over broad transform-helper detours. |
| `0x007672F0` | Oblivion `1.2.0416` | `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`) | IDA path and current hook trampoline | Confirmed call target, descriptive name inferred | Original callee invoked by hook | Do not present as recovered Bethesda symbol. |
| `0x00767410` | Oblivion `1.2.0416` | `NonSkinnedPostSetupVertexReplacementHook` | Exact byte window and current inline hook | Confirmed hook window | Re-emits overwritten bytes and jumps back | Exact pass/wrapper gates required. |
| `0x00767520` | Oblivion `1.2.0416` | `SkinnedRenderTriGeometrySetup` (`sub_767520`) | Build39/40 path decode | Confirmed path, descriptive name inferred | Evidence path, not active hook target | Active skinned hook is `0x007676F9`. |
| `0x007676F9` | Oblivion `1.2.0416` | `SkinnedPostSetupVertexReplacementHook` | Exact byte window and Build40 implementation notes | Confirmed byte window; stack/register assumptions need runtime matrix | Re-emits overwritten bytes and jumps back | Supersedes `sub_765560`/`0x007655F0` as hook boundary. |
| `0x0040CCD3`, `0x0040CE48` | Oblivion `1.2.0416` | World render/camera wrapper call sites | Exact call bytes and current wrapper | Confirmed call sites | Installed only after expected-byte check | Needs runtime validation across menus/RTT/refraction-like paths. |
| `0x0070C0B0` | Oblivion `1.2.0416` | Original world scenegraph render callee | Camera/world decode and wrapper | Likely descriptive ownership | Called by wrapper | Keep name descriptive unless a source symbol is proven. |
| `0x00701970` | Oblivion `1.2.0416` | Camera view/projection setup | Camera decode notes | Confirmed function address if existing IDA label is accepted | Used by camera/depth path | Document expected camera pointer/state before use. |
| `0x00B3FAA8` | Oblivion `1.2.0416` | Exact `NiScreenElements` RTTI skip | Geometry filter implementation | Confirmed for inspected binary | Runtime pointer check | Version-specific RTTI address. |
| `0x00B42EAC`, `0x00B45D74`, `0x00B3F928`, `0x00B333CC` | Oblivion `1.2.0416` | Render mode, render stack depth, renderer pointer, world scenegraph globals | Current guards/state access | Likely/confirmed per decoded use | Guarded by null/state checks | Keep version caveat. |
| `B473D0`, `B47288`, `B46ED8`, `B46C20`, `B47620`, `B47718` | Oblivion `1.2.0416` | Shader family/pass tables | Lighting30/SM3000 decode notes | Likely/confirmed for inspected binary | Exact wrapper/pass gates in implementation | Treat as IDA-identified tables, not cross-version constants. |

## Archived / Superseded Findings

| Stale address / route | Historical use | Current replacement | Action |
| --- | --- | --- | --- |
| `0x005E4515` | xOBSE `OnEatIngredient` event hook site, earlier consume-hook candidate | `0x00666639` for VES player-success consume trigger | Archive only as `StaleDoNotPatch_OnEatIngredientConflictSite`. Never list as active VES hook guidance. |
| `sub_765560` / `0x007655F0` | Skinned helper and bone-matrix decode boundary | `0x007676F9` for current skinned post-setup hook | Keep as skinned setup evidence only. Do not describe as the current hook boundary. |
| Build42 clear support clones for passes `47`, `48`, `51` | Historical clear-support replacement attempt | Build59/61 native-clear policy with `blocked:clearSupportPass` | Do not ship clone bytecode or active guidance for these passes unless a later runtime/IDA pass explicitly validates a new route. |

## Current VES Pipeline Status

Do not express current decode or implementation completion as a percentage. No coverage denominator is currently proven across all Oblivion render paths. Use the runtime `VESDumpShaderRenderer` command and its `VES pipeline coverage` / `VES pipeline largest gap` lines to classify the currently observed scene.

| Pipeline area | Current status | Remaining gap |
| --- | --- | --- |
| Command-driven screen effects | Implemented through explicit OBSE commands and profile-family pixel shader slots. Build 86 registers the commands in the local Daggers opcode ledger at `0x70F0-0x7111`. Build 87 keeps the Dim color-variant commands as public commands but canonicalizes their active renderer profile to `VESDim100` while preserving the Dim variant constant. | Runtime confirmation that each packaged `.pso` slot is loaded and active for representative commands, including the three Dim color variants. |
| Image-space render path | Implemented for the byte-validated `NiRendererRender_ImageSpaceProcessCall` path. Profile-family `.pso` files are the normal shipped path; `VESDistortion.pso` / embedded bytecode are compatibility fallback only. | Menu, render-to-texture, reset, and unusual render-mode validation. |
| Depth-backed screen masking | Implemented as a texture-backed depth capture/bind path where supported by the device/format. | It is not a true terrain/object ID mask; formats and runtime availability must be logged per machine. |
| World/object vertex replacement | Implemented as exact-gated non-skinned and skinned post-setup replacement for decoded visible families. | Runtime matrix for actor, creature, armor, first-person, third-person, and heavy modded scenes. |
| Support-buffer families | Live support-buffer vertex replacement is blocked to preserve native depth/normal/local-map outputs. | RenderNormals, LocalMap, ZOnly, SimpleShadow, and DepthMap remain diagnostic/decode evidence only unless a future runtime pass proves a safe route. |
| True terrain/object identity masking | Not implemented. Current implementation uses depth cues, object pass census, exact-gated vertex replacement, and the `VESDepthMaskDebug` diagnostic. | No validated terrain material ID, object ID, actor ID, form ID, or plugin-owned identity mask target has been observed in the inspected Oblivion paths. |
| Plugin-owned mask/prepass diagnostics | Implemented as read-only counters on the existing world-render wrapper. | Counts only camera/scene/culling/visible-array argument state; it does not collect geometry, draw a mask, or establish identity semantics. |

### Depth-Backed Screen Masking Decode Status

Oblivion IDA evidence supports the current capture order: `NiRenderer_Render` calls `sub_70C0B0` at `0x0040CCD3` and `0x0040CE48`, then later calls `ProcessImageSpaceShader` at `0x0040CF6E`. `sub_70C0B0` calls `SetCameraViewProj`, culls visible geometry, and submits the accumulator, so the plugin-side texture-backed depth surface is captured before the image-space effect samples it.

The Lighting30 DepthMap contracts are also decoded for the inspected binary: `sub_7FD560` builds `B47288[18]` / `B47288[19]` from `SM3DepthMap.v.hlsl`, and `sub_85E660` binds passes `42` and `43` to the DepthMap vertex/pixel programs with the documented masks. This supports pass identification and diagnostics. Live DepthMap vertex replacement is currently blocked by Build 80 to preserve native support-buffer output stability.

The current depth-mask status is qualitative:

| Depth masking area | Estimate |
| --- | --- |
| Render-order decode for depth capture before image-space | High confidence for the inspected `1.2.0416` path |
| Texture-backed depth availability | Implementation present, machine/driver dependent |
| DepthMap pass contracts | High confidence for decoded Lighting30 passes `42` and `43` |
| Shader-side world-surface mask | Implemented as a depth/coherence heuristic, trusted only when the source is the captured world-depth path |
| Late active-depth fallback | Available as a diagnostic / soft depth cue where sampleable, not treated as validated terrain/object masking |
| True terrain/object identity mask | Not implemented; no validated object/terrain ID buffer exists |

Implementation note: `MoonSugarDepthState` now distinguishes `capturedWorld` from `activeFallback`. The HeatShimmer screen mask uses only `capturedWorld` because Oblivion IDA evidence supports that capture order around the world `sub_70C0B0` calls. The active fallback path remains logged by `VESDumpShaderRenderer`, but it is not promoted to terrain/object-mask evidence.

Diagnostic implementation note: `VESDepthMaskDebug` is command-driven and uses the same depth-backed image-space path as HeatShimmer, but it is a visualization tool rather than a gameplay effect. It draws source/trust state and the current raw depth/coherence mask so runtime tests can confirm whether the plugin is sampling the captured-world path, the late active-depth fallback, or no usable depth. This diagnostic does not establish terrain material IDs, object IDs, or a plugin-owned object mask.

Latest Oblivion-only decode pass: landscape and terrain LOD evidence was observed through strings and xrefs such as `TESTerrainLODManager::CreateGrass` (`0x004EA8A0`), terrain LOD mesh/texture builders around `0x004EB1A0`/`0x004ED320`, the DistantLOD shader transform path at `0x008112A0`, and landscape/water shader setup strings near `0x007D9890`/`0x007DD920`. These paths are terrain/LOD/shader construction or transform/setup evidence. They do not currently expose a validated image-space terrain/object ID buffer or a plugin-safe mask render target.

True identity masking decode note: the Build 78 IDA pass followed the object-list/offscreen path (`0x007D2070`, `0x00813300`, `0x007D21F0`), accumulator forced-pass path (`0x007A9820`, `0x007AC9A0`), render-pass name table (`0x007B4920`), canopy shadow mask path (`0x004CE460`, `0x004826F0`, `0x004D0190`, `0x004D06C0`), terrain/land shader loaders (`0x007CD090`, `0x007CEFD0`, `0x00811640`, `0x007E6B10`), and native refraction (`0x00800E20`, `0x00800750`). These paths expose object pointers during traversal or auxiliary render targets such as depth, render normals, local map, canopy shadow, and refraction. None of the inspected outputs is validated as a terrain material ID, object ID, actor ID, form ID, or plugin-neutral identity channel. See `ida_decodes/build78_true_identity_masking/true_identity_masking_decode.md`.

Plugin-owned prepass diagnostic note: Build 79 adds read-only runtime counters for the existing `sub_70C0B0` wrapper inputs. `VESDumpShaderRenderer` now reports whether world-render calls use the current world camera, current world scene graph, scene graph culling process, normal render mode, explicit `visibleGeo` argument, or an installed `NiCullingProcess::VisibleGeo` pointer at offset `+0x08`. This is evidence collection only; it is not a second cull, mask render target, geometry submission path, object ID, terrain ID, or plugin-neutral identity channel. See `ida_decodes/build79_plugin_mask_prepass/plugin_owned_mask_prepass_contract.md`.

Flicker/normal preservation note: Build 80 blocks live object-vertex replacement on native support-buffer passes after in-game white texture flicker was reported with HeadWound/HeatShimmer-style effects. Visible final-color object families can still wobble, but DepthMap, RenderNormals, LocalMap, ZOnly, and SimpleShadow remain on Oblivion's native shaders so their normal/depth auxiliary outputs are not perturbed. HeadWound and HeatShimmer profile pixel shaders also clamp viewport samples and reject isolated near-white outlier taps back to the stable scene sample.

Support-buffer diagnostic correction note: Build 84 aligns runtime readiness strings with the Build 80 live policy. `VESDumpShaderRenderer` now reports SimpleShadow, DepthMap, RenderNormals, LocalMap, and ZOnly readiness as `blocked:preserveNativeSupportBuffers` or `blocked:clearSupportPass` instead of support-clone candidates. The pipeline coverage line reports those observed native paths as `supportPreserved`, not as replacement work waiting for validation. This is a diagnostic correction only; it does not widen replacement eligibility.

Fallback fidelity note: `VESHeadWoundPS.pso` and `VESHeatShimmerPS.pso` are the current required Build 80 profile-specific paths for the flicker/normal-preservation shader changes. The combined `VESDistortion.pso` and embedded bytecode remain compatibility fallbacks; they must not be treated as proof that the latest HeadWound/HeatShimmer profile-specific stability patches are active unless regenerated and verified.

Dim variant fidelity note: Build 82 routes `VESDimWhiteInverted`, `VESDimPurple`, and `VESDimDarkRed` through the existing Dim profile-family shader using the profile variant constant. Dim profiles now require the current standalone `VESDimPS.pso`; the combined fallback is not treated as the current implementation path for those variants. Build 87 preserves that model by storing the three color variants as `VESDim100` active renderer profile executions with variant constants `2.0`, `3.0`, and `4.0`; the requested command name is retained only for console/log identity.

Blind water-safety correction note: Build 83 removes Blind from the depth-backed path after water disappearance was reported. Blind remains a screen-space image effect, but it no longer requests texture-backed depth capture or samples `DepthSampler`; `VESBlindPS.pso` is the current required Blind path.

Runtime implementation note: `VESDumpShaderRenderer` now reports depth-mask trust counters and world-depth capture guard counters. Use `maskTrusted=1` / `trustedFrames` to confirm the shader is using the IDA-validated captured world-depth source; use `guardNoRenderer`, `guardNoEffect`, `guardNoDepthProfile`, `guardCamera`, `guardMode`, and `guardBeginFail` to identify why the trusted mask path did not run.

## Hook Blocks

### `PlayerConsume_ProcessEffectsFromItemCall`

| Field | Value |
| --- | --- |
| Purpose | Trigger the VES consume effect after the observed player-success item effect path. |
| Address/signature | `0x00666639`, call to `0x006A23B0`. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | `WriteRelCall` replacement with trampoline/original call. |
| Caller context | Observed `Player_EquipPotion?` path after the potion/ingredient success gate. |
| Register/stack assumptions | `EDI` and the stack argument still identify the consumed `MagicItem*` in the decoded path. |
| Validation evidence | Current implementation validates expected bytes before patching. Decode notes show the nearby type path. |
| Failure mode | Wrong address or calling convention could corrupt item effect processing or trigger effects on the wrong path; byte validation should fail closed. |
| Ship status | Safe for the inspected binary with current byte validation. |

### `NiRendererRender_ImageSpaceProcessCall`

| Field | Value |
| --- | --- |
| Purpose | Run the VES image-space pass after the hooked engine image-space routine returns. |
| Address/signature | `0x0040CF6E`, call to `ProcessImageSpaceShader` at `0x007B48E0`, expected call bytes documented in implementation. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | `WriteRelCall` pre/post wrapper around original callee. |
| Caller context | Observed world render image-space process call in `NiRenderer::Render`. |
| Register/stack assumptions | Original callee is invoked before the VES post-pass; render state and targets must be restored after plugin drawing. |
| Validation evidence | Current implementation validates expected bytes and renders through the same profile constants/samplers. |
| Failure mode | Incorrect target or state restoration can affect offscreen/menu/RTT paths or corrupt render targets. |
| Ship status | Safe with current guards; language must stay scoped to the hooked/tested path. |

### `NonSkinnedRenderTriGeometrySetupCall`

| Field | Value |
| --- | --- |
| Purpose | Apply local transform wobble before non-skinned geometry setup consumes the transform copy. |
| Address/signature | `0x007694D7`, call to `NonSkinnedRenderTriGeometrySetup` at `0x007672F0`. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | `WriteRelCall` replacement that prepares a local transform and calls original setup. |
| Caller context | `RenderTriGeometries` immediate geometry path for non-hardware-skinned geometry. |
| Register/stack assumptions | Observed call convention and original callee stack cleanup remain valid. |
| Validation evidence | Current implementation validates bytes and filters inactive effects, skinned geometry, exact `NiScreenElements`, and non-normal render mode. |
| Failure mode | Wrong call convention or missing filter can corrupt geometry setup or screen/UI geometry. |
| Ship status | Safe with current filters. |

### `NonSkinnedPostSetupVertexReplacementHook`

| Field | Value |
| --- | --- |
| Purpose | Bind exact-gated replacement vertex shaders after native pass setup and constant flush for non-skinned draws. |
| Address/signature | `0x00767410`; re-emits `xor eax,eax; cmp [esi+0x30],eax` and returns to `0x00767415`. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | Inline jump/trampoline. |
| Caller context | Post-`SetupShaderPrograms`/post-constant-flush window inside `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`). |
| Register/stack assumptions | `EDI`, `EBX`, `EBP`, and `ESI` retain the expected renderer/shader/pass/buffer context at the hook window. |
| Validation evidence | Exact bytes checked before patching; replacement helper gates on pass family, pass index, wrapper identity, and profile state. |
| Failure mode | Wrong register interpretation can bind an invalid shader or break the draw path. |
| Ship status | Needs more validation, but acceptable when exact-gated. |

### `SkinnedPostSetupVertexReplacementHook`

| Field | Value |
| --- | --- |
| Purpose | Bind skinned-compatible exact-gated replacement vertex shaders after native skinned setup and constant flush. |
| Address/signature | `0x007676F9`; re-emits `xor eax,eax; cmp [edi+0x44],eax` and returns to `0x007676FE`. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | Inline jump/trampoline. |
| Caller context | Hardware-skinned draw window inside `SkinnedRenderTriGeometrySetup` (`sub_767520`). |
| Register/stack assumptions | `ESI` is expected as `NiDX9Renderer*`, `EBX` as active shader interface, `EBP` as skin partition, `EDI` as buffer data, and the original `NiGeometry*` stack argument is recovered after the hook prologue. |
| Validation evidence | Exact bytes checked before patching; Build40 documents the stack recovery and helper gates. |
| Failure mode | Incorrect stack/register recovery can corrupt actor, creature, armor, or first/third-person skinned draws. |
| Ship status | Needs more validation; ship only exact-gated with runtime logging. |

### World Render / Camera Wrapper Hooks

| Field | Value |
| --- | --- |
| Purpose | Apply camera sway and depth-capture setup around world scenegraph render calls. |
| Address/signature | `0x0040CCD3`, `0x0040CE48`, both calls to `0x0070C0B0`. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | `WriteRelCall` wrapper around original scenegraph render callee. |
| Caller context | Observed normal world render call sites. |
| Register/stack assumptions | cdecl cleanup remains native; wrapper receives the expected camera/scenegraph arguments and restores camera/renderer state after original return. |
| Validation evidence | Current implementation validates expected bytes and guards by world camera, render mode, recursion, and state restoration. |
| Failure mode | Wrong context can affect menus, render-to-texture, reflections, water/refraction scenes, or camera globals. |
| Ship status | Needs validation matrix; acceptable with current guards. |

### Support / Clear Clone Policy

| Field | Value |
| --- | --- |
| Purpose | Prevent stale clear-support clone guidance from being treated as active. |
| Address/signature | Lighting30 support passes `47`, `48`, and `51`; Build42 historical clone route superseded by Build59/61. |
| Binary version | Oblivion `1.2.0416`. |
| Hook type | No current hook should be added from stale clear clone guidance. |
| Caller context | Support-buffer clear coverage, not ordinary visible material shading. |
| Register/stack assumptions | Not applicable for current implementation. |
| Validation evidence | Build59/61 notes identify paired clear pixel programs that write constant clear values. |
| Failure mode | Replacing clear vertex programs can deform clear coverage and leave stale support-buffer regions. |
| Ship status | Do not ship stale clear clone logic. |
