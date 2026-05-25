// 0x77EB10 @ 0x77EB10
// MoonSugarEffect decode: vertex wrapper validity/restore helper. If vtable +0x40 returns live IDirect3DVertexShader9, succeeds. Otherwise vtable +0x20 reads base creator pointer at +0x18 and creator vtable +0x1C rebuilds/restores the handle. Plain TES4 CreateVertexShader wrappers have no creator and cannot self-restore.
char __cdecl sub_77EB10(int a1)
{
  int v2; // eax

  if ( !shaderProgramFactory || !a1 ) /*0x77eb20*/
    return 0; /*0x77eb20*/
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 0x40))(a1) ) /*0x77eb29*/
    return 1; /*0x77eb32*/
  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 0x20))(a1); /*0x77eb3a*/
  if ( v2 ) /*0x77eb3e*/
    return (*(char (__thiscall **)(int, int))(*(_DWORD *)v2 + 0x1C))(v2, a1); /*0x77eb48*/
  else
    return 0; /*0x77eb4c*/
}
