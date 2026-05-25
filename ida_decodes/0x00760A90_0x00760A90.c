// 0x00760A90 @ 0x00760A90
char __thiscall sub_7609C0(_DWORD *this, int a2)
{
  int v2; // esi
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  int v7; // edx
  D3DFORMAT v8; // eax
  bool v9; // zf
  int v11; // ecx
  D3DFORMAT v12; // eax
  NiSurfaceData *inited; // eax
  int v14; // eax
  int v15; // edx
  D3DFORMAT v16; // eax
  D3DFORMAT v17; // [esp-4h] [ebp-7Ch]
  D3DFORMAT a1[4]; // [esp+14h] [ebp-64h] BYREF
  int v19; // [esp+24h] [ebp-54h]
  int v20; // [esp+28h] [ebp-50h]
  int v21; // [esp+2Ch] [ebp-4Ch]
  int v22; // [esp+30h] [ebp-48h]
  NiSurfaceData v23; // [esp+34h] [ebp-44h] BYREF

  v2 = a2; /*0x7609c6*/
  v4 = (*(int (__stdcall **)(int))(*(_DWORD *)a2 + 0x34))(a2); /*0x7609d3*/
  v5 = 0; /*0x7609db*/
  *(this + 0x17) = v4; /*0x7609dd*/
  *((_BYTE *)this + 0x65) = v4 != 1; /*0x7609e0*/
  *(this + 0x1A) = 0; /*0x7609e3*/
  v6 = (*(int (__stdcall **)(int))(*(_DWORD *)v2 + 0x28))(v2); /*0x7609ec*/
  if ( v6 == 3 ) /*0x7609f1*/
  {
    if ( *(this + 0x17) ) /*0x7609f7*/
    {
      while ( (*(int (__stdcall **)(int, int, D3DFORMAT *))(*(_DWORD *)v2 + 0x44))(v2, v5, a1) >= 0 ) /*0x760a10*/
      {
        if ( !v5 ) /*0x760a14*/
        {
          v7 = v21; /*0x760a1a*/
          *(this + 0x16) = v22; /*0x760a1e*/
          v8 = a1[0]; /*0x760a21*/
          v9 = a1[0] == D3DFMT_A8P8; /*0x760a25*/
          *(this + 0x15) = v7; /*0x760a28*/
          if ( v9 || v8 == D3DFMT_P8 ) /*0x760a30*/
            return 0; /*0x760a30*/
          qmemcpy(this + 3, InitSurfacEData(&v23), 0x44u); /*0x760a47*/
          D3DFMTToTextureFormat(a1[0], (NiSurfaceData *)(this + 3)); /*0x760a4f*/
          v2 = a2; /*0x760a54*/
        }
        *(this + 0x1A) += (v21 * v22 * (unsigned int)*((unsigned __int8 *)this + 0xD)) >> 3; /*0x760a6f*/
        if ( (unsigned int)++v5 >= *(this + 0x17) ) /*0x760a78*/
        {
          *(this + 0x14) = v2; /*0x760a7b*/
          return 1; /*0x760a86*/
        }
      }
      return 0; /*0x760a92*/
    }
    goto LABEL_28; /*0x7609fa*/
  }
  if ( v6 != 5 ) /*0x760a98*/
  {
    if ( v6 == 4 && *(this + 0x17) ) /*0x760b44*/
    {
      while ( (*(int (__stdcall **)(int, int, D3DFORMAT *))(*(_DWORD *)v2 + 0x44))(v2, v5, a1) >= 0 ) /*0x760b60*/
      {
        if ( !v5 ) /*0x760b68*/
        {
          v15 = v19; /*0x760b6e*/
          *(this + 0x16) = v20; /*0x760b72*/
          v16 = a1[0]; /*0x760b75*/
          v9 = a1[0] == D3DFMT_A8P8; /*0x760b79*/
          *(this + 0x15) = v15; /*0x760b7c*/
          if ( v9 || v16 == D3DFMT_P8 ) /*0x760b88*/
            return 0; /*0x760b88*/
          qmemcpy(this + 3, InitSurfacEData(&v23), 0x44u); /*0x760ba3*/
          D3DFMTToTextureFormat(a1[0], (NiSurfaceData *)(this + 3)); /*0x760bab*/
          v2 = a2; /*0x760bb0*/
        }
        *(this + 0x1A) += (v19 * v20 * v21 * (unsigned int)*((unsigned __int8 *)this + 0xD)) >> 3; /*0x760bd0*/
        if ( (unsigned int)++v5 >= *(this + 0x17) ) /*0x760bd9*/
          goto LABEL_28; /*0x760bd9*/
      }
      return 0; /*0x760b60*/
    }
LABEL_28:
    *(this + 0x14) = v2; /*0x760bdf*/
    return 1; /*0x760be5*/
  }
  if ( *(this + 0x17) ) /*0x760a9e*/
  {
    while ( (*(int (__stdcall **)(int, int, D3DFORMAT *))(*(_DWORD *)v2 + 0x44))(v2, v5, a1) >= 0 ) /*0x760ab7*/
    {
      if ( !v5 ) /*0x760abb*/
      {
        v11 = v22; /*0x760ac1*/
        *(this + 0x15) = v21; /*0x760ac5*/
        v12 = a1[0]; /*0x760ac8*/
        v9 = a1[0] == D3DFMT_A8P8; /*0x760acc*/
        *(this + 0x16) = v11; /*0x760acf*/
        if ( v9 || v12 == D3DFMT_P8 ) /*0x760ad7*/
          return 0; /*0x760ad7*/
        inited = InitSurfacEData(&v23); /*0x760add*/
        v17 = a1[0]; /*0x760af3*/
        qmemcpy(this + 3, inited, 0x44u); /*0x760af4*/
        D3DFMTToTextureFormat(v17, (NiSurfaceData *)(this + 3)); /*0x760af6*/
        v2 = a2; /*0x760afb*/
      }
      *(this + 0x1A) += (v21 * v22 * (unsigned int)*((unsigned __int8 *)this + 0xD)) >> 3; /*0x760b16*/
      if ( (unsigned int)++v5 >= *(this + 0x17) ) /*0x760b1f*/
        goto LABEL_19; /*0x760b1f*/
    }
    return 0; /*0x760ab7*/
  }
LABEL_19:
  v14 = *(this + 0x1A); /*0x760b21*/
  *(this + 0x14) = v2; /*0x760b28*/
  *(this + 0x1A) = 6 * v14; /*0x760b2f*/
  return 1; /*0x760a7a*/
}
