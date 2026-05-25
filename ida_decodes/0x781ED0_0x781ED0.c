// 0x781ED0 @ 0x781ED0
NiD3DShaderProgram *__thiscall sub_781ED0(void *this, int a2, int a3, const char *ArgList, int a5, int a6)
{
  NiD3DShaderProgram *v7; // esi
  unsigned __int8 (__thiscall *v8)(void *, int, int, int *, int *, int *, int *); // edx
  int v10; // ebx
  int v11; // [esp+20h] [ebp-10h] BYREF
  int v12; // [esp+24h] [ebp-Ch] BYREF
  int v13; // [esp+28h] [ebp-8h] BYREF
  int v14; // [esp+2Ch] [ebp-4h] BYREF

  v7 = (NiD3DShaderProgram *)FormHeapAlloc(0x2Cu); /*0x781edf*/
  if ( !v7 ) /*0x781ee8*/
    return 0; /*0x781ee8*/
  NiD3DShaderProgram::NiD3DShaderProgram(v7, dword_B428C4); /*0x781ef2*/
  *(_DWORD *)v7 = &NiD3DPixelShader::`vftable'; /*0x781f0a*/
  *((_DWORD *)v7 + 0xA) = 0; /*0x781f10*/
  v8 = *(unsigned __int8 (__thiscall **)(void *, int, int, int *, int *, int *, int *))(*(_DWORD *)this + 0x28); /*0x781f15*/
  v12 = 0; /*0x781f25*/
  v11 = 0; /*0x781f29*/
  v13 = 0; /*0x781f2d*/
  v14 = 0; /*0x781f31*/
  if ( !v8(this, a2, a3, &v11, &v12, &v14, &v13) ) /*0x781f35*/
  {
    (**(void (__thiscall ***)(NiD3DShaderProgram *, int))v7)(v7, 1); /*0x781f43*/
    return 0; /*0x781f4d*/
  }
  v10 = sub_783C30(v11); /*0x781f5d*/
  if ( v10 ) /*0x781f61*/
  {
    (*(void (__thiscall **)(NiD3DShaderProgram *, const char *))(*(_DWORD *)v7 + 8))(v7, ArgList); /*0x781f9a*/
    (*(void (__thiscall **)(NiD3DShaderProgram *, _DWORD))(*(_DWORD *)v7 + 0x10))(v7, 0); /*0x781fa4*/
    (*(void (__thiscall **)(NiD3DShaderProgram *, int, int))(*(_DWORD *)v7 + 0x1C))(v7, v12, v11); /*0x781fb7*/
    (*(void (__thiscall **)(NiD3DShaderProgram *, void *))(*(_DWORD *)v7 + 0x24))(v7, this); /*0x781fc1*/
    (*(void (__thiscall **)(NiD3DShaderProgram *, int))(*(_DWORD *)v7 + 0x3C))(v7, v10); /*0x781fcb*/
    return v7; /*0x781fcf*/
  }
  else
  {
    sub_738460(1, 0, "Failed CreatePixelShader call on %s\n", ArgList); /*0x781f70*/
    (**(void (__thiscall ***)(NiD3DShaderProgram *, int))v7)(v7, 1); /*0x781f80*/
    return 0; /*0x781f85*/
  }
}
