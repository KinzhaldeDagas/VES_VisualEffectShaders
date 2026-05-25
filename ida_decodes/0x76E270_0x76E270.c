// 0x76E270 @ 0x76E270
NiD3DShaderDeclaration *__thiscall NiD3DShaderDeclaration::NiD3DShaderDeclaration(NiD3DShaderDeclaration *this)
{
  NiObject_constr((NiObject *)this); /*0x76e273*/
  this->member.Renderer = 0; /*0x76e27a*/
  this->member.BufferManager = 0; /*0x76e27d*/
  this->member.Device = 0; /*0x76e280*/
  this->member.Unk014 = 0; /*0x76e283*/
  this->member.Unk018 = 0; /*0x76e286*/
  this->member.Unk01C = 0; /*0x76e289*/
  this->member.StreamCount = 0; /*0x76e28c*/
  this->member.Unk024 = 0; /*0x76e28f*/
  LOBYTE(this->member.Unk028) = 0; /*0x76e292*/
  this->__vftable = (#9279 *)&NiD3DShaderDeclaration::`vftable'; /*0x76e295*/
  return this; /*0x76e29d*/
}
