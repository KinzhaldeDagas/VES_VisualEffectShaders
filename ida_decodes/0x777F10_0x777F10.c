// 0x777F10 @ 0x777F10
// MoonSugarEffect decode: BuffData live-stream predicate. Returns true only when StreamCount is nonzero and every VBChip entry has a non-null D3D vertex buffer.
char __thiscall sub_777F10(NiGeometryBufferData *this)
{
  UInt32 StreamCount; // esi
  int v3; // edx
  NiVBChip **i; // eax

  StreamCount = this->StreamCount; /*0x777f11*/
  if ( StreamCount ) /*0x777f16*/
  {
    v3 = 0; /*0x777f1c*/
    for ( i = this->VBChip; *i && (*i)->VB; ++i ) /*0x777f22*/
    {
      if ( ++v3 >= StreamCount ) /*0x777f3a*/
        return 1; /*0x777f3c*/
    }
  }
  return 0; /*0x777f1a*/
}
