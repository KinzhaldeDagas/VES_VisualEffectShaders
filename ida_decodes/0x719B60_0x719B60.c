// 0x719B60 @ 0x719B60
int __thiscall sub_719B60(NiGeometry *this, NiDX9Renderer *a2)
{
  int result; // eax

  NiGeometry::Render(this, a2); /*0x719b69*/
  result = 1; /*0x719b6e*/
  if ( (a2->member.super.SceneState1 == 1 || a2->member.super.SceneState2 == 1) && a2->member.super.IsReady == 1 ) /*0x719b89*/
    return ((int (__thiscall *)(NiDX9Renderer *, NiGeometry *))a2->__vftable->super.RenderTriStrips)(a2, this); /*0x719b96*/
  return result; /*0x719b98*/
}
