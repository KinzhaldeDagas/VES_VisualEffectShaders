// 0x70E1A0 @ 0x70E1A0
// MoonSugarEffect decode: NiCullingProcess::OnVisible. With VisibleGeo, appends NiGeometry into array {data,count,capacity,grow}; without VisibleGeo, queues to active accumulator vtable +0x58 or directly renders as fallback.
const void *__thiscall NiCullingProcess::OnVisible(NiCullingProcess *this, NiGeometry *a2)
{
  const void **VisibleGeo; // esi
  const void *result; // eax
  const void *v4; // eax
  NiAccumulator *accumulator; // ecx

  VisibleGeo = (const void **)this->VisibleGeo; /*0x70e1a1*/
  if ( VisibleGeo ) /*0x70e1a6*/
  {
    if ( this->UseAppendVirtual ) /*0x70e1a8*/
    {
      return (const void *)this->vtbl->AppendVirtual(this, a2); /*0x70e1b4*/
    }
    else
    {
      v4 = VisibleGeo[2]; /*0x70e1b6*/
      if ( VisibleGeo[1] == v4 ) /*0x70e1bc*/
        sub_732200(VisibleGeo, (unsigned int)VisibleGeo[3] + (_DWORD)v4); /*0x70e1c6*/
      result = *VisibleGeo; /*0x70e1ce*/
      *((_DWORD *)*VisibleGeo + (_DWORD)VisibleGeo[1]) = a2; /*0x70e1d4*/
      VisibleGeo[1] = (char *)VisibleGeo[1] + 1; /*0x70e1d7*/
    }
  }
  else
  {
    accumulator = g_Renderer->member.super.accumulator; /*0x70e1e5*/
    if ( !accumulator ) /*0x70e1ee*/
      return ((const void *(__thiscall *)(NiGeometry *, NiDX9Renderer *))a2->__vftable->Render)(a2, g_Renderer); /*0x70e1ee*/
    result = (const void *)(*(int (__thiscall **)(NiAccumulator *, NiGeometry *))(*(_DWORD *)accumulator + 0x58))( /*0x70e1f6*/
                             accumulator,
                             a2);
    if ( !(_BYTE)result ) /*0x70e1fa*/
      return ((const void *(__thiscall *)(NiGeometry *, NiDX9Renderer *))a2->__vftable->Render)(a2, g_Renderer); /*0x70e20d*/
  }
  return result; /*0x70e1db*/
}
