// 0x7D7030 @ 0x7D7030
LONG sub_7D7030()
{
  LONG result; // eax
  int v1; // esi
  _DWORD *v2; // edi

  result = dword_B45D74; /*0x7d7030*/
  if ( dword_B45D74 ) /*0x7d7030*/
  {
    --result; /*0x7d703a*/
    v1 = *(_DWORD *)(4 * result + 0xB45D78); /*0x7d703d*/
    v2 = (_DWORD *)(4 * result + 0xB45D78); /*0x7d7047*/
    dword_B45D74 = result; /*0x7d704e*/
    if ( v1 ) /*0x7d7053*/
    {
      result = InterlockedDecrement((volatile LONG *)(v1 + 4)); /*0x7d7059*/
      if ( !result ) /*0x7d7061*/
        result = (**(int (__thiscall ***)(int, int))v1)(v1, 1); /*0x7d706f*/
      *v2 = 0; /*0x7d7071*/
    }
  }
  return result; /*0x7d7079*/
}
