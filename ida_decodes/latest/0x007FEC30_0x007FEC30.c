// 0x007FEC30 @ 0x007FEC30
// MoonSugarEffect: Lighting30Shader pooled pass builder creates/refcounts 0x36 global passes at dword_B473D0. Runtime v0.0.17 objectVS skipPass suggests this table is the likely dominant non-Parallax scene path to census next.
char __thiscall sub_7FEC30(NiD3DPass *this)
{
  unsigned int i; // edi
  NiD3DPass **v2; // esi
  NiD3DPass *v3; // ecx
  bool v4; // zf
  NiD3DPass *v5; // eax
  NiD3DPass *v6; // eax
  NiD3DPass *v8[2]; // [esp+10h] [ebp-14h] BYREF
  unsigned int v9; // [esp+20h] [ebp-4h]

  v8[1] = this; /*0x7fec56*/
  for ( i = 0; i < 0x36; ++i ) /*0x7fec5a*/
  {
    v2 = sub_7606A0(v8); /*0x7fec6d*/
    v3 = (NiD3DPass *)dword_B473D0[i]; /*0x7fec6f*/
    v4 = v3 == *v2; /*0x7fec75*/
    v9 = 0; /*0x7fec77*/
    if ( !v4 ) /*0x7fec7f*/
    {
      if ( v3 ) /*0x7fec83*/
      {
        v4 = v3->RefCount-- == 1; /*0x7fec85*/
        if ( v4 ) /*0x7fec88*/
          sub_7604D0(v3); /*0x7fec8a*/
      }
      v5 = *v2; /*0x7fec8f*/
      v4 = *v2 == 0; /*0x7fec91*/
      dword_B473D0[i] = (int)*v2; /*0x7fec93*/
      if ( !v4 ) /*0x7fec99*/
        ++v5->RefCount; /*0x7fec9b*/
    }
    v6 = v8[0]; /*0x7fec9f*/
    v9 = 0xFFFFFFFF; /*0x7feca5*/
    if ( v8[0] ) /*0x7feca9*/
    {
      --v8[0]->RefCount; /*0x7fecab*/
      if ( !v6->RefCount ) /*0x7fecb3*/
        sub_7604D0(v6); /*0x7fecb8*/
    }
  }
  sub_85E660(); /*0x7feccc*/
  return 1; /*0x7fecd3*/
}
