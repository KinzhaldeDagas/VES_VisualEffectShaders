// 0x9A3730 @ 0x9A3730
unsigned int __stdcall sub_9A3730(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // edi
  char v5; // al
  int v6; // edi
  int v7; // edi
  double v8; // st7
  int v9; // edi
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax

  v3 = 0; /*0x9a3736*/
  v4 = *(_DWORD *)(a2 + 0x14); /*0x9a373f*/
  if ( !byte_B4295B ) /*0x9a3742*/
    sub_783C70(); /*0x9a3744*/
  if ( dword_B428D8[(unsigned __int8)v4] == 1 ) /*0x9a3757*/
  {
    dword_BAA930 = **(unsigned __int8 **)(a2 + 0x30); /*0x9a3761*/
    v5 = (*(int (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, &dword_BAA930, 0); /*0x9a376c*/
    goto LABEL_27; /*0x9a376c*/
  }
  v6 = *(_DWORD *)(a2 + 0x14); /*0x9a3777*/
  if ( !byte_B4295B ) /*0x9a377a*/
    sub_783C70(); /*0x9a377c*/
  if ( dword_B428D8[(unsigned __int8)v6] == 3 ) /*0x9a378f*/
  {
    dword_BAA934 = **(_DWORD **)(a2 + 0x30); /*0x9a3798*/
    dword_BAA938 = dword_BAA934; /*0x9a379d*/
    dword_BAA93C = dword_BAA934; /*0x9a37a2*/
    dword_BAA940 = dword_BAA934; /*0x9a37a7*/
    v5 = (*(int (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, &dword_BAA934, 0); /*0x9a37b1*/
    goto LABEL_27; /*0x9a37b1*/
  }
  v7 = *(_DWORD *)(a2 + 0x14); /*0x9a37bc*/
  if ( !byte_B4295B ) /*0x9a37bf*/
    sub_783C70(); /*0x9a37c1*/
  if ( dword_B428D8[(unsigned __int8)v7] == 4 ) /*0x9a37d4*/
  {
    flt_BAA990 = **(float **)(a2 + 0x30); /*0x9a37db*/
    v8 = flt_BAA990; /*0x9a37e1*/
    flt_BAA994 = flt_BAA990; /*0x9a37e7*/
    flt_BAA998 = flt_BAA990; /*0x9a37ed*/
LABEL_26:
    flt_BAA99C = v8; /*0x9a393e*/
    v5 = (*(int (__thiscall **)(int, int, float *, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, &flt_BAA990, 0); /*0x9a3955*/
    goto LABEL_27; /*0x9a3955*/
  }
  v9 = *(_DWORD *)(a2 + 0x14); /*0x9a37fe*/
  if ( !byte_B4295B ) /*0x9a3801*/
    sub_783C70(); /*0x9a3803*/
  if ( dword_B428D8[(unsigned __int8)v9] == 5 ) /*0x9a3816*/
  {
    v10 = *(float **)(a2 + 0x30); /*0x9a3818*/
    flt_BAA990 = *v10; /*0x9a381d*/
    flt_BAA994 = v10[1]; /*0x9a3826*/
    flt_BAA998 = flt_BAA990; /*0x9a3832*/
    v8 = flt_BAA994; /*0x9a3838*/
    goto LABEL_26; /*0x9a383e*/
  }
  if ( sub_783370((_DWORD *)a2) ) /*0x9a3845*/
  {
    v11 = *(float **)(a2 + 0x30); /*0x9a384e*/
    flt_BAA990 = *v11; /*0x9a3853*/
    flt_BAA994 = v11[1]; /*0x9a385c*/
    flt_BAA998 = v11[2]; /*0x9a3865*/
    v8 = 1.0; /*0x9a386b*/
    goto LABEL_26; /*0x9a386d*/
  }
  if ( sub_7833A0((_DWORD *)a2) || sub_7833D0((_DWORD *)a2) ) /*0x9a3883*/
  {
    v13 = *(float **)(a2 + 0x30); /*0x9a391e*/
    flt_BAA990 = *v13; /*0x9a3923*/
    flt_BAA994 = v13[1]; /*0x9a392c*/
    flt_BAA998 = v13[2]; /*0x9a3935*/
    v8 = v13[3]; /*0x9a393b*/
    goto LABEL_26; /*0x9a393b*/
  }
  if ( sub_782DE0((_DWORD *)a2) ) /*0x9a3892*/
  {
    v12 = *(float **)(a2 + 0x30); /*0x9a389b*/
    flt_BAA9A0 = *v12; /*0x9a38a2*/
    flt_BAA9A4 = v12[1]; /*0x9a38b0*/
    flt_BAA9A8 = v12[2]; /*0x9a38b9*/
    flt_BAA9AC = 0.0; /*0x9a38c1*/
    flt_BAA9B0 = v12[3]; /*0x9a38ca*/
    flt_BAA9B4 = v12[4]; /*0x9a38d3*/
    flt_BAA9B8 = v12[5]; /*0x9a38dc*/
    flt_BAA9BC = 0.0; /*0x9a38e2*/
    flt_BAA9C0 = v12[6]; /*0x9a38eb*/
    flt_BAA9C4 = v12[7]; /*0x9a38f4*/
    flt_BAA9C8 = v12[8]; /*0x9a38fd*/
    flt_BAA9CC = 0.0; /*0x9a3903*/
    v5 = (*(int (__thiscall **)(int, int, float *, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, &flt_BAA9A0, 0); /*0x9a3909*/
  }
  else
  {
    if ( !sub_782E10((_DWORD *)a2) ) /*0x9a3914*/
      return v3; /*0x9a3914*/
    v5 = (*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)a1 + 0x30))(a1, a2, *(_DWORD *)(a2 + 0x30), 0); /*0x9a391c*/
  }
LABEL_27:
  if ( !v5 ) /*0x9a3959*/
    return 0x80000050; /*0x9a395b*/
  return v3; /*0x9a3960*/
}
