// 0x77B210 @ 0x77B210
// MoonSugarEffect decode: clears NiDX9RenderState cached texture list slots without issuing D3D SetTexture calls.
int __thiscall ClearTextureList(NiDX9RenderState *this)
{
  this->member.unk0FA0[0] = 0; /*0x77b212*/
  this->member.unk0FA0[1] = 0; /*0x77b218*/
  this->member.unk0FA0[2] = 0; /*0x77b21e*/
  this->member.unk0FA0[3] = 0; /*0x77b224*/
  this->member.unk0FA0[4] = 0; /*0x77b22a*/
  this->member.unk0FA0[5] = 0; /*0x77b230*/
  this->member.unk0FA0[6] = 0; /*0x77b236*/
  this->member.unk0FA0[7] = 0; /*0x77b23c*/
  this->member.unk0FA0[8] = 0; /*0x77b242*/
  this->member.unk0FA0[9] = 0; /*0x77b248*/
  this->member.unk0FA0[0xA] = 0; /*0x77b24e*/
  this->member.unk0FA0[0xB] = 0; /*0x77b254*/
  this->member.unk0FA0[0xC] = 0; /*0x77b25a*/
  this->member.unk0FA0[0xD] = 0; /*0x77b260*/
  this->member.unk0FA0[0xE] = 0; /*0x77b266*/
  this->member.unk0FA0[0xF] = 0; /*0x77b26c*/
  return 0; /*0x77b272*/
}
