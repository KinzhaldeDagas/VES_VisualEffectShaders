// 0x0087FA20 @ 0x0087FA20
void __thiscall sub_87FA20(NiTArray_NiD3DPass *this, int a2, int a3, int a4, NiD3DPass *a5)
{
  NiD3DPass *v6; // edi
  int v7; // ebx
  UInt32 Stage; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // ebp
  NiTexture *Texture; // ebx
  int v13; // eax
  UInt32 m_uiRefCount; // ebx
  int v15; // ebp
  NiTexture *v16; // ebp
  UInt32 v17; // ebx
  bool v18; // zf
  NiD3DPass *v19; // ecx
  UInt32 v20; // [esp+34h] [ebp+Ch]
  NiTexture *v21; // [esp+34h] [ebp+Ch]

  v6 = (NiD3DPass *)dword_B47718[0]; /*0x87fa4d*/
  sub_848C40(*(float **)(a4 + 0x10)); /*0x87fa54*/
  v7 = *(_DWORD *)(a4 + 0xC); /*0x87fa59*/
  sub_848E50(v7); /*0x87fa5f*/
  (*((void (__thiscall **)(NiTArray_NiD3DPass *, int, int, _DWORD))this->_vtbl + 0x2F))(this, a2, v7, 0); /*0x87fa76*/
  Stage = v6->Stages.data->Stage; /*0x87fa7f*/
  v20 = Stage; /*0x87fa8b*/
  v9 = ((int (__thiscall *)(NiD3DPass *, _DWORD))a5->__vftable[8].sub_75FD90)(a5, 0); /*0x87fa8f*/
  v10 = *(_DWORD *)(Stage + 4); /*0x87fa91*/
  v11 = v9; /*0x87fa94*/
  if ( v10 != v9 ) /*0x87fa98*/
  {
    if ( v10 ) /*0x87fa9c*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) ) /*0x87faa2*/
        (**(void (__thiscall ***)(int, int))v10)(v10, 1); /*0x87fab8*/
    }
    *(_DWORD *)(v20 + 4) = v11; /*0x87fac0*/
    if ( v11 ) /*0x87fac3*/
      InterlockedIncrement((volatile LONG *)(v11 + 4)); /*0x87fac9*/
  }
  Texture = v6->Stages.data->Texture; /*0x87fad6*/
  v21 = Texture; /*0x87fade*/
  v13 = sub_848FD0(a5, 0); /*0x87fae2*/
  m_uiRefCount = Texture->members.super.super.m_uiRefCount; /*0x87fae7*/
  v15 = v13; /*0x87faea*/
  if ( m_uiRefCount != v13 ) /*0x87faee*/
  {
    if ( m_uiRefCount ) /*0x87faf2*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(m_uiRefCount + 4)) ) /*0x87faf8*/
        (**(void (__thiscall ***)(UInt32, int))m_uiRefCount)(m_uiRefCount, 1); /*0x87fb0e*/
    }
    v21->members.super.super.m_uiRefCount = v15; /*0x87fb16*/
    if ( v15 ) /*0x87fb19*/
      InterlockedIncrement((volatile LONG *)(v15 + 4)); /*0x87fb1f*/
  }
  v16 = v6->Stages.data[1].Texture; /*0x87fb28*/
  v17 = v16->members.super.super.m_uiRefCount; /*0x87fb30*/
  v18 = v17 == dword_B43110; /*0x87fb33*/
  v19 = (NiD3DPass *)dword_B43110; /*0x87fb35*/
  a5 = (NiD3DPass *)dword_B43110; /*0x87fb37*/
  if ( !v18 ) /*0x87fb3b*/
  {
    if ( v17 ) /*0x87fb3f*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) ) /*0x87fb45*/
        (**(void (__thiscall ***)(UInt32, int))v17)(v17, 1); /*0x87fb5b*/
      v19 = a5; /*0x87fb5d*/
    }
    v16->members.super.super.m_uiRefCount = (UInt32)v19; /*0x87fb63*/
    if ( v19 ) /*0x87fb66*/
      InterlockedIncrement((volatile LONG *)v19->Name); /*0x87fb6c*/
  }
  ++v6->RefCount; /*0x87fb77*/
  a5 = v6; /*0x87fb7a*/
  sub_76CE40(this + 4, *((NiD3DPass **)this + 0xE), &a5); /*0x87fb92*/
  v18 = v6->RefCount-- == 1; /*0x87fb9a*/
  if ( v18 ) /*0x87fba1*/
    sub_7604D0(v6); /*0x87fba5*/
  ++*((_DWORD *)this + 0xE); /*0x87fbaa*/
}
