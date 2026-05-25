// 0x801110 @ 0x801110
// SpeedTree texture-stage initializer: D3DTSS_TEXCOORDINDEX=arg2, COLOROP/ALPHAOP=D3DTOP_DISABLE, COLORARG1/ALPHAARG1=D3DTA_TEXTURE, ADDRESSU/V=arg3, MAG/MIN/MIPFILTER=arg4.
_BYTE *__cdecl sub_801110(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx

  v4 = *(_DWORD **)(a1 + 0xC); /*0x801119*/
  *(_DWORD *)a1 = a2; /*0x801122*/
  sub_772FF0(v4, 0xB, a2, 0); /*0x801124*/
  sub_772FF0(*(_DWORD **)(a1 + 0xC), 1, 1, 0); /*0x801132*/
  sub_772FF0(*(_DWORD **)(a1 + 0xC), 2, 2, 0); /*0x801140*/
  sub_772FF0(*(_DWORD **)(a1 + 0xC), 4, 1, 0); /*0x80114e*/
  sub_772FF0(*(_DWORD **)(a1 + 0xC), 5, 2, 0); /*0x80115c*/
  v5 = *(_DWORD **)(a1 + 0xC); /*0x801161*/
  *(_BYTE *)(a1 + 0x5A) = 0; /*0x80116a*/
  sub_772FF0(v5, 0x18, 0, 0); /*0x80116e*/
  sub_773100(*(_DWORD **)(a1 + 0xC), 1, a3, 0, 0); /*0x801181*/
  sub_773100(*(_DWORD **)(a1 + 0xC), 2, a3, 0, 0); /*0x801190*/
  sub_773100(*(_DWORD **)(a1 + 0xC), 5, a4, 0, 0); /*0x8011a3*/
  sub_773100(*(_DWORD **)(a1 + 0xC), 6, a4, 0, 0); /*0x8011b2*/
  sub_773100(*(_DWORD **)(a1 + 0xC), 7, a4, 0, 0); /*0x8011c1*/
  return sub_771640((_DWORD **)a1, 2); /*0x8011cf*/
}
