// 0x7AECB0 @ 0x7AECB0
void __thiscall sub_7AECB0(NiD3DPass *this, NiD3DVertexShader *a2)
{
  volatile LONG *VertexShader; // esi

  VertexShader = (volatile LONG *)this->VertexShader; /*0x7aecb4*/
  if ( VertexShader != (volatile LONG *)a2 ) /*0x7aecbe*/
  {
    if ( VertexShader ) /*0x7aecc2*/
    {
      if ( !InterlockedDecrement(VertexShader + 1) ) /*0x7aecc8*/
        (**(void (__thiscall ***)(volatile LONG *, int))VertexShader)(VertexShader, 1); /*0x7aecde*/
    }
    this->VertexShader = a2; /*0x7aece2*/
    if ( a2 ) /*0x7aece5*/
      InterlockedIncrement((volatile LONG *)a2 + 1); /*0x7aeceb*/
  }
}
