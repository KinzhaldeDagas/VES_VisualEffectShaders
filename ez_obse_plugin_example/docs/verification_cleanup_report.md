# VES Cleanup and Verification Report

Scope: current workspace audit of IDA findings, Codex outputs, markdown notes, release/package text, and live plugin implementation notes for the Oblivion 1.2.0416 VES/OBSE plugin research corpus.

Evidence rule used in this pass: a claim is only treated as confirmed when it is backed by live implementation checks, byte validation, IDA/decompile evidence already recorded in the corpus, runtime logging noted in the docs, or an explicitly documented test. Everything else is marked likely, speculative, unsupported, stale, or unknown.

## A. Executive Summary

Main risks found:

| Risk | Impact | Current status |
| --- | --- | --- |
| Same address named differently across passes | Makes hooks hard to review and increases chance of patching the wrong site | Needs cleanup in docs, not immediately unsafe in code |
| Overconfident language in internal release/build notes | Public-facing copy could claim more certainty than the IDA evidence supports | Must be downgraded before public release reuse |
| Stale hook/address notes survive beside newer findings | Older implementation guidance can reintroduce unsafe patch points | Highest risk areas are the old consume hook, early skinned boundary, and clear support-pass work |
| Hook assumptions not uniformly documented | Future edits may preserve byte signatures but break register/stack assumptions | Needs a current hook contract table |
| Duplicated build-stage docs | Build snapshots are useful evidence, but conflict when read as current guidance | Add source-of-truth references and mark superseded sections |

Highest-priority cleanup targets:

| Priority | Target | Reason |
| --- | --- | --- |
| P0 | Quarantine `0x005E4515` as stale/do-not-patch | It conflicts with the xOBSE ingredient event path and is superseded by `0x00666639` |
| P0 | Mark Build42 clear-support clone guidance stale where superseded by Build59/61 | Later analysis blocks native clear support clones; older text can mislead implementation |
| P0 | Remove or downgrade percentage-complete and "fully/authoritative/faithful" release language | Completion percentages are not evidence-backed |
| P1 | Canonicalize names for `0x007672F0`, `0x00767520`, `0x00767410`, `0x007676F9`, and image-space symbols | Same functions are named differently across passes |
| P1 | Add a current hook safety matrix beside the implementation | The live code validates bytes, but docs do not consistently capture caller/register/stack assumptions |

Ship safety:

The current live hooks appear fail-closed on unexpected bytes in `main.cpp` and are scoped to the inspected 1.2.0416 binary. No current hook is flagged as "do not ship" solely from this audit. The skinned post-setup hook at `0x007676F9`, camera/world wrapper call sites, and support-pass clone logic remain the highest runtime-validation risk. Public release text should not claim full vanilla accuracy, full restoration, or complete decode coverage.

## B. Naming Consolidation Table

