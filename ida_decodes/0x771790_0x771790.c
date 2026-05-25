// 0x771790 @ 0x771790
int __cdecl sub_771790(unsigned int a1)
{
  unsigned int i; // esi
  int result; // eax

  for ( i = a1; i < dword_B28CB0; ++i ) /*0x77179b*/
  {
    ((void (__thiscall *)(NiDX9RenderState *, unsigned int, _DWORD))dword_B42758->vtbl->SetTexture)(dword_B42758, i, 0); /*0x7717b1*/
    ((void (__thiscall *)(NiDX9RenderState *, unsigned int, int, int, _DWORD))dword_B42758->vtbl->SetTextureStageState)( /*0x7717c8*/
      dword_B42758,
      i,
      1,
      1,
      0);
    ((void (__thiscall *)(NiDX9RenderState *, unsigned int, int, int, _DWORD))dword_B42758->vtbl->SetTextureStageState)( /*0x7717df*/
      dword_B42758,
      i,
      4,
      1,
      0);
    result = ((int (__thiscall *)(NiDX9RenderState *, unsigned int, int, _DWORD, _DWORD))dword_B42758->vtbl->SetTextureStageState)( /*0x7717f6*/
               dword_B42758,
               i,
               0x18,
               0,
               0);
  }
  for ( ; i < dword_B28CB8; ++i ) /*0x771809*/
    result = ((int (__thiscall *)(NiDX9RenderState *, unsigned int, _DWORD))dword_B42758->vtbl->SetTexture)( /*0x771821*/
               dword_B42758,
               i,
               0);
  return result; /*0x77182e*/
}
