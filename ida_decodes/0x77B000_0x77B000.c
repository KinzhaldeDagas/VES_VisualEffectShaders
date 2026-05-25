// 0x77B000 @ 0x77B000
_DWORD *__thiscall NiRenderer_SetRenderState(NiDX9Renderer *this, int a2, _DWORD *a3, char a4)
{
  _DWORD *result; // eax

  if ( (_DWORD *)this->member.super.PrecacheCriticalSection.pad018[2 * a2 + 2] != a3 ) /*0x77b014*/
    result = (_DWORD *)(*(int (__stdcall **)(_DWORD, int, _DWORD *))(**((_DWORD **)this + 0x3FE) + 0xE4))( /*0x77b027*/
                         *((_DWORD *)this + 0x3FE),
                         a2,
                         a3);
  if ( a4 ) /*0x77b02e*/
  {
    result = (_DWORD *)this->member.super.PrecacheCriticalSection.pad018[2 * a2 + 2]; /*0x77b030*/
    this->member.super.PrecacheCriticalSection.pad018[2 * a2 + 3] = (UInt32)result; /*0x77b037*/
  }
  this->member.super.PrecacheCriticalSection.pad018[2 * a2 + 2] = (UInt32)a3; /*0x77b03e*/
  return result; /*0x77b045*/
}
