// 0x497E70 @ 0x497E70
// MoonSugarEffect decode: display/render resize recreate caller. Recreates Gamebryo render dimensions, then calls RecreateImageSpaceShader before rebuilding accumulators and scenegraphs.
void __usercall sub_497E70(char a1@<bpl>, double a2@<st2>, double a3@<st1>)
{
  BSShaderAccumulator *inited; // eax
  int v4; // ecx
  double v5; // st7
  int v6; // esi
  _DWORD *v7; // edi
  HWND window; // esi
  LONG v9; // eax
  LONG v10; // ecx
  LONG WindowLongA; // eax
  _DWORD *v12; // eax
  BSShaderAccumulator *v13; // eax
  NiDX9Renderer *v14; // ecx
  HWND v15; // [esp-8h] [ebp-38h]
  DWORD ClassLongA; // [esp-4h] [ebp-34h]
  struct tagRECT Rect; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int v18; // [esp+2Ch] [ebp-4h]

  if ( dword_B350D8 ) /*0x497e98*/
  {
    if ( dword_B350CC ) /*0x497ea4*/
    {
      if ( dword_B350D0 ) /*0x497eb0*/
      {
        inited = InitBSShaderAccumulator(); /*0x497ebc*/
        sub_7A9CF0(inited); /*0x497ec3*/
        v4 = dword_B350D0; /*0x497ed3*/
        v5 = (double)dword_B350D0 / (double)dword_B350CC; /*0x497ed9*/
        dword_B06C5C = dword_B350CC; /*0x497edf*/
        dword_B06C64 = v4; /*0x497ee4*/
        byte_B350D7 = 0; /*0x497eea*/
        if ( v5 != dbl_A31C70 ) /*0x497efb*/
          byte_B350D7 = 1; /*0x497efd*/
        sub_410B00(); /*0x497f04*/
        sub_578EF0(a1, a2, a3, v5); /*0x497f09*/
        sub_405B00(); /*0x497f0e*/
        Interface3dScenegraph_Destructor(); /*0x497f13*/
        v6 = *(_DWORD *)(dword_B350D8 + 8); /*0x497f1e*/
        v7 = (_DWORD *)(dword_B350D8 + 8); /*0x497f21*/
        if ( v6 ) /*0x497f26*/
        {
          if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) ) /*0x497f2c*/
            (**(void (__thiscall ***)(int, int))v6)(v6, 1); /*0x497f42*/
          *v7 = 0; /*0x497f44*/
        }
        if ( sub_76B090((unsigned __int16 *)dword_B350D8, dword_B350CC, dword_B350D0) ) /*0x497f59*/
        {
          window = OSGlobals->window; /*0x497f6d*/
          v9 = dword_B06C5C; /*0x497f76*/
          v10 = dword_B06C64; /*0x497f7b*/
          v15 = hWnd; /*0x497f83*/
          Rect.left = 0; /*0x497f84*/
          Rect.top = 0; /*0x497f88*/
          Rect.right = v9; /*0x497f8c*/
          Rect.bottom = v10; /*0x497f90*/
          ClassLongA = GetClassLongA(v15, 0xFFFFFFF8); /*0x497f9a*/
          WindowLongA = GetWindowLongA(window, 0xFFFFFFF0); /*0x497f9e*/
          AdjustWindowRect(&Rect, WindowLongA, ClassLongA); /*0x497faa*/
          SetWindowPos(window, 0, X, Y, Rect.right - Rect.left, Rect.bottom - Rect.top, 0x40); /*0x497fd4*/
        }
        else
        {
          sub_497B20("Failed to Recreate Gamebryo Render in desired dimensions."); /*0x497fe1*/
        }
        RecreateImageSpaceShader(a1);           // MoonSugarEffect decode: display/render resize resource fence. sub_497E70 calls RecreateImageSpaceShader after Gamebryo render dimensions are recreated and before installing a new shader accumulator/rebuilding scenegraphs. Good boundary for plugin-owned renderer helper resources to invalidate/rebuild. /*0x497fe9*/
        v12 = (_DWORD *)FormHeapAlloc(0x38u); /*0x497ff0*/
        v18 = 0; /*0x497ffe*/
        if ( v12 ) /*0x498002*/
          v13 = (BSShaderAccumulator *)NiAlphaAccumulator_Constructor(v12); /*0x498006*/
        else
          v13 = 0; /*0x49800d*/
        v14 = (NiDX9Renderer *)dword_B350D8; /*0x49800f*/
        v18 = 0xFFFFFFFF; /*0x498016*/
        NiDX9Renderer::SetShaderAccumulator(v14, v13); /*0x49801e*/
        sub_4112E0(g_worldScenegraph); /*0x498029*/
        InterfaceMenuScenegraph_Create(); /*0x49802e*/
        Interface3dScenegraph_Create(); /*0x498033*/
        sub_578CC0(a1, a2, a3, v5, 0); /*0x498039*/
        sub_578CD0(a1, a2, a3, v5); /*0x498041*/
        sub_5B6040(a1, a3, v5, a2); /*0x498046*/
      }
    }
  }
}
