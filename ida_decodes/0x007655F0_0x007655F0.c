// 0x007655F0 @ 0x007655F0
// MoonSugarEffect decode: NiDX9Renderer::CalculateBoneMatrixes. Rebuilds NiSkinInstance cached bone matrix arrays when the root/format changes, computes skin-to-world/bone transforms relative to camera-world translation, and records non-uniform-scale state. This is skinned setup evidence only; the current skinned post-setup hook boundary is 0x007676F9.
void *__thiscall NiDX9Renderer::CalculateBoneMatrixes(
        NiDX9Renderer *this,
        NiSkinInstance *a2,
        NiTransform *a3,
        char a4,
        int a5,
        char a6)
{
  void *v7; // edi
  void *result; // eax
  void *NiNode; // eax
  unsigned int v10; // ecx
  int v11; // edx
  unsigned int v12; // ebx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  double v16; // st7
  float *v17; // eax
  double v18; // st6
  unsigned int v19; // ecx
  double v20; // rt0
  double v21; // rt1
  double v22; // st6
  double v23; // st7
  NiTransform *v24; // eax
  bool v25; // c0
  float *v26; // eax
  int v27; // esi
  NiTransform *v28; // eax
  unsigned int v29; // ebp
  float *v30; // edi
  float *v31; // ebx
  int v32; // ecx
  double scale; // st7
  int v34; // [esp+14h] [ebp-E8h]
  NiTransform *v35; // [esp+14h] [ebp-E8h]
  int v36; // [esp+18h] [ebp-E4h]
  float *v37; // [esp+18h] [ebp-E4h]
  bool v38; // [esp+1Ch] [ebp-E0h]
  unsigned int v39; // [esp+20h] [ebp-DCh]
  int v40; // [esp+24h] [ebp-D8h]
  NiTransform v42; // [esp+2Ch] [ebp-D0h] BYREF
  NiTransform v43; // [esp+60h] [ebp-9Ch] BYREF
  NiTransform v44; // [esp+94h] [ebp-68h] BYREF
  NiTransform v45; // [esp+C8h] [ebp-34h] BYREF

  v7 = *((void **)a2 + 6); /*0x765608*/
  result = TESObjectREFR_GetNiNode((TESObjectREFR *)this->member.vertexBufferMgr); /*0x76560f*/
  if ( v7 != result ) /*0x765616*/
  {
    NiNode = TESObjectREFR_GetNiNode((TESObjectREFR *)this->member.vertexBufferMgr); /*0x765623*/
    v10 = *((_DWORD *)a2 + 8); /*0x765632*/
    v11 = *((_DWORD *)a2 + 9); /*0x765635*/
    *((_DWORD *)a2 + 6) = NiNode; /*0x765638*/
    v12 = *(_DWORD *)(*((_DWORD *)a2 + 2) + 0x40); /*0x76563e*/
    v36 = *((_DWORD *)a2 + 2); /*0x765641*/
    v39 = v12; /*0x765648*/
    v34 = v10; /*0x76564c*/
    if ( a5 == 3 ) /*0x765650*/
      a4 = 1; /*0x765652*/
    if ( v12 > *((_DWORD *)a2 + 7) || a5 != v11 ) /*0x765660*/
    {
      FormHeapFree(v10); /*0x765667*/
      v13 = 0; /*0x76566f*/
      if ( a5 == 4 ) /*0x765674*/
      {
        LOBYTE(v13) = (unsigned __int64)v12 >> 0x1A != 0; /*0x76567f*/
        v14 = FormHeapAlloc((v12 << 6) | -v13); /*0x765687*/
        v15 = v14; /*0x765691*/
        v34 = v14; /*0x765693*/
        if ( v12 ) /*0x765697*/
        {
          v16 = 1.0; /*0x765699*/
          v17 = (float *)(v14 + 0x34); /*0x76569b*/
          v18 = 0.0; /*0x76569e*/
          v19 = v12; /*0x7656a0*/
          while ( 1 ) /*0x7656d4*/
          {
            if ( a4 ) /*0x7656d4*/
            {
              v17[1] = v18; /*0x7656d6*/
              *v17 = v18; /*0x7656d9*/
              v17[0xFFFFFFFF] = v18; /*0x7656db*/
            }
            else
            {
              v17[0xFFFFFFFE] = v18; /*0x7656e0*/
              v17[0xFFFFFFFA] = v18; /*0x7656e3*/
              v17[0xFFFFFFF6] = v18; /*0x7656e6*/
            }
            v21 = v18; /*0x7656e9*/
            v22 = v16; /*0x7656e9*/
            v23 = v21; /*0x7656e9*/
            v17 += 0x10; /*0x7656eb*/
            --v19; /*0x7656ee*/
            v17[0xFFFFFFF2] = v22; /*0x7656f1*/
            if ( !v19 ) /*0x7656f4*/
              break; /*0x7656f4*/
            v20 = v22; /*0x7656ca*/
            v18 = v23; /*0x7656ca*/
            v16 = v20; /*0x7656ca*/
          }
        }
      }
      else
      {
        LOBYTE(v13) = (unsigned __int64)(0xC * v12) >> 0x1E != 0; /*0x7656b2*/
        v34 = FormHeapAlloc((0x30 * v12) | -v13); /*0x7656c2*/
        v15 = v34; /*0x7656c6*/
      }
      *((_DWORD *)a2 + 7) = v12; /*0x7656fa*/
      *((_DWORD *)a2 + 9) = a5; /*0x7656fd*/
      *((_DWORD *)a2 + 8) = v15; /*0x765700*/
    }
    sub_718A80((float *)(*((_DWORD *)a2 + 4) + 0x64), &v42); /*0x76570e*/
    qmemcpy(&v44, sub_53D7A0((NiTransform *)(*((_DWORD *)a2 + 2) + 0xC), &v45, &v42), sizeof(v44)); /*0x765739*/
    v24 = sub_53D7A0(a3, &v45, &v44); /*0x765752*/
    v25 = v44.scale < dbl_A88D40; /*0x765765*/
    qmemcpy(&v43, v24, sizeof(v43)); /*0x76576f*/
    v38 = 0; /*0x765776*/
    if ( v25 ) /*0x76577b*/
      v38 = v44.scale > (double)flt_A88D38; /*0x76578a*/
    if ( a6 ) /*0x76579b*/
    {
      v26 = *((float **)a2 + 0xA); /*0x76579d*/
      if ( !v26 ) /*0x7657a2*/
      {
        v26 = (float *)FormHeapAlloc(0x40u); /*0x7657a6*/
        *((_DWORD *)a2 + 0xA) = v26; /*0x7657ad*/
        v26[3] = 0.0; /*0x7657b0*/
        v26[7] = 0.0; /*0x7657b3*/
        v26[0xB] = 0.0; /*0x7657b9*/
        v26[0xF] = 1.0; /*0x7657be*/
      }
      sub_761BE0(v26, (float *)&v43, &v43.pos.x, v43.scale); /*0x7657da*/
    }
    v27 = *((_DWORD *)a2 + 5); /*0x7657e2*/
    v28 = *(NiTransform **)(v36 + 0x44); /*0x7657e9*/
    v29 = 0; /*0x7657ec*/
    v40 = v27; /*0x7657f0*/
    if ( v12 ) /*0x7657f4*/
    {
      v30 = (float *)v34; /*0x7657fe*/
      v37 = (float *)v34; /*0x765800*/
      v35 = v28; /*0x765804*/
      v31 = v37 + 8; /*0x765808*/
      do /*0x765964*/
      {
        sub_53D7A0((NiTransform *)(*(_DWORD *)(v27 + 4 * v29) + 0x64), &v42, v35); /*0x765820*/
        v32 = *(_DWORD *)(v27 + 4 * v29); /*0x765825*/
        if ( *(float *)(v32 + 0x94) < dbl_A88D40 && flt_A88D38 < (double)*(float *)(v32 + 0x94) ) /*0x76584c*/
          v38 = 1; /*0x76584e*/
        if ( !a6 ) /*0x76585b*/
        {
          qmemcpy(&v42, sub_53D7A0(&v43, &v45, &v42), sizeof(v42)); /*0x76587e*/
          v30 = v37; /*0x765880*/
          v27 = v40; /*0x765884*/
        }
        if ( a5 == 4 ) /*0x765890*/
        {
          if ( a4 ) /*0x7658a2*/
            sub_761B60(v30, (float *)&v42, &v42.pos.x, v42.scale); /*0x7658af*/
          else
            sub_761AE0(v30, (float *)&v42, &v42.pos.x, v42.scale); /*0x7658c7*/
        }
        else
        {
          scale = v42.scale; /*0x7658dd*/
          v31[0xFFFFFFF8] = v42.rot.data[0][0] * v42.scale; /*0x7658df*/
          v31[0xFFFFFFFC] = v42.rot.data[1][0] * scale; /*0x7658e8*/
          *v31 = v42.rot.data[2][0] * scale; /*0x7658f1*/
          v31[0xFFFFFFF9] = v42.rot.data[0][1] * scale; /*0x7658f9*/
          v31[0xFFFFFFFD] = v42.rot.data[1][1] * scale; /*0x765902*/
          v31[1] = v42.rot.data[2][1] * scale; /*0x76590b*/
          v31[0xFFFFFFFA] = v42.rot.data[0][2] * scale; /*0x765914*/
          v31[0xFFFFFFFE] = v42.rot.data[1][2] * scale; /*0x76591d*/
          v31[2] = scale * v42.rot.data[2][2]; /*0x765924*/
          v31[0xFFFFFFFB] = v42.pos.x - CameraWorldTranslate; /*0x765931*/
          v31[0xFFFFFFFF] = v42.pos.y - flt_B3F930; /*0x76593e*/
          v31[3] = v42.pos.z - flt_B3F934; /*0x76594b*/
        }
        v35 = (NiTransform *)((char *)v35 + 0x4C); /*0x76594e*/
        ++v29; /*0x765953*/
        v30 += 0x10; /*0x765956*/
        v31 += 0xC; /*0x765959*/
        v37 = v30; /*0x765960*/
      }
      while ( v29 < v39 ); /*0x765964*/
    }
    return (void *)((int (__thiscall *)(NiDX9RenderState *, bool))this->member.renderState->vtbl->SetVar_0FF5)( /*0x765981*/
                     this->member.renderState,
                     v38);
  }
  return result; /*0x765984*/
}