| Address / symbol / hook target | Names used across passes | Recommended canonical name | Evidence level | Notes |
| --- | --- | --- | --- | --- |
| `0x008037D0` | `ImageShaderList::ProcessImageSpaceShader`, `ImageSpaceShaderList::ProcessImageSpaceShader` | `ImageSpaceShaderList::ProcessImageSpaceShader` | Likely | The corpus mostly uses `ImageSpaceShaderList`. Keep `ImageShaderList` as a previous shorthand/typo unless a vtable/class-name IDA pass proves otherwise. |
| `0x007B48E0` | `sub_7B48E0`, `ProcessImageSpaceShader`, image-space process routine | `ProcessImageSpaceShader` | Confirmed for inspected binary path | Called from the hooked `NiRenderer::Render` site `0x0040CF6E`; exact higher-level class ownership should remain tied to the `0x008037D0` uncertainty. |
| `0x0040CF6E` | image-space hook, NiRenderer image-space call, post-image-space call site | `NiRendererRender_ImageSpaceProcessCall` | Confirmed call site | This is a call site, not the callee. Keep naming explicit to avoid treating it as a function entry. |
| `0x007672F0` | `sub_7672F0`, non-skinned renderer setup path, `RenderTriGeometrySetup`, non-skinned draw loop | `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`) | Confirmed call target, inferred descriptive name | Evidence supports the role in the inspected render path. Do not present the descriptive name as a recovered Bethesda symbol. |
| `0x007694D7` | call to `sub_7672F0`, non-skinned setup call, transform-copy hook site | `NonSkinnedRenderTriGeometrySetupCall` | Confirmed call site | Safer current hook point than detouring broader transform helpers. |
| `0x00767520` | `sub_767520`, skinned path, hardware-skinned draw loop | `SkinnedRenderTriGeometrySetup` (`sub_767520`) | Confirmed path, inferred descriptive name | Keep raw decompiler name in parentheses until class/function ownership is proven. |
| `0x00767410` | object vertex shader hook, non-skinned post-setup hook, post-flush replacement window | `NonSkinnedPostSetupVertexReplacementHook` | Confirmed hook window | Current implementation emits replacement after native setup state. Name should reflect hook purpose, not imply a full engine function boundary. |
| `0x007676F9` | skinned object vertex shader hook, hardware-skinned post-setup hook, faithful skinned analogue | `SkinnedPostSetupVertexReplacementHook` | Confirmed byte window, stack/register use needs runtime matrix | Supersedes earlier skinned-boundary assumptions. Avoid "faithful" unless the validation matrix is attached. |
| `0x007655F0` / `sub_765560` | skinned wobble boundary, matrix/bone calculation path, skinned helper | `SkinnedBoneMatrixHelper` (`sub_765560`) | Likely helper, stale as hook boundary | Earlier notes treating this as the authoritative hook boundary should be marked stale. |
| `NiDX9Renderer::CalculateBoneMatrixes` | skinned boundary, bone matrix function | `NiDX9Renderer::CalculateBoneMatrixes` | Confirmed function identity if IDA label is valid; stale as hook boundary | Useful evidence for skinned setup behavior, not the current hook location. |
| `0x0085E660` | `sub_85E660`, Lighting30 pass pool, pass-population function | `sub_85E660_Lighting30PassPopulate` | Likely | Descriptive suffix is acceptable; avoid claiming recovered source name. |
| `0x007FD260` | `sub_7FD260`, selector route, constant-map/mask state | `sub_7FD260_Lighting30SelectorRoute` | Likely | Keep raw name because semantics are inferred from route and state writes. |
| `0x007FD560` | Lighting30 vertex loader, vtable `+0xAC` loader | `Lighting30VertexProgramLoader` | Likely | Use only where backed by the vtable-loader evidence. |
| `0x007FDDE0` | Lighting30 pixel loader, vtable `+0xB0` loader | `Lighting30PixelProgramLoader` | Likely | Use only where backed by the vtable-loader evidence. |
| `0x005E4515` | old MoonSugar consume hook, xOBSE `OnEatIngredient` site | `StaleDoNotPatch_OnEatIngredientConflictSite` | Confirmed stale for this plugin | Preserve only as historical warning. It must not appear as implementation guidance. |
| `0x00666639` | confirmed player call, player consume call, ingredient success hook | `PlayerConsume_ProcessEffectsFromItemCall` | Confirmed observed path | Safer than `0x005E4515`; wording should say "observed player-success path" unless every consume path has been tested. |

## C. Semantics Confidence Audit

