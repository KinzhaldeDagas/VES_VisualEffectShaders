// 0x717690 @ 0x717690
// MoonSugarEffect decode: NiGeometry/NiScreenElements render entry. Calls NiGeometry::Render to set renderer states, then active-scene path calls NiDX9Renderer vtable +0x160, which resolves to RenderTriGeometries, not the final DrawPrimitive shortcut.
int __thiscall sub_717690(NiGeometry *this, NiDX9Renderer *a2)
{
  int result; // eax

  NiGeometry::Render(this, a2); /*0x717699*/
  result = 1; /*0x71769e*/
  if ( (a2->member.super.SceneState1 == 1 || a2->member.super.SceneState2 == 1) && a2->member.super.IsReady == 1 ) /*0x7176b9*/
    return ((int (__thiscall *)(NiDX9Renderer *, NiGeometry *))a2->__vftable->super.RenderTriShape)(a2, this); /*0x7176c6*/
  return result; /*0x7176c8*/
}
