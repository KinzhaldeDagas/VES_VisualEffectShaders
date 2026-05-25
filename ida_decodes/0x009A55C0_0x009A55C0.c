// 0x009A55C0 @ 0x009A55C0
char __cdecl sub_9A55C0(char *Str1, unsigned __int8 **a2)
{
  int v2; // esi
  unsigned __int8 **i; // edi

  v2 = 0; /*0x9a55c2*/
  if ( !dword_B32588 ) /*0x9a55cb*/
    return 0; /*0x9a55f5*/
  for ( i = (unsigned __int8 **)&unk_B328F0; _strcmp((unsigned __int8 *)Str1, i[1]); i += 2 ) /*0x9a55d1*/
  {
    if ( ++v2 >= (unsigned int)dword_B32588 ) /*0x9a55f3*/
      return 0; /*0x9a55f3*/
  }
  *a2 = *i; /*0x9a5603*/
  return 1; /*0x9a55f5*/
}
