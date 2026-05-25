// 0x00762640 @ 0x00762640
// MoonSugarEffect decode: NiDX9Renderer::SetCamera writes CameraWorldTranslate globals and renderer view/projection matrices from supplied camera position/basis/frustum, then sets D3D view/projection and viewport.
void __userpurge SetCamera(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        float a8,
        float a9,
        int a10,
        float *a11)
{
  float v12; // ecx
  float v13; // edx
  float v14; // eax
  double v15; // st4
  int v16; // eax
  double v18; // st7
  bool v19; // zf
  int (*v20)(void); // eax
  char v21; // al
  double v22; // st7
  float *v23; // ecx
  double v24; // st5
  double v25; // st5
  double v26; // st4
  double v27; // st7
  char v28; // al
  double v29; // st7
  double v30; // st5
  double v31; // st5
  double v32; // st4
  int v33; // eax
  double v34; // st7
  double v35; // st7
  _DWORD v36[4]; // [esp+50h] [ebp-10h] BYREF
  float retaddr; // [esp+60h] [ebp+0h]
  float v38; // [esp+64h] [ebp+4h]
  float v39; // [esp+64h] [ebp+4h]
  float v40; // [esp+64h] [ebp+4h]
  float v41; // [esp+6Ch] [ebp+Ch]
  int v42; // [esp+6Ch] [ebp+Ch]
  int v43; // [esp+6Ch] [ebp+Ch]
  int v44; // [esp+6Ch] [ebp+Ch]
  int v45; // [esp+70h] [ebp+10h]
  float v46; // [esp+74h] [ebp+14h]
  float v47; // [esp+74h] [ebp+14h]
  float v48; // [esp+78h] [ebp+18h]
  int v49; // [esp+78h] [ebp+18h]
  float v50; // [esp+7Ch] [ebp+1Ch]

  if ( !*(_BYTE *)(a1 + 0x6F0) ) /*0x762646*/
  {
    CameraWorldTranslate = *a4; /*0x762659*/
    v12 = Vector3_InitValue_; /*0x762662*/
    flt_B3F930 = a4[1]; /*0x762668*/
    v13 = *(&Vector3_InitValue_ + 1); /*0x762671*/
    flt_B3F934 = a4[2]; /*0x762677*/
    v14 = dword_B3F9B0; /*0x76267c*/
    *(float *)(a1 + 0x980) = *a7; /*0x762691*/
    *(float *)(a1 + 0x984) = *a6; /*0x7626a3*/
    *(float *)(a1 + 0x988) = *a5; /*0x7626b3*/
    *(float *)(a1 + 0x98C) = 0.0; /*0x7626bb*/
    *(float *)(a1 + 0x990) = a7[1]; /*0x7626c4*/
    *(float *)(a1 + 0x994) = a6[1]; /*0x7626cd*/
    *(float *)(a1 + 0x998) = a5[1]; /*0x7626d6*/
    *(float *)(a1 + 0x99C) = 0.0; /*0x7626dc*/
    *(float *)(a1 + 0x9A0) = a7[2]; /*0x7626e5*/
    *(float *)(a1 + 0x9A4) = a6[2]; /*0x7626ee*/
    *(float *)(a1 + 0x9A8) = a5[2]; /*0x7626f7*/
    *(float *)(a1 + 0x9AC) = 0.0; /*0x7626fd*/
    v15 = v14; /*0x762727*/
    v38 = *a7 * v12 + a7[1] * v13 + v14 * a7[2]; /*0x762729*/
    *(float *)(a1 + 0x9B0) = -v38; /*0x762733*/
    v39 = *a6 * v12 + v13 * a6[1] + a6[2] * v14; /*0x76274b*/
    *(float *)(a1 + 0x9B4) = -v39; /*0x762755*/
    v40 = *a5 * v12 + a5[1] * v13 + a5[2] * v14; /*0x76276d*/
    *(float *)(a1 + 0x9B8) = -v40; /*0x76277a*/
    *(float *)(a1 + 0x9BC) = 1.0; /*0x762782*/
    *(float *)(a1 + 0xA00) = *a7; /*0x76278a*/
    *(float *)(a1 + 0xA04) = a7[1]; /*0x762793*/
    *(float *)(a1 + 0xA08) = a7[2]; /*0x76279c*/
    *(float *)(a1 + 0xA0C) = 0.0; /*0x7627a4*/
    *(float *)(a1 + 0xA10) = *a6; /*0x7627ac*/
    *(float *)(a1 + 0xA14) = a6[1]; /*0x7627b5*/
    *(float *)(a1 + 0xA18) = a6[2]; /*0x7627be*/
    *(float *)(a1 + 0xA1C) = 0.0; /*0x7627c4*/
    *(float *)(a1 + 0xA20) = *a5; /*0x7627cc*/
    *(float *)(a1 + 0xA24) = a5[1]; /*0x7627d5*/
    v16 = *(_DWORD *)(a1 + 0x280); /*0x7627de*/
    *(float *)(a1 + 0xA28) = a5[2]; /*0x7627e4*/
    *(float *)(a1 + 0xA2C) = 0.0; /*0x7627eb*/
    *(float *)(a1 + 0xA30) = v12; /*0x7627f3*/
    *(float *)(a1 + 0xA34) = v13; /*0x7627f9*/
    *(float *)(a1 + 0xA38) = v15; /*0x7627ff*/
    *(float *)(a1 + 0xA3C) = 1.0; /*0x762805*/
    (*(void (__stdcall **)(int, int, int, int, int))(*(_DWORD *)v16 + 0xB0))(v16, 2, a1 + 0x980, a3, a2); /*0x762813*/
    *(float *)(a1 + 0x640) = *a7; /*0x762817*/
    *(float *)(a1 + 0x644) = a7[1]; /*0x762820*/
    *(float *)(a1 + 0x648) = a7[2]; /*0x762829*/
    *(float *)(a1 + 0x628) = *a7; /*0x762831*/
    *(float *)(a1 + 0x62C) = a7[1]; /*0x76283a*/
    *(float *)(a1 + 0x630) = a7[2]; /*0x762847*/
    *(float *)(a1 + 0x64C) = *a6; /*0x76284f*/
    *(float *)(a1 + 0x650) = a6[1]; /*0x762858*/
    *(float *)(a1 + 0x654) = a6[2]; /*0x762861*/
    *(float *)(a1 + 0x634) = *a6; /*0x762869*/
    *(float *)(a1 + 0x638) = a6[1]; /*0x762872*/
    *(float *)(a1 + 0x63C) = a6[2]; /*0x76287b*/
    *(float *)(a1 + 0x678) = *(float *)(a10 + 0x10); /*0x762884*/
    v41 = *(float *)(a10 + 0x14) - *(float *)(a10 + 0x10); /*0x762890*/
    v18 = v41; /*0x762894*/
    *(float *)(a1 + 0x67C) = v41; /*0x762898*/
    *(float *)&v42 = *(float *)(a10 + 4) - *(float *)a10; /*0x7628a3*/
    v48 = *(float *)(a10 + 4) + *(float *)a10; /*0x7628ac*/
    v46 = *(float *)(a10 + 8) - *(float *)(a10 + 0xC); /*0x7628b6*/
    v19 = *(_BYTE *)(a10 + 0x18) == 0; /*0x7628bd*/
    *(float *)&v45 = *(float *)(a10 + 0xC) + *(float *)(a10 + 8); /*0x7628cc*/
    v20 = *(int (**)(void))(**(_DWORD **)(a1 + 0x8AC) + 0x48); /*0x7628d0*/
    v50 = 1.0 / v18; /*0x7628d7*/
    if ( v19 ) /*0x7628db*/
    {
      v28 = v20(); /*0x76299d*/
      v29 = dbl_A3D0C0; /*0x76299f*/
      v23 = (float *)(a1 + 0x9C0); /*0x7629ab*/
      v30 = *(float *)&v42; /*0x7629b1*/
      if ( v28 ) /*0x7629b3*/
      {
        *v23 = dbl_A3F400 / v30; /*0x7629bb*/
        v31 = 0.0; /*0x7629bd*/
        *(float *)(a1 + 0x9D0) = 0.0; /*0x7629bf*/
        v32 = v48; /*0x7629c5*/
      }
      else
      {
        *v23 = v29 / v30; /*0x7629cd*/
        v31 = 0.0; /*0x7629cf*/
        *(float *)(a1 + 0x9D0) = 0.0; /*0x7629d1*/
        v32 = -v48; /*0x7629db*/
      }
      *(float *)(a1 + 0x9E0) = v32 / *(float *)&v42; /*0x7629e1*/
      *(float *)(a1 + 0x9F0) = v31; /*0x7629e7*/
      *(float *)(a1 + 0x9C4) = v31; /*0x7629ed*/
      *(float *)(a1 + 0x9D4) = v29 / v46; /*0x7629fd*/
      v27 = v31; /*0x762a0b*/
      *(float *)(a1 + 0x9E4) = -*(float *)&v45 / v46; /*0x762a0d*/
      *(float *)(a1 + 0x9F4) = v31; /*0x762a13*/
      *(float *)(a1 + 0x9C8) = v31; /*0x762a19*/
      *(float *)(a1 + 0x9D8) = v31; /*0x762a1f*/
      *(float *)(a1 + 0x9E8) = *(float *)(a10 + 0x14) * v50; /*0x762a32*/
      *(float *)(a1 + 0x9F8) = -(v50 * (*(float *)(a10 + 0x14) * *(float *)(a10 + 0x10))); /*0x762a42*/
      *(float *)(a1 + 0x9CC) = v31; /*0x762a48*/
      *(float *)(a1 + 0x9DC) = v31; /*0x762a4e*/
      *(float *)(a1 + 0x9EC) = 1.0; /*0x762a56*/
    }
    else
    {
      v21 = v20(); /*0x7628e1*/
      v22 = dbl_A3D0C0; /*0x7628e3*/
      v23 = (float *)(a1 + 0x9C0); /*0x7628ef*/
      v24 = *(float *)&v42; /*0x7628f5*/
      if ( v21 ) /*0x7628f7*/
      {
        *v23 = dbl_A3F400 / v24; /*0x7628ff*/
        v25 = 0.0; /*0x762901*/
        *(float *)(a1 + 0x9D0) = 0.0; /*0x762903*/
        *(float *)(a1 + 0x9E0) = 0.0; /*0x762909*/
        v26 = v48; /*0x76290f*/
      }
      else
      {
        *v23 = v22 / v24; /*0x762917*/
        v25 = 0.0; /*0x762919*/
        *(float *)(a1 + 0x9D0) = 0.0; /*0x76291b*/
        *(float *)(a1 + 0x9E0) = 0.0; /*0x762921*/
        v26 = -v48; /*0x76292b*/
      }
      *(float *)(a1 + 0x9F0) = v26 / *(float *)&v42; /*0x762931*/
      *(float *)(a1 + 0x9C4) = v25; /*0x762937*/
      *(float *)(a1 + 0x9D4) = v22 / v46; /*0x762947*/
      *(float *)(a1 + 0x9E4) = v25; /*0x76294d*/
      *(float *)(a1 + 0x9F4) = -*(float *)&v45 / v46; /*0x76295d*/
      *(float *)(a1 + 0x9C8) = v25; /*0x762963*/
      *(float *)(a1 + 0x9D8) = v25; /*0x762969*/
      *(float *)(a1 + 0x9E8) = v50; /*0x762973*/
      *(float *)(a1 + 0x9F8) = -(v50 * *(float *)(a10 + 0x10)); /*0x76297e*/
      *(float *)(a1 + 0x9CC) = v25; /*0x762984*/
      *(float *)(a1 + 0x9DC) = v25; /*0x76298a*/
      *(float *)(a1 + 0x9EC) = v25; /*0x762990*/
      v27 = 1.0; /*0x762996*/
    }
    v33 = *(_DWORD *)(a1 + 0x280); /*0x762a5c*/
    *(float *)(a1 + 0x9FC) = v27; /*0x762a62*/
    (*(void (__stdcall **)(int, int, float *))(*(_DWORD *)v33 + 0xB0))(v33, 3, v23); /*0x762a74*/
    v43 = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a1 + 0x87C) + 0x4C))(*(_DWORD *)(a1 + 0x87C), 0); /*0x762a87*/
    v34 = (double)v43; /*0x762a8b*/
    if ( v43 < 0 ) /*0x762a8f*/
      v34 = v34 + flt_A2FC78; /*0x762a91*/
    *(float *)&v44 = v34; /*0x762a9d*/
    v49 = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a1 + 0x87C) + 0x50))(*(_DWORD *)(a1 + 0x87C), 0); /*0x762aac*/
    v35 = (double)v49; /*0x762ab0*/
    if ( v49 < 0 ) /*0x762ab4*/
      v35 = v35 + flt_A2FC78; /*0x762ab6*/
    v47 = v35; /*0x762ac0*/
    v36[0] = (__int64)(*a11 * *(float *)&v44); /*0x762aee*/
    v36[1] = (__int64)((1.0 - a11[2]) * v47); /*0x762b25*/
    v36[2] = (__int64)(*(float *)&v44 * (a11[1] - *a11)); /*0x762b54*/
    v36[3] = (__int64)(v47 * (a11[2] - a11[3])); /*0x762b87*/
    retaddr = 0.0; /*0x762b98*/
    (*(void (__cdecl **)(_DWORD, _DWORD *))(**(_DWORD **)(a1 + 0x280) + 0xBC))(*(_DWORD *)(a1 + 0x280), v36); /*0x762baa*/
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)(a1 + 0x8AC) + 0x44))( /*0x762bc9*/
      *(_DWORD *)(a1 + 0x8AC),
      *(float *)(a10 + 0x10),
      *(float *)(a10 + 0x14));
  }
}
