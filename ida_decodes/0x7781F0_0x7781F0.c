// 0x7781F0 @ 0x7781F0
// MoonSugarEffect decode: index-buffer allocator/uploader. Reuses IB only if GetDesc matches index16/writeonly/dynamic-ish ownership, size, and usage; otherwise creates a new D3D index buffer, locks, memcpy's 16-bit indices, unlocks.
int __userpurge sub_7781F0@<eax>(
        int a1@<ecx>,
        NiGeometryBufferData *a2@<edi>,
        int a3@<esi>,
        int a4,
        void *Src,
        int a6,
        int a7,
        unsigned int *a8,
        int a9,
        void *Dst)
{
  void *v11; // ebp
  int v12; // esi
  unsigned int v13; // edi
  int v14; // ebx
  int v15; // eax
  void *v16; // ecx
  int (__stdcall *v17)(int, _DWORD, int, int *, _DWORD, _DWORD); // eax
  void *v18; // ecx
  size_t v19; // [esp+Ch] [ebp-28h]
  int v21; // [esp+20h] [ebp-14h] BYREF
  int v22; // [esp+24h] [ebp-10h]
  void *v23; // [esp+28h] [ebp-Ch]
  int v24; // [esp+2Ch] [ebp-8h]
  unsigned int v25; // [esp+30h] [ebp-4h]

  if ( !*(_DWORD *)(a1 + 8) || !a4 ) /*0x778209*/
    return 0; /*0x778201*/
  v11 = Dst; /*0x778211*/
  HIDWORD(v19) = a3; /*0x778215*/
  v12 = a7; /*0x778216*/
  LODWORD(v19) = a2; /*0x77821a*/
  v13 = 2 * a6; /*0x77821f*/
  v14 = 2 * (_DWORD)Src; /*0x778221*/
  if ( !a7 /*0x778270*/
    || (v21 = 0,
        v22 = 0,
        v23 = 0,
        v24 = 0,
        v25 = 0,
        (*(int (__stdcall **)(int, int *))(*(_DWORD *)a7 + 0x34))(a7, &v21) < 0)
    || v21 != 0x65
    || v22 != 7
    || v23 != v11
    || v24 != a9
    || v25 < v13 )
  {
    v15 = *(_DWORD *)(a1 + 8); /*0x778276*/
    a6 = 0; /*0x778288*/
    if ( (*(int (__stdcall **)(int, unsigned int, void *, int, int, int *, _DWORD))(*(_DWORD *)v15 + 0x6C))( /*0x77829b*/
           v15,
           v13,
           v11,
           0x65,
           a9,
           &a6,
           0) >= 0 )
    {
      v12 = a6; /*0x7782b2*/
    }
    else
    {
      TESTexture::ClearComponentReferences(v16); /*0x7782a2*/
      v12 = 0; /*0x7782aa*/
      a6 = 0; /*0x7782ac*/
    }
    if ( !v12 ) /*0x7782b8*/
    {
      TESTexture::ClearComponentReferences(v16); /*0x7782bf*/
      return 0; /*0x7782d0*/
    }
    *a8 = v13; /*0x7782d7*/
  }
  if ( v14 ) /*0x7782db*/
  {
    v17 = *(int (__stdcall **)(int, _DWORD, int, int *, _DWORD, _DWORD))(*(_DWORD *)v12 + 0x2C); /*0x7782df*/
    a9 = 0; /*0x7782ed*/
    if ( v17(v12, 0, v14, &a9, 0, v19) >= 0 ) /*0x7782f9*/
    {
      LODWORD(v19) = 2 * (_DWORD)Src; /*0x778303*/
      memcpy(Dst, Src, v19); /*0x778306*/
      (*(void (__cdecl **)(int))(*(_DWORD *)v12 + 0x30))(v12); /*0x778314*/
      return v12; /*0x77831f*/
    }
    TESTexture::ClearComponentReferences(v18); /*0x778327*/
    (*(void (__cdecl **)(int))(*(_DWORD *)v12 + 0x30))(v12); /*0x778335*/
    (*(void (__stdcall **)(int))(*(_DWORD *)v12 + 8))(v12); /*0x77833d*/
  }
  return v12; /*0x7781fe*/
}
