// 0x7A9820 @ 0x7A9820
// MoonSugarEffect decode: object render with forced shader id. Sets dword_B42E90 and dword_B42EB8, updates shader property constants, then calls the object's render vtable.
int __stdcall sub_7A9820(_DWORD *a1, unsigned __int16 a2)
{
  NiDX9Renderer *v3; // ebp
  NiProperty *NiPropertyByID; // eax
  float *v5; // edi
  unsigned __int8 i; // bl
  float v8; // [esp+1Ch] [ebp+8h]

  v3 = g_Renderer; /*0x7a9827*/
  dword_B42E90 = a2; /*0x7a9836*/
  dword_B42EB8 = (int)a1; /*0x7a983b*/
  NiPropertyByID = NiNode_GetNiPropertyByID((NiNode *)*a1, 4); /*0x7a9845*/
  v5 = (float *)NiPropertyByID; /*0x7a984a*/
  if ( NiPropertyByID ) /*0x7a984e*/
  {
    if ( (*((int (__thiscall **)(NiProperty *))NiPropertyByID->vtbl + 0x15))(NiPropertyByID) >= 1 /*0x7a986a*/
      && (*(int (__thiscall **)(float *))(*(_DWORD *)v5 + 0x54))(v5) <= 0xA )
    {
      v8 = v5[0x25]; /*0x7a9876*/
      if ( (a2 < 6u || a2 > 9u) && a2 != 0x154 && a2 != 0x155 ) /*0x7a988e*/
        sub_7ECB20(); /*0x7a9890*/
      for ( i = 0; i < *((_BYTE *)a1 + 8); ++i ) /*0x7a9897*/
        sub_7EE390(i, *(_DWORD *)(a1[3] + 4 * i), v8); /*0x7a98b3*/
    }
  }
  return (*(int (__thiscall **)(_DWORD, NiDX9Renderer *))(*(_DWORD *)*a1 + 0x84))(*a1, v3); /*0x7a98d0*/
}
