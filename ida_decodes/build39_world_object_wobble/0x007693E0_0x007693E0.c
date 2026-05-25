// 0x007693E0 @ 0x007693E0
// MoonSugarEffect decode: RenderTriGeometries copies world transform/bound, chooses dynamic/unshared geometry group, then routes to skinned setup 0x767520 or non-skinned setup 0x7672F0.
void __thiscall RenderTriGeometries(NiDX9Renderer *a1, NiGeometry *a5)
{
  _DWORD *v2; // ebp MAPDST
  int v3; // edi
  int v4; // esi
  NiObject *skinData; // eax
  float y; // edx
  float z; // eax
  char v10; // al
  NiSkinInstance *v12; // [esp+4h] [ebp-4Ch]
  NiGeometryData *geomData; // [esp+8h] [ebp-48h]
  _DWORD v14[4]; // [esp+Ch] [ebp-44h] BYREF
  float v15[13]; // [esp+1Ch] [ebp-34h] BYREF
  char a5a; // [esp+54h] [ebp+4h]

  if ( !a1->member.lostDevice ) /*0x7693e6*/
  {
    geomData = a5->member.geomData; /*0x769403*/
    if ( ((unsigned __int16 (*)(void))geomData->__vftable->GetNumVertices)() ) /*0x769407*/
    {
      skinData = a5->member.skinData; /*0x769412*/
      y = a5->member.super.m_kWorldBound.Center.y; /*0x769418*/
      qmemcpy(v15, &a5->member.super.m_worldTransform, sizeof(v15)); /*0x769429*/
      v14[0] = LODWORD(a5->member.super.m_kWorldBound.Center.x); /*0x76942e*/
      v12 = (NiSkinInstance *)skinData; /*0x769435*/
      z = a5->member.super.m_kWorldBound.Center.z; /*0x769439*/
      v14[3] = LODWORD(a5->member.super.m_kWorldBound.Radius); /*0x76943e*/
      *(float *)&v14[1] = y; /*0x769445*/
      *(float *)&v14[2] = z; /*0x769449*/
      v10 = sub_768890(a1, a5, 0); /*0x76944d*/
      a5a = v10; /*0x769468*/
      if ( (geomData->member.m_usDirtyFlags & 0xF000) == 0x8000 || v12 && !v10 ) /*0x769474*/
        NiGeometryGroup::AddGeometryDataToGroup(a1->member.dynamicGeometryGroup, geomData, v12, v10, 0, 0); /*0x7694a2*/
      else
        NiGeometryGroup::AddGeometryDataToGroup(a1->member.unsharedGeometryGroup, geomData, v12, v10, 0, 0); /*0x769488*/
      if ( a5a ) /*0x7694b4*/
        sub_767520((int)a1, (int)a1, (int)a5, (int)v12, (int)a5, (int)geomData, v12, (int)v15, (int)v14, v3, v4, v2); /*0x7694bd*/
      else
        sub_7672F0(a1, a5, geomData, v12, v15, (UInt32)v14, geomData->member.BuffData);// MoonSugarEffect decode/implementation: direct RenderTriGeometries non-skinned call to sub_7672F0. Plugin patches this 5-byte call with a wrapper that preserves thiscall+retn18 behavior, copies arg4 NiTransform, applies subtle active Moon Sugar rigid object wobble, skips skinned/null/exact NiScreenElements, then calls original 0x007672F0. /*0x7694d7*/
    }
  }
}
