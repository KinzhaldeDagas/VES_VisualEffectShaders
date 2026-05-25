// 0x765480 @ 0x765480
int __thiscall sub_765480(NiDX9Renderer *this, float *a2, char a3)
{
  D3DXMATRIX *p_worldMatrix; // ebx
  float *v5; // eax
  float *v6; // eax
  int result; // eax
  float v8[3]; // [esp+20h] [ebp-30h] BYREF
  int v9[9]; // [esp+2Ch] [ebp-24h] BYREF

  p_worldMatrix = &this->member.worldMatrix; /*0x765497*/
  sub_761AE0((float *)&this->member.worldMatrix, a2, a2 + 9, a2[0xC]); /*0x76549f*/
  if ( a3 ) /*0x7654ac*/
    this->member.device->lpVtbl->SetTransform( /*0x7654c3*/
      this->member.device,
      (D3DTRANSFORMSTATETYPE)0x100,
      (const D3DMATRIX *)p_worldMatrix);
  ((void (__thiscall *)(NiDX9RenderState *, float *))this->member.renderState->vtbl->SetNormalization)( /*0x7654d1*/
    this->member.renderState,
    a2);
  sub_710190(a2, (float *)v9, a2[0xC]); /*0x7654e1*/
  v5 = sub_710250(v8, (float *)&this->member.pad624[5], (float *)v9); /*0x7654f7*/
  this->member.pad624[0xB] = *(UInt32 *)v5; /*0x7654fe*/
  this->member.pad624[0xC] = (UInt32)v5[1]; /*0x765507*/
  this->member.camRight.x = v5[2]; /*0x76551b*/
  v6 = sub_710250(v8, (float *)&this->member.pad624[8], (float *)v9); /*0x765527*/
  this->member.camRight.y = *v6; /*0x76552e*/
  this->member.camRight.z = v6[1]; /*0x76553a*/
  result = *((_DWORD *)v6 + 2); /*0x765540*/
  LODWORD(this->member.camUp.x) = result; /*0x765544*/
  return result; /*0x765543*/
}
