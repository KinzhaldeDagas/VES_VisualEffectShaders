// 0x007AC9A0 @ 0x007AC9A0
// MoonSugarEffect decode: BSShaderAccumulator flush for one shader/pass bucket. Normalizes some IDs, refreshes native shader constants, sorts the bucket, then emits RenderPass nodes through sub_7A9820 or native special list dispatch.
void __thiscall sub_7AC9A0(int **this, unsigned int a2, int a3)
{
  unsigned int v3; // edi
  BSShader *shader; // ebp
  int **v5; // ebx
  BSShader *v6; // esi
  NiD3DShaderConstantMap *PixelConstantMap; // ecx
  int *v8; // eax
  int *v9; // esi
  _DWORD *v10; // eax
  bool v11; // zf
  void *v12; // ecx
  int *v13; // ebp
  _DWORD *v14; // eax
  int **v15; // esi
  BSShader *v17; // [esp+14h] [ebp-8h]
  BSShader *v18; // [esp+18h] [ebp-4h]
  _DWORD *v19; // [esp+24h] [ebp+8h]

  v3 = a2; /*0x7ac9ae*/
  if ( byte_B42CE8 ) /*0x7ac9a3*/
  {
    if ( a2 == 0x49 ) /*0x7ac9be*/
    {
      v3 = 0x48; /*0x7ac9c0*/
    }
    else if ( a2 == 0x16F ) /*0x7ac9cd*/
    {
      v3 = 0x16E; /*0x7ac9cf*/
    }
  }
  shader = GetShaderDefinition(1u)->shader; /*0x7ac9db*/
  v5 = this + 5 * (unsigned __int16)a2; /*0x7ac9ef*/
  if ( !v5[0x45] ) /*0x7ac9fc*/
    return; /*0x7ac9fc*/
  v6 = *(BSShader **)(*(_DWORD *)v5[0x42][2] + 0xBC); /*0x7aca0d*/
  v17 = 0; /*0x7aca17*/
  v18 = 0; /*0x7aca1b*/
  if ( v6 ) /*0x7aca1f*/
  {
    if ( ((int (__thiscall *)(BSShader *))v6->__vftable->super.super.super.No1C)(v6) < 1 /*0x7aca3f*/
      || ((int (__thiscall *)(BSShader *))v6->__vftable->super.super.super.No1C)(v6) > 5 )
    {
      if ( ((int (__thiscall *)(BSShader *))v6->__vftable->super.super.super.No1C)(v6) == 0x1B ) /*0x7aca86*/
      {
        v18 = v6; /*0x7aca8e*/
        sub_7FD260(v3); /*0x7aca92*/
        v6->member.super.VertexConstantMap->_vtbl->sub_9A97B0(v6->member.super.VertexConstantMap); /*0x7acaa2*/
        PixelConstantMap = v6->member.super.PixelConstantMap; /*0x7acaa4*/
        goto LABEL_14; /*0x7acaa4*/
      }
    }
    else
    {
      v17 = v6; /*0x7aca47*/
      sub_7D1320((int *)v3); /*0x7aca4b*/
      v6->member.super.VertexConstantMap->_vtbl->sub_9A97B0(v6->member.super.VertexConstantMap); /*0x7aca5b*/
      v6->member.super.PixelConstantMap->_vtbl->sub_9A97B0(v6->member.super.PixelConstantMap); /*0x7aca65*/
      if ( v6 != shader ) /*0x7aca69*/
      {
        shader->member.super.VertexConstantMap->_vtbl->sub_9A97B0(shader->member.super.VertexConstantMap); /*0x7aca73*/
        PixelConstantMap = shader->member.super.PixelConstantMap; /*0x7aca75*/
LABEL_14:
        PixelConstantMap->_vtbl->sub_9A97B0(PixelConstantMap); /*0x7acaa7*/
      }
    }
  }
  if ( byte_B2BB7C ) /*0x7acaae*/
  {
    if ( v3 == 0x48 || v3 == 0x49 || v3 >= 0x168 && v3 <= 0x175 ) /*0x7acadb*/
    {
      sub_7AA550(this + 5 * (unsigned __int16)a2 + 0x41, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7acd2f*/
      sub_7F6FC0(*(this + 0x899), this + 5 * (unsigned __int16)a2 + 0x41, v3); /*0x7acd3c*/
      return; /*0x7acd48*/
    }
    if ( v3 == 0xC || v3 == 0xD || v3 >= 0x195 && v3 <= 0x197 ) /*0x7acb01*/
    {
      sub_7AA550(this + 5 * (unsigned __int16)a2 + 0x41, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7accfd*/
      sub_7F7680(*(this + 0x899), this + 5 * (unsigned __int16)a2 + 0x41, v3); /*0x7acd0a*/
      return; /*0x7acd16*/
    }
    switch ( v3 ) /*0x7acc39*/
    {
      case 0x54u: /*0x7acc39*/
      case 0x5Fu: /*0x7acc39*/
      case 0x6Au: /*0x7acc39*/
      case 0x75u: /*0x7acc39*/
      case 0x82u: /*0x7acc39*/
      case 0x90u: /*0x7acc39*/
      case 0x9Du: /*0x7acc39*/
      case 0xAAu: /*0x7acc39*/
      case 0xB8u: /*0x7acc39*/
      case 0xC5u: /*0x7acc39*/
      case 0xD2u: /*0x7acc39*/
      case 0xDFu: /*0x7acc39*/
      case 0xEEu: /*0x7acc39*/
      case 0xF5u: /*0x7acc39*/
      case 0xFCu: /*0x7acc39*/
      case 0x103u: /*0x7acc39*/
      case 0x10Bu: /*0x7acc39*/
      case 0x11Bu: /*0x7acc39*/
      case 0x122u: /*0x7acc39*/
      case 0x129u: /*0x7acc39*/
      case 0x194u: /*0x7acc39*/
      case 0x18u: /*0x7acc39*/
      case 0x2Fu: /*0x7acc39*/
      case 0x30u: /*0x7acc39*/
      case 0x33u: /*0x7acc39*/
      case 0xE7u: /*0x7acc39*/
      case 0x113u: /*0x7acc39*/
      case 0x114u: /*0x7acc39*/
        sub_7AA550(this + 5 * (unsigned __int16)a2 + 0x41, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7acccb*/
        sub_7F7EE0(*(this + 0x899), this + 5 * (unsigned __int16)a2 + 0x41, v3); /*0x7accd8*/
        return; /*0x7acce4*/
      case 0xEu: /*0x7acc39*/
        sub_7AA550(this + 5 * (unsigned __int16)a2 + 0x41, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7acc56*/
        sub_7F86C0(*(this + 0x899), this + 5 * (unsigned __int16)a2 + 0x41, 0xE); /*0x7acc64*/
        return; /*0x7acc70*/
      case 0x17Bu: /*0x7acc39*/
        sub_7AA550(this + 5 * (unsigned __int16)a2 + 0x41, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7acc95*/
        sub_7F8DB0(*(this + 0x899), this + 5 * (unsigned __int16)a2 + 0x41, 0x17B); /*0x7acca6*/
        return; /*0x7accb2*/
    }
  }
  v8 = v5[0x42]; /*0x7acd52*/
  v9 = (int *)v8[2]; /*0x7acd58*/
  v19 = (_DWORD *)*v8; /*0x7acd60*/
  if ( OcclusionCullngBool && (v10 = *(this + 0x87C)) != 0 ) /*0x7acd72*/
  {
    while ( 1 ) /*0x7acd76*/
    {
      v11 = *v9 == v10[2]; /*0x7acd76*/
      v12 = v10 + 2; /*0x7acd79*/
      v10 = (_DWORD *)*v10; /*0x7acd7e*/
      if ( v11 ) /*0x7acd80*/
        break; /*0x7acd80*/
      if ( !v10 ) /*0x7acd84*/
        goto LABEL_65; /*0x7acd84*/
    }
  }
  else
  {
LABEL_65:
    if ( (v3 < 0x160 || v3 > 0x162) && v3 - 0x156 > 2 ) /*0x7acda5*/
    {
      if ( *((_BYTE *)this + 0x21E2) ) /*0x7acdbd*/
      {
        if ( v17 || v18 ) /*0x7acdd2*/
          sub_7ABDE0(this + 0x885, v9); /*0x7acddb*/
      }
      sub_7A9820(v9, v3); /*0x7acde4*/
    }
    else
    {
      sub_7ABDE0(this + 0x880, v9); /*0x7acdb2*/
    }
    ++dword_B42CBC; /*0x7acde9*/
    v12 = (void *)(*(unsigned __int16 (__thiscall **)(_DWORD))(**(_DWORD **)(*v9 + 0xB4) + 0x5C))(*(_DWORD *)(*v9 + 0xB4)); /*0x7ace02*/
    dword_B42CB4 += (int)v12; /*0x7ace05*/
  }
  if ( v17 ) /*0x7ace10*/
  {
    sub_7D1800(v3); /*0x7ace13*/
  }
  else if ( v18 ) /*0x7ace1f*/
  {
    TESTexture::ClearComponentReferences(v12); /*0x7ace22*/
  }
  while ( v19 ) /*0x7ace33*/
  {
    v13 = (int *)v19[2]; /*0x7ace4d*/
    v19 = (_DWORD *)*v19; /*0x7ace53*/
    if ( OcclusionCullngBool && (v14 = *(this + 0x87C)) != 0 ) /*0x7ace61*/
    {
      while ( 1 ) /*0x7ace66*/
      {
        v11 = *v13 == v14[2]; /*0x7ace66*/
        v14 = (_DWORD *)*v14; /*0x7ace6e*/
        if ( v11 ) /*0x7ace70*/
          break; /*0x7ace70*/
        if ( !v14 ) /*0x7ace74*/
          goto LABEL_86; /*0x7ace74*/
      }
    }
    else
    {
LABEL_86:
      if ( (v3 < 0x160 || v3 > 0x162) && v3 - 0x156 > 2 ) /*0x7ace95*/
      {
        if ( *((_BYTE *)this + 0x21E2) ) /*0x7acea5*/
        {
          if ( v17 || v18 ) /*0x7aceba*/
            sub_7ABDE0(this + 0x885, v13); /*0x7acec3*/
        }
        sub_7A9820(v13, v3); /*0x7acecc*/
      }
      else
      {
        sub_7ABDE0(this + 0x880, v13); /*0x7ace9e*/
      }
      ++dword_B42CBC; /*0x7aced1*/
      dword_B42CB4 += (*(unsigned __int16 (__thiscall **)(_DWORD))(**(_DWORD **)(*v13 + 0xB4) + 0x5C))(*(_DWORD *)(*v13 + 0xB4)); /*0x7aceee*/
    }
  }
  if ( !byte_B42CDA ) /*0x7aceff*/
  {
    v15 = this + 5 * (unsigned __int16)a2 + 0x41; /*0x7acf10*/
    sub_7A9C30((int)v15); /*0x7acf15*/
    v15[3] = v15[1]; /*0x7acf1d*/
    v15[1] = 0; /*0x7acf22*/
    v15[2] = 0; /*0x7acf25*/
    v15[4] = 0; /*0x7acf28*/
  }
}
