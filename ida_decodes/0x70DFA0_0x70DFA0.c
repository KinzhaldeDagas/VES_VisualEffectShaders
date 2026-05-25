// 0x70DFA0 @ 0x70DFA0
// MoonSugarEffect decode: BSCullingProcess destructor only restores NiCullingProcess vtable; no visible-array or heap cleanup is owned here.
void __thiscall BSCullingProcess::~BSCullingProcess(BSCullingProcess *this)
{
  this->super.vtbl = (NiCullingProcessVtbl *)&NiCullingProcess::`vftable'; /*0x70dfa0*/
}
