// 0x77B350 @ 0x77B350
// MoonSugarEffect decode: NiDX9RenderState SetVertexShader cache. Caches current shader at +0xFE0, optional previous at +0xFE4, and only calls D3D SetVertexShader when value changes.
int __thiscall sub_77B350(int this, int a2, char a3)
{
  int result; // eax

  if ( a3 ) /*0x77b355*/
    *(_DWORD *)(this + 0xFE4) = *(_DWORD *)(this + 0xFE0); /*0x77b35d*/
  result = a2; /*0x77b363*/
  if ( *(_DWORD *)(this + 0xFE0) != a2 ) /*0x77b36d*/
  {
    *(_DWORD *)(this + 0xFE0) = a2; /*0x77b36f*/
    return (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 0xFF8) + 0x170))(*(_DWORD *)(this + 0xFF8), a2); /*0x77b38b*/
  }
  return result; /*0x77b38d*/
}
