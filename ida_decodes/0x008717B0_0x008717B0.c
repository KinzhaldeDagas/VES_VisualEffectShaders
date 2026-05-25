// 0x008717B0 @ 0x008717B0
// MoonSugarEffect decode: ParallaxShader pass population slot +0xD4. Populates two pooled passes dword_B476F0..B476F4.
void __thiscall sub_8717B0(volatile LONG **this)
{
  NiD3DPass *v2; // esi
  NiD3DTextureStage *v3; // ebx
  int v4; // eax
  bool v5; // zf
  NiD3DTextureStage *v6; // eax
  NiD3DTextureStage *v7; // eax
  volatile LONG *v8; // ebp
  NiD3DVertexShader *VertexShader; // edi
  volatile LONG *v10; // ebp
  NiD3DPixelShader *PixelShader; // edi
  NiD3DTextureStage **v12; // edi
  NiD3DTextureStage *v13; // eax
  volatile LONG *v14; // ebp
  NiD3DVertexShader *v15; // edi
  volatile LONG *v16; // ebp
  NiD3DPixelShader *v17; // edi
  NiD3DTextureStage *v19; // [esp+20h] [ebp-10h] BYREF
  unsigned int v20; // [esp+2Ch] [ebp-4h]

  v2 = 0; /*0x8717dd*/
  v3 = 0; /*0x8717e3*/
  v20 = 0; /*0x8717e5*/
  v4 = dword_B476F0; /*0x8717ed*/
  v5 = dword_B476F0 == 0; /*0x8717f2*/
  LOBYTE(v20) = 1; /*0x8717f4*/
  if ( !v5 ) /*0x8717f9*/
  {
    v2 = (NiD3DPass *)v4; /*0x8717fb*/
    if ( v4 ) /*0x871803*/
      ++*(_DWORD *)(v4 + 0x60); /*0x871805*/
  }
  if ( !v2->StageCount ) /*0x871809*/
  {
    v6 = (NiD3DTextureStage *)*sub_772630(&v19); /*0x87181e*/
    if ( v6 ) /*0x871822*/
    {
      v3 = v6; /*0x871824*/
      ++v6[7].Unk08; /*0x871826*/
    }
    v7 = v19; /*0x87182e*/
    LOBYTE(v20) = 1; /*0x871834*/
    if ( v19 ) /*0x871839*/
    {
      --v19[7].Unk08; /*0x87183b*/
      if ( !v7[7].Unk08 ) /*0x871844*/
        sub_772560(v7); /*0x871849*/
    }
    sub_801110((int)v3, 0, 1, 2); /*0x871855*/
    sub_760010(v2, v2->CurrentStage, &v3->Stage); /*0x871864*/
  }
  v8 = *(this + 0x43); /*0x871869*/
  VertexShader = v2->VertexShader; /*0x87186f*/
  if ( VertexShader != (NiD3DVertexShader *)v8 ) /*0x871874*/
  {
    if ( VertexShader ) /*0x871878*/
    {
      if ( !InterlockedDecrement((volatile LONG *)VertexShader + 1) ) /*0x87187e*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))VertexShader)(VertexShader, 1); /*0x871894*/
    }
    v2->VertexShader = (NiD3DVertexShader *)v8; /*0x871898*/
    if ( v8 ) /*0x87189b*/
      InterlockedIncrement(v8 + 1); /*0x8718a1*/
  }
  v10 = *(this + 0x61); /*0x8718ab*/
  PixelShader = v2->PixelShader; /*0x8718b1*/
  if ( PixelShader != (NiD3DPixelShader *)v10 ) /*0x8718b6*/
  {
    if ( PixelShader ) /*0x8718ba*/
    {
      if ( !InterlockedDecrement((volatile LONG *)PixelShader + 1) ) /*0x8718c0*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))PixelShader)(PixelShader, 1); /*0x8718d6*/
    }
    v2->PixelShader = (NiD3DPixelShader *)v10; /*0x8718da*/
    if ( v10 ) /*0x8718dd*/
      InterlockedIncrement(v10 + 1); /*0x8718e3*/
  }
  if ( !v2->RenderStateGroup ) /*0x8718e9*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8718f4*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x1B, 1, 0); /*0x871904*/
  if ( !v2->RenderStateGroup ) /*0x871909*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871914*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x13, 9, 0); /*0x871920*/
  if ( !v2->RenderStateGroup ) /*0x871925*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871930*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x14, 1, 0); /*0x87193b*/
  if ( !v2->RenderStateGroup ) /*0x871940*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x87194b*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0xF, 0, 0); /*0x871957*/
  if ( !v2->RenderStateGroup ) /*0x87195c*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871967*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 7, 1, 0); /*0x871972*/
  if ( !v2->RenderStateGroup ) /*0x871977*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871982*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x17, 3, 0); /*0x87198e*/
  if ( !v2->RenderStateGroup ) /*0x871993*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x87199e*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0xE, 0, 0); /*0x8719aa*/
  if ( !v2->RenderStateGroup ) /*0x8719af*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x8719ba*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x34, 0, 0); /*0x8719c6*/
  v5 = v2 == (NiD3DPass *)dword_B476F4; /*0x8719cb*/
  dword_B43F54 = 0x20002; /*0x8719d1*/
  dword_B445E4 = 0x100; /*0x8719db*/
  if ( !v5 ) /*0x8719e5*/
  {
    v5 = v2->RefCount-- == 1; /*0x8719e7*/
    if ( v5 ) /*0x8719eb*/
      sub_7604D0(v2); /*0x8719ef*/
    v2 = (NiD3DPass *)dword_B476F4; /*0x8719f4*/
    if ( dword_B476F4 ) /*0x8719fc*/
      ++v2->RefCount; /*0x871a02*/
  }
  if ( !v2->StageCount ) /*0x871a05*/
  {
    v12 = (NiD3DTextureStage **)sub_772630(&v19); /*0x871a17*/
    v5 = v3 == *v12; /*0x871a19*/
    LOBYTE(v20) = 3; /*0x871a1b*/
    if ( !v5 ) /*0x871a20*/
    {
      if ( v3 ) /*0x871a24*/
      {
        v5 = v3[7].Unk08-- == 1; /*0x871a26*/
        if ( v5 ) /*0x871a2a*/
          sub_772560(v3); /*0x871a2e*/
      }
      v3 = *v12; /*0x871a33*/
      if ( *v12 ) /*0x871a37*/
        ++v3[7].Unk08; /*0x871a3d*/
    }
    v13 = v19; /*0x871a40*/
    LOBYTE(v20) = 1; /*0x871a46*/
    if ( v19 ) /*0x871a4b*/
    {
      --v19[7].Unk08; /*0x871a4d*/
      if ( !v13[7].Unk08 ) /*0x871a56*/
        sub_772560(v13); /*0x871a5b*/
    }
    sub_801110((int)v3, 0, 1, 2); /*0x871a66*/
    sub_760010(v2, v2->CurrentStage, &v3->Stage); /*0x871a75*/
  }
  v14 = *(this + 0x44); /*0x871a7e*/
  v15 = v2->VertexShader; /*0x871a84*/
  if ( v15 != (NiD3DVertexShader *)v14 ) /*0x871a89*/
  {
    if ( v15 ) /*0x871a8d*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v15 + 1) ) /*0x871a93*/
        (**(void (__thiscall ***)(NiD3DVertexShader *, int))v15)(v15, 1); /*0x871aa9*/
    }
    v2->VertexShader = (NiD3DVertexShader *)v14; /*0x871aad*/
    if ( v14 ) /*0x871ab0*/
      InterlockedIncrement(v14 + 1); /*0x871ab6*/
  }
  v16 = *(this + 0x61); /*0x871ac0*/
  v17 = v2->PixelShader; /*0x871ac6*/
  if ( v17 != (NiD3DPixelShader *)v16 ) /*0x871acb*/
  {
    if ( v17 ) /*0x871acf*/
    {
      if ( !InterlockedDecrement((volatile LONG *)v17 + 1) ) /*0x871ad5*/
        (**(void (__thiscall ***)(NiD3DPixelShader *, int))v17)(v17, 1); /*0x871aeb*/
    }
    v2->PixelShader = (NiD3DPixelShader *)v16; /*0x871aef*/
    if ( v16 ) /*0x871af2*/
      InterlockedIncrement(v16 + 1); /*0x871af8*/
  }
  if ( !v2->RenderStateGroup ) /*0x871afe*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b09*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x1B, 1, 0); /*0x871b15*/
  if ( !v2->RenderStateGroup ) /*0x871b1a*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b25*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x13, 9, 0); /*0x871b31*/
  if ( !v2->RenderStateGroup ) /*0x871b36*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b41*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x14, 1, 0); /*0x871b4d*/
  if ( !v2->RenderStateGroup ) /*0x871b52*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b5d*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0xF, 0, 0); /*0x871b69*/
  if ( !v2->RenderStateGroup ) /*0x871b6e*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b79*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 7, 1, 0); /*0x871b85*/
  if ( !v2->RenderStateGroup ) /*0x871b8a*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871b95*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x17, 3, 0); /*0x871ba1*/
  if ( !v2->RenderStateGroup ) /*0x871ba6*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871bb1*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0xE, 0, 0); /*0x871bbd*/
  if ( !v2->RenderStateGroup ) /*0x871bc2*/
    v2->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x871bcd*/
  sub_772CD0((_DWORD *)v2->RenderStateGroup, 0x34, 0, 0); /*0x871bd9*/
  dword_B43F58 = 0x60008; /*0x871be3*/
  dword_B445E8 = 0x100; /*0x871bed*/
  LOBYTE(v20) = 0; /*0x871bf7*/
  if ( v3 ) /*0x871bfc*/
  {
    v5 = v3[7].Unk08-- == 1; /*0x871bfe*/
    if ( v5 ) /*0x871c01*/
      sub_772560(v3); /*0x871c05*/
  }
  v5 = v2->RefCount-- == 1; /*0x871c0a*/
  v20 = 0xFFFFFFFF; /*0x871c0d*/
  if ( v5 ) /*0x871c11*/
    sub_7604D0(v2); /*0x871c15*/
}
