// 0x7B7650 @ 0x7B7650
BSShaderAccumulator *InitBSShaderAccumulator()
{
  BSShaderAccumulator *result; // eax
  BSShaderAccumulator *v1; // eax
  BSShaderAccumulator *v2; // esi
  BSShaderAccumulator *v3; // edi

  result = dword_B430FC; /*0x7b7673*/
  if ( !dword_B430FC ) /*0x7b7673*/
  {
    v1 = (BSShaderAccumulator *)FormHeapAlloc(0x226Cu); /*0x7b7681*/
    if ( v1 ) /*0x7b7697*/
      v2 = BSShaderAccumulator::BSShaderAccumulator(v1); /*0x7b76a0*/
    else
      v2 = 0; /*0x7b76a4*/
    result = dword_B430FC; /*0x7b76a6*/
    if ( dword_B430FC != v2 ) /*0x7b76b5*/
    {
      if ( result ) /*0x7b76b9*/
      {
        v3 = dword_B430FC; /*0x7b76bb*/
        if ( !InterlockedDecrement((volatile LONG *)result + 1) ) /*0x7b76c1*/
          (**(void (__thiscall ***)(BSShaderAccumulator *, int))v3)(v3, 1); /*0x7b76d7*/
      }
      result = v2; /*0x7b76db*/
      dword_B430FC = v2; /*0x7b76dd*/
      if ( v2 ) /*0x7b76e2*/
      {
        InterlockedIncrement((volatile LONG *)v2 + 1); /*0x7b76e8*/
        return dword_B430FC; /*0x7b76ee*/
      }
    }
  }
  return result; /*0x7b76f3*/
}
