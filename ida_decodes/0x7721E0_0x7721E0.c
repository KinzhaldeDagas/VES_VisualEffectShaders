// 0x7721E0 @ 0x7721E0
// MoonSugarEffect decode: applies a NiD3DTextureStage. Resolves NiTexture/NiRenderedTexture through NiDX9TextureManager, calls render state SetTexture(stage, resolved D3D texture), then applies sampler/texture-stage state.
char __thiscall sub_7721E0(NiD3DTextureStage *a1)
{
  _DWORD *v2; // ecx
  bool v3; // zf
  UInt32 Stage; // eax
  NiTexture *Texture; // eax
  int v6; // edi
  char result; // al
  _BYTE v8[2]; // [esp+32h] [ebp-Ah] BYREF
  UInt32 v9; // [esp+34h] [ebp-8h] BYREF
  int v10; // [esp+38h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+3Ch] [ebp+0h] BYREF

  v2 = *((_DWORD **)a1 + 3); /*0x7721f0*/
  v9 = 0; /*0x7721f5*/
  v8[0] = 0; /*0x7721fd*/
  v3 = sub_7730A0(v2, 0xB, &v9, v8) == 0; /*0x772207*/
  Stage = v9; /*0x772209*/
  if ( v3 ) /*0x77220d*/
    Stage = a1->Stage; /*0x77220f*/
  ((void (__thiscall *)(NiDX9RenderState *, UInt32, D3DTEXTURESTAGESTATETYPE, int, UInt8))dword_B42758->vtbl->SetTextureStageState)( /*0x772228*/
    dword_B42758,
    a1->Stage,
    D3DTSS_TEXCOORDINDEX,
    Stage,
    0);
  Texture = a1->Texture; /*0x77222a*/
  v6 = 0; /*0x77222d*/
  if ( Texture ) /*0x772231*/
    v6 = (*(int (__thiscall **)(NiDX9TextureManager *, NiTexture *, char *, char *, _UNKNOWN **))(*(_DWORD *)dword_B42754->member.textureMgr /*0x772256*/
                                                                                                + 8))(
           dword_B42754->member.textureMgr,
           Texture,
           (char *)&v9 + 2,
           (char *)&v9 + 3,
           &retaddr);
  result = ((int (__thiscall *)(NiDX9RenderState *, UInt32))dword_B42758->vtbl->SetTexture)(dword_B42758, a1->Stage); /*0x77226a*/
  if ( v6 ) /*0x77226f*/
  {
    if ( !v8[1] ) /*0x772276*/
      ((void (__thiscall *)(NiDX9RenderState *, UInt32, int, _DWORD, _DWORD))dword_B42758->vtbl->SetSamplerState)( /*0x77228f*/
        dword_B42758,
        a1->Stage,
        7,
        0,
        0);
    sub_7716E0(a1, v10); /*0x772298*/
    return sub_772150(a1); /*0x77229f*/
  }
  return result; /*0x7722a4*/
}
