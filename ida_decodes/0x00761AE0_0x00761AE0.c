// 0x00761AE0 @ 0x00761AE0
// MoonSugarEffect decode: builds a camera-relative D3D world matrix from NiTransform using column/row layout used for non-skinned world constants; translation subtracts CameraWorldTranslate/flt_B3F930/flt_B3F934.
float *__cdecl sub_761AE0(float *a1, float *a2, float *a3, float a4)
{
  *a1 = *a2 * a4; /*0x761af4*/
  a1[1] = a2[3] * a4; /*0x761afb*/
  a1[2] = a2[6] * a4; /*0x761b03*/
  a1[4] = a2[1] * a4; /*0x761b0b*/
  a1[5] = a2[4] * a4; /*0x761b13*/
  a1[6] = a2[7] * a4; /*0x761b1b*/
  a1[8] = a2[2] * a4; /*0x761b23*/
  a1[9] = a2[5] * a4; /*0x761b2b*/
  a1[0xA] = a4 * a2[8]; /*0x761b35*/
  a1[0xC] = *a3 - CameraWorldTranslate; /*0x761b40*/
  a1[0xD] = a3[1] - flt_B3F930; /*0x761b4c*/
  a1[0xE] = a3[2] - flt_B3F934; /*0x761b58*/
  return a1; /*0x761b5b*/
}
