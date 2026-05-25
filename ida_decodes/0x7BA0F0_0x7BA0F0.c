// 0x7BA0F0 @ 0x7BA0F0
// MoonSugarEffect decode: shader system init prewarms shader definitions 1..27, then constructs imageSpaceShaderList if ImageSpaceEffectEnabled.
void __cdecl sub_7BA0F0()
{
  _DWORD *v0; // eax
  BSTextureManager *v1; // eax
  int *v2; // esi
  int v3; // eax
  int *v4; // eax
  unsigned int v5; // esi
  BSShaderAccumulator *inited; // eax
  BSShaderAccumulator *v7; // esi
  volatile LONG *v8; // edi
  bool v9; // zf
  int v10; // edx
  signed int i; // esi
  unsigned int v12; // esi
  NiTPointerList__BSImageSpaceShader *v13; // eax
  NiTPointerList__BSImageSpaceShader *v14; // eax

  if ( !byte_B42F31 ) /*0x7ba115*/
  {
    v0 = (_DWORD *)FormHeapAlloc(0x48u); /*0x7ba124*/
    if ( v0 ) /*0x7ba13a*/
      v1 = (BSTextureManager *)BSTextureManager_Create(v0); /*0x7ba13e*/
    else
      v1 = 0; /*0x7ba145*/
    g_textureManager = v1; /*0x7ba150*/
    v2 = (int *)FormHeapAlloc(0x1Cu); /*0x7ba15a*/
    if ( v2 ) /*0x7ba16d*/
    {
      v3 = sub_7DAB80(); /*0x7ba16f*/
      v4 = sub_7DB050(v2, v3); /*0x7ba177*/
    }
    else
    {
      v4 = 0; /*0x7ba17e*/
    }
    dword_B430B8 = (int)v4; /*0x7ba180*/
    sub_7DACA0(v4, *v4); /*0x7ba18e*/
    if ( !*(_DWORD *)(dword_B430B8 + 4) ) /*0x7ba199*/
    {
      v5 = dword_B430B8; /*0x7ba19f*/
      sub_7DB010((_DWORD *)dword_B430B8); /*0x7ba1a1*/
      FormHeapFree(v5); /*0x7ba1a7*/
      dword_B430B8 = 0; /*0x7ba1af*/
    }
    inited = InitBSShaderAccumulator(); /*0x7ba1b9*/
    v7 = dword_B430FC; /*0x7ba1be*/
    v8 = (volatile LONG *)inited; /*0x7ba1c4*/
    if ( dword_B430FC != inited ) /*0x7ba1c8*/
    {
      if ( v7 ) /*0x7ba1cc*/
      {
        if ( !InterlockedDecrement((volatile LONG *)v7 + 1) ) /*0x7ba1d2*/
          (**(void (__thiscall ***)(BSShaderAccumulator *, int))v7)(v7, 1); /*0x7ba1e8*/
      }
      dword_B430FC = (BSShaderAccumulator *)v8; /*0x7ba1ec*/
      if ( v8 ) /*0x7ba1f2*/
        InterlockedIncrement(v8 + 1); /*0x7ba1f8*/
    }
    sub_7AB1D0(1); /*0x7ba200*/
    sub_7B8990(); /*0x7ba208*/
    v9 = dword_B43104 == 0; /*0x7ba213*/
    *(float *)&v10 = flt_A3D65C; /*0x7ba230*/
    *(float *)&dword_B4616C = flt_A3D65C; /*0x7ba238*/
    dword_B46170 = v10; /*0x7ba241*/
    dword_B46174 = v10; /*0x7ba247*/
    *(float *)&dword_B46178 = 1.0; /*0x7ba24d*/
    if ( !v9 ) /*0x7ba252*/
    {
      for ( i = 1; i < 0x1C; ++i ) /*0x7ba254*/
        GetShaderDefinition(i); /*0x7ba261*/
      if ( dword_B430B8 ) /*0x7ba271*/
      {
        v12 = dword_B430B8; /*0x7ba27b*/
        sub_7DB010((_DWORD *)dword_B430B8); /*0x7ba27d*/
        FormHeapFree(v12); /*0x7ba283*/
        dword_B430B8 = 0; /*0x7ba28b*/
      }
      if ( dword_B43104 ) /*0x7ba295*/
      {
        if ( ImageSpaceEffectEnabled ) /*0x7ba29e*/
        {
          v13 = (NiTPointerList__BSImageSpaceShader *)FormHeapAlloc(0x1Cu); /*0x7ba2a9*/
          if ( v13 ) /*0x7ba2bf*/
            v14 = ImageSpaceshaderList::Create(v13); /*0x7ba2c3*/
          else
            v14 = 0; /*0x7ba2ca*/
          imageSpaceShaderList = v14; /*0x7ba2cc*/
        }
      }
    }
    byte_B42F31 = 1; /*0x7ba2d1*/
  }
}
