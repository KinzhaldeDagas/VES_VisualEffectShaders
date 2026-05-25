// 0x7C1B50 @ 0x7C1B50
// MoonSugarEffect decode: rendered surface cache searches available list for matching width/height/format/depth/usage, otherwise allocates a new BSRenderedTexture wrapper and moves it to in-use list.
int __thiscall NiRenderer_GetRenderedSurface(
        BSTextureManager *this,
        NiTPointerList_Node_void *a2,
        int a3,
        int a4,
        unsigned int a5,
        int a6,
        int a7)
{
  NiTPointerList_Node_void *v7; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  NiTPointerList_Node_void *v13; // edi
  _DWORD *data; // esi
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int *v23; // eax
  int *v24; // esi
  int v25; // eax
  int v26; // ecx
  bool v27; // cc
  int *v28; // edi
  Ni2DBuffer *v29; // eax
  NiTPointerList_Node_void *v30; // eax
  NiTPointerList_Node_void *end; // ecx
  _DWORD *v33; // [esp+10h] [ebp-10h]
  int v35; // [esp+18h] [ebp-8h]
  int v36; // [esp+1Ch] [ebp-4h]

  v7 = a2; /*0x7c1b55*/
  v33 = 0; /*0x7c1b69*/
  v9 = ((int (__thiscall *)(NiTPointerList_Node_void *))a2->next[0xA].prev)(a2); /*0x7c1b71*/
  v36 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 0x4C))(v9, 0); /*0x7c1b81*/
  v10 = ((int (__thiscall *)(NiTPointerList_Node_void *))v7->next[0xA].prev)(v7); /*0x7c1b8a*/
  v11 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 0x50))(v10, 0); /*0x7c1b95*/
  v12 = a6; /*0x7c1b97*/
  v35 = v11; /*0x7c1b9d*/
  if ( a6 ) /*0x7c1ba1*/
  {
    if ( (a5 & 8) == 0 ) /*0x7c1bac*/
    {
      switch ( a6 ) /*0x7c1bc5*/
      {
        case 0x14: /*0x7c1bc5*/
          if ( !byte_B42E98[5] ) /*0x7c1c14*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c14*/
          break; /*0x7c1c14*/
        case 0x15: /*0x7c1bc5*/
          if ( !byte_B42E98[6] ) /*0x7c1c1f*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c1f*/
          break; /*0x7c1c1f*/
        case 0x16: /*0x7c1bc5*/
          if ( !byte_B42E98[7] ) /*0x7c1c2a*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c2a*/
          break; /*0x7c1c2a*/
        case 0x17: /*0x7c1bc5*/
          if ( !byte_B42E98[0] ) /*0x7c1bd3*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1bd3*/
          break; /*0x7c1bd3*/
        case 0x18: /*0x7c1bc5*/
          if ( !byte_B42E98[1] ) /*0x7c1be5*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1be5*/
          break; /*0x7c1be5*/
        case 0x19: /*0x7c1bc5*/
          if ( !byte_B42E98[2] ) /*0x7c1bf3*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1bf3*/
          break; /*0x7c1bf3*/
        case 0x1A: /*0x7c1bc5*/
          if ( !byte_B42E98[3] ) /*0x7c1bfe*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1bfe*/
          break; /*0x7c1bfe*/
        case 0x24: /*0x7c1bc5*/
          if ( !byte_B42E98[0xA] ) /*0x7c1c4b*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c4b*/
          break; /*0x7c1c4b*/
        case 0x32: /*0x7c1bc5*/
          if ( !byte_B42E98[0xC] ) /*0x7c1c5a*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c61*/
          break; /*0x7c1c61*/
        case 0x51: /*0x7c1bc5*/
          if ( !byte_B42E98[4] ) /*0x7c1c09*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c09*/
          break; /*0x7c1c09*/
        case 0x71: /*0x7c1bc5*/
          if ( !byte_B42E98[9] ) /*0x7c1c40*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c40*/
          break; /*0x7c1c40*/
        case 0x72: /*0x7c1bc5*/
          if ( !byte_B42E98[8] ) /*0x7c1c35*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c35*/
          break; /*0x7c1c35*/
        case 0x74: /*0x7c1bc5*/
          if ( !byte_B42E98[0xB] ) /*0x7c1c56*/
            goto NiRenderer_GetRenderedSurface___def_7C1BC5; /*0x7c1c56*/
          break; /*0x7c1c56*/
        default:
NiRenderer_GetRenderedSurface___def_7C1BC5:
          if ( a6 == 0x24 ) /*0x7c1c66*/
          {
            a6 = 0x71; /*0x7c1c68*/
            v12 = 0x71; /*0x7c1c70*/
          }
          break; /*0x7c1c70*/
      }
    }
  }
  a2 = this->unk00.start; /*0x7c1c79*/
  v13 = a2; /*0x7c1c74*/
  if ( a2 )
  {
    do
    {
      if ( v33 ) /*0x7c1c88*/
      {
        a2 = v13; /*0x7c1dc5*/
        goto LABEL_67; /*0x7c1dc5*/
      }
      data = v13->data; /*0x7c1c8e*/
      v15 = *(_DWORD *)(*data + 0x20); /*0x7c1c93*/
      if ( v15 ) /*0x7c1c98*/
        v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 0x4C))(v15); /*0x7c1c9f*/
      else
        v16 = 0; /*0x7c1ca3*/
      if ( (v16 == a3
         || !a3
         && ((v17 = *(_DWORD *)(*data + 0x20)) == 0
           ? (v18 = 0)
           : (v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 0x4C))(v17)),
             v18 == v36))
        && ((v19 = *(_DWORD *)(*data + 0x20)) == 0
          ? (v20 = 0)
          : (v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 0x50))(v19)),
            (v20 == a4
          || !a4
          && ((v21 = *(_DWORD *)(*data + 0x20)) == 0
            ? (v22 = 0)
            : (v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v21 + 0x50))(v21)),
              v22 == v35))
         && data[1] == v12
         && data[2] == a7
         && (data[3] | 0x22) == (a5 | 0x22)) )
      {
        v33 = data; /*0x7c1d28*/
      }
      else
      {
        v13 = v13->next; /*0x7c1d2e*/
      }
    }
    while ( v13 );
    a2 = 0; /*0x7c1d3c*/
    if ( !v33 ) /*0x7c1d40*/
      goto LABEL_58; /*0x7c1d40*/
