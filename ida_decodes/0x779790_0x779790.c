// 0x779790 @ 0x779790
// MoonSugarEffect decode: NiD3DShader vtable +0x40 cleanup after a pass; restores the shader render-state group.
int __thiscall sub_779790(NiD3DShader *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  NiD3DRenderStateGroup *RenderStateGroup; // ecx

  RenderStateGroup = this->member.RenderStateGroup; /*0x779790*/
  if ( RenderStateGroup ) /*0x779795*/
    NiD3DRenderStateGroup::RestoreRenderState(RenderStateGroup); /*0x779797*/
  return 0; /*0x77979e*/
}
