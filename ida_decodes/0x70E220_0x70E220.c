// 0x70E220 @ 0x70E220
BSStringT *__thiscall sub_70E220(BSStringT *this, char *a2, int a3)
{
  this->m_data = a2; /*0x70e22a*/
  *(_DWORD *)&this->m_dataLen = a3; /*0x70e22c*/
  return this; /*0x70e22f*/
}
