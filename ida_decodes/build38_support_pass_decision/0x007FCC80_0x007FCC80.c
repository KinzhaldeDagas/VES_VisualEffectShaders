// 0x007FCC80 @ 0x007FCC80
// MoonSugarEffect build 34 decode-only: constant-map ownership matters for visible aux clones. TexEffect uses alternate fill/rim/fog maps, EnvMap/Decal use distinct constant rows; do not reuse the primary SM3Lighting scratch-register plan blindly.
void __thiscall sub_7FCC80(int *this)
{
  Ni2DBuffer **v2; // esi
  NiD3DShaderConstantMap *v3; // eax
  NiD3DShaderConstantMap *v4; // eax
  int v5; // edi
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, int); // ebp
  Ni2DBuffer *v8; // eax
  Ni2DBuffer *v9; // eax
  Ni2DBuffer *v10; // eax
  Ni2DBuffer *v11; // eax
  Ni2DBuffer *v12; // eax
  Ni2DBuffer *v13; // eax
  int *v14; // edi
  NiD3DShaderConstantMap *v15; // eax
  NiD3DShaderConstantMap *v16; // eax
  Ni2DBuffer *v17; // ebp
  Ni2DBuffer *v18; // esi
  int v19; // esi
  int v20; // edi
  int *v21; // esi
  NiD3DShaderConstantMap *v22; // eax
  NiD3DShaderConstantMap *v23; // eax
  int *v24; // esi
  NiD3DShaderConstantMap *v25; // eax
  NiD3DShaderConstantMap *v26; // eax

  v2 = (Ni2DBuffer **)(this + 0xC); /*0x7fccab*/
  if ( !*(this + 0xC) ) /*0x7fcca7*/
  {
    v3 = (NiD3DShaderConstantMap *)FormHeapAlloc(0x34u); /*0x7fccb6*/
    if ( v3 ) /*0x7fcccc*/
      v4 = NiD3DShaderCostantMapVertex::Construct(v3, *(this + 5)); /*0x7fccd4*/
    else
      v4 = 0; /*0x7fccdb*/
    NiSmartPointer_Set__(v2, (Ni2DBuffer *)v4); /*0x7fcce8*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, _DWORD, CHAR *))(*v2)->__vftable + 7))( /*0x7fcd05*/
      *v2,
      "WorldViewProjTranspose",
      0x20000009,
      0,
      EmptyString);
    v5 = (*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))(*v2, "WorldViewProjTranspose"); /*0x7fcd15*/
    v6 = dword_B46B98[0]; /*0x7fcd17*/
    if ( dword_B46B98[0] != v5 ) /*0x7fcd1e*/
    {
      if ( v6 ) /*0x7fcd22*/
      {
        v7 = (void (__thiscall ***)(_DWORD, int))dword_B46B98[0]; /*0x7fcd24*/
        if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) ) /*0x7fcd2a*/
        {
          if ( v7 ) /*0x7fcd36*/
            (**v7)(v7, 1); /*0x7fcd41*/
        }
      }
      dword_B46B98[0] = v5; /*0x7fcd45*/
      if ( v5 ) /*0x7fcd4b*/
        InterlockedIncrement((volatile LONG *)(v5 + 4)); /*0x7fcd51*/
    }
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, int, CHAR *))(*v2)->__vftable + 7))( /*0x7fcd6f*/
      *v2,
      "SkinWorldViewProjTranspose",
      0x20000009,
      1,
      EmptyString);
    v8 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))( /*0x7fcd7d*/
                         *v2,
                         "SkinWorldViewProjTranspose");
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46B9C, v8); /*0x7fcd85*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, int, CHAR *))(*v2)->__vftable + 7))( /*0x7fcda2*/
      *v2,
      "WorldViewTranspose",
      0x20000009,
      5,
      EmptyString);
    v9 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))( /*0x7fcdb0*/
                         *v2,
                         "WorldViewTranspose");
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46BA4, v9); /*0x7fcdb8*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, int, CHAR *))(*v2)->__vftable + 7))( /*0x7fcdd5*/
      *v2,
      "SkinWorldViewTranspose",
      0x20000009,
      6,
      EmptyString);
    v10 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))( /*0x7fcde3*/
                          *v2,
                          "SkinWorldViewTranspose");
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46BA8, v10); /*0x7fcdeb*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v2)->__vftable /*0x7fce14*/
     + 6))(
      *v2,
      "BoneMatrix3",
      0x20000009,
      0x120000,
      0x1F,
      0x36,
      0,
      0,
      0,
      0,
      0);
    v11 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))(*v2, "BoneMatrix3"); /*0x7fce22*/
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46BA0, v11); /*0x7fce2a*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, _DWORD, int, int, CHAR *, int, int, float *, _DWORD))(*v2)->__vftable /*0x7fce59*/
     + 6))(
      *v2,
      "ConstantGroup",
      0x10000009,
      0,
      0xA,
      0x15,
      EmptyString,
      0x150,
      4,
      &flt_B46D68,
      0);
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, _DWORD, int, int, CHAR *, int, int, float *, _DWORD))(*v2)->__vftable /*0x7fce85*/
     + 6))(
      *v2,
      "decal fade",
      0x10000009,
      0,
      0x20,
      8,
      EmptyString,
      0x80,
      4,
      &flt_B46218,
      0);
    v12 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))(*v2, "decal fade"); /*0x7fce93*/
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46C14, v12); /*0x7fce9b*/
    (*((void (__thiscall **)(Ni2DBuffer *, const char *, int, _DWORD, int, int, CHAR *, int, int, void *, _DWORD))(*v2)->__vftable /*0x7fceca*/
     + 6))(
      *v2,
      "decal proj",
      0x10000009,
      0,
      0x28,
      0x20,
      EmptyString,
      0x200,
      4,
      &unk_B46298,
      0);
    v13 = (Ni2DBuffer *)(*((int (__thiscall **)(Ni2DBuffer *, const char *))(*v2)->__vftable + 0xE))(*v2, "decal proj"); /*0x7fced8*/
    NiSmartPointer_Set__((Ni2DBuffer **)&dword_B46C18, v13); /*0x7fcee0*/
  }
  v14 = this + 0xB; /*0x7fcee9*/
  if ( !*(this + 0xB) ) /*0x7fcee5*/
  {
    v15 = (NiD3DShaderConstantMap *)FormHeapAlloc(0x34u); /*0x7fcef0*/
    if ( v15 ) /*0x7fcf06*/
      v16 = NiD3DShaderCostantMapPixel::Construct(v15, *(this + 5)); /*0x7fcf0e*/
    else
      v16 = 0; /*0x7fcf15*/
    NiSmartPointer_Set__((Ni2DBuffer **)this + 0xB, (Ni2DBuffer *)v16); /*0x7fcf22*/
    (*(void (__thiscall **)(int, const char *, int, _DWORD, _DWORD, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v14 + 0x18))( /*0x7fcf51*/
      *v14,
      "ConstantGroup",
      0x10000009,
      0,
      0,
      0x31,
      EmptyString,
      0x310,
      4,
      &dword_B46F78,
      0);
    *(this + 0x27) = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)*v14 + 0x38))(*v14, "ConstantGroup"); /*0x7fcf61*/
  }
  v17 = (Ni2DBuffer *)*(this + 0x22); /*0x7fcf67*/
  if ( v17 != *v2 ) /*0x7fcf6f*/
  {
    if ( v17 ) /*0x7fcf73*/
    {
      if ( !InterlockedDecrement((volatile LONG *)&v17->members) ) /*0x7fcf79*/
        (*(void (__thiscall **)(Ni2DBuffer *, int))v17->__vftable)(v17, 1); /*0x7fcf90*/
    }
    v18 = *v2; /*0x7fcf92*/
    *(this + 0x22) = (int)v18; /*0x7fcf96*/
    if ( v18 ) /*0x7fcf9c*/
      InterlockedIncrement((volatile LONG *)&v18->members); /*0x7fcfa2*/
  }
  v19 = *(this + 0x21); /*0x7fcfa8*/
  if ( v19 != *v14 ) /*0x7fcfb0*/
  {
    if ( v19 ) /*0x7fcfb4*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) ) /*0x7fcfba*/
        (**(void (__thiscall ***)(int, int))v19)(v19, 1); /*0x7fcfd0*/
    }
    v20 = *v14; /*0x7fcfd2*/
    *(this + 0x21) = v20; /*0x7fcfd6*/
    if ( v20 ) /*0x7fcfdc*/
      InterlockedIncrement((volatile LONG *)(v20 + 4)); /*0x7fcfe2*/
  }
  v21 = this + 0x20; /*0x7fcfef*/
  if ( !*(this + 0x20) ) /*0x7fcfe8*/
  {
    v22 = (NiD3DShaderConstantMap *)FormHeapAlloc(0x34u); /*0x7fcffd*/
    if ( v22 ) /*0x7fd013*/
      v23 = NiD3DShaderCostantMapVertex::Construct(v22, *(this + 5)); /*0x7fd01b*/
    else
      v23 = 0; /*0x7fd022*/
    NiSmartPointer_Set__((Ni2DBuffer **)this + 0x20, (Ni2DBuffer *)v23); /*0x7fd02f*/
    (*(void (__thiscall **)(int, const char *, int, _DWORD, CHAR *))(*(_DWORD *)*v21 + 0x1C))( /*0x7fd04c*/
      *v21,
      "WorldViewProjTranspose",
      0x20000009,
      0,
      EmptyString);
    (*(void (__thiscall **)(int, const char *, int, int, CHAR *))(*(_DWORD *)*v21 + 0x1C))( /*0x7fd066*/
      *v21,
      "SkinWorldViewProjTranspose",
      0x20000009,
      4,
      EmptyString);
    (*(void (__thiscall **)(int, const char *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd08c*/
      *v21,
      "BoneMatrix3",
      0x20000009,
      0x120000,
      0xE,
      0x36,
      0,
      0,
      0,
      0,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd0b5*/
      *v21,
      "EyePosition",
      0x10000007,
      0,
      8,
      1,
      EmptyString,
      0x10,
      4,
      &dword_B46DA8,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, float *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd0de*/
      *v21,
      "U Offset",
      0x10000004,
      0,
      9,
      1,
      EmptyString,
      4,
      4,
      &flt_B46B3C,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, float *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd107*/
      *v21,
      "V Offset",
      0x10000004,
      0,
      0xA,
      1,
      EmptyString,
      4,
      4,
      &flt_B46B40,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, void *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd130*/
      *v21,
      "InvBoundDiameter",
      0x10000004,
      0,
      0xB,
      1,
      EmptyString,
      4,
      4,
      &unk_B46B44,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd159*/
      *v21,
      "FogParam",
      0x10000007,
      0,
      0xC,
      1,
      EmptyString,
      0x10,
      4,
      &dword_B46B88,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v21 + 0x18))( /*0x7fd182*/
      *v21,
      "FogColor",
      0x10000007,
      0,
      0xD,
      1,
      EmptyString,
      0x10,
      4,
      &dword_B46B78,
      0);
  }
  v24 = this + 0x1F; /*0x7fd188*/
  if ( !*(this + 0x1F) ) /*0x7fd184*/
  {
    v25 = (NiD3DShaderConstantMap *)FormHeapAlloc(0x34u); /*0x7fd193*/
    if ( v25 ) /*0x7fd1a9*/
      v26 = NiD3DShaderCostantMapPixel::Construct(v25, *(this + 5)); /*0x7fd1b1*/
    else
      v26 = 0; /*0x7fd1b8*/
    NiSmartPointer_Set__((Ni2DBuffer **)this + 0x1F, (Ni2DBuffer *)v26); /*0x7fd1c5*/
    (*(void (__thiscall **)(int, const char *, int, _DWORD, _DWORD, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v24 + 0x18))( /*0x7fd1f1*/
      *v24,
      "Fill Color",
      0x10000007,
      0,
      0,
      1,
      EmptyString,
      0x10,
      4,
      &dword_B46B48,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, int *, _DWORD))(*(_DWORD *)*v24 + 0x18))( /*0x7fd21a*/
      *v24,
      "Rim Color",
      0x10000007,
      0,
      1,
      1,
      EmptyString,
      0x10,
      4,
      &dword_B46B58,
      0);
    (*(void (__thiscall **)(int, const char *, int, _DWORD, int, int, CHAR *, int, int, float *, _DWORD))(*(_DWORD *)*v24 + 0x18))( /*0x7fd243*/
      *v24,
      "Vars",
      0x10000007,
      0,
      2,
      1,
      EmptyString,
      0x10,
      4,
      &flt_B46B68,
      0);
  }
}
