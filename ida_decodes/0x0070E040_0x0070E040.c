// 0x0070E040 @ 0x0070E040
// MoonSugarEffect decode: NiCullingProcess::SetFrustum copies the camera frustum and rebuilds culling planes from Camera->worldTransform. This confirms a scoped temporary NiCamera transform affects culling, not only rendering.
void __thiscall NiCullingProcess::SetFrustum(NiCullingProcess *this, NiFrustum *a2)
{
  NiCamera *Camera; // edx

  Camera = this->Camera; /*0x70e043*/
  if ( Camera ) /*0x70e048*/
  {
    qmemcpy(&this->CameraFrustum, a2, sizeof(this->CameraFrustum)); /*0x70e05e*/
    sub_717A40(&this->Planes, &this->CameraFrustum, &Camera->members.super.m_worldTransform); /*0x70e064*/
    this->Planes.ActivePlanes = 0x3F; /*0x70e06a*/
  }
}
