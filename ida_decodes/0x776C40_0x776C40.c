// 0x776C40 @ 0x776C40
char __stdcall NiGeometryBufferData::RefreshVBChips(NiGeometryBufferData *a1, UInt32 a2)
{
  NiGeometryGroup *GeometryGroup; // esi
  NiVBChip *v3; // eax

  GeometryGroup = a1->GeometryGroup; /*0x776c4b*/
  GeometryGroup->vtbl->ReleaseChip(GeometryGroup, a1, a2); /*0x776c57*/
  v3 = GeometryGroup->vtbl->CreateChip(GeometryGroup, a1, a2); /*0x776c62*/
  if ( !v3 ) /*0x776c66*/
    return 0; /*0x776c7d*/
  if ( a2 < a1->StreamCount ) /*0x776c6b*/
    a1->VBChip[a2] = v3; /*0x776c70*/
  return 1; /*0x776c73*/
}