| Claim | Current wording pattern | Evidence found | Confidence | Recommended wording |
| --- | --- | --- | --- | --- |
| Player consume hook is confirmed for all player item consumption | "confirmed player call" | Current hook patches `0x00666639` and calls `0x006A23B0`; docs identify it as the player-success path | Likely beyond observed path | "observed player-success consume path in the inspected 1.2.0416 binary" |
| Image-space hook runs after vanilla image-space list | "intentionally runs after engine image-space list has completed" | Hook at `0x0040CF6E` wraps call to `0x007B48E0`; post-hook runs after original callee returns | Confirmed for hooked path | "runs after the hooked engine image-space call returns" |
| Hooked image-space target contains the full rendered world | "render target observed as full scene image, not small overlay target" | Runtime observation is documented for the hook | Confirmed for tested hook path | "observed at this hook as the full scene target during tested world renders" |
| `sub_765560` is the authoritative skinned wobble boundary | "authoritative skinned wobble boundary" | Later Build39/40 work moved implementation to `0x007676F9` post-setup | Stale | "`sub_765560`/bone-matrix work informs skinned setup, but current hook boundary is `0x007676F9`" |
| Native clear support clones are viable/current | Build42 clear support clone guidance | Later Build59/61 notes block native clear support and prefer preserving native clear behavior | Stale | "clear support clone work is historical and superseded by Build59/61; do not use as current implementation guidance" |
| Synthetic native `BSImageSpaceShader` is proven possible | "This confirms a synthetic native BSImageSpaceShader is possible" | IDA path suggests feasibility; no proven vtable-compatible synthetic object is documented as shipped | Likely/speculative | "supports feasibility of a synthetic native shader object; not yet a validated shipped implementation" |
| Lighting30 pass map is fully authoritative | "authoritative pass-population function/map" | IDA evidence identifies functions/tables in 1.2.0416 | Likely/confirmed only for inspected binary | "IDA-identified pass-population path/table in the inspected 1.2.0416 binary" |
| Decode completion percentages are meaningful | "99.9%", "100%", "fully decoded", "complete" | No quantitative coverage method found | Unsupported | Remove percentages; use "implemented path decoded", "partially decoded", or "requires runtime validation" |
| Object/terrain masking is true object identity masking | "true terrain/object masking" | Current work appears depth/screen-space driven unless separate object-ID mask evidence is attached | Speculative/unsupported if stated broadly | "depth-derived scene/terrain mask for the implemented path; object-ID masking remains unconfirmed" |
| Per-vertex object deformation covers all objects | "true per-vertex object deformation" | Hooks are exact-gated and shader-family dependent | Likely only for gated paths | "per-vertex deformation for currently supported exact-gated render paths" |
| Public package is command driven | "each effect is run by its OBSE command; no ini required" | Public `out/VisualEffectShaders/README.txt` and package layout match this | Confirmed | Keep wording. |

## D. Address and Hook Validity Audit

| Address / offset / vtable slot | Current use | Evidence source | Superseded by | Risk level | Recommendation |
| --- | --- | --- | --- | --- | --- |
| `0x00666639` | Player consume hook call site | `main.cpp` constants and byte validation; internal decode notes | Supersedes `0x005E4515` | Low | Keep as current implementation hook, scoped to 1.2.0416 and byte validation. |
| `0x006A23B0` | Original `ProcessEffectsFromItem` call target | `main.cpp` call target constant and hook wrapper | None found | Low | Keep, but document expected argument/register preservation. |
| `0x005E4515` | Historical consume hook site | Decode notes identify xOBSE `OnEatIngredient` conflict | Superseded by `0x00666639` | High if reused | Quarantine as stale/do-not-patch. |
| `0x0040CF6E` | `NiRenderer::Render` image-space process call hook | Exact bytes validate `E8 6D 79 3A 00`; post-call hook wraps `0x007B48E0` | None found | Medium | Keep with render-state guards and state restoration; do not claim global image-space coverage. |
| `0x007B48E0` | Original image-space process routine | Called by `0x0040CF6E` hook | None found | Medium | Keep as callee; canonicalize name and distinguish from call site. |
| `0x007694D7` | Non-skinned setup call hook | Exact call to `0x007672F0`; current implementation uses `WriteRelCall` | Broader helper detours | Low-medium | Keep. It is safer than broad transform helper interception. |
| `0x007672F0` | Non-skinned render setup callee | Current hook calls original after preparing local transform | None found | Low-medium | Keep descriptive name with raw alias. |
| `0x00767410` | Non-skinned object vertex replacement hook | Exact byte window; current implementation re-emits original instructions and jumps back | None found | Medium | Keep only with exact pass/wrapper gates and telemetry. |
| `0x00767520` | Skinned render setup callee evidence | Build docs describe hardware-skinned path | Not current hook | Medium | Use as evidence/path name, not as current hook unless separately validated. |
| `0x007676F9` | Skinned object vertex replacement hook | Exact byte window; stack recovery documented in implementation | Supersedes `sub_765560`/bone-matrix boundary as hook target | Medium-high | Needs runtime validation across actor, creature, armor, and first/third-person cases; ship only exact-gated. |
| `0x007655F0` / `sub_765560` | Historical skinned helper/boundary | Earlier build notes | Superseded by `0x007676F9` as hook point | High if reused as hook | Mark stale as hook boundary; keep only as skinned-setup evidence. |
| `0x0040CCD3`, `0x0040CE48` | World render/camera wrapper call sites | Exact bytes validate calls to `0x0070C0B0`; guarded by world camera/render mode | None found | Medium | Keep with camera restoration and recursion guard; test menus, exteriors, interiors, and render-to-texture cases. |
| `0x0070C0B0` | Original world scenegraph render callee | Current wrapper invokes original | None found | Medium | Keep name as descriptive unless source symbol evidence is added. |
| `0x00701970` | Set camera/view-projection call | Current camera/depth path uses it | None found | Medium | Document expected `camera` pointer and renderer state before use. |
| `0x00B3FAA8` | `NiScreenElements` RTTI check | Current geometry filter skips screen elements | None found | Low | Keep; document as 1.2.0416 RTTI address. |
| `0x00B42EAC`, `0x00B45D74`, `0x00B3F928`, `0x00B333CC` | Render mode, render stack depth, renderer pointer, world scenegraph globals | Current guards/state access | None found | Medium | Keep with version caveat and null checks. |
| `B473D0`, `B47288`, `B46ED8`, `B46C20`, `B47620`, `B47718` | Shader family/pass tables | Multiple Lighting30/SM3000 decode notes | None found | Medium | Treat as 1.2.0416 IDA-identified tables, not general engine constants. |
| Support clear passes `47`, `48`, `51` | Historical clear-support clone route | Build42 notes vs Build59/61 conflict | Superseded by later blocked/deferred decision | High if implemented from older notes | Remove from implementation guidance unless a new IDA/runtime pass validates a clear-compatible clone. |

