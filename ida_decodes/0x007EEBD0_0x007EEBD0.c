// 0x007EEBD0 @ 0x007EEBD0
int __thiscall sub_7EEBD0(char **this, int a2, int a3, int a4, int a5, int a6, int a7, float *a8, int a9)
{
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  double v14; // st7
  float *v15; // eax
  double v16; // st7
  int v17; // eax
  int v18; // ecx
  int v19; // esi
  BOOL v20; // eax
  int v21; // eax
  int ShadowSceneNode; // eax
  _DWORD *v23; // esi
  void (__thiscall ***v24)(_DWORD, int); // edi
  int v26; // [esp+Ch] [ebp-94h] BYREF
  int v27; // [esp+10h] [ebp-90h]
  int v28; // [esp+14h] [ebp-8Ch]
  float v29; // [esp+18h] [ebp-88h] BYREF
  float v30; // [esp+1Ch] [ebp-84h]
  float v31; // [esp+20h] [ebp-80h]
  int v32; // [esp+24h] [ebp-7Ch]
  int v33; // [esp+28h] [ebp-78h] BYREF
  float v34; // [esp+2Ch] [ebp-74h] BYREF
  float v35; // [esp+30h] [ebp-70h]
  float v36; // [esp+34h] [ebp-6Ch]
  float v37; // [esp+38h] [ebp-68h]
  float v38; // [esp+3Ch] [ebp-64h]
  float v39; // [esp+40h] [ebp-60h]
  float v40; // [esp+44h] [ebp-5Ch]
  float v41; // [esp+48h] [ebp-58h]
  float v42; // [esp+4Ch] [ebp-54h]
  float v43; // [esp+50h] [ebp-50h]
  float v44; // [esp+54h] [ebp-4Ch]
  float v45; // [esp+58h] [ebp-48h]
  float x; // [esp+5Ch] [ebp-44h]
  float y; // [esp+60h] [ebp-40h]
  float z; // [esp+64h] [ebp-3Ch]
  float v49; // [esp+68h] [ebp-38h]
  NiTransform v50; // [esp+6Ch] [ebp-34h] BYREF

  sub_765480((NiDX9Renderer *)*(this + 5), a8, 0); /*0x7eebe7*/
  z = 0.0; /*0x7eebee*/
  y = 0.0; /*0x7eebf6*/
  x = 0.0; /*0x7eebfb*/
  v45 = 0.0; /*0x7eec01*/
  v43 = 0.0; /*0x7eec05*/
  v42 = 0.0; /*0x7eec09*/
  v41 = 0.0; /*0x7eec0d*/
  v40 = 0.0; /*0x7eec11*/
  v38 = 0.0; /*0x7eec15*/
  v37 = 0.0; /*0x7eec19*/
  v36 = 0.0; /*0x7eec1d*/
  v35 = 0.0; /*0x7eec21*/
  v49 = 1.0; /*0x7eec27*/
  v44 = 1.0; /*0x7eec2b*/
  v39 = 1.0; /*0x7eec2f*/
  v34 = 1.0; /*0x7eec33*/
  sub_718A80(a8, &v50); /*0x7eec37*/
  v10 = dword_B4665C; /*0x7eec4f*/
  v11 = dword_B46660; /*0x7eec57*/
  v29 = *(float *)&dword_B46658; /*0x7eec5e*/
  v12 = dword_B46664; /*0x7eec62*/
  v30 = *(float *)&v10; /*0x7eec68*/
  v34 = v50.rot.data[0][0] * v50.scale; /*0x7eec6c*/
  v31 = *(float *)&v11; /*0x7eec70*/
  v32 = v12; /*0x7eec78*/
  v35 = v50.rot.data[1][0] * v50.scale; /*0x7eec7e*/
  v36 = v50.rot.data[2][0] * v50.scale; /*0x7eec8b*/
  v38 = v50.rot.data[0][1] * v50.scale; /*0x7eec95*/
  v39 = v50.rot.data[1][1] * v50.scale; /*0x7eec9f*/
  v40 = v50.rot.data[2][1] * v50.scale; /*0x7eecac*/
  v42 = v50.rot.data[0][2] * v50.scale; /*0x7eecb6*/
  v43 = v50.rot.data[1][2] * v50.scale; /*0x7eecc0*/
  v44 = v50.scale * v50.rot.data[2][2]; /*0x7eeccb*/
  x = v50.pos.x; /*0x7eecd6*/
  y = v50.pos.y; /*0x7eece1*/
  z = v50.pos.z; /*0x7eecec*/
  v49 = 1.0; /*0x7eecf2*/
  *(float *)&v26 = v29; /*0x7eecfa*/
  v27 = v10; /*0x7eed02*/
  v28 = v11; /*0x7eed0a*/
  D3DXVec3TransformCoord_0(&v29, &v26, &v34); /*0x7eed1d*/
  *(float *)&v26 = v29; /*0x7eed26*/
  v13 = v30; /*0x7eed2e*/
  *(float *)&dword_B46710 = v29; /*0x7eed32*/
  *(float *)&v27 = v13; /*0x7eed38*/
  v14 = v31; /*0x7eed40*/
  dword_B46714 = v27; /*0x7eed44*/
  v15 = (float *)dword_B43124; /*0x7eed49*/
  *(float *)&v28 = v14; /*0x7eed4e*/
  dword_B46718 = v28; /*0x7eed56*/
  v26 = *((int *)v15 + 0x1A); /*0x7eed5f*/
  v27 = *((int *)v15 + 0x1D); /*0x7eed6a*/
  v16 = v15[0x20]; /*0x7eed6e*/
  v17 = v27; /*0x7eed74*/
  *(float *)&v28 = v16; /*0x7eed78*/
  v18 = v28; /*0x7eed7c*/
  dword_B466F8 = v26; /*0x7eed80*/
  dword_B466FC = v17; /*0x7eed8d*/
  dword_B46700 = v18; /*0x7eed92*/
  v19 = *(_DWORD *)(a6 + 0x18); /*0x7eed98*/
  if ( v19 ) /*0x7eed9d*/
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 0x54))(v19) == 0xF; /*0x7eedb4*/
  else
    v20 = 0; /*0x7eed9f*/
  v21 = v20 ? v19 : 0;
  if ( v21 ) /*0x7eedbc*/
  {
    ShadowSceneNode = GetShadowSceneNode(*(_DWORD *)(v21 + 0x1C) >> 0x1C); /*0x7eedc8*/
    v23 = (_DWORD *)*sub_405AD0(*(_DWORD **)(ShadowSceneNode + 0x118), &v33); /*0x7eede0*/
    if ( v33 ) /*0x7eede8*/
    {
      v24 = (void (__thiscall ***)(_DWORD, int))v33; /*0x7eedeb*/
      if ( !InterlockedDecrement((volatile LONG *)(v33 + 4)) ) /*0x7eedf1*/
        (**v24)(v24, 1); /*0x7eee07*/
    }
    if ( v23 ) /*0x7eee0c*/
    {
      *(this + 0x2C) = (char *)v23[0x38]; /*0x7eee20*/
      *(this + 0x2D) = (char *)v23[0x39]; /*0x7eee25*/
      *(this + 0x2E) = (char *)v23[0x3A]; /*0x7eee2b*/
    }
  }
  return 0; /*0x7eee2e*/
}
