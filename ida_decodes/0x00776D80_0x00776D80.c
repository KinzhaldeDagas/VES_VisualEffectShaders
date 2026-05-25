// 0x00776D80 @ 0x00776D80
// MoonSugarEffect decode: vertex-buffer-manager unlock/staging helper. Copies the staging buffer back to the locked D3D buffer, clears lock bookkeeping, leaves the critical section, then calls the vertex buffer Unlock vtable slot.
bool __userpurge sub_776D80@<al>(int this@<ecx>, int a2@<esi>, int a3)
{
  size_t v6; // [esp-8h] [ebp-8h]

  HIDWORD(v6) = a2; /*0x776d80*/
  LODWORD(v6) = *(_DWORD *)(this + 0x4C); /*0x776d8c*/
  memcpy(*(void **)(this + 0x48), *(const void **)(this + 0x40), v6); /*0x776d8f*/
  *(_DWORD *)(this + 0x48) = 0; /*0x776d9f*/
  *(_DWORD *)(this + 0x4C) = 0; /*0x776da2*/
  if ( (*(_DWORD *)(this + 0xFC))-- == 1 ) /*0x776da5*/
    *(_DWORD *)(this + 0xF8) = 0; /*0x776dac*/
  LeaveCriticalSection((LPCRITICAL_SECTION)(this + 0x80)); /*0x776db0*/
  return (*(int (__stdcall **)(int))(*(_DWORD *)a3 + 0x30))(a3) >= 0; /*0x776dcb*/
}
