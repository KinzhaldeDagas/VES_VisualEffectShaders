// 0x76C910 @ 0x76C910
// MoonSugarEffect decode: NiD3DTextureStage texture setter with refcounting; used by image-space shaders to bind BSRenderedTexture::GetInnerTexture(source) into the pass texture stage.
void __thiscall sub_76C910(_DWORD *this, NiRenderedTexture *a2)
{
  NiRenderedTexture *v3; // esi

  v3 = (NiRenderedTexture *)*(this + 1); /*0x76c914*/
  if ( v3 != a2 ) /*0x76c91e*/
  {
    if ( v3 ) /*0x76c922*/
    {
      if ( !InterlockedDecrement((volatile LONG *)&v3->member) ) /*0x76c928*/
        v3->__vftable->super.super.super.Destructor((NiRefObject *)v3, 1); /*0x76c93e*/
    }
    *(this + 1) = a2; /*0x76c942*/
    if ( a2 ) /*0x76c945*/
      InterlockedIncrement((volatile LONG *)&a2->member); /*0x76c94b*/
  }
}
