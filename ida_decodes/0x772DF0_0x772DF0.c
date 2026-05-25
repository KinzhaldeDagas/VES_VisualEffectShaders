// 0x772DF0 @ 0x772DF0
// SpeedTree shader path: allocate/check out a render-state group from global pool dword_B427A8.
_BYTE *sub_772DF0()
{
  unsigned int *v0; // ecx
  _DWORD *v1; // esi
  _BYTE ***v2; // edi
  _DWORD *v3; // ebx
  _DWORD *v4; // ecx
  _BYTE *result; // eax

  v0 = (unsigned int *)dword_B427A8; /*0x772df0*/
  v1 = (_DWORD *)(dword_B427A8 + 8); /*0x772dfb*/
  v2 = (_BYTE ***)dword_B427A8; /*0x772dff*/
  if ( !*v1 ) /*0x772df6*/
  {
    v3 = v0 + 3; /*0x772e07*/
    sub_7729E0(v0, v0[3]); /*0x772e0b*/
    *v3 *= 2; /*0x772e14*/
  }
  v4 = *v2; /*0x772e17*/
  result = **v2; /*0x772e19*/
  *v4 = v4[--*v1]; /*0x772e23*/
  if ( !*result ) /*0x772e25*/
    *result = 1; /*0x772e2c*/
  return result; /*0x772e28*/
}
