// 0x0077C550 @ 0x0077C550
void __thiscall sub_77C550(unsigned int **this)
{
  unsigned int *v2; // ecx
  NiD3DShaderInterface *v3; // esi
  NiD3DShaderInterface *v4; // [esp+4h] [ebp-Ch] BYREF
  NiTMap_Entry_TESCELL *v5; // [esp+8h] [ebp-8h] BYREF
  void *v6; // [esp+Ch] [ebp-4h] BYREF

  if ( *(this + 5) ) /*0x77c556*/
  {
    v2 = *(this + 6); /*0x77c55c*/
    if ( v2 ) /*0x77c561*/
    {
      v4 = 0; /*0x77c563*/
      v5 = (NiTMap_Entry_TESCELL *)sub_6A9030(v2); /*0x77c572*/
      while ( v5 ) /*0x77c576*/
      {
        sub_452600((NiTMap_TESCELL *)*(this + 6), &v5, &v6, (TESObjectCELL **)&v4); /*0x77c592*/
        v3 = v4; /*0x77c597*/
        if ( v4 ) /*0x77c59d*/
        {
          if ( !v4->__vftable->IsRenderSet(v4) ) /*0x77c5a6*/
          {
            NiD3DShaderInterface::SetDX9Renderer(v3, (NiDX9Renderer *)*(this + 5)); /*0x77c5b2*/
            v3->__vftable->Unk64(v3); /*0x77c5be*/
            sub_769B10(*(this + 5), (int)v3); /*0x77c5c4*/
          }
        }
      }
    }
  }
}
