// 0x00870970 @ 0x00870970
// MoonSugarEffect decode: ParallaxShader pass population slot +0xD0. Populates four pooled passes dword_B476E0..B476EC.
void __thiscall sub_870970(volatile LONG **this)
{
  NiD3DPass *v1; // esi
  NiD3DTextureStage *v2; // edi
  int v3; // eax
  bool v4; // zf
  NiD3DTextureStage *v5; // eax
  NiD3DTextureStage *v6; // eax
  NiD3DTextureStage **v7; // ebx
  NiD3DTextureStage *v8; // eax
  NiD3DTextureStage **v9; // ebx
  NiD3DTextureStage *v10; // eax
  NiD3DTextureStage **v11; // ebx
  NiD3DTextureStage *v12; // eax
  volatile LONG *v13; // ebx
  NiD3DVertexShader *VertexShader; // ebp
  volatile LONG *v15; // ebx
  NiD3DPixelShader *PixelShader; // ebp
  NiD3DTextureStage **v17; // ebp
  NiD3DTextureStage *v18; // eax
  NiD3DTextureStage **v19; // ebp
  NiD3DTextureStage *v20; // eax
  NiD3DTextureStage **v21; // ebp
  NiD3DTextureStage *v22; // eax
  NiD3DTextureStage **v23; // ebp
  NiD3DTextureStage *v24; // eax
  volatile LONG *v25; // ebx
  NiD3DVertexShader *v26; // ebp
  volatile LONG *v27; // ebx
  NiD3DPixelShader *v28; // ebp
  NiD3DTextureStage **v29; // ebp
  NiD3DTextureStage *v30; // eax
  NiD3DTextureStage **v31; // ebp
  NiD3DTextureStage *v32; // eax
  NiD3DTextureStage **v33; // ebp
  NiD3DTextureStage *v34; // eax
  NiD3DTextureStage **v35; // ebp
  NiD3DTextureStage *v36; // eax
  volatile LONG *v37; // ebx
  NiD3DVertexShader *v38; // ebp
  volatile LONG *v39; // ebx
  NiD3DPixelShader *v40; // ebp
  NiD3DTextureStage **v41; // ebp
  NiD3DTextureStage *v42; // eax
  NiD3DTextureStage **v43; // ebp
  NiD3DTextureStage *v44; // eax
  NiD3DTextureStage **v45; // ebp
  NiD3DTextureStage *v46; // eax
  NiD3DTextureStage **v47; // ebp
  NiD3DTextureStage *v48; // eax
  volatile LONG *v49; // ebx
  NiD3DVertexShader *v50; // ebp
  volatile LONG *v51; // ebx
  NiD3DPixelShader *v52; // ebp
  NiD3DTextureStage *v54; // [esp+24h] [ebp-10h] BYREF
  unsigned int v55; // [esp+30h] [ebp-4h]

  v1 = 0; /*0x87099b*/
  v2 = 0; /*0x8709a1*/
  v55 = 0; /*0x8709a3*/
  v3 = dword_B476E0; /*0x8709ab*/
  v4 = dword_B476E0 == 0; /*0x8709b0*/
  LOBYTE(v55) = 1; /*0x8709b7*/
  if ( !v4 ) /*0x8709bc*/
  {
    v1 = (NiD3DPass *)v3; /*0x8709be*/
    if ( v3 ) /*0x8709c6*/
      ++*(_DWORD *)(v3 + 0x60); /*0x8709c8*/
  }
  if ( v1->StageCount < 4 ) /*0x8709d1*/
  {
    v5 = (NiD3DTextureStage *)*sub_772630(&v54); /*0x8709e4*/
    if ( v5 ) /*0x8709e8*/
    {
      v2 = v5; /*0x8709ea*/
      ++v5[7].Unk08; /*0x8709ec*/
    }
    v6 = v54; /*0x8709f3*/
    LOBYTE(v55) = 1; /*0x8709f9*/
    if ( v54 ) /*0x8709fe*/
    {
      --v54[7].Unk08; /*0x870a00*/
      if ( !v6[7].Unk08 ) /*0x870a09*/
        sub_772560(v6); /*0x870a0e*/
    }
    sub_801110((int)v2, 0, 1, 2); /*0x870a19*/
    sub_760010(v1, 0, &v2->Stage); /*0x870a26*/
    v7 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870a38*/
    v4 = v2 == *v7; /*0x870a3a*/
    LOBYTE(v55) = 3; /*0x870a3c*/
    if ( !v4 ) /*0x870a41*/
    {
      if ( v2 ) /*0x870a45*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870a47*/
        if ( v4 ) /*0x870a4b*/
          sub_772560(v2); /*0x870a4f*/
      }
      v2 = *v7; /*0x870a54*/
      if ( *v7 ) /*0x870a58*/
        ++v2[7].Unk08; /*0x870a5e*/
    }
    v8 = v54; /*0x870a61*/
    LOBYTE(v55) = 1; /*0x870a67*/
    if ( v54 ) /*0x870a6c*/
    {
      --v54[7].Unk08; /*0x870a6e*/
      if ( !v8[7].Unk08 ) /*0x870a77*/
        sub_772560(v8); /*0x870a7c*/
    }
    sub_801110((int)v2, 1, 1, 2); /*0x870a86*/
    sub_760010(v1, 1u, &v2->Stage); /*0x870a92*/
    v9 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870aa4*/
    v4 = v2 == *v9; /*0x870aa6*/
    LOBYTE(v55) = 4; /*0x870aa8*/
    if ( !v4 ) /*0x870aad*/
    {
      if ( v2 ) /*0x870ab1*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870ab3*/
        if ( v4 ) /*0x870ab7*/
          sub_772560(v2); /*0x870abb*/
      }
      v2 = *v9; /*0x870ac0*/
      if ( *v9 ) /*0x870ac4*/
        ++v2[7].Unk08; /*0x870aca*/
    }
    v10 = v54; /*0x870acd*/
    LOBYTE(v55) = 1; /*0x870ad3*/
    if ( v54 ) /*0x870ad8*/
    {
      --v54[7].Unk08; /*0x870ada*/
      if ( !v10[7].Unk08 ) /*0x870ae3*/
        sub_772560(v10); /*0x870ae8*/
    }
    sub_801110((int)v2, 2, 1, 2); /*0x870af3*/
    sub_760010(v1, 2u, &v2->Stage); /*0x870b00*/
    v11 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870b12*/
    v4 = v2 == *v11; /*0x870b14*/
    LOBYTE(v55) = 5; /*0x870b16*/
    if ( !v4 ) /*0x870b1b*/
    {
      if ( v2 ) /*0x870b1f*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870b21*/
        if ( v4 ) /*0x870b25*/
          sub_772560(v2); /*0x870b29*/
      }
      v2 = *v11; /*0x870b2e*/
      if ( *v11 ) /*0x870b32*/
        ++v2[7].Unk08; /*0x870b38*/
    }
    v12 = v54; /*0x870b3b*/
    LOBYTE(v55) = 1; /*0x870b41*/
    if ( v54 ) /*0x870b46*/
    {
      --v54[7].Unk08; /*0x870b48*/
      if ( !v12[7].Unk08 ) /*0x870b51*/
        sub_772560(v12); /*0x870b56*/
    }
    sub_76C910(v2, (NiRenderedTexture *)dword_B43110); /*0x870b64*/
    sub_801110((int)v2, 3, 3, 0); /*0x870b70*/
    sub_760010(v1, 3u, &v2->Stage); /*0x870b7d*/
  }
  v13 = *(this + 0x3F); /*0x870b86*/
  VertexShader = v1->VertexShader; /*0x870b8c*/
  if ( VertexShader != (NiD3DVertexShader *)v13 ) /*0x870b91*/
  {
    if ( VertexShader ) /*0x870b95*/
    {
      if ( !InterlockedDecrement((volatile LONG *)VertexShader + 1) ) /*0x870b9b*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))VertexShader)(VertexShader, 1); /*0x870bb2*/
    }
    v1->VertexShader = (NiD3DVertexShader *)v13; /*0x870bb6*/
    if ( v13 ) /*0x870bb9*/
      InterlockedIncrement(v13 + 1); /*0x870bbf*/
  }
  v15 = *(this + 0x5F); /*0x870bc9*/
  PixelShader = v1->PixelShader; /*0x870bcf*/
  if ( PixelShader != (NiD3DPixelShader *)v15 ) /*0x870bd4*/
  {
    if ( PixelShader ) /*0x870bd8*/
    {
      if ( !InterlockedDecrement((volatile LONG *)PixelShader + 1) ) /*0x870bde*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))PixelShader)(PixelShader, 1); /*0x870bf5*/
    }
    v1->PixelShader = (NiD3DPixelShader *)v15; /*0x870bf9*/
    if ( v15 ) /*0x870bfc*/
      InterlockedIncrement(v15 + 1); /*0x870c02*/
  }
  if ( !v1->RenderStateGroup ) /*0x870c08*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c13*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x1B, 1, 0); /*0x870c1f*/
  if ( !v1->RenderStateGroup ) /*0x870c24*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c2f*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x13, 2, 0); /*0x870c3b*/
  if ( !v1->RenderStateGroup ) /*0x870c40*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c4b*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x14, 2, 0); /*0x870c57*/
  if ( !v1->RenderStateGroup ) /*0x870c5c*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c67*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xF, 0, 0); /*0x870c73*/
  if ( !v1->RenderStateGroup ) /*0x870c78*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c83*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 7, 1, 0); /*0x870c8f*/
  if ( !v1->RenderStateGroup ) /*0x870c94*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870c9f*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x17, 3, 0); /*0x870cab*/
  if ( !v1->RenderStateGroup ) /*0x870cb0*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870cbb*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xE, 0, 0); /*0x870cc7*/
  if ( !v1->RenderStateGroup ) /*0x870ccc*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870cd7*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x34, 0, 0); /*0x870ce3*/
  v4 = v1 == (NiD3DPass *)dword_B476E4; /*0x870ceb*/
  dword_B43EC8 = 0x21802; /*0x870cf1*/
  dword_B44558 = 0x18; /*0x870cfb*/
  if ( !v4 ) /*0x870d05*/
  {
    v4 = v1->RefCount-- == 1; /*0x870d07*/
    if ( v4 ) /*0x870d0a*/
      sub_7604D0(v1); /*0x870d0e*/
    v1 = (NiD3DPass *)dword_B476E4; /*0x870d13*/
    if ( dword_B476E4 ) /*0x870d1b*/
      ++v1->RefCount; /*0x870d21*/
  }
  if ( v1->StageCount < 4 ) /*0x870d29*/
  {
    v17 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870d3c*/
    v4 = v2 == *v17; /*0x870d3e*/
    LOBYTE(v55) = 6; /*0x870d41*/
    if ( !v4 ) /*0x870d46*/
    {
      if ( v2 ) /*0x870d4a*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870d4c*/
        if ( v4 ) /*0x870d4f*/
          sub_772560(v2); /*0x870d53*/
      }
      v2 = *v17; /*0x870d58*/
      if ( *v17 ) /*0x870d5d*/
        ++v2[7].Unk08; /*0x870d63*/
    }
    v18 = v54; /*0x870d67*/
    LOBYTE(v55) = 1; /*0x870d6d*/
    if ( v54 ) /*0x870d72*/
    {
      --v54[7].Unk08; /*0x870d74*/
      if ( !v18[7].Unk08 ) /*0x870d7c*/
        sub_772560(v18); /*0x870d81*/
    }
    sub_801110((int)v2, 0, 1, 2); /*0x870d8d*/
    sub_760010(v1, 0, &v2->Stage); /*0x870d9a*/
    v19 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870dac*/
    v4 = v2 == *v19; /*0x870dae*/
    LOBYTE(v55) = 7; /*0x870db1*/
    if ( !v4 ) /*0x870db6*/
    {
      if ( v2 ) /*0x870dba*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870dbc*/
        if ( v4 ) /*0x870dbf*/
          sub_772560(v2); /*0x870dc3*/
      }
      v2 = *v19; /*0x870dc8*/
      if ( *v19 ) /*0x870dcd*/
        ++v2[7].Unk08; /*0x870dd3*/
    }
    v20 = v54; /*0x870dd7*/
    LOBYTE(v55) = 1; /*0x870ddd*/
    if ( v54 ) /*0x870de2*/
    {
      --v54[7].Unk08; /*0x870de4*/
      if ( !v20[7].Unk08 ) /*0x870dec*/
        sub_772560(v20); /*0x870df1*/
    }
    sub_801110((int)v2, 1, 1, 2); /*0x870dfd*/
    sub_760010(v1, 1u, &v2->Stage); /*0x870e0a*/
    v21 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870e1c*/
    v4 = v2 == *v21; /*0x870e1e*/
    LOBYTE(v55) = 8; /*0x870e21*/
    if ( !v4 ) /*0x870e26*/
    {
      if ( v2 ) /*0x870e2a*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870e2c*/
        if ( v4 ) /*0x870e2f*/
          sub_772560(v2); /*0x870e33*/
      }
      v2 = *v21; /*0x870e38*/
      if ( *v21 ) /*0x870e3d*/
        ++v2[7].Unk08; /*0x870e43*/
    }
    v22 = v54; /*0x870e47*/
    LOBYTE(v55) = 1; /*0x870e4d*/
    if ( v54 ) /*0x870e52*/
    {
      --v54[7].Unk08; /*0x870e54*/
      if ( !v22[7].Unk08 ) /*0x870e5c*/
        sub_772560(v22); /*0x870e61*/
    }
    sub_801110((int)v2, 2, 1, 2); /*0x870e6d*/
    sub_760010(v1, 2u, &v2->Stage); /*0x870e7a*/
    v23 = (NiD3DTextureStage **)sub_772630(&v54); /*0x870e8c*/
    v4 = v2 == *v23; /*0x870e8e*/
    LOBYTE(v55) = 9; /*0x870e91*/
    if ( !v4 ) /*0x870e96*/
    {
      if ( v2 ) /*0x870e9a*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x870e9c*/
        if ( v4 ) /*0x870e9f*/
          sub_772560(v2); /*0x870ea3*/
      }
      v2 = *v23; /*0x870ea8*/
      if ( *v23 ) /*0x870ead*/
        ++v2[7].Unk08; /*0x870eb3*/
    }
    v24 = v54; /*0x870eb7*/
    LOBYTE(v55) = 1; /*0x870ebd*/
    if ( v54 ) /*0x870ec2*/
    {
      --v54[7].Unk08; /*0x870ec4*/
      if ( !v24[7].Unk08 ) /*0x870ecc*/
        sub_772560(v24); /*0x870ed1*/
    }
    sub_76C910(v2, (NiRenderedTexture *)dword_B43110); /*0x870edf*/
    sub_801110((int)v2, 3, 3, 0); /*0x870eeb*/
    sub_760010(v1, 3u, &v2->Stage); /*0x870ef8*/
  }
  v25 = *(this + 0x40); /*0x870f01*/
  v26 = v1->VertexShader; /*0x870f07*/
  if ( v26 != (NiD3DVertexShader *)v25 ) /*0x870f0c*/
  {
    if ( v26 ) /*0x870f10*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v26 + 1) ) /*0x870f16*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v26)(v26, 1); /*0x870f2d*/
    }
    v1->VertexShader = (NiD3DVertexShader *)v25; /*0x870f31*/
    if ( v25 ) /*0x870f34*/
      InterlockedIncrement(v25 + 1); /*0x870f3a*/
  }
  v27 = *(this + 0x5F); /*0x870f44*/
  v28 = v1->PixelShader; /*0x870f4a*/
  if ( v28 != (NiD3DPixelShader *)v27 ) /*0x870f4f*/
  {
    if ( v28 ) /*0x870f53*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v28 + 1) ) /*0x870f59*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v28)(v28, 1); /*0x870f70*/
    }
    v1->PixelShader = (NiD3DPixelShader *)v27; /*0x870f74*/
    if ( v27 ) /*0x870f77*/
      InterlockedIncrement(v27 + 1); /*0x870f7d*/
  }
  if ( !v1->RenderStateGroup ) /*0x870f83*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870f8e*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x1B, 1, 0); /*0x870f9a*/
  if ( !v1->RenderStateGroup ) /*0x870f9f*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870faa*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x13, 2, 0); /*0x870fb6*/
  if ( !v1->RenderStateGroup ) /*0x870fbb*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870fc6*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x14, 2, 0); /*0x870fd2*/
  if ( !v1->RenderStateGroup ) /*0x870fd7*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870fe2*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xF, 0, 0); /*0x870fee*/
  if ( !v1->RenderStateGroup ) /*0x870ff3*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x870ffe*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 7, 1, 0); /*0x87100a*/
  if ( !v1->RenderStateGroup ) /*0x87100f*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x87101a*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x17, 3, 0); /*0x871026*/
  if ( !v1->RenderStateGroup ) /*0x87102b*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871036*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xE, 0, 0); /*0x871042*/
  if ( !v1->RenderStateGroup ) /*0x871047*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871052*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x34, 0, 0); /*0x87105e*/
  v4 = v1 == (NiD3DPass *)dword_B476E8; /*0x871066*/
  dword_B43ED4 = 0x61808; /*0x87106c*/
  dword_B44564 = 0x18; /*0x871076*/
  if ( !v4 ) /*0x871080*/
  {
    v4 = v1->RefCount-- == 1; /*0x871082*/
    if ( v4 ) /*0x871085*/
      sub_7604D0(v1); /*0x871089*/
    v1 = (NiD3DPass *)dword_B476E8; /*0x87108e*/
    if ( dword_B476E8 ) /*0x871096*/
      ++v1->RefCount; /*0x87109c*/
  }
  if ( v1->StageCount < 4 ) /*0x8710a4*/
  {
    v29 = (NiD3DTextureStage **)sub_772630(&v54); /*0x8710b7*/
    v4 = v2 == *v29; /*0x8710b9*/
    LOBYTE(v55) = 0xA; /*0x8710bc*/
    if ( !v4 ) /*0x8710c1*/
    {
      if ( v2 ) /*0x8710c5*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x8710c7*/
        if ( v4 ) /*0x8710ca*/
          sub_772560(v2); /*0x8710ce*/
      }
      v2 = *v29; /*0x8710d3*/
      if ( *v29 ) /*0x8710d8*/
        ++v2[7].Unk08; /*0x8710de*/
    }
    v30 = v54; /*0x8710e2*/
    LOBYTE(v55) = 1; /*0x8710e8*/
    if ( v54 ) /*0x8710ed*/
    {
      --v54[7].Unk08; /*0x8710ef*/
      if ( !v30[7].Unk08 ) /*0x8710f7*/
        sub_772560(v30); /*0x8710fc*/
    }
    sub_801110((int)v2, 0, 1, 2); /*0x871108*/
    sub_760010(v1, 0, &v2->Stage); /*0x871115*/
    v31 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871127*/
    v4 = v2 == *v31; /*0x871129*/
    LOBYTE(v55) = 0xB; /*0x87112c*/
    if ( !v4 ) /*0x871131*/
    {
      if ( v2 ) /*0x871135*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x871137*/
        if ( v4 ) /*0x87113a*/
          sub_772560(v2); /*0x87113e*/
      }
      v2 = *v31; /*0x871143*/
      if ( *v31 ) /*0x871148*/
        ++v2[7].Unk08; /*0x87114e*/
    }
    v32 = v54; /*0x871152*/
    LOBYTE(v55) = 1; /*0x871158*/
    if ( v54 ) /*0x87115d*/
    {
      --v54[7].Unk08; /*0x87115f*/
      if ( !v32[7].Unk08 ) /*0x871167*/
        sub_772560(v32); /*0x87116c*/
    }
    sub_801110((int)v2, 1, 1, 2); /*0x871178*/
    sub_760010(v1, 1u, &v2->Stage); /*0x871185*/
    v33 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871197*/
    v4 = v2 == *v33; /*0x871199*/
    LOBYTE(v55) = 0xC; /*0x87119c*/
    if ( !v4 ) /*0x8711a1*/
    {
      if ( v2 ) /*0x8711a5*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x8711a7*/
        if ( v4 ) /*0x8711aa*/
          sub_772560(v2); /*0x8711ae*/
      }
      v2 = *v33; /*0x8711b3*/
      if ( *v33 ) /*0x8711b8*/
        ++v2[7].Unk08; /*0x8711be*/
    }
    v34 = v54; /*0x8711c2*/
    LOBYTE(v55) = 1; /*0x8711c8*/
    if ( v54 ) /*0x8711cd*/
    {
      --v54[7].Unk08; /*0x8711cf*/
      if ( !v34[7].Unk08 ) /*0x8711d7*/
        sub_772560(v34); /*0x8711dc*/
    }
    sub_801110((int)v2, 2, 1, 2); /*0x8711e8*/
    sub_760010(v1, 2u, &v2->Stage); /*0x8711f5*/
    v35 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871207*/
    v4 = v2 == *v35; /*0x871209*/
    LOBYTE(v55) = 0xD; /*0x87120c*/
    if ( !v4 ) /*0x871211*/
    {
      if ( v2 ) /*0x871215*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x871217*/
        if ( v4 ) /*0x87121a*/
          sub_772560(v2); /*0x87121e*/
      }
      v2 = *v35; /*0x871223*/
      if ( *v35 ) /*0x871228*/
        ++v2[7].Unk08; /*0x87122e*/
    }
    v36 = v54; /*0x871232*/
    LOBYTE(v55) = 1; /*0x871238*/
    if ( v54 ) /*0x87123d*/
    {
      --v54[7].Unk08; /*0x87123f*/
      if ( !v36[7].Unk08 ) /*0x871247*/
        sub_772560(v36); /*0x87124c*/
    }
    sub_76C910(v2, (NiRenderedTexture *)dword_B43110); /*0x87125a*/
    sub_801110((int)v2, 3, 3, 0); /*0x871266*/
    sub_760010(v1, 3u, &v2->Stage); /*0x871273*/
  }
  v37 = *(this + 0x41); /*0x87127c*/
  v38 = v1->VertexShader; /*0x871282*/
  if ( v38 != (NiD3DVertexShader *)v37 ) /*0x871287*/
  {
    if ( v38 ) /*0x87128b*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v38 + 1) ) /*0x871291*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v38)(v38, 1); /*0x8712a8*/
    }
    v1->VertexShader = (NiD3DVertexShader *)v37; /*0x8712ac*/
    if ( v37 ) /*0x8712af*/
      InterlockedIncrement(v37 + 1); /*0x8712b5*/
  }
  v39 = *(this + 0x60); /*0x8712bf*/
  v40 = v1->PixelShader; /*0x8712c5*/
  if ( v40 != (NiD3DPixelShader *)v39 ) /*0x8712ca*/
  {
    if ( v40 ) /*0x8712ce*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v40 + 1) ) /*0x8712d4*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v40)(v40, 1); /*0x8712eb*/
    }
    v1->PixelShader = (NiD3DPixelShader *)v39; /*0x8712ef*/
    if ( v39 ) /*0x8712f2*/
      InterlockedIncrement(v39 + 1); /*0x8712f8*/
  }
  if ( !v1->RenderStateGroup ) /*0x8712fe*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871309*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x1B, 1, 0); /*0x871315*/
  if ( !v1->RenderStateGroup ) /*0x87131a*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871325*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x13, 2, 0); /*0x871331*/
  if ( !v1->RenderStateGroup ) /*0x871336*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871341*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x14, 2, 0); /*0x87134d*/
  if ( !v1->RenderStateGroup ) /*0x871352*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x87135d*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xF, 0, 0); /*0x871369*/
  if ( !v1->RenderStateGroup ) /*0x87136e*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871379*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 7, 1, 0); /*0x871385*/
  if ( !v1->RenderStateGroup ) /*0x87138a*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871395*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x17, 3, 0); /*0x8713a1*/
  if ( !v1->RenderStateGroup ) /*0x8713a6*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8713b1*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xE, 0, 0); /*0x8713bd*/
  if ( !v1->RenderStateGroup ) /*0x8713c2*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8713cd*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x34, 0, 0); /*0x8713d9*/
  v4 = v1 == (NiD3DPass *)dword_B476EC; /*0x8713e1*/
  dword_B43F00 = 0x23802; /*0x8713e7*/
  dword_B44590 = 0x38; /*0x8713f1*/
  if ( !v4 ) /*0x8713fb*/
  {
    v4 = v1->RefCount-- == 1; /*0x8713fd*/
    if ( v4 ) /*0x871400*/
      sub_7604D0(v1); /*0x871404*/
    v1 = (NiD3DPass *)dword_B476EC; /*0x871409*/
    if ( dword_B476EC ) /*0x871411*/
      ++v1->RefCount; /*0x871417*/
  }
  if ( v1->StageCount < 4 ) /*0x87141f*/
  {
    v41 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871432*/
    v4 = v2 == *v41; /*0x871434*/
    LOBYTE(v55) = 0xE; /*0x871437*/
    if ( !v4 ) /*0x87143c*/
    {
      if ( v2 ) /*0x871440*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x871442*/
        if ( v4 ) /*0x871445*/
          sub_772560(v2); /*0x871449*/
      }
      v2 = *v41; /*0x87144e*/
      if ( *v41 ) /*0x871453*/
        ++v2[7].Unk08; /*0x871459*/
    }
    v42 = v54; /*0x87145d*/
    LOBYTE(v55) = 1; /*0x871463*/
    if ( v54 ) /*0x871468*/
    {
      --v54[7].Unk08; /*0x87146a*/
      if ( !v42[7].Unk08 ) /*0x871472*/
        sub_772560(v42); /*0x871477*/
    }
    sub_801110((int)v2, 0, 1, 2); /*0x871483*/
    sub_760010(v1, 0, &v2->Stage); /*0x871490*/
    v43 = (NiD3DTextureStage **)sub_772630(&v54); /*0x8714a2*/
    v4 = v2 == *v43; /*0x8714a4*/
    LOBYTE(v55) = 0xF; /*0x8714a7*/
    if ( !v4 ) /*0x8714ac*/
    {
      if ( v2 ) /*0x8714b0*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x8714b2*/
        if ( v4 ) /*0x8714b5*/
          sub_772560(v2); /*0x8714b9*/
      }
      v2 = *v43; /*0x8714be*/
      if ( *v43 ) /*0x8714c3*/
        ++v2[7].Unk08; /*0x8714c9*/
    }
    v44 = v54; /*0x8714cd*/
    LOBYTE(v55) = 1; /*0x8714d3*/
    if ( v54 ) /*0x8714d8*/
    {
      --v54[7].Unk08; /*0x8714da*/
      if ( !v44[7].Unk08 ) /*0x8714e2*/
        sub_772560(v44); /*0x8714e7*/
    }
    sub_801110((int)v2, 1, 1, 2); /*0x8714f3*/
    sub_760010(v1, 1u, &v2->Stage); /*0x871500*/
    v45 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871512*/
    v4 = v2 == *v45; /*0x871514*/
    LOBYTE(v55) = 0x10; /*0x871517*/
    if ( !v4 ) /*0x87151c*/
    {
      if ( v2 ) /*0x871520*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x871522*/
        if ( v4 ) /*0x871525*/
          sub_772560(v2); /*0x871529*/
      }
      v2 = *v45; /*0x87152e*/
      if ( *v45 ) /*0x871533*/
        ++v2[7].Unk08; /*0x871539*/
    }
    v46 = v54; /*0x87153d*/
    LOBYTE(v55) = 1; /*0x871543*/
    if ( v54 ) /*0x871548*/
    {
      --v54[7].Unk08; /*0x87154a*/
      if ( !v46[7].Unk08 ) /*0x871552*/
        sub_772560(v46); /*0x871557*/
    }
    sub_801110((int)v2, 2, 1, 2); /*0x871563*/
    sub_760010(v1, 2u, &v2->Stage); /*0x871570*/
    v47 = (NiD3DTextureStage **)sub_772630(&v54); /*0x871582*/
    v4 = v2 == *v47; /*0x871584*/
    LOBYTE(v55) = 0x11; /*0x871587*/
    if ( !v4 ) /*0x87158c*/
    {
      if ( v2 ) /*0x871590*/
      {
        v4 = v2[7].Unk08-- == 1; /*0x871592*/
        if ( v4 ) /*0x871595*/
          sub_772560(v2); /*0x871599*/
      }
      v2 = *v47; /*0x87159e*/
      if ( *v47 ) /*0x8715a3*/
        ++v2[7].Unk08; /*0x8715a9*/
    }
    v48 = v54; /*0x8715ad*/
    LOBYTE(v55) = 1; /*0x8715b3*/
    if ( v54 ) /*0x8715b8*/
    {
      --v54[7].Unk08; /*0x8715ba*/
      if ( !v48[7].Unk08 ) /*0x8715c2*/
        sub_772560(v48); /*0x8715c7*/
    }
    sub_76C910(v2, (NiRenderedTexture *)dword_B43110); /*0x8715d5*/
    sub_801110((int)v2, 3, 3, 0); /*0x8715e1*/
    sub_760010(v1, 3u, &v2->Stage); /*0x8715ee*/
  }
  v49 = *(this + 0x42); /*0x8715f7*/
  v50 = v1->VertexShader; /*0x8715fd*/
  if ( v50 != (NiD3DVertexShader *)v49 ) /*0x871602*/
  {
    if ( v50 ) /*0x871606*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v50 + 1) ) /*0x87160c*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v50)(v50, 1); /*0x871623*/
    }
    v1->VertexShader = (NiD3DVertexShader *)v49; /*0x871627*/
    if ( v49 ) /*0x87162a*/
      InterlockedIncrement(v49 + 1); /*0x871630*/
  }
  v51 = *(this + 0x60); /*0x87163a*/
  v52 = v1->PixelShader; /*0x871640*/
  if ( v52 != (NiD3DPixelShader *)v51 ) /*0x871645*/
  {
    if ( v52 ) /*0x871649*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v52 + 1) ) /*0x87164f*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v52)(v52, 1); /*0x871666*/
    }
    v1->PixelShader = (NiD3DPixelShader *)v51; /*0x87166a*/
    if ( v51 ) /*0x87166d*/
      InterlockedIncrement(v51 + 1); /*0x871673*/
  }
  if ( !v1->RenderStateGroup ) /*0x871679*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871684*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x1B, 1, 0); /*0x871690*/
  if ( !v1->RenderStateGroup ) /*0x871695*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8716a0*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x13, 2, 0); /*0x8716ac*/
  if ( !v1->RenderStateGroup ) /*0x8716b1*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8716bc*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x14, 2, 0); /*0x8716c8*/
  if ( !v1->RenderStateGroup ) /*0x8716cd*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8716d8*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xF, 0, 0); /*0x8716e4*/
  if ( !v1->RenderStateGroup ) /*0x8716e9*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8716f4*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 7, 1, 0); /*0x871700*/
  if ( !v1->RenderStateGroup ) /*0x871705*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871710*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x17, 3, 0); /*0x87171c*/
  if ( !v1->RenderStateGroup ) /*0x871721*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x87172c*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0xE, 0, 0); /*0x871738*/
  if ( !v1->RenderStateGroup ) /*0x87173d*/
    v1->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871748*/
  sub_772CD0((_DWORD *)v1->RenderStateGroup, 0x34, 0, 0); /*0x871754*/
  dword_B43F0C = 0x63808; /*0x87175e*/
  dword_B4459C = 0x38; /*0x871768*/
  LOBYTE(v55) = 0; /*0x871772*/
  if ( v2 ) /*0x871777*/
  {
    v4 = v2[7].Unk08-- == 1; /*0x871779*/
    if ( v4 ) /*0x87177c*/
      sub_772560(v2); /*0x871780*/
  }
  v4 = v1->RefCount-- == 1; /*0x871785*/
  v55 = 0xFFFFFFFF; /*0x871788*/
  if ( v4 ) /*0x87178c*/
    sub_7604D0(v1); /*0x871790*/
}
