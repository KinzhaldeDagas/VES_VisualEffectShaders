// 0x7F54F0 @ 0x7F54F0
char __thiscall sub_7F54F0(NiD3DPass **this)
{
  int v2; // ebp
  NiD3DPass **v3; // edi
  NiD3DPass *v4; // ecx
  bool v5; // zf
  NiD3DPass *v6; // eax
  NiD3DPass *v7; // eax
  int v8; // eax
  NiD3DTextureStage *v9; // eax
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  NiD3DPass *v16; // [esp+10h] [ebp-14h] BYREF
  int v17; // [esp+14h] [ebp-10h]
  unsigned int v18; // [esp+20h] [ebp-4h]

  v2 = 0; /*0x7f5518*/
  v17 = 0; /*0x7f551a*/
  v18 = 0; /*0x7f5523*/
  v3 = sub_7606A0(&v16); /*0x7f552f*/
  v4 = *(this + 0x27); /*0x7f5531*/
  v5 = v4 == *v3; /*0x7f5537*/
  LOBYTE(v18) = 1; /*0x7f5539*/
  if ( !v5 ) /*0x7f553e*/
  {
    if ( v4 ) /*0x7f5542*/
    {
      v5 = v4->RefCount-- == 1; /*0x7f5544*/
      if ( v5 ) /*0x7f5548*/
        sub_7604D0(v4); /*0x7f554a*/
    }
    v6 = *v3; /*0x7f554f*/
    v5 = *v3 == 0; /*0x7f5551*/
    *(this + 0x27) = *v3; /*0x7f5553*/
    if ( !v5 ) /*0x7f5559*/
      ++v6->RefCount; /*0x7f555b*/
  }
  v7 = v16; /*0x7f555f*/
  LOBYTE(v18) = 0; /*0x7f5565*/
  if ( v16 ) /*0x7f556a*/
  {
    --v16->RefCount; /*0x7f556c*/
    if ( !v7->RefCount ) /*0x7f5575*/
      sub_7604D0(v7); /*0x7f557a*/
  }
  v8 = *sub_772630(&v16); /*0x7f558c*/
  if ( v8 ) /*0x7f5590*/
  {
    v2 = v8; /*0x7f5592*/
    ++*(_DWORD *)(v8 + 0x5C); /*0x7f5594*/
    v17 = v8; /*0x7f5598*/
  }
  v9 = (NiD3DTextureStage *)v16; /*0x7f559c*/
  LOBYTE(v18) = 0; /*0x7f55a2*/
  if ( v16 ) /*0x7f55a7*/
  {
    --*(_DWORD *)&v16->SoftwareVP; /*0x7f55a9*/
    if ( !v9[7].Unk08 ) /*0x7f55b2*/
      sub_772560(v9); /*0x7f55b7*/
  }
  sub_801110(v2, 0, 3, 2); /*0x7f55c3*/
  sub_771640((_DWORD **)v2, 0); /*0x7f55cf*/
  sub_760010(*(this + 0x27), (*(this + 0x27))->CurrentStage, (unsigned int *)v2); /*0x7f55df*/
  v10 = (int)*(this + 0x27); /*0x7f55e4*/
  if ( v10 ) /*0x7f55ec*/
  {
    if ( !*(_DWORD *)(v10 + 0x30) ) /*0x7f55f2*/
      *(_DWORD *)(v10 + 0x30) = sub_772DF0(); /*0x7f55fd*/
    sub_772CD0(*(_DWORD **)(v10 + 0x30), 7, 0, 0); /*0x7f5609*/
    v11 = (int)*(this + 0x27); /*0x7f560e*/
    if ( !*(_DWORD *)(v11 + 0x30) ) /*0x7f5614*/
      *(_DWORD *)(v11 + 0x30) = sub_772DF0(); /*0x7f561f*/
    sub_772CD0(*(_DWORD **)(v11 + 0x30), 0xE, 0, 0); /*0x7f562b*/
    v12 = (int)*(this + 0x27); /*0x7f5630*/
    if ( !*(_DWORD *)(v12 + 0x30) ) /*0x7f5636*/
      *(_DWORD *)(v12 + 0x30) = sub_772DF0(); /*0x7f5641*/
    sub_772CD0(*(_DWORD **)(v12 + 0x30), 0x1B, 0, 0); /*0x7f564d*/
    v13 = (int)*(this + 0x27); /*0x7f5652*/
    if ( !*(_DWORD *)(v13 + 0x30) ) /*0x7f5658*/
      *(_DWORD *)(v13 + 0x30) = sub_772DF0(); /*0x7f5663*/
    sub_772CD0(*(_DWORD **)(v13 + 0x30), 0xF, 0, 0); /*0x7f566f*/
    v14 = (int)*(this + 0x27); /*0x7f5674*/
    if ( !*(_DWORD *)(v14 + 0x30) ) /*0x7f567a*/
      *(_DWORD *)(v14 + 0x30) = sub_772DF0(); /*0x7f5685*/
    sub_772CD0(*(_DWORD **)(v14 + 0x30), 0xA8, 0xF, 0); /*0x7f5694*/
  }
  ((void (__thiscall *)(NiD3DPass **))(*this)[1].VertexShaderTarget)(this); /*0x7f56a3*/
  v18 = 0xFFFFFFFF; /*0x7f56aa*/
  if ( v2 ) /*0x7f56ae*/
  {
    v5 = (*(_DWORD *)(v2 + 0x5C))-- == 1; /*0x7f56b0*/
    if ( v5 ) /*0x7f56b3*/
      sub_772560((NiD3DTextureStage *)v2); /*0x7f56b7*/
  }
  return 1; /*0x7f56be*/
}
