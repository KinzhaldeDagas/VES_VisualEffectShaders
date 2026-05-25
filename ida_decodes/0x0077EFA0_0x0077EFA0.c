// 0x0077EFA0 @ 0x0077EFA0
void __cdecl sub_77EFA0(int a1)
{
  int v1; // eax
  _DWORD *v2; // ecx

  if ( shaderProgramFactory ) /*0x77efa0*/
  {
    if ( a1 ) /*0x77efaf*/
    {
      v1 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 4))(a1); /*0x77efb6*/
      if ( v1 ) /*0x77efba*/
      {
        v2 = *((_DWORD **)shaderProgramFactory + 6); /*0x77efc2*/
        if ( v2 ) /*0x77efc7*/
          NiTMap_RemoveAt(v2, v1); /*0x77efca*/
      }
    }
  }
}
