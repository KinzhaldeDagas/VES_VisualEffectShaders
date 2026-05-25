// 0x9A6370 @ 0x9A6370
unsigned int __stdcall sub_9A6370(int a1, int a2, int a3)
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

  v3 = 0; /*0x9a6376*/
  v4 = *(_DWORD *)(a2 + 0x14); /*0x9a637f*/
  if ( !byte_B4295B ) /*0x9a6382*/
    sub_783C70(); /*0x9a6384*/
  if ( dword_B428D8[(unsigned __int8)v4] == 1 ) /*0x9a6397*/
  {
    dword_BAA930 = **(unsigned __int8 **)(a2 + 0x30); /*0x9a63a1*/
    v5 = (*(int (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, &dword_BAA930, 0); /*0x9a63ac*/
    goto LABEL_27; /*0x9a63ac*/
  }
  v6 = *(_DWORD *)(a2 + 0x14); /*0x9a63b7*/
  if ( !byte_B4295B ) /*0x9a63ba*/
    sub_783C70(); /*0x9a63bc*/
  if ( dword_B428D8[(unsigned __int8)v6] == 3 ) /*0x9a63cf*/
  {
    dword_BAA934 = **(_DWORD **)(a2 + 0x30); /*0x9a63d8*/
    dword_BAA938 = dword_BAA934; /*0x9a63dd*/
    dword_BAA93C = dword_BAA934; /*0x9a63e2*/
    dword_BAA940 = dword_BAA934; /*0x9a63e7*/
    v5 = (*(int (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, &dword_BAA934, 0); /*0x9a63f1*/
    goto LABEL_27; /*0x9a63f1*/
  }
  v7 = *(_DWORD *)(a2 + 0x14); /*0x9a63fc*/
  if ( !byte_B4295B ) /*0x9a63ff*/
    sub_783C70(); /*0x9a6401*/
  if ( dword_B428D8[(unsigned __int8)v7] == 4 ) /*0x9a6414*/
  {
    flt_BAA990 = **(float **)(a2 + 0x30); /*0x9a641b*/
    v8 = flt_BAA990; /*0x9a6421*/
    flt_BAA994 = flt_BAA990; /*0x9a6427*/
    flt_BAA998 = flt_BAA990; /*0x9a642d*/
LABEL_26:
    flt_BAA99C = v8; /*0x9a657e*/
    v5 = (*(int (__thiscall **)(int, int, float *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, &flt_BAA990, 0); /*0x9a6595*/
    goto LABEL_27; /*0x9a6595*/
  }
  v9 = *(_DWORD *)(a2 + 0x14); /*0x9a643e*/
  if ( !byte_B4295B ) /*0x9a6441*/
    sub_783C70(); /*0x9a6443*/
  if ( dword_B428D8[(unsigned __int8)v9] == 5 ) /*0x9a6456*/
  {
    v10 = *(float **)(a2 + 0x30); /*0x9a6458*/
    flt_BAA990 = *v10; /*0x9a645d*/
    flt_BAA994 = v10[1]; /*0x9a6466*/
    flt_BAA998 = flt_BAA990; /*0x9a6472*/
    v8 = flt_BAA994; /*0x9a6478*/
    goto LABEL_26; /*0x9a647e*/
  }
  if ( sub_783370((_DWORD *)a2) ) /*0x9a6485*/
  {
    v11 = *(float **)(a2 + 0x30); /*0x9a648e*/
    flt_BAA990 = *v11; /*0x9a6493*/
    flt_BAA994 = v11[1]; /*0x9a649c*/
    flt_BAA998 = v11[2]; /*0x9a64a5*/
    v8 = 1.0; /*0x9a64ab*/
    goto LABEL_26; /*0x9a64ad*/
  }
  if ( sub_7833A0((_DWORD *)a2) || sub_7833D0((_DWORD *)a2) ) /*0x9a64c3*/
  {
    v13 = *(float **)(a2 + 0x30); /*0x9a655e*/
    flt_BAA990 = *v13; /*0x9a6563*/
    flt_BAA994 = v13[1]; /*0x9a656c*/
    flt_BAA998 = v13[2]; /*0x9a6575*/
    v8 = v13[3]; /*0x9a657b*/
    goto LABEL_26; /*0x9a657b*/
  }
  if ( sub_782DE0((_DWORD *)a2) ) /*0x9a64d2*/
  {
    v12 = *(float **)(a2 + 0x30); /*0x9a64db*/
    flt_BAA9A0 = *v12; /*0x9a64e2*/
    flt_BAA9A4 = v12[1]; /*0x9a64f0*/
    flt_BAA9A8 = v12[2]; /*0x9a64f9*/
    flt_BAA9AC = 0.0; /*0x9a6501*/
    flt_BAA9B0 = v12[3]; /*0x9a650a*/
    flt_BAA9B4 = v12[4]; /*0x9a6513*/
    flt_BAA9B8 = v12[5]; /*0x9a651c*/
    flt_BAA9BC = 0.0; /*0x9a6522*/
    flt_BAA9C0 = v12[6]; /*0x9a652b*/
    flt_BAA9C4 = v12[7]; /*0x9a6534*/
    flt_BAA9C8 = v12[8]; /*0x9a653d*/
    flt_BAA9CC = 0.0; /*0x9a6543*/
    v5 = (*(int (__thiscall **)(int, int, float *, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, &flt_BAA9A0, 0); /*0x9a6549*/
  }
  else
  {
    if ( !sub_782E10((_DWORD *)a2) ) /*0x9a6554*/
      return v3; /*0x9a6554*/
    v5 = (*(int (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)a1 + 0x28))(a1, a2, *(_DWORD *)(a2 + 0x30), 0); /*0x9a655c*/
  }
LABEL_27:
  if ( !v5 ) /*0x9a6599*/
    return 0x80000050; /*0x9a659b*/
  return v3; /*0x9a65a0*/
}
