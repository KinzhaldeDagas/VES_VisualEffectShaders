// 0x76FC40 @ 0x76FC40
// MoonSugarEffect decode: raw declaration element setter. Updates one stream/slot element fields, special-cases one type, marks declaration dirty, and releases cached IDirect3DVertexDeclaration9.
char __thiscall sub_76FC40(int this, unsigned int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v11; // eax
  bool v12; // zf
  _DWORD *v13; // eax
  int v14; // eax

  if ( a3 >= *(_DWORD *)(this + 0x1C) || a2 >= *(_DWORD *)(this + 0x20) ) /*0x76fc59*/
    return 0; /*0x76fc4c*/
  v11 = *(_DWORD *)(0x10 * a2 + *(_DWORD *)(this + 0x24) + 8); /*0x76fc6c*/
  v12 = *(_DWORD *)(v11 + 0x1C * a3 + 8) == a5; /*0x76fc81*/
  v13 = (_DWORD *)(v11 + 0x1C * a3); /*0x76fc85*/
  if ( !v12 || v13[3] != a6 || v13[5] != a7 || v13[6] != a8 || v13[4] != a9 ) /*0x76fca0*/
  {
    v13[2] = a5; /*0x76fca5*/
    v13[3] = a6; /*0x76fca8*/
    v13[5] = a7; /*0x76fcab*/
    v13[6] = a8; /*0x76fcae*/
    v13[4] = a9; /*0x76fcb1*/
    if ( a5 == 1 && a6 != 0x10 ) /*0x76fcb9*/
      v13[3] = 2; /*0x76fcbb*/
    v14 = *(_DWORD *)(this + 0x30); /*0x76fcc2*/
    *(_BYTE *)(this + 0x28) = 1; /*0x76fcc7*/
    if ( v14 ) /*0x76fccb*/
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(v14); /*0x76fcd3*/
      *(_DWORD *)(this + 0x30) = 0; /*0x76fcd5*/
    }
  }
  return 1; /*0x76fc4e*/
}
