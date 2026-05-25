// 0x007CD090 @ 0x007CD090
NiD3DShaderProgram *sub_7CD090()
{
  int v0; // esi
  char **v1; // ebx
  NiD3DShaderProgram *VertexShader; // eax
  volatile LONG *v3; // ebp
  NiD3DShaderProgram **v4; // esi
  int v5; // ebx
  NiD3DShaderProgram *result; // eax
  volatile LONG *v7; // esi
  NiD3DShaderProgram *v8; // ebp
  NiD3DShaderProgram **v9; // esi
  int v10; // ebx
  int v11; // esi
  volatile LONG *v12; // esi
  NiD3DShaderProgram *v13; // ebp
  NiD3DShaderProgram *v14; // [esp+10h] [ebp-2868h]
  _DWORD *v15; // [esp+10h] [ebp-2868h]
  _DWORD *v16; // [esp+10h] [ebp-2868h]
  _DWORD v17[1444]; // [esp+18h] [ebp-2860h] BYREF
  _DWORD v18[418]; // [esp+16A8h] [ebp-11D0h] BYREF
  _DWORD v19[589]; // [esp+1D30h] [ebp-B48h] BYREF
  char Dest[8]; // [esp+2664h] [ebp-214h] BYREF
  char v21[260]; // [esp+266Ch] [ebp-20Ch] BYREF
  char FileName[260]; // [esp+2770h] [ebp-108h] BYREF

  _itoa(Value, Dest, 0xA); /*0x7cd0c1*/
  v19[0] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd0d8*/
  memset(&v19[1], 0, 0xE0); /*0x7cd0df*/
  v19[0x39] = "lighting\\1x\\v\\diffusePt.v.hlsl"; /*0x7cd132*/
  memset(&v19[0x3A], 0, 0x48); /*0x7cd13d*/
  v19[0x4C] = "lighting\\1x\\v\\diffuseDir.v.hlsl"; /*0x7cd154*/
  memset(&v19[0x4D], 0, 0x48); /*0x7cd15f*/
  v19[0x5F] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd179*/
  memset(&v19[0x60], 0, 0x48); /*0x7cd180*/
  v19[0x72] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd19c*/
  v19[0x73] = "VC"; /*0x7cd1a3*/
  v19[0x74] = EmptyString; /*0x7cd1ae*/
  memset(&v19[0x75], 0, 0x40); /*0x7cd1b5*/
  v19[0x85] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd1cc*/
  v19[0x86] = "FACEGENBLEND"; /*0x7cd1d3*/
  v19[0x87] = EmptyString; /*0x7cd1de*/
  memset(&v19[0x88], 0, 0x40); /*0x7cd1e5*/
  v19[0x98] = "lighting\\1x\\v\\specularPt.v.hlsl"; /*0x7cd1fb*/
  memset(&v19[0x99], 0, 0x48); /*0x7cd206*/
  v19[0xAB] = "lighting\\1x\\v\\specularDir.v.hlsl"; /*0x7cd21e*/
  memset(&v19[0xAC], 0, 0x48); /*0x7cd229*/
  v19[0xBE] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd245*/
  memset(&v19[0xBF], 0, 0x48); /*0x7cd24c*/
  v19[0xD1] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd266*/
  v19[0xD2] = &off_A90D88; /*0x7cd26d*/
  v19[0xD3] = EmptyString; /*0x7cd278*/
  memset(&v19[0xD4], 0, 0x40); /*0x7cd27f*/
  v19[0xE4] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd296*/
  v19[0xE5] = "VC"; /*0x7cd29d*/
  v19[0xE6] = EmptyString; /*0x7cd2a8*/
  memset(&v19[0xE7], 0, 0x40); /*0x7cd2af*/
  v19[0xF7] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd2c6*/
  v19[0xF8] = &off_A90D88; /*0x7cd2cd*/
  v19[0xF9] = EmptyString; /*0x7cd2d8*/
  v19[0xFA] = "VC"; /*0x7cd2df*/
  v19[0xFB] = EmptyString; /*0x7cd2ea*/
  memset(&v19[0xFC], 0, 0x38); /*0x7cd2f1*/
  v19[0x10A] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd308*/
  v19[0x10B] = "FACEGENBLEND"; /*0x7cd30f*/
  v19[0x10C] = EmptyString; /*0x7cd31a*/
  memset(&v19[0x10D], 0, 0x40); /*0x7cd321*/
  v19[0x11D] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd32f*/
  v19[0x11E] = "FACEGENBLEND"; /*0x7cd344*/
  v19[0x11F] = EmptyString; /*0x7cd34f*/
  v19[0x120] = &off_A90D88; /*0x7cd356*/
  v19[0x121] = EmptyString; /*0x7cd35d*/
  memset(&v19[0x122], 0, 0x38); /*0x7cd364*/
  v19[0x130] = "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl"; /*0x7cd37b*/
  memset(&v19[0x131], 0, 0x48); /*0x7cd386*/
  v19[0x143] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd397*/
  v19[0x144] = &off_A90D88; /*0x7cd39e*/
  v19[0x145] = EmptyString; /*0x7cd3a5*/
  memset(&v19[0x146], 0, 0x40); /*0x7cd3ac*/
  v19[0x156] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd3cc*/
  v19[0x157] = &off_A90D88; /*0x7cd3d3*/
  v19[0x158] = EmptyString; /*0x7cd3da*/
  v19[0x159] = &off_A8F8C4; /*0x7cd3e1*/
  v19[0x15A] = EmptyString; /*0x7cd3ec*/
  memset(&v19[0x15B], 0, 0x38); /*0x7cd3f3*/
  v19[0x169] = "lighting\\1x\\v\\envmap.v.hlsl"; /*0x7cd40a*/
  memset(&v19[0x16A], 0, 0x48); /*0x7cd415*/
  v19[0x17C] = "lighting\\1x\\v\\vertDir.v.hlsl"; /*0x7cd431*/
  memset(&v19[0x17D], 0, 0x48); /*0x7cd438*/
  v19[0x18F] = "lighting\\1x\\v\\vertDir.v.hlsl"; /*0x7cd44f*/
  v19[0x190] = "VC"; /*0x7cd456*/
  v19[0x191] = EmptyString; /*0x7cd461*/
  memset(&v19[0x192], 0, 0x40); /*0x7cd468*/
  v19[0x1A2] = "lighting\\1x\\v\\vertDirAndPt.v.hlsl"; /*0x7cd484*/
  memset(&v19[0x1A3], 0, 0x48); /*0x7cd48b*/
  v19[0x1B5] = "lighting\\1x\\v\\vertDirAndPt.v.hlsl"; /*0x7cd4a5*/
  v19[0x1B6] = "VC"; /*0x7cd4ac*/
  v19[0x1B7] = EmptyString; /*0x7cd4b7*/
  memset(&v19[0x1B8], 0, 0x40); /*0x7cd4be*/
  v19[0x1C8] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd4d5*/
  v19[0x1C9] = "SI"; /*0x7cd4dc*/
  v19[0x1CA] = EmptyString; /*0x7cd4e7*/
  memset(&v19[0x1CB], 0, 0x40); /*0x7cd4ee*/
  v19[0x1DB] = "lighting\\1x\\v\\land.v.hlsl"; /*0x7cd50a*/
  memset(&v19[0x1DC], 0, 0x48); /*0x7cd511*/
  v19[0x1EE] = "lighting\\1x\\v\\land.v.hlsl"; /*0x7cd527*/
  v19[0x1EF] = "LANDALPHA"; /*0x7cd52e*/
  v19[0x1F0] = EmptyString; /*0x7cd539*/
  memset(&v19[0x1F1], 0, 0x40); /*0x7cd540*/
  v19[0x201] = "lighting\\1x\\v\\land.v.hlsl"; /*0x7cd558*/
  v19[0x202] = "LANDALPHA"; /*0x7cd55f*/
  v19[0x203] = EmptyString; /*0x7cd56a*/
  v19[0x204] = "SI"; /*0x7cd571*/
  v19[0x205] = EmptyString; /*0x7cd57c*/
  memset(&v19[0x206], 0, 0x38); /*0x7cd583*/
  v19[0x214] = "lighting\\1x\\v\\land.v.hlsl"; /*0x7cd59a*/
  v19[0x215] = "PTLIGHT"; /*0x7cd5a1*/
  v19[0x216] = EmptyString; /*0x7cd5ac*/
  memset(&v19[0x217], 0, 0x40); /*0x7cd5b3*/
  v19[0x227] = "lighting\\1x\\v\\land.v.hlsl"; /*0x7cd5cd*/
  v19[0x228] = "LANDALPHA"; /*0x7cd5d4*/
  v19[0x229] = EmptyString; /*0x7cd5df*/
  v19[0x22A] = "PTLIGHT"; /*0x7cd5e6*/
  v19[0x22B] = EmptyString; /*0x7cd5f1*/
  memset(&v19[0x22C], 0, 0x84); /*0x7cd5f8*/
  v18[0] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd632*/
  v18[1] = "SKIN"; /*0x7cd639*/
  v18[2] = EmptyString; /*0x7cd640*/
  memset(&v18[3], 0, 0x40); /*0x7cd647*/
  v18[0x13] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd65e*/
  v18[0x14] = "SKIN"; /*0x7cd665*/
  v18[0x15] = EmptyString; /*0x7cd66c*/
  v18[0x16] = &off_A90D88; /*0x7cd673*/
  v18[0x17] = EmptyString; /*0x7cd67e*/
  memset(&v18[0x18], 0, 0x38); /*0x7cd685*/
  v18[0x26] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd69c*/
  v18[0x27] = "SKIN"; /*0x7cd6a3*/
  v18[0x28] = EmptyString; /*0x7cd6aa*/
  v18[0x29] = &off_A90D88; /*0x7cd6b1*/
  v18[0x2A] = EmptyString; /*0x7cd6bc*/
  v18[0x2B] = &off_A8F8C4; /*0x7cd6c3*/
  v18[0x2C] = EmptyString; /*0x7cd6ce*/
  memset(&v18[0x2D], 0, 0x30); /*0x7cd6d5*/
  v18[0x39] = "lighting\\1x\\v\\diffusePt.v.hlsl"; /*0x7cd6e3*/
  v18[0x3A] = "SKIN"; /*0x7cd6ee*/
  v18[0x3B] = EmptyString; /*0x7cd6f5*/
  memset(&v18[0x3C], 0, 0x40); /*0x7cd6fc*/
  v18[0x4C] = "lighting\\1x\\v\\diffuseDir.v.hlsl"; /*0x7cd71f*/
  v18[0x4D] = "SKIN"; /*0x7cd72a*/
  v18[0x4E] = EmptyString; /*0x7cd731*/
  memset(&v18[0x4F], 0, 0x40); /*0x7cd738*/
  v18[0x5F] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd74f*/
  v18[0x60] = "SKIN"; /*0x7cd756*/
  v18[0x61] = EmptyString; /*0x7cd75d*/
  memset(&v18[0x62], 0, 0x40); /*0x7cd764*/
  v18[0x72] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd77b*/
  v18[0x73] = "SKIN"; /*0x7cd782*/
  v18[0x74] = EmptyString; /*0x7cd789*/
  v18[0x75] = "VC"; /*0x7cd790*/
  v18[0x76] = EmptyString; /*0x7cd79b*/
  memset(&v18[0x77], 0, 0x38); /*0x7cd7a2*/
  v18[0x85] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cd7b9*/
  v18[0x86] = "SKIN"; /*0x7cd7c0*/
  v18[0x87] = EmptyString; /*0x7cd7c7*/
  v18[0x88] = "FACEGENBLEND"; /*0x7cd7ce*/
  v18[0x89] = EmptyString; /*0x7cd7d9*/
  memset(&v18[0x8A], 0, 0x38); /*0x7cd7e0*/
  v18[0x98] = "lighting\\1x\\v\\specularPt.v.hlsl"; /*0x7cd7f7*/
  v18[0x99] = "SKIN"; /*0x7cd802*/
  v18[0x9A] = EmptyString; /*0x7cd809*/
  memset(&v18[0x9B], 0, 0x40); /*0x7cd810*/
  v18[0xAB] = "lighting\\1x\\v\\specularDir.v.hlsl"; /*0x7cd827*/
  v18[0xAC] = "SKIN"; /*0x7cd832*/
  v18[0xAD] = EmptyString; /*0x7cd839*/
  memset(&v18[0xAE], 0, 0x40); /*0x7cd840*/
  v18[0xBE] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd85a*/
  v18[0xBF] = "SKIN"; /*0x7cd865*/
  v18[0xC0] = EmptyString; /*0x7cd86c*/
  memset(&v18[0xC1], 0, 0x40); /*0x7cd873*/
  v18[0xD1] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd889*/
  v18[0xD2] = "SKIN"; /*0x7cd894*/
  v18[0xD3] = EmptyString; /*0x7cd89b*/
  v18[0xD4] = "VC"; /*0x7cd8a2*/
  v18[0xD5] = EmptyString; /*0x7cd8ad*/
  memset(&v18[0xD6], 0, 0x38); /*0x7cd8b4*/
  v18[0xE4] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd8cc*/
  v18[0xE5] = "SKIN"; /*0x7cd8d7*/
  v18[0xE6] = EmptyString; /*0x7cd8de*/
  v18[0xE7] = &off_A90D88; /*0x7cd8e5*/
  v18[0xE8] = EmptyString; /*0x7cd8f0*/
  memset(&v18[0xE9], 0, 0x38); /*0x7cd8f7*/
  v18[0xF7] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd90e*/
  v18[0xF8] = "SKIN"; /*0x7cd919*/
  v18[0xF9] = EmptyString; /*0x7cd920*/
  v18[0xFA] = &off_A90D88; /*0x7cd927*/
  v18[0xFB] = EmptyString; /*0x7cd932*/
  v18[0xFC] = "VC"; /*0x7cd939*/
  v18[0xFD] = EmptyString; /*0x7cd944*/
  memset(&v18[0xFE], 0, 0x30); /*0x7cd94b*/
  v18[0x10A] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd962*/
  v18[0x10B] = "SKIN"; /*0x7cd96d*/
  v18[0x10C] = EmptyString; /*0x7cd974*/
  v18[0x10D] = "FACEGENBLEND"; /*0x7cd97b*/
  v18[0x10E] = EmptyString; /*0x7cd986*/
  memset(&v18[0x10F], 0, 0x38); /*0x7cd98d*/
  v18[0x11D] = "lighting\\1x\\v\\ambDiffuseDirTexture.v.hlsl"; /*0x7cd9a4*/
  v18[0x11E] = "SKIN"; /*0x7cd9af*/
  v18[0x11F] = EmptyString; /*0x7cd9b6*/
  v18[0x120] = "FACEGENBLEND"; /*0x7cd9bd*/
  v18[0x121] = EmptyString; /*0x7cd9c8*/
  v18[0x122] = &off_A90D88; /*0x7cd9cf*/
  v18[0x123] = EmptyString; /*0x7cd9da*/
  memset(&v18[0x124], 0, 0x30); /*0x7cd9e1*/
  v18[0x130] = "lighting\\1x\\v\\ambDiffuseDirAndPt.v.hlsl"; /*0x7cd9fb*/
  v18[0x131] = "SKIN"; /*0x7cda06*/
  v18[0x132] = EmptyString; /*0x7cda0d*/
  memset(&v18[0x133], 0, 0x40); /*0x7cda14*/
  v18[0x143] = "lighting\\1x\\v\\envmap.v.hlsl"; /*0x7cda2b*/
  v18[0x144] = "SKIN"; /*0x7cda36*/
  v18[0x145] = EmptyString; /*0x7cda3d*/
  memset(&v18[0x146], 0, 0xD8); /*0x7cda44*/
  v18[0x17C] = "lighting\\1x\\v\\base.v.hlsl"; /*0x7cda97*/
  v18[0x17D] = "SKIN"; /*0x7cda9e*/
  v18[0x17E] = EmptyString; /*0x7cdaa5*/
  v18[0x17F] = "SI"; /*0x7cdaac*/
  v18[0x180] = EmptyString; /*0x7cdab7*/
  memset(&v18[0x181], 0, 0x84); /*0x7cdabe*/
  v17[0] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdaf8*/
  memset(&v17[1], 0, 0x48); /*0x7cdafc*/
  v17[0x13] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdb10*/
  v17[0x14] = "MODELSPACENORM"; /*0x7cdb14*/
  v17[0x15] = EmptyString; /*0x7cdb1f*/
  v17[0x16] = "LODLANDCLIP"; /*0x7cdb26*/
  v17[0x17] = EmptyString; /*0x7cdb31*/
  memset(&v17[0x18], 0, 0x38); /*0x7cdb38*/
  v17[0x26] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdb4f*/
  v17[0x27] = "SKIN"; /*0x7cdb56*/
  v17[0x28] = EmptyString; /*0x7cdb5d*/
  memset(&v17[0x29], 0, 0x40); /*0x7cdb64*/
  v17[0x39] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdb7b*/
  v17[0x3A] = "PROJ_SHADOW"; /*0x7cdb82*/
  v17[0x3B] = EmptyString; /*0x7cdb8d*/
  memset(&v17[0x3C], 0, 0x40); /*0x7cdb94*/
  v17[0x4C] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdbab*/
  v17[0x4D] = "MODELSPACENORM"; /*0x7cdbb2*/
  v17[0x4E] = EmptyString; /*0x7cdbbd*/
  v17[0x4F] = "PROJ_SHADOW"; /*0x7cdbc4*/
  v17[0x50] = EmptyString; /*0x7cdbcf*/
  v17[0x51] = "LODLANDCLIP"; /*0x7cdbd6*/
  v17[0x52] = EmptyString; /*0x7cdbe1*/
  memset(&v17[0x53], 0, 0x30); /*0x7cdbe8*/
  v17[0x5F] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdbff*/
  v17[0x60] = "SKIN"; /*0x7cdc06*/
  v17[0x61] = EmptyString; /*0x7cdc0d*/
  v17[0x62] = "PROJ_SHADOW"; /*0x7cdc14*/
  v17[0x63] = EmptyString; /*0x7cdc1f*/
  memset(&v17[0x64], 0, 0x38); /*0x7cdc26*/
  v17[0x72] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdc40*/
  v17[0x73] = "STBB"; /*0x7cdc47*/
  v17[0x74] = EmptyString; /*0x7cdc52*/
  memset(&v17[0x75], 0, 0x40); /*0x7cdc59*/
  v17[0x85] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdc67*/
  v17[0x86] = "LIGHTS"; /*0x7cdc7c*/
  v17[0x87] = "2"; /*0x7cdc83*/
  memset(&v17[0x88], 0, 0x40); /*0x7cdc8e*/
  v17[0x98] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdca5*/
  v17[0x99] = "LIGHTS"; /*0x7cdcb0*/
  v17[0x9A] = "2"; /*0x7cdcb7*/
  v17[0x9B] = "SKIN"; /*0x7cdcc2*/
  v17[0x9C] = EmptyString; /*0x7cdcc9*/
  memset(&v17[0x9D], 0, 0x38); /*0x7cdcd0*/
  v17[0xAB] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdce7*/
  v17[0xAC] = "LIGHTS"; /*0x7cdcf2*/
  v17[0xAD] = "2"; /*0x7cdcf9*/
  v17[0xAE] = "PROJ_SHADOW"; /*0x7cdd04*/
  v17[0xAF] = EmptyString; /*0x7cdd0f*/
  memset(&v17[0xB0], 0, 0x38); /*0x7cdd16*/
  v17[0xBE] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdd2d*/
  v17[0xBF] = "LIGHTS"; /*0x7cdd38*/
  v17[0xC0] = "2"; /*0x7cdd3f*/
  v17[0xC1] = "SKIN"; /*0x7cdd4a*/
  v17[0xC2] = EmptyString; /*0x7cdd51*/
  v17[0xC3] = "PROJ_SHADOW"; /*0x7cdd58*/
  v17[0xC4] = EmptyString; /*0x7cdd63*/
  memset(&v17[0xC5], 0, 0x30); /*0x7cdd6a*/
  v17[0xD1] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdd81*/
  v17[0xD2] = "SPECULAR"; /*0x7cdd8c*/
  v17[0xD3] = EmptyString; /*0x7cdd97*/
  memset(&v17[0xD4], 0, 0x40); /*0x7cdd9e*/
  v17[0xE4] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cddb8*/
  v17[0xE5] = "SPECULAR"; /*0x7cddc3*/
  v17[0xE6] = EmptyString; /*0x7cddce*/
  v17[0xE7] = "SKIN"; /*0x7cddd5*/
  v17[0xE8] = EmptyString; /*0x7cdddc*/
  memset(&v17[0xE9], 0, 0x38); /*0x7cdde3*/
  v17[0xF7] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cddef*/
  v17[0xF8] = "SPECULAR"; /*0x7cddfa*/
  v17[0xF9] = EmptyString; /*0x7cde05*/
  v17[0xFA] = "PROJ_SHADOW"; /*0x7cde0c*/
  v17[0xFB] = EmptyString; /*0x7cde17*/
  memset(&v17[0xFC], 0, 0x38); /*0x7cde29*/
  v17[0x10A] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cde40*/
  v17[0x10B] = "SPECULAR"; /*0x7cde4b*/
  v17[0x10C] = EmptyString; /*0x7cde56*/
  v17[0x10D] = "SKIN"; /*0x7cde5d*/
  v17[0x10E] = EmptyString; /*0x7cde64*/
  v17[0x10F] = "PROJ_SHADOW"; /*0x7cde6b*/
  v17[0x110] = EmptyString; /*0x7cde76*/
  memset(&v17[0x111], 0, 0x30); /*0x7cde7d*/
  v17[0x11D] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cde94*/
  v17[0x11E] = "SPECULAR"; /*0x7cde9f*/
  v17[0x11F] = EmptyString; /*0x7cdeaa*/
  v17[0x120] = "LIGHTS"; /*0x7cdeb1*/
  v17[0x121] = "2"; /*0x7cdeb8*/
  memset(&v17[0x122], 0, 0x38); /*0x7cdec3*/
  v17[0x130] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdeda*/
  v17[0x131] = "SPECULAR"; /*0x7cdee5*/
  v17[0x132] = EmptyString; /*0x7cdef0*/
  v17[0x133] = "LIGHTS"; /*0x7cdef7*/
  v17[0x134] = "2"; /*0x7cdefe*/
  v17[0x135] = "SKIN"; /*0x7cdf09*/
  v17[0x136] = EmptyString; /*0x7cdf10*/
  memset(&v17[0x137], 0, 0x30); /*0x7cdf17*/
  v17[0x143] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdf2e*/
  v17[0x144] = "SPECULAR"; /*0x7cdf39*/
  v17[0x145] = EmptyString; /*0x7cdf44*/
  v17[0x146] = "LIGHTS"; /*0x7cdf4b*/
  v17[0x147] = "2"; /*0x7cdf52*/
  v17[0x148] = "PROJ_SHADOW"; /*0x7cdf5d*/
  v17[0x149] = EmptyString; /*0x7cdf68*/
  memset(&v17[0x14A], 0, 0x30); /*0x7cdf6f*/
  v17[0x156] = "lighting\\2x\\v\\ADTS.v.hlsl"; /*0x7cdf85*/
  v17[0x157] = "SPECULAR"; /*0x7cdf90*/
  v17[0x158] = EmptyString; /*0x7cdf9b*/
  v17[0x159] = "LIGHTS"; /*0x7cdfa2*/
  v17[0x15A] = "2"; /*0x7cdfa9*/
  v17[0x15B] = "SKIN"; /*0x7cdfb0*/
  v17[0x15C] = EmptyString; /*0x7cdfb7*/
  v17[0x15D] = "PROJ_SHADOW"; /*0x7cdfbe*/
  v17[0x15E] = EmptyString; /*0x7cdfc9*/
  memset(&v17[0x15F], 0, 0x28); /*0x7cdfd0*/
  v17[0x169] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce016*/
  v17[0x16A] = "LIGHTS"; /*0x7ce021*/
  v17[0x16B] = "2"; /*0x7ce028*/
  memset(&v17[0x16C], 0, 0x40); /*0x7ce03a*/
  v17[0x17C] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce051*/
  v17[0x17D] = "LIGHTS"; /*0x7ce05c*/
  v17[0x17E] = "2"; /*0x7ce063*/
  v17[0x17F] = "SKIN"; /*0x7ce06e*/
  v17[0x180] = EmptyString; /*0x7ce075*/
  memset(&v17[0x181], 0, 0x38); /*0x7ce07c*/
  v17[0x18F] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce093*/
  v17[0x190] = "LIGHTS"; /*0x7ce09e*/
  v17[0x191] = "2"; /*0x7ce0a5*/
  v17[0x192] = "PROJ_SHADOW"; /*0x7ce0b0*/
  v17[0x193] = EmptyString; /*0x7ce0bb*/
  memset(&v17[0x194], 0, 0x38); /*0x7ce0c2*/
  v17[0x1A2] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce0d9*/
  v17[0x1A3] = "LIGHTS"; /*0x7ce0e4*/
  v17[0x1A4] = "2"; /*0x7ce0eb*/
  v17[0x1A5] = "SKIN"; /*0x7ce0f6*/
  v17[0x1A6] = EmptyString; /*0x7ce0fd*/
  v17[0x1A7] = "PROJ_SHADOW"; /*0x7ce104*/
  v17[0x1A8] = EmptyString; /*0x7ce10f*/
  memset(&v17[0x1A9], 0, 0x30); /*0x7ce116*/
  v17[0x1B5] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce12d*/
  v17[0x1B6] = "LIGHTS"; /*0x7ce138*/
  v17[0x1B7] = "3"; /*0x7ce13f*/
  memset(&v17[0x1B8], 0, 0x40); /*0x7ce14a*/
  v17[0x1C8] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce161*/
  v17[0x1C9] = "LIGHTS"; /*0x7ce16c*/
  v17[0x1CA] = "3"; /*0x7ce173*/
  v17[0x1CB] = "SKIN"; /*0x7ce17e*/
  v17[0x1CC] = EmptyString; /*0x7ce185*/
  memset(&v17[0x1CD], 0, 0x38); /*0x7ce18c*/
  v17[0x1DB] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce1a6*/
  v17[0x1DC] = "LIGHTS"; /*0x7ce1b1*/
  v17[0x1DD] = "3"; /*0x7ce1b8*/
  v17[0x1DE] = "PROJ_SHADOW"; /*0x7ce1c3*/
  v17[0x1DF] = EmptyString; /*0x7ce1ce*/
  memset(&v17[0x1E0], 0, 0x38); /*0x7ce1d5*/
  v17[0x1EE] = "lighting\\2x\\v\\AD.v.hlsl"; /*0x7ce1e1*/
  v17[0x1EF] = "LIGHTS"; /*0x7ce1ec*/
  v17[0x1F0] = "3"; /*0x7ce1f3*/
  v17[0x1F1] = "SKIN"; /*0x7ce1fe*/
  v17[0x1F2] = EmptyString; /*0x7ce205*/
  v17[0x1F3] = "PROJ_SHADOW"; /*0x7ce20c*/
  v17[0x1F4] = EmptyString; /*0x7ce217*/
  memset(&v17[0x1F5], 0, 0x30); /*0x7ce21e*/
  v17[0x201] = "lighting\\2x\\v\\DiffusePt.v.hlsl"; /*0x7ce240*/
  v17[0x202] = "LIGHTS"; /*0x7ce24b*/
  v17[0x203] = "2"; /*0x7ce252*/
  memset(&v17[0x204], 0, 0x40); /*0x7ce25d*/
  v17[0x214] = "lighting\\2x\\v\\DiffusePt.v.hlsl"; /*0x7ce274*/
  v17[0x215] = "LIGHTS"; /*0x7ce27f*/
  v17[0x216] = "2"; /*0x7ce286*/
  v17[0x217] = "SKIN"; /*0x7ce291*/
  v17[0x218] = EmptyString; /*0x7ce298*/
  memset(&v17[0x219], 0, 0x38); /*0x7ce29f*/
  v17[0x227] = "lighting\\2x\\v\\DiffusePt.v.hlsl"; /*0x7ce2b6*/
  v17[0x228] = "LIGHTS"; /*0x7ce2c1*/
  v17[0x229] = "3"; /*0x7ce2c8*/
  memset(&v17[0x22A], 0, 0x40); /*0x7ce2d3*/
  v17[0x23A] = "lighting\\2x\\v\\DiffusePt.v.hlsl"; /*0x7ce2ea*/
  v17[0x23B] = "LIGHTS"; /*0x7ce2f5*/
  v17[0x23C] = "3"; /*0x7ce2fc*/
  v17[0x23D] = "SKIN"; /*0x7ce307*/
  v17[0x23E] = EmptyString; /*0x7ce30e*/
  memset(&v17[0x23F], 0, 0x38); /*0x7ce315*/
  v17[0x24D] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce334*/
  memset(&v17[0x24E], 0, 0x48); /*0x7ce33b*/
  v17[0x260] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce352*/
  v17[0x261] = "SKIN"; /*0x7ce359*/
  v17[0x262] = EmptyString; /*0x7ce360*/
  memset(&v17[0x263], 0, 0x40); /*0x7ce367*/
  v17[0x273] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce37e*/
  v17[0x274] = "PROJ_SHADOW"; /*0x7ce385*/
  v17[0x275] = EmptyString; /*0x7ce390*/
  memset(&v17[0x276], 0, 0x40); /*0x7ce397*/
  v17[0x286] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce3a5*/
  v17[0x287] = "SKIN"; /*0x7ce3ac*/
  v17[0x288] = EmptyString; /*0x7ce3b3*/
  v17[0x289] = "PROJ_SHADOW"; /*0x7ce3ba*/
  v17[0x28A] = EmptyString; /*0x7ce3c5*/
  memset(&v17[0x28B], 0, 0x38); /*0x7ce3cc*/
  v17[0x299] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce3ec*/
  v17[0x29A] = "POINT"; /*0x7ce3f3*/
  v17[0x29B] = EmptyString; /*0x7ce3fe*/
  memset(&v17[0x29C], 0, 0x40); /*0x7ce405*/
  v17[0x2AC] = "lighting\\2x\\v\\Specular.v.hlsl"; /*0x7ce41c*/
  v17[0x2AD] = "SKIN"; /*0x7ce423*/
  v17[0x2AE] = EmptyString; /*0x7ce42a*/
  v17[0x2AF] = "POINT"; /*0x7ce431*/
  v17[0x2B0] = EmptyString; /*0x7ce43c*/
  memset(&v17[0x2B1], 0, 0x38); /*0x7ce443*/
  v17[0x2BF] = "lighting\\2x\\v\\EnvMap.v.hlsl"; /*0x7ce462*/
  v17[0x2C0] = "ENVMAP"; /*0x7ce46d*/
  v17[0x2C1] = EmptyString; /*0x7ce474*/
  memset(&v17[0x2C2], 0, 0x40); /*0x7ce47b*/
  v17[0x2D2] = "lighting\\2x\\v\\EnvMap.v.hlsl"; /*0x7ce492*/
  v17[0x2D3] = "SKIN"; /*0x7ce49d*/
  v17[0x2D4] = EmptyString; /*0x7ce4a4*/
  v17[0x2D5] = "ENVMAP"; /*0x7ce4ab*/
  v17[0x2D6] = EmptyString; /*0x7ce4b2*/
  memset(&v17[0x2D7], 0, 0x38); /*0x7ce4b9*/
  v17[0x2E5] = "lighting\\2x\\v\\EnvMap.v.hlsl"; /*0x7ce4d0*/
  v17[0x2E6] = "ENVMAP"; /*0x7ce4db*/
  v17[0x2E7] = EmptyString; /*0x7ce4e2*/
  v17[0x2E8] = &off_A90BE8; /*0x7ce4e9*/
  memset(&v17[0x2E9], 0, 0x3C); /*0x7ce4f4*/
  v17[0x2F8] = "lighting\\2x\\v\\decal.v.hlsl"; /*0x7ce51e*/
  v17[0x2F9] = "DECAL"; /*0x7ce529*/
  v17[0x2FA] = EmptyString; /*0x7ce534*/
  v17[0x2FB] = "MAXDECALS"; /*0x7ce53b*/
  v17[0x2FC] = Dest; /*0x7ce542*/
  memset(&v17[0x2FD], 0, 0x38); /*0x7ce549*/
  v17[0x30B] = "lighting\\2x\\v\\decal.v.hlsl"; /*0x7ce566*/
  v17[0x30C] = "DECAL"; /*0x7ce571*/
  v17[0x30D] = EmptyString; /*0x7ce57c*/
  v17[0x30E] = "ALPHA"; /*0x7ce583*/
  v17[0x30F] = EmptyString; /*0x7ce58e*/
  v17[0x310] = "MAXDECALS"; /*0x7ce595*/
  v17[0x311] = Dest; /*0x7ce59c*/
  memset(&v17[0x312], 0, 0x30); /*0x7ce5a3*/
  v17[0x31E] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ce5c0*/
  v17[0x31F] = "PROJ_SHADOW"; /*0x7ce5c7*/
  v17[0x320] = EmptyString; /*0x7ce5d2*/
  memset(&v17[0x321], 0, 0x40); /*0x7ce5d9*/
  v17[0x331] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ce5ea*/
  v17[0x332] = "LANDALPHA"; /*0x7ce5ff*/
  v17[0x333] = EmptyString; /*0x7ce606*/
  v17[0x334] = "PROJ_SHADOW"; /*0x7ce60d*/
  v17[0x335] = EmptyString; /*0x7ce618*/
  memset(&v17[0x336], 0, 0x38); /*0x7ce61f*/
  v17[0x344] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce636*/
  v17[0x345] = "DIFF"; /*0x7ce641*/
  v17[0x346] = EmptyString; /*0x7ce64c*/
  v17[0x347] = "PTLIGHT"; /*0x7ce653*/
  v17[0x348] = EmptyString; /*0x7ce65e*/
  memset(&v17[0x349], 0, 0x38); /*0x7ce665*/
  v17[0x357] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce67c*/
  v17[0x358] = "SPECULAR"; /*0x7ce687*/
  v17[0x359] = EmptyString; /*0x7ce692*/
  memset(&v17[0x35A], 0, 0x8C); /*0x7ce699*/
  v17[0x37D] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce6c7*/
  v17[0x37E] = "LANDALPHA"; /*0x7ce6d2*/
  v17[0x37F] = EmptyString; /*0x7ce6d9*/
  v17[0x380] = "DIFF"; /*0x7ce6e0*/
  v17[0x381] = EmptyString; /*0x7ce6eb*/
  v17[0x382] = "PTLIGHT"; /*0x7ce6f2*/
  v17[0x383] = EmptyString; /*0x7ce6fd*/
  memset(&v17[0x384], 0, 0x30); /*0x7ce704*/
  v17[0x390] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce71b*/
  v17[0x391] = "LANDALPHA"; /*0x7ce726*/
  v17[0x392] = EmptyString; /*0x7ce72d*/
  v17[0x393] = "SPECULAR"; /*0x7ce734*/
  v17[0x394] = EmptyString; /*0x7ce73f*/
  memset(&v17[0x395], 0, 0x84); /*0x7ce746*/
  v17[0x3B6] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce777*/
  v17[0x3B7] = "SPECULAR"; /*0x7ce782*/
  v17[0x3B8] = EmptyString; /*0x7ce78d*/
  v17[0x3B9] = "PROJ_SHADOW"; /*0x7ce794*/
  v17[0x3BA] = EmptyString; /*0x7ce79f*/
  memset(&v17[0x3BB], 0, 0x38); /*0x7ce7a6*/
  v17[0x3C9] = "lighting\\2x\\v\\landlighting.v.hlsl"; /*0x7ce7bd*/
  v17[0x3CA] = "LANDALPHA"; /*0x7ce7c8*/
  v17[0x3CB] = EmptyString; /*0x7ce7cf*/
  v17[0x3CC] = "SPECULAR"; /*0x7ce7d6*/
  v17[0x3CD] = EmptyString; /*0x7ce7e1*/
  v17[0x3CE] = "PROJ_SHADOW"; /*0x7ce7e8*/
  v17[0x3CF] = EmptyString; /*0x7ce7f3*/
  memset(&v17[0x3D0], 0, 0x30); /*0x7ce7fa*/
  v17[0x3DC] = "lighting\\2x\\v\\depthmap.v.hlsl"; /*0x7ce811*/
  v17[0x3DD] = "DEPTHMAP"; /*0x7ce81c*/
  v17[0x3DE] = EmptyString; /*0x7ce827*/
  memset(&v17[0x3DF], 0, 0x40); /*0x7ce82e*/
  v17[0x3EF] = "lighting\\2x\\v\\depthmap.v.hlsl"; /*0x7ce845*/
  v17[0x3F0] = "DEPTHMAP"; /*0x7ce850*/
  v17[0x3F1] = EmptyString; /*0x7ce85b*/
  v17[0x3F2] = "ALPHATEST"; /*0x7ce862*/
  v17[0x3F3] = EmptyString; /*0x7ce86d*/
  memset(&v17[0x3F4], 0, 0x38); /*0x7ce874*/
  v17[0x402] = "lighting\\2x\\v\\depthmap.v.hlsl"; /*0x7ce88b*/
  v17[0x403] = "DEPTHMAP"; /*0x7ce896*/
  v17[0x404] = EmptyString; /*0x7ce8a1*/
  v17[0x405] = "SKIN"; /*0x7ce8a8*/
  v17[0x406] = EmptyString; /*0x7ce8af*/
  memset(&v17[0x407], 0, 0x38); /*0x7ce8b6*/
  v17[0x415] = "lighting\\2x\\v\\depthmap.v.hlsl"; /*0x7ce8d0*/
  v17[0x416] = "DEPTHMAP"; /*0x7ce8db*/
  v17[0x417] = EmptyString; /*0x7ce8e6*/
  v17[0x418] = "SKIN"; /*0x7ce8ed*/
  v17[0x419] = EmptyString; /*0x7ce8f4*/
  v17[0x41A] = "ALPHATEST"; /*0x7ce8fb*/
  v17[0x41B] = EmptyString; /*0x7ce906*/
  memset(&v17[0x41C], 0, 0x30); /*0x7ce90d*/
  v17[0x428] = "lighting\\2x\\v\\depthmap.v.hlsl"; /*0x7ce924*/
  v17[0x429] = "DEPTHMAP"; /*0x7ce92f*/
  v17[0x42A] = EmptyString; /*0x7ce93a*/
  v17[0x42B] = "WATERDEPTH"; /*0x7ce941*/
  v17[0x42C] = EmptyString; /*0x7ce94c*/
  memset(&v17[0x42D], 0, 0x38); /*0x7ce953*/
  v17[0x43B] = "lighting\\2x\\v\\renderNormals.v.hlsl"; /*0x7ce95f*/
  memset(&v17[0x43C], 0, 0x48); /*0x7ce975*/
  v17[0x44E] = "lighting\\2x\\v\\renderNormals.v.hlsl"; /*0x7ce98c*/
  v17[0x44F] = "SKIN"; /*0x7ce997*/
  v17[0x450] = EmptyString; /*0x7ce99e*/
  memset(&v17[0x451], 0, 0x40); /*0x7ce9a5*/
  v17[0x461] = "lighting\\2x\\v\\renderNormals.v.hlsl"; /*0x7ce9bc*/
  v17[0x462] = "FIRE"; /*0x7ce9c7*/
  v17[0x463] = EmptyString; /*0x7ce9d2*/
  memset(&v17[0x464], 0, 0x40); /*0x7ce9d9*/
  v17[0x474] = "lighting\\2x\\v\\renderNormals.v.hlsl"; /*0x7ce9f0*/
  v17[0x475] = "CLEAR"; /*0x7ce9fb*/
  v17[0x476] = EmptyString; /*0x7cea06*/
  memset(&v17[0x477], 0, 0x40); /*0x7cea0d*/
  v17[0x487] = "lighting\\2x\\v\\renderNormals.v.hlsl"; /*0x7cea27*/
  v17[0x488] = "CLEAR"; /*0x7cea32*/
  v17[0x489] = EmptyString; /*0x7cea3d*/
  v17[0x48A] = "SKIN"; /*0x7cea44*/
  v17[0x48B] = EmptyString; /*0x7cea4b*/
  memset(&v17[0x48C], 0, 0x38); /*0x7cea52*/
  v17[0x49A] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7cea69*/
  memset(&v17[0x49B], 0, 0x48); /*0x7cea74*/
  v17[0x4AD] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7cea8b*/
  v17[0x4AE] = "LANDALPHA"; /*0x7cea96*/
  v17[0x4AF] = EmptyString; /*0x7cea9d*/
  memset(&v17[0x4B0], 0, 0x40); /*0x7ceaa4*/
  v17[0x4C0] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ceabb*/
  v17[0x4C1] = "LANDALPHA"; /*0x7ceac6*/
  v17[0x4C2] = EmptyString; /*0x7ceacd*/
  v17[0x4C3] = "LANDLO"; /*0x7cead4*/
  v17[0x4C4] = EmptyString; /*0x7ceadf*/
  memset(&v17[0x4C5], 0, 0x38); /*0x7ceae6*/
  v17[0x4D3] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ceaf4*/
  v17[0x4D4] = "LANDALPHA"; /*0x7ceaff*/
  v17[0x4D5] = EmptyString; /*0x7ceb06*/
  v17[0x4D6] = "SI"; /*0x7ceb0d*/
  v17[0x4D7] = EmptyString; /*0x7ceb18*/
  memset(&v17[0x4D8], 0, 0x38); /*0x7ceb1f*/
  v17[0x4E6] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ceb3f*/
  v17[0x4E7] = "PTLIGHT"; /*0x7ceb4a*/
  v17[0x4E8] = EmptyString; /*0x7ceb55*/
  memset(&v17[0x4E9], 0, 0x40); /*0x7ceb5c*/
  v17[0x4F9] = "lighting\\2x\\v\\land.v.hlsl"; /*0x7ceb76*/
  v17[0x4FA] = "LANDALPHA"; /*0x7ceb81*/
  v17[0x4FB] = EmptyString; /*0x7ceb88*/
  v17[0x4FC] = "PTLIGHT"; /*0x7ceb8f*/
  v17[0x4FD] = EmptyString; /*0x7ceb9a*/
  memset(&v17[0x4FE], 0, 0x38); /*0x7ceba1*/
  v17[0x50C] = "lighting\\2x\\v\\localMap.v.hlsl"; /*0x7cebbd*/
  memset(&v17[0x50D], 0, 0x48); /*0x7cebc4*/
  v17[0x51F] = "lighting\\2x\\v\\localMap.v.hlsl"; /*0x7cebdb*/
  v17[0x520] = "SKIN"; /*0x7cebe2*/
  v17[0x521] = EmptyString; /*0x7cebe9*/
  memset(&v17[0x522], 0, 0x40); /*0x7cebf0*/
  v17[0x532] = "lighting\\2x\\v\\localMap.v.hlsl"; /*0x7cec07*/
  v17[0x533] = "CLEAR"; /*0x7cec0e*/
  v17[0x534] = EmptyString; /*0x7cec19*/
  memset(&v17[0x535], 0, 0x40); /*0x7cec20*/
  v17[0x545] = "lighting\\1x\\v\\texEffect.v.hlsl"; /*0x7cec3c*/
  memset(&v17[0x546], 0, 0x48); /*0x7cec43*/
  v17[0x558] = "lighting\\1x\\v\\texEffect.v.hlsl"; /*0x7cec5a*/
  v17[0x559] = "SKIN"; /*0x7cec61*/
  v17[0x55A] = EmptyString; /*0x7cec68*/
  memset(&v17[0x55B], 0, 0x40); /*0x7cec6f*/
  v17[0x56B] = "lighting\\2x\\v\\SimpleShadow.v.hlsl"; /*0x7cec8e*/
  v17[0x56C] = "SHADOWMAP"; /*0x7cec99*/
  v17[0x56D] = EmptyString; /*0x7ceca0*/
  memset(&v17[0x56E], 0, 0x40); /*0x7ceca7*/
  v17[0x57E] = "lighting\\2x\\v\\SimpleShadow.v.hlsl"; /*0x7cecb3*/
  v17[0x57F] = "SHADOWMAP"; /*0x7cecbe*/
  v17[0x580] = EmptyString; /*0x7cecc5*/
  v17[0x581] = "SKIN"; /*0x7ceccc*/
  v17[0x582] = EmptyString; /*0x7cecde*/
  memset(&v17[0x583], 0, 0x38); /*0x7cece5*/
  v17[0x591] = "lighting\\2x\\v\\SimpleShadow.v.hlsl"; /*0x7cecfc*/
  v17[0x592] = "SHADOWMAP"; /*0x7ced07*/
  v17[0x593] = EmptyString; /*0x7ced0e*/
  v17[0x594] = "LAND"; /*0x7ced15*/
  v17[0x595] = EmptyString; /*0x7ced20*/
  v17[0x596] = "VC"; /*0x7ced27*/
  v17[0x597] = EmptyString; /*0x7ced32*/
  memset(&v17[0x598], 0, 0x30); /*0x7ced39*/
  v0 = 0; /*0x7ced48*/
  v1 = (char **)v19; /*0x7ced4a*/
  do /*0x7cedf5*/
  {
    if ( *v1 ) /*0x7ced51*/
    {
      sub_801030(*v1, (int)FileName); /*0x7ced64*/
      _sprintf(v21, "SLS1%03i.vso", v0); /*0x7ced77*/
      VertexShader = CreateVertexShader(FileName, v1 + 1, "vs_1_1", v21, 0, 0); /*0x7ced9e*/
      v3 = *(volatile LONG **)(4 * v0 + 0xB45290); /*0x7ceda3*/
      v14 = VertexShader; /*0x7cedac*/
      if ( v3 != (volatile LONG *)VertexShader ) /*0x7cedb0*/
      {
        if ( v3 ) /*0x7cedb4*/
        {
          if ( !InterlockedDecrement(v3 + 1) ) /*0x7cedba*/
            (**(void (__thiscall ***)(volatile LONG *, int))v3)(v3, 1); /*0x7cedd1*/
          VertexShader = v14; /*0x7cedd3*/
        }
        *(_DWORD *)(4 * v0 + 0xB45290) = VertexShader; /*0x7cedd9*/
        if ( VertexShader ) /*0x7cede0*/
          InterlockedIncrement((volatile LONG *)VertexShader + 1); /*0x7cede6*/
      }
    }
    ++v0; /*0x7cedec*/
    v1 += 0x13; /*0x7cedef*/
  }
  while ( v0 < 0x1F ); /*0x7cedf5*/
  v4 = (NiD3DShaderProgram **)v18; /*0x7cedfb*/
  v5 = 0; /*0x7cee02*/
  v15 = v18; /*0x7cee04*/
  do /*0x7ceeb5*/
  {
    result = *v4; /*0x7cee10*/
    if ( *v4 ) /*0x7cee10*/
    {
      sub_801030((char *)result, (int)FileName); /*0x7cee23*/
      _sprintf(v21, "SLS1S%03i.vso", v5); /*0x7cee36*/
      result = CreateVertexShader(FileName, v4 + 1, "vs_1_1", v21, 0, 0); /*0x7cee5d*/
      v7 = *(volatile LONG **)(4 * v5 + 0xB4530C); /*0x7cee62*/
      v8 = result; /*0x7cee69*/
      if ( v7 != (volatile LONG *)result ) /*0x7cee6d*/
      {
        if ( v7 ) /*0x7cee71*/
        {
          result = (NiD3DShaderProgram *)InterlockedDecrement(v7 + 1); /*0x7cee77*/
          if ( !result ) /*0x7cee7f*/
            result = (NiD3DShaderProgram *)(**(int (__thiscall ***)(volatile LONG *, int))v7)(v7, 1); /*0x7cee8d*/
        }
        *(_DWORD *)(4 * v5 + 0xB4530C) = v8; /*0x7cee91*/
        if ( v8 ) /*0x7cee98*/
          result = (NiD3DShaderProgram *)InterlockedIncrement((volatile LONG *)v8 + 1); /*0x7cee9e*/
      }
    }
    ++v5; /*0x7ceea8*/
    v4 = (NiD3DShaderProgram **)(v15 + 0x13); /*0x7ceeab*/
    v15 += 0x13; /*0x7ceeb1*/
  }
  while ( v5 < 0x16 ); /*0x7ceeb5*/
  if ( ShaderPackage >= 2 ) /*0x7ceec2*/
  {
    v9 = (NiD3DShaderProgram **)v17; /*0x7ceec8*/
    v10 = 0; /*0x7ceecc*/
    v16 = v17; /*0x7ceece*/
    do /*0x7cefaa*/
    {
      result = *v9; /*0x7ceed2*/
      if ( *v9 ) /*0x7ceed2*/
      {
        sub_801030((char *)result, (int)FileName); /*0x7cef18*/
        _sprintf(v21, "SLS2%03i.vso", v10); /*0x7cef2b*/
        result = CreateVertexShader(FileName, v9 + 1, "vs_2_0", v21, 0, 0); /*0x7cef52*/
        v12 = *(volatile LONG **)(4 * v10 + 0xB45364); /*0x7cef57*/
        v13 = result; /*0x7cef5e*/
        if ( v12 != (volatile LONG *)result ) /*0x7cef62*/
        {
          if ( v12 ) /*0x7cef66*/
          {
            result = (NiD3DShaderProgram *)InterlockedDecrement(v12 + 1); /*0x7cef6c*/
            if ( !result ) /*0x7cef74*/
              result = (NiD3DShaderProgram *)(**(int (__thiscall ***)(volatile LONG *, int))v12)(v12, 1); /*0x7cef82*/
          }
          *(_DWORD *)(4 * v10 + 0xB45364) = v13; /*0x7cef86*/
          if ( v13 ) /*0x7cef8d*/
            result = (NiD3DShaderProgram *)InterlockedIncrement((volatile LONG *)v13 + 1); /*0x7cef93*/
        }
      }
      else
      {
        v11 = *(_DWORD *)(4 * v10 + 0xB45364); /*0x7ceed8*/
        if ( v11 ) /*0x7ceee1*/
        {
          result = (NiD3DShaderProgram *)InterlockedDecrement((volatile LONG *)(v11 + 4)); /*0x7ceeeb*/
          if ( !result ) /*0x7ceef3*/
            result = (NiD3DShaderProgram *)(**(int (__thiscall ***)(int, int))v11)(v11, 1); /*0x7cef01*/
          *(_DWORD *)(4 * v10 + 0xB45364) = 0; /*0x7cef03*/
        }
      }
      ++v10; /*0x7cef9d*/
      v9 = (NiD3DShaderProgram **)(v16 + 0x13); /*0x7cefa0*/
      v16 += 0x13; /*0x7cefa6*/
    }
    while ( v10 < 0x4C ); /*0x7cefaa*/
  }
  return result; /*0x7cefb0*/
}