## E. Release Notes/Public Claims Cleanup

Public package text reviewed:

| File | Result |
| --- | --- |
| `out/VisualEffectShaders/README.txt` | Generally safe. It describes install paths, command-driven use, and compatibility fallback without claiming full vanilla accuracy. |
| `out/VisualEffectShaders/Install.ps1` | Install behavior only; no reverse-engineering claims found. |

Claims that should not be copied to public-facing release notes without edits:

| Overconfident claim pattern | Safer replacement |
| --- | --- |
| "fully restores" | "restores the implemented command-driven effect path for the currently verified configuration" |
| "confirmed engine path" | "uses an IDA-identified path in the inspected 1.2.0416 binary" |
| "vanilla accurate" | "designed to match observed vanilla state where currently verified" |
| "authoritative" | "IDA-identified" or "currently validated" |
| "faithful" | "state-preserving for the inspected path" |
| "fully engine-native" | "plugin-owned pass that reuses identified engine state" unless a native object/vtable implementation is actually shipped |
| "100% decoded", "99.9% decoded" | "implemented path decoded; remaining coverage requires runtime validation" |
| "true terrain/object masking" | "depth-derived scene masking for the implemented path" unless object-ID/material masking is proven |

Remove from public release text:

| Text category | Reason |
| --- | --- |
| Completion percentages | No coverage metric is documented. |
| Claims that all object or skinned render paths are covered | Current hooks are exact-gated and path-specific. |
| Claims that native clear support clones are current | Later notes supersede them. |
| Any reference to `0x005E4515` as an implementation hook | It is stale and conflicts with xOBSE event ownership. |

Recommended public wording:

> VisualEffectShaders uses OBSE commands to start screen-space shader effects. The current build targets IDA-identified render paths in the inspected Oblivion 1.2.0416 binary and preserves compatibility fallback behavior when required hooks or shader profiles are unavailable.

## F. Hook Safety Review

