// 0x782E70 @ 0x782E70
// MoonSugarEffect decode: NiD3DPixelShader constant setter. Uses entry type to call D3D SetPixelShaderConstantF/I/B via device vtable slots 0x1B4/0x1BC/0x1C4.
bool __thiscall sub_782E70(_DWORD *this, _DWORD *a2, int a3, signed int a4)
{
  int v4; // ebx
  signed int v6; // esi
  int v7; // eax
  int v8; // ebp
  int v9; // eax
  int v11; // edx
  int v12; // [esp-10h] [ebp-20h]
  int v13; // [esp-Ch] [ebp-1Ch]
  char v14; // [esp+18h] [ebp+8h]

  v4 = a3; /*0x782e71*/
  if ( !a3 ) /*0x782e80*/
    v4 = a2[0xC]; /*0x782e82*/
  v6 = a4; /*0x782e85*/
  if ( !a4 ) /*0x782e8b*/
  {
    v6 = a2[8]; /*0x782e8d*/
    if ( !v6 ) /*0x782e92*/
      v6 = 1; /*0x782e94*/
  }
  v7 = a2[5]; /*0x782ea0*/
  v14 = v7; /*0x782ea3*/
  if ( !byte_B4295B ) /*0x782e99*/
  {
    sub_783C70(); /*0x782ea9*/
    LOBYTE(v7) = v14; /*0x782eae*/
  }
  v8 = *(this + 9); /*0x782eb5*/
  v9 = *(_DWORD *)(4 * (unsigned __int8)v7 + 0xB428D8); /*0x782ebd*/
  v13 = a2[7]; /*0x782ec9*/
  if ( v9 == 1 ) /*0x782eca*/
    return (*(int (__stdcall **)(_DWORD, int, int, signed int))(**(_DWORD **)(v8 + 0xFF8) + 0x1C4))( /*0x782ee7*/
             *(_DWORD *)(v8 + 0xFF8),
             v13,
             v4,
             v6) >= 0;
  v11 = **(_DWORD **)(v8 + 0xFF8); /*0x782ef6*/
  v12 = *(_DWORD *)(v8 + 0xFF8); /*0x782ef8*/
  if ( v9 == 3 ) /*0x782ef9*/
    return (*(int (__stdcall **)(int, int, int, signed int))(v11 + 0x1BC))(v12, v13, v4, v6) >= 0; /*0x782f0d*/
  else
    return (*(int (__stdcall **)(int, int, int, signed int))(v11 + 0x1B4))(v12, v13, v4, v6) >= 0; /*0x782f25*/
}
