// 0x7814C0 @ 0x7814C0
// MoonSugarEffect decode: HLSL vertex creator path. Builds 0x44 NiD3DHLSLVertexShader, stores source/profile/blob metadata and creator pointer, then creates the D3D vertex shader through sub_783BF0. Creator-backed wrappers can restore through sub_77EB10.
int __thiscall sub_7814C0(
        _DWORD *this,
        char *a2,
        const char *ArgList,
        const char *a4,
        char *a5,
        int a6,
        int a7,
        int a8)
{
  int v9; // esi
  int v11; // ebx
  int v12; // edi
  int v13; // [esp+2Ch] [ebp-Ch] BYREF
  int v14; // [esp+30h] [ebp-8h] BYREF
  int v15; // [esp+34h] [ebp-4h] BYREF

  v9 = FormHeapAlloc(0x44u); /*0x7814cf*/
  if ( !v9 ) /*0x7814d8*/
    return 0; /*0x7814d8*/
  NiD3DShaderProgram::NiD3DShaderProgram((NiD3DShaderProgram *)v9, dword_B428C4); /*0x7814e6*/
  *(_BYTE *)(v9 + 0x28) = 0; /*0x7814ef*/
  *(_DWORD *)(v9 + 0x2C) = 0; /*0x7814f3*/
  *(_DWORD *)(v9 + 0x30) = 0; /*0x7814f6*/
  *(_DWORD *)(v9 + 0x34) = 0; /*0x7814f9*/
  *(_DWORD *)v9 = &NiD3DHLSLVertexShader::`vftable'; /*0x7814fc*/
  *(_DWORD *)(v9 + 0x38) = 0; /*0x781502*/
  *(_DWORD *)(v9 + 0x3C) = 0; /*0x781505*/
  *(_DWORD *)(v9 + 0x40) = 0; /*0x781508*/
  v15 = 0; /*0x78150b*/
  v13 = 0; /*0x78150f*/
  v14 = 0; /*0x781513*/
  if ( !a4 ) /*0x781517*/
    a4 = "main"; /*0x781519*/
  if ( !a5 ) /*0x781525*/
    a5 = (char *)D3DXGetVertexShaderProfile_0(dword_B428C0); /*0x781533*/
  if ( !sub_781170(this, a2, a4, a5, (void **)&v13, (size_t *)&v15, (int)&v14) ) /*0x781557*/
  {
    (**(void (__thiscall ***)(int, int))v9)(v9, 1); /*0x781568*/
    return 0; /*0x781572*/
  }
  v11 = a8; /*0x78157e*/
  v12 = sub_783BF0(v13, (int)&a6, a7, 0, 0, a8); /*0x781593*/
  if ( v12 ) /*0x781597*/
  {
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 8))(v9, ArgList); /*0x7815d0*/
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v9 + 0x10))(v9, a2); /*0x7815de*/
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v9 + 0x1C))(v9, v15, v13); /*0x7815f1*/
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v9 + 0x24))(v9, this); /*0x7815fb*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 0x44))(v9, v12); /*0x781605*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 0x3C))(v9, a7); /*0x781613*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 0x54))(v9, v11); /*0x78161d*/
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 0x64))(v9, a4); /*0x78162b*/
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v9 + 0x6C))(v9, a5); /*0x781639*/
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 0x74))(v9, v14); /*0x781647*/
    if ( v14 ) /*0x78164f*/
      (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(v14); /*0x781657*/
    return v9; /*0x78165b*/
  }
  else
  {
    sub_738460(1, 0, "Failed CreateVertexShader call on %s\n", ArgList); /*0x7815a6*/
    (**(void (__thiscall ***)(int, int))v9)(v9, 1); /*0x7815b6*/
    return 0; /*0x7815bb*/
  }
}
