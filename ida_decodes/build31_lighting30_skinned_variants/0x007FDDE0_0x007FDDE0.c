// 0x007FDDE0 @ 0x007FDDE0
// MoonSugarEffect build 31: SM3Lighting pixel shader family remains native. Vertex replacement is paired only when the active pixel wrapper matches the normal B46ED8 SM3Lighting program set; low-light/alternate families remain excluded until separately decoded.
NiD3DShaderProgram *sub_7FDDE0()
{
  const char *v0; // eax
  __int16 v1; // cx
  char *v2; // ebp
  char v3; // dl
  __int16 **v4; // edi
  int v5; // esi
  int v6; // eax
  _DWORD *v7; // edi
  NiD3DShaderProgram *result; // eax
  volatile LONG *v9; // ebp
  volatile LONG *v10; // edi
  NiD3DShaderProgram *v11; // ebp
  int v12; // [esp-8h] [ebp-DE4h]
  int v13; // [esp-4h] [ebp-DE0h]
  NiD3DShaderProgram *v14; // [esp+10h] [ebp-DCCh]
  __int16 **i; // [esp+18h] [ebp-DC4h]
  __int16 v16; // [esp+1Ch] [ebp-DC0h] BYREF
  char v17; // [esp+1Eh] [ebp-DBEh]
  __int16 v18; // [esp+20h] [ebp-DBCh] BYREF
  char v19; // [esp+22h] [ebp-DBAh]
  __int16 v20; // [esp+24h] [ebp-DB8h] BYREF
  char v21; // [esp+26h] [ebp-DB6h]
  __int16 v22; // [esp+28h] [ebp-DB4h] BYREF
  char v23; // [esp+2Ah] [ebp-DB2h]
  __int16 v24; // [esp+2Ch] [ebp-DB0h] BYREF
  char v25; // [esp+2Eh] [ebp-DAEh]
  __int16 v26; // [esp+30h] [ebp-DACh] BYREF
  char v27; // [esp+32h] [ebp-DAAh]
  __int16 v28; // [esp+34h] [ebp-DA8h] BYREF
  char v29; // [esp+36h] [ebp-DA6h]
  char *Str1; // [esp+38h] [ebp-DA4h]
  const char *v31; // [esp+3Ch] [ebp-DA0h]
  const char *v32; // [esp+40h] [ebp-D9Ch]
  _DWORD v33[739]; // [esp+44h] [ebp-D98h] BYREF
  char v34[260]; // [esp+BD0h] [ebp-20Ch] BYREF
  char FileName[260]; // [esp+CD4h] [ebp-108h] BYREF

  v31 = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fde10*/
  v32 = "MAXLIGHTS"; /*0x7fde14*/
  v33[0] = "9"; /*0x7fde18*/
  memset(&v33[1], 0, 0x40); /*0x7fde20*/
  v33[0x11] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fde39*/
  v33[0x12] = "MAXLIGHTS"; /*0x7fde40*/
  v33[0x13] = "8"; /*0x7fde47*/
  v33[0x14] = "SPECULAR"; /*0x7fde4e*/
  memset(&v33[0x15], 0, 0x3C); /*0x7fde59*/
  v33[0x24] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fde77*/
  v33[0x25] = "MAXLIGHTS"; /*0x7fde7e*/
  v33[0x26] = "8"; /*0x7fde85*/
  v33[0x27] = "HAIR"; /*0x7fde8c*/
  v33[0x28] = "1"; /*0x7fde97*/
  memset(&v33[0x29], 0, 0x38); /*0x7fdea2*/
  v33[0x37] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fdeb9*/
  v33[0x38] = "MAXLIGHTS"; /*0x7fdec0*/
  v33[0x39] = "7"; /*0x7fdec7*/
  v33[0x3A] = "HAIR"; /*0x7fded2*/
  v33[0x3B] = "1"; /*0x7fdedd*/
  v33[0x3C] = "SPECULAR"; /*0x7fdee8*/
  memset(&v33[0x3D], 0, 0x34); /*0x7fdef3*/
  v33[0x4C] = "8"; /*0x7fdf08*/
  v33[0x4A] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fdf1d*/
  v33[0x4B] = "MAXLIGHTS"; /*0x7fdf24*/
  v33[0x4D] = "PARALLAX"; /*0x7fdf2b*/
  v33[0x4E] = EmptyString; /*0x7fdf36*/
  memset(&v33[0x4F], 0, 0x38); /*0x7fdf3d*/
  v33[0x5D] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fdf54*/
  v33[0x5E] = "MAXLIGHTS"; /*0x7fdf5b*/
  v33[0x5F] = "8"; /*0x7fdf62*/
  v33[0x60] = "PARALLAX"; /*0x7fdf6d*/
  v33[0x61] = EmptyString; /*0x7fdf78*/
  v33[0x62] = "SPECULAR"; /*0x7fdf7f*/
  memset(&v33[0x63], 0, 0x34); /*0x7fdf8a*/
  v33[0x70] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fdfa0*/
  v33[0x71] = "MAXLIGHTS"; /*0x7fdfa7*/
  v33[0x72] = "8"; /*0x7fdfb9*/
  v33[0x73] = "FACEGENBLEND"; /*0x7fdfc4*/
  v33[0x74] = EmptyString; /*0x7fdfcf*/
  memset(&v33[0x75], 0, 0x38); /*0x7fdfd6*/
  v33[0x83] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fdfed*/
  v33[0x84] = "MAXLIGHTS"; /*0x7fdff4*/
  v33[0x85] = "8"; /*0x7fdffb*/
  v33[0x86] = "FACEGENBLEND"; /*0x7fe006*/
  v33[0x87] = EmptyString; /*0x7fe011*/
  v33[0x88] = "SPECULAR"; /*0x7fe018*/
  memset(&v33[0x89], 0, 0x34); /*0x7fe023*/
  v33[0x96] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe041*/
  v33[0x97] = "MAXLIGHTS"; /*0x7fe048*/
  v33[0x98] = "8"; /*0x7fe04f*/
  v33[0x99] = "GLOW"; /*0x7fe05a*/
  v33[0x9A] = EmptyString; /*0x7fe065*/
  memset(&v33[0x9B], 0, 0x38); /*0x7fe06c*/
  v33[0xA9] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe083*/
  v33[0xAA] = "MAXLIGHTS"; /*0x7fe08a*/
  v33[0xAB] = "8"; /*0x7fe091*/
  v33[0xAC] = "GLOW"; /*0x7fe09c*/
  v33[0xAD] = EmptyString; /*0x7fe0a7*/
  v33[0xAE] = "SPECULAR"; /*0x7fe0ae*/
  memset(&v33[0xAF], 0, 0x34); /*0x7fe0b9*/
  v33[0xBC] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe0d7*/
  v33[0xBD] = "MAXLIGHTS"; /*0x7fe0de*/
  v33[0xBE] = "8"; /*0x7fe0e5*/
  v33[0xBF] = "PROJSHADOW"; /*0x7fe0f0*/
  v33[0xC0] = EmptyString; /*0x7fe0fb*/
  memset(&v33[0xC1], 0, 0x38); /*0x7fe102*/
  v33[0xCF] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe119*/
  v33[0xD0] = "MAXLIGHTS"; /*0x7fe120*/
  v33[0xD1] = "8"; /*0x7fe127*/
  v33[0xD2] = "SPECULAR"; /*0x7fe132*/
  v33[0xD3] = 0; /*0x7fe13d*/
  v33[0xD4] = "PROJSHADOW"; /*0x7fe144*/
  v33[0xD5] = EmptyString; /*0x7fe14f*/
  memset(&v33[0xD6], 0, 0x30); /*0x7fe156*/
  v33[0xE2] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe167*/
  v33[0xE3] = "MAXLIGHTS"; /*0x7fe16e*/
  v33[0xE4] = "8"; /*0x7fe175*/
  v33[0xE5] = "HAIR"; /*0x7fe180*/
  v33[0xE6] = "1"; /*0x7fe18b*/
  v33[0xE7] = "PROJSHADOW"; /*0x7fe196*/
  v33[0xE8] = EmptyString; /*0x7fe1a1*/
  memset(&v33[0xE9], 0, 0x30); /*0x7fe1a8*/
  v33[0xFC] = "PROJSHADOW"; /*0x7fe1c6*/
  v33[0x10D] = "PROJSHADOW"; /*0x7fe1cd*/
  v33[0xF5] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe1dd*/
  v33[0xF6] = "MAXLIGHTS"; /*0x7fe1e4*/
  v33[0xF7] = "7"; /*0x7fe1eb*/
  v33[0xF8] = "HAIR"; /*0x7fe1f6*/
  v33[0xF9] = "1"; /*0x7fe201*/
  v33[0xFA] = "SPECULAR"; /*0x7fe20c*/
  v33[0xFB] = 0; /*0x7fe217*/
  v33[0xFD] = EmptyString; /*0x7fe21e*/
  memset(&v33[0xFE], 0, 0x28); /*0x7fe225*/
  v33[0x108] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe26b*/
  v33[0x109] = "MAXLIGHTS"; /*0x7fe272*/
  v33[0x10A] = "8"; /*0x7fe279*/
  v33[0x10B] = "PARALLAX"; /*0x7fe284*/
  v33[0x10C] = EmptyString; /*0x7fe28f*/
  v33[0x10E] = EmptyString; /*0x7fe296*/
  memset(&v33[0x10F], 0, 0x30); /*0x7fe29d*/
  v33[0x11D] = "8"; /*0x7fe2b2*/
  v33[0x130] = "8"; /*0x7fe2b9*/
  v33[0x11B] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe2ce*/
  v33[0x11C] = "MAXLIGHTS"; /*0x7fe2d5*/
  v33[0x11E] = "PARALLAX"; /*0x7fe2dc*/
  v33[0x11F] = EmptyString; /*0x7fe2e7*/
  v33[0x120] = "SPECULAR"; /*0x7fe2ee*/
  v33[0x121] = 0; /*0x7fe2f9*/
  v33[0x122] = "PROJSHADOW"; /*0x7fe300*/
  v33[0x123] = EmptyString; /*0x7fe307*/
  memset(&v33[0x124], 0, 0x28); /*0x7fe30e*/
  v33[0x12E] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe354*/
  v33[0x12F] = "MAXLIGHTS"; /*0x7fe35b*/
  v33[0x131] = "FACEGENBLEND"; /*0x7fe362*/
  v33[0x132] = EmptyString; /*0x7fe36d*/
  v33[0x133] = "PROJSHADOW"; /*0x7fe374*/
  v33[0x134] = EmptyString; /*0x7fe37b*/
  memset(&v33[0x135], 0, 0x30); /*0x7fe382*/
  v33[0x141] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe393*/
  v33[0x142] = "MAXLIGHTS"; /*0x7fe39a*/
  v33[0x143] = "8"; /*0x7fe3a1*/
  v33[0x144] = "FACEGENBLEND"; /*0x7fe3a8*/
  v33[0x145] = EmptyString; /*0x7fe3b3*/
  v33[0x146] = "SPECULAR"; /*0x7fe3ba*/
  v33[0x147] = 0; /*0x7fe3c5*/
  v33[0x148] = "PROJSHADOW"; /*0x7fe41d*/
  v33[0x149] = EmptyString; /*0x7fe424*/
  memset(&v33[0x14A], 0, 0x28); /*0x7fe42b*/
  v33[0x154] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe432*/
  v33[0x155] = "MAXLIGHTS"; /*0x7fe439*/
  v33[0x156] = "8"; /*0x7fe440*/
  v33[0x157] = "GLOW"; /*0x7fe447*/
  v33[0x158] = EmptyString; /*0x7fe452*/
  v33[0x159] = "PROJSHADOW"; /*0x7fe459*/
  v33[0x15A] = EmptyString; /*0x7fe460*/
  memset(&v33[0x15B], 0, 0x30); /*0x7fe467*/
  v33[0x167] = "lighting\\3x\\SM3Lighting.p.hlsl"; /*0x7fe477*/
  v33[0x168] = "MAXLIGHTS"; /*0x7fe47e*/
  v33[0x169] = "8"; /*0x7fe498*/
  v33[0x16A] = "GLOW"; /*0x7fe49f*/
  v33[0x16B] = EmptyString; /*0x7fe4aa*/
  v33[0x16C] = "SPECULAR"; /*0x7fe4b1*/
  v33[0x16D] = 0; /*0x7fe4bc*/
  v33[0x16E] = "PROJSHADOW"; /*0x7fe4c3*/
  v33[0x16F] = EmptyString; /*0x7fe4ce*/
  memset(&v33[0x170], 0, 0x28); /*0x7fe4d5*/
  v33[0x17A] = "lighting\\2x\\p\\EnvMap.p.hlsl"; /*0x7fe51b*/
  v33[0x17B] = "SM3"; /*0x7fe526*/
  v33[0x17C] = EmptyString; /*0x7fe52d*/
  memset(&v33[0x17D], 0, 0x40); /*0x7fe534*/
  v33[0x18D] = "lighting\\2x\\p\\EnvMap.p.hlsl"; /*0x7fe54b*/
  v33[0x18E] = "SM3"; /*0x7fe556*/
  v33[0x18F] = EmptyString; /*0x7fe55d*/
  v33[0x190] = "WINDOW"; /*0x7fe564*/
  memset(&v33[0x191], 0, 0x3C); /*0x7fe56f*/
  v33[0x1A0] = "lighting\\2x\\p\\EnvMap.p.hlsl"; /*0x7fe590*/
  v33[0x1A1] = "SM3"; /*0x7fe59b*/
  v33[0x1A2] = EmptyString; /*0x7fe5a2*/
  v33[0x1A3] = &off_A90BE8; /*0x7fe5a9*/
  memset(&v33[0x1A4], 0, 0x3C); /*0x7fe5b4*/
  v33[0x1B3] = "lighting\\3x\\SM3SimpleShadow.p.hlsl"; /*0x7fe5c7*/
  v33[0x1B4] = "SOFTSHADOW"; /*0x7fe5dd*/
  v33[0x1B5] = "4"; /*0x7fe5e8*/
  v33[0x1B6] = "DEPTHBIAS"; /*0x7fe5f3*/
  v33[0x1B7] = "-2"; /*0x7fe5fe*/
  memset(&v33[0x1B8], 0, 0x38); /*0x7fe609*/
  v33[0x1C6] = "lighting\\2x\\p\\Decal.p.hlsl"; /*0x7fe620*/
  v33[0x1C7] = "SM3"; /*0x7fe62b*/
  v33[0x1C8] = 0; /*0x7fe632*/
  v33[0x1C9] = "MAXDECALS"; /*0x7fe639*/
  v33[0x1CA] = "8"; /*0x7fe644*/
  memset(&v33[0x1CB], 0, 0x38); /*0x7fe64b*/
  v33[0x1D9] = "lighting\\2x\\p\\Decal.p.hlsl"; /*0x7fe662*/
  v33[0x1DA] = "SM3"; /*0x7fe66d*/
  v33[0x1DB] = 0; /*0x7fe674*/
  v33[0x1DC] = "MAXDECALS"; /*0x7fe67b*/
  v33[0x1DD] = "8"; /*0x7fe686*/
  v33[0x1DE] = "ALPHA"; /*0x7fe68d*/
  memset(&v33[0x1DF], 0, 0x34); /*0x7fe698*/
  v33[0x1EC] = "lighting\\3x\\SM3DepthMap.p.hlsl"; /*0x7fe6bb*/
  memset(&v33[0x1ED], 0, 0x48); /*0x7fe6c2*/
  v33[0x1FF] = "lighting\\3x\\SM3DepthMap.p.hlsl"; /*0x7fe6d9*/
  memset(&v33[0x200], 0, 0x48); /*0x7fe6e0*/
  v33[0x212] = "lighting\\2x\\p\\renderNormals.p.hlsl"; /*0x7fe6ff*/
  v33[0x213] = "SM3"; /*0x7fe706*/
  memset(&v33[0x214], 0, 0x44); /*0x7fe70d*/
  v33[0x225] = "lighting\\2x\\p\\renderNormals.p.hlsl"; /*0x7fe72b*/
  v33[0x226] = "SM3"; /*0x7fe732*/
  memset(&v33[0x227], 0, 0x44); /*0x7fe739*/
  v33[0x238] = "lighting\\2x\\p\\renderNormals.p.hlsl"; /*0x7fe757*/
  v33[0x239] = "SM3"; /*0x7fe75e*/
  v33[0x23A] = 0; /*0x7fe765*/
  v33[0x23B] = "FIRE"; /*0x7fe76c*/
  v33[0x23C] = EmptyString; /*0x7fe777*/
  memset(&v33[0x23D], 0, 0x38); /*0x7fe77e*/
  v33[0x24B] = "lighting\\2x\\p\\renderNormals.p.hlsl"; /*0x7fe78a*/
  v33[0x24C] = "SM3"; /*0x7fe79c*/
  v33[0x24D] = 0; /*0x7fe7a3*/
  v33[0x24E] = "CLEAR"; /*0x7fe7aa*/
  v33[0x24F] = EmptyString; /*0x7fe7b5*/
  memset(&v33[0x250], 0, 0x38); /*0x7fe7bc*/
  v33[0x25E] = "lighting\\2x\\p\\renderNormals.p.hlsl"; /*0x7fe7ca*/
  v33[0x25F] = "SM3"; /*0x7fe7df*/
  v33[0x260] = 0; /*0x7fe7e6*/
  v33[0x261] = "CLEAR"; /*0x7fe7ed*/
  v33[0x262] = EmptyString; /*0x7fe7f4*/
  memset(&v33[0x263], 0, 0x38); /*0x7fe7fb*/
  v33[0x271] = "lighting\\2x\\p\\localMap.p.hlsl"; /*0x7fe812*/
  v33[0x272] = "SM3"; /*0x7fe81d*/
  memset(&v33[0x273], 0, 0x44); /*0x7fe824*/
  v33[0x284] = "lighting\\2x\\p\\localMap.p.hlsl"; /*0x7fe845*/
  v33[0x285] = "SM3"; /*0x7fe850*/
  v33[0x286] = 0; /*0x7fe857*/
  v33[0x287] = "CLEAR"; /*0x7fe85e*/
  memset(&v33[0x288], 0, 0x3C); /*0x7fe865*/
  v33[0x297] = "lighting\\1x\\p\\texEffect.p.hlsl"; /*0x7fe88d*/
  v33[0x298] = "HQ"; /*0x7fe894*/
  v33[0x299] = EmptyString; /*0x7fe89b*/
  memset(&v33[0x29A], 0, 0x40); /*0x7fe8a2*/
  v33[0x2AA] = "lighting\\1x\\p\\texEffect.p.hlsl"; /*0x7fe8b9*/
  v33[0x2AB] = "HQ"; /*0x7fe8c0*/
  v33[0x2AC] = EmptyString; /*0x7fe8c7*/
  memset(&v33[0x2AD], 0, 0x40); /*0x7fe8ce*/
  v33[0x2BD] = "lighting\\3x\\SM3ZOnly.p.hlsl"; /*0x7fe8ea*/
  memset(&v33[0x2BE], 0, 0x48); /*0x7fe8f1*/
  v33[0x2D0] = "lighting\\3x\\SM3ZOnly.p.hlsl"; /*0x7fe908*/
  memset(&v33[0x2D1], 0, 0x48); /*0x7fe90f*/
  v0 = sub_7B4780(0); /*0x7fe91c*/
  v1 = a15; /*0x7fe92b*/
  v2 = (char *)v0; /*0x7fe932*/
  LOBYTE(v0) = byte_A93282; /*0x7fe934*/
  v28 = word_A93280; /*0x7fe939*/
  v3 = byte_A900F2; /*0x7fe93e*/
  v29 = (char)v0; /*0x7fe944*/
  LOWORD(v0) = word_A9327C; /*0x7fe948*/
  v24 = v1; /*0x7fe94e*/
  LOBYTE(v1) = byte_A9327E; /*0x7fe953*/
  v4 = (__int16 **)v33; /*0x7fe959*/
  Str1 = v2; /*0x7fe95d*/
  v25 = v3; /*0x7fe961*/
  v20 = (__int16)v0; /*0x7fe965*/
  v21 = v1; /*0x7fe96a*/
  v18 = 0x38; /*0x7fe96e*/
  v19 = 0; /*0x7fe975*/
  v22 = 0x37; /*0x7fe979*/
  v23 = 0; /*0x7fe980*/
  v16 = 0x34; /*0x7fe984*/
  v17 = 0; /*0x7fe98b*/
  v26 = 0x32; /*0x7fe98f*/
  v27 = 0; /*0x7fe996*/
  v5 = 0; /*0x7fe99a*/
  for ( i = (__int16 **)v33; ; v4 = i ) /*0x7fe99c*/
  {
    sub_801030((char *)v4[0xFFFFFFFE], (int)FileName); /*0x7fe9b6*/
    _sprintf(v34, "SM3%03i.pso", v5); /*0x7fe9c9*/
    v6 = sub_404F00(0); /*0x7fe9cf*/
    if ( v6 == 7 ) /*0x7fe9da*/
    {
      if ( v5 < 0x14 ) /*0x7fe9e3*/
        *v4 = &v28; /*0x7fe9e9*/
      if ( v5 == 2 || v5 == 3 || v5 == 0xC || v5 == 0xD ) /*0x7fe9fd*/
        v4[2] = &v26; /*0x7fea03*/
      if ( !v5 || v5 == 2 || v5 == 4 || v5 == 8 || v5 == 0xC || v5 == 0xE || v5 == 0x12 ) /*0x7fea26*/
      {
        *v4 = &v24; /*0x7fea72*/
      }
      else
      {
        if ( v5 == 1 || v5 == 5 || v5 == 6 || v5 == 9 || v5 == 0xB || v5 == 0xF || v5 == 0x10 ) /*0x7fea49*/
        {
          v13 = 1; /*0x7fea63*/
          *v4 = &v20; /*0x7fea65*/
          v12 = 2; /*0x7fea67*/
          goto LABEL_51; /*0x7fea69*/
        }
        if ( v5 < 0x14 ) /*0x7fea4e*/
        {
          v13 = 1; /*0x7fea54*/
          *v4 = &v18; /*0x7fea56*/
          v12 = 2; /*0x7fea58*/
          goto LABEL_51; /*0x7fea5a*/
        }
      }
      v13 = 1; /*0x7fea74*/
      v12 = 2; /*0x7fea76*/
LABEL_51:
      v7 = v4 + 0xFFFFFFFF; /*0x7feb10*/
      result = CreatePixelShader(FileName, v7, v2, v34, v12, v13); /*0x7feb29*/
      v9 = *(volatile LONG **)(4 * v5 + 0xB46ED8); /*0x7feb2e*/
      v14 = result; /*0x7feb37*/
      if ( v9 == (volatile LONG *)result ) /*0x7feb3b*/
        goto LABEL_58; /*0x7feb3b*/
      if ( v9 ) /*0x7feb3f*/
      {
LABEL_53:
        if ( !InterlockedDecrement(v9 + 1) ) /*0x7feb45*/
          (**(void (__thiscall ***)(volatile LONG *, int))v9)(v9, 1); /*0x7feb5c*/
        result = v14; /*0x7feb5e*/
      }
LABEL_56:
      *(_DWORD *)(4 * v5 + 0xB46ED8) = result; /*0x7feb62*/
      if ( result ) /*0x7feb6b*/
        result = (NiD3DShaderProgram *)InterlockedIncrement((volatile LONG *)result + 1); /*0x7feb71*/
      goto LABEL_58; /*0x7feb71*/
    }
    if ( v6 != 5 ) /*0x7fea80*/
    {
      v13 = 0; /*0x7feb0e*/
      v12 = 0; /*0x7feb0f*/
      goto LABEL_51; /*0x7feb0f*/
    }
    if ( !v5 /*0x7feacd*/
      || v5 == 4
      || v5 == 5
      || v5 == 8
      || v5 == 0xB
      || v5 == 0xE
      || v5 == 0xF
      || v5 == 0x10
      || v5 == 0x11
      || v5 == 9
      || v5 == 0xC
      || v5 == 0x12
      || v5 == 19
      || v5 == 6
      || v5 == 7 )
    {
      *v4 = &v22; /*0x7fead3*/
    }
    v7 = v4 + 0xFFFFFFFF; /*0x7feae4*/
    result = CreatePixelShader(FileName, v7, v2, v34, 0, 0); /*0x7feaf0*/
    v9 = *(volatile LONG **)(4 * v5 + 0xB46ED8); /*0x7feaf5*/
    v14 = result; /*0x7feafe*/
    if ( v9 != (volatile LONG *)result ) /*0x7feb02*/
    {
      if ( v9 ) /*0x7feb06*/
        goto LABEL_53; /*0x7feb06*/
      goto LABEL_56; /*0x7feb06*/
    }
LABEL_58:
    if ( v5 < 0x14 ) /*0x7feb7a*/
    {
      _sprintf(v34, "SM3LL%03i.pso", v5); /*0x7feb8e*/
      *i = &v16; /*0x7feba0*/
      result = CreatePixelShader(FileName, v7, Str1, v34, 0, 0); /*0x7febbc*/
      v10 = *(volatile LONG **)(4 * v5 + 0xB46C20); /*0x7febc1*/
      v11 = result; /*0x7febc8*/
      if ( v10 != (volatile LONG *)result ) /*0x7febcc*/
      {
        if ( v10 ) /*0x7febd0*/
        {
          result = (NiD3DShaderProgram *)InterlockedDecrement(v10 + 1); /*0x7febd6*/
          if ( !result ) /*0x7febde*/
            result = (NiD3DShaderProgram *)(**(int (__thiscall ***)(volatile LONG *, int))v10)(v10, 1); /*0x7febec*/
        }
        *(_DWORD *)(4 * v5 + 0xB46C20) = v11; /*0x7febf0*/
        if ( v11 ) /*0x7febf7*/
          result = (NiD3DShaderProgram *)InterlockedIncrement((volatile LONG *)v11 + 1); /*0x7febfd*/
      }
    }
    i += 0x13; /*0x7fec03*/
    if ( ++v5 >= 0x27 ) /*0x7fec0e*/
      break; /*0x7fec0e*/
    v2 = Str1; /*0x7fe9a2*/
  }
  return result; /*0x7fec14*/
}
