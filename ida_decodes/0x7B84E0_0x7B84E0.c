// 0x7B84E0 @ 0x7B84E0
// MoonSugarEffect decode: walks ShaderDefinition cache B42EC0..B42F30; for shaders with type != -1 calls vtable +0x90 to detach pass texture-stage refs before texture-manager rebuild. Does not walk arbitrary plugin-owned shader wrappers or call vertex wrapper +0x5C.
int sub_7B84E0()
{
  int *v0; // esi
  int result; // eax
  int v2; // ecx
  int v3; // ecx

  v0 = dword_B42EC0; /*0x7b84e1*/
  do /*0x7b851f*/
  {
    result = *v0; /*0x7b84e6*/
    if ( *v0 ) /*0x7b84e6*/
    {
      v2 = *(_DWORD *)(result + 4); /*0x7b84ec*/
      if ( v2 ) /*0x7b84f1*/
      {
        result = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 0x1C))(v2); /*0x7b84f8*/
        if ( result == 0xFFFFFFFF ) /*0x7b84fd*/
        {
          v3 = 0; /*0x7b84ff*/
        }
        else
        {
          result = *v0; /*0x7b8503*/
          v3 = *(_DWORD *)(*v0 + 4); /*0x7b8505*/
        }
        if ( v3 ) /*0x7b850a*/
          result = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 0x90))(v3); /*0x7b8514*/
      }
    }
    ++v0; /*0x7b8516*/
  }
  while ( (int)v0 < (int)&byte_B42F30 ); /*0x7b851f*/
  return result; /*0x7b8521*/
}
