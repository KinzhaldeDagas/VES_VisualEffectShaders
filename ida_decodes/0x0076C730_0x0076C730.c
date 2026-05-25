// 0x0076C730 @ 0x0076C730
// NiD3DPass render-state wrapper: ensures pass render-state group exists, then inserts/updates one D3D render state via 0x772CD0.
char __thiscall sub_76C730(_DWORD *this, int a2, int a3, char a4)
{
  if ( !*(this + 0xC) ) /*0x76c733*/
    *(this + 0xC) = sub_772DF0(); /*0x76c73e*/
  return sub_772CD0((_DWORD *)*(this + 0xC), a2, a3, a4); /*0x76c758*/
}
