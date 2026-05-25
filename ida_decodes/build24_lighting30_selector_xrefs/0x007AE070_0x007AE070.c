// 0x007AE070 @ 0x007AE070
// MoonSugarEffect decode: BSShaderAccumulator flush entry (+0x50). Sorts/dispatches queued render passes, handles occlusion/refraction/special lists, then clears pending flag through sub_733830.
void __thiscall BSShaderAccumulator::vtable_entry_0x14(_BYTE *this)
{
  bool v2; // zf
  int i; // edi
  int j; // edi
  ShaderDefinition *ShaderDefinition; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // edx
  NiObjectNET *v8; // eax
  int v9; // ecx
  int *v10; // edx
  float v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int **v14; // ebp
  int *v15; // eax
  int v16; // edi
  int v17; // edx
  int v18; // eax
  double v19; // st7
  int v20; // edx
  unsigned __int16 v21; // ax
  unsigned int v22; // edi
  int v23; // eax
  int k; // eax
  int *v25; // ecx
  int v26; // ebx
  float v27; // eax
  int v28; // ebp
  int v29; // edi
  int v30; // eax
  int v31; // edx
  int v32; // ecx
  int *v33; // eax
  int v34; // edx
  void (__thiscall *v35)(_BYTE *); // eax
  int v36; // eax
  int v37; // edx
  int v38; // ebx
  int v39; // ecx
  float v40; // eax
  int v41; // ebp
  int m; // edi
  float v43; // eax
  int n; // edi
  _DWORD *v45; // eax
  int ii; // edi
  _DWORD *jj; // ebp
  int *v48; // ecx
  int v49; // eax
  int v50; // ebx
  _DWORD *v51; // eax
  _DWORD **v52; // edi
  int *v53; // ebp
  int v54; // edi
  _DWORD *v55; // ebp
  int v56; // eax
  int v57; // ebp
  int v58; // ebp
  int v59; // edi
  _DWORD *kk; // ebp
  int *v61; // ecx
  int v62; // eax
  _DWORD *v63; // edi
  _DWORD *v64; // eax
  NiDX9Renderer *v65; // ebx
  NiScreenElements **v66; // edi
  unsigned int v67; // [esp+58h] [ebp-50h]
  int v68; // [esp+70h] [ebp-38h]
  int v69; // [esp+70h] [ebp-38h]
  _DWORD *v70; // [esp+70h] [ebp-38h]
  int v71; // [esp+74h] [ebp-34h] BYREF
  int v72; // [esp+78h] [ebp-30h] BYREF
  float v73; // [esp+7Ch] [ebp-2Ch]
  IDirect3DDevice9 *shader; // [esp+80h] [ebp-28h]
  float v75; // [esp+84h] [ebp-24h]
  NiDX9Renderer *v76; // [esp+88h] [ebp-20h]
  int v77[4]; // [esp+8Ch] [ebp-1Ch] BYREF
  int v78; // [esp+A4h] [ebp-4h]

  if ( *(this + 0x2268) )
  {
    if ( *((_DWORD *)this + 2) )
    {
      if ( *(this + 0x21E1) )
      {
        *(this + 0x2268) = 0; /*0x7ae0bc*/
        v2 = LOWORD(dword_B42EAC) == 5; /*0x7ae0cc*/
        v76 = g_Renderer; /*0x7ae0d3*/
        byte_B42CDD = 0; /*0x7ae0d7*/
        if ( v2 )
        {
          for ( i = 6; i <= 9; ++i ) /*0x7ae0df*/
            (*(void (__thiscall **)(_BYTE *, int, _DWORD))(*(_DWORD *)this + 0x60))(this, i, 0); /*0x7ae0ed*/
          for ( j = 0x154; j <= 0x155; ++j ) /*0x7ae0f7*/
            (*(void (__thiscall **)(_BYTE *, int, _DWORD))(*(_DWORD *)this + 0x60))(this, j, 0); /*0x7ae109*/
          sub_7AB6F0(this); /*0x7ae118*/
        }
        else
        {
          ShaderDefinition = GetShaderDefinition(1u); /*0x7ae133*/
          v6 = *((_DWORD **)this + 0x1A); /*0x7ae138*/
          shader = (IDirect3DDevice9 *)ShaderDefinition->shader; /*0x7ae146*/
          while ( v6 ) /*0x7ae14a*/
          {
            v7 = (_DWORD *)v6[2]; /*0x7ae150*/
            v6 = (_DWORD *)*v6; /*0x7ae156*/
            sub_7ABBC0(v7); /*0x7ae15b*/
          }
          sub_7AA6C0((_DWORD *)this + 0x880); /*0x7ae16a*/
          sub_7AA6C0((_DWORD *)this + 0x885); /*0x7ae175*/
          if ( byte_B42CD9 ) /*0x7ae17a*/
          {
            if ( LOWORD(dword_B42EAC) != 5 ) /*0x7ae189*/
            {
              v8 = sub_7A9E10(this); /*0x7ae18d*/
              NiSmartPointer_Set__((Ni2DBuffer **)&RenderWindowNiNode, (Ni2DBuffer *)v8); /*0x7ae198*/
              byte_B42CD9 = 0; /*0x7ae19d*/
            }
          }
          v2 = OcclusionCullngBool == 0; /*0x7ae1a3*/
          v9 = *((_DWORD *)this + 8); /*0x7ae1ac*/
          v10 = *((int **)this + 9); /*0x7ae1af*/
          v71 = *((_DWORD *)this + 0xA); /*0x7ae1b2*/
          v11 = *((float *)this + 0xB); /*0x7ae1b6*/
          v68 = v9; /*0x7ae1b9*/
          v72 = (int)v10; /*0x7ae1bd*/
          v75 = v11; /*0x7ae1c1*/
          if ( v2 || (v12 = *((_DWORD *)this + 0x54)) == 0 || byte_B42CDB || LOWORD(dword_B42EAC) == 5 )
          {
            if ( !byte_B42CDA ) /*0x7ae4f1*/
            {
              sub_7AA6C0((_DWORD *)this + 0x50); /*0x7ae4ff*/
              dword_B42CCC = 0; /*0x7ae504*/
            }
          }
          else
          {
            *((_WORD *)this + 0x10F2) = v12; /*0x7ae1f5*/
            *((_DWORD *)this + 8) = v12; /*0x7ae1fe*/
            *((_DWORD *)this + 9) = v12; /*0x7ae201*/
            *((_DWORD *)this + 0xA) = FormHeapAlloc((unsigned __int64)v12 >> 0x1E != 0 ? 0xFFFFFFFF : 4 * v12);
            v13 = FormHeapAlloc((unsigned __int64)*((unsigned int *)this + 9) >> 0x1E != 0 ? 0xFFFFFFFF : 4 * *((_DWORD *)this + 9));
            v14 = *((int ***)this + 0x51); /*0x7ae234*/
            *((_DWORD *)this + 0xB) = v13; /*0x7ae23a*/
            v15 = *((int **)this + 2); /*0x7ae23d*/
            v77[0] = v15[0x19]; /*0x7ae246*/
            v16 = 0; /*0x7ae24a*/
            v77[1] = v15[0x1C]; /*0x7ae251*/
            for ( v77[2] = v15[0x1F]; v14; *(float *)(v20 + 4 * v16 - 4) = v73 ) /*0x7ae25c*/
            {
              v17 = *v14[2]; /*0x7ae268*/
              v14 = (int **)*v14; /*0x7ae26a*/
              *(_DWORD *)(*((_DWORD *)this + 0xA) + 4 * v16) = v17; /*0x7ae26d*/
              v18 = *(_DWORD *)(*((_DWORD *)this + 0xA) + 4 * v16); /*0x7ae273*/
              v73 = *(float *)(v18 + 0x2C); /*0x7ae27e*/
              v19 = sub_47D9E0((float *)(v18 + 0x20), (float *)v77); /*0x7ae285*/
              v20 = *((_DWORD *)this + 0xB); /*0x7ae28e*/
              ++v16; /*0x7ae291*/
              v73 = v19 - v73; /*0x7ae296*/
            }
            *((_DWORD *)this + 8) = v16; /*0x7ae2a4*/
            *((_DWORD *)this + 9) = v16; /*0x7ae2a7*/
            sub_733380(this, 0, v16 - 1); /*0x7ae2b1*/
            v21 = *((_WORD *)this + 0x10F2); /*0x7ae2b6*/
            if ( v21 > *((_WORD *)this + 0x10F3) )
            {
              v22 = *((_DWORD *)this + 0x87A); /*0x7ae2ca*/
              *((_DWORD *)this + 0x87A) = FormHeapAlloc((unsigned __int64)v21 >> 0x1E != 0 ? 0xFFFFFFFF : 4 * v21);
              v23 = 0; /*0x7ae2f2*/
              if ( *((_WORD *)this + 0x10F3) ) /*0x7ae2f4*/
              {
                do /*0x7ae318*/
                {
                  *(_DWORD *)(*((_DWORD *)this + 0x87A) + 4 * v23) = *(_DWORD *)(v22 + 4 * v23); /*0x7ae309*/
                  ++v23; /*0x7ae313*/
                }
                while ( v23 < *((unsigned __int16 *)this + 0x10F3) ); /*0x7ae318*/
              }
              for ( k = *((unsigned __int16 *)this + 0x10F3); k < *((unsigned __int16 *)this + 0x10F2); ++k ) /*0x7ae32a*/
                *(_DWORD *)(*((_DWORD *)this + 0x87A) + 4 * k) = 0; /*0x7ae336*/
              FormHeapFree(v22); /*0x7ae348*/
              *((_WORD *)this + 0x10F3) = *((_WORD *)this + 0x10F2); /*0x7ae357*/
            }
            v25 = *((int **)this + 0xA); /*0x7ae35e*/
            *((_DWORD *)this + 0xC) = 0; /*0x7ae363*/
            v26 = *v25; /*0x7ae366*/
            *((_DWORD *)this + 0xC) = 1; /*0x7ae36b*/
            sub_7D1320((int *)3); /*0x7ae372*/
            (*((void (__thiscall **)(IDirect3DDevice9Vtbl *))shader[0xC].lpVtbl->QueryInterface + 0x12))(shader[0xC].lpVtbl); /*0x7ae386*/
            (*((void (__thiscall **)(IDirect3DDevice9Vtbl *))shader[0xB].lpVtbl->QueryInterface + 0x12))(shader[0xB].lpVtbl); /*0x7ae390*/
            shader = dword_B43104->member.device; /*0x7ae3a0*/
            v27 = COERCE_FLOAT(FormHeapAlloc(0x10u)); /*0x7ae3a4*/
            v73 = v27; /*0x7ae3ac*/
            v78 = 0; /*0x7ae3b2*/
            if ( v27 == 0.0 ) /*0x7ae3b6*/
              v28 = 0; /*0x7ae3cb*/
            else
              v28 = sub_7E2370(SLODWORD(v27), 0, 0, 1, 0, 0); /*0x7ae3c7*/
            v78 = 0xFFFFFFFF; /*0x7ae3cf*/
            *(_WORD *)(v28 + 4) = 3; /*0x7ae3d7*/
            *(_BYTE *)(v28 + 8) = 0; /*0x7ae3dd*/
            if ( v26 ) /*0x7ae3e1*/
            {
              v29 = 0; /*0x7ae3e7*/
              do /*0x7ae477*/
              {
                *(_DWORD *)v28 = v26; /*0x7ae3e9*/
                if ( !*(_DWORD *)(v29 + *((_DWORD *)this + 0x87A)) ) /*0x7ae3f4*/
                  shader->lpVtbl->CreateQuery( /*0x7ae409*/
                    shader,
                    D3DQUERYTYPE_OCCLUSION,
                    (IDirect3DQuery9 **)(v29 + *((_DWORD *)this + 0x87A)));
                (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(v29 + *((_DWORD *)this + 0x87A)) + 0x18))( /*0x7ae41c*/
                  *(_DWORD *)(v29 + *((_DWORD *)this + 0x87A)),
                  2);
                sub_7A9820((_DWORD *)v28, 3u); /*0x7ae423*/
                ++dword_B42CCC; /*0x7ae428*/
                dword_B42CC8 += (*(unsigned __int16 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)v28 + 0xB4) + 0x5C))(*(_DWORD *)(*(_DWORD *)v28 + 0xB4)); /*0x7ae445*/
                (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(v29 + *((_DWORD *)this + 0x87A)) + 0x18))( /*0x7ae45c*/
                  *(_DWORD *)(v29 + *((_DWORD *)this + 0x87A)),
                  1);
                v30 = *((_DWORD *)this + 0xC); /*0x7ae45e*/
                v29 += 4; /*0x7ae461*/
                if ( v30 >= *((_DWORD *)this + 8) ) /*0x7ae467*/
                  break; /*0x7ae467*/
                v26 = *(_DWORD *)(*((_DWORD *)this + 0xA) + 4 * v30); /*0x7ae46c*/
                *((_DWORD *)this + 0xC) = v30 + 1; /*0x7ae474*/
              }
              while ( v26 ); /*0x7ae477*/
            }
            sub_7E2400(v28); /*0x7ae47f*/
            FormHeapFree(v28); /*0x7ae485*/
            if ( !byte_B42CDA || LOWORD(dword_B42EAC) ) /*0x7ae496*/
              sub_7AA6C0((_DWORD *)this + 0x50); /*0x7ae4a6*/
            v31 = v71; /*0x7ae4ae*/
            v32 = v68; /*0x7ae4b2*/
            v71 = *((_DWORD *)this + 0xA); /*0x7ae4b6*/
            v68 = *((_DWORD *)this + 8); /*0x7ae4bd*/
            v33 = *((int **)this + 9); /*0x7ae4c1*/
            *((_DWORD *)this + 0xA) = v31; /*0x7ae4c4*/
            v34 = v72; /*0x7ae4c7*/
            v72 = (int)v33; /*0x7ae4cb*/
            v67 = *((_DWORD *)this + 0xB); /*0x7ae4d2*/
            *((_DWORD *)this + 8) = v32; /*0x7ae4d3*/
            *((_DWORD *)this + 9) = v34; /*0x7ae4d6*/
            FormHeapFree(v67); /*0x7ae4d9*/
            *((float *)this + 0xB) = v75; /*0x7ae4e5*/
          }
          v35 = *(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 0x5C); /*0x7ae50c*/
          *((_DWORD *)this + 7) = 0; /*0x7ae511*/
          v35(this); /*0x7ae514*/
          if ( OcclusionCullngBool ) /*0x7ae516*/
          {
            if ( dword_B42CCC ) /*0x7ae523*/
            {
              if ( !byte_B42CDB && LOWORD(dword_B42EAC) != 5 ) /*0x7ae543*/
              {
                v36 = *((_DWORD *)this + 8); /*0x7ae549*/
                v37 = v68; /*0x7ae550*/
                v38 = *((_DWORD *)this + 0xA); /*0x7ae554*/
                *((_DWORD *)this + 0xA) = v71; /*0x7ae557*/
                v39 = v72; /*0x7ae55a*/
                v69 = v36; /*0x7ae55e*/
                v40 = *((float *)this + 9); /*0x7ae562*/
                v41 = 0; /*0x7ae565*/
                v2 = *((_WORD *)this + 0x10F2) == 0; /*0x7ae567*/
                *((_DWORD *)this + 8) = v37; /*0x7ae56e*/
                v75 = v40; /*0x7ae571*/
                *((_DWORD *)this + 9) = v39; /*0x7ae575*/
                if ( !v2 ) /*0x7ae578*/
                {
                  do /*0x7ae601*/
                  {
                    for ( m = 4 * v41; /*0x7ae5a4*/
                          (*(int (__stdcall **)(_DWORD, int *, int, int))(**(_DWORD **)(m + *((_DWORD *)this + 0x87A))
                                                                        + 0x1C))(
                            *(_DWORD *)(m + *((_DWORD *)this + 0x87A)),
                            &v72,
                            4,
                            1) == 1;
                          ++dword_B42CA8 )
                    {
                      ; /*0x7ae5b0*/
                    }
                    if ( !v72 ) /*0x7ae5db*/
                    {
                      sub_7ABDE0((_DWORD *)this + 0x87B, (int *)(m + *((_DWORD *)this + 0xA))); /*0x7ae5e9*/
                      ++dword_B42CB8; /*0x7ae5ee*/
                    }
                    ++v41; /*0x7ae5fc*/
                  }
                  while ( v41 < *((unsigned __int16 *)this + 0x10F2) ); /*0x7ae601*/
                }
                if ( *((_DWORD *)this + 0x87A) ) /*0x7ae607*/
                {
                  if ( !byte_B42CDA ) /*0x7ae610*/
                    *((_WORD *)this + 0x10F2) = 0; /*0x7ae619*/
                }
                if ( *((int *)this + 8) > 0 ) /*0x7ae626*/
                  FormHeapFree(*((_DWORD *)this + 0xA)); /*0x7ae62c*/
                v43 = v75; /*0x7ae638*/
                *((_DWORD *)this + 0xA) = v38; /*0x7ae63c*/
                *((_DWORD *)this + 8) = v69; /*0x7ae63f*/
                *((float *)this + 9) = v43; /*0x7ae642*/
              }
            }
          }
          if ( byte_B42CDA ) /*0x7ae647*/
          {
            if ( !LOWORD(dword_B42EAC) ) /*0x7ae650*/
              byte_B42CDB = 1; /*0x7ae659*/
          }
          for ( n = 4; n < 0x17C; ++n ) /*0x7ae660*/
            (*(void (__thiscall **)(_BYTE *, int, _DWORD))(*(_DWORD *)this + 0x60))(this, n, 0); /*0x7ae66e*/
          v45 = *((_DWORD **)this + 0x1E); /*0x7ae67b*/
          if ( v45 ) /*0x7ae680*/
          {
            if ( v45[4] ) /*0x7ae682*/
              sub_7ABAC0(v45, 0); /*0x7ae68b*/
          }
          if ( *((_DWORD *)this + 0x23) ) /*0x7ae690*/
          {
            sub_7AA550((_DWORD *)this + 0x1F, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7ae6a4*/
            sub_7F8DB0(*((int **)this + 0x899), (_DWORD *)this + 0x1F, 0x76); /*0x7ae6b2*/
          }
          if ( *((_DWORD *)this + 0x28) ) /*0x7ae6b7*/
          {
            sub_7AA550((_DWORD *)this + 0x24, (int (__cdecl *)(_DWORD *, _DWORD *))sub_7AA390); /*0x7ae6cc*/
            sub_7F9410(*((int **)this + 0x899), (_DWORD *)this + 0x24, 0x195); /*0x7ae6dd*/
          }
          for ( ii = 0x17C; ii < 0x198; ++ii ) /*0x7ae6e2*/
            (*(void (__thiscall **)(_BYTE *, int, _DWORD))(*(_DWORD *)this + 0x60))(this, ii, 0); /*0x7ae6f0*/
          if ( *((_DWORD *)this + 0x12) ) /*0x7ae6fd*/
          {
            for ( jj = *(_DWORD **)(*((_DWORD *)this + 0x10) + 8); jj; jj = *(_DWORD **)(*((_DWORD *)this + 0x10) + 8) ) /*0x7ae70a*/
            {
              sub_7ABAC0(jj, 0); /*0x7ae714*/
              *jj = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7ae71a*/
              FormHeapFree((unsigned int)jj); /*0x7ae721*/
              v48 = *((int **)this + 0x10); /*0x7ae726*/
              v49 = *v48; /*0x7ae729*/
              v2 = *v48 == 0; /*0x7ae72e*/
              *((_DWORD *)this + 0x10) = *v48; /*0x7ae730*/
              if ( v2 ) /*0x7ae733*/
                *((_DWORD *)this + 0x11) = 0; /*0x7ae73a*/
              else
                *(_DWORD *)(v49 + 4) = 0; /*0x7ae735*/
              (*(void (__thiscall **)(_BYTE *, int *))(*((_DWORD *)this + 0xF) + 8))(this + 0x3C, v48); /*0x7ae745*/
              if ( !--*((_DWORD *)this + 0x12) ) /*0x7ae74b*/
                break; /*0x7ae74e*/
            }
          }
          if ( !byte_B42CDB ) /*0x7ae75a*/
          {
            sub_7A9C30((int)(this + 0x21EC)); /*0x7ae76b*/
            *((_DWORD *)this + 0x87E) = *((_DWORD *)this + 0x87C); /*0x7ae773*/
            *((_DWORD *)this + 0x87C) = 0; /*0x7ae776*/
            *((_DWORD *)this + 0x87D) = 0; /*0x7ae779*/
            *((_DWORD *)this + 0x87F) = 0; /*0x7ae77c*/
          }
          v50 = *((_DWORD *)this + 0x88A); /*0x7ae786*/
          if ( *((_DWORD *)this + 0x88E) )
          {
            if ( v50 )
            {
              if ( !byte_B42CDB )
              {
                if ( byte_B42CDE )
                {
                  v51 = *((_DWORD **)this + 0x88C); /*0x7ae7b4*/
                  *((_DWORD *)this + 0x88F) = 0; /*0x7ae7ba*/
                  *(this + 0x2240) = 0; /*0x7ae7c4*/
                  v52 = *(_DWORD ***)(v50 + 0xBC); /*0x7ae7cb*/
                  v70 = v51; /*0x7ae7d3*/
                  if ( v52 )
                  {
                    if ( ((int (__thiscall *)(_DWORD **))(*v52)[7])(v52) < 1
                      || ((int (__thiscall *)(_DWORD **))(*v52)[7])(v52) > 5 )
                    {
                      if ( ((int (__thiscall *)(_DWORD **))(*v52)[7])(v52) == 0x1B )
                      {
                        v53 = (int *)(byte_B42CE0 != 0 ? 0x10 : 0x12A);
                        v72 = (int)v53; /*0x7ae85b*/
                        sub_7FD260((unsigned __int16)v53); /*0x7ae85f*/
                        (*(void (__thiscall **)(_DWORD *))(*v52[0xC] + 0x48))(v52[0xC]); /*0x7ae86f*/
                        (*(void (__thiscall **)(_DWORD *))(*v52[0xB] + 0x48))(v52[0xB]); /*0x7ae87b*/
                      }
                      else
                      {
                        LOWORD(v53) = v72; /*0x7ae87f*/
                      }
                    }
                    else
                    {
                      v72 = byte_B42CE0 != 0 ? 0x10 : 3;
                      LOWORD(v53) = v72; /*0x7ae80b*/
                      sub_7D1320((int *)v72); /*0x7ae812*/
                      (*(void (__thiscall **)(_DWORD *))(*v52[0xC] + 0x48))(v52[0xC]); /*0x7ae822*/
                      (*(void (__thiscall **)(_DWORD *))(*v52[0xB] + 0x48))(v52[0xB]); /*0x7ae82e*/
                    }
                    sub_7E2370((int)v77, v50, (__int16)v53, 0, 0, 0); /*0x7ae890*/
                    v78 = 1; /*0x7ae89d*/
                    while ( v70 ) /*0x7ae8a5*/
                    {
                      v54 = v70[2]; /*0x7ae8b4*/
                      v70 = (_DWORD *)*v70; /*0x7ae8be*/
                      if ( v54 ) /*0x7ae8c2*/
                      {
                        if ( *(_BYTE *)(v54 + 0x19) || !*(_BYTE *)(v54 + 0x1A) ) /*0x7ae8d2*/
                        {
                          *(_BYTE *)(v54 + 0x18) = 0; /*0x7ae9ef*/
                        }
                        else
                        {
                          *(_DWORD *)(v50 + 0x88) = *(_DWORD *)v54; /*0x7ae8de*/
                          *(_DWORD *)(v50 + 0x8C) = *(_DWORD *)(v54 + 4); /*0x7ae8e7*/
                          *(_DWORD *)(v50 + 0x90) = *(_DWORD *)(v54 + 8); /*0x7ae8f0*/
                          v75 = *(float *)(v54 + 0xC); /*0x7ae8f9*/
                          v55 = (_DWORD *)(v54 + 0x14); /*0x7ae8fd*/
                          *(float *)(v50 + 0x94) = v75; /*0x7ae904*/
                          if ( !*(_DWORD *)(v54 + 0x14) ) /*0x7ae90a*/
                            dword_B43104->member.device->lpVtbl->CreateQuery( /*0x7ae927*/
                              dword_B43104->member.device,
                              D3DQUERYTYPE_OCCLUSION,
                              (IDirect3DQuery9 **)(v54 + 0x14));
                          if ( *v55 ) /*0x7ae929*/
                          {
                            if ( *(_BYTE *)(v54 + 0x19) ) /*0x7ae934*/
                            {
                              for ( ; /*0x7ae94e*/
                                    (*(int (__stdcall **)(_DWORD, int *, int, int))(*(_DWORD *)*v55 + 0x1C))(
                                      *v55,
                                      &v71,
                                      4,
                                      1) == 1;
                                    ++dword_B42CAC )
                              {
                                ; /*0x7ae950*/
                              }
                              v56 = v71; /*0x7ae970*/
                              *(_BYTE *)(v54 + 0x18) = v71 == 0; /*0x7ae979*/
                              *(_DWORD *)(v54 + 0x1C) = v56; /*0x7ae97c*/
                              *(_BYTE *)(v54 + 0x19) = 0; /*0x7ae97f*/
                            }
                            if ( (*(int (__stdcall **)(_DWORD, int))(*(_DWORD *)*v55 + 0x18))(*v55, 2) /*0x7ae9ac*/
                              && ((*(void (__stdcall **)(_DWORD, int))(*(_DWORD *)*v55 + 0x18))(*v55, 1),
                                  (*(int (__stdcall **)(_DWORD, int))(*(_DWORD *)*v55 + 0x18))(*v55, 2)) )
                            {
                              v58 = *v55; /*0x7ae9d7*/
                              *(_BYTE *)(v54 + 0x19) = 0; /*0x7ae9da*/
                              *(_BYTE *)(v54 + 0x18) = 0; /*0x7ae9de*/
                              (*(void (__stdcall **)(int, int))(*(_DWORD *)v58 + 0x18))(v58, 1); /*0x7ae9eb*/
                            }
                            else
                            {
                              sub_7A9820(v77, v72); /*0x7ae9be*/
                              v57 = *v55; /*0x7ae9c3*/
                              *(_BYTE *)(v54 + 0x19) = 1; /*0x7ae9c6*/
                              (*(void (__stdcall **)(int, int))(*(_DWORD *)v57 + 0x18))(v57, 1); /*0x7ae9d3*/
                            }
                          }
                        }
                      }
                    }
                    v78 = 0xFFFFFFFF; /*0x7aea02*/
                    sub_7E2400((int)v77); /*0x7aea0a*/
                  }
                }
              }
            }
            *((_DWORD *)this + 0x88F) = 0; /*0x7aea0f*/
            *(this + 0x2240) = 0; /*0x7aea19*/
          }
          sub_7ACF40(this); /*0x7aea22*/
          if ( byte_B42CE2 ) /*0x7aea27*/
            *((_DWORD *)this + 7) = this + 0x2244; /*0x7aea36*/
          else
            *((_DWORD *)this + 7) = this + 0x2254; /*0x7aea41*/
          (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 0x5C))(this); /*0x7aea4b*/
          sub_7ACF40(this); /*0x7aea4f*/
          v59 = 0x198; /*0x7aea54*/
          v72 = 0x198; /*0x7aea59*/
          do /*0x7aeb51*/
          {
            (*(void (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 0x60))(this, v59, 1); /*0x7aea6b*/
            if ( v59 == 0x19B ) /*0x7aea73*/
            {
              if ( byte_B42CE2 ) /*0x7aea79*/
                *((_DWORD *)this + 7) = this + 0x2254; /*0x7aea88*/
              else
                *((_DWORD *)this + 7) = this + 0x2244; /*0x7aea93*/
              (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 0x5C))(this); /*0x7aea9d*/
              sub_7ACF40(this); /*0x7aeaa1*/
              v2 = *((_DWORD *)this + 0x16) == 0; /*0x7aeaa8*/
              *((_DWORD *)this + 7) = 0; /*0x7aeaab*/
              if ( !v2 ) /*0x7aeab2*/
              {
                for ( kk = *(_DWORD **)(*((_DWORD *)this + 0x14) + 8); kk; kk = *(_DWORD **)(*((_DWORD *)this + 0x14) + 8) ) /*0x7aeabc*/
                {
                  sub_7ABAC0(kk, 1); /*0x7aeac6*/
                  *kk = &BSTPersistentList<NiTPointerAllocator<unsigned int>,BSShaderProperty::RenderPass *>::`vftable'; /*0x7aeacc*/
                  FormHeapFree((unsigned int)kk); /*0x7aead3*/
                  v61 = *((int **)this + 0x14); /*0x7aead8*/
                  v62 = *v61; /*0x7aeadb*/
                  v2 = *v61 == 0; /*0x7aeae0*/
                  *((_DWORD *)this + 0x14) = *v61; /*0x7aeae2*/
                  if ( v2 ) /*0x7aeae5*/
                    *((_DWORD *)this + 0x15) = 0; /*0x7aeaec*/
                  else
                    *(_DWORD *)(v62 + 4) = 0; /*0x7aeae7*/
                  (*(void (__thiscall **)(_BYTE *, int *))(*((_DWORD *)this + 0x13) + 8))(this + 0x4C, v61); /*0x7aeaf7*/
                  if ( !--*((_DWORD *)this + 0x16) ) /*0x7aeafd*/
                    break; /*0x7aeb00*/
                }
              }
              v63 = *((_DWORD **)this + 0x871); /*0x7aeb0c*/
              while ( v63 ) /*0x7aeb1a*/
              {
                v64 = v63; /*0x7aeb23*/
                v63 = (_DWORD *)*v63; /*0x7aeb25*/
                (*(void (__thiscall **)(_BYTE *, _DWORD *))(*((_DWORD *)this + 0x870) + 8))(this + 0x21C0, v64); /*0x7aeb2d*/
              }
              v59 = v72; /*0x7aeb33*/
              *((_DWORD *)this + 0x873) = 0; /*0x7aeb37*/
              *((_DWORD *)this + 0x871) = 0; /*0x7aeb3a*/
              *((_DWORD *)this + 0x872) = 0; /*0x7aeb3d*/
            }
            v72 = ++v59; /*0x7aeb4d*/
          }
          while ( v59 <= 0x19F ); /*0x7aeb51*/
          sub_7ABAC0((_DWORD *)this + 0x29, 1); /*0x7aeb61*/
          if ( LOWORD(dword_B42EAC) == 4 ) /*0x7aeb6e*/
          {
            v65 = v76; /*0x7aeb74*/
            if ( v76 ) /*0x7aeb7a*/
            {
              if ( (v76->member.super.SceneState1 == 1 || v76->member.super.SceneState2 == 1) /*0x7aeb97*/
                && v76->member.super.IsReady == 1 )
              {
                v76->__vftable->super.SetupScreenSpaceCamera((NiRenderer *)v76, 0); /*0x7aeba5*/
              }
              v66 = (NiScreenElements **)dword_B42CF8; /*0x7aeba7*/
              do /*0x7aebc1*/
                sub_709C60(*v66++); /*0x7aebb3*/
              while ( (int)v66 < (int)&dword_B42D3C ); /*0x7aebc1*/
              if ( (v65->member.super.SceneState1 == 1 || v65->member.super.SceneState2 == 1) /*0x7aebda*/
                && v65->member.super.IsReady == 1 )
              {
                v65->__vftable->super.Clear((NiRenderer *)v65, 0, 2); /*0x7aebea*/
              }
              SetCameraViewProj(v65, *((NiCamera **)this + 2)); /*0x7aebf2*/
            }
          }
          sub_733830(this); /*0x7aebf9*/
        }
      }
    }
  }
}
