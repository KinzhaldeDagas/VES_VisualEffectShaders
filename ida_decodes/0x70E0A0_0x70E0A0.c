// 0x70E0A0 @ 0x70E0A0
// MoonSugarEffect decode: NiCullingProcess::Process sets camera/frustum. If VisibleGeo is null, it prepares the active accumulator (+0x4C), traverses NiAVObject_Render, then flushes accumulator (+0x50). If an explicit visible array is supplied, it temporarily installs it.
void __thiscall NiCullingProcess::Process(NiCullingProcess *this, NiCamera *a2, NiAVObject *a3, void *a4)
{
  NiCamera *v5; // ebx
  NiCamera *v6; // edi
  void *v7; // ebp
  NiFrustum *p_Frustum; // [esp-4h] [ebp-28h]
  void *VisibleGeo; // [esp+14h] [ebp-10h]

  v5 = a2; /*0x70e0c7*/
  v6 = 0; /*0x70e0cb*/
  if ( a2 ) /*0x70e0cf*/
  {
    if ( a3 ) /*0x70e0d9*/
    {
      p_Frustum = &a2->members.Frustum; /*0x70e0e5*/
      this->Camera = a2; /*0x70e0e6*/
      NiCullingProcess::SetFrustum(this, p_Frustum); /*0x70e0e9*/
      v7 = a4; /*0x70e0ee*/
      VisibleGeo = 0; /*0x70e0f4*/
      if ( a4 ) /*0x70e0f8*/
      {
        VisibleGeo = this->VisibleGeo; /*0x70e0fd*/
        this->VisibleGeo = a4; /*0x70e101*/
      }
      a2 = 0; /*0x70e104*/
      if ( !this->VisibleGeo ) /*0x70e108*/
      {
        NiSmartPointer_Set__((Ni2DBuffer **)&a2, (Ni2DBuffer *)g_Renderer->member.super.accumulator); /*0x70e124*/
        v6 = a2; /*0x70e129*/
        if ( a2 ) /*0x70e12f*/
          ((void (__thiscall *)(NiCamera *, NiCamera *))a2->vtbl->UpdateControllers)(a2, v5); /*0x70e139*/
      }
      NiAVObject_Render(a3, this); /*0x70e140*/
      if ( v6 ) /*0x70e147*/
        v6->vtbl->Unk_14((NiAVObject *)v6); /*0x70e150*/
      if ( v7 ) /*0x70e154*/
        this->VisibleGeo = VisibleGeo; /*0x70e15a*/
      this->Camera = 0; /*0x70e15f*/
      if ( v6 ) /*0x70e16e*/
      {
        if ( !InterlockedDecrement((volatile LONG *)&v6->members) ) /*0x70e174*/
          v6->vtbl->super.super.Destructor((NiRefObject *)v6, 1); /*0x70e186*/
      }
    }
  }
}
