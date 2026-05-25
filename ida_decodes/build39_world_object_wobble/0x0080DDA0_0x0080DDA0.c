// 0x0080DDA0 @ 0x0080DDA0
// SpeedTreeFrondShader pre-render transform. Builds inverse scaled local transform, converts global directional and point light into object space, stores point-light block at +0x98..+0xA4 and directional-light block at +0xA8..+0xB4.
int __thiscall sub_80DDA0(char **this, int a2, int a3, int a4, int a5, int a6, int a7, float *a8, int a9)
{
  float v11; // edx
  float v12; // eax
  double v13; // st7
  double v14; // st7
  float v16; // [esp+30h] [ebp-BCh]
  float v17; // [esp+34h] [ebp-B8h]
  float v18; // [esp+3Ch] [ebp-B0h] BYREF
  float v19; // [esp+40h] [ebp-ACh]
  float v20; // [esp+44h] [ebp-A8h]
  float v21[3]; // [esp+48h] [ebp-A4h] BYREF
  float v22[3]; // [esp+54h] [ebp-98h] BYREF
  float v23[16]; // [esp+60h] [ebp-8Ch] BYREF
  _BYTE v24[12]; // [esp+A0h] [ebp-4Ch] BYREF
  _BYTE v25[64]; // [esp+ACh] [ebp-40h] BYREF

  sub_765480((NiDX9Renderer *)*(this + 5), a8, 0); /*0x80ddb7*/
  v23[0] = a8[0xC] * *a8; /*0x80ddc8*/
  v23[1] = a8[3] * a8[0xC]; /*0x80ddda*/
  v23[2] = a8[6] * a8[0xC]; /*0x80dde4*/
  v23[4] = a8[1] * a8[0xC]; /*0x80ddee*/
  v23[5] = a8[4] * a8[0xC]; /*0x80ddf8*/
  v23[6] = a8[7] * a8[0xC]; /*0x80de02*/
  v23[8] = a8[2] * a8[0xC]; /*0x80de0c*/
  v23[9] = a8[5] * a8[0xC]; /*0x80de16*/
  v23[0xA] = a8[8] * a8[0xC]; /*0x80de20*/
  v23[0xC] = a8[9]; /*0x80de27*/
  v23[0xD] = a8[0xA]; /*0x80de2e*/
  v23[0xE] = a8[0xB]; /*0x80de35*/
  v23[3] = 0.0; /*0x80de3e*/
  v23[7] = 0.0; /*0x80de42*/
  v23[0xB] = 0.0; /*0x80de46*/
  v23[0xF] = 1.0; /*0x80de4c*/
  D3DXMatrixInverse_0(v25, 0, v23); /*0x80de53*/
  v18 = -flt_B465A8; /*0x80de67*/
  v19 = -flt_B465AC; /*0x80de79*/
  v20 = -flt_B465B0; /*0x80de8d*/
  D3DXVec3TransformNormal_0(v24, &v18, v25); /*0x80de91*/
  D3DXVec3Normalize_0(&v18, v24); /*0x80dea0*/
  v11 = v19; /*0x80dec7*/
  v12 = v20; /*0x80decb*/
  *((float *)this + 0x2A) = v18; /*0x80decf*/
  *((float *)this + 0x2B) = v11; /*0x80ded9*/
  *((float *)this + 0x2C) = v12; /*0x80dedf*/
  *((float *)this + 0x2D) = 0.0; /*0x80dee5*/
  v22[0] = flt_B46528; /*0x80def1*/
  v22[1] = flt_B4652C; /*0x80df07*/
  v22[2] = flt_B46530; /*0x80df16*/
  D3DXVec3TransformCoord_0(v21, v22, v25); /*0x80df1b*/
  v13 = v21[1]; /*0x80df2c*/
  *(this + 0x26) = (char *)LODWORD(v21[0]); /*0x80df30*/
  v16 = v13; /*0x80df36*/
  v14 = v21[2]; /*0x80df3e*/
  *((float *)this + 0x27) = v16; /*0x80df42*/
  v17 = v14; /*0x80df48*/
  *((float *)this + 0x28) = v17; /*0x80df52*/
  *((float *)this + 0x29) = 1.0; /*0x80df62*/
  return 0; /*0x80df68*/
}
