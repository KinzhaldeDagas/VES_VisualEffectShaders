// 0x77B7B0 @ 0x77B7B0
// MoonSugarEffect decode: NiDX9RenderState full Reset. Reinitializes render-state caches, clears pixel/vertex shader and texture caches, resets helper state, then writes default D3D render states through cached setters.
int __thiscall Reset(NiDX9RenderState *this)
{
  double v2; // rt0
  int result; // eax

  ((void (__thiscall *)(NiDX9RenderState *))this->vtbl->InitializeRenderStates)(this); /*0x77b7bb*/
  ((void (__thiscall *)(NiDX9RenderState *))this->vtbl->ClearPixelShaders)(this); /*0x77b7c4*/
  ((void (__thiscall *)(NiDX9RenderState *))this->vtbl->func_02E)(this); /*0x77b7d0*/
  ((void (__thiscall *)(NiDX9RenderState *))this->vtbl->ClearTextureList)(this); /*0x77b7dc*/
  sub_780A20(this->member.unk0F8); /*0x77b7e4*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x16, 2, 0); /*0x77b7f6*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 8, 3, 0); /*0x77b805*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 9, 2, 0); /*0x77b814*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x1B, 0, 0); /*0x77b823*/
  ((void (__thiscall *)(NiDX9RenderState *, int, UInt32, _DWORD))this->vtbl->SetRenderState)( /*0x77b834*/
    this,
    0x13,
    this->member.unk000C[0xB],
    0);
  ((void (__thiscall *)(NiDX9RenderState *, int, UInt32, _DWORD))this->vtbl->SetRenderState)( /*0x77b845*/
    this,
    0x14,
    this->member.unk000C[0xC],
    0);
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0xF, 0, 0); /*0x77b854*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x19, 8, 0); /*0x77b863*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x18, 0, 0); /*0x77b872*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x17, 8, 0); /*0x77b881*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0xE, 0, 0); /*0x77b890*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x1A, 0, 0); /*0x77b89f*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x1D, 0, 0); /*0x77b8ae*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x1C, 0, 0); /*0x77b8bd*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(
    this,
    0x23,
    (this->member.Flags & 1) != 0 ? 3 : 0,
    0);
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x8C, 3, 0); /*0x77b8ea*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x30, 0, 0); /*0x77b8f9*/
  ((void (__thiscall *)(NiDX9RenderState *, int, _DWORD, _DWORD))this->vtbl->SetRenderState)(this, 0x22, 0, 0); /*0x77b908*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x8F, 1, 0); /*0x77b91a*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 7, 1, 0); /*0x77b929*/
  ((void (__thiscall *)(NiDX9RenderState *, int, int, _DWORD))this->vtbl->SetRenderState)(this, 0x8D, 1, 0); /*0x77b93b*/
  LODWORD(this->member.CurrentFogColor.r) = dword_B3FA90; /*0x77b946*/
  LODWORD(this->member.CurrentFogColor.g) = dword_B3FA94; /*0x77b957*/
  LODWORD(this->member.CurrentFogColor.b) = dword_B3FA98; /*0x77b96c*/
  v2 = dbl_A3DDD8; /*0x77b984*/
  result = (unsigned __int8)(int)(v2 * this->member.CurrentFogColor.b); /*0x77b9f6*/
  this->member.unk098[0] = result /*0x77b9ff*/
                         | (((unsigned __int8)(int)(this->member.CurrentFogColor.g * v2)
                           | (((int)(this->member.CurrentFogColor.r * v2) | 0xFFFFFF00) << 8)) << 8);
  return result; /*0x77ba05*/
}
