// 0x77A0B0 @ 0x77A0B0
// MoonSugarEffect decode: NiD3DShader vtable +0x48 pass-loop begin. Selects pass 0, refcounts CurrentPass, and returns pass count.
UInt32 __thiscall sub_77A0B0(NiD3DShader *this)
{
  NiD3DPass *CurrentPass; // ecx
  NiD3DPass **data; // edi
  bool v4; // zf
  NiD3DPass *v5; // eax

  this->member.CurrentPassIndex = 0;            // MoonSugarEffect decode: pass-loop begin. Sets shader+0x34 CurrentPassIndex=0, then reads shader+0x44 Passes.data and stores Passes.data[0] into shader+0x3C CurrentPass with pass refcounting. /*0x77a0b3*/
  CurrentPass = this->member.CurrentPass; /*0x77a0ba*/
  data = (NiD3DPass **)this->member.Passes.data; /*0x77a0be*/
  if ( CurrentPass != *data ) /*0x77a0c3*/
  {
    if ( CurrentPass ) /*0x77a0c7*/
    {
      v4 = CurrentPass->RefCount-- == 1; /*0x77a0c9*/
      if ( v4 ) /*0x77a0cd*/
        sub_7604D0(CurrentPass); /*0x77a0cf*/
    }
    v5 = *data; /*0x77a0d4*/
    v4 = *data == 0; /*0x77a0d6*/
    this->member.CurrentPass = *data; /*0x77a0d8*/
    if ( !v4 ) /*0x77a0db*/
      ++v5->RefCount; /*0x77a0dd*/
  }
  return this->member.PassCount; /*0x77a0e4*/
}
