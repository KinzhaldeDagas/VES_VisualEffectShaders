// 0x9A8E30 @ 0x9A8E30
BOOL __thiscall sub_9A8E30(
        unsigned __int16 *this,
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
        int a12)
{
  unsigned int v14; // eax
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // eax
  int v19; // ecx
  unsigned int i; // [esp+2Ch] [ebp-8h]
  NiExtraData *ExtraData; // [esp+30h] [ebp-4h]
  char v23; // [esp+38h] [ebp+4h]
  int v24; // [esp+5Ch] [ebp+28h]

  *((_DWORD *)this + 8) = a2; /*0x9a8e3f*/
  v23 = 1; /*0x9a8e48*/
  ExtraData = NiObjectNET_GetExtraData(a3, off_B29F84); /*0x9a8e52*/
  v14 = 0; /*0x9a8e56*/
  for ( i = 0; i < *(this + 0xB); v14 = ++i ) /*0x9a8e58*/
  {
    v16 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * v14); /*0x9a8e73*/
    if ( !v16 ) /*0x9a8e78*/
      continue; /*0x9a8e78*/
    if ( !*(_BYTE *)(v16 + 8) ) /*0x9a8e82*/
      return v23 == 0; /*0x9a8e82*/
    v24 = *(_DWORD *)(v16 + 0x1C); /*0x9a8e8e*/
    if ( v24 == 0xFFFFFFFF && !*(_DWORD *)(v16 + 0x24) ) /*0x9a8e94*/
      continue; /*0x9a8e98*/
    v17 = *(_DWORD *)(v16 + 0x14) & 0xF0000000; /*0x9a8ea1*/
    switch ( v17 ) /*0x9a8ead*/
    {
      case 0x20000000u: /*0x9a8ead*/
        v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, NiObjectNET *, int, int, int, int, int, int, int, int))(*(_DWORD *)this + 0x54))( /*0x9a8eb4*/
                this,
                a2,
                v16,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11);
        break;
      case 0x10000000u: /*0x9a8ead*/
        v19 = *(_DWORD *)(v16 + 0x18); /*0x9a8ec5*/
        if ( v19 == 1 ) /*0x9a8ecb*/
        {
          v18 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD))(**((_DWORD **)this + 0xA) + 0x178))( /*0x9a8ef7*/
                  *((_DWORD *)this + 0xA),
                  v24,
                  *(_DWORD *)(v16 + 0x30),
                  *(_DWORD *)(v16 + 0x20)) < 0;
        }
        else if ( v19 == 2 ) /*0x9a8f01*/
        {
          v18 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD))(**((_DWORD **)this + 0xA) + 0x1B4))( /*0x9a8f2d*/
                  *((_DWORD *)this + 0xA),
                  v24,
                  *(_DWORD *)(v16 + 0x30),
                  *(_DWORD *)(v16 + 0x20)) < 0;
        }
        else
        {
          v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, int))(*(_DWORD *)this + 0x58))(this, a2, v16, a11); /*0x9a8f3e*/
        }
        break;
      case 0x30000000u: /*0x9a8ead*/
        v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, NiObjectNET *, int, int, int, int, int, int, int, int, int, NiExtraData *))(*(_DWORD *)this + 0x5C))( /*0x9a8f85*/
                this,
                a2,
                v16,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                a12,
                ExtraData);
        break;
      case 0x40000000u: /*0x9a8ead*/
        v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, int))(*(_DWORD *)this + 0x60))(this, a2, v16, a11); /*0x9a8f9e*/
        break;
      case 0x50000000u: /*0x9a8ead*/
        v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, NiObjectNET *, int, int, int, int, int, int))(*(_DWORD *)this + 0x64))( /*0x9a8fce*/
                this,
                a2,
                v16,
                a3,
                a4,
                a7,
                a8,
                a9,
                a10,
                a11);
        break;
      case 0x60000000u: /*0x9a8ead*/
        v18 = (*(int (__thiscall **)(unsigned __int16 *, int, int, NiObjectNET *, int, int, int, int, int, int, int, int))(*(_DWORD *)this + 0x6C))( /*0x9a9008*/
                this,
                a2,
                v16,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11);
        break;
      default:
        goto LABEL_23; /*0x9a8fd8*/
    }
    if ( v18 ) /*0x9a900c*/
LABEL_23:
      v23 = 0; /*0x9a900e*/
  }
  return v23 == 0; /*0x9a9032*/
}
