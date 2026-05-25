// 0x75FB10 @ 0x75FB10
_DWORD *__thiscall sub_75FB10(_DWORD *this, _DWORD *a2)
{
  int v2; // eax

  v2 = *(this + 1); /*0x75fb10*/
  *a2 = v2; /*0x75fb1a*/
  if ( v2 ) /*0x75fb1c*/
    InterlockedIncrement((volatile LONG *)(v2 + 4)); /*0x75fb22*/
  return a2; /*0x75fb2a*/
}
