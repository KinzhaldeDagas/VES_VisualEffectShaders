// 0x70C0B0 @ 0x70C0B0
// MoonSugarEffect decode: all observed native xrefs pass visibleGeo=0. Nonzero visible-array route exists in code but is not used by normal decoded world/offscreen callers.
void __cdecl sub_70C0B0(NiCamera *a1, SceneGraph *a2, NiCullingProcess *a3, _DWORD *a4)
{
  _DWORD *VisibleGeo; // esi

  if ( g_Renderer ) /*0x70c0b0*/
  {
    if ( a1 ) /*0x70c0c1*/
    {
      if ( a2 ) /*0x70c0ca*/
      {
        VisibleGeo = a4; /*0x70c0cd*/
        if ( !a4 ) /*0x70c0d8*/
          VisibleGeo = a3->VisibleGeo; /*0x70c0da*/
        SetCameraViewProj(g_Renderer, a1);      // MoonSugarEffect decode: SetCameraViewProj call inside sub_70C0B0. Useful render-only hook, but culling has not been swayed unless camera object was already temporarily changed. /*0x70c0de*/
        if ( VisibleGeo ) /*0x70c0e7*/
        {
          VisibleGeo[1] = 0; /*0x70c0ea*/
          ((void (__thiscall *)(NiCullingProcess *, NiCamera *, SceneGraph *, _DWORD *))a3->vtbl->Process)( /*0x70c0f8*/
            a3,
            a1,
            a2,
            VisibleGeo);
          sub_70C000(a1, VisibleGeo); /*0x70c0fc*/
        }
        else
        {
          ((void (__thiscall *)(NiCullingProcess *, NiCamera *, SceneGraph *, _DWORD))a3->vtbl->Process)(a3, a1, a2, 0); /*0x70c112*/
        }
      }
    }
  }
}
