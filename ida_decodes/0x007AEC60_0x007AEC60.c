// 0x007AEC60 @ 0x007AEC60
// MoonSugarEffect decode: NiD3DPass pixel-shader ref setter. Replaces pass+0x44 with NiD3DPixelShader*, releases old wrapper, AddRefs new wrapper.
void __thiscall sub_7AEC60(NiD3DPassVtbl **this, NiD3DPixelShader *a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)*(this + 0x11); /*0x7aec64*/
  if ( v3 != (volatile LONG *)a2 ) /*0x7aec6e*/
  {
    if ( v3 ) /*0x7aec72*/
    {
      if ( !InterlockedDecrement(v3 + 1) ) /*0x7aec78*/
        (**(void (__thiscall ***)(volatile LONG *, int))v3)(v3, 1); /*0x7aec8e*/
    }
    *(this + 0x11) = (NiD3DPassVtbl *)a2; /*0x7aec92*/
    if ( a2 ) /*0x7aec95*/
      InterlockedIncrement((volatile LONG *)a2 + 1); /*0x7aec9b*/
  }
}
