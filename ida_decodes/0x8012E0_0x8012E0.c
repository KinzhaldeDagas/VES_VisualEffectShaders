// 0x8012E0 @ 0x8012E0
void __thiscall BSShader::~BSShader(BSShader *this)
{
  NiD3DPass *Unk070; // ecx

  this->__vftable = (BSShaderVtbl *)&BSShader::`vftable'; /*0x801309*/
  Unk070 = (NiD3DPass *)this->member.Unk070; /*0x80130f*/
  if ( Unk070 ) /*0x80131f*/
  {
    if ( Unk070->RefCount-- == 1 ) /*0x801321*/
      sub_7604D0(Unk070); /*0x801327*/
    this->member.Unk070 = 0; /*0x80132c*/
  }
  sub_76B350(dword_B43104, (NiD3DShaderInterface *)this); /*0x801339*/
  _LN21(&this->member.Unk070, 4u, 1, (void (__thiscall *)(void *))sub_4027D0); /*0x80134d*/
  sub_76C760((NiD3DShader *)this); /*0x80135c*/
}
