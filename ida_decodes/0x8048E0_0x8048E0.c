// 0x8048E0 @ 0x8048E0
// MoonSugarEffect decode: CopyShader/image-space begin pass. Clones pass texture stage, binds BSImageSpaceShader +0x7C inner rendered texture as stage texture for mode 0/3/4, then falls through to common shader setup.
int __thiscall sub_8048E0(int this, int a2, int a3, int a4, int a5, int a6, int a7, char a8)
{
  int v9; // eax
  int v10; // ebp
  int v11; // eax
  int v13; // eax
  NiRenderedTexture *v14; // eax
  int v15; // ecx
  int v16; // eax
  double v17; // st7
  int v18; // eax
  double v19; // st7
  float *v20; // eax
  double v21; // st6
  int v22; // eax
  NiRenderedTexture *v23; // eax
  int v24; // ecx
  int v25; // eax
  double v26; // st7
  int v27; // ecx
  float *v28; // eax
  double v29; // st7
  double v30; // st6
  NiRenderedTexture *InnerTexture; // [esp-4h] [ebp-34h]
  _DWORD *v32; // [esp+14h] [ebp-1Ch] BYREF
  int v33; // [esp+18h] [ebp-18h]
  int v34; // [esp+1Ch] [ebp-14h]
  int v35; // [esp+20h] [ebp-10h]
  int v36; // [esp+2Ch] [ebp-4h]

  (*(void (__thiscall **)(int))(*(_DWORD *)this + 0x80))(this); /*0x804911*/
  v34 = 0; /*0x804917*/
  v36 = 0; /*0x80491b*/
  v32 = 0; /*0x80491f*/
  v9 = *(_DWORD *)(this + 0x70); /*0x804923*/
  LOBYTE(v36) = 1; /*0x804928*/
  if ( !v9 ) /*0x80492d*/
    JUMPOUT(0x804BD9); /*0x804bd9*/
  v10 = v9; /*0x804933*/
  ++*(_DWORD *)(v9 + 0x60); /*0x804935*/
  v11 = *(_DWORD *)(this + 0xA4); /*0x804939*/
  v34 = v10; /*0x804942*/
  switch ( v11 ) /*0x80494c*/
  {
    case 0: /*0x80494c*/
      sub_7AEC20((NiD3DTextureStage **)&v32, **(NiD3DTextureStage ***)(v10 + 0x24)); /*0x80495d*/
      InnerTexture = BSRenderedTexture::GetInnerTexture(*(BSRenderedTexture **)(this + 0x7C)); /*0x80496a*/
      sub_76C910(v32, InnerTexture); /*0x80496f*/
      goto LABEL_4; /*0x80496f*/
    case 1: /*0x80494c*/
      sub_7AEC20((NiD3DTextureStage **)&v32, **(NiD3DTextureStage ***)(v10 + 0x24)); /*0x80498e*/
      sub_76C910(v32, (NiRenderedTexture *)dword_B474F0); /*0x80499a*/
LABEL_4:
      sub_76C730((_DWORD *)v10, 0x1B, 0, 0); /*0x804974*/
      break; /*0x80497a*/
    case 2: /*0x80494c*/
      sub_7AEC20((NiD3DTextureStage **)&v32, **(NiD3DTextureStage ***)(v10 + 0x24)); /*0x8049a6*/
      sub_76C910(v32, (NiRenderedTexture *)dword_B474EC); /*0x8049b6*/
      sub_76C730((_DWORD *)v10, 0x1B, 1, 0); /*0x8049c2*/
      sub_76C730((_DWORD *)v10, 0x13, 9, 0); /*0x8049ce*/
      sub_76C730((_DWORD *)v10, 0x14, 1, 0); /*0x8049da*/
      break; /*0x8049df*/
    case 3: /*0x80494c*/
      sub_76C730((_DWORD *)v10, 0x1B, 0, 0); /*0x8049ea*/
      v13 = (unsigned __int16)word_B474C8 - 1; /*0x8049f6*/
      if ( v13 > 6 ) /*0x8049fc*/
      {
        v33 = 6; /*0x804a0d*/
      }
      else if ( v13 >= 0 ) /*0x804a00*/
      {
        v33 = (unsigned __int16)word_B474C8 - 1; /*0x804a17*/
      }
      else
      {
        v33 = 0; /*0x804a02*/
      }
      sub_7AEC20((NiD3DTextureStage **)&v32, **(NiD3DTextureStage ***)(v10 + 0x24)); /*0x804a25*/
      v14 = BSRenderedTexture::GetInnerTexture(*(BSRenderedTexture **)(this + 0x7C)); /*0x804a2d*/
      sub_76C910(v32, v14); /*0x804a37*/
      v15 = *(_DWORD *)(*(_DWORD *)(this + 0x7C) + 0x20); /*0x804a3f*/
      if ( v15 ) /*0x804a44*/
        v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 0x4C))(v15); /*0x804a4b*/
      else
        v16 = 0; /*0x804a4f*/
      v35 = v16; /*0x804a53*/
      v17 = (double)v16; /*0x804a57*/
      if ( v16 < 0 ) /*0x804a5b*/
        v17 = v17 + flt_A2FC78; /*0x804a5d*/
      v18 = v33; /*0x804a6b*/
      qmemcpy(&unk_B474F8, (char *)&unk_A93780 + 0xF0 * v33, 0xF0u); /*0x804a85*/
      flt_B2E03C = 1.0 / v17; /*0x804a87*/
      flt_B2E040 = 0.0; /*0x804a8f*/
      v19 = *(float *)(4 * v18 + 0xA93760); /*0x804a95*/
      v20 = (float *)&unk_B47510; /*0x804a9c*/
      do /*0x804ad1*/
      {
        v21 = v20[0xFFFFFFFC]; /*0x804aa1*/
        v20 += 0x14; /*0x804aa4*/
        v20[0xFFFFFFE8] = v21 / v19; /*0x804aae*/
        v20[0xFFFFFFEC] = v20[0xFFFFFFEC] / v19; /*0x804ab6*/
        v20[0xFFFFFFF0] = v20[0xFFFFFFF0] / v19; /*0x804abe*/
        v20[0xFFFFFFF4] = v20[0xFFFFFFF4] / v19; /*0x804ac6*/
        v20[0xFFFFFFF8] = v20[0xFFFFFFF8] / v19; /*0x804ace*/
      }
      while ( (int)v20 < (int)&flt_B47600 ); /*0x804ad1*/
      break; /*0x804ad1*/
    case 4: /*0x80494c*/
      sub_76C730((_DWORD *)v10, 0x1B, 0, 0); /*0x804ade*/
      v22 = (unsigned __int16)word_B474C8 - 1; /*0x804aea*/
      if ( v22 > 6 ) /*0x804af0*/
      {
        v33 = 6; /*0x804b01*/
      }
      else if ( v22 >= 0 ) /*0x804af4*/
      {
        v33 = (unsigned __int16)word_B474C8 - 1; /*0x804b0b*/
      }
      else
      {
        v33 = 0; /*0x804af6*/
      }
      sub_7AEC20((NiD3DTextureStage **)&v32, **(NiD3DTextureStage ***)(v10 + 0x24)); /*0x804b19*/
      v23 = BSRenderedTexture::GetInnerTexture(*(BSRenderedTexture **)(this + 0x7C)); /*0x804b21*/
      sub_76C910(v32, v23); /*0x804b2b*/
      flt_B2E03C = 0.0; /*0x804b32*/
      v24 = *(_DWORD *)(*(_DWORD *)(this + 0x7C) + 0x20); /*0x804b3b*/
      if ( v24 ) /*0x804b40*/
        v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v24 + 0x4C))(v24); /*0x804b47*/
      else
        v25 = 0; /*0x804b4b*/
      v35 = v25; /*0x804b4f*/
      v26 = (double)v25; /*0x804b53*/
      if ( v25 < 0 ) /*0x804b57*/
        v26 = v26 + flt_A2FC78; /*0x804b59*/
      qmemcpy(&unk_B474F8, (char *)&unk_A93780 + 0xF0 * v33, 0xF0u); /*0x804b7d*/
      v27 = v33; /*0x804b7f*/
      v28 = (float *)&unk_B47510; /*0x804b83*/
      flt_B2E040 = 1.0 / v26; /*0x804b88*/
      v29 = *(float *)(4 * v27 + 0xA93760); /*0x804b8e*/
      do /*0x804bc5*/
      {
        v30 = v28[0xFFFFFFFC]; /*0x804b95*/
        v28 += 0x14; /*0x804b98*/
        v28[0xFFFFFFE8] = v30 / v29; /*0x804ba2*/
        v28[0xFFFFFFEC] = v28[0xFFFFFFEC] / v29; /*0x804baa*/
        v28[0xFFFFFFF0] = v28[0xFFFFFFF0] / v29; /*0x804bb2*/
        v28[0xFFFFFFF4] = v28[0xFFFFFFF4] / v29; /*0x804bba*/
        v28[0xFFFFFFF8] = v28[0xFFFFFFF8] / v29; /*0x804bc2*/
      }
      while ( (int)v28 < (int)&flt_B47600 ); /*0x804bc5*/
      break; /*0x804bc5*/
    default:
      JUMPOUT(0x804BC9); /*0x804bc9*/
  }
  return def_80494C(this, (NiD3DPass *)v10, a2, a3, a4, a5, a6, a7, a8);
}