| Hook | Purpose | Address/signature | Evidence | Control-flow assumptions | Failure mode | Safer alternative | Ship recommendation |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Player consume process-effects hook | Start consume-triggered effect after vanilla item effect handling | `0x00666639`, call to `0x006A23B0`; byte-validated in `main.cpp` | Current implementation validates expected bytes before patching | Hook fires on observed player-success consume path; original call preserves expected state | If address is wrong, effect may trigger incorrectly or original item effect handling may be corrupted; byte validation should fail closed | None safer found in current notes; old `0x005E4515` is worse | Safe for 1.2.0416 with current byte validation |
| Image-space post-call hook | Render VES distortion/pass after engine image-space processing | `0x0040CF6E` call to `0x007B48E0`; expected bytes validate call | IDA/corpus notes plus live wrapper | Hooked call is the relevant world render image-space call; render state can be restored safely | Incorrect target can corrupt render target/state or affect non-world renders | Native `BSImageSpaceShader` object remains a future safer integration if proven | Safe with current guards; needs wording limited to tested path |
| Non-skinned transform-copy hook | Apply local transform wobble before non-skinned geometry setup | `0x007694D7` call to `0x007672F0`; call replacement | Current hook filters inactive, skinned, screen elements, non-normal render mode | `ecx`/stack match the observed call convention and original callee returns with stack cleanup | Wrong calling convention could corrupt geometry setup; byte validation mitigates version mismatch | Broader transform-helper detours are less safe | Safe with current filters |
| Non-skinned post-setup vertex replacement | Replace/bind object vertex shader after native setup state | `0x00767410`; inline jump re-emits overwritten bytes and returns to `0x00767415` | Exact byte window documented in code | `edi`, `ebx`, `ebp`, `esi` retain the expected geometry/pass/wrapper state at the patch window | Wrong register assumption binds wrong shader or breaks draw path | Use only exact pass/wrapper gates; no clearly safer hook found | Needs more validation but acceptable exact-gated |
| Skinned post-setup vertex replacement | Replace/bind skinned object vertex shader after native setup state | `0x007676F9`; inline jump re-emits overwritten bytes and returns to `0x007676FE` | Later Build39/40 work supersedes earlier skinned boundary notes | Stack recovery of original geometry pointer remains valid after `pushad/pushfd`; registers match observed path | Wrong stack/register assumption can corrupt skinned actor/creature draws | Keep as exact-gated path; otherwise defer skinned support | Needs more validation; ship only exact-gated with runtime logging |
| World render/camera wrapper hooks | Apply camera sway/depth capture around world scenegraph render | `0x0040CCD3`, `0x0040CE48` calls to `0x0070C0B0`; byte-validated | Current wrapper checks world camera/render mode and restores camera state | Both call sites are normal world scenegraph render paths where camera replacement/restoration is valid | Wrong call context can affect menus, RTT, reflections, or shadow-like passes | Guard by `GetWorldCamera`, render mode, recursion depth; no safer current hook documented | Needs validation matrix; acceptable with current guards |
| Proposed native support/clear clone hooks | Extend support pass rendering and clear behavior | Build42 clear-support clone addresses/tables | Later Build59/61 notes block/defer clear clones | Assumes native clear passes can be cloned safely | Can clear the wrong target or break native support behavior | Preserve native clear behavior; use plugin-owned fallback only if proven | Do not ship stale clear clone guidance |

## G. Documentation Deduplication Plan

Source-of-truth recommendations:

| Topic | Source of truth | Treatment |
| --- | --- | --- |
| Current hook addresses, signatures, and safety | `ez_obse_plugin_example/docs/verification_cleanup_report.md` plus a future compact `current_hook_contracts.md` | Keep current and implementation-aligned. |
| Long-form decode narrative | `ez_obse_plugin_example/docs/ingredient_consume_hook_decode.md` | Keep as the main narrative, but add status markers for stale/superseded sections. |
| Historical build evidence | `ida_decodes/build*/` | Preserve as evidence snapshots, not implementation guidance. Add an index/status note. |
| Public install/use docs | `out/VisualEffectShaders/README.txt` | Keep command-focused; avoid IDA certainty claims. |
| Release/Nexus copy | Separate public release note drafted from current facts only | Do not paste internal decode claims directly. |

Files/prompts that should be merged or reduced:

| Group | Recommended action |
| --- | --- |
| Build28 and Build29 `SM3000_contract.md` | Keep the newer augmented contract as current; mark the older copy historical or replace with a pointer. |
| Build38 support decision matrix, Build42 support implementation contract, Build59 clear support fidelity | Merge the current decision into one support-pass status section. Mark Build42 clear clone material stale where contradicted by Build59/61. |
| Build39 world object wobble and Build40 hardware-skinned implementation | Keep Build40 as current hook mechanics; keep Build39 as rationale/evidence. |
| Prompt/Codex output summaries that repeat release claims | Reduce to short pointers to source-of-truth docs. |
| Public README vs internal decode docs | Keep separate. Public README should describe commands/install only. |

