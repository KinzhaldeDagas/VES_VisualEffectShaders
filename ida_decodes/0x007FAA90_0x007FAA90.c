// 0x007FAA90 @ 0x007FAA90
// Branch/lighting shader load thunk: dispatches vtable +0xAC then +0xB0. For SpeedTreeBranchShader these are 0x80FCE0 vertex loader and 0x810630 pixel loader.
int __thiscall sub_7FAA90(void *this)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 0xAC))(this); /*0x7faa9b*/
  return (*(int (__thiscall **)(void *))(*(_DWORD *)this + 0xB0))(this);
}
