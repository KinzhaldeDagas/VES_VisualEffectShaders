// 0x00783070 @ 0x00783070
int __usercall sub_783070@<eax>(int a1@<ecx>, int a2@<esi>)
{
  int result; // eax

  if ( *(_DWORD *)(a1 + 0x30) ) /*0x783070*/
    return sub_763090(*(_DWORD *)(a1 + 0x20), a2, a1); /*0x78307a*/
  return result; /*0x78307f*/
}
