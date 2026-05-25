// 0x800110 @ 0x800110
// MoonSugarEffect decode: RefractionShader dtor releases programs/pass/extra texture, returns global dword_B474AC to texture manager, then calls BSImageSpaceShader dtor.
void __thiscall RefractionShader::~RefractionShader(RefractionShader *this)
{
  NiD3DVertexShader *v2; // edi
  NiD3DPixelShader *v3; // edi
  NiD3DPass *v4; // ecx
  UInt32 v6; // edi
  UInt32 v7; // edi
  UInt32 v8; // edi

  this->super.__vftable = (BSImageSpaceShaderVtbl *)&RefractionShader::`vftable'; /*0x80013b*/
  v2 = this->Vertex[0]; /*0x800141*/
  if ( v2 ) /*0x800151*/
  {
    if ( !InterlockedDecrement((volatile LONG *)v2 + 1) ) /*0x800157*/
      (**(void (__thiscall ***)(NiD3DVertexShader *, int))v2)(v2, 1); /*0x80016d*/
    this->Vertex[0] = 0; /*0x80016f*/
  }
  v3 = this->Pixel[0]; /*0x800179*/
  if ( v3 ) /*0x800187*/
  {
    if ( !InterlockedDecrement((volatile LONG *)v3 + 1) ) /*0x80018d*/
      (**(void (__thiscall ***)(NiD3DPixelShader *, int))v3)(v3, 1); /*0x8001a3*/
    this->Pixel[0] = 0; /*0x8001a5*/
  }
  v4 = (NiD3DPass *)this->Unk90[1]; /*0x8001ab*/
  if ( v4 ) /*0x8001b9*/
  {
    if ( v4->RefCount-- == 1 ) /*0x8001bb*/
      sub_7604D0(v4); /*0x8001c1*/
    this->Unk90[1] = 0; /*0x8001c6*/
  }
  v6 = this->Unk90[2]; /*0x8001cd*/
  if ( v6 ) /*0x8001d5*/
  {
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) ) /*0x8001db*/
      (**(void (__thiscall ***)(UInt32, int))v6)(v6, 1); /*0x8001f1*/
    this->Unk90[2] = 0; /*0x8001f3*/
  }
  if ( dword_B474AC ) /*0x8001fd*/
  {
    sub_7C1EE0(g_textureManager, (BSRenderedTexture *)dword_B474AC); /*0x80020d*/
    v7 = dword_B474AC; /*0x800212*/
    if ( dword_B474AC ) /*0x800212*/
    {
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) ) /*0x800220*/
      {
        if ( v7 ) /*0x80022c*/
          (**(void (__thiscall ***)(UInt32, int))v7)(v7, 1); /*0x800236*/
      }
      dword_B474AC = 0; /*0x800238*/
    }
  }
  v8 = this->Unk90[2]; /*0x800242*/
  if ( v8 ) /*0x80024f*/
  {
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) ) /*0x800255*/
      (**(void (__thiscall ***)(UInt32, int))v8)(v8, 1); /*0x80026b*/
  }
  _LN21(&this->Unk90[1], 4u, 1, (void (__thiscall *)(void *))sub_4027D0); /*0x80027c*/
  _LN21(this->Pixel, 4u, 1, (void (__thiscall *)(void *))sub_7016A0); /*0x800290*/
  _LN21(this->Vertex, 4u, 1, (void (__thiscall *)(void *))sub_7016A0); /*0x8002aa*/
  BSImageSpaceShader::~BSImageSpaceShader(&this->super); /*0x8002b9*/
}
