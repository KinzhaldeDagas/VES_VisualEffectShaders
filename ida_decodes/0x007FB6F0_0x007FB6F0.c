// 0x007FB6F0 @ 0x007FB6F0
// MoonSugarEffect decode: Lighting30Shader transform slot (+0x34). Calls sub_765480 with the passed NiTransform and builds lighting/shadow globals from it; confirms rigid Moon Sugar transform-copy wobble reaches Lighting30 materials.
double __userpurge sub_7FB6F0@<st0>(
        char *a1@<ecx>,
        double result@<st0>,
        float a3,
        NiSkinInstance *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        NiTransform *a9,
        int a10)
{
  int v11; // esi
  BOOL v13; // eax
  int v14; // edi
  bool v15; // zf
  NiSkinInstance *v16; // esi
  float *v17; // ebx
  _DWORD *v18; // eax
  float v19; // edi
  double v20; // st6
  double v21; // st5
  float *v22; // eax
  double v23; // st6
  int v24; // edx
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  int v28; // edi
  int v29; // ebx
  int v30; // eax
  float *v31; // esi
  float v32; // ecx
  double v33; // st6
  float v34; // eax
  float v35; // edx
  float *v36; // esi
  int v37; // edi
  float v38; // edx
  float v39; // eax
  float v40; // ecx
  float v41; // edx
  double v42; // st6
  int v43; // eax
  double v44; // st6
  float v45; // ecx
  float v46; // edx
  float v47; // ecx
  int v48; // edx
  double v49; // st5
  double v50; // st4
  double v51; // st3
  double v52; // st6
  double v53; // st5
  double v54; // st4
  double v55; // st3
  float v56; // edx
  float v57; // eax
  float v58; // ecx
  double v59; // st6
  float v60; // eax
  float v61; // ecx
  double v62; // st6
  int v63; // edx
  double v64; // st6
  int v65; // eax
  double v66; // st6
  int v67; // ecx
  double v68; // st6
  int v69; // edx
  double v70; // st6
  int v71; // eax
  double v72; // st6
  int v73; // ecx
  double v74; // st6
  int v75; // edx
  double v76; // st6
  int v77; // eax
  double v78; // st6
  int v79; // ecx
  double v80; // st6
  int v81; // edx
  double v82; // st6
  int v83; // eax
  int v84; // ecx
  int v85; // edx
  int v86; // eax
  int v87; // ecx
  int v88; // edx
  int v89; // eax
  int v90; // ecx
  int v91; // edx
  int v92; // ecx
  IDirect3DDevice9 *device; // ebx
  int *v94; // ecx
  int v95; // eax
  float *v96; // ebx
  int v97; // eax
  double v98; // st5
  double v99; // st6
  double v100; // st4
  int v101; // edi
  float *v102; // esi
  float v103; // edx
  float v104; // eax
  float v105; // eax
  float v106; // ecx
  float v107; // edx
  int v108; // ecx
  char *v109; // edi
  const float *v110; // edi
  int i; // esi
  float v112; // [esp+64h] [ebp-25Ch] BYREF
  int v113; // [esp+68h] [ebp-258h]
  int v114; // [esp+6Ch] [ebp-254h]
  float v115; // [esp+70h] [ebp-250h]
  bool v116; // [esp+77h] [ebp-249h]
  float v117; // [esp+78h] [ebp-248h] BYREF
  float v118; // [esp+7Ch] [ebp-244h]
  float v119; // [esp+80h] [ebp-240h]
  float v120; // [esp+84h] [ebp-23Ch]
  float scale; // [esp+88h] [ebp-238h]
  float v122; // [esp+8Ch] [ebp-234h] BYREF
  int v123; // [esp+90h] [ebp-230h]
  float v124; // [esp+94h] [ebp-22Ch] BYREF
  float v125; // [esp+98h] [ebp-228h]
  float v126; // [esp+9Ch] [ebp-224h]
  float v127; // [esp+A0h] [ebp-220h] BYREF
  float v128; // [esp+A4h] [ebp-21Ch]
  float v129; // [esp+A8h] [ebp-218h]
  float v130; // [esp+ACh] [ebp-214h]
  float v131; // [esp+B0h] [ebp-210h] BYREF
  float v132; // [esp+B4h] [ebp-20Ch]
  float v133; // [esp+B8h] [ebp-208h]
  int v134; // [esp+BCh] [ebp-204h]
  _BYTE v135[64]; // [esp+C0h] [ebp-200h] BYREF
  float v136[19]; // [esp+100h] [ebp-1C0h] BYREF
  float v137; // [esp+14Ch] [ebp-174h] BYREF
  float v138; // [esp+150h] [ebp-170h]
  float v139; // [esp+154h] [ebp-16Ch]
  float v140; // [esp+158h] [ebp-168h] BYREF
  float v141; // [esp+15Ch] [ebp-164h]
  float v142; // [esp+160h] [ebp-160h]
  float v143; // [esp+164h] [ebp-15Ch]
  float v144; // [esp+168h] [ebp-158h]
  float v145; // [esp+16Ch] [ebp-154h]
  float v146; // [esp+170h] [ebp-150h]
  float v147; // [esp+174h] [ebp-14Ch]
  float v148; // [esp+178h] [ebp-148h]
  float v149; // [esp+17Ch] [ebp-144h]
  float v150; // [esp+180h] [ebp-140h]
  float v151; // [esp+184h] [ebp-13Ch]
  float v152; // [esp+188h] [ebp-138h]
  float v153; // [esp+18Ch] [ebp-134h]
  float v154; // [esp+190h] [ebp-130h]
  float v155; // [esp+194h] [ebp-12Ch]
  float v156; // [esp+198h] [ebp-128h] BYREF
  float v157; // [esp+19Ch] [ebp-124h]
  float v158; // [esp+1A0h] [ebp-120h]
  float v159; // [esp+1A4h] [ebp-11Ch]
  float v160; // [esp+1A8h] [ebp-118h]
  float v161; // [esp+1ACh] [ebp-114h]
  float v162; // [esp+1B0h] [ebp-110h]
  float v163; // [esp+1B4h] [ebp-10Ch]
  float v164; // [esp+1B8h] [ebp-108h]
  float v165; // [esp+1BCh] [ebp-104h]
  float v166; // [esp+1C0h] [ebp-100h]
  float v167; // [esp+1C4h] [ebp-FCh]
  float v168; // [esp+1C8h] [ebp-F8h]
  float v169; // [esp+1CCh] [ebp-F4h]
  float v170; // [esp+1D0h] [ebp-F0h]
  float v171; // [esp+1D4h] [ebp-ECh]
  IDirect3DDevice9 *v172; // [esp+1D8h] [ebp-E8h]
  int v173; // [esp+1DCh] [ebp-E4h]
  _BYTE v174[64]; // [esp+1E0h] [ebp-E0h] BYREF
  char v175[96]; // [esp+220h] [ebp-A0h] BYREF
  _BYTE v176[64]; // [esp+280h] [ebp-40h] BYREF

  v11 = *(_DWORD *)(a7 + 0x18); /*0x7fb701*/
  v120 = *(float *)&a1; /*0x7fb709*/
  if ( v11 ) /*0x7fb70d*/
    v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 0x54))(v11) == 0xA; /*0x7fb724*/
  else
    v13 = 0; /*0x7fb70f*/
  v14 = v13 ? v11 : 0;
  v15 = (*(_BYTE *)(v14 + 0x1C) & 2) == 0; /*0x7fb734*/
  v123 = dword_B42E90; /*0x7fb738*/
  v116 = !v15; /*0x7fb741*/
  if ( v15 ) /*0x7fb745*/
  {
    v17 = (float *)a9; /*0x7fb788*/
    v16 = a4; /*0x7fb78b*/
  }
  else
  {
    if ( !a5 ) /*0x7fb74b*/
      return result; /*0x7fb74b*/
    v15 = *((_DWORD *)a1 + 0xD) == 0; /*0x7fb751*/
    v16 = a4; /*0x7fb755*/
    v17 = (float *)a9; /*0x7fb758*/
    if ( v15 ) /*0x7fb75b*/
      NiDX9Renderer::CalculateBoneMatrixes(dword_B43104, a4, a9, 0, 3, 1); /*0x7fb76b*/
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(LODWORD(v120) + 0x18) + 0x30))( /*0x7fb784*/
      *(_DWORD *)(LODWORD(v120) + 0x18),
      *(unsigned __int16 *)(a5 + 0x24));
  }
  sub_765480(*(NiDX9Renderer **)(LODWORD(v120) + 0x14), v17, 0); /*0x7fb798*/
  if ( LOWORD(dword_B42EAC) == 5 ) /*0x7fb7a5*/
  {
    v18 = sub_405AD0(**(_DWORD ***)(dword_B42EB8 + 0xC), &v122); /*0x7fb7b7*/
    v19 = v122; /*0x7fb7be*/
    v120 = *(float *)(*v18 + 0xF8); /*0x7fb7ca*/
    if ( v122 != 0.0 && !InterlockedDecrement((volatile LONG *)(LODWORD(v122) + 4)) && v19 != 0.0 ) /*0x7fb7e0*/
      (**(void (__thiscall ***)(_DWORD, int))LODWORD(v19))(LODWORD(v19), 1); /*0x7fb7ea*/
    if ( !v16 ) /*0x7fb7ee*/
      v120 = v120 / v17[0xC]; /*0x7fb7f7*/
    flt_B47014 = v120; /*0x7fb801*/
  }
  else
  {
    v20 = 0.0; /*0x7fb817*/
    v21 = 1.0; /*0x7fb819*/
    if ( !*(_BYTE *)(v14 + 0x100) ) /*0x7fb810*/
    {
      v15 = !v116; /*0x7fb821*/
      *(_BYTE *)(v14 + 0x100) = 1; /*0x7fb828*/
      v170 = 0.0; /*0x7fb82f*/
      v169 = 0.0; /*0x7fb836*/
      v168 = 0.0; /*0x7fb83d*/
      v167 = 0.0; /*0x7fb844*/
      v165 = 0.0; /*0x7fb84b*/
      v164 = 0.0; /*0x7fb852*/
      v163 = 0.0; /*0x7fb859*/
      v162 = 0.0; /*0x7fb860*/
      v160 = 0.0; /*0x7fb867*/
      v159 = 0.0; /*0x7fb86e*/
      v158 = 0.0; /*0x7fb875*/
      v157 = 0.0; /*0x7fb87c*/
      v154 = 0.0; /*0x7fb883*/
      v153 = 0.0; /*0x7fb88a*/
      v152 = 0.0; /*0x7fb891*/
      v151 = 0.0; /*0x7fb898*/
      v149 = 0.0; /*0x7fb89f*/
      v148 = 0.0; /*0x7fb8a6*/
      v147 = 0.0; /*0x7fb8ad*/
      v146 = 0.0; /*0x7fb8b4*/
      v144 = 0.0; /*0x7fb8bb*/
      v143 = 0.0; /*0x7fb8c2*/
      v142 = 0.0; /*0x7fb8c9*/
      v141 = 0.0; /*0x7fb8d0*/
      v171 = 1.0; /*0x7fb8d7*/
      v166 = 1.0; /*0x7fb8de*/
      v161 = 1.0; /*0x7fb8e5*/
      v156 = 1.0; /*0x7fb8ec*/
      v155 = 1.0; /*0x7fb8f3*/
      v150 = 1.0; /*0x7fb8fa*/
      v145 = 1.0; /*0x7fb901*/
      v140 = 1.0; /*0x7fb908*/
      if ( v15 || !v16 ) /*0x7fb917*/
      {
        sub_718A80(v17, (NiTransform *)v135); /*0x7fb9f6*/
        v156 = *(float *)v135 * *(float *)&v135[0x30]; /*0x7fba0c*/
        v157 = *(float *)&v135[0xC] * *(float *)&v135[0x30]; /*0x7fba19*/
        v158 = *(float *)&v135[0x18] * *(float *)&v135[0x30]; /*0x7fba29*/
        v160 = *(float *)&v135[4] * *(float *)&v135[0x30]; /*0x7fba36*/
        v161 = *(float *)&v135[0x10] * *(float *)&v135[0x30]; /*0x7fba46*/
        v162 = *(float *)&v135[0x1C] * *(float *)&v135[0x30]; /*0x7fba56*/
        v164 = *(float *)&v135[8] * *(float *)&v135[0x30]; /*0x7fba63*/
        v165 = *(float *)&v135[0x14] * *(float *)&v135[0x30]; /*0x7fba73*/
        v166 = *(float *)&v135[0x30] * *(float *)&v135[0x20]; /*0x7fba81*/
        v168 = *(float *)&v135[0x24]; /*0x7fba8f*/
        v169 = *(float *)&v135[0x28]; /*0x7fba9d*/
        v170 = *(float *)&v135[0x2C]; /*0x7fbaab*/
        v23 = 1.0; /*0x7fbab2*/
        v171 = 1.0; /*0x7fbab4*/
      }
      else
      {
        v22 = *((float **)v16 + 0xA); /*0x7fb91d*/
        v140 = *v22; /*0x7fb929*/
        v141 = v22[1]; /*0x7fb933*/
        v142 = v22[2]; /*0x7fb93d*/
        v144 = v22[4]; /*0x7fb947*/
        v145 = v22[5]; /*0x7fb951*/
        v146 = v22[6]; /*0x7fb95b*/
        v148 = v22[8]; /*0x7fb965*/
        v149 = v22[9]; /*0x7fb96f*/
        v150 = v22[0xA]; /*0x7fb979*/
        v152 = v22[0xC] + CameraWorldTranslate; /*0x7fb989*/
        v153 = v22[0xD] + flt_B3F930; /*0x7fb999*/
        v154 = v22[0xE] + flt_B3F934; /*0x7fb9a9*/
        v143 = v22[3]; /*0x7fb9b3*/
        v147 = v22[7]; /*0x7fb9bd*/
        v151 = v22[0xB]; /*0x7fb9c7*/
        v155 = v22[0xF]; /*0x7fb9d9*/
        D3DXMatrixInverse_0(&v156, 0, &v140); /*0x7fb9e3*/
        v23 = 1.0; /*0x7fb9e8*/
      }
      if ( BYTE2(dword_B4696C) ) /*0x7fbabb*/
      {
        v24 = dword_B42EB8; /*0x7fbac8*/
        v25 = *(_DWORD *)(dword_B42EB8 + 0xC); /*0x7fbace*/
        if ( !v25 || *(_BYTE *)(*(_DWORD *)v25 + 0xF5) || v123 >= 0x147 && v123 <= 0x14D ) /*0x7fbaf8*/
        {
          qmemcpy(v136, (const void *)(*(_DWORD *)(LODWORD(v120) + 0x14) + 0x940), 0x40u); /*0x7fbccd*/
          D3DXMatrixTranspose_0(v136, v136); /*0x7fbccf*/
          flt_B46D68 = v136[0]; /*0x7fbcdb*/
          flt_B46D6C = v136[1]; /*0x7fbce8*/
          flt_B46D70 = v136[2]; /*0x7fbcf5*/
          flt_B46D74 = v136[3]; /*0x7fbd02*/
          flt_B46D78 = v136[4]; /*0x7fbd0f*/
          flt_B46D7C = v136[5]; /*0x7fbd1c*/
          flt_B46D80 = v136[6]; /*0x7fbd29*/
          flt_B46D84 = v136[7]; /*0x7fbd36*/
          flt_B46D88 = v136[8]; /*0x7fbd43*/
          flt_B46D8C = v136[9]; /*0x7fbd50*/
          flt_B46D90 = v136[0xA]; /*0x7fbd5d*/
          flt_B46D94 = v136[0xB]; /*0x7fbd6a*/
          flt_B46D98 = v136[0xC]; /*0x7fbd77*/
          flt_B46D9C = v136[0xD]; /*0x7fbd84*/
          flt_B46DA0 = v136[0xE]; /*0x7fbd91*/
          flt_B46DA4 = v136[0xF]; /*0x7fbd9e*/
        }
        else
        {
          *(float *)&v135[0x38] = 0.0; /*0x7fbb02*/
          *(float *)&v135[0x34] = 0.0; /*0x7fbb09*/
          *(float *)&v135[0x30] = 0.0; /*0x7fbb10*/
          *(float *)&v135[0x2C] = 0.0; /*0x7fbb17*/
          *(float *)&v135[0x24] = 0.0; /*0x7fbb1e*/
          *(float *)&v135[0x20] = 0.0; /*0x7fbb25*/
          *(float *)&v135[0x1C] = 0.0; /*0x7fbb2c*/
          *(float *)&v135[0x18] = 0.0; /*0x7fbb33*/
          *(float *)&v135[0x10] = 0.0; /*0x7fbb3a*/
          *(float *)&v135[0xC] = 0.0; /*0x7fbb41*/
          *(float *)&v135[8] = 0.0; /*0x7fbb45*/
          *(float *)&v135[4] = 0.0; /*0x7fbb49*/
          v136[0xE] = 0.0; /*0x7fbb4d*/
          v136[0xD] = 0.0; /*0x7fbb54*/
          v136[0xC] = 0.0; /*0x7fbb5b*/
          v136[0xB] = 0.0; /*0x7fbb62*/
          v136[9] = 0.0; /*0x7fbb69*/
          v136[8] = 0.0; /*0x7fbb70*/
          v136[7] = 0.0; /*0x7fbb77*/
          v136[6] = 0.0; /*0x7fbb7e*/
          v136[4] = 0.0; /*0x7fbb85*/
          v136[3] = 0.0; /*0x7fbb8c*/
          v136[2] = 0.0; /*0x7fbb93*/
          v136[1] = 0.0; /*0x7fbb9a*/
          *(float *)&v135[0x3C] = v23; /*0x7fbba1*/
          *(float *)&v135[0x28] = v23; /*0x7fbba8*/
          *(float *)&v135[0x14] = v23; /*0x7fbbaf*/
          *(float *)v135 = v23; /*0x7fbbb6*/
          v136[0xF] = v23; /*0x7fbbba*/
          v136[0xA] = v23; /*0x7fbbc1*/
          v136[5] = v23; /*0x7fbbc8*/
          v136[0] = v23; /*0x7fbbcf*/
          if ( v16 ) /*0x7fbbd6*/
          {
            qmemcpy(v135, *((const void **)v16 + 0xA), sizeof(v135)); /*0x7fbbe4*/
          }
          else
          {
            sub_7640A0((float *)v135, v17); /*0x7fbbee*/
            v24 = dword_B42EB8; /*0x7fbbf3*/
          }
          v26 = dword_B42E90 - 0x14E; /*0x7fbc0e*/
          *(float *)&v135[0x30] = CameraWorldTranslate + *(float *)&v135[0x30]; /*0x7fbc16*/
          *(float *)&v135[0x34] = flt_B3F930 + *(float *)&v135[0x34]; /*0x7fbc2a*/
          *(float *)&v135[0x38] = flt_B3F934 + *(float *)&v135[0x38]; /*0x7fbc3e*/
          if ( v26 > 3 ) /*0x7fbc45*/
            v27 = *(_DWORD *)(*(_DWORD *)(v24 + 0xC) + 4); /*0x7fbc51*/
          else
            v27 = **(_DWORD **)(v24 + 0xC); /*0x7fbc4a*/
          D3DXMatrixMultiply_0(v174, v135, v27 + 0x10); /*0x7fbc65*/
          qmemcpy(v136, v174, 0x40u); /*0x7fbc88*/
          D3DXMatrixTranspose_0(v136, v136); /*0x7fbc8a*/
          qmemcpy(&flt_B46D68, v136, 0x40u); /*0x7fbca0*/
        }
        v16 = a4; /*0x7fbda4*/
        v23 = 1.0; /*0x7fbda7*/
      }
      if ( v123 < 0x152 || v123 > 0x153 ) /*0x7fbdb9*/
      {
        v28 = 0; /*0x7fbdc5*/
        v29 = Double_To_SInt32(result); /*0x7fbdd2*/
        *(float *)&v30 = COERCE_FLOAT(Double_To_SInt32(result)); /*0x7fbdd4*/
        v122 = *(float *)&v30; /*0x7fbde3*/
        if ( (v123 < 0x14E || v123 > 0x151) && v29 > 0 ) /*0x7fbdf7*/
        {
          v31 = (float *)&unk_B47018; /*0x7fbdff*/
          v28 = v29; /*0x7fbe06*/
          v130 = 0.0; /*0x7fbe08*/
          do /*0x7fbee3*/
          {
            v112 = -*v31; /*0x7fbe1c*/
            *(float *)&v113 = -v31[1]; /*0x7fbe31*/
            *(float *)&v114 = -v31[2]; /*0x7fbe3b*/
            v124 = v112; /*0x7fbe43*/
            v125 = *(float *)&v113; /*0x7fbe4b*/
            v126 = *(float *)&v114; /*0x7fbe53*/
            D3DXVec3TransformNormal_0(&v137, &v124, &v156); /*0x7fbe57*/
            D3DXVec3Normalize_0(&v124, &v137); /*0x7fbe69*/
            v117 = v124; /*0x7fbe72*/
            v131 = v124; /*0x7fbe7e*/
            v118 = v125; /*0x7fbe82*/
            v132 = v125; /*0x7fbe8e*/
            v119 = v126; /*0x7fbe92*/
            v133 = v126; /*0x7fbe9e*/
            result = sub_43F350(&v131); /*0x7fbea2*/
            v31 += 8; /*0x7fbead*/
            --v29; /*0x7fbeb0*/
            v127 = v131; /*0x7fbeb3*/
            v128 = v132; /*0x7fbebf*/
            v32 = v132; /*0x7fbec3*/
            v33 = v133; /*0x7fbec7*/
            v31[0xFFFFFFF8] = v131; /*0x7fbecb*/
            v34 = v130; /*0x7fbece*/
            v129 = v33; /*0x7fbed2*/
            v35 = v129; /*0x7fbed6*/
            v31[0xFFFFFFF9] = v32; /*0x7fbeda*/
            v31[0xFFFFFFFA] = v35; /*0x7fbedd*/
            v31[0xFFFFFFFB] = v34; /*0x7fbee0*/
          }
          while ( v29 ); /*0x7fbee3*/
          v23 = 1.0; /*0x7fbee9*/
          *(float *)&v30 = v122; /*0x7fbeeb*/
        }
        if ( v30 > 0 ) /*0x7fbef1*/
        {
          v36 = (float *)((char *)&unk_B47018 + 0x20 * v28); /*0x7fbf02*/
          v37 = v30; /*0x7fbf04*/
          do /*0x7fc02e*/
          {
            v38 = v36[1]; /*0x7fbf08*/
            v39 = v36[2]; /*0x7fbf0b*/
            v127 = *v36; /*0x7fbf0e*/
            v40 = v36[3]; /*0x7fbf16*/
            v131 = v127; /*0x7fbf19*/
            v128 = v38; /*0x7fbf1d*/
            v129 = v39; /*0x7fbf25*/
            v132 = v38; /*0x7fbf29*/
            v133 = v39; /*0x7fbf39*/
            v130 = v40; /*0x7fbf41*/
            D3DXVec3TransformCoord_0(&v137, &v131, &v156); /*0x7fbf4e*/
            v117 = v137; /*0x7fbf5e*/
            v118 = v138; /*0x7fbf6d*/
            v124 = v137; /*0x7fbf7c*/
            v119 = v139; /*0x7fbf80*/
            v125 = v138; /*0x7fbf8c*/
            v122 = v130; /*0x7fbf90*/
            v126 = v139; /*0x7fbf94*/
            if ( !a4 ) /*0x7fbf98*/
            {
              if ( v123 == 0x14E || v123 == 0x14F ) /*0x7fbfaa*/
              {
                scale = a9->scale; /*0x7fbfc2*/
                v124 = v137 * scale; /*0x7fbfd0*/
                v125 = scale * v125; /*0x7fbfda*/
                v126 = scale * v126; /*0x7fbfe2*/
              }
              else
              {
                v122 = v130 / a9->scale; /*0x7fbfb4*/
              }
            }
            v36 += 8; /*0x7fbff0*/
            --v37; /*0x7fbff3*/
            v112 = v124; /*0x7fbff6*/
            *(float *)&v113 = v125; /*0x7fc002*/
            v41 = v125; /*0x7fc006*/
            v42 = v126; /*0x7fc00a*/
            v36[0xFFFFFFF8] = v124; /*0x7fc00e*/
            *(float *)&v114 = v42; /*0x7fc011*/
            v43 = v114; /*0x7fc015*/
            v44 = v122; /*0x7fc019*/
            v36[0xFFFFFFF9] = v41; /*0x7fc01d*/
            v115 = v44; /*0x7fc020*/
            v45 = v115; /*0x7fc024*/
            *((_DWORD *)v36 + 0xFFFFFFFA) = v43; /*0x7fc028*/
            v36[0xFFFFFFFB] = v45; /*0x7fc02b*/
          }
          while ( v37 ); /*0x7fc02e*/
          v23 = 1.0; /*0x7fc034*/
        }
        v16 = a4; /*0x7fc036*/
        v17 = (float *)a9; /*0x7fc039*/
      }
      v46 = *(float *)&dword_B46658; /*0x7fc041*/
      v47 = *(float *)&dword_B46660; /*0x7fc047*/
      v132 = *(float *)&dword_B4665C; /*0x7fc04d*/
      v131 = v46; /*0x7fc055*/
      v48 = dword_B46664; /*0x7fc059*/
      v133 = v47; /*0x7fc067*/
      v134 = v48; /*0x7fc06b*/
      if ( (unsigned int)(v123 - 0x147) > 6 ) /*0x7fc06f*/
      {
        v137 = v131; /*0x7fc132*/
        v138 = v132; /*0x7fc145*/
        v139 = v133; /*0x7fc155*/
        D3DXVec3TransformCoord_0(&v117, &v137, &v156); /*0x7fc15c*/
        v52 = v117; /*0x7fc161*/
        v53 = v118; /*0x7fc16d*/
        *(float *)&dword_B46DA8 = v117; /*0x7fc171*/
        *(float *)&v113 = v53; /*0x7fc176*/
        v54 = v119; /*0x7fc17e*/
        dword_B46DAC = v113; /*0x7fc182*/
        *(float *)&v114 = v54; /*0x7fc188*/
        dword_B46DB0 = v114; /*0x7fc192*/
        v55 = v52; /*0x7fc1a0*/
        v23 = 1.0; /*0x7fc1a0*/
        v112 = v55; /*0x7fc1a2*/
        *(float *)&dword_B46DB4 = 1.0; /*0x7fc1a6*/
        *(float *)&v113 = v53; /*0x7fc1b1*/
        *(float *)&dword_B46F88 = v112; /*0x7fc1b5*/
        dword_B46F8C = v113; /*0x7fc1bf*/
        *(float *)&v114 = v54; /*0x7fc1c5*/
        dword_B46F90 = v114; /*0x7fc1cd*/
        v115 = 1.0; /*0x7fc1d2*/
        *(float *)&dword_B46F94 = 1.0; /*0x7fc1da*/
      }
      else
      {
        v117 = v131 - CameraWorldTranslate; /*0x7fc07f*/
        v118 = v132 - flt_B3F930; /*0x7fc08d*/
        v119 = v133 - flt_B3F934; /*0x7fc09b*/
        v49 = v117; /*0x7fc09f*/
        v50 = v118; /*0x7fc0ab*/
        *(float *)&dword_B46DA8 = v117; /*0x7fc0af*/
        *(float *)&v113 = v50; /*0x7fc0b5*/
        v51 = v119; /*0x7fc0bd*/
        dword_B46DAC = v113; /*0x7fc0c1*/
        *(float *)&v114 = v51; /*0x7fc0c7*/
        dword_B46DB0 = v114; /*0x7fc0d1*/
        v115 = v23; /*0x7fc0d6*/
        *(float *)&dword_B46DB4 = v115; /*0x7fc0e0*/
        v112 = v49; /*0x7fc0e6*/
        *(float *)&dword_B46F88 = v112; /*0x7fc0ee*/
        *(float *)&v113 = v50; /*0x7fc0f4*/
        dword_B46F8C = v113; /*0x7fc0fe*/
        *(float *)&v114 = v51; /*0x7fc103*/
        dword_B46F90 = v114; /*0x7fc10b*/
        v115 = v23; /*0x7fc111*/
        *(float *)&dword_B46F94 = v115; /*0x7fc119*/
      }
      v21 = v23; /*0x7fc1e2*/
      v20 = 0.0; /*0x7fc1e2*/
    }
    if ( BYTE1(dword_B46978) ) /*0x7fc1e4*/
    {
      if ( v116 && v16 ) /*0x7fc1fe*/
      {
        v56 = CameraWorldTranslate; /*0x7fc204*/
        *(float *)v135 = v21; /*0x7fc20a*/
        v57 = flt_B3F930; /*0x7fc20e*/
        v58 = flt_B3F934; /*0x7fc215*/
        *(float *)&v135[4] = v20; /*0x7fc21b*/
        *(float *)&v135[8] = *(float *)&v135[4]; /*0x7fc21f*/
        v117 = v56; /*0x7fc223*/
        v118 = v57; /*0x7fc22b*/
        *(float *)&v135[0xC] = v56; /*0x7fc22f*/
        v119 = v58; /*0x7fc233*/
        *(float *)&v135[0x10] = *(float *)&v135[4]; /*0x7fc237*/
        *(float *)&v135[0x18] = *(float *)&v135[4]; /*0x7fc23e*/
        *(float *)&v135[0x14] = v21; /*0x7fc247*/
        *(float *)&v135[0x1C] = v57; /*0x7fc252*/
        *(float *)&v135[0x20] = *(float *)&v135[4]; /*0x7fc25b*/
        *(float *)&v135[0x24] = *(float *)&v135[4]; /*0x7fc262*/
        *(float *)&v135[0x28] = *(float *)&v135[0x14]; /*0x7fc26b*/
        *(float *)&v135[0x2C] = v58; /*0x7fc276*/
        v59 = v21; /*0x7fc27d*/
        *(float *)&v135[0x30] = *(float *)&v135[4]; /*0x7fc27f*/
        *(float *)&v135[0x34] = *(float *)&v135[4]; /*0x7fc286*/
        *(float *)&v135[0x38] = *(float *)&v135[4]; /*0x7fc28d*/
      }
      else
      {
        *(float *)v135 = *v17; /*0x7fc29d*/
        *(float *)&v135[4] = v17[1]; /*0x7fc2a4*/
        *(float *)&v135[8] = v17[2]; /*0x7fc2ab*/
        *(float *)&v135[0xC] = v17[9]; /*0x7fc2b2*/
        *(float *)&v135[0x10] = v17[3]; /*0x7fc2b9*/
        *(float *)&v135[0x14] = v17[4]; /*0x7fc2c3*/
        *(float *)&v135[0x18] = v17[5]; /*0x7fc2cd*/
        *(float *)&v135[0x1C] = v17[0xA]; /*0x7fc2d7*/
        *(float *)&v135[0x20] = v17[6]; /*0x7fc2e1*/
        *(float *)&v135[0x24] = v17[7]; /*0x7fc2eb*/
        *(float *)&v135[0x28] = v17[8]; /*0x7fc2f5*/
        *(float *)&v135[0x2C] = v17[0xB]; /*0x7fc2ff*/
        *(float *)&v135[0x30] = v20; /*0x7fc306*/
        *(float *)&v135[0x34] = v20; /*0x7fc30d*/
        *(float *)&v135[0x38] = v20; /*0x7fc314*/
        v59 = v17[0xC]; /*0x7fc31b*/
      }
      *(float *)&v135[0x3C] = v59; /*0x7fc31e*/
      qmemcpy(v136, v135, 0x40u); /*0x7fc335*/
      v115 = v136[3]; /*0x7fc35f*/
      v60 = v136[1]; /*0x7fc36e*/
      v61 = v136[2]; /*0x7fc372*/
      v112 = v136[4]; /*0x7fc376*/
      v62 = v136[5]; /*0x7fc37a*/
      dword_B46E18 = LODWORD(v136[0]); /*0x7fc381*/
      v63 = LODWORD(v115); /*0x7fc387*/
      *(float *)&v113 = v62; /*0x7fc38b*/
      v64 = v136[6]; /*0x7fc38f*/
      *(float *)&dword_B46E1C = v60; /*0x7fc396*/
      v65 = LODWORD(v112); /*0x7fc39b*/
      *(float *)&v114 = v64; /*0x7fc39f*/
      v66 = v136[7]; /*0x7fc3a3*/
      *(float *)&dword_B46E20 = v61; /*0x7fc3aa*/
      v67 = v113; /*0x7fc3b0*/
      v115 = v66; /*0x7fc3b4*/
      v68 = v136[8]; /*0x7fc3b8*/
      dword_B46E24 = v63; /*0x7fc3bf*/
      v69 = v114; /*0x7fc3c5*/
      v112 = v68; /*0x7fc3c9*/
      v70 = v136[9]; /*0x7fc3cd*/
      dword_B46E28 = v65; /*0x7fc3d4*/
      v71 = LODWORD(v115); /*0x7fc3d9*/
      *(float *)&v113 = v70; /*0x7fc3dd*/
      v72 = v136[0xA]; /*0x7fc3e1*/
      dword_B46E2C = v67; /*0x7fc3e8*/
      v73 = LODWORD(v112); /*0x7fc3ee*/
      *(float *)&v114 = v72; /*0x7fc3f2*/
      v74 = v136[0xB]; /*0x7fc3f6*/
      dword_B46E30 = v69; /*0x7fc3fd*/
      v75 = v113; /*0x7fc403*/
      v115 = v74; /*0x7fc407*/
      v76 = v136[0xC]; /*0x7fc40b*/
      dword_B46E34 = v71; /*0x7fc412*/
      v77 = v114; /*0x7fc417*/
      v112 = v76; /*0x7fc41b*/
      v78 = v136[0xD]; /*0x7fc41f*/
      dword_B46E38 = v73; /*0x7fc426*/
      v79 = LODWORD(v115); /*0x7fc42c*/
      *(float *)&v113 = v78; /*0x7fc430*/
      v80 = v136[0xE]; /*0x7fc434*/
      dword_B46E3C = v75; /*0x7fc43b*/
      v81 = LODWORD(v112); /*0x7fc441*/
      *(float *)&v114 = v80; /*0x7fc445*/
      v82 = v136[0xF]; /*0x7fc449*/
      dword_B46E40 = v77; /*0x7fc450*/
      v83 = v113; /*0x7fc455*/
      v115 = v82; /*0x7fc459*/
      dword_B46E44 = v79; /*0x7fc45d*/
      v84 = v114; /*0x7fc463*/
      dword_B46E48 = v81; /*0x7fc467*/
      v85 = LODWORD(v115); /*0x7fc46d*/
      dword_B46E4C = v83; /*0x7fc471*/
      v86 = LODWORD(flt_B44EE8); /*0x7fc476*/
      dword_B46E50 = v84; /*0x7fc47b*/
      v87 = LODWORD(flt_B44EEC); /*0x7fc481*/
      dword_B46E54 = v85; /*0x7fc487*/
      v88 = dword_B44EF0; /*0x7fc48d*/
      dword_B46E58 = v86; /*0x7fc493*/
      v89 = LODWORD(flt_B44EF4); /*0x7fc498*/
      dword_B46E5C = v87; /*0x7fc49d*/
      v90 = LODWORD(flt_B44EF8); /*0x7fc4a3*/
      dword_B46E60 = v88; /*0x7fc4a9*/
      v91 = LODWORD(flt_B44EFC); /*0x7fc4af*/
      dword_B46E64 = v89; /*0x7fc4b5*/
      dword_B46E68 = v90; /*0x7fc4ba*/
      dword_B46E6C = v91; /*0x7fc4c0*/
      v92 = LODWORD(flt_B44F04); /*0x7fc4cb*/
      v16 = a4; /*0x7fc4d1*/
      dword_B46E70 = dword_B44F00; /*0x7fc4d4*/
      dword_B46E74 = v92; /*0x7fc4d9*/
    }
    if ( HIBYTE(dword_B4697C) ) /*0x7fc4e5*/
    {
      if ( v16 ) /*0x7fc4f0*/
      {
        qmemcpy(v136, *((const void **)v16 + 0xA), 0x40u); /*0x7fc50c*/
        D3DXMatrixTranspose_0(v136, v136); /*0x7fc50e*/
        qmemcpy(&unk_B46E78, v136, 0x40u); /*0x7fc524*/
      }
    }
    device = dword_B43104->member.device; /*0x7fc530*/
    v172 = device; /*0x7fc53f*/
    if ( (unsigned int)(v123 - 0x14E) <= 3 ) /*0x7fc546*/
    {
      v94 = *(int **)(dword_B42EB8 + 0xC); /*0x7fc551*/
      v95 = *v94; /*0x7fc554*/
      v15 = *(_BYTE *)(*v94 + 0x214) == 0; /*0x7fc556*/
      v173 = *v94; /*0x7fc55d*/
      if ( v15 ) /*0x7fc564*/
      {
        v96 = (float *)(v95 + 0x150); /*0x7fc56e*/
        v97 = *(_DWORD *)(LODWORD(v120) + 0x14); /*0x7fc574*/
        qmemcpy(v136, (const void *)(v97 + 0x980), 0x40u); /*0x7fc589*/
        v98 = flt_B3F930; /*0x7fc592*/
        v99 = CameraWorldTranslate; /*0x7fc5ad*/
        v100 = flt_B3F934; /*0x7fc5db*/
        scale = v136[8] * v100 + v136[0] * v99 + v136[4] * v98; /*0x7fc5e4*/
        v136[0xC] = -scale; /*0x7fc5ee*/
        scale = v136[5] * v98 + v136[1] * v99 + v136[9] * v100; /*0x7fc614*/
        v136[0xD] = -scale; /*0x7fc61e*/
        scale = v99 * v136[2] + v98 * v136[6] + v100 * v136[0xA]; /*0x7fc644*/
        v136[0xE] = -scale; /*0x7fc64e*/
        qmemcpy(v174, (const void *)(v97 + 0x9C0), sizeof(v174)); /*0x7fc655*/
        D3DXMatrixMultiply_0(v135, v136, v174); /*0x7fc660*/
        D3DXMatrixInverse_0(v176, 0, v135); /*0x7fc674*/
        D3DXMatrixTranspose_0(v135, v176); /*0x7fc686*/
        LODWORD(v122) = &v175[4] - (char *)v96; /*0x7fc694*/
        v101 = 0; /*0x7fc69f*/
        v102 = v96; /*0x7fc6a3*/
        LODWORD(v120) = &v175[8] - (char *)v96; /*0x7fc6a5*/
        v123 = &v175[0xC] - (char *)v96; /*0x7fc6b2*/
        LODWORD(scale) = v175 - (char *)v96; /*0x7fc6bf*/
        do /*0x7fc764*/
        {
          v103 = v102[1]; /*0x7fc6c5*/
          v104 = v102[2]; /*0x7fc6c8*/
          v117 = *v102; /*0x7fc6cb*/
          v112 = v117; /*0x7fc6d3*/
          v118 = v103; /*0x7fc6d7*/
          v119 = v104; /*0x7fc6df*/
          *(float *)&v113 = v103; /*0x7fc6e3*/
          *(float *)&v114 = v104; /*0x7fc6f0*/
          v115 = -v102[3]; /*0x7fc6fc*/
          D3DXPlaneNormalize_0(&v112, &v112); /*0x7fc700*/
          D3DXPlaneTransform_0(&v127, &v112, v135); /*0x7fc714*/
          v105 = scale; /*0x7fc71d*/
          v106 = v122; /*0x7fc721*/
          *(float *)((char *)v102 + LODWORD(scale)) = v127; /*0x7fc725*/
          v107 = v120; /*0x7fc72c*/
          *(float *)((char *)v102 + LODWORD(v106)) = v128; /*0x7fc732*/
          v108 = v123; /*0x7fc739*/
          *(float *)((char *)v102 + LODWORD(v107)) = v129; /*0x7fc73d*/
          result = v130; /*0x7fc741*/
          *(float *)((char *)v102 + v108) = v130; /*0x7fc746*/
          v172->lpVtbl->SetClipPlane(v172, v101++, (float *)((char *)v102 + LODWORD(v105))); /*0x7fc759*/
          v102 += 4; /*0x7fc75e*/
        }
        while ( v101 < 6 ); /*0x7fc764*/
        v109 = (char *)(v173 + 0x1B4); /*0x7fc771*/
        *(_BYTE *)(v173 + 0x214) = 1; /*0x7fc783*/
        qmemcpy(v109, v175, 0x60u); /*0x7fc78a*/
      }
      else
      {
        v110 = (const float *)(v95 + 0x1B4); /*0x7fc797*/
        for ( i = 0; i < 6; ++i ) /*0x7fc79d*/
        {
          device->lpVtbl->SetClipPlane(device, i, v110); /*0x7fc7ab*/
          v110 += 4; /*0x7fc7b0*/
        }
      }
    }
  }
  return result; /*0x7fb807*/
}
