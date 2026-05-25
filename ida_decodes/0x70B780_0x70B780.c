// 0x70B780 @ 0x70B780
NiNode *__thiscall NiNode::NiNode(NiNode *this, unsigned __int16 a2)
{
  NiAVObject::NiAVObject((NiAVObject *)this); /*0x70b7a9*/
  this->vtbl = (NiNodeVtbl *)&NiNode::`vftable'; /*0x70b7c1*/
  sub_4B2D30(&this->members.children, a2, 1); /*0x70b7c7*/
  this->members.effects.numItems = 0; /*0x70b7cc*/
  this->members.effects.head = 0; /*0x70b7d2*/
  this->members.effects.end = 0; /*0x70b7d8*/
  this->members.effects.vtlb = &NiTPointerList<NiDynamicEffect *>::`vftable'; /*0x70b7de*/
  return this; /*0x70b7ea*/
}
