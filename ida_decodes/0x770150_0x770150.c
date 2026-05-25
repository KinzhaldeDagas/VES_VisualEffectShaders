// 0x770150 @ 0x770150
// MoonSugarEffect decode: converts one internal 0x1C-byte declaration element into an 8-byte D3DVERTEXELEMENT9 entry, assigns byte offset, maps type/method/usage through static tables, and returns element byte size for stride accumulation.
int __thiscall sub_770150(_DWORD *this, int a2, __int16 a3)
{
  *(_WORD *)(*(this + 0xB) + 8 * *(this + 6)) = a3; /*0x77015d*/
  *(_WORD *)(*(this + 0xB) + 8 * *(this + 6) + 2) = *(_WORD *)(a2 + 4); /*0x770170*/
  *(_BYTE *)(*(this + 0xB) + 8 * *(this + 6) + 4) = *(_BYTE *)(4 * *(_DWORD *)(a2 + 0xC) + 0xB29858); /*0x770186*/
  *(_BYTE *)(*(this + 0xB) + 8 * *(this + 6) + 5) = *(_BYTE *)(4 * *(_DWORD *)(a2 + 0x10) + 0xB2983C); /*0x77019b*/
  *(_BYTE *)(*(this + 0xB) + 8 * *(this + 6) + 6) = *(_BYTE *)(4 * *(_DWORD *)(a2 + 0x14) + 0xB298A0); /*0x7701b0*/
  *(_BYTE *)(*(this + 0xB) + 8 * (*(this + 6))++ + 7) = *(_BYTE *)(a2 + 0x18); /*0x7701bd*/
  if ( *(int *)(a2 + 0xC) < 0x12 ) /*0x7701cc*/
    return *(_DWORD *)(4 * *(_DWORD *)(a2 + 0xC) + 0xB42708); /*0x7701d6*/
  else
    return 0; /*0x7701ce*/
}
