// 0x4455E0 @ 0x4455E0
void __userpurge sub_4455E0(
        unsigned int a1@<ecx>,
        double PlayerNode@<st0>,
        double st4_0@<st3>,
        double st5_0@<st2>,
        double a5@<st1>,
        double a6@<st7>,
        double a7@<st4>,
        double a8@<st6>,
        double a9@<st5>,
        int a10@<edi>,
        TESObjectREFR *a2,
        float *a12)
{
  BSShaderAccumulator *inited; // eax
  TESObjectREFR *v14; // edi
  char v16; // bl
  void *v17; // ecx
  _DWORD *ShadowSceneNode; // eax
  _DWORD *v19; // eax
  int v20; // eax
  double v21; // st7
  bool v22; // bl
  BSExtraDataVtbl *v23; // edi
  BaseExtraListMembr *p_members; // eax
  int v25; // ecx
  int *v26; // eax
  NiAVObject *v27; // edi
  _DWORD *v28; // ecx
  _DWORD *v29; // ecx
  WaterManager *v30; // ecx
  BSShaderAccumulator *v31; // eax
  _DWORD *sound; // ecx
  NiNode *v33; // [esp+4h] [ebp-18h]
  char a2a; // [esp+20h] [ebp+4h]

  byte_B43384 = 1; /*0x4455e5*/
  if ( !*(_BYTE *)(a1 + 0x51) && !*(_BYTE *)(a1 + 0x52) ) /*0x4455f3*/
    sub_40D160((NiDX9Renderer *)OSGlobals, a10, a1); /*0x4455ff*/
  byte_B43074 = 1; /*0x445604*/
  inited = InitBSShaderAccumulator(); /*0x44560b*/
  sub_7AB6F0(inited); /*0x445612*/
  *(_BYTE *)(bhkWorldM + 0x19) = 0; /*0x44561c*/
  sub_88B680((int *)bhkWorldM, 0); /*0x445628*/
  v14 = *(TESObjectREFR **)(a1 + 0x34); /*0x44562d*/
  if ( v14 == a2 ) /*0x445636*/
  {
    sub_444FB0(a1, a2, PlayerNode, a6, a5, st5_0, st4_0, a7, a8, a9, a12, 0); /*0x445641*/
    byte_B43384 = 0; /*0x445648*/
    return; /*0x445651*/
  }
  if ( bPreemptivelyUnloadCells ) /*0x445654*/
  {
    if ( !v14 ) /*0x445660*/
    {
      v16 = sub_4C9300(); /*0x44566c*/
      if ( sub_43FFF0((_DWORD *)a1, st5_0, a5, PlayerNode, 1, 0) || v16 ) /*0x445679*/
        sub_43FC20((TES *)a1, 0); /*0x44567f*/
    }
  }
  OSGlobals->unk18 = 0; /*0x44568c*/
  if ( a2 ) /*0x445693*/
  {
    if ( !sub_45A500(SaveLoad_CurrentSavegame) && !sub_40FDA0(v17) ) /*0x4456a4*/
      sub_40D4D0((InputGlobal *)OSGlobals, st5_0, a5, PlayerNode); /*0x4456b3*/
  }
  ShadowSceneNode = (_DWORD *)GetShadowSceneNode(0); /*0x4456ba*/
  sub_7C7E50(ShadowSceneNode); /*0x4456c4*/
  a2a = 0; /*0x4456cb*/
  if ( v14 ) /*0x4456d0*/
  {
    a2a = 1; /*0x4456d4*/
    sub_4D6450((int)v14, st5_0, a5, PlayerNode); /*0x4456d9*/
    nullsub_returnTrue_0arg(); /*0x4456e0*/
    sub_7B84E0(); /*0x4456e5*/
    PlayerNode = nullsub_returnTrue_0arg(); /*0x4456ec*/
    v33 = PlayerCharacter_GetPlayerNode(TESDataHandler_g_PlayerRef, 0); /*0x445701*/
    v19 = (_DWORD *)GetShadowSceneNode(0); /*0x445704*/
    ShadowSceneNodeAddShadowCaster(v19, (volatile LONG *)v33); /*0x44570e*/
  }
  if ( !TES::IsInteriorCellPreloaded((TES *)a1, (TESObjectCELL *)a2) ) /*0x445716*/
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 0x38) + 4 * uInteriorCellBuffer - 4) ) /*0x445728*/
      sub_440120( /*0x445733*/
        (_DWORD *)a1,
        st5_0,
        a5,
        PlayerNode,
        *(TESObjectCELL **)(*(_DWORD *)(a1 + 0x38) + 4 * uInteriorCellBuffer - 4));
  }
  *(_DWORD *)(a1 + 0x34) = a2; /*0x44573a*/
  if ( a2 ) /*0x44573d*/
  {
    if ( *(_DWORD *)(a1 + 0x48) == 0x7FFFFFFF && !a2a ) /*0x445751*/
    {
      v20 = *(_DWORD *)(a1 + 0x24); /*0x445756*/
      *(_DWORD *)(a1 + 0x48) = *(_DWORD *)(a1 + 0x20); /*0x44575f*/
      *(_DWORD *)(a1 + 0x4C) = v20; /*0x445762*/
      sub_441D50(a1, PlayerNode, st5_0, st4_0, a5, a9, a8, a7, a6, 1, 0); /*0x445765*/
    }
    *(_DWORD *)(a1 + 0x20) = (int)*a12 >> 0xC; /*0x445783*/
    v21 = a12[1]; /*0x44578d*/
    *(_DWORD *)(a1 + 0x24) = (int)v21 >> 0xC; /*0x44579e*/
    sub_4D4310((TESObjectCELL *)a2); /*0x4457a1*/
    v22 = sub_45A500(SaveLoad_CurrentSavegame); /*0x4457b3*/
    if ( TESObjectCELL_IsInterior((TESObjectCELL *)a2) ) /*0x4457b5*/
      v23 = sub_424180((ExtraDataList *)&a2->member.rot.z); /*0x4457c6*/
    else
      v23 = (BSExtraDataVtbl *)bhkWorldM; /*0x4457ca*/
    if ( v23 ) /*0x4457d2*/
      sub_889E00(v23); /*0x4457d6*/
    p_members = &a2->member.baseExtraList.members; /*0x4457db*/
    v25 = 0; /*0x4457de*/
    if ( a2 != (TESObjectREFR *)0xFFFFFFB8 ) /*0x4457e2*/
    {
      do /*0x4457f1*/
      {
        if ( p_members->m_data ) /*0x4457e4*/
          ++v25; /*0x4457e9*/
        p_members = *(BaseExtraListMembr **)p_members->m_presenceBitfield; /*0x4457ec*/
      }
      while ( p_members ); /*0x4457f1*/
      if ( v25 ) /*0x4457f5*/
      {
        if ( BYTE2(a2->member.rot.y) != 3 ) /*0x4457fb*/
          sub_440AF0(a1, st5_0, a5, (char)a2, 1, 0, 0); /*0x445803*/
      }
    }
    sub_4D63A0(a2, st5_0, a5, v21, *(_DWORD *)(a1 + 0xC)); /*0x44580e*/
    v26 = (int *)sub_4AF170(a2); /*0x445815*/
    if ( v26 ) /*0x44581c*/
      sub_4E7610(v26); /*0x445820*/
    sub_4D5BD0((int)a2, a5, v21, st5_0, st4_0, a7, a9, a8, a6, (char)a2, 1); /*0x445829*/
    if ( sub_43E000(ModelLoaderPtr, (TESObjectCELL *)a2) ) /*0x445835*/
      sub_440AF0(a1, st5_0, a5, (char)a2, 1, 0, 0); /*0x445846*/
    sub_440190((_DWORD *)a1, (TESObjectCELL *)a2); /*0x44584e*/
    if ( !v22 ) /*0x445855*/
      sub_434020(ioManager, st5_0, a5, v21, 1); /*0x44585f*/
    if ( v23 ) /*0x445866*/
      v21 = sub_88D1D0(0); /*0x44586c*/
    if ( *(_BYTE *)(a1 + 0x51) || *(_BYTE *)(a1 + 0x52) ) /*0x445877*/
    {
      if ( !v22 ) /*0x4458a1*/
        goto LABEL_49; /*0x4458a1*/
    }
    else if ( !v22 ) /*0x44587f*/
    {
      sub_5ADB40(); /*0x445881*/
      v21 = flt_B33A48; /*0x445886*/
      sub_5732D0((NiAVObject **)dword_B3A6B0, st5_0, a5, v21, 2, flt_B33A48); /*0x445898*/
LABEL_49:
      sub_677360((int)&ActorProcessManager_ptr); /*0x4458a3*/
      sub_441610((_DWORD *)a1); /*0x4458af*/
      sub_678750(&ActorProcessManager_ptr); /*0x4458b9*/
      sub_675F40((int)&ActorProcessManager_ptr); /*0x4458c3*/
      sub_675FC0((int)&ActorProcessManager_ptr, v21); /*0x4458cd*/
    }
    sub_43FC20((TES *)a1, 0); /*0x4458d2*/
    sub_447130((char *)TESDataHandler); /*0x4458e1*/
    v27 = sub_4D58B0((int)a2); /*0x4458ed*/
    NiAVObject_InitializePropertyState(v27); /*0x4458f1*/
    NiNode_UpdateDynamicEffectState((NiNode *)v27); /*0x4458f8*/
    if ( !LOWORD(v27[1].members.super.m_controller) ) /*0x4458fd*/
    {
      v21 = 0.0; /*0x445907*/
      NiAVObject_UpdateNiAVObject(v27, 0.0, 0); /*0x445911*/
    }
    sub_4CB670(a2, 1); /*0x44591a*/
    if ( (LOBYTE(a2->member.rot.y) & 2) != 0 ) /*0x445928*/
    {
      if ( *(_DWORD *)(a1 + 0x54) ) /*0x44592a*/
        sub_498F30(); /*0x445931*/
      sub_49A000(*(_DWORD **)(a1 + 0x58), (TESObjectCELL *)a2); /*0x44593a*/
      if ( TES->currentInteriorCell ) /*0x445945*/
      {
        v28 = *(_DWORD **)(a1 + 0x58); /*0x44594b*/
        if ( v28 ) /*0x445950*/
          sub_49B5F0(v28, *(_DWORD *)(a1 + 0x20), *(_DWORD *)(a1 + 0x24)); /*0x44595a*/
      }
    }
    else
    {
      v29 = *(_DWORD **)(a1 + 0x58); /*0x445961*/
      if ( v29 ) /*0x445966*/
        sub_499FF0(v29); /*0x445968*/
      v30 = *(WaterManager **)(a1 + 0x54); /*0x44596d*/
      if ( v30 ) /*0x445972*/
        WaterManager::Destroy_(v30, st5_0, a5, v21, (int *)1); /*0x445976*/
    }
    sub_43FD70((TES *)a1, st5_0, a5, v21, (TESObjectCELL *)a2); /*0x44597e*/
  }
  if ( !a2a ) /*0x445989*/
  {
    v31 = InitBSShaderAccumulator(); /*0x44598b*/
    if ( v31 ) /*0x445992*/
      sub_7A9CF0(v31); /*0x445996*/
    nullsub_returnTrue_0arg(); /*0x44599d*/
    sub_7C4D90(); /*0x4459a2*/
    sub_7B2130(1); /*0x4459a9*/
    nullsub_returnTrue_0arg(); /*0x4459b0*/
    sub_482670(*(_DWORD **)(a1 + 8)); /*0x4459bb*/
  }
  if ( *(_BYTE *)(a1 + 0x51) || *(_BYTE *)(a1 + 0x52) ) /*0x4459c6*/
  {
    sub_578E30(st5_0, a5, (char)a2); /*0x4459cc*/
    sub_5A9010((char)a2, st5_0, a5); /*0x4459d1*/
    sound = OSGlobals->sound; /*0x4459db*/
    if ( sound ) /*0x4459e0*/
      sub_6A9AA0(sound); /*0x4459e2*/
  }
  sub_43FC20((TES *)a1, 0); /*0x4459eb*/
  Player_UpdateHUDHealthBarTarget_(0); /*0x4459f2*/
  byte_B43384 = 0; /*0x4459fc*/
}
