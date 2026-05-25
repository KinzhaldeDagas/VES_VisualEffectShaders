// 0x7AD270 @ 0x7AD270
// MoonSugarEffect decode: BSShaderAccumulator per-geometry enqueue entry (+0x58) used when culling has no VisibleGeo array. This is the normal accumulator-direct path for visible geometry.
void __userpurge sub_7AD270(
        int a1@<ecx>,
        int a2@<edi>,
        NiGeometry *a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15)
{
  volatile LONG *v15; // esi
  int v17; // eax
  volatile LONG *v18; // edi
  _DWORD *v19; // eax
  bool v20; // zf
  int v21; // ecx
  BSShaderProperty *v22; // ebp
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int (__thiscall *v27)(BSShaderProperty *, float *, int, float *, int); // edx
  int v28; // eax
  _DWORD *v29; // esi
  _WORD *v30; // eax
  _DWORD *v31; // esi
  int v32; // ecx
  int (__thiscall *v33)(BSShaderProperty *, float *, int, float *, int); // edx
  int v34; // eax
  _DWORD *v35; // esi
  unsigned __int16 *v36; // eax
  int (__thiscall *v37)(BSShaderProperty *, float *, int, volatile LONG **, int); // edx
  int v38; // eax
  void **v39; // esi
  _DWORD *v40; // edi
  BSTextureManager *v41; // ecx
  _DWORD **v42; // esi
  int v43; // edx
  int (__thiscall *v44)(BSShaderProperty *, float *, int, float *, int); // edx
  int v45; // eax
  void *i; // esi
  _DWORD *v47; // edi
  BSTextureManager *v48; // ecx
  int start; // eax
  int ShadowSceneNode; // eax
  char v51; // al
  int (__thiscall *v52)(BSShaderProperty *, float *, int, volatile LONG **, int); // edx
  _DWORD *v53; // eax
  NiObject *j; // esi
  int v55; // eax
  int v56; // eax
  int v57; // esi
  BSShader *v58; // edi
  int v59; // eax
  int v60; // ebp
  _DWORD *v61; // edx
  unsigned __int16 v62; // si
  _DWORD *v63; // ecx
  int *v64; // eax
  volatile LONG *v65; // edi
  int v66; // edi
  float *v67; // eax
  float v68; // edx
  float v69; // ecx
  float v70; // edx
  int v71; // eax
  float v72; // ecx
  float v73; // edx
  double v74; // st7
  float v75; // edx
  double v76; // st7
  float v77; // eax
  float v78; // ecx
  float v79; // edx
  int v80; // ecx
  double v81; // st6
  int v82; // eax
  double v83; // st6
  int v84; // ecx
  double v85; // st6
  int v86; // edx
  int v87; // eax
  int v88; // ecx
  int v89; // ecx
  int v90; // eax
  _DWORD *v91; // eax
  int v92; // [esp-Eh] [ebp-9Ch]
  int v93; // [esp-Eh] [ebp-9Ch]
  int v94; // [esp-Eh] [ebp-9Ch]
  int v95; // [esp-Eh] [ebp-9Ch]
  int v96; // [esp-Eh] [ebp-9Ch]
  char v97; // [esp+1h] [ebp-8Dh]
  _DWORD *v98; // [esp+2h] [ebp-8Ch]
  int v99; // [esp+6h] [ebp-88h] BYREF
  int v100; // [esp+Ah] [ebp-84h]
  void *v101[2]; // [esp+Eh] [ebp-80h] BYREF
  volatile LONG *v102; // [esp+16h] [ebp-78h] BYREF
  float v103; // [esp+1Ah] [ebp-74h] BYREF
  int v104; // [esp+1Eh] [ebp-70h]
  volatile LONG *v105; // [esp+22h] [ebp-6Ch] BYREF
  float v106; // [esp+26h] [ebp-68h]
  float v107; // [esp+2Ah] [ebp-64h]
  float v108; // [esp+2Eh] [ebp-60h]
  float v109; // [esp+32h] [ebp-5Ch]
  float v110; // [esp+36h] [ebp-58h]
  float v111; // [esp+3Ah] [ebp-54h]
  float v112[3]; // [esp+3Eh] [ebp-50h] BYREF
  float v113; // [esp+4Ah] [ebp-44h]
  float v114; // [esp+4Eh] [ebp-40h]
  float v115; // [esp+52h] [ebp-3Ch]
  float v116; // [esp+56h] [ebp-38h]
  int v117; // [esp+5Ah] [ebp-34h]
  int v118; // [esp+5Eh] [ebp-30h]
  float v119; // [esp+62h] [ebp-2Ch]
  int v120; // [esp+66h] [ebp-28h]
  int v121; // [esp+6Ah] [ebp-24h]
  int v122; // [esp+6Eh] [ebp-20h]
  int v123; // [esp+72h] [ebp-1Ch]
  int v124; // [esp+76h] [ebp-18h]
  int v125; // [esp+7Eh] [ebp-10h]
  float *retaddr; // [esp+8Eh] [ebp+0h] BYREF

  v15 = (volatile LONG *)a3; /*0x7ad27c*/
  if ( !byte_B42CDA ) /*0x7ad273*/
    goto LABEL_178; /*0x7ad273*/
  if ( byte_B42CDB ) /*0x7ad287*/
  {
    if ( !a3 ) /*0x7ad292*/
      return; /*0x7ad292*/
    v17 = (int)a3->__vftable->super.super.GetType((NiObject *)a3); /*0x7ad29f*/
    if ( !v17 ) /*0x7ad2a3*/
      return; /*0x7ad2a3*/
    while ( (char *)v17 != dword_B3FCDC ) /*0x7ad2b5*/
    {
      v17 = *(_DWORD *)(v17 + 4); /*0x7ad2b7*/
      if ( !v17 ) /*0x7ad2bc*/
        return; /*0x7ad2bc*/
    }
  }
  if ( !byte_B42CDA ) /*0x7ad2c8*/
  {
LABEL_178:
    if ( byte_B42CDB ) /*0x7ad2d1*/
      sub_7AB6F0((_DWORD *)a1); /*0x7ad2dc*/
  }
  if ( !*(_BYTE *)(a1 + 0x2268) && !byte_B42CE8 ) /*0x7ad2ea*/
    *(_BYTE *)(a1 + 0x2268) = 1; /*0x7ad2f3*/
  v99 = a2; /*0x7ad2fa*/
  v18 = *sub_405760(a3, &v105); /*0x7ad307*/
  if ( v105 ) /*0x7ad30f*/
  {
    v15 = v105; /*0x7ad311*/
    if ( !InterlockedDecrement(v105 + 1) ) /*0x7ad317*/
      (**(void (__thiscall ***)(volatile LONG *, int, int))v15)(v15, 1, v99); /*0x7ad32d*/
  }
  if ( !v18 ) /*0x7ad331*/
  {
    v19 = sub_7ABC40((_DWORD *)a1, 0, (int)v15); /*0x7ad33d*/
    sub_7ABDE0(v19, (int *)&retaddr); /*0x7ad344*/
    return; /*0x7ad351*/
  }
  v20 = byte_B42CE3 == 0; /*0x7ad354*/
  v21 = *((_DWORD *)retaddr + 0x2F); /*0x7ad362*/
  v22 = *((BSShaderProperty **)v18 + 6); /*0x7ad369*/
  v103 = *(float *)&v22; /*0x7ad36c*/
  if ( v20 ) /*0x7ad370*/
  {
    if ( !v21 ) /*0x7ad428*/
      goto LABEL_24; /*0x7ad428*/
  }
  else
  {
    v23 = *((_DWORD *)v18 + 8); /*0x7ad378*/
    if ( !v21 ) /*0x7ad37b*/
    {
      if ( !v23 ) /*0x7ad383*/
        return; /*0x7ad383*/
      v24 = **(_DWORD **)(v23 + 0x20); /*0x7ad38c*/
      if ( !v24 || !*(_DWORD *)(v24 + 8) ) /*0x7ad396*/
        return; /*0x7ad399*/
LABEL_24:
      if ( *(_BYTE *)(a1 + 0x21E0) ) /*0x7ad39f*/
      {
        v25 = *((_DWORD *)v18 + 2); /*0x7ad3ac*/
        if ( (*(_BYTE *)(v25 + 0x18) & 1) == 0 || *(_BYTE *)(a1 + 0x34) && (*(_WORD *)(v25 + 0x18) & 0x2000) != 0 ) /*0x7ad3ca*/
        {
          if ( LOWORD(dword_B42EAC) != 6 ) /*0x7adf89*/
          {
            v91 = sub_7ABC40((_DWORD *)a1, (int)v18, (int)v15); /*0x7adf95*/
            sub_7ABDE0(v91, (int *)&retaddr); /*0x7adf9c*/
          }
        }
        else if ( byte_B42CE3 ) /*0x7ad3d0*/
        {
          sub_5B1E20((BSTextureManager *)(a1 + 0xC), (void **)&retaddr); /*0x7adf70*/
        }
        else if ( byte_B42CE1 && (double)dword_B42CE4 > retaddr[0xA] ) /*0x7ad401*/
        {
          sub_5B1E20((BSTextureManager *)(a1 + 0x2254), (void **)&retaddr); /*0x7ad415*/
        }
        else
        {
          sub_5B1E20((BSTextureManager *)(a1 + 0x2244), (void **)&retaddr); /*0x7adf54*/
        }
      }
      else
      {
        (*(void (__thiscall **)(float *, NiDX9Renderer *))(*(_DWORD *)retaddr + 0x84))(retaddr, g_Renderer); /*0x7adfc2*/
      }
      return; /*0x7ad423*/
    }
  }
  if ( *(float *)&v22 == 0.0 ) /*0x7ad430*/
    goto LABEL_24; /*0x7ad430*/
  v15 = (volatile LONG *)(*(int (__thiscall **)(int))(*(_DWORD *)v21 + 0x1C))(v21); /*0x7ad440*/
  v26 = (*((int (__thiscall **)(BSShaderProperty *))v22->vtbl + 0x15))(v22); /*0x7ad447*/
  if ( v15 == (volatile LONG *)0x16 ) /*0x7ad44c*/
  {
    if ( v26 == 0xB ) /*0x7ad455*/
    {
      v27 = *((int (__thiscall **)(BSShaderProperty *, float *, int, float *, int))v22->vtbl + 0x17); /*0x7ad464*/
      v92 = dword_B42F40; /*0x7ad475*/
      v103 = 0.0; /*0x7ad479*/
      v28 = *(_DWORD *)(v27(v22, retaddr, v92, &v103, 1) + 4); /*0x7ad483*/
      v29 = *(_DWORD **)v28; /*0x7ad486*/
      v30 = *(_WORD **)(v28 + 8); /*0x7ad48b*/
      for ( v101[0] = v30; v30; v101[0] = v30 ) /*0x7ad493*/
      {
        if ( byte_B42CE8 ) /*0x7ad4a0*/
        {
          if ( v30[2] == 0x17D ) /*0x7ad4ad*/
            sub_7A9820(v30, 0x17Du); /*0x7ad4b3*/
        }
        else
        {
          sub_7ABDE0((_DWORD *)(a1 + 0x14 * ((unsigned __int16)v30[2] + 0xD)), (int *)v101); /*0x7ad4cc*/
        }
        if ( !v29 ) /*0x7ad4d3*/
          break; /*0x7ad4d3*/
        v30 = (_WORD *)v29[2]; /*0x7ad4d8*/
        v29 = (_DWORD *)*v29; /*0x7ad4dc*/
      }
      v31 = (_DWORD *)v125; /*0x7ad4e4*/
      ++dword_B42CD0; /*0x7ad4eb*/
      if ( !(*(int (__thiscall **)(_DWORD *))(*v31 + 0x10))(v31) ) /*0x7ad4fd*/
        return; /*0x7ad4fd*/
      v32 = v31[0x2D]; /*0x7ad503*/
LABEL_45:
      dword_B42CC4 += (*(unsigned __int16 (__thiscall **)(int))(*(_DWORD *)v32 + 0x5C))(v32); /*0x7ad509*/
      return; /*0x7ad525*/
    }
    goto LABEL_89; /*0x7ad455*/
  }
  if ( v15 != (volatile LONG *)0x18 ) /*0x7ad52b*/
  {
    if ( v15 == (volatile LONG *)0x19 ) /*0x7ad5c4*/
    {
      if ( v26 != 0xE ) /*0x7ad5cd*/
        goto LABEL_89; /*0x7ad5cd*/
      if ( !*(_BYTE *)(a1 + 0x21E3) ) /*0x7ad5da*/
        return; /*0x7ad5da*/
      v37 = *((int (__thiscall **)(BSShaderProperty *, float *, int, volatile LONG **, int))v22->vtbl + 0x17); /*0x7ad5e9*/
      v94 = dword_B42F40; /*0x7ad5fa*/
      v102 = 0; /*0x7ad5fe*/
      v38 = *(_DWORD *)(v37(v22, retaddr, v94, &v102, 1) + 4); /*0x7ad608*/
      v40 = *(_DWORD **)v38; /*0x7ad610*/
      v101[0] = *(void **)(v38 + 8); /*0x7ad615*/
      v39 = (void **)v101[0]; /*0x7ad60b*/
      if ( v101[0] ) /*0x7ad619*/
      {
        while ( 1 ) /*0x7ad624*/
        {
          if ( *(_DWORD *)(v100 + 0x108) == 8 ) /*0x7ad62e*/
          {
            sub_7AD1C0((_DWORD *)(a1 + 0xA4), (int)v39); /*0x7ad63a*/
            goto LABEL_70; /*0x7ad63f*/
          }
          sub_5B1E20((BSTextureManager *)(a1 + 0x21C0), v101); /*0x7ad64c*/
          if ( byte_B42CE3 ) /*0x7ad651*/
          {
            v41 = (BSTextureManager *)(a1 + 0xC); /*0x7ad6ad*/
            goto LABEL_69; /*0x7ad6ad*/
          }
          if ( *(_DWORD *)(v100 + 0x108) != 8 ) /*0x7ad664*/
            break; /*0x7ad664*/
          if ( !byte_B42CE1 || !byte_B42CE2 ) /*0x7ad66f*/
            goto LABEL_64; /*0x7ad676*/
          v41 = (BSTextureManager *)(a1 + 0x2254); /*0x7ad678*/
LABEL_69:
          sub_5B1E20(v41, v39); /*0x7ad6b0*/
LABEL_70:
          if ( v40 ) /*0x7ad6b8*/
          {
            v39 = (void **)v40[2]; /*0x7ad6ba*/
            v40 = (_DWORD *)*v40; /*0x7ad6c2*/
            v101[0] = v39; /*0x7ad6c4*/
            if ( v39 ) /*0x7ad6c8*/
              continue; /*0x7ad6c8*/
          }
          goto LABEL_72; /*0x7ad6c8*/
        }
        if ( byte_B42CE1 && (double)dword_B42CE4 > *((float *)*v39 + 0xA) ) /*0x7ad6a3*/
        {
          v41 = (BSTextureManager *)(a1 + 0x2254); /*0x7ad6a5*/
          goto LABEL_69; /*0x7ad6ab*/
        }
LABEL_64:
        v41 = (BSTextureManager *)(a1 + 0x2244); /*0x7ad680*/
        goto LABEL_69; /*0x7ad686*/
      }
    }
    else
    {
      if ( v15 != (volatile LONG *)0x1A ) /*0x7ad715*/
      {
        if ( (int)v15 <= (int)0xFFFFFFFF ) /*0x7ad7e1*/
          goto LABEL_24; /*0x7ad7e1*/
        goto LABEL_89; /*0x7ad7e1*/
      }
      if ( v26 != 0xD ) /*0x7ad71e*/
        goto LABEL_89; /*0x7ad71e*/
      if ( !*(_BYTE *)(a1 + 0x21E3) ) /*0x7ad72b*/
        return; /*0x7ad72b*/
      v44 = *((int (__thiscall **)(BSShaderProperty *, float *, int, float *, int))v22->vtbl + 0x17); /*0x7ad73a*/
      v95 = dword_B42F40; /*0x7ad74b*/
      v103 = 0.0; /*0x7ad74f*/
      v45 = *(_DWORD *)(v44(v22, retaddr, v95, &v103, 1) + 4); /*0x7ad759*/
      v47 = *(_DWORD **)v45; /*0x7ad761*/
      v101[0] = *(void **)(v45 + 8); /*0x7ad766*/
      for ( i = v101[0]; i; v101[0] = i ) /*0x7ad76a*/
      {
        sub_5B1E20((BSTextureManager *)(a1 + 0x21C0), v101); /*0x7ad77d*/
        if ( byte_B42CE3 ) /*0x7ad782*/
        {
          v48 = (BSTextureManager *)(a1 + 0xC); /*0x7ad7b8*/
        }
        else if ( byte_B42CE1 && (double)dword_B42CE4 > *(float *)(*(_DWORD *)i + 0x28) ) /*0x7ad7a6*/
        {
          v48 = (BSTextureManager *)(a1 + 0x2254); /*0x7ad7a8*/
        }
        else
        {
          v48 = (BSTextureManager *)(a1 + 0x2244); /*0x7ad7b0*/
        }
        sub_5B1E20(v48, (void **)i); /*0x7ad7bc*/
        if ( !v47 ) /*0x7ad7c3*/
          break; /*0x7ad7c3*/
        i = (void *)v47[2]; /*0x7ad7c9*/
        v47 = (_DWORD *)*v47; /*0x7ad7d1*/
      }
    }
LABEL_72:
    v42 = (_DWORD **)v125; /*0x7ad6ce*/
    ++dword_B42CD0; /*0x7ad6d5*/
    if ( !((int (__thiscall *)(_DWORD **))(*v42)[4])(v42) ) /*0x7ad6e7*/
      return; /*0x7ad6e7*/
    v43 = *v42[0x2D]; /*0x7ad6f3*/
    goto LABEL_74; /*0x7ad6f3*/
  }
  if ( v26 == 0xC ) /*0x7ad534*/
  {
    v33 = *((int (__thiscall **)(BSShaderProperty *, float *, int, float *, int))v22->vtbl + 0x17); /*0x7ad54a*/
    v93 = dword_B42F40; /*0x7ad554*/
    v103 = 0.0; /*0x7ad558*/
    v34 = *(_DWORD *)(v33(v22, retaddr, v93, &v103, 1) + 4); /*0x7ad562*/
    v35 = *(_DWORD **)v34; /*0x7ad565*/
    v36 = *(unsigned __int16 **)(v34 + 8); /*0x7ad56a*/
    for ( v101[0] = v36; v36; v101[0] = v36 ) /*0x7ad572*/
    {
      sub_7ABDE0((_DWORD *)(a1 + 0x14 * (v36[2] + 0xD)), (int *)v101); /*0x7ad586*/
      if ( !v35 ) /*0x7ad58d*/
        break; /*0x7ad58d*/
      v36 = (unsigned __int16 *)v35[2]; /*0x7ad592*/
      v35 = (_DWORD *)*v35; /*0x7ad596*/
    }
    ++dword_B42CD0; /*0x7ad59e*/
    if ( (*(int (__thiscall **)(float *))(*(_DWORD *)retaddr + 0x10))(retaddr) ) /*0x7ad5ac*/
    {
      v32 = *((_DWORD *)retaddr + 0x2D); /*0x7ad5b6*/
      goto LABEL_45; /*0x7ad5bc*/
    }
    return; /*0x7ad5b0*/
  }
LABEL_89:
  if ( v26 < 1 ) /*0x7ad7ea*/
    goto LABEL_24; /*0x7ad7ea*/
  start = (int)v22[1].member.passes.start; /*0x7ad7f0*/
  if ( !start || !sub_7AA3C0(a1, start, 1) ) /*0x7ad7ff*/
  {
    v20 = *((_BYTE *)retaddr + 0x18) >> 7 == 0; /*0x7ad81c*/
    v109 = *((float *)v18 + 2); /*0x7ad81e*/
    if ( v20 && LOWORD(dword_B42EAC) != 5 ) /*0x7ad82c*/
    {
      ShadowSceneNode = GetShadowSceneNode(v22->member.passInfo >> 0x1C); /*0x7ad835*/
      if ( !sub_7C7050((int)retaddr, ShadowSceneNode) ) /*0x7ad846*/
        return; /*0x7ad846*/
      *((_WORD *)retaddr + 0xC) |= 0x80u; /*0x7ad84c*/
    }
    v51 = *(_DWORD *)(a1 + 0x5C) > 0; /*0x7ad856*/
    if ( v51 != ((v22->member.passInfo & 0x200) != 0) ) /*0x7ad865*/
    {
      sub_434980(v22, 0x200, v51); /*0x7ad86f*/
      sub_7E24C0(v22); /*0x7ad876*/
    }
    v52 = *((int (__thiscall **)(BSShaderProperty *, float *, int, volatile LONG **, int))v22->vtbl + 0x17); /*0x7ad884*/
    v96 = dword_B42F40; /*0x7ad88e*/
    v105 = 0; /*0x7ad892*/
    v53 = (_DWORD *)v52(v22, retaddr, v96, &v105, 1); /*0x7ad89a*/
    v101[0] = v53; /*0x7ad89e*/
    if ( v53 ) /*0x7ad8a2*/
    {
      v97 = 0; /*0x7ad8ac*/
      if ( v53[3] > 1u ) /*0x7ad8b1*/
      {
        for ( j = *(NiObject **)(v125 + 0xC); j; j = (NiObject *)j[6].members.m_uiRefCount ) /*0x7ad8bf*/
        {
          if ( v97 ) /*0x7ad8c8*/
            break; /*0x7ad8c8*/
          if ( NiRTTI::IsObjectOfRTTIType(&stru_B3CE30, j) ) /*0x7ad8d0*/
          {
            v55 = FormHeapAlloc(0x18u); /*0x7ad8de*/
            if ( v55 ) /*0x7ad8e8*/
            {
              *(_DWORD *)v55 = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7ad8ea*/
              *(_DWORD *)(v55 + 4) = 0; /*0x7ad8f0*/
              *(_DWORD *)(v55 + 8) = 0; /*0x7ad8f3*/
              *(_DWORD *)(v55 + 0xC) = 0; /*0x7ad8f6*/
            }
            else
            {
              v55 = 0; /*0x7ad8fb*/
            }
            *(float *)(v55 + 0x14) = 0.0; /*0x7ad901*/
            v99 = v55; /*0x7ad904*/
            sub_7AA6C0((_DWORD *)v55); /*0x7ad908*/
            sub_6AA320((_DWORD *)(a1 + 0x3C), &v99); /*0x7ad915*/
            v97 = 1; /*0x7ad91a*/
          }
        }
      }
      if ( *((_DWORD *)v101[0] + 3) && *(float *)(v100 + 0x20) > 0.0 ) /*0x7ad942*/
      {
        if ( *(_BYTE *)(a1 + 0x21E2) ) /*0x7ad948*/
        {
          if ( *(_BYTE *)(a1 + 0x21E0) ) /*0x7ad955*/
          {
            v56 = (*(int (**)(void))(*(_DWORD *)v100 + 0x64))(); /*0x7ad963*/
            if ( *(_DWORD *)(v56 + 0xC) ) /*0x7ad965*/
            {
              v20 = *(_BYTE *)(a1 + 0x21E0) == 0; /*0x7ad96b*/
              v57 = *(_DWORD *)(*(_DWORD *)(v56 + 4) + 8); /*0x7ad975*/
              v99 = v57; /*0x7ad978*/
              if ( v20 ) /*0x7ad97c*/
              {
                v58 = sub_7A9CC0(); /*0x7ad99c*/
                sub_7D1320((int *)*(unsigned __int16 *)(v57 + 4)); /*0x7ad9a5*/
                if ( v58 ) /*0x7ad9af*/
                {
                  v58->member.super.VertexConstantMap->_vtbl->sub_9A97B0(v58->member.super.VertexConstantMap); /*0x7ad9b9*/
                  v58->member.super.PixelConstantMap->_vtbl->sub_9A97B0(v58->member.super.PixelConstantMap); /*0x7ad9c3*/
                }
                sub_7A9820((_DWORD *)v57, *(_WORD *)(v57 + 4)); /*0x7ad9cd*/
              }
              else
              {
                sub_7ABDE0((_DWORD *)(a1 + 0x14 * (*(unsigned __int16 *)(v57 + 4) + 0xD)), &v99); /*0x7ad990*/
              }
            }
          }
        }
        v59 = *((_DWORD *)v101[0] + 1); /*0x7ad9d6*/
        v61 = *(_DWORD **)v59; /*0x7ad9de*/
        v98 = *(_DWORD **)v59; /*0x7ad9e3*/
        v99 = *(_DWORD *)(v59 + 8); /*0x7ad9e7*/
        v60 = v99; /*0x7ad9d9*/
        if ( v99 ) /*0x7ad9eb*/
        {
          while ( 1 ) /*0x7ada0b*/
          {
            v62 = *(_WORD *)(v60 + 4); /*0x7ada0b*/
            if ( byte_B42CE8 ) /*0x7ada04*/
            {
              if ( (unsigned __int16)(v62 - 0x168) <= 0x12u && v62 != 0x16E && v62 != 0x16F || v62 == 0x17B ) /*0x7ada30*/
                break; /*0x7ada30*/
            }
            if ( v62 != 0x190 /*0x7ada67*/
              && v62 != 0x192
              && ((unsigned __int16)(v62 - 0x34) > 0x13u || *((_DWORD *)v101[0] + 3) != 1) )
            {
              JUMPOUT(0x7ADCD8); /*0x7adcd8*/
            }
            v65 = *sub_405760(*(NiGeometry **)v60, &v102); /*0x7ada7a*/
            sub_7016A0((NiD3DVertexShader *)&v102); /*0x7ada80*/
            v66 = *((_DWORD *)v65 + 3); /*0x7ada85*/
            if ( !v66 ) /*0x7ada8a*/
            {
              if ( v62 != 0x190 && v62 != 0x192 ) /*0x7adc30*/
              {
                switch ( v62 ) /*0x7adc45*/
                {
                  case '4': /*0x7adc45*/
LABEL_144:
                    def_7ADBF2(a1, v60, 0x19u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc4c*/
                    break; /*0x7adc51*/
                  case '5': /*0x7adc45*/
LABEL_138:
                    def_7ADBF2(a1, v60, 0x1Au, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adbf9*/
                    break; /*0x7adbfe*/
                  case '6': /*0x7adc45*/
LABEL_145:
                    def_7ADBF2(a1, v60, 0x1Bu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc56*/
                    break; /*0x7adc5b*/
                  case '7': /*0x7adc45*/
LABEL_146:
                    def_7ADBF2(a1, v60, 0x1Cu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc60*/
                    break; /*0x7adc65*/
                  case '8': /*0x7adc45*/
LABEL_147:
                    def_7ADBF2(a1, v60, 0x1Eu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc6a*/
                    break; /*0x7adc6f*/
                  case '9': /*0x7adc45*/
LABEL_148:
                    def_7ADBF2(a1, v60, 0x1Fu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc71*/
                    break; /*0x7adc76*/
                  case ':': /*0x7adc45*/
LABEL_149:
                    def_7ADBF2(a1, v60, 0x1Du, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc78*/
                    break; /*0x7adc7d*/
                  case ';': /*0x7adc45*/
LABEL_150:
                    def_7ADBF2(a1, v60, 0x20u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc7f*/
                    break; /*0x7adc84*/
                  case '<': /*0x7adc45*/
LABEL_151:
                    def_7ADBF2(a1, v60, 0x21u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc86*/
                    break; /*0x7adc8b*/
                  case '=': /*0x7adc45*/
LABEL_152:
                    def_7ADBF2(a1, v60, 0x22u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc8d*/
                    break; /*0x7adc92*/
                  case '>': /*0x7adc45*/
LABEL_153:
                    def_7ADBF2(a1, v60, 0x24u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc94*/
                    break; /*0x7adc99*/
                  case '?': /*0x7adc45*/
LABEL_154:
                    def_7ADBF2(a1, v60, 0x25u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adc9b*/
                    break; /*0x7adca0*/
                  case '@': /*0x7adc45*/
LABEL_156:
                    def_7ADBF2(a1, v60, 0x26u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adca9*/
                    break; /*0x7adcae*/
                  case 'A': /*0x7adc45*/
LABEL_157:
                    def_7ADBF2(a1, v60, 0x27u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adcb0*/
                    break; /*0x7adcb5*/
                  case 'B': /*0x7adc45*/
LABEL_158:
                    def_7ADBF2(a1, v60, 0x29u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adcb7*/
                    break; /*0x7adcbc*/
                  case 'C': /*0x7adc45*/
LABEL_159:
                    def_7ADBF2(a1, v60, 0x2Au, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adcbe*/
                    break; /*0x7adcc3*/
                  case 'D': /*0x7adc45*/
LABEL_155:
                    def_7ADBF2(a1, v60, 0x28u, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adca2*/
                    break; /*0x7adca7*/
                  case 'E': /*0x7adc45*/
LABEL_160:
                    def_7ADBF2(a1, v60, 0x2Bu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adcc5*/
                    break; /*0x7adcca*/
                  case 'F': /*0x7adc45*/
LABEL_161:
                    def_7ADBF2(a1, v60, 0x2Cu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adccc*/
                    break; /*0x7adcd1*/
                  case 'G': /*0x7adc45*/
LABEL_162:
                    def_7ADBF2(a1, v60, 0x2Eu, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adcd3*/
                    break; /*0x7adcd4*/
                }
                return; /*0x7adcd4*/
              }
              if ( !v98 ) /*0x7adefd*/
                goto LABEL_167; /*0x7adefd*/
              v64 = v98 + 2; /*0x7adf03*/
              v63 = (_DWORD *)*v98; /*0x7adf06*/
              goto LABEL_165; /*0x7adf06*/
            }
            v67 = *(float **)(a1 + 8); /*0x7ada90*/
            v68 = v67[0x22]; /*0x7ada96*/
            v103 = *(float *)(v66 + 0x2C); /*0x7ada9c*/
            v69 = v67[0x23]; /*0x7adaa0*/
            v104 = *(int *)(v66 + 0x30); /*0x7adaae*/
            v106 = v68; /*0x7adab2*/
            v70 = v67[0x24]; /*0x7adab6*/
            v71 = *(_DWORD *)v60 + 0x20; /*0x7adabc*/
            v107 = v69; /*0x7adabf*/
            v113 = *(float *)v71; /*0x7adac5*/
            v72 = *(float *)(v71 + 8); /*0x7adad1*/
            v108 = v70; /*0x7adad4*/
            v73 = *(float *)(v71 + 4); /*0x7adad8*/
            v112[0] = v113 - v106; /*0x7adadb*/
            v114 = v73; /*0x7adadf*/
            v74 = v73; /*0x7adae3*/
            v75 = *(float *)(v71 + 0xC); /*0x7adae7*/
            v115 = v72; /*0x7adaee*/
            v116 = v75; /*0x7adaf6*/
            v112[1] = v74 - v107; /*0x7adafa*/
            v112[2] = v72 - v108; /*0x7adb06*/
            v76 = sub_404C90(v112); /*0x7adb0a*/
            if ( v103 < v76 + v116 ) /*0x7adb20*/
            {
              v77 = *(float *)(v66 + 0x20); /*0x7adb2a*/
              v78 = *(float *)(v66 + 0x24); /*0x7adb2d*/
              v117 = v104; /*0x7adb30*/
              v79 = *(float *)(v66 + 0x28); /*0x7adb34*/
              v109 = v77; /*0x7adb39*/
              *(float *)&v118 = *(float *)&v104 - v103; /*0x7adb41*/
              v110 = v78; /*0x7adb45*/
              v80 = v118; /*0x7adb4b*/
              v119 = 0.0; /*0x7adb4f*/
              v111 = v79; /*0x7adb53*/
              *(float *)&v120 = 0.0; /*0x7adb5b*/
              v81 = v77; /*0x7adb5f*/
              dword_B46638 = v104; /*0x7adb63*/
              v82 = v120; /*0x7adb68*/
              *(float *)&v121 = v81; /*0x7adb6c*/
              v83 = v110; /*0x7adb70*/
              dword_B4663C = v80; /*0x7adb74*/
              v84 = v121; /*0x7adb7a*/
              *(float *)&v122 = v83; /*0x7adb7e*/
              v85 = v111; /*0x7adb85*/
              *(float *)&dword_B46640 = 0.0; /*0x7adb89*/
              v86 = v122; /*0x7adb8f*/
              *(float *)&v123 = v85; /*0x7adb96*/
              dword_B46644 = v82; /*0x7adb9d*/
              v87 = v123; /*0x7adba2*/
              *(float *)&v124 = 0.0; /*0x7adba9*/
              dword_B46648 = v84; /*0x7adbb0*/
              v88 = v124; /*0x7adbb6*/
              dword_B4664C = v86; /*0x7adbbd*/
              dword_B46650 = v87; /*0x7adbc3*/
              dword_B46654 = v88; /*0x7adbc8*/
              def_7ADBF2(a1, v60, v62, (int)a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); /*0x7adbce*/
              return; /*0x7adbce*/
            }
            if ( v62 != 0x190 && v62 != 0x192 ) /*0x7adbe1*/
            {
              switch ( v62 ) /*0x7adbf2*/
              {
                case '4': /*0x7adbf2*/
                  goto LABEL_144;
                case '5': /*0x7adbf2*/
                  goto LABEL_138;
                case '6': /*0x7adbf2*/
                  goto LABEL_145;
                case '7': /*0x7adbf2*/
                  goto LABEL_146;
                case '8': /*0x7adbf2*/
                  goto LABEL_147;
                case '9': /*0x7adbf2*/
                  goto LABEL_148;
                case ':': /*0x7adbf2*/
                  goto LABEL_149;
                case ';': /*0x7adbf2*/
                  goto LABEL_150;
                case '<': /*0x7adbf2*/
                  goto LABEL_151;
                case '=': /*0x7adbf2*/
                  goto LABEL_152;
                case '>': /*0x7adbf2*/
                  goto LABEL_153;
                case '?': /*0x7adbf2*/
                  goto LABEL_154;
                case '@': /*0x7adbf2*/
                  goto LABEL_156;
                case 'A': /*0x7adbf2*/
                  goto LABEL_157;
                case 'B': /*0x7adbf2*/
                  goto LABEL_158;
                case 'C': /*0x7adbf2*/
                  goto LABEL_159;
                case 'D': /*0x7adbf2*/
                  goto LABEL_155;
                case 'E': /*0x7adbf2*/
                  goto LABEL_160;
                case 'F': /*0x7adbf2*/
                  goto LABEL_161;
                case 'G': /*0x7adbf2*/
                  goto LABEL_162;
              }
            }
            if ( !v98 ) /*0x7adc08*/
              goto LABEL_167; /*0x7adc08*/
            v64 = v98 + 2; /*0x7adc14*/
            v98 = (_DWORD *)*v98; /*0x7adc17*/
LABEL_166:
            v60 = *v64; /*0x7adf0c*/
            v99 = *v64; /*0x7adf10*/
            if ( !v99 ) /*0x7adf14*/
              goto LABEL_167; /*0x7adf14*/
            v61 = v98; /*0x7ada00*/
          }
          if ( !v61 ) /*0x7ada34*/
            goto LABEL_167; /*0x7ada34*/
          v63 = (_DWORD *)*v61; /*0x7ada3a*/
          v64 = v61 + 2; /*0x7ada3c*/
LABEL_165:
          v98 = v63; /*0x7adf08*/
          goto LABEL_166; /*0x7adf08*/
        }
LABEL_167:
        v89 = v125; /*0x7adf1a*/
        ++dword_B42CD0; /*0x7adf21*/
        v90 = (*(int (__thiscall **)(int))(*(_DWORD *)v89 + 0x10))(v89); /*0x7adf2d*/
        if ( !v90 ) /*0x7adf31*/
          return; /*0x7adf31*/
        v43 = **(_DWORD **)(v90 + 0xB4); /*0x7adf3d*/
LABEL_74:
        dword_B42CC4 += (*(unsigned __int16 (**)(void))(v43 + 0x5C))(); /*0x7ad6f5*/
      }
    }
  }
}
