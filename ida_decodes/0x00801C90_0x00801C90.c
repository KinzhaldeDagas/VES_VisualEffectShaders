// 0x00801C90 @ 0x00801C90
// MoonSugarEffect decode: native pixel shader loader. Uses compiled cache when current, optionally upgrades ps_2_0 profile through sub_7B4780, compiles entry 'main', writes .pso cache, then calls CreatePixelShader.
NiD3DShaderProgram *__stdcall CreatePixelShader(
        char *lpFileName,
        _DWORD *a2,
        char *Str1,
        const char *a4,
        int a5,
        int a6)
{
  int v6; // esi
  char v7; // bl
  bool v8; // zf
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  int (__cdecl **v12)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // ebp
  int v13; // esi
  const char **v14; // ebx
  const char *v15; // eax
  const char *v16; // edx
  unsigned int v17; // eax
  char *v18; // edi
  char *v20; // edi
  const char *v21; // esi
  char v22; // cl
  const char *v23; // eax
  char *v24; // edi
  const char *v26; // ecx
  unsigned int v27; // eax
  const char *v28; // esi
  char *v29; // edi
  char *v31; // eax
  char v33; // cl
  const char *v34; // esi
  DWORD dwLowDateTime; // esi
  const char **v36; // ebp
  int v37; // ebx
  const char *v38; // eax
  const char *v39; // edx
  unsigned int v40; // eax
  char *v41; // edi
  char *v43; // edi
  const char *v44; // esi
  char v45; // cl
  const char *v46; // eax
  char *v47; // edi
  const char *v49; // ecx
  unsigned int v50; // eax
  const char *v51; // esi
  char *v52; // edi
  char *v54; // eax
  char v56; // cl
  const char *v57; // eax
  FILE *v58; // esi
  int v59; // eax
  const void *v60; // eax
  _DWORD *v61; // eax
  void (__cdecl *v62)(char *, _DWORD); // eax
  _BYTE *v63; // eax
  int (__cdecl **v64)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // esi
  int v65; // edi
  void *v66; // esi
  NiD3DShaderProgram *v67; // eax
  NiD3DShaderProgram *v68; // eax
  void (__thiscall *v69)(NiD3DShaderProgram *, int); // edx
  int v71; // [esp+10h] [ebp-DC0h]
  size_t v72; // [esp+14h] [ebp-DBCh]
  _BYTE v73[12]; // [esp+1Ch] [ebp-DB4h]
  int v74; // [esp+38h] [ebp-D98h]
  char TimeForFileOrContainer; // [esp+3Ah] [ebp-D96h]
  int Size; // [esp+3Ch] [ebp-D94h] BYREF
  int v77; // [esp+40h] [ebp-D90h] BYREF
  void *Src; // [esp+44h] [ebp-D8Ch]
  unsigned __int64 v79; // [esp+48h] [ebp-D88h] BYREF
  FILETIME v80; // [esp+50h] [ebp-D80h] BYREF
  const char *v81; // [esp+58h] [ebp-D78h]
  _DWORD *v82; // [esp+5Ch] [ebp-D74h]
  int v83; // [esp+60h] [ebp-D70h]
  const char *v84; // [esp+64h] [ebp-D6Ch]
  int v85; // [esp+68h] [ebp-D68h]
  _DWORD *v86; // [esp+6Ch] [ebp-D64h]
  NiD3DShaderProgram *v87; // [esp+70h] [ebp-D60h]
  int v88; // [esp+74h] [ebp-D5Ch]
  int v89; // [esp+78h] [ebp-D58h] BYREF
  int v90; // [esp+7Ch] [ebp-D54h] BYREF
  int v91; // [esp+80h] [ebp-D50h]
  void **v92; // [esp+84h] [ebp-D4Ch] BYREF
  char v93[4]; // [esp+88h] [ebp-D48h] BYREF
  char Filename[260]; // [esp+8Ch] [ebp-D44h] BYREF
  char v95[259]; // [esp+190h] [ebp-C40h] BYREF
  char v96; // [esp+293h] [ebp-B3Dh] BYREF
  char v97[1300]; // [esp+294h] [ebp-B3Ch] BYREF
  char v98[260]; // [esp+7A8h] [ebp-628h] BYREF
  char v99[1300]; // [esp+8ACh] [ebp-524h] BYREF
  unsigned int v100; // [esp+DCCh] [ebp-4h]

  v6 = 0; /*0x801cec*/
  v84 = lpFileName; /*0x801cf5*/
  v82 = a2; /*0x801cf9*/
  v85 = (int)a4; /*0x801cfd*/
  Size = 0; /*0x801d01*/
  v77 = 0; /*0x801d05*/
  v87 = 0; /*0x801d09*/
  v90 = 0; /*0x801d0d*/
  v83 = 0; /*0x801d11*/
  sub_801210(Filename, lpFileName, a4); /*0x801d15*/
  HIBYTE(v74) = 1; /*0x801d25*/
  if ( dword_B430B8 ) /*0x801d1a*/
    v6 = NiTMap_GetAtIndex((_DWORD *)dword_B430B8, (int)a4); /*0x801d32*/
  if ( byte_B2DD4C )
  {
    if ( !v6 )
    {
      v80 = 0; /*0x801d53*/
      v79 = 0; /*0x801d5b*/
      TimeForFileOrContainer = ArciveManager::GetTimeForFileOrContainer(lpFileName, &v80, 0x20); /*0x801d68*/
      v7 = ArciveManager::GetTimeForFileOrContainer(Filename, (FILETIME *)&v79, 0x20); /*0x801d7d*/
      if ( !v7 ) /*0x801d84*/
      {
        if ( useHardDriveCache ) /*0x801d86*/
        {
          if ( !&CacheOrNullString || !CacheOrNullString ) /*0x801d98*/
          {
            strcpy_toB42D80("cache:\\"); /*0x801da5*/
            sub_801210(Filename, lpFileName, (const char *)v85); /*0x801dba*/
          }
          v7 = ArciveManager::GetTimeForFileOrContainer(Filename, (FILETIME *)&v79, 0x20); /*0x801dd6*/
        }
      }
      if ( !TimeForFileOrContainer )
      {
        _sprintf(v95, "SHADER ERROR : error opening HLSL source file : %s", lpFileName);
        if ( dword_B42E8C ) /*0x801df2*/
          dword_B42E8C(v95, 0); /*0x801e08*/
      }
      if ( !v7 ) /*0x801e0f*/
        HIBYTE(v74) = 0; /*0x801e11*/
      if ( *(_QWORD *)&v80 > v79 ) /*0x801e2b*/
        HIBYTE(v74) = 0; /*0x801e2d*/
    }
  }
  BYTE2(v74) = 0; /*0x801e36*/
  Src = 0; /*0x801e3b*/
  if ( v6 ) /*0x801e3f*/
  {
    Src = (void *)(v6 + 0x104); /*0x801e47*/
    goto LABEL_79; /*0x801e4b*/
  }
  if ( HIBYTE(v74) )
  {
    v63 = sub_431130(Filename, 0, 0x2800, 0x20); /*0x8022d3*/
    v64 = (int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v63; /*0x8022d8*/
    if ( v63 ) /*0x8022df*/
    {
      if ( v63[0x24] ) /*0x8022e5*/
      {
        v65 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v63 + 0x1C))(v63); /*0x8022f4*/
        v83 = v65; /*0x8022f7*/
        Src = (void *)FormHeapAlloc(v65); /*0x802307*/
        BYTE2(v74) = 1; /*0x80230b*/
        ReadFile__(v64, (int)Src, v65); /*0x802310*/
      }
      (*(void (__thiscall **)(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD), int))*v64)(v64, 1); /*0x80231d*/
      goto LABEL_79; /*0x80231d*/
    }
    _sprintf(v95, "SHADER ERROR : error opening cache file : %s", Filename);
    v62 = (void (__cdecl *)(char *, _DWORD))dword_B42E8C; /*0x802419*/
    if ( !dword_B42E8C ) /*0x802423*/
      return 0; /*0x802423*/
