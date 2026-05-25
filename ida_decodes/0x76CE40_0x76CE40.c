// 0x76CE40 @ 0x76CE40
NiD3DPass *__thiscall sub_76CE40(NiTArray_NiD3DPass *this, NiD3DPass *a2, NiD3DPass **a3)
{
  NiD3DPass *result; // eax
  int v5; // ecx
  NiD3DPass *data; // edx
  NiD3DPass **v7; // esi
  NiD3DPass *v8; // ecx
  bool v9; // zf

  if ( (dword_B42578 & 1) == 0 ) /*0x76ce50*/
  {
    dword_B42578 |= 1u; /*0x76ce52*/
    dword_B42574 = 0; /*0x76ce5d*/
    atexit(sub_A26DC0); /*0x76ce67*/
  }
  result = a2; /*0x76ce73*/
  if ( (unsigned int)a2 < this->end ) /*0x76ce7d*/
  {
    v5 = dword_B42574; /*0x76ce96*/
    data = this->data; /*0x76ce9e*/
    if ( *a3 == (NiD3DPass *)dword_B42574 ) /*0x76cea1*/
    {
      if ( *((_DWORD *)&data->__vftable + (_DWORD)a2) != v5 ) /*0x76ceb1*/
        --this->numObjs; /*0x76ceb3*/
    }
    else if ( *((_DWORD *)&data->__vftable + (_DWORD)a2) == v5 ) /*0x76cea6*/
    {
      ++this->numObjs; /*0x76cea8*/
    }
  }
  else
  {
    this->end = (_WORD)a2 + 1; /*0x76ce82*/
    if ( *a3 != (NiD3DPass *)dword_B42574 ) /*0x76ce8e*/
      ++this->numObjs; /*0x76ce90*/
  }
  v7 = (NiD3DPass **)(&this->data->__vftable + (_DWORD)a2); /*0x76cebc*/
  v8 = *v7; /*0x76cebf*/
  if ( *v7 != *a3 ) /*0x76cec3*/
  {
    if ( v8 ) /*0x76cec7*/
    {
      v9 = v8->RefCount-- == 1; /*0x76cec9*/
      if ( v9 ) /*0x76cecd*/
        sub_7604D0(v8); /*0x76cecf*/
    }
    result = *a3; /*0x76ced4*/
    v9 = *a3 == 0; /*0x76ced6*/
    *v7 = *a3; /*0x76ced8*/
    if ( !v9 ) /*0x76ceda*/
      ++result->RefCount; /*0x76cedc*/
  }
  return result; /*0x76cedf*/
}
