// 0x405760 @ 0x405760
// MoonSugarEffect decode: NiGeometry render-pass bundle accessor. Returns this->unk0AC through an out pointer and AddRefs the bundle; callers release immediately after reading the raw pointer.
volatile LONG **__thiscall sub_405760(NiGeometry *this, volatile LONG **a2)
{
  volatile LONG *unk0AC; // eax

  unk0AC = (volatile LONG *)this->member.unk0AC; /*0x405761*/
  *a2 = unk0AC; /*0x405776*/
  if ( unk0AC ) /*0x405778*/
    InterlockedIncrement(unk0AC + 1); /*0x40577e*/
  return a2; /*0x405786*/
}
