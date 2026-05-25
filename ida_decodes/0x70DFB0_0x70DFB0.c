// 0x70DFB0 @ 0x70DFB0
// MoonSugarEffect decode: base NiCullingProcess frustum test path. Preserves/restores ActivePlanes, calls object OnVisible only when bounds pass active planes.
void __thiscall NiCullingProcess_Culling_(BSCullingProcess *this, NiAVObject *a2)
{
  unsigned int v3; // edi
  NiFrustumPlanes *p_Planes; // ebx
  signed int v5; // eax
  UInt32 ActivePlanes; // [esp+4h] [ebp-4h]

  ActivePlanes = this->super.Planes.ActivePlanes; /*0x70dfbc*/
  if ( ActivePlanes ) /*0x70dfc0*/
  {
    v3 = 0; /*0x70dfd6*/
    p_Planes = &this->super.Planes; /*0x70dfd8*/
    do /*0x70e019*/
    {
      if ( ((1 << v3) & this->super.Planes.ActivePlanes) != 0 ) /*0x70dfef*/
      {
        v5 = sub_47DA70(&a2->members.m_kWorldBound, p_Planes); /*0x70dff9*/
        if ( v5 == 2 ) /*0x70e001*/
          break; /*0x70e001*/
        if ( v5 == 1 ) /*0x70e006*/
          this->super.Planes.ActivePlanes &= ~(1 << v3); /*0x70e00a*/
      }
      ++v3; /*0x70e010*/
      p_Planes = (NiFrustumPlanes *)((char *)p_Planes + 0x10); /*0x70e013*/
    }
    while ( v3 < 6 ); /*0x70e019*/
    if ( v3 == 6 ) /*0x70e021*/
      a2->vtbl->OnVisible(a2, &this->super); /*0x70e02d*/
    this->super.Planes.ActivePlanes = ActivePlanes; /*0x70e033*/
  }
  else
  {
    a2->vtbl->OnVisible(a2, &this->super); /*0x70dfcc*/
  }
}
