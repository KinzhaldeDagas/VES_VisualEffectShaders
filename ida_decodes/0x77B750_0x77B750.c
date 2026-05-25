// 0x77B750 @ 0x77B750
int __thiscall sub_77B750(_DWORD *this, unsigned __int8 a2)
{
  int result; // eax
  int v4; // eax

  if ( a2 != *((_BYTE *)this + 0x1014) ) /*0x77b75d*/
  {
    result = *(this + 0x3FF); /*0x77b75f*/
    if ( *(_BYTE *)(result + 0x5C9) ) /*0x77b765*/
    {
      v4 = *(this + 0x3FE); /*0x77b76e*/
      *((_BYTE *)this + 0x1014) = a2; /*0x77b774*/
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v4 + 0x134))(v4, a2); /*0x77b787*/
      return (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 0x94))(this, *(this + 0x3F8)); /*0x77b79a*/
    }
  }
  return result; /*0x77b79c*/
}
