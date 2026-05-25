// 0x00783100 @ 0x00783100
// MoonSugarEffect decode: NiD3DVertexShader constant setter. Uses entry type to call D3D SetVertexShaderConstantF/I/B via device vtable slots 0x178/0x180/0x188.
bool __thiscall sub_7830C0(_DWORD *this, _DWORD *a2, int a3, signed int a4)
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

  v4 = a3; /*0x7830c1*/
  if ( !a3 ) /*0x7830d0*/
    v4 = a2[0xC]; /*0x7830d2*/
  v6 = a4; /*0x7830d5*/
  if ( !a4 ) /*0x7830db*/
  {
    v6 = a2[8]; /*0x7830dd*/
    if ( !v6 ) /*0x7830e2*/
      v6 = 1; /*0x7830e4*/
  }
  v7 = a2[5]; /*0x7830f0*/
  v14 = v7; /*0x7830f3*/
  if ( !byte_B4295B ) /*0x7830e9*/
  {
    sub_783C70(); /*0x7830f9*/
    LOBYTE(v7) = v14; /*0x7830fe*/
  }
  v8 = *(this + 9); /*0x783105*/
  v9 = *(_DWORD *)(4 * (unsigned __int8)v7 + 0xB428D8); /*0x78310d*/
  v13 = a2[7]; /*0x783119*/
  if ( v9 == 1 ) /*0x78311a*/
    return (*(int (__stdcall **)(_DWORD, int, int, signed int))(**(_DWORD **)(v8 + 0xFF8) + 0x188))( /*0x783137*/
             *(_DWORD *)(v8 + 0xFF8),
             v13,
             v4,
             v6) >= 0;
  v11 = **(_DWORD **)(v8 + 0xFF8); /*0x783146*/
  v12 = *(_DWORD *)(v8 + 0xFF8); /*0x783148*/
  if ( v9 == 3 ) /*0x783149*/
    return (*(int (__stdcall **)(int, int, int, signed int))(v11 + 0x180))(v12, v13, v4, v6) >= 0; /*0x78315d*/
  else
    return (*(int (__stdcall **)(int, int, int, signed int))(v11 + 0x178))(v12, v13, v4, v6) >= 0; /*0x783175*/
}
