// 0x780D80 @ 0x780D80
NiD3DShaderProgram *__thiscall sub_780D80(NiD3DShaderProgram *this, int a2)
{
  NiD3DShaderProgram::NiD3DShaderProgram(this, a2); /*0x780d88*/
  *((_BYTE *)this + 0x28) = 0; /*0x780d8f*/
  *((_DWORD *)this + 0xB) = 0; /*0x780d92*/
  *((_DWORD *)this + 0xC) = 0; /*0x780d95*/
  *((_DWORD *)this + 0xD) = 0; /*0x780d98*/
  *(_DWORD *)this = &NiD3DVertexShader::`vftable'; /*0x780d9b*/
  return this; /*0x780da3*/
}
