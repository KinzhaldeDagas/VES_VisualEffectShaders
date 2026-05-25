// 0x771150 @ 0x771150
// MoonSugarEffect decode: builds cached D3DVERTEXELEMENT9 array from enabled stream elements, computes per-stream stride, appends D3DDECL_END, and calls IDirect3DDevice9::CreateVertexDeclaration.
int __thiscall sub_771150(int this)
{
  int result; // eax
  int v3; // edi
  unsigned int v4; // ebp
  unsigned int v5; // ebx
  int v6; // edx
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  unsigned int v9; // edx
  bool v10; // zf
  int v11; // ebx
  int v12; // ecx
  unsigned int v13; // ebp
  _DWORD *v14; // eax
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h]

  result = *(_DWORD *)(this + 0x30); /*0x771157*/
  v3 = 0; /*0x77115b*/
  v4 = 0; /*0x77115d*/
  if ( *(_BYTE *)(this + 0x28) )
  {
    if ( result ) /*0x77116b*/
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)result + 8))(result); /*0x771173*/
      *(_DWORD *)(this + 0x30) = 0; /*0x771175*/
    }
    v5 = 0; /*0x771179*/
    if ( *(_DWORD *)(this + 0x20) ) /*0x77117b*/
    {
      do /*0x7711bc*/
      {
        v6 = v3 + *(_DWORD *)(this + 0x24); /*0x771183*/
        if ( v6 ) /*0x771185*/
        {
          v7 = 0; /*0x771187*/
          *(_BYTE *)v6 = 0; /*0x771189*/
          if ( *(_DWORD *)(this + 0x1C) ) /*0x77118c*/
          {
            v8 = (_DWORD *)(*(_DWORD *)(v6 + 8) + 0xC); /*0x771194*/
            do /*0x7711b1*/
            {
              if ( v8[0xFFFFFFFF] != 0xFFFFFFFF && *v8 != 0x11 ) /*0x7711a0*/
              {
                ++v4; /*0x7711a2*/
                *(_BYTE *)v6 = 1; /*0x7711a5*/
              }
              ++v7; /*0x7711a8*/
              v8 += 7; /*0x7711ab*/
            }
            while ( v7 < *(_DWORD *)(this + 0x1C) ); /*0x7711b1*/
          }
        }
        ++v5; /*0x7711b3*/
        v3 += 0x10; /*0x7711b6*/
      }
      while ( v5 < *(_DWORD *)(this + 0x20) ); /*0x7711bc*/
      if ( v4 ) /*0x7711c0*/
        ++v4; /*0x7711c2*/
      v3 = 0; /*0x7711c5*/
    }
    if ( *(_DWORD *)(this + 0x14) < v4 ) /*0x7711ca*/
    {
      FormHeapFree(*(_DWORD *)(this + 0x2C)); /*0x7711d0*/
      *(_DWORD *)(this + 0x2C) = 0; /*0x7711d8*/
    }
    if ( !v4 ) /*0x7711dd*/
    {
      *(_DWORD *)(this + 0x14) = 0; /*0x7711df*/
      return 0; /*0x7711eb*/
    }
    if ( !*(_DWORD *)(this + 0x2C) )
    {
      *(_DWORD *)(this + 0x14) = v4; /*0x7711ff*/
      *(_DWORD *)(this + 0x2C) = FormHeapAlloc((unsigned __int64)v4 >> 0x1D != 0 ? 0xFFFFFFFF : 8 * v4);
    }
    v9 = 0; /*0x771212*/
    v10 = *(_DWORD *)(this + 0x20) == 0; /*0x771214*/
    *(_DWORD *)(this + 0x18) = 0; /*0x771217*/
    v17 = 0; /*0x77121a*/
    if ( !v10 ) /*0x77121e*/
    {
      v16 = 0; /*0x771220*/
      do /*0x771288*/
      {
        v11 = v16 + *(_DWORD *)(this + 0x24); /*0x771227*/
        if ( *(_BYTE *)v11 ) /*0x77122b*/
        {
          v12 = 0; /*0x771230*/
          v13 = 0; /*0x771232*/
          v15 = 0; /*0x771237*/
          if ( *(_DWORD *)(this + 0x1C) ) /*0x771234*/
          {
            do /*0x771272*/
            {
              v14 = (_DWORD *)(v3 + *(_DWORD *)(v11 + 8)); /*0x771243*/
              if ( v14[2] != 0xFFFFFFFF && v14[3] != 0x11 ) /*0x77124f*/
              {
                v14[1] = v12; /*0x771252*/
                v15 += sub_770150((_DWORD *)this, (int)v14, v9); /*0x77125d*/
                v12 = v15; /*0x771261*/
                v9 = v17; /*0x771265*/
              }
              ++v13; /*0x771269*/
              v3 += 0x1C; /*0x77126c*/
            }
            while ( v13 < *(_DWORD *)(this + 0x1C) ); /*0x771272*/
            v3 = 0; /*0x771274*/
          }
          *(_DWORD *)(v11 + 0xC) = v12; /*0x771276*/
        }
        v16 += 0x10; /*0x771279*/
        v17 = ++v9; /*0x771284*/
      }
      while ( v9 < *(_DWORD *)(this + 0x20) ); /*0x771288*/
    }
    *(_WORD *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18)) = 0xFF; /*0x771290*/
    *(_WORD *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18) + 2) = 0; /*0x77129c*/
    *(_BYTE *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18) + 4) = 0x11; /*0x7712a7*/
    *(_BYTE *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18) + 5) = 0; /*0x7712b2*/
    *(_BYTE *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18) + 6) = 0; /*0x7712bd*/
    *(_BYTE *)(*(_DWORD *)(this + 0x2C) + 8 * *(_DWORD *)(this + 0x18) + 7) = 0; /*0x7712c8*/
    if ( (*(int (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(this + 0x10) + 0x158))( /*0x7712e5*/
           *(_DWORD *)(this + 0x10),
           *(_DWORD *)(this + 0x2C),
           this + 0x30) < 0 )
      return 0; /*0x7712e5*/
    result = *(_DWORD *)(this + 0x30); /*0x7712eb*/
    *(_BYTE *)(this + 0x28) = 0; /*0x7712ed*/
  }
  return result; /*0x7711e3*/
}
