// 0x007FF4A0 @ 0x007FF4A0
int __thiscall sub_7FF4A0(NiTArray_NiD3DPass *this, float a2, int a3, int a4, float a5, int a6, int a7, int a8)
{
  int v9; // edi
  int v10; // esi
  BOOL v11; // eax
  signed int v12; // ebp
  int v13; // eax
  int v15; // esi
  float v16; // ecx
  float v17; // edx
  double v18; // st7
  double v19; // st6
  int v20; // edi
  bool v21; // zf
  float v22; // edx
  float v23; // eax
  int v24; // ecx
  double v25; // st7
  double v26; // st6
  int v27; // eax
  int v28; // edx
  double v29; // rt0
  int v30; // eax
  bool v31; // cl
  double v32; // st6
  double v33; // st6
  int v34; // edx
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  unsigned __int16 v38; // ax
  int v39; // ecx
  int i; // eax
  int j; // ecx
  int v42; // ecx
  int v43; // edx
  float v44; // eax
  int v45; // edx
  int v46; // eax
  int v47; // ecx
  int v48; // ecx
  int v49; // eax
  bool v50; // cc
  int v51; // eax
  double v52; // rtt
  double v53; // st6
  double v54; // st7
  UInt32 v55; // eax
  int v56; // eax
  NiD3DPass *v57; // esi
  int v58; // edi
  int v59; // ebp
  float *v60; // ecx
  double v61; // st7
  double v62; // st6
  double v63; // st5
  int v64; // eax
  double v65; // st6
  double v66; // st7
  int v67; // ecx
  int v68; // edx
  int v69; // eax
  float v70; // edx
  float v71; // eax
  float v72; // ecx
  int v73; // eax
  double v74; // st6
  int v75; // edx
  int v76; // eax
  int v77; // ecx
  int v78; // edx
  double v79; // rt0
  int v80; // edx
  int v81; // ecx
  int v82; // eax
  double v83; // rt1
  double v84; // st6
  double v85; // st7
  double v86; // rt2
  UInt32 Stage; // ebx
  int v88; // eax
  int v89; // edi
  int v90; // ebp
  NiTexture *Texture; // ebx
  int v92; // ebp
  UInt32 m_uiRefCount; // edi
  int v94; // edx
  int v95; // eax
  int v96; // edi
  int v97; // ebp
  char v98; // al
  _DWORD *Unk08; // edi
  NiRenderedTexture *InnerTexture; // eax
  char v101; // al
  float v102; // eax
  NiD3DPass *v103; // [esp-4h] [ebp-5Ch]
  float *v104; // [esp+18h] [ebp-40h]
  int v105; // [esp+1Ch] [ebp-3Ch]
  int v106; // [esp+20h] [ebp-38h]
  int v107; // [esp+24h] [ebp-34h]
  float v108; // [esp+28h] [ebp-30h]
  float v109; // [esp+28h] [ebp-30h]
  float v111; // [esp+30h] [ebp-28h] BYREF
  float v112; // [esp+34h] [ebp-24h]
  float v113; // [esp+38h] [ebp-20h]
  int v114; // [esp+3Ch] [ebp-1Ch]
  int v115; // [esp+40h] [ebp-18h]
  int v116; // [esp+44h] [ebp-14h]
  int v117; // [esp+48h] [ebp-10h]
  unsigned int v118; // [esp+54h] [ebp-4h]

  (*((void (__thiscall **)(NiTArray_NiD3DPass *))this->_vtbl + 0x20))(this); /*0x7ff4d5*/
  v9 = LODWORD(a5); /*0x7ff4d7*/
  v10 = *(_DWORD *)(LODWORD(a5) + 0x18); /*0x7ff4db*/
  if ( v10 ) /*0x7ff4e0*/
    v11 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v10 + 0x54))(*(_DWORD *)(LODWORD(a5) + 0x18)) == 0xA; /*0x7ff4f7*/
  else
    v11 = 0; /*0x7ff4e2*/
  v12 = dword_B42E90; /*0x7ff4f9*/
  v13 = v11 ? v10 : 0;
  v104 = (float *)v13; /*0x7ff50d*/
  v105 = dword_B42E90; /*0x7ff511*/
  if ( LOWORD(dword_B42EAC) == 5 ) /*0x7ff515*/
    return sub_7FF080(this, *(float *)&v13, v12, v9); /*0x7ff523*/
  v15 = *(_DWORD *)(v9 + 0x10); /*0x7ff528*/
  v16 = *(float *)(v15 + 0x44); /*0x7ff52e*/
  v17 = *(float *)(v15 + 0x48); /*0x7ff531*/
  v111 = *(float *)(v15 + 0x40); /*0x7ff535*/
  v112 = v16; /*0x7ff53e*/
  v107 = v15; /*0x7ff545*/
  v113 = v17; /*0x7ff549*/
  sub_7FAB60(v13, v15, v12); /*0x7ff54d*/
  v18 = 0.0; /*0x7ff560*/
  v19 = 1.0; /*0x7ff564*/
  if ( sub_8AA390(&v111, (float *)&dword_B3FA90) ) /*0x7ff55b*/
  {
    if ( UseHDR ) /*0x7ff56c*/
    {
      *(float *)&v106 = sub_507140(); /*0x7ff57e*/
      v111 = *(float *)&v106 * v111; /*0x7ff58c*/
      v112 = *(float *)&v106 * v112; /*0x7ff596*/
      v113 = *(float *)&v106 * v113; /*0x7ff59e*/
    }
    v20 = (int)v104; /*0x7ff5a2*/
    if ( (*(int (__thiscall **)(float *, _DWORD))(*(_DWORD *)v104 + 0x90))(v104, 0) ) /*0x7ff5b2*/
    {
      v25 = 1.0; /*0x7ff687*/
      if ( !UseHDR ) /*0x7ff680*/
      {
        if ( v111 >= 1.0 ) /*0x7ff694*/
          v111 = 1.0; /*0x7ff696*/
        if ( v112 >= 1.0 ) /*0x7ff6a3*/
          v112 = 1.0; /*0x7ff6a5*/
        if ( v113 >= 1.0 ) /*0x7ff6b2*/
          v113 = 1.0; /*0x7ff6b4*/
      }
      *(float *)&v114 = v111; /*0x7ff6bc*/
      v32 = v112; /*0x7ff6c4*/
      *(float *)&dword_B46FB8 = v111; /*0x7ff6c8*/
      *(float *)&v115 = v32; /*0x7ff6cd*/
      v33 = v113; /*0x7ff6d5*/
      dword_B46FBC = v115; /*0x7ff6d9*/
      *(float *)&v116 = v33; /*0x7ff6df*/
      v26 = 0.0; /*0x7ff6e7*/
      dword_B46FC0 = v116; /*0x7ff6e9*/
      *(float *)&v117 = 0.0; /*0x7ff6ef*/
      *(float *)&dword_B46FC4 = 0.0; /*0x7ff6f7*/
    }
    else
    {
      v21 = UseHDR == 0; /*0x7ff5bc*/
      v22 = *(float *)&dword_B46F7C; /*0x7ff5cd*/
      v23 = *(float *)&dword_B46F80; /*0x7ff5d3*/
      v114 = dword_B46F78; /*0x7ff5d8*/
      v24 = dword_B46F84; /*0x7ff5e0*/
      *(float *)&v114 = v111 + *(float *)&v114; /*0x7ff5ea*/
      *(float *)&v115 = v112 + v22; /*0x7ff5fa*/
      *(float *)&v116 = v113 + v23; /*0x7ff606*/
      v25 = 1.0; /*0x7ff60a*/
      if ( v21 ) /*0x7ff60c*/
      {
        if ( *(float *)&v114 >= 1.0 ) /*0x7ff617*/
          *(float *)&v114 = 1.0; /*0x7ff619*/
        if ( *(float *)&v115 >= 1.0 ) /*0x7ff626*/
          *(float *)&v115 = 1.0; /*0x7ff628*/
        if ( *(float *)&v116 >= 1.0 ) /*0x7ff635*/
          *(float *)&v116 = 1.0; /*0x7ff637*/
      }
      v26 = 0.0; /*0x7ff63f*/
      v27 = v115; /*0x7ff641*/
      dword_B46F78 = v114; /*0x7ff645*/
      v28 = v116; /*0x7ff64b*/
      dword_B46F7C = v27; /*0x7ff64f*/
      dword_B46F80 = v28; /*0x7ff654*/
      dword_B46F84 = v24; /*0x7ff65a*/
    }
    v29 = v26; /*0x7ff660*/
    v19 = v25; /*0x7ff660*/
    v18 = v29; /*0x7ff660*/
  }
  else
  {
    v20 = (int)v104; /*0x7ff701*/
  }
  v30 = dword_B42F40; /*0x7ff662*/
  v31 = (dword_B42F40 & 8) != 0 && (*(_BYTE *)(v20 + 0x1C) & 1) != 0; /*0x7ff679*/
  LOBYTE(v106) = v31; /*0x7ff70e*/
  if ( (v30 & 1) != 0 ) /*0x7ff712*/
    flt_B46FC8 = v19; /*0x7ff714*/
  else
    flt_B46FC8 = v18; /*0x7ff71e*/
  if ( (v30 & 2) != 0 ) /*0x7ff728*/
    flt_B46FCC = v19; /*0x7ff72a*/
  else
    flt_B46FCC = v18; /*0x7ff734*/
  if ( (v30 & 4) != 0 ) /*0x7ff73e*/
    flt_B46FD0 = v19; /*0x7ff740*/
  else
    flt_B46FD0 = v18; /*0x7ff74a*/
  if ( v31 ) /*0x7ff754*/
    flt_B46FD4 = v19; /*0x7ff756*/
  else
    flt_B46FD4 = v18; /*0x7ff760*/
  if ( v12 == 0x14E || v12 == 0x14F ) /*0x7ff776*/
  {
    if ( (*(_DWORD *)(v20 + 0x1C) & 0x800) != 0 ) /*0x7ff77f*/
      flt_B46FD4 = v18; /*0x7ff783*/
    else
      flt_B46FD4 = v19; /*0x7ff7e9*/
  }
  v34 = dword_B25AD4; /*0x7ff797*/
  v35 = dword_B25AD8; /*0x7ff79d*/
  dword_B46DE8 = dword_B25AD0; /*0x7ff7a2*/
  v36 = dword_B25ADC; /*0x7ff7a8*/
  dword_B46DEC = v34; /*0x7ff7ae*/
  dword_B46DF0 = v35; /*0x7ff7b4*/
  dword_B46DF4 = v36; /*0x7ff7b9*/
  if ( v12 >= 0x147 ) /*0x7ff7bf*/
  {
    if ( (unsigned int)(v12 - 0x152) > 1 ) /*0x7ff8b9*/
    {
      if ( v12 == 0x14D ) /*0x7ff8fa*/
      {
        if ( !(unsigned __int16)sub_7ED5D0((_DWORD *)v20) ) /*0x7ff906*/
        {
          if ( byte_B42CE3 ) /*0x7ff910*/
          {
            *(float *)&v114 = flt_A3D65C; /*0x7ff91e*/
            v115 = v114; /*0x7ff926*/
            v42 = v114; /*0x7ff92a*/
            v116 = v114; /*0x7ff92e*/
            v43 = v114; /*0x7ff932*/
            dword_B47008[0] = v114; /*0x7ff938*/
            *(float *)&v117 = 1.0; /*0x7ff93d*/
            dword_B4700C = v42; /*0x7ff941*/
            v44 = *(float *)&v117; /*0x7ff947*/
            dword_B47010 = v43; /*0x7ff94b*/
            flt_B47014 = v44; /*0x7ff951*/
          }
          else
          {
            v45 = dword_B46F7C; /*0x7ff95e*/
            v46 = dword_B46F80; /*0x7ff964*/
            dword_B47008[0] = dword_B46F78; /*0x7ff969*/
            v47 = dword_B46F84; /*0x7ff96f*/
            dword_B4700C = v45; /*0x7ff975*/
            dword_B47010 = v46; /*0x7ff97b*/
            LODWORD(flt_B47014) = v47; /*0x7ff980*/
          }
        }
        *(_DWORD *)(*((_DWORD *)this + 0x27) + 0x20) = 0xA; /*0x7ff98c*/
        v48 = dword_B2DCFC; /*0x7ff993*/
        v49 = 1; /*0x7ff999*/
        v50 = dword_B2DCFC <= 1; /*0x7ff99e*/
        LOBYTE(dword_B46939) = 1; /*0x7ff9a0*/
        BYTE1(dword_B46939) = 0; /*0x7ff9a7*/
        if ( !v50 ) /*0x7ff9ae*/
        {
          do /*0x7ff9c5*/
          {
            *(_BYTE *)(2 * v49 + 0xB4693A) = 0; /*0x7ff9b0*/
            *(_BYTE *)(2 * v49++ + 0xB46939) = 0; /*0x7ff9b8*/
          }
          while ( v49 < v48 ); /*0x7ff9c5*/
        }
        *(_BYTE *)(dword_B46C18 + 8) = 0; /*0x7ff9cd*/
      }
      else
      {
        v51 = *((_DWORD *)this + 0x27); /*0x7ff9dc*/
        if ( (unsigned int)(v12 - 0x14E) > 3 ) /*0x7ff9e2*/
        {
          *(_DWORD *)(v51 + 0x20) = 9; /*0x7ff9f5*/
          _memset(&dword_B46939, 0, 2 * dword_B2DCFC); /*0x7ffa11*/
          v54 = 0.0; /*0x7ffa16*/
          flt_B46FD8 = 0.0; /*0x7ffa18*/
        }
        else
        {
          v52 = v19; /*0x7ff9e4*/
          v53 = v18; /*0x7ff9e4*/
          v54 = v52; /*0x7ff9e4*/
          *(_DWORD *)(v51 + 0x20) = 0xB; /*0x7ff9e6*/
          flt_B46FD8 = v53; /*0x7ff9ed*/
        }
        v55 = dword_B46C18; /*0x7ffa21*/
        flt_B46FDC = v54; /*0x7ffa26*/
        *(_BYTE *)(v55 + 8) = 0; /*0x7ffa2c*/
      }
    }
    else
    {
      *(_BYTE *)(dword_B46C18 + 8) = 1; /*0x7ff8c3*/
      *(_BYTE *)(dword_B46C14 + 8) = 1; /*0x7ff8cf*/
      dword_B46939 = 0x1010101; /*0x7ff8d8*/
      dword_B4693D = 0x1010101; /*0x7ff8dd*/
      *(_DWORD *)(*((_DWORD *)this + 0x27) + 0x20) = 0x11; /*0x7ff8e8*/
    }
  }
  else
  {
    LOBYTE(v37) = *(_BYTE *)(dword_B42EB8 + 8); /*0x7ff7cb*/
    if ( (_BYTE)v37 ) /*0x7ff7d0*/
    {
      LOWORD(v37) = (unsigned __int8)v37; /*0x7ff7d8*/
      if ( dword_B2DCFC < (unsigned __int8)v37 ) /*0x7ff7dd*/
        v37 = dword_B2DCFC; /*0x7ff7df*/
      v38 = v37 - 1; /*0x7ff7e4*/
    }
    else
    {
      v38 = 0; /*0x7ff7f1*/
    }
    flt_B46FD8 = v19; /*0x7ff7f6*/
    flt_B46FDC = (float)v38; /*0x7ff808*/
    flt_B46FE0 = *(float *)(v15 + 0x4C); /*0x7ff811*/
    *(_DWORD *)(*((_DWORD *)this + 0x27) + 0x20) = 2 * v38 + 0xB; /*0x7ff81d*/
    if ( *(_DWORD *)(*(_DWORD *)(LODWORD(a2) + 0xB4) + 0x24) ) /*0x7ff82a*/
      v18 = v19; /*0x7ff835*/
    v39 = v38 + 1; /*0x7ff83b*/
    flt_B46FE4 = v18; /*0x7ff83e*/
    for ( i = 0; i < v39; ++i ) /*0x7ff848*/
    {
      *(_BYTE *)(2 * i + 0xB4693A) = 1; /*0x7ff850*/
      *(_BYTE *)(2 * i + 0xB46939) = 1; /*0x7ff858*/
    }
    for ( j = dword_B2DCFC; i < j; ++i ) /*0x7ff86f*/
    {
      *(_BYTE *)(2 * i + 0xB4693A) = 0; /*0x7ff880*/
      *(_BYTE *)(2 * i + 0xB46939) = 0; /*0x7ff888*/
    }
    *(_BYTE *)(dword_B46C18 + 8) = 0; /*0x7ff89d*/
    *(_BYTE *)(dword_B46C14 + 8) = 0; /*0x7ff8a7*/
  }
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 0xC) + 0x48))(*((_DWORD *)this + 0xC)); /*0x7ffa38*/
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 0xB) + 0x48))(*((_DWORD *)this + 0xB)); /*0x7ffa42*/
  v56 = sub_862B40(v12, (_DWORD *)v20, v106); /*0x7ffa4d*/
  v57 = (NiD3DPass *)v56; /*0x7ffa52*/
  if ( v56 ) /*0x7ffa56*/
  {
    if ( (unsigned int)(v12 - 0x15E) <= 1 ) /*0x7ffa65*/
      sub_7FEE40((NiGeometry *)LODWORD(a2), v20, v56); /*0x7ffa70*/
    v21 = (*(_BYTE *)(v20 + 0x1C) & 2) == 0; /*0x7ffa75*/
    v58 = *((_DWORD *)this + 9); /*0x7ffa7e*/
    if ( v21 ) /*0x7ffa81*/
      v59 = *((_DWORD *)this + 0x23); /*0x7ffa8b*/
    else
      v59 = *((_DWORD *)this + 0x24); /*0x7ffa83*/
    if ( v58 != v59 ) /*0x7ffa93*/
    {
      if ( v58 ) /*0x7ffa97*/
      {
        if ( !InterlockedDecrement((volatile LONG *)(v58 + 4)) ) /*0x7ffa9d*/
          (**(void (__thiscall ***)(int, int))v58)(v58, 1); /*0x7ffaaf*/
      }
      *((_DWORD *)this + 9) = v59; /*0x7ffab3*/
      if ( v59 ) /*0x7ffab6*/
        InterlockedIncrement((volatile LONG *)(v59 + 4)); /*0x7ffabc*/
    }
    if ( HIBYTE(dword_B46970) ) /*0x7ffac2*/
    {
      v60 = *(float **)(LODWORD(a5) + 0xC); /*0x7ffad3*/
      if ( !v60 ) /*0x7ffad8*/
      {
        *(float *)&v114 = flt_A93350; /*0x7ffc31*/
        dword_B46DB8 = v114; /*0x7ffc3b*/
        *(float *)&v115 = 0.0; /*0x7ffc41*/
        *(float *)&v116 = 1.0; /*0x7ffc4b*/
        *(float *)&dword_B46DBC = 0.0; /*0x7ffc4f*/
        v75 = dword_B25AD0; /*0x7ffc55*/
        v65 = 0.0; /*0x7ffc5b*/
        v66 = 1.0; /*0x7ffc5b*/
        *(float *)&v117 = 0.0; /*0x7ffc61*/
        dword_B46DC0 = v116; /*0x7ffc65*/
        v76 = dword_B25AD4; /*0x7ffc6e*/
        dword_B46DC4 = v117; /*0x7ffc73*/
        v77 = dword_B25AD8; /*0x7ffc79*/
        dword_B46DC8 = v75; /*0x7ffc7f*/
        v78 = dword_B25ADC; /*0x7ffc85*/
        dword_B46DCC = v76; /*0x7ffc8b*/
        dword_B46DD0 = v77; /*0x7ffc90*/
        dword_B46DD4 = v78; /*0x7ffc96*/
        goto LABEL_97; /*0x7ffc9c*/
      }
      v108 = v60[0xB]; /*0x7ffae1*/
      a5 = v60[0xC]; /*0x7ffae8*/
      v61 = 0.0; /*0x7ffaec*/
      v62 = a5; /*0x7ffaf8*/
      v63 = v108; /*0x7ffafd*/
      if ( a5 == 0.0 && 0.0 == v63 ) /*0x7ffb10*/
      {
        *(float *)&v114 = flt_A93350; /*0x7ffb1c*/
        dword_B46DB8 = v114; /*0x7ffb24*/
        *(float *)&v115 = 0.0; /*0x7ffb2a*/
        *(float *)&dword_B46DBC = 0.0; /*0x7ffb34*/
        v64 = dword_B25AD0; /*0x7ffb39*/
        *(float *)&v116 = 1.0; /*0x7ffb3e*/
        v65 = 0.0; /*0x7ffb46*/
        v66 = 1.0; /*0x7ffb46*/
        *(float *)&v117 = 0.0; /*0x7ffb48*/
        *(float *)&dword_B46DC0 = 1.0; /*0x7ffb4c*/
        v67 = dword_B25AD4; /*0x7ffb56*/
        dword_B46DC4 = v117; /*0x7ffb5c*/
        v68 = dword_B25AD8; /*0x7ffb62*/
        dword_B46DC8 = v64; /*0x7ffb68*/
        v69 = dword_B25ADC; /*0x7ffb6d*/
        dword_B46DCC = v67; /*0x7ffb72*/
        dword_B46DD0 = v68; /*0x7ffb78*/
        dword_B46DD4 = v69; /*0x7ffb7e*/
        goto LABEL_97; /*0x7ffb83*/
      }
      v70 = v60[8]; /*0x7ffb88*/
      v71 = v60[9]; /*0x7ffb8d*/
      v72 = v60[0xA]; /*0x7ffb90*/
      a5 = v62 - v63; /*0x7ffb93*/
      v111 = v70; /*0x7ffb97*/
      v112 = v71; /*0x7ffb9b*/
      *(float *)&v114 = v62; /*0x7ffb9f*/
      v113 = v72; /*0x7ffbab*/
      v73 = LODWORD(a5); /*0x7ffbb3*/
      dword_B46DB8 = v114; /*0x7ffbb9*/
      *(float *)&v116 = 1.0; /*0x7ffbbf*/
      dword_B46DBC = v73; /*0x7ffbc3*/
      *(float *)&v117 = 0.0; /*0x7ffbce*/
      dword_B46DC0 = v116; /*0x7ffbd2*/
      *(float *)&v114 = v111; /*0x7ffbe0*/
      dword_B46DC4 = v117; /*0x7ffbe4*/
      *(float *)&v115 = v112; /*0x7ffbf2*/
      dword_B46DC8 = v114; /*0x7ffbf6*/
      *(float *)&v116 = v113; /*0x7ffc03*/
      dword_B46DCC = v115; /*0x7ffc07*/
      v74 = 1.0; /*0x7ffc11*/
      *(float *)&v117 = 1.0; /*0x7ffc13*/
      dword_B46DD0 = v116; /*0x7ffc17*/
      dword_B46DD4 = v117; /*0x7ffc21*/
    }
    else
    {
      v61 = 0.0; /*0x7ffc9e*/
      v74 = 1.0; /*0x7ffca0*/
    }
    v79 = v74; /*0x7ffca2*/
    v65 = v61; /*0x7ffca2*/
    v66 = v79; /*0x7ffca2*/
LABEL_97:
    v21 = byte_B42CE3 == 0; /*0x7ffca4*/
    v80 = dword_B25AE8; /*0x7ffcb0*/
    v81 = dword_B25AE4; /*0x7ffcb6*/
    LODWORD(flt_B46FA8) = dword_B25AE0; /*0x7ffcbc*/
    v82 = dword_B25AEC; /*0x7ffcc1*/
    dword_B46FB0 = v80; /*0x7ffcc6*/
    dword_B46FAC = v81; /*0x7ffcd0*/
    dword_B46FB4 = v82; /*0x7ffcd6*/
    if ( v21 && (unsigned int)(v105 - 0x147) <= 6 ) /*0x7ffce6*/
    {
      a5 = *(float *)(v107 + 0x50); /*0x7ffcef*/
      v83 = v65; /*0x7ffcf3*/
      v84 = v66; /*0x7ffcf3*/
      v85 = v83; /*0x7ffcf3*/
      if ( v84 <= a5 ) /*0x7ffcfe*/
      {
        flt_B46FA8 = v104[0x29]; /*0x7ffd27*/
      }
      else
      {
        a5 = *(float *)(v107 + 0x50); /*0x7ffd07*/
        flt_B46FA8 = v104[0x29] * a5; /*0x7ffd15*/
      }
    }
    else
    {
      a5 = *(float *)(v107 + 0x50); /*0x7ffd36*/
      v86 = v65; /*0x7ffd3a*/
      v84 = v66; /*0x7ffd3a*/
      v85 = v86; /*0x7ffd3a*/
      if ( v84 <= a5 ) /*0x7ffd45*/
        flt_B46FA8 = v84; /*0x7ffd52*/
      else
        flt_B46FA8 = *(float *)(v107 + 0x50); /*0x7ffd4a*/
    }
    if ( (unsigned int)(v105 - 0x147) > 0x18 || (unsigned int)(v105 - 0x14E) <= 3 ) /*0x7ffd6c*/
    {
      Stage = v57->Stages.data->Stage; /*0x7ffd77*/
      v88 = (*(int (__thiscall **)(float *, _DWORD))(*(_DWORD *)v104 + 0x88))(v104, 0); /*0x7ffd89*/
      v89 = *(_DWORD *)(Stage + 4); /*0x7ffd8b*/
      v90 = v88; /*0x7ffd8e*/
      if ( v89 != v88 ) /*0x7ffd92*/
      {
        if ( v89 ) /*0x7ffd96*/
        {
          if ( !InterlockedDecrement((volatile LONG *)(v89 + 4)) ) /*0x7ffd9c*/
            (**(void (__thiscall ***)(int, int))v89)(v89, 1); /*0x7ffdb2*/
        }
        *(_DWORD *)(Stage + 4) = v90; /*0x7ffdb6*/
        if ( v90 ) /*0x7ffdb9*/
          InterlockedIncrement((volatile LONG *)(v90 + 4)); /*0x7ffdbf*/
      }
      Texture = v57->Stages.data->Texture; /*0x7ffdce*/
      if ( (*(int (__thiscall **)(float *, _DWORD))(*(_DWORD *)v104 + 0x8C))(v104, 0) ) /*0x7ffddb*/
        v92 = (*(int (__thiscall **)(float *, _DWORD))(*(_DWORD *)v104 + 0x8C))(v104, 0); /*0x7ffdef*/
      else
        v92 = dword_B430DC; /*0x7ffdf3*/
      m_uiRefCount = Texture->members.super.super.m_uiRefCount; /*0x7ffdf9*/
      if ( m_uiRefCount != v92 ) /*0x7ffdfe*/
      {
        if ( m_uiRefCount ) /*0x7ffe02*/
        {
          if ( !InterlockedDecrement((volatile LONG *)(m_uiRefCount + 4)) ) /*0x7ffe08*/
            (**(void (__thiscall ***)(UInt32, int))m_uiRefCount)(m_uiRefCount, 1); /*0x7ffe1e*/
        }
        Texture->members.super.super.m_uiRefCount = v92; /*0x7ffe22*/
        if ( v92 ) /*0x7ffe25*/
          InterlockedIncrement((volatile LONG *)(v92 + 4)); /*0x7ffe2b*/
      }
      v94 = dword_B25AD4; /*0x7ffe37*/
      v95 = dword_B25AD8; /*0x7ffe3d*/
      dword_B46FE8 = dword_B25AD0; /*0x7ffe42*/
      dword_B46FF4 = dword_B25ADC; /*0x7ffe4e*/
      dword_B46FEC = v94; /*0x7ffe58*/
      dword_B46FF0 = v95; /*0x7ffe5e*/
      if ( sub_7ED5C0(v104) /*0x7ffeb1*/
        && (unsigned int)(dword_B42E90 - 0x14E) <= 3
        && ((v96 = dword_B42EB8, v97 = **(_DWORD **)(dword_B42EB8 + 0xC), (v98 = *(_BYTE *)(v97 + 0xF4)) != 0)
         && *(_DWORD *)(v97 + 0x114)
         || *(_BYTE *)(v97 + 0x120))
        && *(_BYTE *)(v96 + 8) )
      {
        if ( v98 ) /*0x7ffebd*/
        {
          if ( sub_405A80() ) /*0x7ffebf*/
          {
            *(float *)&dword_B46FEC = 1.0; /*0x7ffeca*/
            Unk08 = (_DWORD *)v57->Stages.data->Unk08; /*0x7ffed3*/
            InnerTexture = BSRenderedTexture::GetInnerTexture(*(BSRenderedTexture **)(v97 + 0x114)); /*0x7ffedc*/
            sub_76C910(Unk08, InnerTexture); /*0x7ffee4*/
            sub_771640((_DWORD **)Unk08, 1); /*0x7ffeed*/
            sub_7715E0((_DWORD **)Unk08, 0); /*0x7ffef6*/
            v96 = dword_B42EB8; /*0x7ffefb*/
          }
        }
        v101 = *(_BYTE *)(v97 + 0x120); /*0x7fff06*/
        a5 = *(float *)(**(_DWORD **)(v96 + 0xC) + 0x128); /*0x7fff14*/
        if ( v101 ) /*0x7fff18*/
        {
          v85 = 0.0; /*0x7fff1a*/
          *(float *)&dword_B46FF4 = 0.0; /*0x7fff1c*/
          v84 = 1.0; /*0x7fff22*/
        }
        else
        {
          *(float *)&dword_B46FF4 = 1.0; /*0x7fff32*/
          v84 = 1.0; /*0x7fff3a*/
          v85 = 0.0; /*0x7fff3a*/
        }
        *(float *)&dword_B46FF0 = a5; /*0x7fff28*/
      }
      else
      {
        v85 = 0.0; /*0x7fff48*/
        v84 = 1.0; /*0x7fff4a*/
      }
    }
    if ( v105 == 0x14D ) /*0x7fff56*/
    {
      v102 = a2; /*0x7fff58*/
      a2 = *(float *)(LODWORD(a2) + 0x20) - CameraWorldTranslate; /*0x7fff65*/
      a5 = *(float *)(LODWORD(v102) + 0x24) - flt_B3F930; /*0x7fff72*/
      v109 = *(float *)(LODWORD(v102) + 0x28) - flt_B3F934; /*0x7fff7f*/
      flt_B46E08 = a2; /*0x7fff87*/
      flt_B46E0C = a5; /*0x7fff91*/
      flt_B46E10 = v109; /*0x7fff9b*/
    }
    if ( ((_DWORD)v104[7] & 0x80000) != 0 ) /*0x7fffac*/
    {
      v21 = v57->RenderStateGroup == 0; /*0x7fffae*/
      a2 = v84; /*0x7fffb4*/
      if ( v21 ) /*0x7fffb8*/
        v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x7fffbf*/
      sub_772CD0((_DWORD *)v57->RenderStateGroup, 0xAF, SLODWORD(a2), 0); /*0x7fffd1*/
      v21 = v57->RenderStateGroup == 0; /*0x7fffdc*/
      a2 = flt_A77830; /*0x7fffe0*/
      if ( v21 ) /*0x7fffe4*/
        v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x7fffeb*/
    }
    else
    {
      a2 = v85; /*0x800005*/
      if ( (unsigned int)(v105 - 0x14E) > 3 ) /*0x800009*/
      {
        if ( !v57->RenderStateGroup ) /*0x80004e*/
          v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x800059*/
        sub_772CD0((_DWORD *)v57->RenderStateGroup, 0xAF, SLODWORD(a2), 0); /*0x80006b*/
        v21 = v57->RenderStateGroup == 0; /*0x800072*/
        a2 = 0.0; /*0x800076*/
        if ( v21 ) /*0x80007a*/
          v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x800081*/
      }
      else
      {
        if ( !v57->RenderStateGroup ) /*0x80000b*/
          v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x800016*/
        sub_772CD0((_DWORD *)v57->RenderStateGroup, 0xAF, SLODWORD(a2), 0); /*0x800028*/
        v21 = v57->RenderStateGroup == 0; /*0x800033*/
        a2 = flt_A906F4; /*0x800037*/
        if ( v21 ) /*0x80003b*/
          v57->RenderStateGroup = (NiD3DRenderStateGroup *)sub_772DF0(); /*0x800042*/
      }
    }
    sub_772CD0((_DWORD *)v57->RenderStateGroup, 0xC3, SLODWORD(a2), 0); /*0x800093*/
    ++v57->RefCount; /*0x80009d*/
    a2 = *(float *)&v57; /*0x8000a0*/
    v103 = *((NiD3DPass **)this + 0xE); /*0x8000b0*/
    v118 = 0; /*0x8000b4*/
    sub_76CE40(this + 4, v103, (NiD3DPass **)&a2); /*0x8000bc*/
    v21 = v57->RefCount-- == 1; /*0x8000c4*/
    v118 = 0xFFFFFFFF; /*0x8000c7*/
    if ( v21 ) /*0x8000cb*/
      sub_7604D0(v57); /*0x8000cf*/
    ++*((_DWORD *)this + 0xE); /*0x8000d4*/
  }
  return 0; /*0x8000d9*/
}
