// 0x70BF30 @ 0x70BF30
// MoonSugarEffect decode: visible-array submission helper. If renderer has an accumulator, AddRefs it and calls vtable +0x54 with the visible array; otherwise renders every NiGeometry directly through vtable +0x84.
void __cdecl sub_70BF30(_DWORD *a1)
{
  NiDX9Renderer *v1; // ebp
  volatile LONG *accumulator; // esi
  unsigned int v3; // edi
  unsigned int i; // esi
  volatile LONG *v5; // [esp+14h] [ebp-10h]

  v1 = g_Renderer; /*0x70bf55*/
  if ( g_Renderer ) /*0x70bf55*/
  {
    accumulator = (volatile LONG *)v1->member.super.accumulator; /*0x70bf63*/
    v5 = accumulator; /*0x70bf68*/
    if ( accumulator ) /*0x70bf6c*/
    {
      InterlockedIncrement(accumulator + 1); /*0x70bf72*/
      (*(void (__thiscall **)(volatile LONG *, _DWORD *))(*accumulator + 0x54))(accumulator, a1); /*0x70bf90*/
    }
    else
    {
      v3 = a1[1]; /*0x70bf98*/
      for ( i = 0; i < v3; ++i ) /*0x70bf9f*/
        (*(void (__thiscall **)(_DWORD, NiDX9Renderer *))(**(_DWORD **)(*a1 + 4 * i) + 0x84))( /*0x70bfaf*/
          *(_DWORD *)(*a1 + 4 * i),
          v1);
      accumulator = v5; /*0x70bfb8*/
    }
    if ( accumulator ) /*0x70bfc6*/
    {
      if ( !InterlockedDecrement(accumulator + 1) ) /*0x70bfcc*/
        (**(void (__thiscall ***)(volatile LONG *, int))accumulator)(accumulator, 1); /*0x70bfde*/
    }
  }
}
