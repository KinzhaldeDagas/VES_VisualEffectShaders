// 0x7073D0 @ 0x7073D0
int __thiscall NiAVObject_Render(NiAVObject *this, NiCullingProcess *a2)
{
  int result; // eax

  if ( (this->members.m_flags & 1) == 0 ) /*0x7073d4*/
    return a2->vtbl->ProcessCull(a2, this); /*0x7073e5*/
  return result; /*0x7073e7*/
}
