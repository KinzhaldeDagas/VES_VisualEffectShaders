// 0x405710 @ 0x405710
void __thiscall NiDX9Renderer::SetShaderAccumulator(NiDX9Renderer *this, BSShaderAccumulator *a2)
{
  volatile LONG *accumulator; // esi

  accumulator = (volatile LONG *)this->member.super.accumulator; /*0x405714*/
  if ( accumulator != (volatile LONG *)a2 ) /*0x40571e*/
  {
    if ( accumulator ) /*0x405722*/
    {
      if ( !InterlockedDecrement(accumulator + 1) ) /*0x405728*/
        (**(void (__thiscall ***)(volatile LONG *, int))accumulator)(accumulator, 1); /*0x40573e*/
    }
    this->member.super.accumulator = a2; /*0x405742*/
    if ( a2 ) /*0x405745*/
      InterlockedIncrement((volatile LONG *)a2 + 1); /*0x40574b*/
  }
}
