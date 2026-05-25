// 0x008097D0 @ 0x008097D0
char __thiscall sub_8097D0(BSShader *this)
{
  unsigned __int16 *v2; // edi
  int v3; // ebx
  int v4; // esi
  unsigned __int16 *v5; // edi
  int v6; // ebx
  int v7; // esi
  NiD3DPass **v8; // esi
  NiD3DPass *v9; // ecx

  sub_8025F0(this); /*0x8097d6*/
  v2 = (unsigned __int16 *)((char *)this + 0x9C); /*0x8097db*/
  v3 = 0x14; /*0x8097e1*/
  do /*0x809814*/
  {
    v4 = *(_DWORD *)v2; /*0x8097e6*/
    if ( *(_DWORD *)v2 ) /*0x8097e6*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) ) /*0x8097f0*/
      {
        if ( v4 ) /*0x8097fc*/
          (**(void (__thiscall ***)(int, int))v4)(v4, 1); /*0x809806*/
      }
      *(_DWORD *)v2 = 0; /*0x809808*/
    }
    v2 += 2; /*0x80980e*/
    --v3; /*0x809811*/
  }
  while ( v3 ); /*0x809814*/
  v5 = (unsigned __int16 *)((char *)this + 0xEC); /*0x809816*/
  v6 = 0xA; /*0x80981c*/
  do /*0x80984f*/
  {
    v7 = *(_DWORD *)v5; /*0x809821*/
    if ( *(_DWORD *)v5 ) /*0x809821*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) ) /*0x80982b*/
      {
        if ( v7 ) /*0x809837*/
          (**(void (__thiscall ***)(int, int))v7)(v7, 1); /*0x809841*/
      }
      *(_DWORD *)v5 = 0; /*0x809843*/
    }
    v5 += 2; /*0x809849*/
    --v6; /*0x80984c*/
  }
  while ( v6 ); /*0x80984f*/
  v8 = (NiD3DPass **)dword_B47718; /*0x809851*/
  do /*0x80987f*/
  {
    v9 = *v8; /*0x809860*/
    if ( *v8 ) /*0x809860*/
    {
      if ( v9->RefCount-- == 1 ) /*0x809866*/
        sub_7604D0(v9); /*0x80986b*/
      *v8 = 0; /*0x809870*/
    }
    ++v8; /*0x809876*/
  }
  while ( (int)v8 < (int)&dword_B47768 ); /*0x80987f*/
  return 1; /*0x809881*/
}
