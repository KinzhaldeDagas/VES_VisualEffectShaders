// 0x779710 @ 0x779710
// MoonSugarEffect decode: NiD3DShader vtable +0x34 world/skinning setup. Calculates bone matrices and vertex blending for skinned partitions, otherwise disables vertex blending and uploads model transform.
int __thiscall sub_779710(
        NiD3DShader *this,
        int _C,
        NiSkinInstance *a2,
        int a3,
        int a5,
        int a6,
        int a7,
        NiTransform *a4,
        int a9)
{
  if ( a3 ) /*0x77971a*/
  {
    if ( !this->member.CurrentPassIndex ) /*0x77971c*/
      NiDX9Renderer::CalculateBoneMatrixes(this->member.super.D3DRenderer, a2, a4, 0, 4, 0); /*0x779737*/
    ((void (__thiscall *)(NiDX9RenderState *, _DWORD))this->member.super.D3DRenderState->vtbl->SetVertexBlending)( /*0x779749*/
      this->member.super.D3DRenderState,
      *(unsigned __int16 *)(a3 + 0x24));
    sub_765560(this->member.super.D3DRenderer, (int)a2, a3, (int)a4); /*0x779751*/
    return 0; /*0x779759*/
  }
  else
  {
    if ( !this->member.CurrentPassIndex ) /*0x77975f*/
    {
      ((void (__thiscall *)(NiDX9RenderState *, _DWORD))this->member.super.D3DRenderState->vtbl->SetVertexBlending)( /*0x77976f*/
        this->member.super.D3DRenderState,
        0);
      sub_765480(this->member.super.D3DRenderer, (float *)a4, 1); /*0x77977b*/
    }
    return 0; /*0x779781*/
  }
}
