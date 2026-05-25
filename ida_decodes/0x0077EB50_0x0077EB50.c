// 0x0077EB50 @ 0x0077EB50
// MoonSugarEffect decode: shader-program factory lookup/validity helper used by program vtables. If no concrete D3D handle exists, asks the shader program factory to restore/retrieve one for the wrapper.
char __cdecl sub_77EB50(int a1)
{
  int v2; // eax

  if ( !shaderProgramFactory || !a1 ) /*0x77eb60*/
    return 0; /*0x77eb60*/
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 0x38))(a1) ) /*0x77eb69*/
    return 1; /*0x77eb72*/
  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 0x20))(a1); /*0x77eb7a*/
  if ( v2 ) /*0x77eb7e*/
    return (*(char (__thiscall **)(int, int))(*(_DWORD *)v2 + 0x20))(v2, a1); /*0x77eb88*/
  else
    return 0; /*0x77eb8c*/
}
