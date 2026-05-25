// 0x0087AC50 @ 0x0087AC50
// MoonSugarEffect decode: SkinShader pooled-pass builder. Creates/refcounts 0x14 NiD3DPass entries in global table 0x00B47718, then calls vtable +0xC0 to populate pass stages/shaders.
char __thiscall sub_87AC50(void *this)
{
  unsigned int i; // edi
  NiD3DPass **v2; // esi
  NiD3DPass *v3; // ecx
  bool v4; // zf
  NiD3DPass *v5; // eax
  NiD3DPass *v6; // eax
  NiD3DPass *v8; // [esp+10h] [ebp-14h] BYREF
  void *v9; // [esp+14h] [ebp-10h]
  unsigned int v10; // [esp+20h] [ebp-4h]

  v9 = this; /*0x87ac76*/
  for ( i = 0; i < 0x14; ++i ) /*0x87ac7a*/
  {
    v2 = sub_7606A0(&v8); /*0x87ac8d*/
    v3 = (NiD3DPass *)dword_B47718[i]; /*0x87ac8f*/
    v4 = v3 == *v2; /*0x87ac95*/
    v10 = 0; /*0x87ac97*/
    if ( !v4 ) /*0x87ac9f*/
    {
      if ( v3 ) /*0x87aca3*/
      {
        v4 = v3->RefCount-- == 1; /*0x87aca5*/
        if ( v4 ) /*0x87aca8*/
          sub_7604D0(v3); /*0x87acaa*/
      }
      v5 = *v2; /*0x87acaf*/
      v4 = *v2 == 0; /*0x87acb1*/
      dword_B47718[i] = (int)*v2; /*0x87acb3*/
      if ( !v4 ) /*0x87acb9*/
        ++v5->RefCount; /*0x87acbb*/
    }
    v6 = v8; /*0x87acbf*/
    v10 = 0xFFFFFFFF; /*0x87acc5*/
    if ( v8 ) /*0x87acc9*/
    {
      --v8->RefCount; /*0x87accb*/
      if ( !v6->RefCount ) /*0x87acd3*/
        sub_7604D0(v6); /*0x87acd8*/
    }
  }
  (*(void (__thiscall **)(void *))(*(_DWORD *)v9 + 0xC0))(v9); /*0x87acf1*/
  return 1; /*0x87acf5*/
}
