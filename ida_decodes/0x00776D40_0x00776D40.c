// 0x00776D40 @ 0x00776D40
// MoonSugarEffect decode: strided memcpy helper used by fallback packer to copy source vertex arrays into mapped stream bytes.
void *__userpurge sub_776D40@<eax>(int a1@<edi>, char *Dst, char *Src, int a4, size_t Size, int a6)
{
  void *result; // eax
  size_t v9; // [esp-14h] [ebp-14h]

  result = (void *)HIDWORD(Size); /*0x776d40*/
  if ( HIDWORD(Size) ) /*0x776d46*/
  {
    HIDWORD(v9) = a1; /*0x776d57*/
    do /*0x776d74*/
    {
      LODWORD(v9) = Size; /*0x776d60*/
      result = memcpy(Dst, Src, v9); /*0x776d63*/
      Dst += a4; /*0x776d6b*/
      Src += Size; /*0x776d6d*/
      --HIDWORD(Size); /*0x776d6f*/
    }
    while ( HIDWORD(Size) ); /*0x776d74*/
  }
  return result; /*0x776d7a*/
}
