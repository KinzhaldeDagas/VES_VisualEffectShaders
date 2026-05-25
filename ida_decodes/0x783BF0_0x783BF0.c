// 0x783BF0 @ 0x783BF0
// MoonSugarEffect decode: helper creates IDirect3DVertexShader9 from bytecode using global D3D device dword_B428C0 vtable +0x16C. Extra args are ignored by this helper; output handle is returned through the first stack slot.
int __stdcall sub_783BF0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // eax

  v6 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)dword_B428C0 + 0x16C))(dword_B428C0, a1, &a1); /*0x783c08*/
  if ( v6 >= 0 ) /*0x783c0c*/
    return a1; /*0x783c25*/
  sub_738460(1, 0, "Failed to create vertex shader\nError 0x%08x\n", v6); /*0x783c18*/
  return 0; /*0x783c22*/
}
