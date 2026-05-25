// 0x0080B7A0 @ 0x0080B7A0
int __thiscall sub_80B7A0(
        void *this,
        float *a2,
        const void **a3,
        int a4,
        int a5,
        int a6,
        int a7,
        NiTransform *a8,
        int a9)
{
  _DWORD *v9; // ebx
  int v10; // eax
  _DWORD *v11; // ebp
  float *v12; // eax
  int v13; // edx
  int v14; // ecx
  float *v15; // edi
  float *v16; // esi
  float *v17; // ebx
  double v18; // st7
  float *v19; // eax
  float v20; // ecx
  float v21; // edx
  float v22; // ecx
  float v23; // edx
  int v24; // eax
  double v25; // st7
  double v26; // st7
  float v27; // edx
  float v28; // ecx
  float v29; // eax
  float v30; // edx
  float v31; // ecx
  int v32; // edx
  void (__thiscall ***v33)(_DWORD, int); // ebp
  float *v34; // ebp
  float v35; // edx
  float v36; // eax
  double v37; // st6
  double v38; // st7
  double v39; // st5
  double v40; // st7
  double v41; // st6
  float v42; // ecx
  float v43; // edx
  double v44; // st6
  double v45; // st5
  double v46; // st4
  double v47; // st3
  double v48; // st2
  bool v49; // c0
  bool v50; // c3
  long double v51; // st2
  float v52; // ecx
  float v53; // edx
  int v54; // eax
  double v55; // st1
  long double v56; // st7
  double v57; // st2
  double v58; // st4
  double v59; // st6
  double v60; // rt2
  long double v61; // st4
  double v62; // st7
  double v63; // rt1
  double v64; // st7
  double v65; // st7
  float v66; // edx
  float v67; // eax
  double v68; // st7
  float v69; // ecx
  float *v70; // eax
  int v71; // eax
  bool v72; // zf
  int v74; // [esp+Ch] [ebp-F8h]
  void (__thiscall ***v75)(_DWORD, int); // [esp+Ch] [ebp-F8h]
  float v76; // [esp+Ch] [ebp-F8h]
  float v77; // [esp+Ch] [ebp-F8h]
  float v78; // [esp+10h] [ebp-F4h]
  float v79; // [esp+10h] [ebp-F4h]
  float v80; // [esp+10h] [ebp-F4h]
  float v81; // [esp+10h] [ebp-F4h]
  float v82; // [esp+10h] [ebp-F4h]
  float v83; // [esp+10h] [ebp-F4h]
  float v84; // [esp+10h] [ebp-F4h]
  float v85; // [esp+10h] [ebp-F4h]
  float v86; // [esp+14h] [ebp-F0h]
  float v87; // [esp+14h] [ebp-F0h]
  float v88; // [esp+14h] [ebp-F0h]
  float v89; // [esp+14h] [ebp-F0h]
  float v90; // [esp+18h] [ebp-ECh] BYREF
  float v91; // [esp+1Ch] [ebp-E8h]
  float v92; // [esp+20h] [ebp-E4h]
  float *v93; // [esp+24h] [ebp-E0h]
  float v94; // [esp+28h] [ebp-DCh]
  float v95; // [esp+2Ch] [ebp-D8h]
  float v96; // [esp+30h] [ebp-D4h]
  float v97; // [esp+34h] [ebp-D0h]
  float v98; // [esp+38h] [ebp-CCh] BYREF
  float v99; // [esp+3Ch] [ebp-C8h]
  float v100; // [esp+40h] [ebp-C4h]
  float v101; // [esp+44h] [ebp-C0h]
  float v102; // [esp+48h] [ebp-BCh]
  float v103; // [esp+4Ch] [ebp-B8h]
  float v104; // [esp+50h] [ebp-B4h] BYREF
  float v105; // [esp+54h] [ebp-B0h]
  float v106; // [esp+58h] [ebp-ACh]
  int v107; // [esp+5Ch] [ebp-A8h]
  float v108; // [esp+60h] [ebp-A4h]
  float v109; // [esp+64h] [ebp-A0h]
  float v110; // [esp+68h] [ebp-9Ch]
  int v111; // [esp+6Ch] [ebp-98h]
  float v112; // [esp+70h] [ebp-94h] BYREF
  float v113; // [esp+74h] [ebp-90h]
  float v114; // [esp+78h] [ebp-8Ch]
  float v115; // [esp+7Ch] [ebp-88h]
  float v116; // [esp+80h] [ebp-84h]
  float v117; // [esp+84h] [ebp-80h]
  float v118; // [esp+88h] [ebp-7Ch]
  float v119; // [esp+8Ch] [ebp-78h]
  float v120; // [esp+90h] [ebp-74h]
  float v121; // [esp+94h] [ebp-70h]
  float v122; // [esp+98h] [ebp-6Ch]
  float v123; // [esp+9Ch] [ebp-68h]
  int v124; // [esp+A0h] [ebp-64h] BYREF
  float v125; // [esp+A4h] [ebp-60h]
  float v126; // [esp+A8h] [ebp-5Ch]
  float v127; // [esp+ACh] [ebp-58h]
  float v128; // [esp+B0h] [ebp-54h]
  float v129; // [esp+B4h] [ebp-50h]
  float v130; // [esp+B8h] [ebp-4Ch]
  int v131; // [esp+BCh] [ebp-48h]
  _DWORD v132[2]; // [esp+C0h] [ebp-44h] BYREF
  float v133; // [esp+C8h] [ebp-3Ch]
  float v134; // [esp+CCh] [ebp-38h]
  float v135; // [esp+D0h] [ebp-34h]
  float v136; // [esp+D4h] [ebp-30h]
  float v137; // [esp+D8h] [ebp-2Ch]
  float v138; // [esp+DCh] [ebp-28h]
  float v139; // [esp+E0h] [ebp-24h]
  float v140; // [esp+E4h] [ebp-20h]
  float v141; // [esp+E8h] [ebp-1Ch]
  float v142; // [esp+ECh] [ebp-18h]
  _DWORD *v143; // [esp+F0h] [ebp-14h]
  float v144; // [esp+F4h] [ebp-10h]
  float v145; // [esp+F8h] [ebp-Ch]
  float v146; // [esp+FCh] [ebp-8h]
  int v147; // [esp+100h] [ebp-4h]

  v9 = *(_DWORD **)(a6 + 0x18); /*0x80b7ae*/
  v131 = (int)this; /*0x80b7b5*/
  v143 = v9; /*0x80b7bc*/
  if ( v9 && ShaderPackage >= 2 ) /*0x80b7d4*/
  {
    sub_7ED160(v9); /*0x80b7dc*/
    v10 = v9[7]; /*0x80b7e1*/
    v74 = 1; /*0x80b7ee*/
    if ( (v10 & 0x800) != 0 ) /*0x80b7f2*/
      v74 = 2; /*0x80b7f4*/
    if ( (v10 & 0x1000) != 0 ) /*0x80b7fd*/
      ++v74; /*0x80b7ff*/
    v11 = sub_7ED160(v9); /*0x80b80f*/
    v12 = a2; /*0x80b811*/
    v13 = *((int *)a2 + 0x23); /*0x80b81e*/
    v94 = a2[0x22]; /*0x80b824*/
    v14 = *((int *)a2 + 0x24); /*0x80b828*/
    v95 = *(float *)&v13; /*0x80b82e*/
    v96 = *(float *)&v14; /*0x80b832*/
    if ( v74 > 0 ) /*0x80b836*/
    {
      v15 = (float *)(v9 + 0x4A); /*0x80b847*/
      v16 = &flt_B46528; /*0x80b84d*/
      v93 = (float *)(v9 + 0x47); /*0x80b852*/
      v17 = (float *)(v9 + 0x3E); /*0x80b856*/
      v111 = v74; /*0x80b85c*/
      while ( 1 ) /*0x80b862*/
      {
        v18 = dbl_A2FC70; /*0x80b862*/
        if ( !v11 ) /*0x80b868*/
        {
          *v17 = Vector3_InitValue_; /*0x80bef3*/
          v70 = v93; /*0x80befb*/
          v17[1] = *(&Vector3_InitValue_ + 1); /*0x80beff*/
          v17[2] = dword_B3F9B0; /*0x80bf08*/
          *v70 = 0.0; /*0x80bf0b*/
          *(_DWORD *)v15 = dword_B25AD0; /*0x80bf13*/
          *((_DWORD *)v15 + 1) = dword_B25AD4; /*0x80bf1b*/
          *((_DWORD *)v15 + 2) = dword_B25AD8; /*0x80bf23*/
          *((_DWORD *)v15 + 3) = dword_B25ADC; /*0x80bf2c*/
          goto LABEL_45; /*0x80bf2c*/
        }
        if ( *((_BYTE *)v11 + 0xFC) ) /*0x80b86e*/
        {
          v19 = (float *)*sub_405AD0(v11, v132); /*0x80b888*/
          v20 = v19[0x23]; /*0x80b890*/
          v90 = v19[0x22]; /*0x80b896*/
          v21 = v19[0x24]; /*0x80b89a*/
          v91 = v20; /*0x80b8a9*/
          v92 = v21; /*0x80b8ad*/
          if ( v132[0] ) /*0x80b8b1*/
          {
            v75 = (void (__thiscall ***)(_DWORD, int))v132[0]; /*0x80b8b7*/
            if ( !InterlockedDecrement((volatile LONG *)(v132[0] + 4)) ) /*0x80b8bf*/
              (**v75)(v75, 1); /*0x80b8df*/
          }
        }
        else
        {
          v22 = v16[0x21]; /*0x80b8ec*/
          v23 = v16[0x22]; /*0x80b8f2*/
          v144 = v16[0x20]; /*0x80b8f8*/
          v145 = v22; /*0x80b908*/
          v146 = v23; /*0x80b90f*/
          v24 = *((_DWORD *)v16 + 0x23); /*0x80b916*/
          v115 = v144 * v18; /*0x80b91c*/
          v147 = v24; /*0x80b923*/
          v116 = v22 * v18; /*0x80b933*/
          v117 = v18 * v23; /*0x80b941*/
          v101 = v115 + v94; /*0x80b953*/
          v102 = v95 + v116; /*0x80b962*/
          v103 = v96 + v117; /*0x80b971*/
          *(float *)&v132[1] = v101; /*0x80b979*/
          v25 = v102; /*0x80b987*/
          *v16 = v101; /*0x80b98b*/
          v133 = v25; /*0x80b98d*/
          v26 = v103; /*0x80b99b*/
          v16[1] = v133; /*0x80b99f*/
          v27 = v101; /*0x80b9a2*/
          v134 = v26; /*0x80b9a6*/
          v135 = flt_A3F3D8; /*0x80b9ba*/
          v28 = v135; /*0x80b9c1*/
          v16[2] = v134; /*0x80b9c8*/
          v29 = v102; /*0x80b9cb*/
          v16[3] = v28; /*0x80b9cf*/
          v90 = v27; /*0x80b9d6*/
          v91 = v29; /*0x80b9da*/
          v92 = v103; /*0x80b9de*/
        }
        v30 = v16[0xFFFFFFE0]; /*0x80b9e5*/
        v31 = v16[0xFFFFFFE2]; /*0x80b9e8*/
        v105 = v16[0xFFFFFFE1]; /*0x80b9eb*/
        v104 = v30; /*0x80b9ef*/
        v32 = *((_DWORD *)v16 + 0xFFFFFFE3); /*0x80b9f3*/
        v106 = v31; /*0x80b9fd*/
        v107 = v32; /*0x80ba04*/
        v76 = *(float *)(*sub_405AD0(v11, &v124) + 0xF8); /*0x80ba1e*/
        if ( v124 ) /*0x80ba22*/
        {
          v33 = (void (__thiscall ***)(_DWORD, int))v124; /*0x80ba24*/
          if ( !InterlockedDecrement((volatile LONG *)(v124 + 4)) ) /*0x80ba2a*/
            (**v33)(v33, 1); /*0x80ba41*/
        }
        v34 = v93; /*0x80ba45*/
        if ( 0.0 == *v93 ) /*0x80ba51*/
        {
          v35 = v91; /*0x80ba5b*/
          v36 = v92; /*0x80ba5f*/
          *v17 = v90; /*0x80ba63*/
          v17[1] = v35; /*0x80ba65*/
          v17[2] = v36; /*0x80ba68*/
          *v34 = v76; /*0x80ba6b*/
        }
        else
        {
          if ( !sub_8AA390(v17, &v90) && v76 == *v34 && !sub_632310(v15, &v104) ) /*0x80baa1*/
            goto LABEL_43; /*0x80baa1*/
          v78 = v76 - *v34; /*0x80bab2*/
          v112 = v90 - v94; /*0x80babe*/
          v113 = v91 - v95; /*0x80baca*/
          v114 = v92 - v96; /*0x80bad6*/
          v97 = sub_43F350(&v112) / v76; /*0x80bae7*/
          v98 = *v17 - v94; /*0x80baf1*/
          v99 = v17[1] - v95; /*0x80bafc*/
          v100 = v17[2] - v96; /*0x80bb07*/
          sub_43F350(&v98); /*0x80bb0b*/
          v37 = v98; /*0x80bb20*/
          v108 = v112 - v98; /*0x80bb22*/
          v109 = v113 - v99; /*0x80bb36*/
          v110 = v114 - v100; /*0x80bb4a*/
          v38 = v100; /*0x80bb56*/
          v39 = v99; /*0x80bb5e*/
          v86 = v113 * v99 + v112 * v98 + v114 * v100; /*0x80bb60*/
          if ( v86 < dbl_A94368 ) /*0x80bb73*/
            goto LABEL_42; /*0x80bb73*/
          v87 = v108 * v108 + v109 * v109 + v110 * v110; /*0x80bb9b*/
          v88 = sqrt(v87); /*0x80bba8*/
          v40 = flt_A45FF4; /*0x80bbba*/
          if ( v40 < v88 ) /*0x80bbbf*/
          {
            v38 = v100; /*0x80bd5e*/
            v39 = v99; /*0x80bd60*/
            v37 = v98; /*0x80bd60*/
LABEL_42:
            v63 = dbl_A38538; /*0x80bd62*/
            v128 = v108 * v63; /*0x80bd70*/
            v129 = v109 * v63; /*0x80bd7d*/
            v130 = v63 * v110; /*0x80bd88*/
            v136 = v37 + v128; /*0x80bd9a*/
            v137 = v39 + v129; /*0x80bda8*/
            v138 = v38 + v130; /*0x80bdb6*/
            v118 = v136 * v97; /*0x80bdce*/
            v119 = v137 * v97; /*0x80bdde*/
            v120 = v97 * v138; /*0x80bdec*/
            v97 = *v34; /*0x80bdf6*/
            v121 = v118 * v97; /*0x80be0b*/
            v122 = v119 * v97; /*0x80be1b*/
            v123 = v97 * v120; /*0x80be29*/
            v125 = v121 + v94; /*0x80be3b*/
            v64 = v122; /*0x80be49*/
            *v17 = v125; /*0x80be50*/
            v126 = v64 + v95; /*0x80be56*/
            v65 = v123; /*0x80be64*/
            v17[1] = v126; /*0x80be6b*/
            v127 = v65 + v96; /*0x80be72*/
            v17[2] = v127; /*0x80be80*/
            goto LABEL_43; /*0x80be80*/
          }
          v41 = v78; /*0x80bbc5*/
          v42 = v91; /*0x80bbcd*/
          v43 = v92; /*0x80bbd3*/
          v79 = fabs(v78); /*0x80bbd9*/
          *v17 = v90; /*0x80bbdd*/
          v17[1] = v42; /*0x80bbe3*/
          v17[2] = v43; /*0x80bbe8*/
          if ( v79 <= v40 ) /*0x80bbf2*/
          {
            *v34 = v76; /*0x80bc0b*/
            v80 = v104 - *v15; /*0x80bc16*/
            v44 = v105; /*0x80bc1a*/
            v89 = v105 - v15[1]; /*0x80bc23*/
            v45 = v106; /*0x80bc27*/
            v77 = v106 - v15[2]; /*0x80bc30*/
            v46 = v80; /*0x80bc34*/
            v81 = fabs(v80); /*0x80bc3c*/
            v47 = v81; /*0x80bc40*/
            v48 = dbl_A2FC80; /*0x80bc44*/
            if ( v48 < v81 || (v82 = fabs(v89), v82 > v48) ) /*0x80bc6a*/
            {
              v51 = v89; /*0x80bcb1*/
LABEL_32:
              v55 = dbl_A30068; /*0x80bcb3*/
              if ( v55 >= v47 ) /*0x80bcc2*/
              {
                *v15 = v104; /*0x80bcdc*/
                v58 = dbl_A38538; /*0x80bce4*/
                v56 = v51; /*0x80bce6*/
              }
              else
              {
                v56 = v51; /*0x80bcc4*/
                v57 = v46 * dbl_A38538 + *v15; /*0x80bcd2*/
                v58 = dbl_A38538; /*0x80bcd2*/
                *v15 = v57; /*0x80bcd4*/
              }
              v84 = fabs(v56); /*0x80bcec*/
              if ( v84 <= v55 ) /*0x80bcfb*/
              {
                v15[1] = v44; /*0x80bd11*/
                v62 = v58; /*0x80bd16*/
                v59 = v55; /*0x80bd18*/
              }
              else
              {
                v59 = v55; /*0x80bcfd*/
                v60 = v58; /*0x80bd06*/
                v61 = v56 * v58 + v15[1]; /*0x80bd06*/
                v62 = v60; /*0x80bd06*/
                v15[1] = v61; /*0x80bd08*/
              }
              v85 = fabs(v77); /*0x80bd22*/
              if ( v85 <= v59 ) /*0x80bd33*/
                v15[2] = v45; /*0x80bd48*/
              else
                v15[2] = v62 * v77 + v15[2]; /*0x80bd3c*/
              goto LABEL_43; /*0x80bd3f*/
            }
            v83 = fabs(v77); /*0x80bc72*/
            v49 = v83 < v48; /*0x80bc7a*/
            v50 = v83 == v48; /*0x80bc7a*/
            v51 = v89; /*0x80bc7e*/
            if ( !v49 && !v50 ) /*0x80bc80*/
              goto LABEL_32; /*0x80bc83*/
            v52 = v105; /*0x80bc8b*/
            v53 = v106; /*0x80bc91*/
            *v15 = v104; /*0x80bc97*/
            v54 = v107; /*0x80bc9b*/
            v15[1] = v52; /*0x80bca1*/
            v15[2] = v53; /*0x80bca6*/
            *((_DWORD *)v15 + 3) = v54; /*0x80bca9*/
          }
          else
          {
            *v34 = v41 * dbl_A38538 + *v34; /*0x80bbfd*/
          }
        }
LABEL_43:
        v139 = *v17; /*0x80be83*/
        v140 = v17[1]; /*0x80be96*/
        v66 = v140; /*0x80be9d*/
        v141 = v17[2]; /*0x80bea7*/
        v67 = v141; /*0x80beae*/
        v68 = *v34; /*0x80beb5*/
        *v16 = v139; /*0x80beb8*/
        v16[1] = v66; /*0x80beba*/
        v142 = v68; /*0x80bebd*/
        v69 = v142; /*0x80bec4*/
        v16[2] = v67; /*0x80becb*/
        v16[3] = v69; /*0x80bece*/
        v16[0xFFFFFFE0] = *v15; /*0x80bed3*/
        v16[0xFFFFFFE1] = v15[1]; /*0x80bed9*/
        v16[0xFFFFFFE2] = v15[2]; /*0x80bedf*/
        v16[0xFFFFFFE3] = v15[3]; /*0x80bee5*/
LABEL_45:
        v71 = sub_7ED180(v143); /*0x80bf2f*/
        ++v93; /*0x80bf3b*/
        v17 += 3; /*0x80bf40*/
        v16 += 4; /*0x80bf43*/
        v15 += 4; /*0x80bf46*/
        v72 = v111-- == 1; /*0x80bf49*/
        v11 = (_DWORD *)v71; /*0x80bf4e*/
        if ( v72 ) /*0x80bf50*/
          goto LABEL_46; /*0x80bf50*/
      }
    }
  }
  else
  {
LABEL_46:
    v12 = a2; /*0x80bf57*/
  }
  return sub_7C9230(v131, (int)a3, *(float *)&v12, a3, a4, a5, a6, a7, a8, a9); /*0x80bfa3*/
}
