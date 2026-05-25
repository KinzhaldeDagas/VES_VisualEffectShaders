# Embedded vertex bytecode contract

Build 52 changes shader availability, not shader eligibility.

## Oblivion evidence

`CreateVertexShader` at `0x008014E0` is the native vertex program loader. The decoded success path shows:

- `0x00801B93`: compiled vertex shader bytecode is passed to the D3D device `CreateVertexShader`;
- `0x00801BCC`: Oblivion allocates the concrete `NiD3DVertexShader` wrapper;
- `0x00801BF0`: the wrapper is initialized against the renderer/device;
- `0x00801C14`: the D3D shader handle is stored through the wrapper vtable setter.

The object hook already runs after native pass setup and constant flush, so Moon Sugar does not need to create new native `NiD3DShaderProgram` wrappers for replacement draws. It installs a plugin-owned D3D vertex shader handle for the current draw only.

## Build 52 application

The replacement vertex shaders are now compiled offline with the same HLSL strings and macro sets used by the runtime compiler:

- legacy `PAR2016/SKIN2008` clone: `vs_2_0`;
- Lighting30 object, EnvMap, TexEffect, Decal, DepthMap, ZOnly, SimpleShadow, RenderNormals, and LocalMap clones: `vs_3_0`.

Runtime selection remains unchanged. The exact pass/program gates still decide whether a replacement is legal. The embedded bytecode only removes the dependency on `d3dx9_43.dll` for replacement vertex shader creation.

If embedded creation fails, the old runtime D3DX source compile path remains as a fallback. No Fallout behavior is used for eligibility or shader semantics.
