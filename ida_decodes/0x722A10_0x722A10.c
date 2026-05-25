// 0x722A10 @ 0x722A10
// MoonSugarEffect decode: NiGeometry::Render copies geometry render-pass/property state (+0xAC) and dynamic-effect state (+0xB0) into the renderer, then ticks controllers. It does not choose a replacement shader.
NiDX9Renderer *__thiscall NiGeometry::Render(NiGeometry *this, NiDX9Renderer *a2)
{
  NiDX9Renderer *result; // eax
  NiInterpController *i; // esi

  result = a2; /*0x722a16*/
  a2->member.super.propertyState = this->member.unk0AC; /*0x722a1a*/
  a2->member.super.dynamicEffectState = this->member.unk0B0; /*0x722a24*/
  for ( i = this->member.super.super.m_controller; i; i = (NiInterpController *)i->member.next ) /*0x722a2c*/
    result = (NiDX9Renderer *)((int (__thiscall *)(NiInterpController *))i->vtbl->super.Unk_1A)(i); /*0x722a37*/
  return result; /*0x722a40*/
}
