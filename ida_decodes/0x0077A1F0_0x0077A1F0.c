// 0x0077A1F0 @ 0x0077A1F0
// MoonSugarEffect decode: shader SetupShaderPrograms (shader-interface vtable +0x38). Calls current pass setup, applies shader-level constant maps, then sets shader declaration on pass 0. Offsets: NiD3DShader +0x24 declaration, +0x2C pixel map, +0x30 vertex map, +0x34 current pass index, +0x38 pass count, +0x3C current pass, +0x44 pass array.
NiObjectNET *__thiscall SetupShaderPrograms(
        NiD3DShader *this,
        NiObjectNET *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  NiExtraData *ExtraData; // eax
  int v12; // eax
  NiD3DShaderConstantMap *PixelConstantMap; // ecx
  NiD3DShaderConstantMap *VertexConstantMap; // ecx
  NiD3DShaderDeclaration *ShaderDeclaration; // ecx
  NiDX9RenderStateVtbl *vtbl; // edi
  int v17; // eax
  NiObjectNET *v19; // [esp+84h] [ebp+4h]

  if ( a2 ) /*0x77a1fe*/
  {
    ExtraData = NiObjectNET_GetExtraData(a2, off_B29F84); /*0x77a208*/
    if ( ExtraData ) /*0x77a20f*/
    {
      ExtraData[1].member.m_pcName = 0; /*0x77a211*/
      ExtraData[2].__vftable = 0; /*0x77a214*/
    }
  }
  v12 = ((int (__thiscall *)(NiD3DPass *, NiObjectNET *, int, int, int, int, int, int, int, UInt32))this->member.CurrentPass->__vftable->sub_75FBA0)( /*0x77a247*/
          this->member.CurrentPass,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          this->member.CurrentPassIndex);
  PixelConstantMap = this->member.PixelConstantMap; /*0x77a249*/
  v19 = (NiObjectNET *)v12; /*0x77a24e*/
  if ( PixelConstantMap ) /*0x77a252*/
  {
    if ( this->member.CurrentPass->PixelShader ) /*0x77a257*/
      ((void (__thiscall *)(NiD3DShaderConstantMap *, NiD3DPixelShader *, NiObjectNET *, int, int, int, int, int, int, int, UInt32, int))PixelConstantMap->_vtbl->sub_9A8E30)( /*0x77a28e*/
        PixelConstantMap,
        this->member.CurrentPass->PixelShader,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        this->member.CurrentPassIndex,
        1);
  }
  VertexConstantMap = this->member.VertexConstantMap; /*0x77a290*/
  if ( VertexConstantMap ) /*0x77a295*/
  {
    if ( this->member.CurrentPass->VertexShader ) /*0x77a29a*/
      ((void (__thiscall *)(NiD3DShaderConstantMap *, NiD3DVertexShader *, NiObjectNET *, int, int, int, int, int, int, int, UInt32, int))VertexConstantMap->_vtbl->sub_9A8E30)( /*0x77a2d1*/
        VertexConstantMap,
        this->member.CurrentPass->VertexShader,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        this->member.CurrentPassIndex,
        1);
  }
  if ( !this->member.CurrentPassIndex ) /*0x77a2d3*/
  {
    ShaderDeclaration = this->member.ShaderDeclaration; /*0x77a2d9*/
    if ( ShaderDeclaration ) /*0x77a2de*/
    {
      vtbl = this->member.super.D3DRenderState->vtbl; /*0x77a2e5*/
      v17 = (*((int (__thiscall **)(NiD3DShaderDeclaration *, _DWORD))ShaderDeclaration->__vftable + 0x1D))( /*0x77a2ec*/
              ShaderDeclaration,
              0);
      ((void (__thiscall *)(NiDX9RenderState *, int))vtbl->SetVertexDeclaration)(this->member.super.D3DRenderState, v17); /*0x77a2f8*/
    }
  }
  return v19; /*0x77a2fe*/
}
