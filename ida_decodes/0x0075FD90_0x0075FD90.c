// 0x0075FD90 @ 0x0075FD90
// MoonSugarEffect decode: NiD3DPass apply-to-render. Reads vertex wrapper vtable +0x50 (wrapper byte +0x28) to set software VP, applies render states, applies each texture stage through sub_772400, and disables remaining stages.
UInt8 __thiscall NiD3DPAss::ApplyPassToRender(
        NiD3DPass *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  NiD3DVertexShader *VertexShader; // ecx
  UInt8 v11; // bp
  void (__thiscall **p_SetSoftwareVertexProcessing)(NiDX9RenderState, UInt8); // esi
  int v13; // eax
  NiD3DRenderStateGroup *RenderStateGroup; // ecx
  unsigned int end; // ebx
  unsigned int i; // esi
  NiD3DTextureStage *v17; // ecx

  VertexShader = this->VertexShader; /*0x75fd95*/
  v11 = 0; /*0x75fd98*/
  if ( VertexShader ) /*0x75fd9c*/
  {
    p_SetSoftwareVertexProcessing = &renderStateG->vtbl->SetSoftwareVertexProcessing; /*0x75fdaa*/
    v13 = (*(int (__thiscall **)(NiD3DVertexShader *))(*(_DWORD *)VertexShader + 0x50))(VertexShader); /*0x75fdb0*/
    ((void (__thiscall *)(NiDX9RenderState *, int))*p_SetSoftwareVertexProcessing)(renderStateG, v13); /*0x75fdbb*/
  }
  else
  {
    ((void (__stdcall *)(_DWORD))renderStateG->vtbl->SetSoftwareVertexProcessing)(this->SoftwareVP); /*0x75fdd2*/
  }
  RenderStateGroup = this->RenderStateGroup; /*0x75fdd4*/
  if ( RenderStateGroup ) /*0x75fdd9*/
    NiD3DRenderStateGroup::SetRenderStates(RenderStateGroup); /*0x75fddb*/
  end = this->Stages.end; /*0x75fde1*/
  for ( i = 0; i < end; v11 = sub_772400(v17) ) /*0x75fde1*/
  {
    v17 = (NiD3DTextureStage *)*(&this->Stages.data->Stage + i); /*0x75fdf3*/
    if ( !v17 ) /*0x75fdf8*/
      break; /*0x75fdf8*/
    ++i; /*0x75fdff*/
  }
  if ( i < dword_B28CB8 ) /*0x75fe10*/
    sub_771790(i); /*0x75fe13*/
  return v11; /*0x75fe1b*/
}
