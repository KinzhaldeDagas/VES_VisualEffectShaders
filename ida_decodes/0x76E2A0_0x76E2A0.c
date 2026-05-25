// 0x76E2A0 @ 0x76E2A0
void __thiscall NiD3DShaderDeclaration::~NiD3DShaderDeclaration(NiD3DShaderDeclaration *this)
{
  bool v2; // zf
  UInt32 v3; // edi
  int v4; // ebx
  UInt32 v5; // eax
  IDirect3DDevice9 *Device; // eax

  v2 = this->member.Unk024 == 0; /*0x76e2a3*/
  this->__vftable = (#9279 *)&NiD3DShaderDeclaration::`vftable'; /*0x76e2a7*/
  if ( !v2 ) /*0x76e2ad*/
  {
    v3 = 0; /*0x76e2b0*/
    if ( this->member.StreamCount ) /*0x76e2b2*/
    {
      v4 = 0; /*0x76e2b8*/
      do /*0x76e2dc*/
      {
        v5 = v4 + this->member.Unk024; /*0x76e2c3*/
        if ( v5 ) /*0x76e2c5*/
          FormHeapFree(*(_DWORD *)(v5 + 8)); /*0x76e2cb*/
        ++v3; /*0x76e2d3*/
        v4 += 0x10; /*0x76e2d6*/
      }
      while ( v3 < this->member.StreamCount ); /*0x76e2dc*/
    }
    FormHeapFree(this->member.Unk024); /*0x76e2e3*/
  }
  Device = this->member.Device; /*0x76e2ec*/
  this->member.Unk024 = 0; /*0x76e2ef*/
  this->member.Renderer = 0; /*0x76e2f6*/
  Device->lpVtbl->Release(Device); /*0x76e303*/
  this->member.Device = 0; /*0x76e305*/
  NiRefObject_destr(this); /*0x76e30f*/
}
