// 0x9A35A0 @ 0x9A35A0
signed int __stdcall sub_9A35A0(
        int a1,
        int a2,
        NiObjectNET *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v14; // edi
  _DWORD *v15; // eax
  NiExtraData *ExtraData; // eax
  int *v17; // edi
  int v18; // ebx
  int v19; // ebx

  if ( !a3 ) /*0x9a35a8*/
    return 1; /*0x9a35b0*/
  if ( a13 /*0x9a35fb*/
    && (v14 = *(_DWORD *)(a13 + 0x18),
        v15 = (_DWORD *)(*(_DWORD *)(a13 + 0x20) + 8 * v14),
        *v15 == (*(_DWORD *)(a2 + 0x1C) | (a11 << 0x10)))
    && (ExtraData = (NiExtraData *)v15[1], *(_DWORD *)(a13 + 0x18) = v14 + 1, ExtraData)
    || (ExtraData = NiObjectNET_GetExtraData(a3, *(const char **)(a2 + 0xC))) != 0 )
  {
    v17 = sub_9A9040((_DWORD *)a2, (int)ExtraData); /*0x9a361f*/
    if ( !v17 ) /*0x9a3623*/
      return 0x80000040; /*0x9a362d*/
  }
  else
  {
    v17 = sub_9A92E0(a2); /*0x9a3605*/
    if ( !v17 ) /*0x9a3609*/
      return 0x80000010; /*0x9a3613*/
  }
  v18 = *(_DWORD *)(a2 + 0x14); /*0x9a3637*/
  if ( !byte_B4295B ) /*0x9a363a*/
    sub_783C70(); /*0x9a363c*/
  if ( dword_B428D8[(unsigned __int8)v18] == 9 ) /*0x9a364f*/
  {
    if ( !(*(unsigned __int8 (__thiscall **)(int, int, int *, int))(*(_DWORD *)a1 + 0x30))(a1, a2, v17, 4) ) /*0x9a365e*/
      return 0x80000050; /*0x9a3670*/
    return 0; /*0x9a3662*/
  }
  v19 = *(_DWORD *)(a2 + 0x14); /*0x9a367a*/
  if ( !byte_B4295B ) /*0x9a367d*/
    sub_783C70(); /*0x9a367f*/
  if ( dword_B428D8[(unsigned __int8)v19] != 6 /*0x9a36cd*/
    && !sub_7833A0((_DWORD *)a2)
    && !sub_783340((_DWORD *)a2)
    && !sub_783310((_DWORD *)a2)
    && !sub_7833D0((_DWORD *)a2)
    && !sub_7832E0((_DWORD *)a2)
    && !sub_7832B0((_DWORD *)a2) )
  {
    if ( sub_782DE0((_DWORD *)a2) ) /*0x9a36d8*/
    {
      if ( !(*(unsigned __int8 (__thiscall **)(int, int, int *, int))(*(_DWORD *)a1 + 0x30))(a1, a2, v17, 3) ) /*0x9a36ee*/
        return 0x80000050; /*0x9a36fc*/
    }
    else
    {
      sub_9A32B0((_DWORD *)a2); /*0x9a3701*/
    }
    return 0; /*0x9a36f2*/
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, v17, 0) ) /*0x9a371b*/
    return 0; /*0x9a370b*/
  return 0x80000050; /*0x9a35af*/
}
