// 0x776C90 @ 0x776C90
int __userpurge sub_776C90@<eax>(char *this@<ecx>, int a2, int a3, size_t Size, int a5)
{
  int (__stdcall *v6)(int, int, _DWORD, void **, _DWORD); // eax
  DWORD CurrentThreadId; // eax
  void *v9; // ecx
  bool v10; // cf
  size_t v11; // [esp+4h] [ebp-14h]
  void *Src; // [esp+14h] [ebp-4h] BYREF

  v6 = *(int (__stdcall **)(int, int, _DWORD, void **, _DWORD))(*(_DWORD *)a2 + 0x2C); /*0x776cb1*/
  Src = 0; /*0x776cb4*/
  if ( v6(a2, a3, Size, &Src, HIDWORD(Size)) < 0 ) /*0x776cc0*/
    return 0; /*0x776cc4*/
  EnterCriticalSection((LPCRITICAL_SECTION)this + 4); /*0x776cd3*/
  CurrentThreadId = GetCurrentThreadId(); /*0x776cd9*/
  ++*((_DWORD *)this + 0x3F); /*0x776cdf*/
  v9 = Src; /*0x776ce3*/
  *((_DWORD *)this + 0x3E) = CurrentThreadId; /*0x776ce7*/
  v10 = *((_DWORD *)this + 0x11) < (unsigned int)Size; /*0x776cea*/
  *((_DWORD *)this + 0x12) = v9; /*0x776ced*/
  *((_DWORD *)this + 0x13) = Size; /*0x776cf0*/
  if ( v10 ) /*0x776cf4*/
  {
    FormHeapFree(*((_DWORD *)this + 0x10)); /*0x776cfa*/
    *((_DWORD *)this + 0x10) = FormHeapAlloc(Size); /*0x776d08*/
    *((_DWORD *)this + 0x11) = Size; /*0x776d0b*/
  }
  if ( (Size & 0x300000000000LL) == 0 ) /*0x776d14*/
  {
    LODWORD(v11) = Size; /*0x776d1d*/
    memcpy(*((void **)this + 0x10), Src, v11); /*0x776d20*/
  }
  return *((_DWORD *)this + 0x10); /*0x776cc2*/
}
