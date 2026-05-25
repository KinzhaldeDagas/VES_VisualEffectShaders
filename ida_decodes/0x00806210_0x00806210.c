// 0x00806210 @ 0x00806210
ShaderDefinition *GeometryDecalShader()
{
  ShaderDefinition *v0; // eax
  ShaderDefinition *v1; // edi
  NiDX9ShaderDeclaration *DX9ShaderDeclaration; // eax
  LONG (__stdcall *v3)(volatile LONG *); // ebp
  int v4; // esi
  int v5; // eax
  void (__thiscall ***v6)(_DWORD, int); // ebx
  NiDX9ShaderDeclaration *ShaderDeclaration; // esi
  NiDX9ShaderDeclaration *v8; // ebx
  NiDX9ShaderDeclaration *v9; // esi
  int v10; // eax
  void (__thiscall ***v11)(_DWORD, int); // ebx
  int i; // eax
  GeometryDecalShader *v13; // eax
  GeometryDecalShader *v14; // esi
  BSShader *shader; // ebx

  v0 = (ShaderDefinition *)FormHeapAlloc(8u); /*0x806237*/
  if ( v0 ) /*0x80624d*/
    v1 = ShaderDefinition::Init(v0); /*0x806256*/
  else
    v1 = 0; /*0x80625a*/
  DX9ShaderDeclaration = CreateDX9ShaderDeclaration(dword_B43104, 2, 1u); /*0x80626e*/
  v3 = InterlockedDecrement; /*0x806273*/
  v4 = (int)DX9ShaderDeclaration; /*0x806279*/
  v5 = dword_B47604; /*0x80627b*/
  if ( dword_B47604 != v4 ) /*0x806285*/
  {
    if ( v5 ) /*0x806289*/
    {
      v6 = (void (__thiscall ***)(_DWORD, int))dword_B47604; /*0x80628b*/
      if ( !v3((volatile LONG *)(v5 + 4)) ) /*0x806291*/
      {
        if ( v6 ) /*0x806299*/
          (**v6)(v6, 1); /*0x8062a3*/
      }
    }
    v5 = v4; /*0x8062a7*/
    dword_B47604 = v4; /*0x8062a9*/
    if ( v4 ) /*0x8062ae*/
    {
      InterlockedIncrement((volatile LONG *)(v4 + 4)); /*0x8062b4*/
      v5 = dword_B47604; /*0x8062ba*/
    }
  }
  ShaderDeclaration = v1->ShaderDeclaration; /*0x8062bf*/
  v8 = (NiDX9ShaderDeclaration *)v5; /*0x8062c3*/
  if ( v1->ShaderDeclaration != (NiDX9ShaderDeclaration *)v5 ) /*0x8062c5*/
  {
    if ( ShaderDeclaration ) /*0x8062c9*/
    {
      if ( !v3((volatile LONG *)&ShaderDeclaration->members) ) /*0x8062cf*/
        (*(void (__thiscall **)(NiDX9ShaderDeclaration *, int))ShaderDeclaration->__vftable)(ShaderDeclaration, 1); /*0x8062e1*/
    }
    v1->ShaderDeclaration = v8; /*0x8062e5*/
    if ( v8 ) /*0x8062e7*/
      InterlockedIncrement((volatile LONG *)&v8->members); /*0x8062ed*/
  }
  v9 = CreateDX9ShaderDeclaration(dword_B43104, 4, 1u); /*0x806303*/
  v10 = dword_B47608; /*0x806305*/
  if ( (NiDX9ShaderDeclaration *)dword_B47608 != v9 ) /*0x80630f*/
  {
    if ( v10 ) /*0x806313*/
    {
      v11 = (void (__thiscall ***)(_DWORD, int))dword_B47608; /*0x806315*/
      if ( !v3((volatile LONG *)(v10 + 4)) ) /*0x80631b*/
      {
        if ( v11 ) /*0x806323*/
          (**v11)(v11, 1); /*0x80632d*/
      }
    }
    dword_B47608 = (int)v9; /*0x806331*/
    if ( v9 ) /*0x806337*/
      InterlockedIncrement((volatile LONG *)&v9->members); /*0x80633d*/
  }
  (*((void (__thiscall **)(NiDX9ShaderDeclaration *, _DWORD, _DWORD, _DWORD, int, _DWORD))v1->ShaderDeclaration->__vftable /*0x806354*/
   + 0x14))(
    v1->ShaderDeclaration,
    0,
    0,
    0,
    2,
    0);
  (*((void (__thiscall **)(NiDX9ShaderDeclaration *, int, int, int, int, _DWORD))v1->ShaderDeclaration->__vftable + 0x14))( /*0x806367*/
    v1->ShaderDeclaration,
    1,
    3,
    3,
    2,
    0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)dword_B47608 + 0x50))( /*0x80637e*/
    dword_B47608,
    0,
    0,
    0,
    2,
    0);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)dword_B47608 + 0x50))( /*0x806395*/
    dword_B47608,
    1,
    1,
    1,
    3,
    0);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)dword_B47608 + 0x50))( /*0x8063ac*/
    dword_B47608,
    2,
    2,
    2,
    4,
    0);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)dword_B47608 + 0x50))( /*0x8063c3*/
    dword_B47608,
    3,
    3,
    3,
    2,
    0);
  if ( v1->ShaderDeclaration ) /*0x8063c5*/
  {
    for ( i = (*((int (__thiscall **)(NiDX9ShaderDeclaration *))v1->ShaderDeclaration->__vftable + 1))(v1->ShaderDeclaration); /*0x8063d4*/
          i;
          i = *(_DWORD *)(i + 4) )
    {
      if ( (char *)i == dword_B3F684 ) /*0x8063db*/
        break; /*0x8063db*/
    }
  }
  v13 = (GeometryDecalShader *)FormHeapAlloc(0xA0u); /*0x8063e9*/
  if ( v13 ) /*0x8063ff*/
    v14 = GeometryDecalShader::GeometryDecalShader(v13); /*0x806408*/
  else
    v14 = 0; /*0x80640c*/
  (*(void (__thiscall **)(GeometryDecalShader *))(*(_DWORD *)v14 + 0x84))(v14); /*0x806420*/
  sub_805320((volatile LONG **)v14); /*0x806424*/
  sub_805670(v14); /*0x80642b*/
  (*(void (__thiscall **)(GeometryDecalShader *))(*(_DWORD *)v14 + 0x88))(v14); /*0x80643a*/
  (*(void (__thiscall **)(GeometryDecalShader *, NiDX9ShaderDeclaration *))(*(_DWORD *)v14 + 0x54))( /*0x806446*/
    v14,
    v1->ShaderDeclaration);
  shader = v1->shader; /*0x806448*/
  if ( shader != (BSShader *)v14 ) /*0x80644d*/
  {
    if ( shader ) /*0x806451*/
    {
      if ( !v3((volatile LONG *)&shader->member) ) /*0x806457*/
        shader->__vftable->super.super.super.super.Destructor((NiRefObject *)shader, 1); /*0x806469*/
    }
    v1->shader = (BSShader *)v14; /*0x80646b*/
    InterlockedIncrement((volatile LONG *)v14 + 1); /*0x806472*/
  }
  return v1; /*0x80647a*/
}