LABEL_67:
    sub_7AA860(this, &a2); /*0x7c1dc9*/
    *((_BYTE *)v33 + 0x10) = 1; /*0x7c1de0*/
    v28 = v33; /*0x7c1de3*/
  }
  else
  {
LABEL_58:
    v23 = (int *)FormHeapAlloc(0x14u); /*0x7c1d46*/
    if ( v23 ) /*0x7c1d52*/
    {
      *v23 = 0; /*0x7c1d54*/
      v24 = v23; /*0x7c1d5a*/
    }
    else
    {
      v24 = 0; /*0x7c1d5e*/
    }
    v25 = a7; /*0x7c1d64*/
    v24[3] = a5; /*0x7c1d68*/
    v26 = a3; /*0x7c1d6b*/
    v27 = a3 <= 0; /*0x7c1d6f*/
    v24[1] = v12; /*0x7c1d71*/
    v28 = v24; /*0x7c1d79*/
    v24[2] = v25; /*0x7c1d7b*/
    *((_BYTE *)v24 + 0x10) = 1; /*0x7c1d7e*/
    if ( v27 || a4 <= 0 ) /*0x7c1d88*/
      v29 = (Ni2DBuffer *)sub_7C1430(this, (int)v7, v36, v35, a6, v25, a5); /*0x7c1db6*/
    else
      v29 = (Ni2DBuffer *)sub_7C1430(this, (int)v7, v26, a4, a6, v25, a5); /*0x7c1d9a*/
    NiSmartPointer_Set__((Ni2DBuffer **)v24, v29); /*0x7c1dbe*/
  }
  v30 = (NiTPointerList_Node_void *)(*((int (__thiscall **)(NiTPointerList_void *))this->unk10.__vftable + 1))(&this->unk10); /*0x7c1df4*/
  v30->data = v28; /*0x7c1df6*/
  v30->next = 0; /*0x7c1df9*/
  v30->prev = this->unk10.end; /*0x7c1e02*/
  end = this->unk10.end; /*0x7c1e05*/
  if ( end ) /*0x7c1e0a*/
  {
    end->next = v30; /*0x7c1e0c*/
    ++this->unk10.numItems; /*0x7c1e0e*/
  }
  else
  {
    ++this->unk10.numItems; /*0x7c1e20*/
    this->unk10.start = v30; /*0x7c1e23*/
  }
  this->unk10.end = v30; /*0x7c1e11*/
  return *v28; /*0x7c1e16*/
}
