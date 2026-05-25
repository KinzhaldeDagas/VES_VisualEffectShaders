// 0x007FB400 @ 0x007FB400
int __thiscall sub_7FB400(NiD3DShader *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // esi
  BOOL v10; // eax
  int v11; // eax

  v8 = *(_DWORD *)(a5 + 0x18); /*0x7fb406*/
  if ( v8 ) /*0x7fb40e*/
    v10 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v8 + 0x54))(*(_DWORD *)(a5 + 0x18)) == 0xA; /*0x7fb425*/
  else
    v10 = 0; /*0x7fb410*/
  v11 = v10 ? v8 : 0;
  if ( v11 ) /*0x7fb42d*/
    *(_BYTE *)(v11 + 0x100) = 0; /*0x7fb42f*/
  return sub_77A1B0(this, a2, a3, a4, a5, a6, a7, a8); /*0x7fb45c*/
}
