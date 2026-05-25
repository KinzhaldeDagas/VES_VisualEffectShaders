// 0x0085E660 @ 0x0085E660
// MoonSugarEffect build 26: pass population binds B473D0 entries to concrete Lighting30 vertex/pixel program families. Build 26 OBSE telemetry records top VS/PS program families and marks only plain no-skin SM3Lighting as a future candidate, still diagnostic-only.
void sub_85E660()
{
  NiD3DPass *v0; // esi
  int v1; // eax
  bool v2; // zf
  NiD3DVertexShader *VertexShader; // edi
  int v4; // ebp
  NiD3DPixelShader *PixelShader; // edi
  int v6; // ebp
  NiD3DVertexShader *v7; // edi
  int v8; // ebp
  NiD3DPixelShader *v9; // edi
  int v10; // ebp
  NiD3DVertexShader *v11; // edi
  int v12; // ebp
  NiD3DPixelShader *v13; // edi
  int v14; // ebp
  NiD3DVertexShader *v15; // edi
  int v16; // ebp
  NiD3DPixelShader *v17; // edi
  int v18; // ebp
  NiD3DVertexShader *v19; // edi
  int v20; // ebp
  NiD3DPixelShader *v21; // edi
  int v22; // ebp
  NiD3DVertexShader *v23; // edi
  int v24; // ebp
  NiD3DPixelShader *v25; // edi
  int v26; // ebp
  NiD3DVertexShader *v27; // edi
  int v28; // ebp
  NiD3DPixelShader *v29; // edi
  int v30; // ebp
  NiD3DVertexShader *v31; // edi
  int v32; // ebp
  NiD3DPixelShader *v33; // edi
  int v34; // ebp
  NiD3DVertexShader *v35; // edi
  int v36; // ebp
  NiD3DPixelShader *v37; // edi
  int v38; // ebp
  NiD3DVertexShader *v39; // edi
  int v40; // ebp
  NiD3DPixelShader *v41; // edi
  int v42; // ebp
  NiD3DVertexShader *v43; // edi
  int v44; // ebp
  NiD3DPixelShader *v45; // edi
  int v46; // ebp
  NiD3DVertexShader *v47; // edi
  int v48; // ebp
  NiD3DPixelShader *v49; // edi
  int v50; // ebp
  NiD3DVertexShader *v51; // edi
  int v52; // ebp
  NiD3DPixelShader *v53; // edi
  int v54; // ebp
  NiD3DVertexShader *v55; // edi
  int v56; // ebp
  NiD3DPixelShader *v57; // edi
  int v58; // ebp
  NiD3DVertexShader *v59; // edi
  int v60; // ebp
  NiD3DPixelShader *v61; // edi
  int v62; // ebp
  unsigned int *v63; // eax
  NiD3DTextureStage *v64; // eax
  unsigned int *v65; // edi
  unsigned int *v66; // eax
  NiD3DTextureStage *v67; // eax
  unsigned int *v68; // edi
  unsigned int *v69; // eax
  NiD3DTextureStage *v70; // eax
  unsigned int *v71; // edi
  unsigned int *v72; // eax
  NiD3DTextureStage *v73; // eax
  unsigned int *v74; // edi
  unsigned int *v75; // eax
  NiD3DTextureStage *v76; // eax
  unsigned int *v77; // edi
  unsigned int *v78; // eax
  NiD3DTextureStage *v79; // eax
  unsigned int *v80; // edi
  unsigned int *v81; // eax
  NiD3DTextureStage *v82; // eax
  unsigned int *v83; // edi
  unsigned int *v84; // eax
  NiD3DTextureStage *v85; // eax
  unsigned int *v86; // edi
  unsigned int *v87; // eax
  NiD3DTextureStage *v88; // eax
  unsigned int *v89; // edi
  unsigned int *v90; // eax
  NiD3DTextureStage *v91; // eax
  unsigned int *v92; // edi
  unsigned int *v93; // eax
  NiD3DTextureStage *v94; // eax
  unsigned int *v95; // edi
  unsigned int *v96; // eax
  NiD3DTextureStage *v97; // eax
  unsigned int *v98; // edi
  unsigned int *v99; // eax
  NiD3DTextureStage *v100; // eax
  unsigned int *v101; // edi
  unsigned int *v102; // eax
  NiD3DTextureStage *v103; // eax
  unsigned int *v104; // edi
  NiD3DPass *v105; // esi
  NiD3DPass *v106; // esi
  NiD3DPass *v107; // esi
  unsigned int *v108; // eax
  NiD3DTextureStage *v109; // eax
  unsigned int *v110; // edi
  NiD3DPass *v111; // esi
  unsigned int *v112; // eax
  NiD3DTextureStage *v113; // eax
  unsigned int *v114; // ebp
  NiD3DPass *v115; // esi
  unsigned int *v116; // eax
  NiD3DTextureStage *v117; // eax
  NiD3DPassVtbl **v118; // esi
  NiD3DPassVtbl **v119; // esi
  NiD3DPass *v120; // esi
  unsigned int *v121; // eax
  NiD3DTextureStage *v122; // eax
  unsigned int *v123; // edi
  unsigned int *v124; // eax
  NiD3DTextureStage *v125; // eax
  unsigned int *v126; // edi
  NiD3DPass *v127; // esi
  unsigned int *v128; // eax
  NiD3DTextureStage *v129; // eax
  unsigned int *v130; // edi
  unsigned int *v131; // eax
  NiD3DTextureStage *v132; // eax
  unsigned int *v133; // edi
  NiD3DPass *v134; // esi
  unsigned int *v135; // eax
  NiD3DTextureStage *v136; // eax
  unsigned int *v137; // edi
  NiD3DPass *v138; // esi
  unsigned int *v139; // eax
  NiD3DTextureStage *v140; // eax
  NiD3DPassVtbl **v141; // esi
  NiD3DPassVtbl **v142; // esi
  NiD3DPass *v143; // esi
  NiD3DTextureStage *v144; // ecx
  NiD3DPassVtbl **v145; // [esp+78h] [ebp-18h] BYREF
  unsigned int *a3; // [esp+7Ch] [ebp-14h] BYREF
  NiD3DTextureStage *v147; // [esp+80h] [ebp-10h] BYREF
  unsigned int v148; // [esp+8Ch] [ebp-4h]

  v0 = 0; /*0x85e687*/
  v145 = 0; /*0x85e68b*/
  v148 = 0; /*0x85e68f*/
  a3 = 0; /*0x85e693*/
  v1 = dword_B473D0[0]; /*0x85e697*/
  v2 = dword_B473D0[0] == 0; /*0x85e69c*/
  LOBYTE(v148) = 1; /*0x85e69e*/
  if ( !v2 ) /*0x85e6a3*/
  {
    v0 = (NiD3DPass *)v1; /*0x85e6a5*/
    v145 = (NiD3DPassVtbl **)v1; /*0x85e6a9*/
    if ( v1 ) /*0x85e6ad*/
      ++*(_DWORD *)(v1 + 0x60); /*0x85e6af*/
  }
  sub_85E570(v0); /*0x85e6b4*/
  VertexShader = v0->VertexShader; /*0x85e6be*/
  v4 = dword_B47300; /*0x85e6c6*/
  if ( VertexShader != (NiD3DVertexShader *)dword_B47300 ) /*0x85e6c8*/
  {
    if ( VertexShader ) /*0x85e6cc*/
    {
      if ( !InterlockedDecrement((volatile LONG *)VertexShader + 1) ) /*0x85e6d2*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))VertexShader)(VertexShader, 1); /*0x85e6e8*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v4; /*0x85e6ec*/
    if ( v4 ) /*0x85e6ef*/
      InterlockedIncrement((volatile LONG *)(v4 + 4)); /*0x85e6f5*/
  }
  PixelShader = v0->PixelShader; /*0x85e700*/
  v6 = dword_B46F6C; /*0x85e705*/
  if ( PixelShader != (NiD3DPixelShader *)dword_B46F6C ) /*0x85e707*/
  {
    if ( PixelShader ) /*0x85e70b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)PixelShader + 1) ) /*0x85e711*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))PixelShader)(PixelShader, 1); /*0x85e727*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v6; /*0x85e72b*/
    if ( v6 ) /*0x85e72e*/
      InterlockedIncrement((volatile LONG *)(v6 + 4)); /*0x85e734*/
  }
  if ( !v0->RenderStateGroup ) /*0x85e73a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e744*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85e74f*/
  if ( !v0->RenderStateGroup ) /*0x85e754*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e75e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85e769*/
  if ( !v0->RenderStateGroup ) /*0x85e76e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e778*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x85e782*/
  if ( !v0->RenderStateGroup ) /*0x85e787*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e791*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85e79b*/
  if ( !v0->RenderStateGroup ) /*0x85e7a0*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e7aa*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x16, 1, 0); /*0x85e7b5*/
  if ( !v0->RenderStateGroup ) /*0x85e7ba*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e7c4*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xA8, 0, 0); /*0x85e7d1*/
  v2 = v0 == (NiD3DPass *)dword_B473D4; /*0x85e7d6*/
  dword_B46988[0] = 0x812; /*0x85e7dc*/
  dword_B46A60[0] = 0; /*0x85e7e6*/
  if ( !v2 ) /*0x85e7ec*/
  {
    v2 = v0->RefCount-- == 1; /*0x85e7ee*/
    if ( v2 ) /*0x85e7f2*/
      sub_7604D0(v0); /*0x85e7f6*/
    v0 = (NiD3DPass *)dword_B473D4; /*0x85e7fb*/
    v145 = (NiD3DPassVtbl **)dword_B473D4; /*0x85e803*/
    if ( v145 ) /*0x85e807*/
      ++v0->RefCount; /*0x85e809*/
  }
  sub_85E570(v0); /*0x85e80e*/
  v7 = v0->VertexShader; /*0x85e818*/
  v8 = dword_B47300; /*0x85e820*/
  if ( v7 != (NiD3DVertexShader *)dword_B47300 ) /*0x85e822*/
  {
    if ( v7 ) /*0x85e826*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v7 + 1) ) /*0x85e82c*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v7)(v7, 1); /*0x85e842*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v8; /*0x85e846*/
    if ( v8 ) /*0x85e849*/
      InterlockedIncrement((volatile LONG *)(v8 + 4)); /*0x85e84f*/
  }
  v9 = v0->PixelShader; /*0x85e85a*/
  v10 = dword_B46F6C; /*0x85e85f*/
  if ( v9 != (NiD3DPixelShader *)dword_B46F6C ) /*0x85e861*/
  {
    if ( v9 ) /*0x85e865*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v9 + 1) ) /*0x85e86b*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v9)(v9, 1); /*0x85e881*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v10; /*0x85e885*/
    if ( v10 ) /*0x85e888*/
      InterlockedIncrement((volatile LONG *)(v10 + 4)); /*0x85e88e*/
  }
  if ( !v0->RenderStateGroup ) /*0x85e894*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e89e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85e8a9*/
  if ( !v0->RenderStateGroup ) /*0x85e8ae*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e8b8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85e8c3*/
  if ( !v0->RenderStateGroup ) /*0x85e8c8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e8d2*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85e8dd*/
  if ( !v0->RenderStateGroup ) /*0x85e8e2*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e8ec*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85e8f6*/
  v2 = v0 == (NiD3DPass *)dword_B473D8; /*0x85e8fb*/
  dword_B4698C = 2; /*0x85e901*/
  dword_B46A64 = 0; /*0x85e90b*/
  if ( !v2 ) /*0x85e911*/
  {
    v2 = v0->RefCount-- == 1; /*0x85e913*/
    if ( v2 ) /*0x85e917*/
      sub_7604D0(v0); /*0x85e91b*/
    v0 = (NiD3DPass *)dword_B473D8; /*0x85e920*/
    v145 = (NiD3DPassVtbl **)dword_B473D8; /*0x85e928*/
    if ( v145 ) /*0x85e92c*/
      ++v0->RefCount; /*0x85e92e*/
  }
  sub_85E570(v0); /*0x85e933*/
  v11 = v0->VertexShader; /*0x85e93d*/
  v12 = dword_B47304; /*0x85e945*/
  if ( v11 != (NiD3DVertexShader *)dword_B47304 ) /*0x85e947*/
  {
    if ( v11 ) /*0x85e94b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v11 + 1) ) /*0x85e951*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v11)(v11, 1); /*0x85e967*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v12; /*0x85e96b*/
    if ( v12 ) /*0x85e96e*/
      InterlockedIncrement((volatile LONG *)(v12 + 4)); /*0x85e974*/
  }
  v13 = v0->PixelShader; /*0x85e97f*/
  v14 = dword_B46F70; /*0x85e984*/
  if ( v13 != (NiD3DPixelShader *)dword_B46F70 ) /*0x85e986*/
  {
    if ( v13 ) /*0x85e98a*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v13 + 1) ) /*0x85e990*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v13)(v13, 1); /*0x85e9a6*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v14; /*0x85e9aa*/
    if ( v14 ) /*0x85e9ad*/
      InterlockedIncrement((volatile LONG *)(v14 + 4)); /*0x85e9b3*/
  }
  if ( !v0->RenderStateGroup ) /*0x85e9b9*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e9c3*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85e9ce*/
  if ( !v0->RenderStateGroup ) /*0x85e9d3*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e9dd*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85e9e8*/
  if ( !v0->RenderStateGroup ) /*0x85e9ed*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85e9f7*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85ea02*/
  if ( !v0->RenderStateGroup ) /*0x85ea07*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ea11*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85ea1b*/
  v2 = v0 == (NiD3DPass *)dword_B473DC; /*0x85ea20*/
  dword_B46990 = 0xC; /*0x85ea26*/
  dword_B46A68 = 0; /*0x85ea30*/
  if ( !v2 ) /*0x85ea36*/
  {
    v2 = v0->RefCount-- == 1; /*0x85ea38*/
    if ( v2 ) /*0x85ea3c*/
      sub_7604D0(v0); /*0x85ea40*/
    v0 = (NiD3DPass *)dword_B473DC; /*0x85ea45*/
    v145 = (NiD3DPassVtbl **)dword_B473DC; /*0x85ea4d*/
    if ( v145 ) /*0x85ea51*/
      ++v0->RefCount; /*0x85ea53*/
  }
  sub_85E570(v0); /*0x85ea58*/
  v15 = v0->VertexShader; /*0x85ea62*/
  v16 = dword_B47288[0]; /*0x85ea6a*/
  if ( v15 != (NiD3DVertexShader *)dword_B47288[0] ) /*0x85ea6c*/
  {
    if ( v15 ) /*0x85ea70*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v15 + 1) ) /*0x85ea76*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v15)(v15, 1); /*0x85ea8c*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v16; /*0x85ea90*/
    if ( v16 ) /*0x85ea93*/
      InterlockedIncrement((volatile LONG *)(v16 + 4)); /*0x85ea99*/
  }
  v17 = v0->PixelShader; /*0x85eaa4*/
  v18 = dword_B46ED8[0]; /*0x85eaa9*/
  if ( v17 != (NiD3DPixelShader *)dword_B46ED8[0] ) /*0x85eaab*/
  {
    if ( v17 ) /*0x85eaaf*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v17 + 1) ) /*0x85eab5*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v17)(v17, 1); /*0x85eacb*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v18; /*0x85eacf*/
    if ( v18 ) /*0x85ead2*/
      InterlockedIncrement((volatile LONG *)(v18 + 4)); /*0x85ead8*/
  }
  if ( !v0->RenderStateGroup ) /*0x85eade*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eae8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85eaf3*/
  if ( !v0->RenderStateGroup ) /*0x85eaf8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eb02*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85eb0d*/
  if ( !v0->RenderStateGroup ) /*0x85eb12*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eb1c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85eb27*/
  if ( !v0->RenderStateGroup ) /*0x85eb2c*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eb36*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85eb40*/
  v2 = v0 == (NiD3DPass *)dword_B473E0; /*0x85eb45*/
  dword_B46994 = 0x30002; /*0x85eb4b*/
  dword_B46A6C = 0x16; /*0x85eb55*/
  if ( !v2 ) /*0x85eb5f*/
  {
    v2 = v0->RefCount-- == 1; /*0x85eb61*/
    if ( v2 ) /*0x85eb65*/
      sub_7604D0(v0); /*0x85eb69*/
    v0 = (NiD3DPass *)dword_B473E0; /*0x85eb6e*/
    v145 = (NiD3DPassVtbl **)dword_B473E0; /*0x85eb76*/
    if ( v145 ) /*0x85eb7a*/
      ++v0->RefCount; /*0x85eb7c*/
  }
  sub_85E570(v0); /*0x85eb81*/
  v19 = v0->VertexShader; /*0x85eb8b*/
  v20 = dword_B4728C; /*0x85eb93*/
  if ( v19 != (NiD3DVertexShader *)dword_B4728C ) /*0x85eb95*/
  {
    if ( v19 ) /*0x85eb99*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v19 + 1) ) /*0x85eb9f*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v19)(v19, 1); /*0x85ebb5*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v20; /*0x85ebb9*/
    if ( v20 ) /*0x85ebbc*/
      InterlockedIncrement((volatile LONG *)(v20 + 4)); /*0x85ebc2*/
  }
  v21 = v0->PixelShader; /*0x85ebcd*/
  v22 = dword_B46ED8[0]; /*0x85ebd2*/
  if ( v21 != (NiD3DPixelShader *)dword_B46ED8[0] ) /*0x85ebd4*/
  {
    if ( v21 ) /*0x85ebd8*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v21 + 1) ) /*0x85ebde*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v21)(v21, 1); /*0x85ebf4*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v22; /*0x85ebf8*/
    if ( v22 ) /*0x85ebfb*/
      InterlockedIncrement((volatile LONG *)(v22 + 4)); /*0x85ec01*/
  }
  if ( !v0->RenderStateGroup ) /*0x85ec07*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ec11*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85ec1c*/
  if ( !v0->RenderStateGroup ) /*0x85ec21*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ec2b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85ec36*/
  if ( !v0->RenderStateGroup ) /*0x85ec3b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ec45*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85ec50*/
  if ( !v0->RenderStateGroup ) /*0x85ec55*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ec5f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85ec6b*/
  v2 = v0 == (NiD3DPass *)dword_B473E4; /*0x85ec70*/
  dword_B46998 = 0x3000C; /*0x85ec7b*/
  dword_B46A70 = 0x16; /*0x85ec81*/
  if ( !v2 ) /*0x85ec8b*/
  {
    v2 = v0->RefCount-- == 1; /*0x85ec8d*/
    if ( v2 ) /*0x85ec91*/
      sub_7604D0(v0); /*0x85ec95*/
    v0 = (NiD3DPass *)dword_B473E4; /*0x85ec9a*/
    v145 = (NiD3DPassVtbl **)dword_B473E4; /*0x85eca2*/
    if ( v145 ) /*0x85eca6*/
      ++v0->RefCount; /*0x85eca8*/
  }
  sub_85E570(v0); /*0x85ecad*/
  v23 = v0->VertexShader; /*0x85ecb7*/
  v24 = dword_B47290; /*0x85ecbf*/
  if ( v23 != (NiD3DVertexShader *)dword_B47290 ) /*0x85ecc1*/
  {
    if ( v23 ) /*0x85ecc5*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v23 + 1) ) /*0x85eccb*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v23)(v23, 1); /*0x85ece1*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v24; /*0x85ece5*/
    if ( v24 ) /*0x85ece8*/
      InterlockedIncrement((volatile LONG *)(v24 + 4)); /*0x85ecee*/
  }
  v25 = v0->PixelShader; /*0x85ecf9*/
  v26 = dword_B46EE0; /*0x85ecfe*/
  if ( v25 != (NiD3DPixelShader *)dword_B46EE0 ) /*0x85ed00*/
  {
    if ( v25 ) /*0x85ed04*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v25 + 1) ) /*0x85ed0a*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v25)(v25, 1); /*0x85ed20*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v26; /*0x85ed24*/
    if ( v26 ) /*0x85ed27*/
      InterlockedIncrement((volatile LONG *)(v26 + 4)); /*0x85ed2d*/
  }
  if ( !v0->RenderStateGroup ) /*0x85ed33*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ed3e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85ed4a*/
  if ( !v0->RenderStateGroup ) /*0x85ed4f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ed5a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85ed66*/
  if ( !v0->RenderStateGroup ) /*0x85ed6b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ed76*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85ed82*/
  if ( !v0->RenderStateGroup ) /*0x85ed87*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ed92*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85ed9e*/
  v2 = v0 == (NiD3DPass *)dword_B473E8; /*0x85eda3*/
  dword_B4699C = 0x30002; /*0x85eda9*/
  dword_B46A74 = 0x1E; /*0x85edb3*/
  if ( !v2 ) /*0x85edbd*/
  {
    v2 = v0->RefCount-- == 1; /*0x85edbf*/
    if ( v2 ) /*0x85edc3*/
      sub_7604D0(v0); /*0x85edc7*/
    v0 = (NiD3DPass *)dword_B473E8; /*0x85edcc*/
    v145 = (NiD3DPassVtbl **)dword_B473E8; /*0x85edd4*/
    if ( v145 ) /*0x85edd8*/
      ++v0->RefCount; /*0x85edda*/
  }
  sub_85E570(v0); /*0x85eddf*/
  v27 = v0->VertexShader; /*0x85ede9*/
  v28 = dword_B47288[0]; /*0x85edf1*/
  if ( v27 != (NiD3DVertexShader *)dword_B47288[0] ) /*0x85edf3*/
  {
    if ( v27 ) /*0x85edf7*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v27 + 1) ) /*0x85edfd*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v27)(v27, 1); /*0x85ee13*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v28; /*0x85ee17*/
    if ( v28 ) /*0x85ee1a*/
      InterlockedIncrement((volatile LONG *)(v28 + 4)); /*0x85ee20*/
  }
  v29 = v0->PixelShader; /*0x85ee2b*/
  v30 = dword_B46EE8; /*0x85ee30*/
  if ( v29 != (NiD3DPixelShader *)dword_B46EE8 ) /*0x85ee32*/
  {
    if ( v29 ) /*0x85ee36*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v29 + 1) ) /*0x85ee3c*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v29)(v29, 1); /*0x85ee52*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v30; /*0x85ee56*/
    if ( v30 ) /*0x85ee59*/
      InterlockedIncrement((volatile LONG *)(v30 + 4)); /*0x85ee5f*/
  }
  if ( !v0->RenderStateGroup ) /*0x85ee65*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ee70*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85ee7c*/
  if ( !v0->RenderStateGroup ) /*0x85ee81*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ee8c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85ee98*/
  if ( !v0->RenderStateGroup ) /*0x85ee9d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eea8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85eeb4*/
  if ( !v0->RenderStateGroup ) /*0x85eeb9*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eec4*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85eed0*/
  v2 = v0 == (NiD3DPass *)dword_B473EC; /*0x85eed5*/
  dword_B469A0 = 0x30002; /*0x85eedb*/
  dword_B46A78 = 0x16; /*0x85eee5*/
  if ( !v2 ) /*0x85eeef*/
  {
    v2 = v0->RefCount-- == 1; /*0x85eef1*/
    if ( v2 ) /*0x85eef5*/
      sub_7604D0(v0); /*0x85eef9*/
    v0 = (NiD3DPass *)dword_B473EC; /*0x85eefe*/
    v145 = (NiD3DPassVtbl **)dword_B473EC; /*0x85ef06*/
    if ( v145 ) /*0x85ef0a*/
      ++v0->RefCount; /*0x85ef0c*/
  }
  sub_85E570(v0); /*0x85ef11*/
  v31 = v0->VertexShader; /*0x85ef1b*/
  v32 = dword_B47288[0]; /*0x85ef23*/
  if ( v31 != (NiD3DVertexShader *)dword_B47288[0] ) /*0x85ef25*/
  {
    if ( v31 ) /*0x85ef29*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v31 + 1) ) /*0x85ef2f*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v31)(v31, 1); /*0x85ef45*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v32; /*0x85ef49*/
    if ( v32 ) /*0x85ef4c*/
      InterlockedIncrement((volatile LONG *)(v32 + 4)); /*0x85ef52*/
  }
  v33 = v0->PixelShader; /*0x85ef5d*/
  v34 = dword_B46EF0; /*0x85ef62*/
  if ( v33 != (NiD3DPixelShader *)dword_B46EF0 ) /*0x85ef64*/
  {
    if ( v33 ) /*0x85ef68*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v33 + 1) ) /*0x85ef6e*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v33)(v33, 1); /*0x85ef84*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v34; /*0x85ef88*/
    if ( v34 ) /*0x85ef8b*/
      InterlockedIncrement((volatile LONG *)(v34 + 4)); /*0x85ef91*/
  }
  if ( !v0->RenderStateGroup ) /*0x85ef97*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85efa2*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85efae*/
  if ( !v0->RenderStateGroup ) /*0x85efb3*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85efbe*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85efca*/
  if ( !v0->RenderStateGroup ) /*0x85efcf*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85efda*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85efe6*/
  if ( !v0->RenderStateGroup ) /*0x85efeb*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85eff6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f002*/
  v2 = v0 == (NiD3DPass *)dword_B473F0; /*0x85f007*/
  dword_B469A4 = 0x30002; /*0x85f00d*/
  dword_B46A7C = 0x16; /*0x85f017*/
  if ( !v2 ) /*0x85f021*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f023*/
    if ( v2 ) /*0x85f027*/
      sub_7604D0(v0); /*0x85f02b*/
    v0 = (NiD3DPass *)dword_B473F0; /*0x85f030*/
    v145 = (NiD3DPassVtbl **)dword_B473F0; /*0x85f038*/
    if ( v145 ) /*0x85f03c*/
      ++v0->RefCount; /*0x85f03e*/
  }
  sub_85E570(v0); /*0x85f043*/
  v35 = v0->VertexShader; /*0x85f04d*/
  v36 = dword_B4728C; /*0x85f055*/
  if ( v35 != (NiD3DVertexShader *)dword_B4728C ) /*0x85f057*/
  {
    if ( v35 ) /*0x85f05b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v35 + 1) ) /*0x85f061*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v35)(v35, 1); /*0x85f077*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v36; /*0x85f07b*/
    if ( v36 ) /*0x85f07e*/
      InterlockedIncrement((volatile LONG *)(v36 + 4)); /*0x85f084*/
  }
  v37 = v0->PixelShader; /*0x85f08f*/
  v38 = dword_B46EF0; /*0x85f094*/
  if ( v37 != (NiD3DPixelShader *)dword_B46EF0 ) /*0x85f096*/
  {
    if ( v37 ) /*0x85f09a*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v37 + 1) ) /*0x85f0a0*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v37)(v37, 1); /*0x85f0b6*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v38; /*0x85f0ba*/
    if ( v38 ) /*0x85f0bd*/
      InterlockedIncrement((volatile LONG *)(v38 + 4)); /*0x85f0c3*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f0c9*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f0d4*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f0e0*/
  if ( !v0->RenderStateGroup ) /*0x85f0e5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f0f0*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f0fc*/
  if ( !v0->RenderStateGroup ) /*0x85f101*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f10c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f118*/
  if ( !v0->RenderStateGroup ) /*0x85f11d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f128*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f134*/
  v2 = v0 == (NiD3DPass *)dword_B473F4; /*0x85f139*/
  dword_B469A8 = 0x3000C; /*0x85f13f*/
  dword_B46A80 = 0x16; /*0x85f145*/
  if ( !v2 ) /*0x85f14f*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f151*/
    if ( v2 ) /*0x85f155*/
      sub_7604D0(v0); /*0x85f159*/
    v0 = (NiD3DPass *)dword_B473F4; /*0x85f15e*/
    v145 = (NiD3DPassVtbl **)dword_B473F4; /*0x85f166*/
    if ( v145 ) /*0x85f16a*/
      ++v0->RefCount; /*0x85f16c*/
  }
  sub_85E570(v0); /*0x85f171*/
  v39 = v0->VertexShader; /*0x85f17b*/
  v40 = dword_B47288[0]; /*0x85f183*/
  if ( v39 != (NiD3DVertexShader *)dword_B47288[0] ) /*0x85f185*/
  {
    if ( v39 ) /*0x85f189*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v39 + 1) ) /*0x85f18f*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v39)(v39, 1); /*0x85f1a5*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v40; /*0x85f1a9*/
    if ( v40 ) /*0x85f1ac*/
      InterlockedIncrement((volatile LONG *)(v40 + 4)); /*0x85f1b2*/
  }
  v41 = v0->PixelShader; /*0x85f1bd*/
  v42 = dword_B46EF8; /*0x85f1c2*/
  if ( v41 != (NiD3DPixelShader *)dword_B46EF8 ) /*0x85f1c4*/
  {
    if ( v41 ) /*0x85f1c8*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v41 + 1) ) /*0x85f1ce*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v41)(v41, 1); /*0x85f1e4*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v42; /*0x85f1e8*/
    if ( v42 ) /*0x85f1eb*/
      InterlockedIncrement((volatile LONG *)(v42 + 4)); /*0x85f1f1*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f1f7*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f202*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f20e*/
  if ( !v0->RenderStateGroup ) /*0x85f213*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f21e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f22a*/
  if ( !v0->RenderStateGroup ) /*0x85f22f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f23a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f246*/
  if ( !v0->RenderStateGroup ) /*0x85f24b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f256*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f262*/
  v2 = v0 == (NiD3DPass *)dword_B473F8; /*0x85f267*/
  dword_B469AC = 0x30002; /*0x85f26d*/
  dword_B46A84 = 0x36; /*0x85f277*/
  if ( !v2 ) /*0x85f281*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f283*/
    if ( v2 ) /*0x85f287*/
      sub_7604D0(v0); /*0x85f28b*/
    v0 = (NiD3DPass *)dword_B473F8; /*0x85f290*/
    v145 = (NiD3DPassVtbl **)dword_B473F8; /*0x85f298*/
    if ( v145 ) /*0x85f29c*/
      ++v0->RefCount; /*0x85f29e*/
  }
  sub_85E570(v0); /*0x85f2a3*/
  v43 = v0->VertexShader; /*0x85f2ad*/
  v44 = dword_B4728C; /*0x85f2b5*/
  if ( v43 != (NiD3DVertexShader *)dword_B4728C ) /*0x85f2b7*/
  {
    if ( v43 ) /*0x85f2bb*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v43 + 1) ) /*0x85f2c1*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v43)(v43, 1); /*0x85f2d7*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v44; /*0x85f2db*/
    if ( v44 ) /*0x85f2de*/
      InterlockedIncrement((volatile LONG *)(v44 + 4)); /*0x85f2e4*/
  }
  v45 = v0->PixelShader; /*0x85f2ef*/
  v46 = dword_B46EF8; /*0x85f2f4*/
  if ( v45 != (NiD3DPixelShader *)dword_B46EF8 ) /*0x85f2f6*/
  {
    if ( v45 ) /*0x85f2fa*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v45 + 1) ) /*0x85f300*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v45)(v45, 1); /*0x85f316*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v46; /*0x85f31a*/
    if ( v46 ) /*0x85f31d*/
      InterlockedIncrement((volatile LONG *)(v46 + 4)); /*0x85f323*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f329*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f334*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f340*/
  if ( !v0->RenderStateGroup ) /*0x85f345*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f350*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f35c*/
  if ( !v0->RenderStateGroup ) /*0x85f361*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f36c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f378*/
  if ( !v0->RenderStateGroup ) /*0x85f37d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f388*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f394*/
  v2 = v0 == (NiD3DPass *)dword_B473FC; /*0x85f399*/
  dword_B469B0 = 0x3000C; /*0x85f39f*/
  dword_B46A88 = 0x36; /*0x85f3a5*/
  if ( !v2 ) /*0x85f3af*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f3b1*/
    if ( v2 ) /*0x85f3b5*/
      sub_7604D0(v0); /*0x85f3b9*/
    v0 = (NiD3DPass *)dword_B473FC; /*0x85f3be*/
    v145 = (NiD3DPassVtbl **)dword_B473FC; /*0x85f3c6*/
    if ( v145 ) /*0x85f3ca*/
      ++v0->RefCount; /*0x85f3cc*/
  }
  sub_85E570(v0); /*0x85f3d1*/
  v47 = v0->VertexShader; /*0x85f3db*/
  v48 = dword_B47290; /*0x85f3e3*/
  if ( v47 != (NiD3DVertexShader *)dword_B47290 ) /*0x85f3e5*/
  {
    if ( v47 ) /*0x85f3e9*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v47 + 1) ) /*0x85f3ef*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v47)(v47, 1); /*0x85f405*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v48; /*0x85f409*/
    if ( v48 ) /*0x85f40c*/
      InterlockedIncrement((volatile LONG *)(v48 + 4)); /*0x85f412*/
  }
  v49 = v0->PixelShader; /*0x85f41d*/
  v50 = dword_B46ED8[0]; /*0x85f422*/
  if ( v49 != (NiD3DPixelShader *)dword_B46ED8[0] ) /*0x85f424*/
  {
    if ( v49 ) /*0x85f428*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v49 + 1) ) /*0x85f42e*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v49)(v49, 1); /*0x85f444*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v50; /*0x85f448*/
    if ( v50 ) /*0x85f44b*/
      InterlockedIncrement((volatile LONG *)(v50 + 4)); /*0x85f451*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f457*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f462*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f46e*/
  if ( !v0->RenderStateGroup ) /*0x85f473*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f47e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f48a*/
  if ( !v0->RenderStateGroup ) /*0x85f48f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f49a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f4a6*/
  if ( !v0->RenderStateGroup ) /*0x85f4ab*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f4b6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f4c2*/
  v2 = v0 == (NiD3DPass *)dword_B47400; /*0x85f4c7*/
  dword_B469B4 = 0x30002; /*0x85f4cd*/
  dword_B46A8C = 0x16; /*0x85f4d7*/
  if ( !v2 ) /*0x85f4e1*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f4e3*/
    if ( v2 ) /*0x85f4e7*/
      sub_7604D0(v0); /*0x85f4eb*/
    v0 = (NiD3DPass *)dword_B47400; /*0x85f4f0*/
    v145 = (NiD3DPassVtbl **)dword_B47400; /*0x85f4f8*/
    if ( v145 ) /*0x85f4fc*/
      ++v0->RefCount; /*0x85f4fe*/
  }
  sub_85E570(v0); /*0x85f503*/
  v51 = v0->VertexShader; /*0x85f50d*/
  v52 = dword_B47294; /*0x85f515*/
  if ( v51 != (NiD3DVertexShader *)dword_B47294 ) /*0x85f517*/
  {
    if ( v51 ) /*0x85f51b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v51 + 1) ) /*0x85f521*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v51)(v51, 1); /*0x85f537*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v52; /*0x85f53b*/
    if ( v52 ) /*0x85f53e*/
      InterlockedIncrement((volatile LONG *)(v52 + 4)); /*0x85f544*/
  }
  v53 = v0->PixelShader; /*0x85f54f*/
  v54 = dword_B46ED8[0]; /*0x85f554*/
  if ( v53 != (NiD3DPixelShader *)dword_B46ED8[0] ) /*0x85f556*/
  {
    if ( v53 ) /*0x85f55a*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v53 + 1) ) /*0x85f560*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v53)(v53, 1); /*0x85f576*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v54; /*0x85f57a*/
    if ( v54 ) /*0x85f57d*/
      InterlockedIncrement((volatile LONG *)(v54 + 4)); /*0x85f583*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f589*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f594*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f5a0*/
  if ( !v0->RenderStateGroup ) /*0x85f5a5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f5b0*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f5bc*/
  if ( !v0->RenderStateGroup ) /*0x85f5c1*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f5cc*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f5d8*/
  if ( !v0->RenderStateGroup ) /*0x85f5dd*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f5e8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f5f4*/
  v2 = v0 == (NiD3DPass *)dword_B47404; /*0x85f5f9*/
  dword_B469B8 = 0x3000C; /*0x85f5ff*/
  dword_B46A90 = 0x16; /*0x85f605*/
  if ( !v2 ) /*0x85f60f*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f611*/
    if ( v2 ) /*0x85f615*/
      sub_7604D0(v0); /*0x85f619*/
    v0 = (NiD3DPass *)dword_B47404; /*0x85f61e*/
    v145 = (NiD3DPassVtbl **)dword_B47404; /*0x85f626*/
    if ( v145 ) /*0x85f62a*/
      ++v0->RefCount; /*0x85f62c*/
  }
  sub_85E570(v0); /*0x85f631*/
  v55 = v0->VertexShader; /*0x85f63b*/
  v56 = dword_B47290; /*0x85f643*/
  if ( v55 != (NiD3DVertexShader *)dword_B47290 ) /*0x85f645*/
  {
    if ( v55 ) /*0x85f649*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v55 + 1) ) /*0x85f64f*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v55)(v55, 1); /*0x85f665*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v56; /*0x85f669*/
    if ( v56 ) /*0x85f66c*/
      InterlockedIncrement((volatile LONG *)(v56 + 4)); /*0x85f672*/
  }
  v57 = v0->PixelShader; /*0x85f67d*/
  v58 = dword_B46EE8; /*0x85f682*/
  if ( v57 != (NiD3DPixelShader *)dword_B46EE8 ) /*0x85f684*/
  {
    if ( v57 ) /*0x85f688*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v57 + 1) ) /*0x85f68e*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v57)(v57, 1); /*0x85f6a4*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v58; /*0x85f6a8*/
    if ( v58 ) /*0x85f6ab*/
      InterlockedIncrement((volatile LONG *)(v58 + 4)); /*0x85f6b1*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f6b7*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f6c2*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f6ce*/
  if ( !v0->RenderStateGroup ) /*0x85f6d3*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f6de*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f6ea*/
  if ( !v0->RenderStateGroup ) /*0x85f6ef*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f6fa*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f706*/
  if ( !v0->RenderStateGroup ) /*0x85f70b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f716*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f722*/
  v2 = v0 == (NiD3DPass *)dword_B47408; /*0x85f727*/
  dword_B469BC = 0x30012; /*0x85f72d*/
  dword_B46A94 = 0x16; /*0x85f737*/
  if ( !v2 ) /*0x85f741*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f743*/
    if ( v2 ) /*0x85f747*/
      sub_7604D0(v0); /*0x85f74b*/
    v0 = (NiD3DPass *)dword_B47408; /*0x85f750*/
    v145 = (NiD3DPassVtbl **)dword_B47408; /*0x85f758*/
    if ( v145 ) /*0x85f75c*/
      ++v0->RefCount; /*0x85f75e*/
  }
  sub_85E570(v0); /*0x85f763*/
  v59 = v0->VertexShader; /*0x85f76d*/
  v60 = dword_B47290; /*0x85f775*/
  if ( v59 != (NiD3DVertexShader *)dword_B47290 ) /*0x85f777*/
  {
    if ( v59 ) /*0x85f77b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v59 + 1) ) /*0x85f781*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v59)(v59, 1); /*0x85f797*/
    }
    v0->VertexShader = (NiD3DVertexShader *)v60; /*0x85f79b*/
    if ( v60 ) /*0x85f79e*/
      InterlockedIncrement((volatile LONG *)(v60 + 4)); /*0x85f7a4*/
  }
  v61 = v0->PixelShader; /*0x85f7af*/
  v62 = dword_B46EF8; /*0x85f7b4*/
  if ( v61 != (NiD3DPixelShader *)dword_B46EF8 ) /*0x85f7b6*/
  {
    if ( v61 ) /*0x85f7ba*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v61 + 1) ) /*0x85f7c0*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v61)(v61, 1); /*0x85f7d6*/
    }
    v0->PixelShader = (NiD3DPixelShader *)v62; /*0x85f7da*/
    if ( v62 ) /*0x85f7dd*/
      InterlockedIncrement((volatile LONG *)(v62 + 4)); /*0x85f7e3*/
  }
  if ( !v0->RenderStateGroup ) /*0x85f7e9*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f7f4*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f800*/
  if ( !v0->RenderStateGroup ) /*0x85f805*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f810*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f81c*/
  if ( !v0->RenderStateGroup ) /*0x85f821*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f82c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f838*/
  if ( !v0->RenderStateGroup ) /*0x85f83d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f848*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f854*/
  v2 = v0 == (NiD3DPass *)dword_B4740C; /*0x85f861*/
  dword_B469C0 = 0x30002; /*0x85f867*/
  dword_B46A98 = 0x36; /*0x85f871*/
  if ( !v2 ) /*0x85f877*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f879*/
    if ( v2 ) /*0x85f87c*/
      sub_7604D0(v0); /*0x85f880*/
    v0 = (NiD3DPass *)dword_B4740C; /*0x85f885*/
    v145 = (NiD3DPassVtbl **)dword_B4740C; /*0x85f88d*/
    if ( v145 ) /*0x85f891*/
      ++v0->RefCount; /*0x85f893*/
  }
  sub_85E570(v0); /*0x85f898*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B47294); /*0x85f8a9*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46EF8); /*0x85f8b7*/
  if ( !v0->RenderStateGroup ) /*0x85f8bc*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f8c7*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f8d3*/
  if ( !v0->RenderStateGroup ) /*0x85f8d8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f8e3*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f8ef*/
  if ( !v0->RenderStateGroup ) /*0x85f8f4*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f8ff*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f90b*/
  if ( !v0->RenderStateGroup ) /*0x85f910*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f91b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f927*/
  v2 = v0 == (NiD3DPass *)dword_B47410; /*0x85f92c*/
  dword_B469C4 = 0x3000C; /*0x85f932*/
  dword_B46A9C = 0x36; /*0x85f938*/
  if ( !v2 ) /*0x85f93e*/
  {
    v2 = v0->RefCount-- == 1; /*0x85f940*/
    if ( v2 ) /*0x85f943*/
      sub_7604D0(v0); /*0x85f947*/
    v0 = (NiD3DPass *)dword_B47410; /*0x85f94c*/
    v145 = (NiD3DPassVtbl **)dword_B47410; /*0x85f954*/
    if ( v145 ) /*0x85f958*/
      ++v0->RefCount; /*0x85f95a*/
  }
  sub_85E570(v0); /*0x85f95f*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B47298); /*0x85f96f*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F00); /*0x85f97d*/
  if ( !v0->RenderStateGroup ) /*0x85f982*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f98d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85f999*/
  if ( !v0->RenderStateGroup ) /*0x85f99e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f9a9*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85f9b5*/
  if ( !v0->RenderStateGroup ) /*0x85f9ba*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f9c5*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85f9d1*/
  if ( !v0->RenderStateGroup ) /*0x85f9d6*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85f9e1*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85f9ed*/
  v2 = v0 == (NiD3DPass *)dword_B47414; /*0x85f9f2*/
  dword_B469C8 = 0xC430002; /*0x85f9fd*/
  dword_B46AA0 = 0x16; /*0x85fa03*/
  if ( !v2 ) /*0x85fa0d*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fa0f*/
    if ( v2 ) /*0x85fa12*/
      sub_7604D0(v0); /*0x85fa16*/
    v0 = (NiD3DPass *)dword_B47414; /*0x85fa1b*/
    v145 = (NiD3DPassVtbl **)dword_B47414; /*0x85fa23*/
    if ( v145 ) /*0x85fa27*/
      ++v0->RefCount; /*0x85fa29*/
  }
  sub_85E570(v0); /*0x85fa2e*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B4729C); /*0x85fa3f*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F00); /*0x85fa4c*/
  if ( !v0->RenderStateGroup ) /*0x85fa51*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fa5c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fa68*/
  if ( !v0->RenderStateGroup ) /*0x85fa6d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fa78*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fa84*/
  if ( !v0->RenderStateGroup ) /*0x85fa89*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fa94*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85faa0*/
  if ( !v0->RenderStateGroup ) /*0x85faa5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fab0*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85fabc*/
  v2 = v0 == (NiD3DPass *)dword_B47418; /*0x85fac1*/
  dword_B469CC = 0xC43000C; /*0x85facc*/
  dword_B46AA4 = 0x16; /*0x85fad2*/
  if ( !v2 ) /*0x85fadc*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fade*/
    if ( v2 ) /*0x85fae2*/
      sub_7604D0(v0); /*0x85fae6*/
    v0 = (NiD3DPass *)dword_B47418; /*0x85faeb*/
    v145 = (NiD3DPassVtbl **)dword_B47418; /*0x85faf3*/
    if ( v145 ) /*0x85fafc*/
      ++v0->RefCount; /*0x85fafe*/
  }
  sub_85E570(v0); /*0x85fb09*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A0); /*0x85fb1a*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F08); /*0x85fb28*/
  if ( !v0->RenderStateGroup ) /*0x85fb2d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fb38*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fb43*/
  if ( !v0->RenderStateGroup ) /*0x85fb48*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fb53*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fb5f*/
  if ( !v0->RenderStateGroup ) /*0x85fb64*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fb6f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85fb7a*/
  if ( !v0->RenderStateGroup ) /*0x85fb7f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fb8a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85fb96*/
  v2 = v0 == (NiD3DPass *)dword_B4741C; /*0x85fb9b*/
  dword_B469D0 = 0xC430002; /*0x85fba1*/
  dword_B46AA8 = 0x1E; /*0x85fba7*/
  if ( !v2 ) /*0x85fbb1*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fbb3*/
    if ( v2 ) /*0x85fbb7*/
      sub_7604D0(v0); /*0x85fbbb*/
    v0 = (NiD3DPass *)dword_B4741C; /*0x85fbc0*/
    v145 = (NiD3DPassVtbl **)dword_B4741C; /*0x85fbc8*/
    if ( v145 ) /*0x85fbcc*/
      ++v0->RefCount; /*0x85fbce*/
  }
  sub_85E570(v0); /*0x85fbd2*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B47298); /*0x85fbe2*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F10); /*0x85fbf0*/
  if ( !v0->RenderStateGroup ) /*0x85fbf5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fc00*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fc0b*/
  if ( !v0->RenderStateGroup ) /*0x85fc10*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fc1b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fc27*/
  if ( !v0->RenderStateGroup ) /*0x85fc2c*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fc37*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85fc42*/
  if ( !v0->RenderStateGroup ) /*0x85fc47*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fc52*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85fc5e*/
  v2 = v0 == (NiD3DPass *)dword_B47420; /*0x85fc63*/
  dword_B469D4 = 0xC430002; /*0x85fc69*/
  dword_B46AAC = 0x16; /*0x85fc6f*/
  if ( !v2 ) /*0x85fc79*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fc7b*/
    if ( v2 ) /*0x85fc7f*/
      sub_7604D0(v0); /*0x85fc83*/
    v0 = (NiD3DPass *)dword_B47420; /*0x85fc88*/
    v145 = (NiD3DPassVtbl **)dword_B47420; /*0x85fc90*/
    if ( v145 ) /*0x85fc94*/
      ++v0->RefCount; /*0x85fc96*/
  }
  sub_85E570(v0); /*0x85fc9a*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B47298); /*0x85fcab*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F18); /*0x85fcb8*/
  if ( !v0->RenderStateGroup ) /*0x85fcbd*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fcc8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fcd3*/
  if ( !v0->RenderStateGroup ) /*0x85fcd8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fce3*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fcef*/
  if ( !v0->RenderStateGroup ) /*0x85fcf4*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fcff*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85fd0a*/
  if ( !v0->RenderStateGroup ) /*0x85fd0f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fd1a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85fd26*/
  v2 = v0 == (NiD3DPass *)dword_B47424; /*0x85fd2b*/
  dword_B469D8 = 0xC430002; /*0x85fd31*/
  dword_B46AB0 = 0x16; /*0x85fd37*/
  if ( !v2 ) /*0x85fd41*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fd43*/
    if ( v2 ) /*0x85fd47*/
      sub_7604D0(v0); /*0x85fd4b*/
    v0 = (NiD3DPass *)dword_B47424; /*0x85fd50*/
    v145 = (NiD3DPassVtbl **)dword_B47424; /*0x85fd58*/
    if ( v145 ) /*0x85fd5c*/
      ++v0->RefCount; /*0x85fd5e*/
  }
  sub_85E570(v0); /*0x85fd62*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B4729C); /*0x85fd73*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F18); /*0x85fd81*/
  if ( !v0->RenderStateGroup ) /*0x85fd86*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fd91*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fd9c*/
  if ( !v0->RenderStateGroup ) /*0x85fda1*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fdac*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fdb8*/
  if ( !v0->RenderStateGroup ) /*0x85fdbd*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fdc8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85fdd3*/
  if ( !v0->RenderStateGroup ) /*0x85fdd8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fde3*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85fdef*/
  v2 = v0 == (NiD3DPass *)dword_B47428; /*0x85fdf4*/
  dword_B469DC = 0xC43000C; /*0x85fdfa*/
  dword_B46AB4 = 0x16; /*0x85fe00*/
  if ( !v2 ) /*0x85fe0a*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fe0c*/
    if ( v2 ) /*0x85fe10*/
      sub_7604D0(v0); /*0x85fe14*/
    v0 = (NiD3DPass *)dword_B47428; /*0x85fe19*/
    v145 = (NiD3DPassVtbl **)dword_B47428; /*0x85fe21*/
    if ( v145 ) /*0x85fe25*/
      ++v0->RefCount; /*0x85fe27*/
  }
  sub_85E570(v0); /*0x85fe2b*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B47298); /*0x85fe3b*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F20); /*0x85fe49*/
  if ( !v0->RenderStateGroup ) /*0x85fe4e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fe59*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fe64*/
  if ( !v0->RenderStateGroup ) /*0x85fe69*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fe74*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85fe80*/
  if ( !v0->RenderStateGroup ) /*0x85fe85*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85fe90*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85fe9b*/
  if ( !v0->RenderStateGroup ) /*0x85fea0*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85feab*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85feb7*/
  v2 = v0 == (NiD3DPass *)dword_B4742C; /*0x85febc*/
  dword_B469E0 = 0xC430002; /*0x85fec7*/
  dword_B46AB8 = 0x36; /*0x85fecd*/
  if ( !v2 ) /*0x85fed3*/
  {
    v2 = v0->RefCount-- == 1; /*0x85fed5*/
    if ( v2 ) /*0x85fed9*/
      sub_7604D0(v0); /*0x85fedd*/
    v0 = (NiD3DPass *)dword_B4742C; /*0x85fee2*/
    v145 = (NiD3DPassVtbl **)dword_B4742C; /*0x85feea*/
    if ( v145 ) /*0x85feee*/
      ++v0->RefCount; /*0x85fef0*/
  }
  sub_85E570(v0); /*0x85fef5*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B4729C); /*0x85ff06*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F20); /*0x85ff13*/
  if ( !v0->RenderStateGroup ) /*0x85ff18*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ff23*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85ff2f*/
  if ( !v0->RenderStateGroup ) /*0x85ff34*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ff3f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x85ff4b*/
  if ( !v0->RenderStateGroup ) /*0x85ff50*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ff5b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x85ff67*/
  if ( !v0->RenderStateGroup ) /*0x85ff6c*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ff77*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x85ff83*/
  v2 = v0 == (NiD3DPass *)dword_B47430; /*0x85ff88*/
  dword_B469E4 = 0xC43000C; /*0x85ff8e*/
  dword_B46ABC = 0x36; /*0x85ff94*/
  if ( !v2 ) /*0x85ff9a*/
  {
    v2 = v0->RefCount-- == 1; /*0x85ff9c*/
    if ( v2 ) /*0x85ffa0*/
      sub_7604D0(v0); /*0x85ffa4*/
    v0 = (NiD3DPass *)dword_B47430; /*0x85ffa9*/
    v145 = (NiD3DPassVtbl **)dword_B47430; /*0x85ffb1*/
    if ( v145 ) /*0x85ffb5*/
      ++v0->RefCount; /*0x85ffb7*/
  }
  sub_85E570(v0); /*0x85ffbc*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A0); /*0x85ffcd*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F00); /*0x85ffdb*/
  if ( !v0->RenderStateGroup ) /*0x85ffe0*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x85ffeb*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x85fff7*/
  if ( !v0->RenderStateGroup ) /*0x85fffc*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860007*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860013*/
  if ( !v0->RenderStateGroup ) /*0x860018*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860023*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x86002f*/
  if ( !v0->RenderStateGroup ) /*0x860034*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86003f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x86004b*/
  v2 = v0 == (NiD3DPass *)dword_B47434; /*0x860050*/
  dword_B469E8 = 0xC430002; /*0x860056*/
  dword_B46AC0 = 0x16; /*0x86005c*/
  if ( !v2 ) /*0x860066*/
  {
    v2 = v0->RefCount-- == 1; /*0x860068*/
    if ( v2 ) /*0x86006c*/
      sub_7604D0(v0); /*0x860070*/
    v0 = (NiD3DPass *)dword_B47434; /*0x860075*/
    v145 = (NiD3DPassVtbl **)dword_B47434; /*0x86007d*/
    if ( v145 ) /*0x860081*/
      ++v0->RefCount; /*0x860083*/
  }
  sub_85E570(v0); /*0x860088*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A4); /*0x860098*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F00); /*0x8600a6*/
  if ( !v0->RenderStateGroup ) /*0x8600ab*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8600b6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x8600c2*/
  if ( !v0->RenderStateGroup ) /*0x8600c7*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8600d2*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x8600de*/
  if ( !v0->RenderStateGroup ) /*0x8600e3*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8600ee*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x8600fa*/
  if ( !v0->RenderStateGroup ) /*0x8600ff*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86010a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860116*/
  v2 = v0 == (NiD3DPass *)dword_B47438; /*0x86011b*/
  dword_B469EC = 0xC43000C; /*0x860121*/
  dword_B46AC4 = 0x16; /*0x860127*/
  if ( !v2 ) /*0x860131*/
  {
    v2 = v0->RefCount-- == 1; /*0x860133*/
    if ( v2 ) /*0x860137*/
      sub_7604D0(v0); /*0x86013b*/
    v0 = (NiD3DPass *)dword_B47438; /*0x860140*/
    v145 = (NiD3DPassVtbl **)dword_B47438; /*0x860148*/
    if ( v145 ) /*0x86014c*/
      ++v0->RefCount; /*0x86014e*/
  }
  sub_85E570(v0); /*0x860153*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A0); /*0x860164*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F10); /*0x860171*/
  if ( !v0->RenderStateGroup ) /*0x860176*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860181*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x86018d*/
  if ( !v0->RenderStateGroup ) /*0x860192*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86019d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x8601a9*/
  if ( !v0->RenderStateGroup ) /*0x8601ae*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8601b9*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x8601c5*/
  if ( !v0->RenderStateGroup ) /*0x8601ca*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8601d5*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x8601e1*/
  v2 = v0 == (NiD3DPass *)dword_B4743C; /*0x8601e6*/
  dword_B469F0 = 0xC430002; /*0x8601ec*/
  dword_B46AC8 = 0x16; /*0x8601f2*/
  if ( !v2 ) /*0x8601fc*/
  {
    v2 = v0->RefCount-- == 1; /*0x8601fe*/
    if ( v2 ) /*0x860202*/
      sub_7604D0(v0); /*0x860206*/
    v0 = (NiD3DPass *)dword_B4743C; /*0x86020b*/
    v145 = (NiD3DPassVtbl **)dword_B4743C; /*0x860213*/
    if ( v145 ) /*0x860217*/
      ++v0->RefCount; /*0x860219*/
  }
  sub_85E570(v0); /*0x86021e*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A0); /*0x86022f*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F20); /*0x86023d*/
  if ( !v0->RenderStateGroup ) /*0x860242*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86024d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860259*/
  if ( !v0->RenderStateGroup ) /*0x86025e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860269*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860275*/
  if ( !v0->RenderStateGroup ) /*0x86027a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860285*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x860291*/
  if ( !v0->RenderStateGroup ) /*0x860296*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8602a1*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x8602ad*/
  v2 = v0 == (NiD3DPass *)dword_B47440; /*0x8602b2*/
  dword_B469F4 = 0xC430002; /*0x8602b8*/
  dword_B46ACC = 0x36; /*0x8602be*/
  if ( !v2 ) /*0x8602c4*/
  {
    v2 = v0->RefCount-- == 1; /*0x8602c6*/
    if ( v2 ) /*0x8602ca*/
      sub_7604D0(v0); /*0x8602ce*/
    v0 = (NiD3DPass *)dword_B47440; /*0x8602d3*/
    v145 = (NiD3DPassVtbl **)dword_B47440; /*0x8602db*/
    if ( v145 ) /*0x8602df*/
      ++v0->RefCount; /*0x8602e1*/
  }
  sub_85E570(v0); /*0x8602e6*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A4); /*0x8602f6*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F20); /*0x860304*/
  if ( !v0->RenderStateGroup ) /*0x860309*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860314*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860320*/
  if ( !v0->RenderStateGroup ) /*0x860325*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860330*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x86033c*/
  if ( !v0->RenderStateGroup ) /*0x860341*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86034c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 1, 0); /*0x860358*/
  if ( !v0->RenderStateGroup ) /*0x86035d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860368*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860374*/
  v2 = v0 == (NiD3DPass *)dword_B47444; /*0x860379*/
  dword_B469F8 = 0xC43000C; /*0x86037f*/
  dword_B46AD0 = 0x36; /*0x860385*/
  if ( !v2 ) /*0x86038b*/
  {
    v2 = v0->RefCount-- == 1; /*0x86038d*/
    if ( v2 ) /*0x860391*/
      sub_7604D0(v0); /*0x860395*/
    v0 = (NiD3DPass *)dword_B47444; /*0x86039a*/
    v145 = (NiD3DPassVtbl **)dword_B47444; /*0x8603a2*/
    if ( v145 ) /*0x8603a6*/
      ++v0->RefCount; /*0x8603a8*/
  }
  if ( v0->StageCount < 2 ) /*0x8603b6*/
  {
    v63 = sub_772630(&v147); /*0x8603c1*/
    LOBYTE(v148) = 2; /*0x8603ce*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v63); /*0x8603d2*/
    v64 = v147; /*0x8603d7*/
    LOBYTE(v148) = 1; /*0x8603dd*/
    if ( v147 ) /*0x8603e2*/
    {
      --v147[7].Unk08; /*0x8603e4*/
      if ( !v64[7].Unk08 ) /*0x8603ed*/
        sub_772560(v64); /*0x8603f2*/
    }
    v65 = a3; /*0x8603f7*/
    sub_801110((int)a3, 0, 1, 2); /*0x860401*/
    sub_760010(v0, v0->CurrentStage, v65); /*0x860410*/
    v66 = sub_772630(&v147); /*0x86041a*/
    LOBYTE(v148) = 3; /*0x860427*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v66); /*0x86042c*/
    v67 = v147; /*0x860431*/
    LOBYTE(v148) = 1; /*0x860437*/
    if ( v147 ) /*0x86043c*/
    {
      --v147[7].Unk08; /*0x86043e*/
      if ( !v67[7].Unk08 ) /*0x860447*/
        sub_772560(v67); /*0x86044c*/
    }
    v68 = a3; /*0x860451*/
    sub_801110((int)a3, 0, 1, 2); /*0x86045b*/
    sub_760010(v0, v0->CurrentStage, v68); /*0x86046a*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A8); /*0x860477*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F28[0]); /*0x860485*/
  if ( !v0->RenderStateGroup ) /*0x86048a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860495*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x8604a1*/
  if ( !v0->RenderStateGroup ) /*0x8604a6*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8604b1*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x8604bd*/
  if ( !v0->RenderStateGroup ) /*0x8604c2*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8604cd*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x8604d9*/
  if ( !v0->RenderStateGroup ) /*0x8604de*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8604e9*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x8604f5*/
  if ( !v0->RenderStateGroup ) /*0x8604fa*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860505*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x860510*/
  if ( !v0->RenderStateGroup ) /*0x860515*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860520*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x86052b*/
  if ( !v0->RenderStateGroup ) /*0x860530*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86053b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860547*/
  v2 = v0 == (NiD3DPass *)dword_B47448; /*0x86054c*/
  dword_B469FC = 0x8802; /*0x860557*/
  dword_B46AD4 = 0x10; /*0x86055d*/
  if ( !v2 ) /*0x860567*/
  {
    v2 = v0->RefCount-- == 1; /*0x860569*/
    if ( v2 ) /*0x86056d*/
      sub_7604D0(v0); /*0x860571*/
    v0 = (NiD3DPass *)dword_B47448; /*0x860576*/
    v145 = (NiD3DPassVtbl **)dword_B47448; /*0x86057e*/
    if ( v145 ) /*0x860582*/
      ++v0->RefCount; /*0x860584*/
  }
  if ( v0->StageCount < 2 ) /*0x86058d*/
  {
    v69 = sub_772630(&v147); /*0x860598*/
    LOBYTE(v148) = 4; /*0x8605a5*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v69); /*0x8605aa*/
    v70 = v147; /*0x8605af*/
    LOBYTE(v148) = 1; /*0x8605b5*/
    if ( v147 ) /*0x8605ba*/
    {
      --v147[7].Unk08; /*0x8605bc*/
      if ( !v70[7].Unk08 ) /*0x8605c5*/
        sub_772560(v70); /*0x8605ca*/
    }
    v71 = a3; /*0x8605cf*/
    sub_801110((int)a3, 0, 1, 2); /*0x8605d9*/
    sub_760010(v0, v0->CurrentStage, v71); /*0x8605e8*/
    v72 = sub_772630(&v147); /*0x8605f2*/
    LOBYTE(v148) = 5; /*0x8605ff*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v72); /*0x860604*/
    v73 = v147; /*0x860609*/
    LOBYTE(v148) = 1; /*0x86060f*/
    if ( v147 ) /*0x860614*/
    {
      --v147[7].Unk08; /*0x860616*/
      if ( !v73[7].Unk08 ) /*0x86061f*/
        sub_772560(v73); /*0x860624*/
    }
    v74 = a3; /*0x860629*/
    sub_801110((int)a3, 0, 1, 2); /*0x860633*/
    sub_760010(v0, v0->CurrentStage, v74); /*0x860642*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472A8); /*0x86064f*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F2C); /*0x86065d*/
  if ( !v0->RenderStateGroup ) /*0x860662*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86066d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860679*/
  if ( !v0->RenderStateGroup ) /*0x86067e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860689*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860695*/
  if ( !v0->RenderStateGroup ) /*0x86069a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8606a5*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x8606b1*/
  if ( !v0->RenderStateGroup ) /*0x8606b6*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8606c1*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x8606cd*/
  if ( !v0->RenderStateGroup ) /*0x8606d2*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8606dd*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x8606e8*/
  if ( !v0->RenderStateGroup ) /*0x8606ed*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8606f8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x860703*/
  if ( !v0->RenderStateGroup ) /*0x860708*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860713*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x86071f*/
  v2 = v0 == (NiD3DPass *)dword_B4744C; /*0x860724*/
  dword_B46A00 = 0x8802; /*0x86072a*/
  dword_B46AD8 = 0x10; /*0x860730*/
  if ( !v2 ) /*0x86073a*/
  {
    v2 = v0->RefCount-- == 1; /*0x86073c*/
    if ( v2 ) /*0x860740*/
      sub_7604D0(v0); /*0x860744*/
    v0 = (NiD3DPass *)dword_B4744C; /*0x860749*/
    v145 = (NiD3DPassVtbl **)dword_B4744C; /*0x860751*/
    if ( v145 ) /*0x860755*/
      ++v0->RefCount; /*0x860757*/
  }
  if ( v0->StageCount < 2 ) /*0x860760*/
  {
    v75 = sub_772630(&v147); /*0x86076b*/
    LOBYTE(v148) = 6; /*0x860778*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v75); /*0x86077d*/
    v76 = v147; /*0x860782*/
    LOBYTE(v148) = 1; /*0x860788*/
    if ( v147 ) /*0x86078d*/
    {
      --v147[7].Unk08; /*0x86078f*/
      if ( !v76[7].Unk08 ) /*0x860798*/
        sub_772560(v76); /*0x86079d*/
    }
    v77 = a3; /*0x8607a2*/
    sub_801110((int)a3, 0, 1, 2); /*0x8607ac*/
    sub_760010(v0, v0->CurrentStage, v77); /*0x8607bb*/
    v78 = sub_772630(&v147); /*0x8607c5*/
    LOBYTE(v148) = 7; /*0x8607d2*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v78); /*0x8607d7*/
    v79 = v147; /*0x8607dc*/
    LOBYTE(v148) = 1; /*0x8607e2*/
    if ( v147 ) /*0x8607e7*/
    {
      --v147[7].Unk08; /*0x8607e9*/
      if ( !v79[7].Unk08 ) /*0x8607f2*/
        sub_772560(v79); /*0x8607f7*/
    }
    v80 = a3; /*0x8607fc*/
    sub_801110((int)a3, 0, 1, 2); /*0x860806*/
    sub_760010(v0, v0->CurrentStage, v80); /*0x860815*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472AC); /*0x860822*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F28[0]); /*0x860830*/
  if ( !v0->RenderStateGroup ) /*0x860835*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860840*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x86084c*/
  if ( !v0->RenderStateGroup ) /*0x860851*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86085c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860868*/
  if ( !v0->RenderStateGroup ) /*0x86086d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860878*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x860884*/
  if ( !v0->RenderStateGroup ) /*0x860889*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860894*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x8608a0*/
  if ( !v0->RenderStateGroup ) /*0x8608a5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8608b0*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x8608bb*/
  if ( !v0->RenderStateGroup ) /*0x8608c0*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8608cb*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x8608d6*/
  if ( !v0->RenderStateGroup ) /*0x8608db*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8608e6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x8608f2*/
  v2 = v0 == (NiD3DPass *)dword_B47450; /*0x8608f7*/
  dword_B46A04 = 0x8802; /*0x8608fd*/
  dword_B46ADC = 0x10; /*0x860903*/
  if ( !v2 ) /*0x86090d*/
  {
    v2 = v0->RefCount-- == 1; /*0x86090f*/
    if ( v2 ) /*0x860913*/
      sub_7604D0(v0); /*0x860917*/
    v0 = (NiD3DPass *)dword_B47450; /*0x86091c*/
    v145 = (NiD3DPassVtbl **)dword_B47450; /*0x860924*/
    if ( v145 ) /*0x860928*/
      ++v0->RefCount; /*0x86092a*/
  }
  if ( v0->StageCount < 2 ) /*0x860933*/
  {
    v81 = sub_772630(&v147); /*0x86093e*/
    LOBYTE(v148) = 8; /*0x86094b*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v81); /*0x860950*/
    v82 = v147; /*0x860955*/
    LOBYTE(v148) = 1; /*0x86095b*/
    if ( v147 ) /*0x860960*/
    {
      --v147[7].Unk08; /*0x860962*/
      if ( !v82[7].Unk08 ) /*0x86096b*/
        sub_772560(v82); /*0x860970*/
    }
    v83 = a3; /*0x860975*/
    sub_801110((int)a3, 0, 1, 2); /*0x86097f*/
    sub_760010(v0, v0->CurrentStage, v83); /*0x86098e*/
    v84 = sub_772630(&v147); /*0x860998*/
    LOBYTE(v148) = 9; /*0x8609a5*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v84); /*0x8609aa*/
    v85 = v147; /*0x8609af*/
    LOBYTE(v148) = 1; /*0x8609b5*/
    if ( v147 ) /*0x8609ba*/
    {
      --v147[7].Unk08; /*0x8609bc*/
      if ( !v85[7].Unk08 ) /*0x8609c5*/
        sub_772560(v85); /*0x8609ca*/
    }
    v86 = a3; /*0x8609cf*/
    sub_801110((int)a3, 0, 1, 2); /*0x8609d9*/
    sub_760010(v0, v0->CurrentStage, v86); /*0x8609e8*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472AC); /*0x8609f5*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F2C); /*0x860a03*/
  if ( !v0->RenderStateGroup ) /*0x860a08*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a13*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860a1f*/
  if ( !v0->RenderStateGroup ) /*0x860a24*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a2f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860a3b*/
  if ( !v0->RenderStateGroup ) /*0x860a40*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a4b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x860a57*/
  if ( !v0->RenderStateGroup ) /*0x860a5c*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a67*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x860a73*/
  if ( !v0->RenderStateGroup ) /*0x860a78*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a83*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x860a8e*/
  if ( !v0->RenderStateGroup ) /*0x860a93*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860a9e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x860aa9*/
  if ( !v0->RenderStateGroup ) /*0x860aae*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860ab9*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860ac5*/
  v2 = v0 == (NiD3DPass *)dword_B47454; /*0x860aca*/
  dword_B46A08 = 0x8802; /*0x860ad0*/
  dword_B46AE0 = 0x10; /*0x860ad6*/
  if ( !v2 ) /*0x860ae0*/
  {
    v2 = v0->RefCount-- == 1; /*0x860ae2*/
    if ( v2 ) /*0x860ae6*/
      sub_7604D0(v0); /*0x860aea*/
    v0 = (NiD3DPass *)dword_B47454; /*0x860aef*/
    v145 = (NiD3DPassVtbl **)dword_B47454; /*0x860af7*/
    if ( v145 ) /*0x860afb*/
      ++v0->RefCount; /*0x860afd*/
  }
  if ( v0->StageCount < 2 ) /*0x860b04*/
  {
    v87 = sub_772630(&v147); /*0x860b0f*/
    LOBYTE(v148) = 0xA; /*0x860b1c*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v87); /*0x860b21*/
    v88 = v147; /*0x860b26*/
    LOBYTE(v148) = 1; /*0x860b2c*/
    if ( v147 ) /*0x860b31*/
    {
      --v147[7].Unk08; /*0x860b33*/
      if ( !v88[7].Unk08 ) /*0x860b3c*/
        sub_772560(v88); /*0x860b41*/
    }
    v89 = a3; /*0x860b46*/
    sub_801110((int)a3, 0, 1, 2); /*0x860b50*/
    sub_760010(v0, v0->CurrentStage, v89); /*0x860b5f*/
    v90 = sub_772630(&v147); /*0x860b69*/
    LOBYTE(v148) = 0xB; /*0x860b76*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v90); /*0x860b7b*/
    v91 = v147; /*0x860b80*/
    LOBYTE(v148) = 1; /*0x860b86*/
    if ( v147 ) /*0x860b8b*/
    {
      --v147[7].Unk08; /*0x860b8d*/
      if ( !v91[7].Unk08 ) /*0x860b96*/
        sub_772560(v91); /*0x860b9b*/
    }
    v92 = a3; /*0x860ba0*/
    sub_801110((int)a3, 0, 1, 2); /*0x860baa*/
    sub_760010(v0, v0->CurrentStage, v92); /*0x860bb9*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472B0); /*0x860bc6*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F28[0]); /*0x860bd4*/
  if ( !v0->RenderStateGroup ) /*0x860bd9*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860be4*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860bf0*/
  if ( !v0->RenderStateGroup ) /*0x860bf5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c00*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860c0c*/
  if ( !v0->RenderStateGroup ) /*0x860c11*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c1c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x860c28*/
  if ( !v0->RenderStateGroup ) /*0x860c2d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c38*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x860c44*/
  if ( !v0->RenderStateGroup ) /*0x860c49*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c54*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x860c5f*/
  if ( !v0->RenderStateGroup ) /*0x860c64*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c6f*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x860c7a*/
  if ( !v0->RenderStateGroup ) /*0x860c7f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860c8a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860c96*/
  v2 = v0 == (NiD3DPass *)dword_B47458; /*0x860c9b*/
  dword_B46A0C = 0x1000800C; /*0x860ca6*/
  dword_B46AE4 = 0x10; /*0x860cac*/
  if ( !v2 ) /*0x860cb6*/
  {
    v2 = v0->RefCount-- == 1; /*0x860cb8*/
    if ( v2 ) /*0x860cbc*/
      sub_7604D0(v0); /*0x860cc0*/
    v0 = (NiD3DPass *)dword_B47458; /*0x860cc5*/
    v145 = (NiD3DPassVtbl **)dword_B47458; /*0x860ccd*/
    if ( v145 ) /*0x860cd1*/
      ++v0->RefCount; /*0x860cd3*/
  }
  if ( v0->StageCount < 2 ) /*0x860cda*/
  {
    v93 = sub_772630(&v147); /*0x860ce5*/
    LOBYTE(v148) = 0xC; /*0x860cf2*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v93); /*0x860cf7*/
    v94 = v147; /*0x860cfc*/
    LOBYTE(v148) = 1; /*0x860d02*/
    if ( v147 ) /*0x860d07*/
    {
      --v147[7].Unk08; /*0x860d09*/
      if ( !v94[7].Unk08 ) /*0x860d12*/
        sub_772560(v94); /*0x860d17*/
    }
    v95 = a3; /*0x860d1c*/
    sub_801110((int)a3, 0, 1, 2); /*0x860d26*/
    sub_760010(v0, v0->CurrentStage, v95); /*0x860d35*/
    v96 = sub_772630(&v147); /*0x860d3f*/
    LOBYTE(v148) = 0xD; /*0x860d4c*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v96); /*0x860d51*/
    v97 = v147; /*0x860d56*/
    LOBYTE(v148) = 1; /*0x860d5c*/
    if ( v147 ) /*0x860d61*/
    {
      --v147[7].Unk08; /*0x860d63*/
      if ( !v97[7].Unk08 ) /*0x860d6c*/
        sub_772560(v97); /*0x860d71*/
    }
    v98 = a3; /*0x860d76*/
    sub_801110((int)a3, 0, 1, 2); /*0x860d80*/
    sub_760010(v0, v0->CurrentStage, v98); /*0x860d8f*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472B4); /*0x860d9c*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F28[0]); /*0x860daa*/
  if ( !v0->RenderStateGroup ) /*0x860daf*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860dba*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860dc6*/
  if ( !v0->RenderStateGroup ) /*0x860dcb*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860dd6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860de2*/
  if ( !v0->RenderStateGroup ) /*0x860de7*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860df2*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x860dfe*/
  if ( !v0->RenderStateGroup ) /*0x860e03*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860e0e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x860e1a*/
  if ( !v0->RenderStateGroup ) /*0x860e1f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860e2a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x860e35*/
  if ( !v0->RenderStateGroup ) /*0x860e3a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860e45*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x860e50*/
  if ( !v0->RenderStateGroup ) /*0x860e55*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860e60*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x860e6c*/
  v2 = v0 == (NiD3DPass *)dword_B4745C; /*0x860e71*/
  dword_B46A10 = 0x1000800C; /*0x860e77*/
  dword_B46AE8 = 0x10; /*0x860e7d*/
  if ( !v2 ) /*0x860e87*/
  {
    v2 = v0->RefCount-- == 1; /*0x860e89*/
    if ( v2 ) /*0x860e8d*/
      sub_7604D0(v0); /*0x860e91*/
    v0 = (NiD3DPass *)dword_B4745C; /*0x860e96*/
    v145 = (NiD3DPassVtbl **)dword_B4745C; /*0x860e9e*/
    if ( v145 ) /*0x860ea2*/
      ++v0->RefCount; /*0x860ea4*/
  }
  if ( v0->StageCount < 2 ) /*0x860ead*/
  {
    v99 = sub_772630(&v147); /*0x860eb8*/
    LOBYTE(v148) = 0xE; /*0x860ec5*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v99); /*0x860eca*/
    v100 = v147; /*0x860ecf*/
    LOBYTE(v148) = 1; /*0x860ed5*/
    if ( v147 ) /*0x860eda*/
    {
      --v147[7].Unk08; /*0x860edc*/
      if ( !v100[7].Unk08 ) /*0x860ee5*/
        sub_772560(v100); /*0x860eea*/
    }
    v101 = a3; /*0x860eef*/
    sub_801110((int)a3, 0, 1, 2); /*0x860ef9*/
    sub_760010(v0, v0->CurrentStage, v101); /*0x860f08*/
    v102 = sub_772630(&v147); /*0x860f12*/
    LOBYTE(v148) = 0xF; /*0x860f1f*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v102); /*0x860f24*/
    v103 = v147; /*0x860f29*/
    LOBYTE(v148) = 1; /*0x860f2f*/
    if ( v147 ) /*0x860f34*/
    {
      --v147[7].Unk08; /*0x860f36*/
      if ( !v103[7].Unk08 ) /*0x860f3f*/
        sub_772560(v103); /*0x860f44*/
    }
    v104 = a3; /*0x860f49*/
    sub_801110((int)a3, 0, 1, 2); /*0x860f53*/
    sub_760010(v0, v0->CurrentStage, v104); /*0x860f62*/
  }
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472B8); /*0x860f6f*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F30); /*0x860f7d*/
  if ( !v0->RenderStateGroup ) /*0x860f82*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860f8d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x860f99*/
  if ( !v0->RenderStateGroup ) /*0x860f9e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860fa9*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x860fb5*/
  if ( !v0->RenderStateGroup ) /*0x860fba*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860fc5*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x860fd1*/
  if ( !v0->RenderStateGroup ) /*0x860fd6*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860fe1*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x860fed*/
  if ( !v0->RenderStateGroup ) /*0x860ff2*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x860ffd*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 2, 0); /*0x861008*/
  if ( !v0->RenderStateGroup ) /*0x86100d*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861018*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 2, 0); /*0x861023*/
  if ( !v0->RenderStateGroup ) /*0x861028*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861033*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x86103f*/
  v2 = v0 == (NiD3DPass *)dword_B47460; /*0x861044*/
  dword_B46A14 = 0x208802; /*0x86104a*/
  dword_B46AEC = 0x10; /*0x861054*/
  if ( !v2 ) /*0x86105e*/
  {
    v2 = v0->RefCount-- == 1; /*0x861060*/
    if ( v2 ) /*0x861064*/
      sub_7604D0(v0); /*0x861068*/
    v0 = (NiD3DPass *)dword_B47460; /*0x86106d*/
    v145 = (NiD3DPassVtbl **)dword_B47460; /*0x861075*/
    if ( v145 ) /*0x861079*/
      ++v0->RefCount; /*0x86107b*/
  }
  sub_85E570(v0); /*0x861080*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472BC); /*0x861091*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F34); /*0x86109e*/
  if ( !v0->RenderStateGroup ) /*0x8610a3*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8610ae*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x8610ba*/
  if ( !v0->RenderStateGroup ) /*0x8610bf*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8610ca*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x8610d6*/
  if ( !v0->RenderStateGroup ) /*0x8610db*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8610e6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x8610f2*/
  if ( !v0->RenderStateGroup ) /*0x8610f7*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861102*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x86110e*/
  if ( !v0->RenderStateGroup ) /*0x861113*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86111e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 9, 0); /*0x86112a*/
  if ( !v0->RenderStateGroup ) /*0x86112f*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86113a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 1, 0); /*0x861146*/
  if ( !v0->RenderStateGroup ) /*0x86114b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861156*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x861162*/
  if ( !v0->RenderStateGroup ) /*0x861167*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861172*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x98, 0x3F, 1u); /*0x861185*/
  v2 = v0 == (NiD3DPass *)dword_B47464; /*0x86118a*/
  dword_B46A18 = 0x30802; /*0x86119a*/
  dword_B46AF0 = 0xC10; /*0x8611a0*/
  if ( !v2 ) /*0x8611a6*/
  {
    v2 = v0->RefCount-- == 1; /*0x8611a8*/
    if ( v2 ) /*0x8611ac*/
      sub_7604D0(v0); /*0x8611b0*/
    v0 = (NiD3DPass *)dword_B47464; /*0x8611b5*/
    v145 = (NiD3DPassVtbl **)dword_B47464; /*0x8611bd*/
    if ( v145 ) /*0x8611c1*/
      ++v0->RefCount; /*0x8611c3*/
  }
  sub_85E570(v0); /*0x8611c7*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472C0); /*0x8611d8*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F34); /*0x8611e6*/
  if ( !v0->RenderStateGroup ) /*0x8611eb*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8611f6*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x861201*/
  if ( !v0->RenderStateGroup ) /*0x861206*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861211*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x86121d*/
  if ( !v0->RenderStateGroup ) /*0x861222*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86122d*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x861239*/
  if ( !v0->RenderStateGroup ) /*0x86123e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861249*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x861254*/
  if ( !v0->RenderStateGroup ) /*0x861259*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861264*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 9, 0); /*0x861270*/
  if ( !v0->RenderStateGroup ) /*0x861275*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861280*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 1, 0); /*0x86128b*/
  if ( !v0->RenderStateGroup ) /*0x861290*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86129b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x8612a7*/
  if ( !v0->RenderStateGroup ) /*0x8612ac*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8612b7*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x98, 0x3F, 1u); /*0x8612c5*/
  v2 = v0 == (NiD3DPass *)dword_B47468; /*0x8612ca*/
  dword_B46A1C = 0x30802; /*0x8612d0*/
  dword_B46AF4 = 0xC10; /*0x8612d6*/
  if ( !v2 ) /*0x8612dc*/
  {
    v2 = v0->RefCount-- == 1; /*0x8612de*/
    if ( v2 ) /*0x8612e2*/
      sub_7604D0(v0); /*0x8612e6*/
    v0 = (NiD3DPass *)dword_B47468; /*0x8612eb*/
    v145 = (NiD3DPassVtbl **)dword_B47468; /*0x8612f3*/
    if ( v145 ) /*0x8612f7*/
      ++v0->RefCount; /*0x8612f9*/
  }
  sub_85E570(v0); /*0x8612fd*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472C4); /*0x86130d*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F34); /*0x86131b*/
  if ( !v0->RenderStateGroup ) /*0x861320*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86132b*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x861336*/
  if ( !v0->RenderStateGroup ) /*0x86133b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861346*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x861352*/
  if ( !v0->RenderStateGroup ) /*0x861357*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861362*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x86136e*/
  if ( !v0->RenderStateGroup ) /*0x861373*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86137e*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x861389*/
  if ( !v0->RenderStateGroup ) /*0x86138e*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861399*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 9, 0); /*0x8613a5*/
  if ( !v0->RenderStateGroup ) /*0x8613aa*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8613b5*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 1, 0); /*0x8613c0*/
  if ( !v0->RenderStateGroup ) /*0x8613c5*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8613d0*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x8613dc*/
  if ( !v0->RenderStateGroup ) /*0x8613e1*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8613ec*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x98, 0x3F, 1u); /*0x8613fa*/
  v2 = v0 == (NiD3DPass *)dword_B4746C; /*0x8613ff*/
  dword_B46A20 = 0x3080C; /*0x86140a*/
  dword_B46AF8 = 0xC10; /*0x861410*/
  if ( !v2 ) /*0x861416*/
  {
    v2 = v0->RefCount-- == 1; /*0x861418*/
    if ( v2 ) /*0x86141c*/
      sub_7604D0(v0); /*0x861420*/
    v0 = (NiD3DPass *)dword_B4746C; /*0x861425*/
    v145 = (NiD3DPassVtbl **)dword_B4746C; /*0x86142d*/
    if ( v145 ) /*0x861431*/
      ++v0->RefCount; /*0x861433*/
  }
  sub_85E570(v0); /*0x861437*/
  sub_7AECB0(v0, (NiD3DVertexShader *)dword_B472C8); /*0x861448*/
  sub_7AEC60(&v0->__vftable, (NiD3DPixelShader *)dword_B46F34); /*0x861455*/
  if ( !v0->RenderStateGroup ) /*0x86145a*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861465*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 7, 1, 0); /*0x861470*/
  if ( !v0->RenderStateGroup ) /*0x861475*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861480*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x17, 4, 0); /*0x86148c*/
  if ( !v0->RenderStateGroup ) /*0x861491*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86149c*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0xE, 0, 0); /*0x8614a8*/
  if ( !v0->RenderStateGroup ) /*0x8614ad*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8614b8*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x1B, 1, 0); /*0x8614c3*/
  if ( !v0->RenderStateGroup ) /*0x8614c8*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8614d3*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x13, 9, 0); /*0x8614df*/
  if ( !v0->RenderStateGroup ) /*0x8614e4*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8614ef*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x14, 1, 0); /*0x8614fa*/
  if ( !v0->RenderStateGroup ) /*0x8614ff*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86150a*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x34, 0, 0); /*0x861516*/
  if ( !v0->RenderStateGroup ) /*0x86151b*/
    v0->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861526*/
  sub_772CD0((_DWORD *)v0->RenderStateGroup, 0x98, 0x3F, 1u); /*0x861534*/
  dword_B46A24 = 0x3080C; /*0x861542*/
  dword_B46AFC = 0xC10; /*0x861548*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47470); /*0x86154e*/
  v105 = (NiD3DPass *)v145; /*0x861553*/
  sub_85E570((NiD3DPass *)v145); /*0x861558*/
  sub_7715E0(v105->Stages.data->Texture, 0); /*0x861568*/
  sub_7AECB0(v105, (NiD3DVertexShader *)dword_B472CC); /*0x861576*/
  sub_7AEC60(&v105->__vftable, (NiD3DPixelShader *)dword_B46F38); /*0x861583*/
  if ( !v105->RenderStateGroup ) /*0x861588*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861593*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 7, 1, 0); /*0x86159f*/
  if ( !v105->RenderStateGroup ) /*0x8615a4*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8615ae*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x17, 4, 0); /*0x8615b9*/
  if ( !v105->RenderStateGroup ) /*0x8615be*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8615c8*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0xE, 0, 0); /*0x8615d2*/
  if ( !v105->RenderStateGroup ) /*0x8615d7*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8615e1*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x1B, 1, 0); /*0x8615eb*/
  if ( !v105->RenderStateGroup ) /*0x8615f0*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8615fa*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x13, 9, 0); /*0x861605*/
  if ( !v105->RenderStateGroup ) /*0x86160a*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861614*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x14, 6, 0); /*0x86161f*/
  if ( !v105->RenderStateGroup ) /*0x861624*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86162e*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0xF, 1, 0); /*0x861638*/
  if ( !v105->RenderStateGroup ) /*0x86163d*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861647*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x19, 5, 0); /*0x861652*/
  if ( !v105->RenderStateGroup ) /*0x861657*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861661*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x18, 0, 0); /*0x86166b*/
  if ( !v105->RenderStateGroup ) /*0x861670*/
    v105->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86167a*/
  sub_772CD0((_DWORD *)v105->RenderStateGroup, 0x34, 0, 0); /*0x861684*/
  dword_B46A28 = 2; /*0x861697*/
  dword_B46B00 = 0; /*0x86169d*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47474); /*0x8616a3*/
  v106 = (NiD3DPass *)v145; /*0x8616a8*/
  sub_85E570((NiD3DPass *)v145); /*0x8616ad*/
  sub_7715E0(v106->Stages.data->Texture, 0); /*0x8616bc*/
  sub_7AECB0(v106, (NiD3DVertexShader *)dword_B472CC); /*0x8616ca*/
  sub_7AEC60(&v106->__vftable, (NiD3DPixelShader *)dword_B46F3C); /*0x8616d7*/
  if ( !v106->RenderStateGroup ) /*0x8616dc*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8616e6*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 7, 1, 0); /*0x8616f0*/
  if ( !v106->RenderStateGroup ) /*0x8616f5*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8616ff*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x17, 4, 0); /*0x86170a*/
  if ( !v106->RenderStateGroup ) /*0x86170f*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861719*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0xE, 0, 0); /*0x861723*/
  if ( !v106->RenderStateGroup ) /*0x861728*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861732*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x1B, 1, 0); /*0x86173c*/
  if ( !v106->RenderStateGroup ) /*0x861741*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86174b*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x13, 9, 0); /*0x861756*/
  if ( !v106->RenderStateGroup ) /*0x86175b*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861765*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x14, 6, 0); /*0x861770*/
  if ( !v106->RenderStateGroup ) /*0x861775*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86177f*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0xF, 1, 0); /*0x861789*/
  if ( !v106->RenderStateGroup ) /*0x86178e*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861798*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x19, 5, 0); /*0x8617a3*/
  if ( !v106->RenderStateGroup ) /*0x8617a8*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8617b2*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x18, 0, 0); /*0x8617bc*/
  if ( !v106->RenderStateGroup ) /*0x8617c1*/
    v106->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8617cb*/
  sub_772CD0((_DWORD *)v106->RenderStateGroup, 0x34, 0, 0); /*0x8617d5*/
  dword_B46A2C = 2; /*0x8617e3*/
  dword_B46B04 = 0; /*0x8617e9*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47480); /*0x8617ef*/
  v107 = (NiD3DPass *)v145; /*0x8617f4*/
  if ( !v145[6] ) /*0x8617f8*/
  {
    v108 = sub_772630(&v147); /*0x861802*/
    LOBYTE(v148) = 0x10; /*0x86180f*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v108); /*0x861814*/
    v109 = v147; /*0x861819*/
    LOBYTE(v148) = 1; /*0x86181f*/
    if ( v147 ) /*0x861824*/
    {
      --v147[7].Unk08; /*0x861826*/
      if ( !v109[7].Unk08 ) /*0x86182f*/
        sub_772560(v109); /*0x861833*/
    }
    v110 = a3; /*0x861839*/
    sub_801110((int)a3, 0, 1, 2); /*0x861840*/
    sub_760010(v107, v107->CurrentStage, v110); /*0x86184f*/
  }
  sub_7AECB0(v107, (NiD3DVertexShader *)dword_B472D8); /*0x86185c*/
  sub_7AEC60(&v107->__vftable, (NiD3DPixelShader *)dword_B46F48); /*0x86186a*/
  if ( !v107->RenderStateGroup ) /*0x86186f*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861879*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 0x1B, 0, 0); /*0x861883*/
  if ( !v107->RenderStateGroup ) /*0x861888*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861892*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 0xF, 0, 0); /*0x86189c*/
  if ( !v107->RenderStateGroup ) /*0x8618a1*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8618ab*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 7, 1, 0); /*0x8618b5*/
  if ( !v107->RenderStateGroup ) /*0x8618ba*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8618c4*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 0x17, 4, 0); /*0x8618cf*/
  if ( !v107->RenderStateGroup ) /*0x8618d4*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8618de*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 0xE, 1, 0); /*0x8618e8*/
  if ( !v107->RenderStateGroup ) /*0x8618ed*/
    v107->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8618f7*/
  sub_772CD0((_DWORD *)v107->RenderStateGroup, 0x34, 0, 0); /*0x861903*/
  dword_B46A38 = 0x12; /*0x86191b*/
  dword_B46B10 = 0x200; /*0x861921*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47484); /*0x861927*/
  v111 = (NiD3DPass *)v145; /*0x86192c*/
  if ( !v145[6] ) /*0x861930*/
  {
    v112 = sub_772630(&v147); /*0x86193b*/
    LOBYTE(v148) = 0x11; /*0x861948*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v112); /*0x86194d*/
    v113 = v147; /*0x861952*/
    LOBYTE(v148) = 1; /*0x861958*/
    if ( v147 ) /*0x86195d*/
    {
      --v147[7].Unk08; /*0x86195f*/
      if ( !v113[7].Unk08 ) /*0x861968*/
        sub_772560(v113); /*0x86196d*/
    }
    v114 = a3; /*0x861972*/
    sub_801110((int)a3, 0, 1, 2); /*0x86197d*/
    sub_760010(v111, v111->CurrentStage, v114); /*0x86198c*/
  }
  sub_7AECB0(v111, (NiD3DVertexShader *)dword_B472DC); /*0x86199a*/
  sub_7AEC60(&v111->__vftable, (NiD3DPixelShader *)dword_B46F4C); /*0x8619a8*/
  if ( !v111->RenderStateGroup ) /*0x8619ad*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8619b8*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 0x1B, 0, 0); /*0x8619c4*/
  if ( !v111->RenderStateGroup ) /*0x8619c9*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8619d4*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 0xF, 0, 0); /*0x8619e0*/
  if ( !v111->RenderStateGroup ) /*0x8619e5*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8619f0*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 7, 1, 0); /*0x8619fc*/
  if ( !v111->RenderStateGroup ) /*0x861a01*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861a0c*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 0x17, 4, 0); /*0x861a18*/
  if ( !v111->RenderStateGroup ) /*0x861a1d*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861a28*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 0xE, 1, 0); /*0x861a34*/
  if ( !v111->RenderStateGroup ) /*0x861a39*/
    v111->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861a44*/
  sub_772CD0((_DWORD *)v111->RenderStateGroup, 0x34, 0, 0); /*0x861a50*/
  dword_B46A3C = 0x2C; /*0x861a63*/
  dword_B46B14 = 0x200; /*0x861a69*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47488); /*0x861a6f*/
  v115 = (NiD3DPass *)v145; /*0x861a74*/
  if ( !v145[6] ) /*0x861a78*/
  {
    v116 = sub_772630(&v147); /*0x861a83*/
    LOBYTE(v148) = 0x12; /*0x861a90*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v116); /*0x861a94*/
    v117 = v147; /*0x861a99*/
    LOBYTE(v148) = 1; /*0x861a9f*/
    if ( v147 ) /*0x861aa4*/
    {
      --v147[7].Unk08; /*0x861aa6*/
      if ( !v117[7].Unk08 ) /*0x861aaf*/
        sub_772560(v117); /*0x861ab4*/
    }
    sub_801110((int)a3, 0, 1, 2); /*0x861ac4*/
    sub_760010(v115, v115->CurrentStage, a3); /*0x861ad7*/
  }
  sub_7AECB0(v115, (NiD3DVertexShader *)dword_B472E0); /*0x861ae5*/
  sub_7AEC60(&v115->__vftable, (NiD3DPixelShader *)dword_B46F50); /*0x861af3*/
  if ( !v115->RenderStateGroup ) /*0x861af8*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b03*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0x1B, 1, 0); /*0x861b0f*/
  if ( !v115->RenderStateGroup ) /*0x861b14*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b1f*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0x13, 5, 0); /*0x861b2b*/
  if ( !v115->RenderStateGroup ) /*0x861b30*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b3b*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0x14, 6, 0); /*0x861b47*/
  if ( !v115->RenderStateGroup ) /*0x861b4c*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b57*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0xF, 0, 0); /*0x861b63*/
  if ( !v115->RenderStateGroup ) /*0x861b68*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b73*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 7, 1, 0); /*0x861b7f*/
  if ( !v115->RenderStateGroup ) /*0x861b84*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861b8f*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0x17, 4, 0); /*0x861b9b*/
  if ( !v115->RenderStateGroup ) /*0x861ba0*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861bab*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0xE, 0, 0); /*0x861bb7*/
  if ( !v115->RenderStateGroup ) /*0x861bbc*/
    v115->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861bc7*/
  sub_772CD0((_DWORD *)v115->RenderStateGroup, 0x34, 0, 0); /*0x861bd3*/
  dword_B46A40 = 0x108012; /*0x861be1*/
  dword_B46B18 = 0x200; /*0x861beb*/
  sub_76C890((NiD3DPass **)&v145, &dword_B4748C); /*0x861bf1*/
  v118 = v145; /*0x861bfb*/
  sub_7AECB0((NiD3DPass *)v145, (NiD3DVertexShader *)dword_B472E4); /*0x861c02*/
  sub_7AEC60(v118, (NiD3DPixelShader *)dword_B46F54); /*0x861c10*/
  if ( !v118[0xC] ) /*0x861c15*/
    v118[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861c20*/
  sub_772CD0(v118[0xC], 0x1B, 0, 0); /*0x861c2c*/
  if ( !v118[0xC] ) /*0x861c31*/
    v118[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861c3b*/
  sub_772CD0(v118[0xC], 0xF, 0, 0); /*0x861c45*/
  if ( !v118[0xC] ) /*0x861c4a*/
    v118[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861c54*/
  sub_772CD0(v118[0xC], 7, 0, 0); /*0x861c5e*/
  if ( !v118[0xC] ) /*0x861c63*/
    v118[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861c6d*/
  sub_772CD0(v118[0xC], 0xE, 0, 0); /*0x861c77*/
  if ( !v118[0xC] ) /*0x861c7c*/
    v118[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861c86*/
  sub_772CD0(v118[0xC], 0x34, 0, 0); /*0x861c90*/
  dword_B46A44 = 2; /*0x861c9e*/
  dword_B46B1C = 0; /*0x861ca8*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47490); /*0x861cae*/
  v119 = v145; /*0x861cb9*/
  sub_7AECB0((NiD3DPass *)v145, (NiD3DVertexShader *)dword_B472E8); /*0x861cc0*/
  sub_7AEC60(v119, (NiD3DPixelShader *)dword_B46F58); /*0x861ccd*/
  if ( !v119[0xC] ) /*0x861cd2*/
    v119[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861cdc*/
  sub_772CD0(v119[0xC], 0x1B, 0, 0); /*0x861ce6*/
  if ( !v119[0xC] ) /*0x861ceb*/
    v119[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861cf5*/
  sub_772CD0(v119[0xC], 0xF, 0, 0); /*0x861cff*/
  if ( !v119[0xC] ) /*0x861d04*/
    v119[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861d0e*/
  sub_772CD0(v119[0xC], 7, 0, 0); /*0x861d18*/
  if ( !v119[0xC] ) /*0x861d1d*/
    v119[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861d27*/
  sub_772CD0(v119[0xC], 0xE, 0, 0); /*0x861d31*/
  if ( !v119[0xC] ) /*0x861d36*/
    v119[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x861d40*/
  sub_772CD0(v119[0xC], 0x34, 0, 0); /*0x861d4a*/
  dword_B46A48 = 0xC; /*0x861d58*/
  dword_B46B20 = 0; /*0x861d62*/
  sub_76C890((NiD3DPass **)&v145, &dword_B474A0); /*0x861d68*/
  v120 = (NiD3DPass *)v145; /*0x861d6d*/
  if ( (unsigned int)v145[6] < 2 ) /*0x861d75*/
  {
    v121 = sub_772630(&v147); /*0x861d80*/
    LOBYTE(v148) = 0x13; /*0x861d8d*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v121); /*0x861d92*/
    v122 = v147; /*0x861d97*/
    LOBYTE(v148) = 1; /*0x861d9d*/
    if ( v147 ) /*0x861da2*/
    {
      --v147[7].Unk08; /*0x861da4*/
      if ( !v122[7].Unk08 ) /*0x861dad*/
        sub_772560(v122); /*0x861db1*/
    }
    v123 = a3; /*0x861db6*/
    sub_801110((int)a3, 0, 1, 2); /*0x861dc1*/
    sub_760010(v120, v120->CurrentStage, v123); /*0x861dd0*/
    v124 = sub_772630(&v147); /*0x861dda*/
    LOBYTE(v148) = 0x14; /*0x861de7*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v124); /*0x861dec*/
    v125 = v147; /*0x861df1*/
    LOBYTE(v148) = 1; /*0x861df7*/
    if ( v147 ) /*0x861dfc*/
    {
      --v147[7].Unk08; /*0x861dfe*/
      if ( !v125[7].Unk08 ) /*0x861e07*/
        sub_772560(v125); /*0x861e0c*/
    }
    v126 = a3; /*0x861e11*/
    sub_801110((int)a3, 1, 1, 2); /*0x861e1c*/
    sub_760010(v120, v120->CurrentStage, v126); /*0x861e2b*/
  }
  sub_7AECB0(v120, (NiD3DVertexShader *)dword_B472F8); /*0x861e3b*/
  sub_7AEC60(&v120->__vftable, (NiD3DPixelShader *)dword_B46F64); /*0x861e48*/
  if ( !v120->RenderStateGroup ) /*0x861e4d*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861e57*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0x1B, 1, 0); /*0x861e62*/
  if ( !v120->RenderStateGroup ) /*0x861e67*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861e71*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0x13, 5, 0); /*0x861e7c*/
  if ( !v120->RenderStateGroup ) /*0x861e81*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861e8b*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0x14, 6, 0); /*0x861e96*/
  if ( !v120->RenderStateGroup ) /*0x861e9b*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861ea5*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0xF, 0, 0); /*0x861eaf*/
  if ( !v120->RenderStateGroup ) /*0x861eb4*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861ebe*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 7, 1, 0); /*0x861ec9*/
  if ( !v120->RenderStateGroup ) /*0x861ece*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861ed8*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0x17, 3, 0); /*0x861ee3*/
  if ( !v120->RenderStateGroup ) /*0x861ee8*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861ef2*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0xE, 0, 0); /*0x861efc*/
  if ( !v120->RenderStateGroup ) /*0x861f01*/
    v120->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x861f0b*/
  sub_772CD0((_DWORD *)v120->RenderStateGroup, 0x34, 0, 0); /*0x861f15*/
  dword_B46A58 = 0; /*0x861f23*/
  dword_B46B30 = 0; /*0x861f29*/
  sub_76C890((NiD3DPass **)&v145, &dword_B474A4); /*0x861f2f*/
  v127 = (NiD3DPass *)v145; /*0x861f34*/
  if ( (unsigned int)v145[6] < 2 ) /*0x861f3c*/
  {
    v128 = sub_772630(&v147); /*0x861f47*/
    LOBYTE(v148) = 0x15; /*0x861f54*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v128); /*0x861f59*/
    v129 = v147; /*0x861f5e*/
    LOBYTE(v148) = 1; /*0x861f64*/
    if ( v147 ) /*0x861f69*/
    {
      --v147[7].Unk08; /*0x861f6b*/
      if ( !v129[7].Unk08 ) /*0x861f74*/
        sub_772560(v129); /*0x861f78*/
    }
    v130 = a3; /*0x861f7d*/
    sub_801110((int)a3, 0, 1, 2); /*0x861f88*/
    sub_760010(v127, v127->CurrentStage, v130); /*0x861f97*/
    v131 = sub_772630(&v147); /*0x861fa1*/
    LOBYTE(v148) = 0x16; /*0x861fae*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v131); /*0x861fb3*/
    v132 = v147; /*0x861fb8*/
    LOBYTE(v148) = 1; /*0x861fbe*/
    if ( v147 ) /*0x861fc3*/
    {
      --v147[7].Unk08; /*0x861fc5*/
      if ( !v132[7].Unk08 ) /*0x861fce*/
        sub_772560(v132); /*0x861fd3*/
    }
    v133 = a3; /*0x861fd8*/
    sub_801110((int)a3, 1, 1, 2); /*0x861fe3*/
    sub_760010(v127, v127->CurrentStage, v133); /*0x861ff2*/
  }
  sub_7AECB0(v127, (NiD3DVertexShader *)dword_B472FC); /*0x862002*/
  sub_7AEC60(&v127->__vftable, (NiD3DPixelShader *)dword_B46F68); /*0x86200f*/
  if ( !v127->RenderStateGroup ) /*0x862014*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86201e*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0x1B, 1, 0); /*0x862029*/
  if ( !v127->RenderStateGroup ) /*0x86202e*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862038*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0x13, 5, 0); /*0x862043*/
  if ( !v127->RenderStateGroup ) /*0x862048*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862052*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0x14, 6, 0); /*0x86205d*/
  if ( !v127->RenderStateGroup ) /*0x862062*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86206c*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0xF, 0, 0); /*0x862076*/
  if ( !v127->RenderStateGroup ) /*0x86207b*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862085*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 7, 1, 0); /*0x862090*/
  if ( !v127->RenderStateGroup ) /*0x862095*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86209f*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0x17, 3, 0); /*0x8620aa*/
  if ( !v127->RenderStateGroup ) /*0x8620af*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8620b9*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0xE, 0, 0); /*0x8620c3*/
  if ( !v127->RenderStateGroup ) /*0x8620c8*/
    v127->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8620d2*/
  sub_772CD0((_DWORD *)v127->RenderStateGroup, 0x34, 0, 0); /*0x8620dc*/
  dword_B46A5C = 0; /*0x8620ea*/
  dword_B46B34 = 0; /*0x8620f0*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47478); /*0x8620f6*/
  v134 = (NiD3DPass *)v145; /*0x8620fb*/
  if ( !v145[6] ) /*0x8620ff*/
  {
    v135 = sub_772630(&v147); /*0x86210a*/
    LOBYTE(v148) = 0x17; /*0x862117*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v135); /*0x86211c*/
    v136 = v147; /*0x862121*/
    LOBYTE(v148) = 1; /*0x862127*/
    if ( v147 ) /*0x86212c*/
    {
      --v147[7].Unk08; /*0x86212e*/
      if ( !v136[7].Unk08 ) /*0x862137*/
        sub_772560(v136); /*0x86213b*/
    }
    v137 = a3; /*0x862140*/
    sub_801110((int)a3, 0, 1, 2); /*0x86214b*/
    sub_760010(v134, v134->CurrentStage, v137); /*0x86215a*/
  }
  sub_7AECB0(v134, (NiD3DVertexShader *)dword_B472D0); /*0x862169*/
  sub_7AEC60(&v134->__vftable, (NiD3DPixelShader *)dword_B46F40); /*0x862177*/
  if ( !v134->RenderStateGroup ) /*0x86217c*/
    v134->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862186*/
  sub_772CD0((_DWORD *)v134->RenderStateGroup, 0x1B, 0, 0); /*0x862190*/
  if ( !v134->RenderStateGroup ) /*0x862195*/
    v134->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86219f*/
  sub_772CD0((_DWORD *)v134->RenderStateGroup, 7, 1, 0); /*0x8621aa*/
  if ( !v134->RenderStateGroup ) /*0x8621af*/
    v134->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8621b9*/
  sub_772CD0((_DWORD *)v134->RenderStateGroup, 0x17, 4, 0); /*0x8621c4*/
  if ( !v134->RenderStateGroup ) /*0x8621c9*/
    v134->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8621d3*/
  sub_772CD0((_DWORD *)v134->RenderStateGroup, 0xE, 1, 0); /*0x8621de*/
  if ( !v134->RenderStateGroup ) /*0x8621e3*/
    v134->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8621ed*/
  sub_772CD0((_DWORD *)v134->RenderStateGroup, 0x34, 0, 0); /*0x8621f9*/
  dword_B46A30 = 0x12; /*0x86220c*/
  dword_B46B08 = 0x400; /*0x862212*/
  sub_76C890((NiD3DPass **)&v145, &dword_B4747C); /*0x862218*/
  v138 = (NiD3DPass *)v145; /*0x86221d*/
  if ( !v145[6] ) /*0x862221*/
  {
    v139 = sub_772630(&v147); /*0x86222c*/
    LOBYTE(v148) = 0x18; /*0x862239*/
    sub_75FAE0((NiD3DTextureStage **)&a3, v139); /*0x86223e*/
    v140 = v147; /*0x862243*/
    LOBYTE(v148) = 1; /*0x862249*/
    if ( v147 ) /*0x86224e*/
    {
      --v147[7].Unk08; /*0x862250*/
      if ( !v140[7].Unk08 ) /*0x862259*/
        sub_772560(v140); /*0x86225e*/
    }
    sub_801110((int)a3, 0, 1, 2); /*0x86226e*/
    sub_760010(v138, v138->CurrentStage, a3); /*0x862281*/
  }
  sub_7AECB0(v138, (NiD3DVertexShader *)dword_B472D4); /*0x86228e*/
  sub_7AEC60(&v138->__vftable, (NiD3DPixelShader *)dword_B46F40); /*0x86229c*/
  if ( !v138->RenderStateGroup ) /*0x8622a1*/
    v138->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8622ac*/
  sub_772CD0((_DWORD *)v138->RenderStateGroup, 0x1B, 0, 0); /*0x8622b8*/
  if ( !v138->RenderStateGroup ) /*0x8622bd*/
    v138->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8622c8*/
  sub_772CD0((_DWORD *)v138->RenderStateGroup, 7, 1, 0); /*0x8622d4*/
  if ( !v138->RenderStateGroup ) /*0x8622d9*/
    v138->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8622e4*/
  sub_772CD0((_DWORD *)v138->RenderStateGroup, 0x17, 4, 0); /*0x8622f0*/
  if ( !v138->RenderStateGroup ) /*0x8622f5*/
    v138->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862300*/
  sub_772CD0((_DWORD *)v138->RenderStateGroup, 0xE, 1, 0); /*0x86230c*/
  if ( !v138->RenderStateGroup ) /*0x862311*/
    v138->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86231c*/
  sub_772CD0((_DWORD *)v138->RenderStateGroup, 0x34, 0, 0); /*0x862328*/
  dword_B46A34 = 0x2C; /*0x862336*/
  dword_B46B0C = 0x400; /*0x86233c*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47494); /*0x862342*/
  v141 = v145; /*0x86234d*/
  sub_7AECB0((NiD3DPass *)v145, (NiD3DVertexShader *)dword_B472EC); /*0x862354*/
  sub_7AEC60(v141, (NiD3DPixelShader *)dword_B46F5C); /*0x862361*/
  if ( !v141[0xC] ) /*0x862366*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x862371*/
  sub_772CD0(v141[0xC], 0x1B, 0, 0); /*0x86237d*/
  if ( !v141[0xC] ) /*0x862382*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x86238c*/
  sub_772CD0(v141[0xC], 0xF, 0, 0); /*0x862396*/
  if ( !v141[0xC] ) /*0x86239b*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8623a5*/
  sub_772CD0(v141[0xC], 7, 1, 0); /*0x8623b0*/
  if ( !v141[0xC] ) /*0x8623b5*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8623bf*/
  sub_772CD0(v141[0xC], 0x17, 4, 0); /*0x8623ca*/
  if ( !v141[0xC] ) /*0x8623cf*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8623d9*/
  sub_772CD0(v141[0xC], 0xE, 1, 0); /*0x8623e4*/
  if ( !v141[0xC] ) /*0x8623e9*/
    v141[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8623f3*/
  sub_772CD0(v141[0xC], 0x34, 0, 0); /*0x8623fd*/
  dword_B46A4C = 0x12; /*0x86240b*/
  dword_B46B24 = 0; /*0x862411*/
  sub_76C890((NiD3DPass **)&v145, &dword_B47498); /*0x862417*/
  v142 = v145; /*0x862422*/
  sub_7AECB0((NiD3DPass *)v145, (NiD3DVertexShader *)dword_B472F0); /*0x862429*/
  sub_7AEC60(v142, (NiD3DPixelShader *)dword_B46F5C); /*0x862437*/
  if ( !v142[0xC] ) /*0x86243c*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x862446*/
  sub_772CD0(v142[0xC], 0x1B, 0, 0); /*0x862450*/
  if ( !v142[0xC] ) /*0x862455*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x86245f*/
  sub_772CD0(v142[0xC], 0xF, 0, 0); /*0x862469*/
  if ( !v142[0xC] ) /*0x86246e*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x862478*/
  sub_772CD0(v142[0xC], 7, 1, 0); /*0x862483*/
  if ( !v142[0xC] ) /*0x862488*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x862492*/
  sub_772CD0(v142[0xC], 0x17, 4, 0); /*0x86249d*/
  if ( !v142[0xC] ) /*0x8624a2*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8624ac*/
  sub_772CD0(v142[0xC], 0xE, 1, 0); /*0x8624b7*/
  if ( !v142[0xC] ) /*0x8624bc*/
    v142[0xC] = (NiD3DPassVtbl *)sub_772DF0(); /*0x8624c6*/
  sub_772CD0(v142[0xC], 0x34, 0, 0); /*0x8624d0*/
  dword_B46A50 = 0x2C; /*0x8624de*/
  dword_B46B28 = 0; /*0x8624e4*/
  sub_76C890((NiD3DPass **)&v145, &dword_B4749C); /*0x8624ea*/
  v143 = (NiD3DPass *)v145; /*0x8624f4*/
  sub_7AECB0((NiD3DPass *)v145, (NiD3DVertexShader *)dword_B472F4); /*0x8624fb*/
  sub_7AEC60(&v143->__vftable, (NiD3DPixelShader *)dword_B46F60); /*0x862509*/
  if ( !v143->RenderStateGroup ) /*0x86250e*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862518*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 0x1B, 0, 0); /*0x862522*/
  if ( !v143->RenderStateGroup ) /*0x862527*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862531*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 0xF, 0, 0); /*0x86253b*/
  if ( !v143->RenderStateGroup ) /*0x862540*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86254a*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 7, 1, 0); /*0x862555*/
  if ( !v143->RenderStateGroup ) /*0x86255a*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862564*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 0x17, 8, 0); /*0x86256f*/
  if ( !v143->RenderStateGroup ) /*0x862574*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x86257e*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 0xE, 1, 0); /*0x862589*/
  if ( !v143->RenderStateGroup ) /*0x86258e*/
    v143->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x862598*/
  sub_772CD0((_DWORD *)v143->RenderStateGroup, 0x34, 0, 0); /*0x8625a2*/
  v144 = (NiD3DTextureStage *)a3; /*0x8625a7*/
  v2 = a3 == 0; /*0x8625ab*/
  dword_B46A54 = 2; /*0x8625ad*/
  dword_B46B2C = 0; /*0x8625b7*/
  LOBYTE(v148) = 0; /*0x8625bd*/
  if ( !v2 ) /*0x8625c2*/
  {
    v2 = v144[7].Unk08-- == 1; /*0x8625c7*/
    if ( v2 ) /*0x8625ca*/
      sub_772560(v144); /*0x8625cc*/
  }
  v2 = v143->RefCount-- == 1; /*0x8625d6*/
  v148 = 0xFFFFFFFF; /*0x8625d9*/
  if ( v2 ) /*0x8625dd*/
    sub_7604D0(v143); /*0x8625e1*/
}
