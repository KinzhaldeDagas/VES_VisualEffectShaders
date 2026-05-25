# Build 86 Daggers Opcode Registration

Scope: replace the temporary VES opcode hotfix base with a range recorded in `C:\src\Daggers_opcodes.csv`.

## Registered Range

| Plugin | Start | End | Count |
| --- | --- | --- | --- |
| `VisualEffectShaders.dll` | `0x70F0` | `0x7111` | 34 |

The plugin now calls `SetOpcodeBase(0x70F0)`.

## Command Order

The CSV rows follow the OBSE `RegisterCommand` order used by `main.cpp`. The Dim color commands are:

| Command | Opcode |
| --- | --- |
| `VESDimPurple` | `0x7103` |
| `VESDimDarkRed` | `0x7104` |

## Semantics

This is an opcode registration correction only. It does not alter shader bytecode, profile IDs, hook addresses, render-path semantics, or effect behavior.

