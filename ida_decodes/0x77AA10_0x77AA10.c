// 0x77AA10 @ 0x77AA10
void __thiscall NiD3DShader_RemoveShaderPasses_(NiD3DShader *this)
{
  NiD3DPass *v2; // edi
  NiD3DPass *CurrentPass; // ecx
  NiD3DPass *v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0; /*0x77aa18*/
  if ( this->member.PassCount ) /*0x77aa1a*/
  {
    v5 = 0; /*0x77aa20*/
    do /*0x77aa3a*/
    {
      sub_76CE40(&this->member.Passes, v2, &v5); /*0x77aa2f*/
      v2 = (NiD3DPass *)((char *)v2 + 1); /*0x77aa34*/
    }
    while ( (unsigned int)v2 < this->member.PassCount ); /*0x77aa3a*/
  }
  CurrentPass = this->member.CurrentPass; /*0x77aa3d*/
  if ( CurrentPass ) /*0x77aa42*/
  {
    if ( CurrentPass->RefCount-- == 1 ) /*0x77aa44*/
      sub_7604D0(CurrentPass); /*0x77aa4a*/
    this->member.CurrentPass = 0; /*0x77aa4f*/
  }
  this->member.PassCount = 0; /*0x77aa53*/
  this->member.CurrentPassIndex = 0; /*0x77aa56*/
}
