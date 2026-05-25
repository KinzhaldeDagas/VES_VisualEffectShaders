// 0x007FB250 @ 0x007FB250
char __thiscall sub_7FB250(BSShader *this)
{
  LONG (__stdcall *v1)(volatile LONG *); // ebp
  int *v2; // edi
  int v3; // esi
  int i; // edi
  int v5; // esi
  int v6; // esi
  NiD3DPass **v7; // esi
  NiD3DPass *v8; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // ebp
  int v13; // edx

  sub_8025F0(this); /*0x7fb254*/
  v1 = InterlockedDecrement; /*0x7fb259*/
  v2 = dword_B47288; /*0x7fb25f*/
  do /*0x7fb28f*/
  {
    v3 = *v2; /*0x7fb266*/
    if ( *v2 ) /*0x7fb266*/
    {
      if ( !v1((volatile LONG *)(v3 + 4)) ) /*0x7fb270*/
      {
        if ( v3 ) /*0x7fb278*/
          (**(void (__thiscall ***)(int, int))v3)(v3, 1); /*0x7fb282*/
      }
      *v2 = 0; /*0x7fb284*/
    }
    ++v2; /*0x7fb286*/
  }
  while ( (int)v2 < (int)dword_B47308 ); /*0x7fb28f*/
  for ( i = 0; i < 0x27; ++i ) /*0x7fb291*/
  {
    v5 = dword_B46ED8[i]; /*0x7fb293*/
    if ( v5 ) /*0x7fb29b*/
    {
      if ( !v1((volatile LONG *)(v5 + 4)) ) /*0x7fb2a1*/
        (**(void (__thiscall ***)(int, int))v5)(v5, 1); /*0x7fb2b3*/
      dword_B46ED8[i] = 0; /*0x7fb2b5*/
    }
    v6 = dword_B46C20[i]; /*0x7fb2bb*/
    if ( v6 ) /*0x7fb2c3*/
    {
      if ( !v1((volatile LONG *)(v6 + 4)) ) /*0x7fb2c9*/
        (**(void (__thiscall ***)(int, int))v6)(v6, 1); /*0x7fb2db*/
      dword_B46C20[i] = 0; /*0x7fb2dd*/
    }
  }
  v7 = (NiD3DPass **)dword_B473D0; /*0x7fb2ee*/
  do /*0x7fb311*/
  {
    v8 = *v7; /*0x7fb2f6*/
    if ( *v7 ) /*0x7fb2f6*/
    {
      if ( v8->RefCount-- == 1 ) /*0x7fb2fc*/
        sub_7604D0(v8); /*0x7fb301*/
      *v7 = 0; /*0x7fb306*/
    }
    ++v7; /*0x7fb308*/
  }
  while ( (int)v7 < (int)&dword_B474A8 ); /*0x7fb311*/
  v10 = dword_B25AD0; /*0x7fb313*/
  v11 = dword_B25AD8; /*0x7fb318*/
  v12 = dword_B25ADC; /*0x7fb31e*/
  v13 = dword_B25AD4; /*0x7fb324*/
  dword_B46CC8 = dword_B25AD0; /*0x7fb32a*/
  dword_B46CD0 = v11; /*0x7fb32f*/
  dword_B46CD4 = v12; /*0x7fb335*/
  dword_B46CCC = v13; /*0x7fb34a*/
  qmemcpy(&unk_B46CD8, &dword_B46CC8, 0x200u); /*0x7fb350*/
  dword_B46F78 = v10; /*0x7fb352*/
  dword_B46F80 = v11; /*0x7fb357*/
  dword_B46F84 = v12; /*0x7fb35d*/
  dword_B46F7C = v13; /*0x7fb372*/
  qmemcpy(&dword_B46F88, &dword_B46F78, 0x300u); /*0x7fb378*/
  return 1; /*0x7fb37a*/
}
