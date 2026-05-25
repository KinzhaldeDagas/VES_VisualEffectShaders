// 0x77B410 @ 0x77B410
// MoonSugarEffect decode: NiDX9RenderState SetFVF cache. Marks fixed-function input mode (+0x1000=0), caches FVF at +0x1004, optional previous +0x1008, calls D3D SetFVF only on change.
int __thiscall sub_77B410(int this, int a2, char a3)
{
  int result; // eax

  result = a2; /*0x77b410*/
  if ( a2 ) /*0x77b416*/
  {
    if ( *(_BYTE *)(this + 0x1000) || *(_DWORD *)(this + 0x1004) != a2 ) /*0x77b427*/
    {
      *(_BYTE *)(this + 0x1000) = 0; /*0x77b42e*/
      if ( a3 ) /*0x77b435*/
        *(_DWORD *)(this + 0x1008) = *(_DWORD *)(this + 0x1004); /*0x77b43d*/
      *(_DWORD *)(this + 0x1004) = a2; /*0x77b443*/
      return (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 0xFF8) + 0x164))(*(_DWORD *)(this + 0xFF8), a2); /*0x77b45f*/
    }
  }
  return result; /*0x77b461*/
}
