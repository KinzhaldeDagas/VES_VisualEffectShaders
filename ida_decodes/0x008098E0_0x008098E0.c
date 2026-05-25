// 0x008098E0 @ 0x008098E0
// MoonSugarEffect decode: SkinShader render selector. dword_B42E90 == 0x4E selects helper 0x0087FA20, pass index 0, and global pass dword_B47718[0]; later native setup consumes that selected pass through the normal shader-interface pass loop.
int __thiscall sub_8098E0(Ni2DBuffer **this, _DWORD *a2, int a3, int a4, NiRenderedTexture *a5, int a6, int a7, int a8)
{
  int pixelLayout; // esi
  BOOL v11; // eax
  NiRenderedTexture *v12; // edi
  BOOL v13; // edi
  const char *m_pcName; // eax
  float v16; // eax
  float v17; // ecx
  float v18; // edx
  double v19; // st7
  int v20; // eax
  double v21; // st7
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  unsigned __int16 v25; // ax
  int *v26; // eax
  unsigned __int16 v27; // ax
  BSShader *shader; // eax
  Ni2DBuffer *m_uiRefCount; // eax
  unsigned __int16 v30; // di
  int v31; // esi
  _DWORD *v32; // ecx
  _DWORD **v33; // esi
  char v34; // al
  _DWORD *v35; // ecx
  char v36; // [esp+1Bh] [ebp-41h]
  unsigned __int16 v37; // [esp+1Ch] [ebp-40h]
  int v38; // [esp+20h] [ebp-3Ch]
  _DWORD *v39; // [esp+24h] [ebp-38h]
  int v40; // [esp+28h] [ebp-34h] BYREF
  int v41; // [esp+2Ch] [ebp-30h]
  int v42; // [esp+30h] [ebp-2Ch]
  float v43; // [esp+34h] [ebp-28h]
  int v44; // [esp+38h] [ebp-24h]
  int v45; // [esp+3Ch] [ebp-20h]
  float v46; // [esp+40h] [ebp-1Ch]
  float v47; // [esp+44h] [ebp-18h]
  float v48; // [esp+48h] [ebp-14h]
  int v49; // [esp+4Ch] [ebp-10h]
  unsigned int v50; // [esp+58h] [ebp-4h]
  bool v51; // [esp+6Ch] [ebp+10h]

  ((void (__thiscall *)(Ni2DBuffer **))(*this)[6].members.width)(this); /*0x809911*/
  v38 = dword_B42E90; /*0x80991d*/
  if ( dword_B42E90 == 0x126 || dword_B42E90 == 0x123 ) /*0x80992c*/
    return sub_7C9F30(this, a2, a3, a4, a5, a6, a7, a8); /*0x80a054*/
  v37 = 0; /*0x809934*/
  v40 = 0; /*0x809938*/
  pixelLayout = a5->member.super.formatPrefs.pixelLayout; /*0x809940*/
  v50 = 0; /*0x809945*/
  v36 = 0; /*0x809949*/
  v11 = pixelLayout /*0x80996c*/
     && (*(int (__thiscall **)(int))(*(_DWORD *)pixelLayout + 0x54))(pixelLayout) >= 1
     && (*(int (__thiscall **)(int))(*(_DWORD *)pixelLayout + 0x54))(pixelLayout) <= 0xA;
  v39 = v11 ? (_DWORD *)pixelLayout : 0;
  v12 = 0; /*0x80997f*/
  if ( v39 )
  {
    v13 = pixelLayout /*0x8099a6*/
       && (*(int (__thiscall **)(int))(*(_DWORD *)pixelLayout + 0x54))(pixelLayout) >= 5
       && (*(int (__thiscall **)(int))(*(_DWORD *)pixelLayout + 0x54))(pixelLayout) <= 0xA;
    v12 = v13 ? (NiRenderedTexture *)pixelLayout : 0;
  }
  if ( !pixelLayout ) /*0x8099b7*/
  {
    if ( dword_B42E8C ) /*0x8099b9*/
      dword_B42E8C("Attempting to render geometry with a shader, but no shader property", 0); /*0x8099c8*/
    return 0; /*0x8099cf*/
  }
  m_pcName = a5->member.super.super.m_pcName; /*0x8099d8*/
  v51 = (*(_BYTE *)(pixelLayout + 0x1C) & 2) != 0; /*0x8099db*/
  if ( m_pcName && (m_pcName[0x18] & 1) != 0 ) /*0x8099ec*/
  {
    v16 = *(float *)&dword_B46498; /*0x8099f1*/
    v17 = *(float *)&dword_B4649C; /*0x8099f6*/
    v41 = *(int *)(pixelLayout + 0x20); /*0x8099fc*/
    v18 = *(float *)&dword_B464A0; /*0x809a00*/
    v46 = v16; /*0x809a06*/
    v19 = v16; /*0x809a0a*/
    v20 = dword_B464A4; /*0x809a0e*/
    *(float *)&v42 = v19; /*0x809a13*/
    v47 = v17; /*0x809a17*/
    v43 = v17; /*0x809a23*/
    v48 = v18; /*0x809a27*/
    v21 = v18; /*0x809a2b*/
    v22 = LODWORD(v17); /*0x809a2f*/
    *(float *)&v44 = v21; /*0x809a33*/
    v49 = v20; /*0x809a3b*/
    v23 = v44; /*0x809a3f*/
    v45 = v41; /*0x809a43*/
    dword_B46498 = v42; /*0x809a47*/
    v24 = v45; /*0x809a4d*/
    dword_B4649C = v22; /*0x809a51*/
    dword_B464A0 = v23; /*0x809a57*/
    dword_B464A4 = v24; /*0x809a5c*/
    v36 = 1; /*0x809a62*/
  }
  else
  {
    sub_7E2430(pixelLayout, 1.0); /*0x809a71*/
  }
  if ( v39 ) /*0x809a7f*/
  {
    if ( LOWORD(dword_B42EAC) == 1 ) /*0x809a8f*/
    {
      v27 = sub_7ED5D0(v39); /*0x809ac5*/
      if ( v27 > 0xAu ) /*0x809ad1*/
        v27 = 0xA; /*0x809ad3*/
      v26 = (int *)((char *)&unk_B2DD50 + 0x10 * v27); /*0x809ade*/
    }
    else
    {
      if ( LOWORD(dword_B42EAC) != 2 ) /*0x809a94*/
        goto LABEL_33; /*0x809a94*/
      v25 = (*(int (__thiscall **)(_DWORD *, _DWORD *))(*v39 + 0x60))(v39, a2); /*0x809aa4*/
      if ( v25 > 0x10u ) /*0x809aad*/
        v25 = 0x10; /*0x809aaf*/
      v26 = (int *)((char *)&unk_B2DE00 + 0x10 * v25); /*0x809aba*/
    }
    sub_7ECAE0(0, *v26, v26[1], v26[2], v26[3]); /*0x809b00*/
    sub_7ECAE0(0x19u, dword_B25AD0, dword_B25AD4, dword_B25AD8, dword_B25ADC); /*0x809b2f*/
  }
LABEL_33:
  shader = GetShaderDefinition(1u)->shader; /*0x809b37*/
  if ( v51 ) /*0x809b4e*/
    m_uiRefCount = (Ni2DBuffer *)shader[1].member.super.super.super.super.m_uiRefCount; /*0x809b50*/
  else
    m_uiRefCount = (Ni2DBuffer *)shader[1].__vftable; /*0x809b58*/
  NiSmartPointer_Set__(this + 9, m_uiRefCount); /*0x809b5c*/
  if ( v38 > 0x18C ) /*0x809b6a*/
  {
    switch ( v38 ) /*0x809e2f*/
    {
      case 0x18D: /*0x809e2f*/
        sub_851E70(this, a2, a3, (int)a5, v12); /*0x809ea9*/
        break;
      case 0x18E: /*0x809e2f*/
        sub_848950(this, a2, a3, (int)a5, v12); /*0x809e95*/
        break;
      case 0x18F: /*0x809e2f*/
        sub_848AD0(this, a2, a3, (int)a5, v12); /*0x809e81*/
        break;
      default:
LABEL_66:
        v31 = sub_7C9F30(this, a2, a3, a4, a5, a6, a7, a8); /*0x809e3b*/
        v50 = 0xFFFFFFFF; /*0x809e63*/
        sub_7016A0((NiD3DVertexShader *)&v40); /*0x809e6b*/
        return v31; /*0x809e72*/
    }
    goto LABEL_41; /*0x809e86*/
  }
  if ( v38 == 0x18C ) /*0x809b70*/
  {
    sub_851CA0(this, a2, a3, (int)a5, v12); /*0x809e20*/
LABEL_41:
    v30 = v37; /*0x809bc0*/
    sub_76C730(*(_DWORD **)(4 * v37 + 0xB47718), 0x1C, 0, 0); /*0x809bd4*/
    if ( (unsigned int)(v38 - 0x10F) > 0x1A ) /*0x809be5*/
    {
      if ( v38 == 0xA || v38 == 0xB ) /*0x809ecd*/
        sub_76C730(*(_DWORD **)(4 * v37 + 0xB47718), 0xA8, 8, 0); /*0x809efa*/
      else
        sub_76C730(*(_DWORD **)(4 * v37 + 0xB47718), 0xA8, 7, 0); /*0x809ee1*/
    }
    else
    {
      sub_76C730(*(_DWORD **)(4 * v37 + 0xB47718), 0xA8, 0xF, 0); /*0x809bfb*/
    }
    goto LABEL_75; /*0x809c00*/
  }
  switch ( v38 ) /*0x809b8b*/
  {
    case 0x4E: /*0x809b8b*/
      sub_87FA20((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809b9c*/
      v37 = 0; /*0x809ba1*/
      break; /*0x809ba1*/
    case 0x53: /*0x809b8b*/
      sub_87FBD0((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c0f*/
      v37 = 1; /*0x809c14*/
      break; /*0x809c1c*/
    case 0x59: /*0x809b8b*/
      sub_87FD80((NiTArray_NiD3DPass *)this, (int)a2, a3, (int)a5, v12); /*0x809d40*/
      v37 = 2; /*0x809d45*/
      break; /*0x809d4d*/
    case 0x5E: /*0x809b8b*/
      sub_87FFC0((NiTArray_NiD3DPass *)this, (int)a2, a3, (int)a5, v12); /*0x809d5c*/
      v37 = 3; /*0x809d61*/
      break; /*0x809d69*/
    case 0x64: /*0x809b8b*/
      sub_880200((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c28*/
      v37 = 4; /*0x809c2d*/
      break; /*0x809c35*/
    case 0x69: /*0x809b8b*/
      sub_8803B0((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c44*/
      v37 = 5; /*0x809c49*/
      break; /*0x809c51*/
    case 0x6F: /*0x809b8b*/
      sub_880560((NiTArray_NiD3DPass *)this, (int)a2, a3, (int)a5, v12); /*0x809d78*/
      v37 = 6; /*0x809d7d*/
      break; /*0x809d85*/
    case 0x74: /*0x809b8b*/
      sub_8807A0((NiTArray_NiD3DPass *)this, (int)a2, a3, (int)a5, v12); /*0x809d94*/
      v37 = 7; /*0x809d99*/
      break; /*0x809da1*/
    case 0x79: /*0x809b8b*/
      sub_8809E0((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c60*/
      v37 = 8; /*0x809c65*/
      break; /*0x809c6d*/
    case 0x7F: /*0x809b8b*/
      sub_880C00((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c7c*/
      v37 = 9; /*0x809c81*/
      break; /*0x809c89*/
    case 0x87: /*0x809b8b*/
      sub_880E20((NiTArray_NiD3DPass *)this, (int)a2, a3, a5, v12); /*0x809db0*/
      v37 = 0xA; /*0x809db5*/
      break; /*0x809dbd*/
    case 0x8D: /*0x809b8b*/
      sub_8810E0((NiTArray_NiD3DPass *)this, (int)a2, a3, a5, v12); /*0x809dcc*/
      v37 = 0xB; /*0x809dd1*/
      break; /*0x809dd9*/
    case 0x94: /*0x809b8b*/
      sub_8813A0((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809c98*/
      v37 = 0xC; /*0x809c9d*/
      break; /*0x809ca5*/
    case 0x9A: /*0x809b8b*/
      sub_881610((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809cb4*/
      v37 = 0xD; /*0x809cb9*/
      break; /*0x809cc1*/
    case 0xA1: /*0x809b8b*/
      sub_881880((NiTArray_NiD3DPass *)this, (int)a2, a3, a5, v12); /*0x809de8*/
      v37 = 0xE; /*0x809ded*/
      break; /*0x809df5*/
    case 0xA7: /*0x809b8b*/
      sub_881B80((NiTArray_NiD3DPass *)this, (int)a2, a3, a5, v12); /*0x809e04*/
      v37 = 0xF; /*0x809e09*/
      break; /*0x809e11*/
    case 0xE9: /*0x809b8b*/
      sub_881E80((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809cd0*/
      v37 = 0x10; /*0x809cd5*/
      break; /*0x809cdd*/
    case 0xEC: /*0x809b8b*/
      sub_881FD0((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809cec*/
      v37 = 0x11; /*0x809cf1*/
      break; /*0x809cf9*/
    case 0xF7: /*0x809b8b*/
      sub_882120((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809d08*/
      v37 = 0x12; /*0x809d0d*/
      break; /*0x809d15*/
    case 0xFA: /*0x809b8b*/
      sub_882270((unsigned int *)this, (int)a2, a3, (int)a5, v12); /*0x809d24*/
      v37 = 0x13; /*0x809d29*/
      break; /*0x809d31*/
    default:
      goto LABEL_66;
  }
  if ( v38 >= 0 ) /*0x809baf*/
    goto LABEL_41; /*0x809baf*/
  v30 = v37; /*0x809f01*/
LABEL_75:
  v32 = *(_DWORD **)(4 * v30 + 0xB47718); /*0x809f05*/
  v33 = (_DWORD **)(4 * v30 + 0xB47718); /*0x809f17*/
  if ( LOWORD(dword_B42EAC) == 4 ) /*0x809f20*/
  {
    sub_76C730(v32, 0x34, 1, 0); /*0x809f26*/
    sub_76C730(*v33, 0x38, 8, 0); /*0x809f33*/
    sub_76C730(*v33, 0x37, 7, 0); /*0x809f40*/
    sub_76C730(*v33, 0x35, 1, 0); /*0x809f4d*/
    sub_76C730(*v33, 0x36, 1, 0); /*0x809f5a*/
  }
  else
  {
    sub_76C730(v32, 0x34, 0, 0); /*0x809f60*/
  }
  if ( (unsigned int)(v38 - 0x33) > 0x15F ) /*0x809f72*/
  {
    if ( (unsigned int)(v38 - 3) <= 0xDB ) /*0x809fe7*/
      sub_76C730(*v33, 0x1B, v36 != 0, 0); /*0x809ffe*/
  }
  else
  {
    v34 = sub_7C8510(); /*0x809f74*/
    v35 = *v33; /*0x809f7b*/
    if ( v34 ) /*0x809f7f*/
    {
      if ( v36 ) /*0x809f86*/
      {
        sub_76C730(v35, 0x1B, 1, 0); /*0x809f97*/
        (*((void (__thiscall **)(_DWORD, const char *))(*(this + 6))->__vftable + 2))( /*0x809faa*/
          *(this + 6),
          a5->member.super.super.m_pcName);
      }
      else
      {
        sub_76C730(v35, 0x1B, 0, 0); /*0x809f8c*/
      }
      sub_76C730(*v33, 0x17, 4, 0); /*0x809fb4*/
      sub_76C730(*v33, 0xE, 1, 0); /*0x809fbf*/
    }
    else
    {
      sub_76C730(v35, 0x1B, 1, 0); /*0x809fc5*/
      sub_76C730(*v33, 0x17, 3, 0); /*0x809fd2*/
      sub_76C730(*v33, 0xE, 0, 0); /*0x809fdd*/
    }
  }
  if ( dword_B42EB8 ) /*0x80a003*/
  {
    if ( !*(_BYTE *)(dword_B42EB8 + 7) ) /*0x80a00c*/
      flt_B4668C = 0.0; /*0x80a014*/
  }
  v50 = 0xFFFFFFFF; /*0x80a01e*/
  sub_7016A0((NiD3DVertexShader *)&v40); /*0x80a026*/
  return 0; /*0x80a059*/
}
