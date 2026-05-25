# IDA Decode Corpus Status

This directory is a historical evidence corpus. Files under `build*/`, `latest*/`, and address-named `.c` exports are snapshots from specific decode passes. They are not automatically current implementation guidance.

Current source-of-truth files:

| Topic | Canonical file |
| --- | --- |
| Current hook addresses, hook status, stale-address quarantine, terminology, and confidence legend | `ez_obse_plugin_example/docs/current_hook_contracts.md` |
| Cleanup audit and action list | `ez_obse_plugin_example/docs/verification_cleanup_report.md` |
| Long-form decode narrative | `ez_obse_plugin_example/docs/ingredient_consume_hook_decode.md` |
| Public command/install wording | `out/VisualEffectShaders/README.txt` |

## Historical Snapshot Status

| Area | Files | Status |
| --- | --- | --- |
| SM3000 Lighting30 contract | `build28_lighting30_sm3000_contract/SM3000_contract.md`, `build29_lighting30_sm3000_vs3_implementation/SM3000_contract.md` | Build29 is the augmented/current snapshot for the SM3000 implementation. Build28 is historical decode evidence. |
| Support-pass policy | `build38_support_pass_decision/Support_pass_decision_matrix.md`, `build42_support_pipeline_implementation/Support_pipeline_implementation_contract.md`, `build59_clear_support_fidelity/Clear_support_fidelity.md` | Build59/61 supersede Build42 clear replacement guidance for passes `47`, `48`, and `51`. Keep Build42 non-clear notes as historical implementation context only. |
| Skinned object wobble | `build39_world_object_wobble/World_object_wobble_submission_coverage.md`, `build40_hardware_skinned_object_wobble/Hardware_skinned_object_wobble_implementation.md` | Build40 is the current hook-mechanics snapshot. Build39 is rationale/evidence. `sub_765560` and `0x007655F0` are skinned setup evidence, not current hook boundaries. |
| Lighting30 tables/selectors | `lighting30_build20/`, `build21_program_labels/`, `build22_lighting30_pass_map/`, `build23_lighting30_selector_masks/`, `build24_lighting30_selector_routes/`, `build25_lighting30_constant_masks/`, `build26_lighting30_contract_telemetry/`, `build27_lighting30_pixel_contracts/` | Historical evidence chain. Use neutral names such as `sub_85E660_Lighting30PassPopulate` and `sub_7FD260_Lighting30SelectorRoute`; do not claim recovered source names. |
| Auxiliary shader families | `build33_lighting30_auxiliary_contracts/`, `build34_aux_visible_shader_families/`, `build35_envmap_implementation/`, `build36_texeffect_implementation/`, `build37_decal_implementation/`, `build41_depthmap_implementation/`, `build43_simpleshadow_pipeline_implementation/` | Historical decode/implementation snapshots. Active use remains exact-gated and path-specific. |

## Corpus Rules

- Preserve raw address-named `.c` exports as evidence snapshots.
- Do not promote an address or inferred name from a historical note to current implementation guidance unless it appears in `current_hook_contracts.md`.
- Keep stale addresses in archived/superseded sections only.
- Avoid quantitative decode-completion percentages unless a future pass adds a real coverage method.
- Public-facing text must use conservative wording: "IDA-identified in the inspected 1.2.0416 binary", "observed in this call path", "designed around observed behavior", or "requires runtime validation".

