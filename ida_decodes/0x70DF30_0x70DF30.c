// 0x70DF30 @ 0x70DF30
// MoonSugarEffect decode: NiCullingProcess ctor; +4 UseAppendVirtual, +8 VisibleGeo pointer, +0C Camera. SceneGraph passes null, so normal world culling does not start with a reusable visible array.
NiCullingProcess *__thiscall NiCullingProcess_NiCullingProcess(NiCullingProcess *this, void *a2)
{
  NiFrustumPlanes *p_Planes; // edi
  int i; // ebp

  this->vtbl = (NiCullingProcessVtbl *)&NiCullingProcess::`vftable'; /*0x70df4c*/
  this->UseAppendVirtual = 0; /*0x70df56*/
  NiFrustum::InitFrustum(&this->CameraFrustum, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0); /*0x70df61*/
  p_Planes = &this->Planes; /*0x70df69*/
  for ( i = 5; i >= 0; --i ) /*0x70df6b*/
  {
    sub_716DB0(p_Planes); /*0x70df72*/
    p_Planes = (NiFrustumPlanes *)((char *)p_Planes + 0x10); /*0x70df77*/
  }
  this->Planes.ActivePlanes = 0x3F; /*0x70df83*/
  this->VisibleGeo = a2; /*0x70df8b*/
  this->Camera = 0; /*0x70df8e*/
  return this; /*0x70df8a*/
}
