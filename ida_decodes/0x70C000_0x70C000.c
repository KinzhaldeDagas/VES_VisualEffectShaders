// 0x70C000 @ 0x70C000
// MoonSugarEffect decode: after culling, calls accumulator prepare with camera, renders visible geo list, then flushes accumulator. Confirms sub_70C0B0 is camera->cull->submit boundary.
void __cdecl sub_70C000(NiCamera *a1, _DWORD *a2)
{
  volatile LONG *accumulator; // esi

  if ( g_Renderer ) /*0x70c023*/
  {
    if ( a1 ) /*0x70c032*/
    {
      accumulator = (volatile LONG *)g_Renderer->member.super.accumulator; /*0x70c034*/
      if ( accumulator ) /*0x70c03d*/
      {
        InterlockedIncrement(accumulator + 1); /*0x70c043*/
        (*(void (__thiscall **)(volatile LONG *, NiCamera *))(*accumulator + 0x4C))(accumulator, a1); /*0x70c05d*/
      }
      sub_70BF30(a2); /*0x70c064*/
      if ( accumulator ) /*0x70c06e*/
      {
        (*(void (__thiscall **)(volatile LONG *))(*accumulator + 0x50))(accumulator); /*0x70c077*/
        if ( !InterlockedDecrement(accumulator + 1) ) /*0x70c089*/
          (**(void (__thiscall ***)(volatile LONG *, int))accumulator)(accumulator, 1); /*0x70c09b*/
      }
    }
  }
}
