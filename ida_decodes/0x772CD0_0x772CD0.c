// 0x772CD0 @ 0x772CD0
// Render-state group setter: inserts or updates a D3D render-state id/value pair and tracks ordering by apply bucket flag.
char __thiscall sub_772CD0(_DWORD *this, int a2, int a3, unsigned __int8 a4)
{
  _DWORD *v5; // edi
  _DWORD *v6; // eax
  bool v7; // zf
  unsigned int *v8; // ecx
  _DWORD *v9; // edi
  _DWORD **v10; // ebp
  _DWORD *v11; // ebx
  _DWORD *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  char v16; // [esp+Fh] [ebp-1h] BYREF

  v16 = 0; /*0x772ce2*/
  v5 = sub_7727D0(this, a2, &v16); /*0x772cec*/
  if ( v5 ) /*0x772cf2*/
  {
    LOBYTE(v6) = v16; /*0x772cf4*/
    v7 = v16 == (char)a4; /*0x772cf8*/
    v5[1] = a3; /*0x772d00*/
    if ( !v7 ) /*0x772d03*/
    {
      if ( (_BYTE)v6 ) /*0x772d0e*/
      {
        sub_772790(this, (int)v5); /*0x772d10*/
        v6 = (_DWORD *)*(this + 2); /*0x772d15*/
        if ( v6 ) /*0x772d1a*/
        {
          v6[3] = v5; /*0x772d1c*/
          v6 = (_DWORD *)*(this + 2); /*0x772d1f*/
          v5[2] = v6; /*0x772d22*/
        }
        v5[3] = 0; /*0x772d25*/
        ++*(this + 1); /*0x772d28*/
        *(this + 2) = v5; /*0x772d2c*/
      }
      else
      {
        sub_772750(this, (int)v5); /*0x772d36*/
        v6 = (_DWORD *)*(this + 4); /*0x772d3b*/
        if ( v6 ) /*0x772d40*/
        {
          v6[3] = v5; /*0x772d42*/
          v5[2] = *(this + 4); /*0x772d48*/
        }
        v5[3] = 0; /*0x772d4b*/
        ++*(this + 3); /*0x772d4e*/
        *(this + 4) = v5; /*0x772d52*/
      }
    }
  }
  else
  {
    v8 = (unsigned int *)dword_B427AC; /*0x772d5c*/
    v9 = (_DWORD *)(dword_B427AC + 8); /*0x772d65*/
    v10 = (_DWORD **)dword_B427AC; /*0x772d69*/
    if ( !*v9 ) /*0x772d62*/
    {
      v11 = v8 + 3; /*0x772d70*/
      sub_772A80(v8, v8[3]); /*0x772d74*/
      *v11 *= 2; /*0x772d7d*/
    }
    v12 = *v10; /*0x772d81*/
    v6 = (_DWORD *)**v10; /*0x772d84*/
    *v12 = v12[--*v9]; /*0x772d93*/
    v6[2] = 0; /*0x772d9d*/
    v6[3] = 0; /*0x772da0*/
    *v6 = a2; /*0x772da3*/
    v6[1] = a3; /*0x772da5*/
    if ( a4 ) /*0x772da9*/
    {
      v13 = *(this + 4); /*0x772dab*/
      if ( v13 ) /*0x772db0*/
      {
        *(_DWORD *)(v13 + 0xC) = v6; /*0x772db2*/
        v6[2] = *(this + 4); /*0x772db8*/
      }
      v6[3] = 0; /*0x772dbb*/
      ++*(this + 3); /*0x772dbe*/
      *(this + 4) = v6; /*0x772dc3*/
    }
    else
    {
      v14 = *(this + 2); /*0x772dcc*/
      if ( v14 ) /*0x772dd1*/
      {
        *(_DWORD *)(v14 + 0xC) = v6; /*0x772dd3*/
        v6[2] = *(this + 2); /*0x772dd9*/
      }
      v6[3] = 0; /*0x772ddc*/
      ++*(this + 1); /*0x772ddf*/
      *(this + 2) = v6; /*0x772de3*/
    }
  }
  return (char)v6; /*0x772d2f*/
}
