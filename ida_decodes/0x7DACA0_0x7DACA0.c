// 0x7DACA0 @ 0x7DACA0
char __thiscall sub_7DACA0(unsigned int *this, const char *a2)
{
  char result; // al
  unsigned int v4; // edi
  void *BSFile; // eax
  int (__cdecl **v6)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // ebx
  int v7; // eax
  TESForm *v8; // esi
  _DWORD *v9; // ebp
  int v10; // [esp+10h] [ebp-114h]
  unsigned int v11; // [esp+14h] [ebp-110h]
  char v12[260]; // [esp+1Ch] [ebp-108h] BYREF

  result = 0; /*0x7dacbf*/
  v4 = 0; /*0x7dacc1*/
  if ( a2 ) /*0x7dacc9*/
  {
    _sprintf(v12, "\\Data\\Shaders\\%s", a2); /*0x7dacdb*/
    BSFile = FileFinder_LoadBSFile(v12, 0, 0); /*0x7dace7*/
    v6 = (int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))BSFile; /*0x7dacec*/
    if ( BSFile ) /*0x7dacf3*/
    {
      if ( (*((int (__stdcall **)(void *))BSFile + 1))(BSFile) == 0xC && v10 == 0x64 ) /*0x7dad23*/
      {
        v7 = FormHeapAlloc(1u); /*0x7dad2a*/
        *(this + 1) = v7; /*0x7dad3a*/
        if ( ReadFile__(v6, v7, 1) == 1 ) /*0x7dad46*/
        {
          v8 = (TESForm *)*(this + 1); /*0x7dad4c*/
          if ( v11 ) /*0x7dad54*/
          {
            v9 = this + 2; /*0x7dad56*/
            do /*0x7dad7d*/
            {
              sub_412D30(v9, (int)v8, v8); /*0x7dad64*/
              ++v4; /*0x7dad6f*/
              v8 = (TESForm *)((char *)v8 + (unsigned int)&v8[0xA].member.modlist.data->name[0xE8]); /*0x7dad76*/
            }
            while ( v4 < v11 ); /*0x7dad7d*/
          }
        }
        else
        {
          FormHeapFree(*(this + 1)); /*0x7dad85*/
          *(this + 1) = 0; /*0x7dad8d*/
        }
      }
      (*(void (__thiscall **)(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD), int))*v6)(v6, 1); /*0x7dad98*/
    }
    return 0; /*0x7dad9b*/
  }
  return result; /*0x7dada0*/
}
