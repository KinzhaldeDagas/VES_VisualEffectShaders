// 0x008066E0 @ 0x008066E0
char __thiscall sub_8066E0(BSShader *this)
{
  unsigned __int16 *v2; // edi
  int v3; // ebx
  int v4; // esi
  unsigned __int16 *v5; // edi
  int v6; // ebx
  int v7; // esi
  NiD3DPass **v8; // esi
  NiD3DPass *v9; // ecx

  sub_8025F0(this); /*0x8066e6*/
  v2 = (unsigned __int16 *)((char *)this + 0x9C); /*0x8066eb*/
  v3 = 0x24; /*0x8066f1*/
  do /*0x806724*/
  {
    v4 = *(_DWORD *)v2; /*0x8066f6*/
    if ( *(_DWORD *)v2 ) /*0x8066f6*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) ) /*0x806700*/
      {
        if ( v4 ) /*0x80670c*/
          (**(void (__thiscall ***)(int, int))v4)(v4, 1); /*0x806716*/
      }
      *(_DWORD *)v2 = 0; /*0x806718*/
    }
    v2 += 2; /*0x80671e*/
    --v3; /*0x806721*/
  }
  while ( v3 ); /*0x806724*/
  v5 = (unsigned __int16 *)((char *)this + 0x12C); /*0x806726*/
  v6 = 0x1E; /*0x80672c*/
  do /*0x80675f*/
  {
    v7 = *(_DWORD *)v5; /*0x806731*/
    if ( *(_DWORD *)v5 ) /*0x806731*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) ) /*0x80673b*/
      {
        if ( v7 ) /*0x806747*/
          (**(void (__thiscall ***)(int, int))v7)(v7, 1); /*0x806751*/
      }
      *(_DWORD *)v5 = 0; /*0x806753*/
    }
    v5 += 2; /*0x806759*/
    --v6; /*0x80675c*/
  }
  while ( v6 ); /*0x80675f*/
  v8 = (NiD3DPass **)dword_B47620; /*0x806761*/
  do /*0x80678f*/
  {
    v9 = *v8; /*0x806770*/
    if ( *v8 ) /*0x806770*/
    {
      if ( v9->RefCount-- == 1 ) /*0x806776*/
        sub_7604D0(v9); /*0x80677b*/
      *v8 = 0; /*0x806780*/
    }
    ++v8; /*0x806786*/
  }
  while ( (int)v8 < (int)&unk_B47710 ); /*0x80678f*/
  return 1; /*0x806791*/
}
