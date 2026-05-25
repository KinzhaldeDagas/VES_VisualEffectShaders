// 0x00767410 @ 0x00767410
// MoonSugarEffect build 19: runtime build 18 showed objectVS hook hot but inactive dump prevented pass census. Implementation now samples CurrentPass family at the post-setup draw window before the active-effect gate, then only applies replacement after active/whitelist checks.
int __thiscall sub_7672F0(
        NiDX9Renderer *this,
        NiGeometry *a2,
        NiGeometryData *a3,
        _DWORD *a4,
        float *a5,
        UInt32 a6,
        NiGeometryBufferData *a7)
{
  NiGeometry *v7; // ebp
  NiD3DShader *defaultShader; // ebx
  NiGeometryBufferData *v10; // esi
  int result; // eax
  UInt16 *ArrayLengths; // eax
  UINT TriCount; // ebp
  bool v14; // cf
  int v15; // [esp+C4h] [ebp-4h]
  NiGeometryBufferData *v16; // [esp+E0h] [ebp+18h]

  v7 = a2; /*0x7672f3*/
  if ( !a2 || (defaultShader = (NiD3DShader *)NiRTTI_Cast(&NiD3DShaderInterfaceString, a2->member.shader)) == 0 ) /*0x767317*/
    defaultShader = this->member.defaultShader; /*0x767319*/
  v10 = a7; /*0x767327*/
  result = defaultShader->__vftable->Unk28( /*0x767343*/
             (NiD3DShaderInterface *)defaultShader,
             (int)a2,
             (int)a4,
             (int)a7,
             (int)this->member.super.propertyState,
             (unsigned int)this->member.super.dynamicEffectState,
             (int)a5,
             a6);
  if ( !result ) /*0x767347*/
  {
    defaultShader->__vftable->Unk2C( /*0x76736d*/
      (NiD3DShaderInterface *)defaultShader,
      (UInt32)a2,
      (UInt32)a4,
      (UInt32)a7,
      (UInt32)this->member.super.propertyState,
      (UInt32)this->member.super.dynamicEffectState,
      (UInt32)a5,
      a6);
    if ( defaultShader->__vftable->Unk48((NiD3DShaderInterface *)defaultShader) ) /*0x767376*/
    {
      do /*0x7674ce*/
      {
        defaultShader->__vftable->Unk30( /*0x7673a0*/
          (NiD3DShaderInterface *)defaultShader,
          (int)v7,
          (int)a4,
          (int)v10,
          (int)this->member.super.propertyState,
          (int)this->member.super.dynamicEffectState,
          (int)a5,
          a6);
        defaultShader->__vftable->Unk34( /*0x7673c4*/
          (NiD3DShaderInterface *)defaultShader,
          (int)v7,
          a4,
          0,
          (int)v10,
          (int)this->member.super.propertyState,
          (int)this->member.super.dynamicEffectState,
          a5,
          a6);
        v10 = (NiGeometryBufferData *)defaultShader->__vftable->Unk3C( /*0x7673ed*/
                                        (NiD3DShaderInterface *)defaultShader,
                                        (UInt32)v7,
                                        0,
                                        (UInt32)v10,
                                        (UInt32)this->member.super.propertyState);
        defaultShader->__vftable->SetupShaderPrograms( /*0x7673fb*/
          (NiD3DShaderInterface *)defaultShader,
          (int)v7,
          a4,
          0,
          (int)v10,
          (int)this->member.super.propertyState,
          (int)this->member.super.dynamicEffectState,
          a5,
          a6);
        (*(void (__thiscall **)(NiDX9ShaderConstantManager *))(*(_DWORD *)this->member.renderState->member.ShaderConstantManager /*0x76740e*/
                                                             + 4))(this->member.renderState->member.ShaderConstantManager);
        if ( v10->IB )                          // MoonSugarEffect build 32: post-flush direct D3D vertex override now covers primary Lighting30 SM3 no-skin/skinned vertex contracts with normal or low-light matching pixel routes, while preserving native PS, texture, constant-map, and render-state ownership. /*0x767412*/
        {
          v16 = 0; /*0x76741a*/
          v15 = 0; /*0x76741e*/
          if ( v10->NumArrays ) /*0x767417*/
          {
            do /*0x76747e*/
            {
              ArrayLengths = v10->ArrayLengths; /*0x767428*/
              if ( ArrayLengths ) /*0x76742d*/
                TriCount = ArrayLengths[v15] - 2; /*0x767437*/
              else
                TriCount = v10->TriCount; /*0x76743c*/
              this->member.device->lpVtbl->DrawIndexedPrimitive( /*0x767462*/
                this->member.device,
                v10->PrimitiveType,
                v10->BaseVertexIndex,
                0,
                v10->VertCount,
                (UINT)v16,
                TriCount);
              v14 = v15 + 1 < v10->NumArrays; /*0x767473*/
              v16 = (NiGeometryBufferData *)((char *)v16 + TriCount + 2); /*0x767476*/
              ++v15; /*0x76747a*/
            }
            while ( v14 ); /*0x76747e*/
            v7 = a2; /*0x767480*/
          }
        }
        else
        {
          this->member.device->lpVtbl->DrawPrimitive( /*0x7674a1*/
            this->member.device,
            v10->PrimitiveType,
            v10->BaseVertexIndex,
            v10->TriCount);
        }
        defaultShader->__vftable->Unk40( /*0x7674c5*/
          (NiD3DShaderInterface *)defaultShader,
          (UInt32)v7,
          (UInt32)a4,
          0,
          (UInt32)v10,
          (UInt32)this->member.super.propertyState,
          (UInt32)this->member.super.dynamicEffectState,
          (UInt32)a5,
          a6);
      }
      while ( defaultShader->__vftable->Unk4C((NiD3DShaderInterface *)defaultShader) ); /*0x7674ce*/
    }
    defaultShader->__vftable->Unk44( /*0x7674f8*/
      (NiD3DShaderInterface *)defaultShader,
      (UInt32)v7,
      (UInt32)a4,
      (UInt32)v10,
      (UInt32)this->member.super.propertyState,
      (UInt32)this->member.super.dynamicEffectState,
      (UInt32)a5,
      a6);
    return ((int (__thiscall *)(NiDX9RenderState *, _DWORD))this->member.renderState->vtbl->SetVar_0FF5)( /*0x76750c*/
             this->member.renderState,
             0);
  }
  return result; /*0x76750e*/
}
