// 0x4D0190 @ 0x4D0190
// MoonSugarEffect decode: canopy/shadow offscreen path constructs culling process with null VisibleGeo and renders through sub_70C0B0 into StartUsingRenderTarget targets, so it uses accumulator-direct culling.
int *__stdcall sub_4D0190(int *a1, NiCamera *a2)
{
  BSRenderedTexture *v2; // esi
  char v3; // bl
  BSRenderedTexture *v4; // edi
  int v5; // ebp
  NiDX9Renderer *v6; // eax
  BSTextureManager *v7; // ecx
  int v8; // eax
  int v9; // eax
  BSRenderedTexture *v10; // eax
  BSRenderedTexture *v11; // eax
  NiDX9Renderer *v12; // ecx
  NiDX9Renderer *v13; // ecx
  int ShadowSceneNode; // esi
  char v15; // al
  NiRenderTargetGroup *v16; // eax
  char v17; // bl
  int v18; // eax
  int v19; // edi
  char v20; // al
  unsigned __int16 v21; // bx
  NiRenderTargetGroup *v22; // eax
  ShaderDefinition *ShaderDefinition; // eax
  BSShader *shader; // edi
  NiRenderedTexture *InnerTexture; // eax
  LONG (__stdcall *v26)(volatile LONG *); // ebx
  char v28; // [esp+14h] [ebp-D4h]
  char v29; // [esp+15h] [ebp-D3h]
  char v30; // [esp+16h] [ebp-D2h]
  char v31; // [esp+17h] [ebp-D1h]
  BSRenderedTexture *v32; // [esp+18h] [ebp-D0h]
  char v33; // [esp+1Fh] [ebp-C9h]
  BSRenderedTexture *a3; // [esp+20h] [ebp-C8h]
  char a4[4]; // [esp+24h] [ebp-C4h]
  float v36; // [esp+2Ch] [ebp-BCh] BYREF
  float v37; // [esp+30h] [ebp-B8h]
  float v38; // [esp+34h] [ebp-B4h]
  float v39; // [esp+38h] [ebp-B0h]
  float v40[4]; // [esp+3Ch] [ebp-ACh] BYREF
  _BYTE v41[156]; // [esp+4Ch] [ebp-9Ch] BYREF

  v2 = 0; /*0x4d01bd*/
  nullsub_returnTrue_0arg(); /*0x4d01c5*/
  if ( byte_B42D40 && ImageSpaceEffectEnabled && ShaderPackage >= 2 ) /*0x4d01e6*/
  {
    v3 = 1; /*0x4d01e8*/
    v28 = 1; /*0x4d01ea*/
  }
  else
  {
    v28 = 0; /*0x4d01f0*/
    v3 = 0; /*0x4d01f5*/
  }
  v4 = 0; /*0x4d01f9*/
  v32 = 0; /*0x4d01fb*/
  v5 = 0; /*0x4d01ff*/
  *(_DWORD *)&v41[0x98] = 1; /*0x4d0201*/
  *(_DWORD *)a4 = 0; /*0x4d020c*/
  a3 = 0; /*0x4d0210*/
  v6 = dword_B43104; /*0x4d0216*/
  v7 = g_textureManager; /*0x4d021b*/
  v41[0x98] = 3; /*0x4d0229*/
  if ( v3 ) /*0x4d0232*/
  {
    v8 = sub_7C2420(v7, v6, 0x100, 0, 0, 0); /*0x4d0238*/
    if ( v8 ) /*0x4d023f*/
    {
      v32 = (BSRenderedTexture *)v8; /*0x4d0241*/
      InterlockedIncrement((volatile LONG *)(v8 + 4)); /*0x4d0249*/
      v4 = v32; /*0x4d024f*/
    }
    v9 = sub_7C2420(g_textureManager, dword_B43104, 0x100, 0, 0, 0); /*0x4d026b*/
    if ( v9 ) /*0x4d0272*/
    {
      a3 = (BSRenderedTexture *)v9; /*0x4d0274*/
      InterlockedIncrement((volatile LONG *)(v9 + 4)); /*0x4d027c*/
      v2 = a3; /*0x4d0282*/
    }
    v10 = sub_7C15C0(g_textureManager, (int)dword_B43104, 0x100, 0, 0, 4); /*0x4d029e*/
    if ( v10 ) /*0x4d02a5*/
    {
      *(_DWORD *)a4 = v10; /*0x4d02a7*/
      InterlockedIncrement((volatile LONG *)&v10->members); /*0x4d02af*/
      v5 = *(_DWORD *)a4; /*0x4d02b5*/
    }
  }
  else
  {
    v11 = sub_7C15C0(v7, (int)v6, 0x100, 0, 0, 0); /*0x4d02bb*/
    if ( !v11 ) /*0x4d02c2*/
      goto LABEL_54; /*0x4d02c2*/
    v32 = v11; /*0x4d02c8*/
    InterlockedIncrement((volatile LONG *)&v11->members); /*0x4d02d0*/
    v4 = v32; /*0x4d02d6*/
  }
  if ( v4 ) /*0x4d02dc*/
  {
    if ( !v3 || v5 && v2 ) /*0x4d02f0*/
    {
      v12 = dword_B43104; /*0x4d02f8*/
      v40[0] = 0.0; /*0x4d02fe*/
      v40[1] = 0.0; /*0x4d0306*/
      v40[2] = 0.0; /*0x4d030b*/
      v40[3] = 0.0; /*0x4d030f*/
      ((void (__thiscall *)(NiDX9Renderer *, float *))v12->__vftable->super.GetClearColor)(v12, v40); /*0x4d0318*/
      v13 = dword_B43104; /*0x4d031c*/
      if ( v3 ) /*0x4d0322*/
      {
        v36 = flt_A4695C; /*0x4d032e*/
        v37 = flt_A46958; /*0x4d0339*/
        v38 = flt_A46954; /*0x4d0343*/
      }
      else
      {
        v36 = 0.0; /*0x4d035c*/
        v37 = 0.0; /*0x4d0361*/
        v38 = 0.0; /*0x4d0365*/
      }
      v39 = 1.0; /*0x4d0349*/
      ((void (__thiscall *)(NiDX9Renderer *, float *))v13->__vftable->super.SetClearColor4)(v13, &v36); /*0x4d0352*/
      ShadowSceneNode = GetShadowSceneNode(0); /*0x4d0386*/
      NiCullingProcess_NiCullingProcess((NiCullingProcess *)v41, 0); /*0x4d0388*/
      v15 = *(_BYTE *)(ShadowSceneNode + 0x12C); /*0x4d038d*/
      v41[0x98] = 4; /*0x4d0393*/
      v33 = v15; /*0x4d039b*/
      *(_BYTE *)(ShadowSceneNode + 0x12C) = 1; /*0x4d039f*/
      *((_BYTE *)InitBSShaderAccumulator() + 0x21E3) = 0; /*0x4d03ab*/
      v31 = 0; /*0x4d03be*/
      if ( !g_Renderer->member.super.SceneState1 && !g_Renderer->member.super.SceneState2 ) /*0x4d03c5*/
      {
        NiRenderer_BeginScene(kClear_NONE, 0); /*0x4d03d2*/
        v31 = 1; /*0x4d03da*/
      }
      v16 = BSRenderedTexture::UseTextureToRender(v4); /*0x4d03e3*/
      StartUsingRenderTarget(v16, kClear_ALL); /*0x4d03e9*/
      v17 = byte_B42E86; /*0x4d03f5*/
      byte_B42E86 = 1; /*0x4d0404*/
      sub_70C0B0(a2, (SceneGraph *)ShadowSceneNode, (NiCullingProcess *)v41, 0); /*0x4d040b*/
      byte_B42E86 = v17; /*0x4d0413*/
      sub_7D7110(); /*0x4d0419*/
      if ( v28 ) /*0x4d0423*/
      {
        v18 = sub_49A140(); /*0x4d0429*/
        v19 = v18; /*0x4d042e*/
        v30 = 0; /*0x4d0432*/
        if ( v18 ) /*0x4d0437*/
        {
          v20 = *(_BYTE *)(v18 + 0x18) & 1; /*0x4d043c*/
          *(_WORD *)(v19 + 0x18) |= 1u; /*0x4d043e*/
          v30 = v20; /*0x4d0443*/
        }
        if ( !byte_B125E8 || (v29 = 1, !*(_BYTE *)(sub_55F7E0(1) + 0x20)) ) /*0x4d045a*/
          v29 = 0; /*0x4d0465*/
        *(_BYTE *)(sub_55F7E0(1) + 0x20) = 0; /*0x4d0471*/
        v21 = dword_B42EAC; /*0x4d0475*/
        sub_7B4890(6u); /*0x4d047e*/
        if ( a3 ) /*0x4d048c*/
          v22 = BSRenderedTexture::UseTextureToRender(a3); /*0x4d048e*/
        else
          v22 = 0; /*0x4d0495*/
        StartUsingRenderTarget(v22, kClear_ALL); /*0x4d049a*/
        sub_70C0B0(a2, (SceneGraph *)ShadowSceneNode, (NiCullingProcess *)v41, 0); /*0x4d04a8*/
        sub_7D7110(); /*0x4d04ad*/
        sub_7B4890(v21); /*0x4d04b3*/
        *(_BYTE *)(sub_55F7E0(1) + 0x20) = v29; /*0x4d04c8*/
        if ( v19 ) /*0x4d04cb*/
        {
          if ( v30 ) /*0x4d04d2*/
            *(_WORD *)(v19 + 0x18) |= 1u; /*0x4d04d4*/
          else
            *(_WORD *)(v19 + 0x18) &= ~1u; /*0x4d04db*/
        }
        ShaderDefinition = GetShaderDefinition(0x18u); /*0x4d04e3*/
        if ( ShaderDefinition ) /*0x4d04ed*/
        {
          shader = ShaderDefinition->shader; /*0x4d04ef*/
          if ( shader ) /*0x4d04f4*/
          {
            if ( shader->__vftable[1].super.super.super.GetType((NiShader *)shader) ) /*0x4d0500*/
            {
              InnerTexture = BSRenderedTexture::GetInnerTexture(v32); /*0x4d050a*/
              sub_4CA340(shader, (int)InnerTexture); /*0x4d0512*/
              sub_7B4900(shader, dword_B43104, (char)a3, a4[0]); /*0x4d0528*/
            }
          }
        }
        v4 = v32; /*0x4d0530*/
      }
      if ( v31 ) /*0x4d0539*/
        NiRenderer_EndScene(); /*0x4d053b*/
      *(_BYTE *)(ShadowSceneNode + 0x12C) = v33; /*0x4d0544*/
      *((_BYTE *)InitBSShaderAccumulator() + 0x21E3) = 1; /*0x4d054f*/
      ((void (__thiscall *)(NiDX9Renderer *, float *))dword_B43104->__vftable->super.SetClearColor4)(dword_B43104, v40); /*0x4d0566*/
      v41[0x98] = 3; /*0x4d056c*/
      BSCullingProcess::~BSCullingProcess((BSCullingProcess *)v41); /*0x4d0574*/
      v3 = v28; /*0x4d0579*/
      v5 = *(_DWORD *)a4; /*0x4d057d*/
      v2 = a3; /*0x4d0581*/
    }
  }
  if ( !v3 ) /*0x4d0587*/
  {
LABEL_54:
    nullsub_returnTrue_0arg(); /*0x4d0602*/
    *a1 = (int)v4; /*0x4d0615*/
    if ( v4 ) /*0x4d0617*/
      InterlockedIncrement((volatile LONG *)&v4->members); /*0x4d061d*/
    v26 = InterlockedDecrement; /*0x4d0625*/
    v41[0x98] = 2; /*0x4d0633*/
    if ( v2 ) /*0x4d063b*/
    {
      if ( !v26((volatile LONG *)&v2->members) ) /*0x4d0641*/
        (*(void (__thiscall **)(BSRenderedTexture *, int))v2->vtbl)(v2, 1); /*0x4d064f*/
    }
    v41[0x98] = 1; /*0x4d0653*/
    if ( v5 ) /*0x4d065b*/
      goto LABEL_60; /*0x4d065b*/
    goto LABEL_62; /*0x4d065b*/
  }
  sub_7C1EE0(g_textureManager, v4); /*0x4d0590*/
  sub_7C1EE0(g_textureManager, v2); /*0x4d059c*/
  nullsub_returnTrue_0arg(); /*0x4d05a3*/
  *a1 = v5; /*0x4d05b4*/
  if ( v5 ) /*0x4d05b6*/
    InterlockedIncrement((volatile LONG *)(v5 + 4)); /*0x4d05bc*/
  v26 = InterlockedDecrement; /*0x4d05c4*/
  v41[0x98] = 2; /*0x4d05d2*/
  if ( v2 ) /*0x4d05da*/
  {
    if ( !v26((volatile LONG *)&v2->members) ) /*0x4d05e0*/
      (*(void (__thiscall **)(BSRenderedTexture *, int))v2->vtbl)(v2, 1); /*0x4d05ee*/
  }
  v41[0x98] = 1; /*0x4d05f2*/
  if ( v5 ) /*0x4d05fa*/
  {
LABEL_60:
    if ( !v26((volatile LONG *)(v5 + 4)) ) /*0x4d0661*/
      (**(void (__thiscall ***)(int, int))v5)(v5, 1); /*0x4d0670*/
  }
LABEL_62:
  v41[0x98] = 0; /*0x4d0672*/
  if ( v4 ) /*0x4d067c*/
  {
    if ( !v26((volatile LONG *)&v4->members) ) /*0x4d0682*/
      (*(void (__thiscall **)(BSRenderedTexture *, int))v4->vtbl)(v4, 1); /*0x4d0690*/
  }
  return a1; /*0x4d0699*/
}
