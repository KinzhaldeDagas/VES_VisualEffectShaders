// 0x7D21F0 @ 0x7D21F0
// MoonSugarEffect decode: shadow/offscreen object-list cleanup/finalize; walks list entries, updates eligible shader properties, resets active shader globals, then frees object lists.
void __thiscall sub_7D21F0(_DWORD *this)
{
  _DWORD *v2; // edi
  NiNode *v3; // eax
  NiProperty *NiPropertyByID; // esi
  BOOL v5; // eax
  _DWORD *v6; // eax

  v2 = (_DWORD *)*(this + 0x3A); /*0x7d21f4*/
  while ( v2 )
  {
    v3 = (NiNode *)v2[2]; /*0x7d2203*/
    v2 = (_DWORD *)*v2; /*0x7d2205*/
    NiPropertyByID = NiNode_GetNiPropertyByID(v3, 4); /*0x7d2210*/
    if ( NiPropertyByID )
    {
      v5 = (*((int (__thiscall **)(NiProperty *))NiPropertyByID->vtbl + 0x15))(NiPropertyByID) >= 1 /*0x7d2239*/
        && (*((int (__thiscall **)(NiProperty *))NiPropertyByID->vtbl + 0x15))(NiPropertyByID) <= 0xA;
      v6 = v5 ? (_DWORD *)NiPropertyByID : 0;
      if ( v6 ) /*0x7d2241*/
        sub_7EE720(v6, (char)this); /*0x7d2246*/
    }
  }
  dword_B42E90 = 0xFFFFFFFF; /*0x7d2256*/
  dword_B42EB8 = 0; /*0x7d2260*/
  NiTPointerList::FreeAllNodes((NiTPointerList__BSImageSpaceShader *)(this + 0x39)); /*0x7d226a*/
  NiTPointerList::FreeAllNodes((NiTPointerList__BSImageSpaceShader *)this + 0xB); /*0x7d2277*/
}
