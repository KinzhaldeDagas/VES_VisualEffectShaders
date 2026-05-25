// 0x71AC10 @ 0x71AC10
// MoonSugarEffect decode: BSShaderAccumulator visible-array consumer (+0x54). Iterates {data,count}; direct-renders disallowed/flagged geometry, otherwise appends geometry into accumulator group list for normal material-owned flush.
NiDX9Renderer *__thiscall sub_71AC10(_DWORD *this, _DWORD *a2)
{
  NiDX9Renderer *result; // eax
  unsigned int v4; // esi
  unsigned int v5; // ebp
  _BYTE *v6; // edi
  int v7; // eax
  NiDX9Renderer **v8; // ecx
  unsigned int i; // [esp+Ch] [ebp-8h]
  NiDX9Renderer *v10; // [esp+10h] [ebp-4h]

  result = g_Renderer; /*0x71ac13*/
  v4 = a2[1]; /*0x71ac21*/
  v5 = 0; /*0x71ac24*/
  v10 = g_Renderer; /*0x71ac28*/
  for ( i = v4; v5 < v4; ++v5 ) /*0x71ac30*/
  {
    v6 = *(_BYTE **)(*a2 + 4 * v5); /*0x71ac3d*/
    v7 = *(_DWORD *)(*((_DWORD *)v6 + 0x2B) + 8); /*0x71ac46*/
    if ( (*(_BYTE *)(v7 + 0x18) & 1) == 0 /*0x71ac6c*/
      || *((_BYTE *)this + 0x34) && (*(_WORD *)(v7 + 0x18) & 0x2000) != 0
      || (v6[0x18] & 0x40) != 0 )
    {
      result = (NiDX9Renderer *)(*(int (__thiscall **)(_BYTE *, NiDX9Renderer *))(*(_DWORD *)v6 + 0x84))(v6, v10); /*0x71acbf*/
    }
    else
    {
      result = (NiDX9Renderer *)(*(int (__thiscall **)(_DWORD *))(*(this + 3) + 4))(this + 3); /*0x71ac79*/
      result->member.super.accumulator = (NiAccumulator *)v6; /*0x71ac7b*/
      result->__vftable = 0; /*0x71ac7e*/
      result->member.super.super.m_uiRefCount = *(this + 5); /*0x71ac87*/
      v8 = (NiDX9Renderer **)*(this + 5); /*0x71ac8a*/
      if ( v8 ) /*0x71ac8f*/
      {
        *v8 = result; /*0x71ac91*/
        ++*(this + 6); /*0x71ac93*/
      }
      else
      {
        ++*(this + 6); /*0x71aca0*/
        *(this + 4) = result; /*0x71aca4*/
      }
      *(this + 5) = result; /*0x71ac97*/
      v4 = i; /*0x71ac9a*/
    }
  }
  return result; /*0x71accd*/
}
