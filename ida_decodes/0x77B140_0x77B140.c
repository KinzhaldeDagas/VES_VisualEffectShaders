// 0x77B140 @ 0x77B140
int __thiscall sub_77B140(_DWORD **this, int a2, int a3, _DWORD *a4, char a5)
{
  int result; // eax
  int *v6; // esi

  result = *(unsigned __int16 *)(2 * a3 + 0xB427E0); /*0x77b145*/
  if ( (unsigned __int16)result < 8u ) /*0x77b151*/
  {
    result = (unsigned __int16)result + 8 * a2; /*0x77b15b*/
    v6 = (int *)(this + 2 * result + 0x248); /*0x77b16a*/
    if ( (_DWORD *)*v6 != a4 ) /*0x77b171*/
      result = (*(int (__stdcall **)(_DWORD, int, int, _DWORD *))(**(this + 0x3FE) + 0x10C))( /*0x77b185*/
                 *(this + 0x3FE),
                 a2,
                 a3,
                 a4);
    if ( a5 ) /*0x77b18c*/
    {
      result = *v6; /*0x77b18e*/
      v6[1] = *v6; /*0x77b190*/
    }
    *v6 = (int)a4; /*0x77b193*/
  }
  return result; /*0x77b197*/
}
