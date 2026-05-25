// 0x7ABDE0 @ 0x7ABDE0
// MoonSugarEffect decode: BSTPersistentList append helper. Reuses a free node or allocates one, stores payload at node+8, links at tail, increments count.
int *__thiscall sub_7ABDE0(_DWORD *this, int *a2)
{
  int *result; // eax
  _DWORD *v4; // ecx

  result = (int *)*(this + 3); /*0x7abde3*/
  if ( result ) /*0x7abde8*/
    *(this + 3) = *result; /*0x7abdf6*/
  else
    result = sub_44D810(); /*0x7abded*/
  result[2] = *a2; /*0x7abdff*/
  *result = 0; /*0x7abe02*/
  result[1] = *(this + 2); /*0x7abe0b*/
  v4 = (_DWORD *)*(this + 2); /*0x7abe0e*/
  if ( v4 ) /*0x7abe13*/
  {
    *v4 = result; /*0x7abe15*/
    ++*(this + 4); /*0x7abe17*/
  }
  else
  {
    ++*(this + 4); /*0x7abe22*/
    *(this + 1) = result; /*0x7abe26*/
  }
  *(this + 2) = result; /*0x7abe1b*/
  return result; /*0x7abe1e*/
}
