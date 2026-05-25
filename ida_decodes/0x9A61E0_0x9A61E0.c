// 0x9A61E0 @ 0x9A61E0
signed int __stdcall sub_9A61E0(
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

  if ( !a3 ) /*0x9a61e8*/
    return 1; /*0x9a61f0*/
  if ( a13 /*0x9a623b*/
    && (v14 = *(_DWORD *)(a13 + 0x14),
        v15 = (_DWORD *)(*(_DWORD *)(a13 + 0x1C) + 8 * v14),
        *v15 == (*(_DWORD *)(a2 + 0x1C) | (a11 << 0x10)))
    && (ExtraData = (NiExtraData *)v15[1], *(_DWORD *)(a13 + 0x14) = v14 + 1, ExtraData)
    || (ExtraData = NiObjectNET_GetExtraData(a3, *(const char **)(a2 + 0xC))) != 0 )
  {
    v17 = sub_9A9040((_DWORD *)a2, (int)ExtraData); /*0x9a625f*/
    if ( !v17 ) /*0x9a6263*/
      return 0x80000040; /*0x9a626d*/
  }
  else
  {
    v17 = sub_9A92E0(a2); /*0x9a6245*/
    if ( !v17 ) /*0x9a6249*/
      return 0x80000010; /*0x9a6253*/
  }
  v18 = *(_DWORD *)(a2 + 0x14); /*0x9a6277*/
  if ( !byte_B4295B ) /*0x9a627a*/
    sub_783C70(); /*0x9a627c*/
  if ( dword_B428D8[(unsigned __int8)v18] == 9 ) /*0x9a628f*/
  {
    if ( !(*(unsigned __int8 (__thiscall **)(int, int, int *, int))(*(_DWORD *)a1 + 0x28))(a1, a2, v17, 4) ) /*0x9a629e*/
      return 0x80000050; /*0x9a62b0*/
    return 0; /*0x9a62a2*/
  }
  v19 = *(_DWORD *)(a2 + 0x14); /*0x9a62ba*/
  if ( !byte_B4295B ) /*0x9a62bd*/
    sub_783C70(); /*0x9a62bf*/
  if ( dword_B428D8[(unsigned __int8)v19] != 6 /*0x9a630d*/
    && !sub_7833A0((_DWORD *)a2)
    && !sub_783340((_DWORD *)a2)
    && !sub_783310((_DWORD *)a2)
    && !sub_7833D0((_DWORD *)a2)
    && !sub_7832E0((_DWORD *)a2)
    && !sub_7832B0((_DWORD *)a2) )
  {
    if ( sub_782DE0((_DWORD *)a2) ) /*0x9a6318*/
    {
      if ( !(*(unsigned __int8 (__thiscall **)(int, int, int *, int))(*(_DWORD *)a1 + 0x28))(a1, a2, v17, 3) ) /*0x9a632e*/
        return 0x80000050; /*0x9a633c*/
    }
    else
    {
      sub_9A32B0((_DWORD *)a2); /*0x9a6341*/
    }
    return 0; /*0x9a6332*/
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, v17, 0) ) /*0x9a635b*/
    return 0; /*0x9a634b*/
  return 0x80000050; /*0x9a61ef*/
}
