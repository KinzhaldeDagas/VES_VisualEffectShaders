// 0x9A4AC0 @ 0x9A4AC0
unsigned int __stdcall sub_9A4AC0(int a1, int a2, int a3)
{
  int *v3; // eax

  v3 = sub_9A92E0(a2); /*0x9a4ac6*/
  if ( v3 )
    return (*(unsigned __int8 (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, v3, 0) != 0
         ? 0
         : 0x80000050;
  else
    return 1; /*0x9a4acf*/
}
