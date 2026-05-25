// 0x7AB6F0 @ 0x7AB6F0
int __thiscall sub_7AB6F0(_DWORD *this)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // esi
  int v3; // edi
  int *v4; // eax
  int v5; // ecx
  bool v6; // zf
  _DWORD *v7; // esi
  int *v8; // eax
  int v9; // ecx
  _DWORD *v10; // esi
  _DWORD *v11; // ebp
  int *v12; // eax
  int v13; // ecx
  _DWORD *v14; // esi
  _DWORD *v15; // esi
  int result; // eax
  _DWORD *v17; // ebp
  _DWORD *v18; // esi
  unsigned int v19; // edi
  _DWORD *i; // esi
  _DWORD *v21; // eax

  v1 = this; /*0x7ab6f4*/
  v2 = this + 0x42; /*0x7ab6fb*/
  v3 = 0x1A3; /*0x7ab701*/
  do /*0x7ab723*/
  {
    sub_7A9C30((int)(v2 + 0xFFFFFFFF)); /*0x7ab70b*/
    v2[2] = *v2; /*0x7ab712*/
    *v2 = 0; /*0x7ab715*/
    v2[1] = 0; /*0x7ab717*/
    v2[3] = 0; /*0x7ab71a*/
    v2 += 5; /*0x7ab71d*/
    --v3; /*0x7ab720*/
  }
  while ( v3 ); /*0x7ab723*/
  while ( v1[0x12] ) /*0x7ab725*/
  {
    v4 = (int *)v1[0x10]; /*0x7ab730*/
    v5 = *v4; /*0x7ab733*/
    v6 = *v4 == 0; /*0x7ab735*/
    v1[0x10] = *v4; /*0x7ab737*/
    if ( v6 ) /*0x7ab73a*/
      v1[0x11] = 0; /*0x7ab741*/
    else
      *(_DWORD *)(v5 + 4) = 0; /*0x7ab73c*/
    v7 = (_DWORD *)v4[2]; /*0x7ab746*/
    (*(void (__thiscall **)(_DWORD *, int *))(v1[0xF] + 8))(v1 + 0xF, v4); /*0x7ab74f*/
    --v1[0x12]; /*0x7ab751*/
    if ( v7 ) /*0x7ab757*/
    {
      sub_7A9C30((int)v7); /*0x7ab75b*/
      v7[3] = v7[1]; /*0x7ab763*/
      v7[1] = 0; /*0x7ab766*/
      v7[2] = 0; /*0x7ab769*/
      v7[4] = 0; /*0x7ab76c*/
      *v7 = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7ab770*/
      FormHeapFree((unsigned int)v7); /*0x7ab776*/
    }
  }
  v1[0x17] = 0; /*0x7ab783*/
  v1[0x18] = 0; /*0x7ab786*/
  while ( v1[0x16] ) /*0x7ab789*/
  {
    v8 = (int *)v1[0x14]; /*0x7ab791*/
    v9 = *v8; /*0x7ab794*/
    v6 = *v8 == 0; /*0x7ab796*/
    v1[0x14] = *v8; /*0x7ab798*/
    if ( v6 ) /*0x7ab79b*/
      v1[0x15] = 0; /*0x7ab7a2*/
    else
      *(_DWORD *)(v9 + 4) = 0; /*0x7ab79d*/
    v10 = (_DWORD *)v8[2]; /*0x7ab7a7*/
    (*(void (__thiscall **)(_DWORD *, int *))(v1[0x13] + 8))(v1 + 0x13, v8); /*0x7ab7b0*/
    --v1[0x16]; /*0x7ab7b2*/
    if ( v10 ) /*0x7ab7b8*/
    {
      sub_7A9C30((int)v10); /*0x7ab7bc*/
      v10[3] = v10[1]; /*0x7ab7c4*/
      v10[1] = 0; /*0x7ab7c7*/
      v10[2] = 0; /*0x7ab7ca*/
      v10[4] = 0; /*0x7ab7cd*/
      *v10 = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7ab7d1*/
      FormHeapFree((unsigned int)v10); /*0x7ab7d7*/
    }
  }
  v1[0x1D] = 0; /*0x7ab7e4*/
  if ( v1[0x1C] ) /*0x7ab7e7*/
  {
    v11 = v1 + 0x19; /*0x7ab7ec*/
    do /*0x7ab862*/
    {
      v12 = (int *)v11[1]; /*0x7ab7f0*/
      v13 = *v12; /*0x7ab7f3*/
      v6 = *v12 == 0; /*0x7ab7f5*/
      v11[1] = *v12; /*0x7ab7f7*/
      if ( v6 ) /*0x7ab7fa*/
        v11[2] = 0; /*0x7ab801*/
      else
        *(_DWORD *)(v13 + 4) = 0; /*0x7ab7fc*/
      v14 = (_DWORD *)v12[2]; /*0x7ab807*/
      (*(void (__thiscall **)(_DWORD *, int *))(*v11 + 8))(v11, v12); /*0x7ab810*/
      --v11[3]; /*0x7ab812*/
      if ( v14 ) /*0x7ab818*/
      {
        sub_7A9C30((int)v14); /*0x7ab81c*/
        v14[3] = v14[1]; /*0x7ab824*/
        v14[1] = 0; /*0x7ab82c*/
        v14[2] = 0; /*0x7ab82f*/
        v14[4] = 0; /*0x7ab832*/
        sub_7A9C30((int)(v14 + 5)); /*0x7ab835*/
        v14[8] = v14[6]; /*0x7ab83d*/
        v14[6] = 0; /*0x7ab840*/
        v14[7] = 0; /*0x7ab843*/
        v14[9] = 0; /*0x7ab846*/
        v14[5] = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7ab84a*/
        *v14 = &BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *>::`vftable'; /*0x7ab850*/
        FormHeapFree((unsigned int)v14); /*0x7ab856*/
      }
    }
    while ( *(this + 0x1C) ); /*0x7ab862*/
    v1 = this; /*0x7ab867*/
  }
  v15 = (_DWORD *)v1[0x1E]; /*0x7ab869*/
  if ( v15 ) /*0x7ab86e*/
  {
    sub_7A9C30(v1[0x1E]); /*0x7ab872*/
    v15[3] = v15[1]; /*0x7ab87a*/
    v15[1] = 0; /*0x7ab87d*/
    v15[2] = 0; /*0x7ab880*/
    v15[4] = 0; /*0x7ab883*/
  }
  sub_7A9C30((int)(v1 + 0x24)); /*0x7ab88e*/
  v1[0x27] = v1[0x25]; /*0x7ab896*/
  v1[0x25] = 0; /*0x7ab899*/
  v1[0x26] = 0; /*0x7ab89c*/
  v1[0x28] = 0; /*0x7ab89f*/
  sub_7A9C30((int)(v1 + 0x1F)); /*0x7ab8a7*/
  result = v1[0x20]; /*0x7ab8ac*/
  v1[0x22] = result; /*0x7ab8af*/
  v1[0x20] = 0; /*0x7ab8b2*/
  v1[0x21] = 0; /*0x7ab8b5*/
  v1[0x23] = 0; /*0x7ab8b8*/
  if ( v1[0x877] ) /*0x7ab8bb*/
  {
    v17 = *(_DWORD **)(*(_DWORD *)(v1[0x875] + 8) + 4); /*0x7ab8cc*/
    if ( v17[4] ) /*0x7ab8cf*/
    {
      v18 = (_DWORD *)v17[1]; /*0x7ab8d4*/
      while ( v18 ) /*0x7ab8d9*/
      {
        v19 = v18[2]; /*0x7ab8e0*/
        v18 = (_DWORD *)*v18; /*0x7ab8e8*/
        if ( v19 ) /*0x7ab8ea*/
        {
          sub_7E2400(v19); /*0x7ab8ee*/
          FormHeapFree(v19); /*0x7ab8f4*/
        }
      }
      sub_7A9C30((int)v17); /*0x7ab902*/
      result = v17[1]; /*0x7ab907*/
      v17[3] = result; /*0x7ab90a*/
      v17[1] = 0; /*0x7ab90d*/
      v17[2] = 0; /*0x7ab910*/
      v17[4] = 0; /*0x7ab913*/
    }
    v1 = this; /*0x7ab916*/
  }
  for ( i = (_DWORD *)v1[0x871]; i; result = (*(int (__thiscall **)(_DWORD *, _DWORD *))(v1[0x870] + 8))( /*0x7ab928*/
                                               v1 + 0x870,
                                               v21) )
  {
    v21 = i; /*0x7ab932*/
    i = (_DWORD *)*i; /*0x7ab934*/
  }
  v1[0x873] = 0; /*0x7ab942*/
  v1[0x871] = 0; /*0x7ab945*/
  v1[0x872] = 0; /*0x7ab948*/
  byte_B42CDB = 0; /*0x7ab94e*/
  return result; /*0x7ab94b*/
}
