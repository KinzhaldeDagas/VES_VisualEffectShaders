// 0x7227A0 @ 0x7227A0
// MoonSugarEffect decode: NiGeometry::OnVisible forwards the visible geometry to NiCullingProcess::OnVisible.
const void *__thiscall NiGeometry::OnVisible(NiGeometry *this, NiCullingProcess *a2)
{
  return NiCullingProcess::OnVisible(a2, this); /*0x7227aa*/
}
