// 0x7A9800 @ 0x7A9800
// MoonSugarEffect decode: BSShaderAccumulator prepare-with-camera entry (+0x4C). Stores camera at accumulator +8 and marks pending flag +0x2268.
int __thiscall sub_7A9800(int this, int a2)
{
  int result; // eax

  if ( !*(_BYTE *)(this + 0x2268) ) /*0x7a9800*/
  {
    *(_DWORD *)(this + 8) = a2; /*0x7a980d*/
    *(_BYTE *)(this + 0x2268) = 1; /*0x7a9810*/
    return a2; /*0x7a9809*/
  }
  return result; /*0x7a9817*/
}
