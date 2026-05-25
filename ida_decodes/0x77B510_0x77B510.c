// 0x77B510 @ 0x77B510
// MoonSugarEffect decode: NiDX9RenderState SetVertexDeclaration cache. Marks declaration input mode (+0x1000=1), caches declaration at +0x100C, optional previous +0x1010, calls D3D SetVertexDeclaration only on change.
int __thiscall sub_77B510(int this, int a2, char a3)
{
  int result; // eax

  result = a2; /*0x77b510*/
  if ( a2 ) /*0x77b516*/
  {
    if ( !*(_BYTE *)(this + 0x1000) || *(_DWORD *)(this + 0x100C) != a2 ) /*0x77b527*/
    {
      *(_BYTE *)(this + 0x1000) = 1; /*0x77b52e*/
      if ( a3 ) /*0x77b535*/
        *(_DWORD *)(this + 0x1010) = *(_DWORD *)(this + 0x100C); /*0x77b53d*/
      *(_DWORD *)(this + 0x100C) = a2; /*0x77b543*/
      return (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 0xFF8) + 0x15C))(*(_DWORD *)(this + 0xFF8), a2); /*0x77b55f*/
    }
  }
  return result; /*0x77b561*/
}
