// 0x70AB40 @ 0x70AB40
// MoonSugarEffect decode: NiNode::OnVisible recurses visible children when world bound radius is nonzero; geometry children eventually reach NiCullingProcess::OnVisible.
void __thiscall NiNode::OnVisible(NiNode *this, NiCullingProcess *a2)
{
  unsigned int i; // esi
  NiAVObject *v4; // ecx

  if ( 0.0 != this->members.super.m_kWorldBound.Radius ) /*0x70ab4d*/
  {
    for ( i = 0; i < this->members.children.end; ++i ) /*0x70ab52*/
    {
      v4 = *((NiAVObject **)&this->members.children.data->vtbl + i); /*0x70ab66*/
      if ( v4 ) /*0x70ab6b*/
        NiAVObject_Render(v4, a2); /*0x70ab6e*/
    }
  }
}
