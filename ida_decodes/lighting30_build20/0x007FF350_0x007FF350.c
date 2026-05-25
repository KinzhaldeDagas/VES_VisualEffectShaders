// 0x007FF350 @ 0x007FF350
bool __stdcall sub_7FF350(NiNode *a1)
{
  int v1; // edi
  NiProperty *NiPropertyByID; // eax
  LONG (__stdcall *v3)(volatile LONG *); // ebp
  NiNode *v4; // esi
  BSShaderPPLightingProperty *v5; // eax
  BSShaderPPLightingProperty *v6; // esi
  int v7; // esi

  v1 = (int)a1; /*0x7ff374*/
  NiPropertyByID = NiNode_GetNiPropertyByID(a1, 4); /*0x7ff37c*/
  v3 = InterlockedDecrement; /*0x7ff383*/
  if ( NiPropertyByID ) /*0x7ff389*/
  {
    if ( (*((int (__thiscall **)(NiProperty *))NiPropertyByID->vtbl + 0x15))(NiPropertyByID) == 0xA ) /*0x7ff3a0*/
      return 1; /*0x7ff3a0*/
    sub_708560((int **)v1, (volatile LONG **)&a1, 4); /*0x7ff3af*/
    if ( a1 ) /*0x7ff3ba*/
    {
      v4 = a1; /*0x7ff3bc*/
      if ( !v3((volatile LONG *)&a1->members) ) /*0x7ff3c2*/
        v4->vtbl->super.super.super.Destructor((NiRefObject *)v4, 1); /*0x7ff3d4*/
    }
  }
  v5 = (BSShaderPPLightingProperty *)FormHeapAlloc(0x108u); /*0x7ff3db*/
  if ( v5 ) /*0x7ff3f1*/
    v6 = sub_863430(v5); /*0x7ff3fa*/
  else
    v6 = 0; /*0x7ff3fe*/
  sub_405680((NiNode *)v1, (BSShaderProperty *)v6); /*0x7ff40b*/
  if ( !(*(unsigned __int8 (__thiscall **)(BSShaderPPLightingProperty *, int))(*(_DWORD *)v6 + 0x58))(v6, v1) ) /*0x7ff418*/
  {
    sub_4A1220((int **)v1, (int)v6); /*0x7ff421*/
    v7 = *(_DWORD *)(v1 + 0xBC); /*0x7ff426*/
    if ( v7 ) /*0x7ff42e*/
    {
      if ( !v3((volatile LONG *)(v7 + 4)) ) /*0x7ff434*/
        (**(void (__thiscall ***)(int, int))v7)(v7, 1); /*0x7ff446*/
      *(_DWORD *)(v1 + 0xBC) = 0; /*0x7ff448*/
    }
    return 0; /*0x7ff448*/
  }
  return (*(int (__thiscall **)(BSShaderPPLightingProperty *, _DWORD))(*(_DWORD *)v6 + 0x8C))(v6, 0) != 0; /*0x7ff475*/
}
