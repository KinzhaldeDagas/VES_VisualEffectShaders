// 0x007F15E0 @ 0x007F15E0
// MoonSugarEffect decode: SpeedTreeLeafShader transform slot (+0x34). Calls sub_765480 with passed NiTransform, builds inverse local matrix and leaf lighting/camera constants. Rigid transform-copy wobble reaches leaves; true leaf ripple remains shader/data owned.
int __thiscall sub_7F15E0(char **this, int a2, int a3, int a4, int a5, int a6, int a7, float *a8, int a9)
{
  _DWORD *v10; // edi
  BOOL v11; // eax
  float v13[16]; // [esp+1Ch] [ebp-80h] BYREF
  int v14[16]; // [esp+5Ch] [ebp-40h] BYREF

  sub_765480((NiDX9Renderer *)*(this + 5), a8, 0); /*0x7f15f8*/
  v13[0] = a8[0xC] * *a8; /*0x7f1609*/
  v13[1] = a8[3] * a8[0xC]; /*0x7f1618*/
  v13[2] = a8[6] * a8[0xC]; /*0x7f1622*/
  v13[4] = a8[1] * a8[0xC]; /*0x7f162c*/
  v13[5] = a8[4] * a8[0xC]; /*0x7f1636*/
  v13[6] = a8[7] * a8[0xC]; /*0x7f1640*/
  v13[8] = a8[2] * a8[0xC]; /*0x7f164a*/
  v13[9] = a8[5] * a8[0xC]; /*0x7f1654*/
  v13[0xA] = a8[8] * a8[0xC]; /*0x7f165e*/
  v13[0xC] = a8[9]; /*0x7f1665*/
  v13[0xD] = a8[0xA]; /*0x7f166c*/
  v13[0xE] = a8[0xB]; /*0x7f1673*/
  v13[3] = 0.0; /*0x7f1679*/
  v13[7] = 0.0; /*0x7f167d*/
  v13[0xB] = 0.0; /*0x7f1681*/
  v13[0xF] = 1.0; /*0x7f1687*/
  D3DXMatrixInverse_0(v14, 0, v13); /*0x7f168b*/
  v10 = *(_DWORD **)(a6 + 0x18); /*0x7f1697*/
  if ( v10 ) /*0x7f169c*/
    v11 = (*(int (__thiscall **)(_DWORD))(*v10 + 0x54))(*(_DWORD *)(a6 + 0x18)) == 9; /*0x7f16b3*/
  else
    v11 = 0; /*0x7f169e*/
  sub_7F0100(v11 ? v10 : 0, (int)v14, a8[0xC]);
  sub_7F1170(); /*0x7f16cf*/
  return 0; /*0x7f16d4*/
}
