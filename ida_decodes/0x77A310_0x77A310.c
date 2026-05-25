// 0x77A310 @ 0x77A310
// MoonSugarEffect decode: NiD3DShader vtable +0x3C geometry buffer binding. Packs skinned/non-skinned geometry when needed, then SetStreamSource for each BuffData stream and SetIndices(BuffData->IB).
NiGeometryBufferData *__thiscall sub_77A310(NiD3DShader *this, int a2, int a5, NiGeometryBufferData *a4, int _1C)
{
  NiTriShapeData *v6; // eax
  _DWORD *v7; // edx
  NiGeometryBufferData *BuffData; // edi
  UInt32 StreamCount; // eax
  UINT i; // esi
  NiVBChip *v11; // ecx

  if ( a2 && (!this->member.CurrentPassIndex || (*(_WORD *)(*(_DWORD *)(a2 + 0xB4) + 0x2E) & 0xF000) == 0x8000 && a5) ) /*0x77a33d*/
  {
    v6 = *(NiTriShapeData **)(a2 + 0xB4); /*0x77a341*/
    v7 = *(_DWORD **)(a2 + 0xB8); /*0x77a347*/
    if ( a5 ) /*0x77a34f*/
    {
      BuffData = *(NiGeometryBufferData **)(a5 + 0x28); /*0x77a354*/
      NiDX9Renderer::PackSkinnedGeometryBuffer( /*0x77a35f*/
        this->member.super.D3DRenderer,
        (int)BuffData,
        (int)v6,
        (int)v7,
        a5,
        this->member.ShaderDeclaration,
        0);
    }
    else
    {
      BuffData = v6->member.super.super.BuffData; /*0x77a369*/
      NiDX9Renderer::PackGeometryBuffers( /*0x77a373*/
        this->member.super.D3DRenderer,
        BuffData,
        v6,
        v7,
        this->member.ShaderDeclaration,
        0);
    }
  }
  else
  {
    BuffData = a4; /*0x77a37a*/
  }
  if ( BuffData ) /*0x77a380*/
  {
    StreamCount = BuffData->StreamCount; /*0x77a382*/
    for ( i = 0; i < StreamCount; ++i ) /*0x77a389*/
    {
      if ( i >= StreamCount ) /*0x77a39c*/
        v11 = 0; /*0x77a3a6*/
      else
        v11 = BuffData->VBChip[i]; /*0x77a3a1*/
      this->member.super.D3DDevice->lpVtbl->SetStreamSource( /*0x77a3bc*/
        this->member.super.D3DDevice,
        i,
        v11->VB,
        0,
        BuffData->VertexStride[i]);
      StreamCount = BuffData->StreamCount; /*0x77a3be*/
    }
    this->member.super.D3DDevice->lpVtbl->SetIndices(this->member.super.D3DDevice, BuffData->IB); /*0x77a3d9*/
  }
  return BuffData; /*0x77a3dd*/
}
