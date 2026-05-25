// 0x77A0F0 @ 0x77A0F0
// MoonSugarEffect decode: NiD3DShader vtable +0x4C pass-loop advance. Ends current pass, advances/refcounts CurrentPass, returns remaining pass count.
UInt32 __thiscall sub_77A0F0(NiD3DShader *this)
{
  NiD3DPass *CurrentPass; // ecx
  UInt32 v3; // eax
  NiD3DPass **v5; // edi
  NiD3DPass *v6; // ecx
  bool v7; // zf
  NiD3DPass *v8; // eax

  CurrentPass = this->member.CurrentPass; /*0x77a0f3*/
  if ( CurrentPass ) /*0x77a0f8*/
    CurrentPass->__vftable->sub_75F9E0(CurrentPass, this->member.CurrentPassIndex); /*0x77a103*/
  v3 = ++this->member.CurrentPassIndex; /*0x77a109*/
  if ( v3 == this->member.PassCount ) /*0x77a10f*/
    return 0; /*0x77a111*/
  v5 = (NiD3DPass **)(&this->member.Passes.data->__vftable + v3); /*0x77a119*/
  v6 = this->member.CurrentPass; /*0x77a11c*/
  if ( v6 != *v5 ) /*0x77a121*/
  {
    if ( v6 ) /*0x77a125*/
    {
      v7 = v6->RefCount-- == 1; /*0x77a127*/
      if ( v7 ) /*0x77a12b*/
        sub_7604D0(v6); /*0x77a12d*/
    }
    v8 = *v5; /*0x77a132*/
    v7 = *v5 == 0; /*0x77a134*/
    this->member.CurrentPass = *v5; /*0x77a136*/
    if ( !v7 ) /*0x77a139*/
      ++v8->RefCount; /*0x77a13b*/
  }
  return this->member.PassCount - this->member.CurrentPassIndex; /*0x77a113*/
}
