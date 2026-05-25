// 0x007EF6B0 @ 0x007EF6B0
int __thiscall sub_7EF6B0(void *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  NiD3DPass *v9; // edi
  NiD3DTextureStage *v10; // ebx
  bool v11; // zf
  int v12; // esi
  NiD3DTextureStage *Stage; // eax
  int v14; // eax
  NiD3DPass *v16; // [esp+14h] [ebp-14h] BYREF
  NiD3DTextureStage *v17; // [esp+18h] [ebp-10h]
  unsigned int v18; // [esp+24h] [ebp-4h]
  bool v19; // [esp+38h] [ebp+10h]

  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 0x80))(this); /*0x7ef6e2*/
  v9 = 0; /*0x7ef6e4*/
  v10 = 0; /*0x7ef6e6*/
  v16 = 0; /*0x7ef6e8*/
  v18 = 0; /*0x7ef6ec*/
  v17 = 0; /*0x7ef6f0*/
  v11 = dword_B42E90 == 0x19B; /*0x7ef6f4*/
  LOBYTE(v18) = 1; /*0x7ef6fe*/
  if ( v11 ) /*0x7ef703*/
  {
    if ( dword_B46704 ) /*0x7ef709*/
    {
      v16 = (NiD3DPass *)dword_B46704; /*0x7ef71a*/
      v9 = v16; /*0x7ef716*/
      ++v16->RefCount; /*0x7ef72d*/
      v12 = *(_DWORD *)(a5 + 0x18); /*0x7ef730*/
      Stage = (NiD3DTextureStage *)v9->Stages.data->Stage; /*0x7ef73c*/
      v19 = *(_DWORD *)(v12 + 0xA8) == 1; /*0x7ef73e*/
      if ( Stage ) /*0x7ef745*/
      {
        ++Stage[7].Unk08; /*0x7ef747*/
        v10 = Stage; /*0x7ef74a*/
        v17 = Stage; /*0x7ef74c*/
      }
      sub_76C910(v10, *(NiRenderedTexture **)(v12 + 0x9C)); /*0x7ef759*/
      v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 0x68))(v12); /*0x7ef765*/
      sub_8011E0((int)v10, v14); /*0x7ef769*/
      if ( v19 ) /*0x7ef776*/
      {
        if ( *(_DWORD *)(v12 + 0xA4) == 1 ) /*0x7ef77f*/
          sub_7AECB0(v9, (NiD3DVertexShader *)dword_B466E8); /*0x7ef789*/
        else
          sub_7AECB0(v9, (NiD3DVertexShader *)dword_B466EC); /*0x7ef7a0*/
        sub_7AEC60(&v9->__vftable, (NiD3DPixelShader *)dword_B4670C); /*0x7ef795*/
      }
      else
      {
        if ( *(_DWORD *)(v12 + 0xA4) == 1 ) /*0x7ef7b7*/
          sub_7AECB0(v9, (NiD3DVertexShader *)dword_B466E0[0]); /*0x7ef7c4*/
        else
          sub_7AECB0(v9, (NiD3DVertexShader *)dword_B466E4); /*0x7ef862*/
        sub_7AEC60(&v9->__vftable, (NiD3DPixelShader *)dword_B46708[0]); /*0x7ef7d2*/
      }
      *((float *)this + 0x28) = flt_B2DAEC; /*0x7ef7e3*/
      sub_7EF980(v12, (_DWORD *)this + 0x1F, (_DWORD *)this + 0x22, (_DWORD *)this + 0x25, (float *)this + 0x2A); /*0x7ef7fe*/
      sub_76CE40((NiTArray_NiD3DPass *)this + 4, *((NiD3DPass **)this + 0xE), &v16); /*0x7ef80f*/
      ++*((_DWORD *)this + 0xE); /*0x7ef814*/
    }
  }
  LOBYTE(v18) = 0; /*0x7ef81d*/
  if ( v10 ) /*0x7ef822*/
  {
    v11 = v10[7].Unk08-- == 1; /*0x7ef824*/
    if ( v11 ) /*0x7ef827*/
      sub_772560(v10); /*0x7ef82b*/
  }
  v18 = 0xFFFFFFFF; /*0x7ef832*/
  if ( v9 ) /*0x7ef836*/
  {
    v11 = v9->RefCount-- == 1; /*0x7ef838*/
    if ( v11 ) /*0x7ef83b*/
      sub_7604D0(v9); /*0x7ef83f*/
  }
  return 0; /*0x7ef846*/
}
