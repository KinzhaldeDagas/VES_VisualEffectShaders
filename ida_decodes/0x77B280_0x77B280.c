// 0x77B280 @ 0x77B280
// MoonSugarEffect decode: NiDX9RenderState SetTexture cache. Caches texture per sampler at +0xFA0 and only calls D3D SetTexture on change.
HRESULT __thiscall SetTexture(NiDX9RenderState *this, DWORD sampler, IDirect3DBaseTexture9 *a3)
{
  HRESULT result; // eax

  result = (HRESULT)sampler; /*0x77b280*/
  if ( (IDirect3DBaseTexture9 *)this->member.unk0FA0[sampler] != a3 ) /*0x77b28f*/
  {
    this->member.unk0FA0[sampler] = (UInt32)a3; /*0x77b292*/
    return this->member.Device->lpVtbl->SetTexture(this->member.Device, sampler, a3); /*0x77b2aa*/
  }
  return result; /*0x77b2ad*/
}
