// 0x781C60 @ 0x781C60
int __thiscall sub_781C60(void *this, int a2, int a3, const char *ArgList, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // esi
  unsigned __int8 (__thiscall *v11)(void *, int, int, int *, int *, int *, int *); // edx
  int v13; // ebx
  int v14; // ebp
  int v15; // [esp+20h] [ebp-10h] BYREF
  int v16; // [esp+24h] [ebp-Ch] BYREF
  int v17; // [esp+28h] [ebp-8h] BYREF
  int v18; // [esp+2Ch] [ebp-4h] BYREF

  v10 = FormHeapAlloc(0x38u); /*0x781c6f*/
  if ( !v10 ) /*0x781c78*/
    return 0; /*0x781c78*/
  NiD3DShaderProgram::NiD3DShaderProgram((NiD3DShaderProgram *)v10, dword_B428C4); /*0x781c82*/
  *(_DWORD *)v10 = &NiD3DVertexShader::`vftable'; /*0x781c9a*/
  *(_BYTE *)(v10 + 0x28) = 0; /*0x781ca0*/
  *(_DWORD *)(v10 + 0x2C) = 0; /*0x781ca3*/
  *(_DWORD *)(v10 + 0x30) = 0; /*0x781ca6*/
  *(_DWORD *)(v10 + 0x34) = 0; /*0x781ca9*/
  v11 = *(unsigned __int8 (__thiscall **)(void *, int, int, int *, int *, int *, int *))(*(_DWORD *)this + 0x28); /*0x781cae*/
  v18 = 0; /*0x781cbe*/
  v15 = 0; /*0x781cc2*/
  v16 = 0; /*0x781cc6*/
  v17 = 0; /*0x781cca*/
  if ( !v11(this, a2, a3, &v15, &v18, &v17, &v16) ) /*0x781cce*/
  {
    (**(void (__thiscall ***)(int, int))v10)(v10, 1); /*0x781cdc*/
    return 0; /*0x781ce6*/
  }
  v13 = a9; /*0x781ce9*/
  v14 = sub_783BF0(v15, (int)&a7, a8, v17, v16, a9); /*0x781d0f*/
  if ( v14 ) /*0x781d13*/
  {
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 8))(v10, ArgList); /*0x781d4c*/
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 0x10))(v10, 0); /*0x781d57*/
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 0x1C))(v10, v18, v15); /*0x781d6a*/
    (*(void (__thiscall **)(int, void *))(*(_DWORD *)v10 + 0x24))(v10, this); /*0x781d74*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 0x44))(v10, v14); /*0x781d7e*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 0x3C))(v10, a8); /*0x781d8c*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 0x4C))(v10, a7); /*0x781d9a*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 0x54))(v10, v13); /*0x781da4*/
    return v10; /*0x781da8*/
  }
  else
  {
    sub_738460(1, 0, "Failed CreateVertexShader call on %s\n", ArgList); /*0x781d22*/
    (**(void (__thiscall ***)(int, int))v10)(v10, 1); /*0x781d32*/
    return 0; /*0x781d37*/
  }
}
