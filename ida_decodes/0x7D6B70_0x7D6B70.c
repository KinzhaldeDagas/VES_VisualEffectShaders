// 0x7D6B70 @ 0x7D6B70
int sub_7D6B70()
{
  int *v0; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 0; /*0x7d6b73*/
  if ( dword_B45D74 ) /*0x7d6b76*/
  {
    v0 = (int *)(4 * dword_B45D74 + 0xB45D74); /*0x7d6b85*/
  }
  else
  {
    v2 = 0; /*0x7d6b90*/
    v0 = &v2; /*0x7d6b94*/
  }
  return *v0; /*0x7d6bc5*/
}