LABEL_93:
    v62(v95, 0); /*0x802425*/
    return 0; /*0x80242f*/
  }
  v8 = UseHDR == 0; /*0x801e5b*/
  v86 = 0; /*0x801e62*/
  if ( !v8 ) /*0x801e66*/
  {
    v9 = v82; /*0x801e68*/
    if ( *v82 ) /*0x801e6c*/
    {
      v10 = v82 + 2; /*0x801e70*/
      do /*0x801e78*/
      {
        v9 = v10; /*0x801e73*/
        v10 += 2; /*0x801e75*/
      }
      while ( *v9 ); /*0x801e78*/
    }
    *v9 = &off_A6DFC0; /*0x801e7c*/
    v9[1] = EmptyString; /*0x801e82*/
    v86 = v9; /*0x801e89*/
  }
  *(_DWORD *)&v73[4] = 4; /*0x801e8d*/
  v81 = Str1; /*0x801e95*/
  if ( !strncmp(Str1, "ps_2_0", *(size_t *)&v73[4]) ) /*0x801e99*/
  {
    v81 = sub_7B4780(1); /*0x801eb1*/
    if ( !v81 ) /*0x801eb5*/
      v81 = Str1; /*0x801eb7*/
  }
  v11 = sub_431130(lpFileName, 0, 0x2800, 0x20); /*0x801ec7*/
  v12 = (int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v11; /*0x801ecc*/
  if ( !v11 )
  {
LABEL_73:
    _sprintf(v95, "SHADER ERROR : error opening hlsl file : %s", lpFileName);
    v62 = (void (__cdecl *)(char *, _DWORD))dword_B42E8C; /*0x8022a6*/
    if ( !dword_B42E8C ) /*0x8022b0*/
      return 0; /*0x8022b0*/
    goto LABEL_93; /*0x8022b0*/
  }
  if ( !v11[0x24] ) /*0x801edf*/
  {
    (**(void (__thiscall ***)(_BYTE *, int))v11)(v11, 1); /*0x802291*/
    goto LABEL_73; /*0x802291*/
  }
  v13 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)v11 + 0x1C))(v11); /*0x801eed*/
  v91 = v13; /*0x801ef0*/
  v80.dwLowDateTime = FormHeapAlloc(v13); /*0x801f00*/
  ReadFile__(v12, v80.dwLowDateTime, v13); /*0x801f04*/
  v14 = (const char **)(v82 + 1); /*0x801f0d*/
  v92 = &ShaderIncludes::`vftable'; /*0x801f10*/
  *(_DWORD *)v93 = lpFileName; /*0x801f18*/
  v97[0] = 0; /*0x801f1c*/
  v88 = 0; /*0x801f24*/
  LODWORD(v79) = v82 + 1; /*0x801f2c*/
  do /*0x80200e*/
  {
    v15 = v14[0xFFFFFFFF]; /*0x801f30*/
    if ( !v15 ) /*0x801f35*/
      break; /*0x801f35*/
    v16 = v14[0xFFFFFFFF]; /*0x801f3b*/
    v17 = &v15[strlen(v15) + 1] - v16; /*0x801f50*/
    v18 = &v96; /*0x801f52*/
    while ( *++v18 ) /*0x801f5d*/
      ; /*0x801f55*/
    qmemcpy(v18, v16, 4 * (v17 >> 2)); /*0x801f66*/
    v21 = &v16[4 * (v17 >> 2)]; /*0x801f66*/
    v20 = &v18[4 * (v17 >> 2)]; /*0x801f66*/
    v22 = v17; /*0x801f68*/
    v23 = *v14; /*0x801f6a*/
    v8 = *v14 == 0; /*0x801f6f*/
    qmemcpy(v20, v21, v22 & 3); /*0x801f71*/
    if ( !v8 ) /*0x801f73*/
    {
      if ( *v23 ) /*0x801f75*/
      {
        v24 = &v96; /*0x801f81*/
        while ( *++v24 ) /*0x801f8c*/
          ; /*0x801f84*/
        *(_WORD *)v24 = word_A61F44; /*0x801f95*/
        v26 = v23; /*0x801f98*/
        v27 = strlen(v23) + 1; /*0x801fb0*/
        v28 = v26; /*0x801fb2*/
        v29 = &v96; /*0x801fb4*/
        while ( *++v29 ) /*0x801fbf*/
          ; /*0x801fb7*/
        qmemcpy(v29, v28, v27); /*0x801fc6*/
      }
    }
    v31 = &v96; /*0x801fd6*/
    while ( *++v31 ) /*0x801fe8*/
      ; /*0x801fe0*/
    v33 = byte_A36132; /*0x801ff1*/
    *(_WORD *)v31 = word_A36130; /*0x801ff7*/
    v31[2] = v33; /*0x801ffa*/
    v14 += 2; /*0x802004*/
    ++v88; /*0x80200a*/
  }
  while ( v88 < 8 ); /*0x80200e*/
  v34 = v81; /*0x802014*/
  _sprintf(v99, "compiling : %s\n %s %s", v84, v81, v97);
  if ( dword_B42E8C ) /*0x802038*/
    dword_B42E8C(v99, 0); /*0x80204e*/
  v71 = (int)v34; /*0x80206c*/
  dwLowDateTime = v80.dwLowDateTime; /*0x80206d*/
  v80.dwLowDateTime = D3DXCompileShader_0( /*0x802083*/
                        v80.dwLowDateTime,
                        v91,
                        (int)v82,
                        (int)&v92,
                        (int)"main",
                        v71,
                        0,
                        (int)&Size,
                        (int)&v77,
                        (int)&v90);
  (*(void (__thiscall **)(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD), int))*v12)(v12, 1); /*0x802090*/
  FormHeapFree(dwLowDateTime); /*0x802093*/
  if ( v77 ) /*0x8020a0*/
  {
    if ( !Size ) /*0x8020ab*/
    {
      v36 = (const char **)v79; /*0x8020b1*/
      v97[0] = 0; /*0x8020b5*/
      v37 = 8; /*0x8020bd*/
      do /*0x802193*/
      {
        v38 = v36[0xFFFFFFFF]; /*0x8020c2*/
        if ( v38 ) /*0x8020c7*/
        {
          v39 = v36[0xFFFFFFFF]; /*0x8020cd*/
          v40 = &v38[strlen(v38) + 1] - v39; /*0x8020e0*/
          v41 = &v96; /*0x8020e2*/
          while ( *++v41 ) /*0x8020ed*/
            ; /*0x8020e5*/
          qmemcpy(v41, v39, 4 * (v40 >> 2)); /*0x8020f6*/
          v44 = &v39[4 * (v40 >> 2)]; /*0x8020f6*/
          v43 = &v41[4 * (v40 >> 2)]; /*0x8020f6*/
          v45 = v40; /*0x8020f8*/
          v46 = *v36; /*0x8020fa*/
          v8 = *v36 == 0; /*0x802100*/
          qmemcpy(v43, v44, v45 & 3); /*0x802102*/
          if ( !v8 ) /*0x802104*/
          {
            if ( *v46 ) /*0x802106*/
            {
              v47 = &v96; /*0x802112*/
              while ( *++v47 ) /*0x80211d*/
                ; /*0x802115*/
              *(_WORD *)v47 = word_A61F44; /*0x802126*/
              v49 = v46; /*0x802129*/
              v50 = strlen(v46) + 1; /*0x802140*/
              v51 = v49; /*0x802142*/
              v52 = &v96; /*0x802144*/
              while ( *++v52 ) /*0x80214f*/
                ; /*0x802147*/
              qmemcpy(v52, v51, v50); /*0x802156*/
            }
          }
          v54 = &v96; /*0x802166*/
          while ( *++v54 ) /*0x802178*/
            ; /*0x802170*/
          v56 = byte_A36132; /*0x802181*/
          *(_WORD *)v54 = word_A36130; /*0x802187*/
          v54[2] = v56; /*0x80218a*/
        }
        v36 += 2; /*0x80218d*/
        --v37; /*0x802190*/
      }
      while ( v37 ); /*0x802193*/
      v57 = (const char *)(*(int (__stdcall **)(int))(*(_DWORD *)v77 + 0xC))(v77); /*0x8021a3*/
      _sprintf(v99, "%s\n %s\n %s", v84, v97, v57); /*0x8021c0*/
      if ( dword_B42E8C ) /*0x8021c5*/
        dword_B42E8C(v99, 0); /*0x8021db*/
      (*(void (__stdcall **)(int))(*(_DWORD *)v77 + 8))(v77); /*0x8021ea*/
      v77 = 0; /*0x8021ec*/
    }
  }
  if ( v80.dwLowDateTime ) /*0x8021f9*/
    return 0; /*0x8021f9*/
  if ( Size ) /*0x802204*/
  {
    v58 = fopen(Filename, "wb"); /*0x802215*/
    v59 = (*(int (__stdcall **)(int))(*(_DWORD *)Size + 0x10))(Size); /*0x802224*/
    *(_DWORD *)&v73[4] = v58; /*0x802226*/
    *(_DWORD *)v73 = 1; /*0x802227*/
    v83 = v59; /*0x80222a*/
    v72 = __PAIR64__(v59, Size); /*0x802237*/
    v60 = (const void *)(*(int (**)(void))(*(_DWORD *)Size + 0xC))(); /*0x802238*/
    fwrite(v60, v72, *(size_t *)v73, *(FILE **)&v73[8]); /*0x80223b*/
    fflush(v58); /*0x802241*/
    fclose(v58); /*0x802247*/
    sub_42E800(v93); /*0x802254*/
    Src = (void *)(*(int (__stdcall **)(int, _DWORD))(*(_DWORD *)v74 + 0xC))(v74, *(_DWORD *)&v73[4]); /*0x802268*/
  }
  v61 = v86; /*0x80226c*/
  if ( v86 ) /*0x802272*/
  {
    *v86 = 0; /*0x802278*/
    v61[1] = 0; /*0x80227e*/
  }
LABEL_79:
  v66 = Src; /*0x80231f*/
  if ( Src )
  {
    if ( dword_B430B4 ) /*0x80232b*/
    {
      *(_DWORD *)&v73[4] = v83; /*0x80233d*/
      sub_7DAF50((unsigned __int16 *)dword_B430B4, (char *)v85, Src, *(size_t *)&v73[4]); /*0x802340*/
      goto LABEL_89; /*0x802345*/
    }
    if ( !dword_B43104->member.device->lpVtbl->CreatePixelShader(dword_B43104->member.device, Src, &v89) ) /*0x802368*/
    {
      v67 = (NiD3DShaderProgram *)FormHeapAlloc(0x2Cu); /*0x8023a2*/
      LODWORD(v79) = v67; /*0x8023aa*/
      v100 = 0; /*0x8023b0*/
      if ( v67 ) /*0x8023bb*/
        v68 = sub_780B90(v67, (int)dword_B43104); /*0x8023c6*/
      else
        v68 = 0; /*0x8023cd*/
      v69 = *(void (__thiscall **)(NiD3DShaderProgram *, int))(*(_DWORD *)v68 + 0x3C); /*0x8023d5*/
      v100 = 0xFFFFFFFF; /*0x8023db*/
      v87 = v68; /*0x8023e6*/
      v69(v68, v89); /*0x8023ea*/
      goto LABEL_89; /*0x8023ea*/
    }
    _sprintf(v98, "SHADER ERROR : failed to create pixel shader : %s", Filename);
    if ( dword_B42E8C ) /*0x802381*/
      dword_B42E8C(v98, 0); /*0x80239b*/
    return 0; /*0x802434*/
  }
LABEL_89:
  if ( BYTE2(v74) ) /*0x8023f1*/
    FormHeapFree((unsigned int)v66); /*0x8023f4*/
  return v87; /*0x802436*/
}
