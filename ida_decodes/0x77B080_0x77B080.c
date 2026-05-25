// 0x77B080 @ 0x77B080
// MoonSugarEffect decode: NiDX9RenderState SetPixelShader cache. Caches current shader at +0xFE8, optional previous at +0xFEC, and only calls D3D SetPixelShader when value changes.
int __thiscall sub_77B080(int this, int a2, char a3)
{
  int result; // eax

  if ( a3 ) /*0x77b085*/
    *(_DWORD *)(this + 0xFEC) = *(_DWORD *)(this + 0xFE8); /*0x77b08d*/
  result = a2; /*0x77b093*/
  if ( *(_DWORD *)(this + 0xFE8) != a2 ) /*0x77b09d*/
  {
    *(_DWORD *)(this + 0xFE8) = a2; /*0x77b09f*/
    return (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 0xFF8) + 0x1AC))(*(_DWORD *)(this + 0xFF8), a2); /*0x77b0bb*/
  }
  return result; /*0x77b0bd*/
}
