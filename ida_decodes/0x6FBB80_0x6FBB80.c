// 0x6FBB80 @ 0x6FBB80
// MoonSugarEffect decode: BSCullingProcess ProcessCull override. If +0x90/unk90 is nonzero, uses normal frustum culling; if zero, bypasses cull tests and calls object OnVisible directly.
void __thiscall BSCullingProcess_Culling(BSCullingProcess *this, NiAVObject *a2)
{
  if ( this->unk90 ) /*0x6fbb80*/
    NiCullingProcess_Culling_(this, a2); /*0x6fbb89*/
  else
    a2->vtbl->OnVisible(a2, &this->super); /*0x6fbb9d*/
}