Canonical terminology list:

| Use | Avoid / previously called |
| --- | --- |
| `PlayerConsume_ProcessEffectsFromItemCall` | generic "confirmed player call" without scope |
| `NiRendererRender_ImageSpaceProcessCall` | treating `0x0040CF6E` as a function entry |
| `ProcessImageSpaceShader` | inconsistent `ImageShaderList` spelling unless quoting history |
| `NonSkinnedRenderTriGeometrySetup` (`sub_7672F0`) | plain "draw loop" without path qualifier |
| `SkinnedRenderTriGeometrySetup` (`sub_767520`) | generic "skinned path" without address |
| `NonSkinnedPostSetupVertexReplacementHook` | "object vertex shader hook" with no timing |
| `SkinnedPostSetupVertexReplacementHook` | "faithful skinned hook" |
| `SkinnedBoneMatrixHelper` (`sub_765560`) | "authoritative skinned hook boundary" |
| `StaleDoNotPatch_OnEatIngredientConflictSite` | `0x005E4515` as an active hook |
| "IDA-identified in 1.2.0416" | "authoritative", "fully decoded", "vanilla accurate" |

## H. Final Action List

P0: must fix before release

| Task | Owner/file target | Reason |
| --- | --- | --- |
| Mark `0x005E4515` stale/do-not-patch everywhere it appears as implementation guidance | `ingredient_consume_hook_decode.md`, related build notes | Prevent reintroducing xOBSE event conflict |
| Mark Build42 clear-support clone implementation guidance stale where superseded | Build42/59/61 support docs | Prevent shipping unsupported clear-pass clone logic |
| Remove percentage-completion claims and unsupported "fully/100%/vanilla accurate" wording from release notes and copied docs | Release/Nexus text, generated summaries | Public claims exceed evidence |
| Ensure any packaged public README stays command-driven and does not include internal speculative decode claims | `out/VisualEffectShaders/README.txt` and future release notes | Avoid public overclaiming |

P1: should fix before release

| Task | Owner/file target | Reason |
| --- | --- | --- |
| Add a compact current hook contract table with address, bytes, caller, registers/stack, hook type, and failure mode | New `current_hook_contracts.md` or top of main decode doc | Makes future code review safer |
| Canonicalize address/function names using the table above | Main decode doc and build indexes | Reduces drift across passes |
| Add a runtime validation matrix for `0x007676F9` skinned hook | Internal docs and test notes | Highest remaining hook-assumption risk |
| Add a runtime validation matrix for camera/world wrapper hooks | Internal docs and test notes | Needed for menus, RTT, first/third person, interiors/exteriors |
| Tag support-pass table addresses as 1.2.0416-specific | Lighting30/SM3000 docs | Prevent accidental cross-version assumptions |

P2: cleanup / documentation quality

| Task | Owner/file target | Reason |
| --- | --- | --- |
| Add a docs index that separates current guidance from historical evidence snapshots | `ida_decodes/README.md` or internal docs root | Reduces drift |
| Collapse duplicate SM3000 contract copies | Build28/29 docs | Avoid conflicting edits |
| Collapse support-pass decision docs into one current status section | Build38/42/59/61 docs | Avoid stale route selection |
| Replace "faithful" with concrete evidence wording unless attached to a validation result | Internal docs | Keeps language technically reviewable |
| Add "previously called" notes for retained aliases | Main decode doc | Preserves history without multiplying names |

P3: optional future refinement

| Task | Owner/file target | Reason |
| --- | --- | --- |
| Add a script to extract and diff hardcoded addresses from docs and `main.cpp` | Tooling | Catches stale addresses automatically |
| Add a runtime log capture template for hook validation | Docs/test tooling | Makes future evidence easier to compare |
| Perform an IDA naming pass for `ImageSpaceShaderList` and Lighting30 helper ownership | IDA corpus | Could upgrade likely names to confirmed |
| Revisit native `BSImageSpaceShader` object feasibility | Future decode branch | May produce a cleaner image-space integration later |

